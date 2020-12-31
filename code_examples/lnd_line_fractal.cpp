#include "loopndisplay.hpp"

#define SEED "F++F++F++F++F"
#define SUBSTITUTION "F++F++F+++++F-F++F"
#define FORWARD_CHAR 'F'
#define TURN_ANGLE 3.14159265358979 / 5.0
#define START_ANGLE 1.4
#define ITERATIONS 7

/* #define SEED "F-F-F-F"
#define SUBSTITUTION "F-F+F+F-F"
#define FORWARD_CHAR 'F'
#define TURN_ANGLE 3.14159265358979 / 2.0
#define START_ANGLE 3.14159265358979 / 2.0
#define ITERATIONS 8 */ 

/* #define SEED "F--F"
#define SUBSTITUTION "F-F+F+F-F"
#define FORWARD_CHAR 'F'
#define TURN_ANGLE 3.14159265358979 / 2.0
#define START_ANGLE 1.4
#define ITERATIONS 8 */


class line_fractal : protected lnd::looper
{

protected:

	lnd::group_vertex<2> line_coord;
	lnd::program line_prog;
	lnd::shader_fragment line_frag;

	float shift_X = 0.0f;
	float shift_Y = 0.0f;
	float scale = 1.0f;

	std::string fractal_substitute(const std::string& curve, char forward_char, const std::string after_spin);
	template <typename Ty> std::vector<Ty> fractal_path(std::string curve, Ty dist, Ty angle, Ty angle0, char forward_char);

	void setup();
	inline void loop(float dt);
	inline void display();
	void exit() { }
	bool exit_condition() { return key_escape(); }
};


std::string line_fractal::fractal_substitute(const std::string& curve, char forward_char, const std::string after_spin)
{
	std::string acc("");
	{
		std::size_t forward_char_count = std::count(curve.begin(), curve.end(), forward_char);
		acc.reserve(forward_char_count * after_spin.size() + (curve.size() - forward_char_count));
	}

	for (std::size_t n = 0; n < curve.size(); n++)
	{
		if (curve[n] == forward_char) { acc += after_spin; }
		else { acc += curve[n]; }
	}

	return acc;
}

template <typename Ty> std::vector<Ty> line_fractal::fractal_path(std::string curve, Ty dist, Ty angle, Ty angle0, char forward_char)
{
	std::vector<Ty> path(2 * std::count(curve.begin(), curve.end(), forward_char) + 2);
	path[0] = static_cast<Ty>(0);
	path[1] = static_cast<Ty>(0);

	// write the coordinates

	{
		Ty x = static_cast<Ty>(0);
		Ty y = static_cast<Ty>(0);
		Ty* ptr = path.data() + 2;
		for (std::size_t n = 0; n < curve.size(); n++)
		{
			if (curve[n] == forward_char)
			{
				x += dist * std::cos(angle0);
				y += dist * std::sin(angle0);
				*ptr = x;
				*(ptr + 1) = y;
				ptr += 2;
			}
			else if (curve[n] == '+') { angle0 += angle; }
			else if (curve[n] == '-') { angle0 -= angle; }
			else {}
		}
	}

	// rescale the coordinates

	{
		Ty min_x = static_cast<Ty>(0);
		Ty min_y = static_cast<Ty>(0);
		Ty max_x = static_cast<Ty>(0);
		Ty max_y = static_cast<Ty>(0);

		Ty* ptr = path.data();
		for (std::size_t n = 0; n < path.size(); n += 2)
		{
			if (*ptr < min_x) { min_x = *ptr; }
			if (*ptr > max_x) { max_x = *ptr; }
			if (*(ptr + 1) < min_y) { min_y = *(ptr + 1); }
			if (*(ptr + 1) > max_y) { max_y = *(ptr + 1); }
			ptr += 2;
		}

		Ty delta_x_inv = static_cast<Ty>(1.8) / (max_x - min_x);
		Ty delta_y_inv = static_cast<Ty>(1.8) / (max_y - min_y);
		Ty delta_inv = (delta_x_inv < delta_y_inv) ? delta_x_inv : delta_y_inv;

		if (delta_x_inv < delta_y_inv)
		{
			Ty offset_y = static_cast<Ty>(0.9) * delta_x_inv / delta_y_inv;
			ptr = path.data();
			for (std::size_t n = 0; n < path.size(); n += 2)
			{
				*ptr = (*ptr - min_x) * delta_inv - static_cast<Ty>(0.9);
				*(ptr + 1) = (*(ptr + 1) - min_y) * delta_inv - offset_y;
				ptr += 2;
			}
		}
		else
		{
			Ty offset_x = static_cast<Ty>(0.9) * delta_y_inv / delta_x_inv;
			ptr = path.data();
			for (std::size_t n = 0; n < path.size(); n += 2)
			{
				*ptr = (*ptr - min_x) * delta_inv - offset_x;
				*(ptr + 1) = (*(ptr + 1) - min_y) * delta_inv - static_cast<Ty>(0.9);
				ptr += 2;
			}
		}
	}

	return path;
}

void line_fractal::setup()
{
	std::string curve = SEED;
	for (int n = ITERATIONS; n > 0; n--)
	{
		curve = fractal_substitute(curve, FORWARD_CHAR, SUBSTITUTION);
	}

	std::vector<double> coord_double_precision = fractal_path(curve, 1.0, TURN_ANGLE, START_ANGLE, FORWARD_CHAR);

	std::cout << "Line fractal : " << (coord_double_precision.size() / 2) - 1 << " lines to draw." << std::endl;

	line_coord.resize_vertex_count(coord_double_precision.size() / 2);
	for (std::size_t n = 0; n < coord_double_precision.size(); n++)
	{
		line_coord[n] = static_cast<float>(coord_double_precision[n]);
	}

	line_coord.buffer_new_id();
	line_coord.buffer_allocate();

	line_frag.new_shader(
		"	#version 330 core												\n"
		"	out vec4 color;													\n"
		"	in vec2 X;														\n"
		"	void main()														\n"
		"	{																\n"
		"		float r2 = X[0] * X[0] + X[1] * X[1];						\n"
		"		color = vec4(1.0, 1.0 - 0.2 * r2, 1.0 - 0.4 * r2, 1.0);		\n"
		"	}																\n"
	);

	line_prog.new_program(vertex_shift_scale(), line_frag);
}

inline void line_fractal::loop(float dt)
{
	if (key_W()) { shift_Y -= 0.5f * dt; }
	if (key_S()) { shift_Y += 0.5f * dt; }
	if (key_A()) { shift_X += 0.5f * dt; }
	if (key_D()) { shift_X -= 0.5f * dt; }
	if (key_space_press())
	{
		scale *= 1.25f;
		shift_X *= 1.25f;
		shift_Y *= 1.25f;
	}
	if (key_ctrl_press() || key_shift_press())
	{
		scale *= 0.8f;
		shift_X *= 0.8f;
		shift_Y *= 0.8f;
	}

	call_display();
}

inline void line_fractal::display()
{
	clear_window();
	lnd::set_vertex_shift_scale(line_prog, shift_X, shift_Y, scale);
	line_coord.draw_line_strip(line_prog);
}


int main()
{
	lnd::window<line_fractal> main_window;
	main_window.set_anti_aliasing(true);
	main_window.show(960, 960, true, 0.05,
		"Line fractal ! (WSAD for moving, space for zooming, "
		"ctrl or shift for unzooming, escape for exit)");
	return 0;
}
