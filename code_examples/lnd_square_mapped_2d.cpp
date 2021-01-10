#include "loopndisplay.hpp"
#include <random>

class square_mapped_2d : protected lnd::looper
{

private:

	float theta = 0.0f;

	lnd::shader_vertex lights_vertex;
	lnd::shader_fragment lights_fragment;

	lnd::program prog;

	lnd::group_cluster_vertex<3, 2> square;
	lnd::group_cluster_vertex<6, 2> square_frame;

	lnd::texture<4> tex;
	lnd::texture<1> spec_tex;
	lnd::texture<3> frame_tex;
	lnd::group_cluster_vertex<3, 2> tex_coord;

protected:

	void setup();
	inline void loop(float);
	inline void display();
	void exit() { }
	bool exit_condition() { return key_escape(); }
};

void square_mapped_2d::setup()
{
	constexpr float pi = 3.14159265358979f;

	square.resize_cluster_count(2);
	square(0) = { -0.5f, -0.5f,    -0.5f, 0.5f,    0.5f, 0.5f };
	square(1) = { -0.5f, -0.5f,    0.5f, 0.5f,    0.5f, -0.5f };
	square.buffer_new_id();
	square.buffer_allocate();

	tex_coord.resize_cluster_count(2);
	tex_coord(0) = { 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f };
	tex_coord(1) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
	tex_coord.buffer_new_id();
	tex_coord.buffer_allocate();

	square_frame.make_frames_from(square, tex_coord, true);
	square_frame.buffer_new_id();
	square_frame.buffer_allocate();

	tex.resize(1024, 1024);
	spec_tex.resize(1024, 1024);
	frame_tex.resize(1024, 1024);


	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> distribution(0, 31);

	for (size_t i = 0; i < 1024; i++)
	{
		for (size_t j = 0; j < 1024; j++)
		{
			frame_tex(i, j)[0] = static_cast<unsigned char>(127);
			frame_tex(i, j)[1] = static_cast<unsigned char>(127);
			frame_tex(i, j)[2] = static_cast<unsigned char>(255);

			if ((i < 512 && j < 512) || (i >= 512 && j >= 512))
			{
				unsigned char x = static_cast<unsigned char>(distribution(mt) + 192);
				tex(i, j)[0] = x;
				tex(i, j)[1] = x;
				tex(i, j)[2] = x;
				tex(i, j)[3] = static_cast<unsigned char>(255);

				spec_tex(i, j)[0] = static_cast<unsigned char>(255);

				if (i < 32 && i <= j && i <= 512 - j)
				{
					frame_tex(i, j)[0] = static_cast<unsigned char>(85);
				}
				if (i > 480 && i >= j && i >= 512 - j)
				{
					frame_tex(i, j)[0] = static_cast<unsigned char>(170);
				}
				if (j < 32 && j < i && j < 512 - i)
				{
					frame_tex(i, j)[1] = static_cast<unsigned char>(85);
				}
				if (j > 480 && j > i && j > 512 - i)
				{
					frame_tex(i, j)[1] = static_cast<unsigned char>(170);
				}
			}
			else
			{
				auto y = distribution(mt);
				unsigned char x = static_cast<unsigned char>(y + 96);
				tex(i, j)[0] = x;
				tex(i, j)[1] = x;
				tex(i, j)[2] = x;
				tex(i, j)[3] = static_cast<unsigned char>(255);

				spec_tex(i, j)[0] = static_cast<unsigned char>(y + 32);
			}
		}
	}

	tex.map_linear();
	tex.buffer_new_id();
	tex.buffer_allocate();

	spec_tex.map_linear();
	spec_tex.buffer_new_id();
	spec_tex.buffer_allocate();

	frame_tex.map_linear();
	frame_tex.buffer_new_id();
	frame_tex.buffer_allocate();

	lights_vertex.new_shader(lnd::source_vertex_mapped_shift_rotate(1024, 768, true));
	lights_fragment.new_shader(lnd::source_fragment_mapped_skylight());


	float light_dir[3] = { -0.0f, -1.0f, -0.6f };
	float light_col[3] = { 0.9f, 0.8f, 1.0f };

	prog.new_program(lights_vertex, lights_fragment);
	set_skylight(prog, light_dir, light_col);
}

inline void square_mapped_2d::loop(float dt)
{
	constexpr float pi = 3.14159265358979f;
	constexpr float pi2 = 2.0f * 3.14159265358979f;

	theta += dt;
	if (theta > pi) { theta -= pi2; }

	call_display();
}

inline void square_mapped_2d::display()
{
	clear_window();
	set_vertex_shift_rotate_rad(prog, 0.0f, 0.0f, theta);
	square.draw_mapped(prog, tex_coord, tex, frame_tex, square_frame);
}

int main()
{
	lnd::window<square_mapped_2d> main_window;
	main_window.set_anti_aliasing(true);
	main_window.show(1024, 768, true, 0.01, "Mapped square 2D");
	return 0;
}
