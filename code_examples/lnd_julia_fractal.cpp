#include "loopndisplay.hpp"

class julia_fractal : protected lnd::looper
{

private:

	float quad[8] = { 0.0f };
	lnd::shader_fragment julia_fs;
	lnd::program julia_prog;
	float theta = 0.0f;
	float shift_X = 0.0f;
	float shift_Y = 0.0f;
	float scale = 1.0f;

protected:

	void setup();
	inline void loop(float);
	inline void display();
	void exit() { }
	bool exit_condition() { return key_escape(); }
};


void julia_fractal::setup()
{
	quad[0] = min_X(); quad[1] = min_Y();
	quad[2] = max_X(); quad[3] = min_Y();
	quad[4] = max_X(); quad[5] = max_Y();
	quad[6] = min_X(); quad[7] = max_Y();

	julia_fs.new_shader(
		"#version 330 core														\n"
		"in vec2 X;																\n"
		"out vec4 color;														\n"
		"uniform vec2 params;													\n"
		"uniform vec2 shift;													\n"
		"uniform float scale;													\n"
		"void main() {															\n"
		"	vec2 C = vec2(-0.5, 0.0) + 0.5 * params;							\n"
		"	vec2 z = scale * vec2(X) + shift;									\n"
		"	color = vec4(0.0, 0.0, 0.0, 1.0);									\n"
		"	for (int i = 0; i < 1000; i++)										\n"
		"	{																	\n"
		"		z = vec2(z[0] * z[0] - z[1] * z[1], 2.0 * z[0] * z[1]) + C;		\n"
		"		if (z[0] * z[0] + z[1] * z[1] > 8.0)							\n"
		"		{																\n"
		"			color = vec4(0.06 + i * 0.01, 0.0, 0.03 * i, 1.0f);			\n"
		"			break;														\n"
		"		}																\n"
		"	}																	\n"
		"}																		\n"
	);
	julia_prog.new_program(vertex_identity(), julia_fs);
}

inline void julia_fractal::loop(float dt)
{
	if (mouse_1()) { theta += 0.3f * dt; }
	if (theta > 3.14159f) { theta -= 2.0f * 3.14159f; }
	if (mouse_2()) { theta -= 0.3f * dt; }
	if (theta < 3.14159f) { theta += 2.0f * 3.14159f; }

	if (key_W()) { shift_Y += 2.0f * scale * dt; }
	if (key_S()) { shift_Y -= 2.0f * scale * dt; }
	if (key_A()) { shift_X -= 2.0f * scale * dt; }
	if (key_D()) { shift_X += 2.0f * scale * dt; }
	if (key_space_press()) { scale *= 0.8; }
	if (key_ctrl_press() || key_shift_press()) { scale *= 1.25; }

	call_display();
}

inline void julia_fractal::display()
{
	clear_window();
	lnd::set_uniform_1f(julia_prog, "scale", scale);
	lnd::set_uniform_2f(julia_prog, "shift", shift_X, shift_Y);
	lnd::set_uniform_2f(julia_prog, "params", std::cosf(theta), std::sinf(theta));
	draw_quad(quad, julia_prog);
}

int main()
{
	lnd::window<julia_fractal> main_window;
	main_window.show(1024, 768, true, 0.02,
		"Julia fractal shader ! (WSAD for moving, space for zooming, "
		"ctrl or shift for unzooming, left or right click for changing the shape, "
		"escape for exit)"
	);
	return 0;
}
