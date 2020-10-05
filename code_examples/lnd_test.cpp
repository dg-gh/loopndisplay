#include "loopndisplay.h"

constexpr float pi = 3.14159265358979f;

class test_program : protected lnd::looper
{

private:

	lnd::group_cluster_vertex<4, 2> outer;
	int count = 0;

	lnd::group_cluster_vertex<4, 2> small_quad;
	lnd::program small_prog;
	lnd::group_cluster_color<4, 3> color;
	float phi = 0.0f;

	lnd::group_cluster_vertex<4, 2> quad;
	lnd::texture<4> tex;
	lnd::group_cluster_vertex<4, 2> tex_coord;
	lnd::program prog;
	float theta = 0.0f;

	lnd::group_vertex<2> line;
	lnd::group_color<3> line_color;
	GLsizei first = 0;
	GLsizei last = 0;

	float coeff = 0.25f * pi / 180.0f;

protected:

	void setup();
	inline void loop(float);
	inline void display();
	void exit() {};
	bool exit_condition() { return key_escape(); }
};

inline void test_program::setup()
{
	outer.resize_cluster_count(120);
	for (size_t k = 0; k < 120; k++)
	{
		float c = std::cosf(-pi / 60.0f * static_cast<float>(k));
		float s = std::sinf(-pi / 60.0f * static_cast<float>(k));

		outer(k) = {
			c * (-0.005f) - s * (0.9f), s * (-0.005f) + c * (0.9f),
			c * (0.005f) - s * (0.9f), s * (0.005f) + c * (0.9f),
			c * (0.005f) - s * (0.8f), s * (0.005f) + c * (0.8f),
			c * (-0.005f) - s * (0.8f), s * (-0.005f) + c * (0.8f)
		};
	}
	outer.buffer_new_id();
	outer.buffer_allocate();

	small_quad.resize_cluster_count(1);
	small_quad(0) = { -0.2f, -0.2f, 0.2f, -0.2f, 0.2f, 0.2f, -0.2f, 0.2f };
	small_quad.buffer_new_id();
	small_quad.buffer_allocate();

	color.resize_cluster_count(1);
	color(0) = {
		1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 1.0f
	};
	color.buffer_new_id();
	color.buffer_allocate();

	quad.resize_cluster_count(1);
	quad(0) = { -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f };
	quad.buffer_new_id();
	quad.buffer_allocate();

	tex_coord.resize_cluster_count(1);
	tex_coord(0) = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f };
	tex_coord.buffer_new_id();
	tex_coord.buffer_allocate();

	tex.resize(100, 100);
	for (size_t i = 0; i < 10000; i++)
	{
		tex(i)[0] = static_cast<unsigned char>(rand() & 127);
		tex(i)[1] = static_cast<unsigned char>(rand() & 255);
		tex(i)[2] = static_cast<unsigned char>(rand() & 255);
		tex(i)[3] = static_cast<unsigned char>(rand() & 255);
	}
	tex.buffer_new_id();
	tex.buffer_allocate();

	line.resize_vertex_count(200);
	for (size_t i = 0; i < 200; i++)
	{
		line(i) = { min_X() + static_cast<float>(i) / 199.0f * (max_X() - min_X()), static_cast<float>(rand() & 255) / (15.0f * 256.0f) - 0.4f };
	}
	line.buffer_new_id();
	line.buffer_allocate();

	line_color.resize_color_count(200);
	for (size_t i = 0; i < 200; i++)
	{
		line_color(i) = {
			sinf(static_cast<float>(i) * 0.01f),
			sinf(static_cast<float>(i) * 0.01f + 1.0f),
			sinf(static_cast<float>(i) * 0.01f + 2.0f) };
	}
	line_color.buffer_new_id();
	line_color.buffer_allocate();

	small_prog.new_program(vertex_RGB_shift_rotate(), fragment_RGB());
	prog.new_program(vertex_texture_shift_rotate(), fragment_texture());
}

inline void test_program::loop(float dt)
{
	count++;
	if (count > 120) { count = 1; }

	theta += 1.0f;
	if (theta > 180.0f) { theta -= 360.0f; }

	phi -= 2.0f;
	if (phi < -720.0f) { phi += 1440.0f; }

	if (first == 0 && last < 200) { last += 2; }
	else if (last >= 200 && first < 200) { first += 2; }
	else { first = 0; last = 0; }

	call_display();
}

inline void test_program::display()
{
	clear_window();

	for (size_t i = 0; i < 10000; i++)
	{
		tex(i)[0] = static_cast<unsigned char>(rand() & 127);
		tex(i)[1] = static_cast<unsigned char>(rand() & 255);
		tex(i)[2] = static_cast<unsigned char>(rand() & 255);
		tex(i)[3] = static_cast<unsigned char>(rand() & 127);
	}
	tex.buffer_update();

	small_quad.draw_RGBa(set_vertex_shift_rotate_deg(small_prog, 0.3f * std::cosf(coeff * phi), 0.3f * std::sinf(-coeff * phi), phi), color);

	lnd::enable_transparency();
	quad.draw_tex(set_vertex_shift_rotate_deg(prog, 0.0f, 0.0f, theta), tex_coord, tex);
	lnd::disable_transparency();

	outer.draw_ranged(0, count, program_cyan());
	line.draw_ranged_line_strip_RGBa(first, last, program_RGB(), line_color);
}

int main()
{
	lnd::window<test_program> main_window;
	main_window.set_anti_aliasing(true);
	main_window.show(800, 600, true, 0.01, "Test program");
	return 0;
}
