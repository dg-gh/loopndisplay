#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "loopndisplay.hpp"

class clock_program : protected lnd::looper
{

private:

	lnd::group_vertex<2> sec_needle;
	lnd::program sec_program;

	lnd::group_vertex<2> min_needle;
	lnd::group_color<3> min_needle_color;

	lnd::program min_program;
	lnd::program min_contour_program;

	lnd::group_vertex<2> hour_needle;
	lnd::group_color<3> hour_needle_color;

	lnd::program hour_program;
	lnd::program hour_contour_program;

	lnd::group_cluster_vertex<4, 2> sec;
	lnd::group_cluster_vertex<4, 2> hour;
	lnd::group_cluster_color<4, 3> hour_color;

	lnd::group_cluster_index<8> contour;

	lnd::group_vertex<2> circle;
	lnd::group_vertex<2> center;

	lnd::program light_green;

	float sec_counter = 0.0f;
	float min_counter = 0.0f;
	float hour_counter = 0.0f;

protected:

	void setup();
	inline void loop(float);
	inline void display();
	void exit() { }
	bool exit_condition() { return key_escape(); }
};

void clock_program::setup()
{
	constexpr float pi = 3.14159265358979f;

	sec.resize_cluster_count(60);
	for (size_t k = 0; k < 60; k++)
	{
		float c = std::cosf(pi / 30.0f * static_cast<float>(k));
		float s = std::sinf(pi / 30.0f * static_cast<float>(k));

		sec(k) = {
			c * (-0.01f) - s * (0.9f), s * (-0.01f) + c * (0.9f),
			c * (0.01f) - s * (0.9f), s * (0.01f) + c * (0.9f),
			c * (0.01f) - s * (0.8f), s * (0.01f) + c * (0.8f),
			c * (-0.01f) - s * (0.8f), s * (-0.01f) + c * (0.8f)
		};
	}
	sec.buffer_new_id();
	sec.buffer_allocate();

	contour.resize_cluster_count(12);
	contour(0) = { 0, 1, 1, 2, 2, 3, 3, 0 };
	contour.propagate_with_offset(4);

	contour.buffer_new_id();
	contour.buffer_allocate();

	hour.resize_cluster_count(12);
	for (size_t k = 0; k < 12; k++)
	{
		float c = std::cos(pi / 6.0f * static_cast<float>(k));
		float s = std::sin(pi / 6.0f * static_cast<float>(k));

		hour(k) = {
			c * (-0.02f) - s * (0.91f), s * (-0.02f) + c * (0.91f),
			c * (0.02f) - s * (0.91f), s * (0.02f) + c * (0.91f),
			c * (0.02f) - s * (0.78f), s * (0.02f) + c * (0.78f),
			c * (-0.02f) - s * (0.78f), s * (-0.02f) + c * (0.78f)
		};
	}
	hour.buffer_new_id();
	hour.buffer_allocate();

	hour_color.resize_cluster_count(12);
	for (size_t k = 0; k < 12; k++)
	{
		hour_color(k) = {
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
			0.0f, 0.6f, 1.0f,
			0.0f, 0.6f, 1.0f
		};
	}
	hour_color.buffer_new_id();
	hour_color.buffer_allocate();

	sec_needle.resize_vertex_count(10);
	sec_needle = { 0.0f, 0.75f, 0.015f, 0.015f,
		0.015f * std::cosf(0.0f * pi / 6.0f), -0.015f * std::sinf(0.0f * pi / 6.0f) - 0.08f,
		0.015f * std::cosf(1.0f * pi / 6.0f), -0.015f * std::sinf(1.0f * pi / 6.0f) - 0.08f,
		0.015f * std::cosf(2.0f * pi / 6.0f), -0.015f * std::sinf(2.0f * pi / 6.0f) - 0.08f,
		0.015f * std::cosf(3.0f * pi / 6.0f), -0.015f * std::sinf(3.0f * pi / 6.0f) - 0.08f,
		0.015f * std::cosf(4.0f * pi / 6.0f), -0.015f * std::sinf(4.0f * pi / 6.0f) - 0.08f,
		0.015f * std::cosf(5.0f * pi / 6.0f), -0.015f * std::sinf(5.0f * pi / 6.0f) - 0.08f,
		0.015f * std::cosf(6.0f * pi / 6.0f), -0.015f * std::sinf(6.0f * pi / 6.0f) - 0.08f,
		-0.015f, 0.015f };
	sec_needle.buffer_new_id();
	sec_needle.buffer_allocate();
	sec_program.new_program(vertex_shift_rotate(), fragment_cyan());

	min_needle.resize_vertex_count(10);
	min_needle = { 0.0f, 0.7f, 0.03f, 0.03f,
		0.03f * std::cosf(0.0f * pi / 6.0f), -0.03f * std::sinf(0.0f * pi / 6.0f),
		0.03f * std::cosf(1.0f * pi / 6.0f), -0.03f * std::sinf(1.0f * pi / 6.0f),
		0.03f * std::cosf(2.0f * pi / 6.0f), -0.03f * std::sinf(2.0f * pi / 6.0f),
		0.03f * std::cosf(3.0f * pi / 6.0f), -0.03f * std::sinf(3.0f * pi / 6.0f),
		0.03f * std::cosf(4.0f * pi / 6.0f), -0.03f * std::sinf(4.0f * pi / 6.0f),
		0.03f * std::cosf(5.0f * pi / 6.0f), -0.03f * std::sinf(5.0f * pi / 6.0f),
		0.03f * std::cosf(6.0f * pi / 6.0f), -0.03f * std::sinf(6.0f * pi / 6.0f),
		-0.03f, 0.03f };
	min_needle.buffer_new_id();
	min_needle.buffer_allocate();

	min_needle_color.resize_color_count(10);
	min_needle_color = {
		1.0f, 0.0f, 1.0f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
	};
	min_needle_color.buffer_new_id();
	min_needle_color.buffer_allocate();

	min_program.new_program(vertex_RGB_shift_rotate(), fragment_RGB());
	min_contour_program.new_program(vertex_shift_rotate(), fragment_white());

	hour_needle.resize_vertex_count(10);
	hour_needle = { 0.0f, 0.6f, 0.035f, 0.035f,
		0.035f * std::cosf(0.0f * pi / 6.0f), -0.035f * std::sinf(0.0f * pi / 6.0f),
		0.035f * std::cosf(1.0f * pi / 6.0f), -0.035f * std::sinf(1.0f * pi / 6.0f),
		0.035f * std::cosf(2.0f * pi / 6.0f), -0.035f * std::sinf(2.0f * pi / 6.0f),
		0.035f * std::cosf(3.0f * pi / 6.0f), -0.035f * std::sinf(3.0f * pi / 6.0f),
		0.035f * std::cosf(4.0f * pi / 6.0f), -0.035f * std::sinf(4.0f * pi / 6.0f),
		0.035f * std::cosf(5.0f * pi / 6.0f), -0.035f * std::sinf(5.0f * pi / 6.0f),
		0.035f * std::cosf(6.0f * pi / 6.0f), -0.035f * std::sinf(6.0f * pi / 6.0f),
		-0.035f, 0.035f };
	hour_needle.buffer_new_id();
	hour_needle.buffer_allocate();

	hour_needle_color.resize_color_count(10);
	hour_needle_color = {
		1.0f, 0.0f, 0.3f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
		0.0f, 0.2f, 0.4f,
	};
	hour_needle_color.buffer_new_id();
	hour_needle_color.buffer_allocate();

	hour_program.new_program(vertex_RGB_shift_rotate(), fragment_RGB());
	hour_contour_program.new_program(vertex_shift_rotate(), fragment_white());

	circle.resize_vertex_count(182);
	for (size_t k = 0; k < 182; k += 2)
	{
		float c = std::cosf((2 * pi / 180.0f) * static_cast<float>(k));
		float s = std::sinf((2 * pi / 180.0f) * static_cast<float>(k));
		circle(k) = { c * 0.945f, s * 0.945f };
		circle(k + 1) = { c * 0.95f, s * 0.95f };
	}
	circle.buffer_new_id();
	circle.buffer_allocate();

	center.resize_vertex_count(14);
	center = { 0.0f, 0.0f,
		0.01f * std::cosf(0.0f * pi / 6.0f), -0.01f * std::sinf(0.0f * pi / 6.0f),
		0.01f * std::cosf(1.0f * pi / 6.0f), -0.01f * std::sinf(1.0f * pi / 6.0f),
		0.01f * std::cosf(2.0f * pi / 6.0f), -0.01f * std::sinf(2.0f * pi / 6.0f),
		0.01f * std::cosf(3.0f * pi / 6.0f), -0.01f * std::sinf(3.0f * pi / 6.0f),
		0.01f * std::cosf(4.0f * pi / 6.0f), -0.01f * std::sinf(4.0f * pi / 6.0f),
		0.01f * std::cosf(5.0f * pi / 6.0f), -0.01f * std::sinf(5.0f * pi / 6.0f),
		0.01f * std::cosf(6.0f * pi / 6.0f), -0.01f * std::sinf(6.0f * pi / 6.0f),
		0.01f * std::cosf(7.0f * pi / 6.0f), -0.01f * std::sinf(7.0f * pi / 6.0f),
		0.01f * std::cosf(8.0f * pi / 6.0f), -0.01f * std::sinf(8.0f * pi / 6.0f),
		0.01f * std::cosf(9.0f * pi / 6.0f), -0.01f * std::sinf(9.0f * pi / 6.0f),
		0.01f * std::cosf(10.0f * pi / 6.0f), -0.01f * std::sinf(10.0f * pi / 6.0f),
		0.01f * std::cosf(11.0f * pi / 6.0f), -0.01f * std::sinf(11.0f * pi / 6.0f),
		0.01f * std::cosf(12.0f * pi / 6.0f), -0.01f * std::sinf(12.0f * pi / 6.0f)
	};
	center.buffer_new_id();
	center.buffer_allocate();

	{
		std::time_t date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		char* char_ptr = std::ctime(&date);

		int _hour = 10 * (static_cast<int>(*(char_ptr + 11)) - static_cast <int>('0'))
			+ (static_cast<int>(*(char_ptr + 12)) - static_cast <int>('0'));
		int _minute = 10 * (static_cast<int>(*(char_ptr + 14)) - static_cast <int>('0'))
			+ (static_cast<int>(*(char_ptr + 15)) - static_cast <int>('0'));
		int _second = 10 * (static_cast<int>(*(char_ptr + 17)) - static_cast <int>('0'))
			+ (static_cast<int>(*(char_ptr + 18)) - static_cast <int>('0'));

		sec_counter = static_cast<float>(_second);
		min_counter = static_cast<float>(_minute);
		hour_counter = static_cast<float>(_minute + 60 * _hour);

		if (_hour >= 12) { hour_counter -= 720.0f; };
	}
}

void clock_program::loop(float dt)
{
	sec_counter++;
	if (sec_counter > 59.5f)
	{
		sec_counter = 0.0f;
		min_counter++;
		hour_counter++;
		if (min_counter > 59.5f) { min_counter = 0.0f; }
		if (hour_counter > 719.5f) { hour_counter = 0.0f; }
	}

	call_display();

	std::cout << "seconds elapsed : " << dt << std::endl;
}

inline void clock_program::display()
{
	clear_window();

	sec.draw(program_cyan());
	hour.draw_RGBA(program_RGB(), hour_color);
	hour.draw_lines_indexed(program_cyan(), contour);
	hour_needle.draw_tri_fan_RGBA(lnd::set_vertex_shift_rotate_deg(hour_program, 0.0f, 0.0f, hour_counter * (-0.5f)), hour_needle_color);
	hour_needle.draw_line_loop(lnd::set_vertex_shift_rotate_deg(hour_contour_program, 0.0f, 0.0f, hour_counter * (-0.5f)));
	min_needle.draw_tri_fan_RGBA(lnd::set_vertex_shift_rotate_deg(min_program, 0.0f, 0.0f, min_counter * (-6.0f)), min_needle_color);
	min_needle.draw_line_loop(lnd::set_vertex_shift_rotate_deg(min_contour_program, 0.0f, 0.0f, min_counter * (-6.0f)));
	sec_needle.draw_tri_fan(lnd::set_vertex_shift_rotate_deg(sec_program, 0.0f, 0.0f, sec_counter * (-6.0f)));
	center.draw_tri_fan(program_black());
	circle.draw_tri_strip(program_magenta());
}

int main()
{
	lnd::window<clock_program> main_window;
	main_window.set_anti_aliasing(true);
	main_window.show(800, 600, true, 1.0, "Clock");
	return 0;
}
