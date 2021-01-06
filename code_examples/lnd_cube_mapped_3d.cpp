#define LND_AVX_EXT
#include "loopndisplay.hpp"
#include <random>

class cube_mapped_3d : protected lnd::looper
{

private:

	lnd::camera_3d P;
	lnd::model_3d P0;
	lnd::model_3d P1;
	lnd::model_3d P2;

	lnd::shader_vertex lights_3d_vertex;
	lnd::shader_fragment lights_3d_fragment;

	lnd::program prog;
	lnd::program prog0;
	lnd::program prog1;
	lnd::program prog2;

	lnd::group_cluster_vertex<3, 3> cube;
	lnd::group_cluster_vertex<9, 3> cube_normals;
	lnd::group_cluster_vertex<3, 3> cube_light;

	lnd::texture<4> tex;
	lnd::texture<1> spec_tex;
	lnd::texture<3> frame_tex;
	lnd::group_cluster_vertex<3, 2> tex_coord;

	float light_position0[3];
	float angle0 = 0.0f;

	float light_position1[3];
	float angle1 = 2.0f / 3.0f * 3.14159265358979f;

	float light_position2[3];
	float angle2 = -2.0f / 3.0f * 3.14159265358979f;

protected:

	void setup();
	inline void loop(float);
	inline void display();
	void exit() { }
	bool exit_condition() { return key_escape(); }
};

void cube_mapped_3d::setup()
{
	constexpr float pi = 3.14159265358979f;

	lnd::enable_3d();
	lnd::enable_face_culling(true, true);
	lnd::enable_transparency();

	cube.resize_cluster_count(12);

	cube(0) = { -0.5f, -0.5f, -0.5f,    -0.5f, 0.5f, -0.5f,    0.5f, 0.5f, -0.5f };
	cube(1) = { -0.5f, -0.5f, -0.5f,    0.5f, 0.5f, -0.5f,    0.5f, -0.5f, -0.5f };
	cube(2) = { 0.5f, -0.5f, -0.5f,    0.5f, 0.5f, -0.5f,    0.5f, 0.5f, 0.5f };
	cube(3) = { 0.5f, -0.5f, -0.5f,    0.5f, 0.5f, 0.5f,    0.5f, -0.5f, 0.5f };
	cube(4) = { 0.5f, -0.5f, 0.5f,    0.5f, 0.5f, 0.5f,    -0.5f, 0.5f, 0.5f };
	cube(5) = { 0.5f, -0.5f, 0.5f,    -0.5f, 0.5f, 0.5f,    -0.5f, -0.5f, 0.5f };
	cube(6) = { -0.5f, -0.5f, 0.5f,    -0.5f, 0.5f, 0.5f,    -0.5f, 0.5f, -0.5f };
	cube(7) = { -0.5f, -0.5f, 0.5f,    -0.5f, 0.5f, -0.5f,    -0.5f, -0.5f, -0.5f };
	cube(8) = { -0.5f, 0.5f, 0.5f,    0.5f, 0.5f, 0.5f,    0.5f, 0.5f, -0.5f };
	cube(9) = { -0.5f, 0.5f, 0.5f,    0.5f, 0.5f, -0.5f,    -0.5f, 0.5f, -0.5f };
	cube(10) = { 0.5f, -0.5f, 0.5f,    -0.5f, -0.5f, 0.5f,    -0.5f, -0.5f, -0.5f };
	cube(11) = { 0.5f, -0.5f, 0.5f,    -0.5f, -0.5f, -0.5f,    0.5f, -0.5f, -0.5f };

	cube.buffer_new_id();
	cube.buffer_allocate();


	tex_coord.resize_cluster_count(12);

	tex_coord(0) = { 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f };
	tex_coord(1) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
	tex_coord(2) = { 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f };
	tex_coord(3) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
	tex_coord(4) = { 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f };
	tex_coord(5) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
	tex_coord(6) = { 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f };
	tex_coord(7) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
	tex_coord(8) = { 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f };
	tex_coord(9) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
	tex_coord(10) = { 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f };
	tex_coord(11) = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };

	tex_coord.buffer_new_id();
	tex_coord.buffer_allocate();


	cube_normals.make_frames_from(cube, tex_coord, true);
	cube_normals.buffer_new_id();
	cube_normals.buffer_allocate();

	cube_light.resize_cluster_count(12);

	cube_light(0) = { -0.1f, -0.1f, -0.1f,    -0.1f, 0.1f, -0.1f,    0.1f, 0.1f, -0.1f };
	cube_light(1) = { -0.1f, -0.1f, -0.1f,    0.1f, 0.1f, -0.1f,    0.1f, -0.1f, -0.1f };
	cube_light(2) = { 0.1f, -0.1f, -0.1f,    0.1f, 0.1f, -0.1f,    0.1f, 0.1f, 0.1f };
	cube_light(3) = { 0.1f, -0.1f, -0.1f,    0.1f, 0.1f, 0.1f,    0.1f, -0.1f, 0.1f };
	cube_light(4) = { 0.1f, -0.1f, 0.1f,    0.1f, 0.1f, 0.1f,    -0.1f, 0.1f, 0.1f };
	cube_light(5) = { 0.1f, -0.1f, 0.1f,    -0.1f, 0.1f, 0.1f,    -0.1f, -0.1f, 0.1f };
	cube_light(6) = { -0.1f, -0.1f, 0.1f,    -0.1f, 0.1f, 0.1f,    -0.1f, 0.1f, -0.1f };
	cube_light(7) = { -0.1f, -0.1f, 0.1f,    -0.1f, 0.1f, -0.1f,    -0.1f, -0.1f, -0.1f };
	cube_light(8) = { -0.1f, 0.1f, 0.1f,    0.1f, 0.1f, 0.1f,    0.1f, 0.1f, -0.1f };
	cube_light(9) = { -0.1f, 0.1f, 0.1f,    0.1f, 0.1f, -0.1f,    -0.1f, 0.1f, -0.1f };
	cube_light(10) = { 0.1f, -0.1f, 0.1f,    -0.1f, -0.1f, 0.1f,    -0.1f, -0.1f, -0.1f };
	cube_light(11) = { 0.1f, -0.1f, 0.1f,    -0.1f, -0.1f, -0.1f,    0.1f, -0.1f, -0.1f };

	cube_light.buffer_new_id();
	cube_light.buffer_allocate();

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


	lights_3d_vertex.new_shader(lnd::source_vertex_mapped_3d());
	lights_3d_fragment.new_shader(lnd::source_fragment_mapped_3d(3));

	prog.new_program(lights_3d_vertex, lights_3d_fragment);
	prog0.new_program(vertex_3d(), fragment_red());
	prog1.new_program(vertex_3d(), fragment_green());
	prog2.new_program(vertex_3d(), fragment_blue());

	lnd::set_ambient_light_3d(prog, std::array<float, 3>{0.0f, 0.0f, 0.2f}.data());
	lnd::set_m_matrix_3d(prog, std::array<float, 16>{
		1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
	}.data());

	lnd::set_material_3d(prog, 1.0f, 0.5f, 8.0f);

	light_position0[2] = 1.0f;
	light_position1[2] = 1.0f;
	light_position2[2] = 1.0f;

	lnd::set_pointlight_prop_3d(prog, 0,
		std::array<float, 4>{1.0f, 0.0f, 0.0f, 0.2f}.data(),
		std::array<float, 3>{1.0f, 0.01f, 0.001f}.data());
	lnd::set_pointlight_prop_3d(prog, 1,
		std::array<float, 4>{0.0f, 1.0f, 0.0f, 0.2f}.data(),
		std::array<float, 3>{1.0f, 0.01f, 0.001f}.data());
	lnd::set_pointlight_prop_3d(prog, 2,
		std::array<float, 4>{0.0f, 0.0f, 1.0f, 0.2f}.data(),
		std::array<float, 3>{1.0f, 0.01f, 0.001f}.data());

	lnd::set_pointlights_range_3d(prog, 0, 3);

	P.compute_p_matrix(screen_ratio(), 0.5f * pi, 100.f, 0.1f);
	P.position[0] = -2.0f;
}

inline void cube_mapped_3d::loop(float dt)
{
	constexpr float pi = 3.14159265358979f;
	constexpr float pi2 = 2.0f * 3.14159265358979f;

	P.compute_trig();

	if (key_W()) { P.move_forward(dt); }
	if (key_S()) { P.move_backward(dt); }
	if (key_A()) { P.move_left(dt); }
	if (key_D()) { P.move_right(dt); }
	if (key_space()) { P.move_up(dt); }
	if (key_shift()) { P.move_down(dt); }

	if (key_up()) { P.turn_up_rad(dt); }
	if (key_down()) { P.turn_down_rad(dt); }
	if (key_left()) { P.turn_left_rad(dt); }
	if (key_right()) { P.turn_right_rad(dt); }

	angle0 += dt;
	if (angle0 > pi) { angle0 -= pi2; }
	light_position0[0] = 2.0f * cosf(angle0);
	light_position0[1] = 2.0f * sinf(angle0);
	P0.set_position(light_position0);

	angle1 += dt;
	if (angle1 > pi) { angle1 -= pi2; }
	light_position1[0] = 2.0f * cosf(angle1);
	light_position1[1] = 2.0f * sinf(angle1);
	P1.set_position(light_position1);

	angle2 += dt;
	if (angle2 > pi) { angle2 -= pi2; }
	light_position2[0] = 2.0f * cosf(angle2);
	light_position2[1] = 2.0f * sinf(angle2);
	P2.set_position(light_position2);

	call_display();
}

inline void cube_mapped_3d::display()
{
	clear_window();

	P.compute_v_matrix();
	P.compute_vp_matrix();

	lnd::set_mvp_position_3d(prog, P.vp_matrix_data(), P.position_data());
	lnd::set_pointlight_pos_3d(prog, 0, light_position0);
	lnd::set_pointlight_pos_3d(prog, 1, light_position1);
	lnd::set_pointlight_pos_3d(prog, 2, light_position2);
	cube.draw_mapped_3d(prog, tex_coord, tex, spec_tex, frame_tex, cube_normals);

	P.compute_mvp_matrix(P0.m_matrix_data());
	lnd::set_mvp_matrix_3d(prog0, P.mvp_matrix_data());
	cube_light.draw_3d(prog0);

	P.compute_mvp_matrix(P1.m_matrix_data());
	lnd::set_mvp_matrix_3d(prog1, P.mvp_matrix_data());
	cube_light.draw_3d(prog1);

	P.compute_mvp_matrix(P2.m_matrix_data());
	lnd::set_mvp_matrix_3d(prog2, P.mvp_matrix_data());
	cube_light.draw_3d(prog2);
}

int main()
{
	lnd::window<cube_mapped_3d> main_window;
	main_window.set_anti_aliasing(true);
	main_window.show(1024, 768, true, 0.01, "Mapped cube 3D (use WASD space and shift for moving and arrows for turning)");
	return 0;
}
