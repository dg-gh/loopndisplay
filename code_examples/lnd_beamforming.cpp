#include "loopndisplay.hpp"

class beamforming : protected lnd::looper
{

private:

	float quad[8] = { 0.0f };
	lnd::shader_fragment beamforming_fs;
	lnd::program beamforming_prog;
	float phase_shift = 0.0f;
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


void beamforming::setup()
{
	quad[0] = min_X(); quad[1] = min_Y();
	quad[2] = max_X(); quad[3] = min_Y();
	quad[4] = max_X(); quad[5] = max_Y();
	quad[6] = min_X(); quad[7] = max_Y();

	beamforming_fs.new_shader(
		"#version 330 core																				\n"
		"in vec2 X;																						\n"
		"out vec4 color;																				\n"
		"uniform vec2 params;																			\n"
		"uniform vec2 shift;																			\n"
		"uniform float scale;																			\n"
		"uniform float dir;																				\n"
		"uniform float d;																				\n"
		"void main() {																					\n"
		"	vec2 C = vec2(-0.5, 0.0) + 0.5 * params;													\n"
		"	vec2 z = scale * vec2(X) + shift;															\n"
		"	color = vec4(0.0, 0.0, 0.0, 1.0);															\n"
		"	float dx = 0.003;																			\n"
		"	float AMP = sin(400 * sqrt(z[0] * z[0] + z[1] * z[1]));										\n"
		"	for (int k = 0; k < 40; ++k)																\n"
		"	{																							\n"
		"		AMP += sin(k * dir + 400 * sqrt((z[0] + k * dx) * (z[0] + k * dx) + z[1] * z[1]));		\n"
		"		AMP += sin(- k * dir + 400 * sqrt((z[0] - k * dx) * (z[0] - k * dx) + z[1] * z[1]));	\n"
		"	}																							\n"
		"	if (z[1] < 0) { AMP = 0; }																	\n"
		"	color[0] = 0.015 * max(0, AMP); color[2] = -0.1 * min(0, AMP);								\n"
		"}																								\n"
	);
	beamforming_prog.new_program(vertex_identity(), beamforming_fs);
}

inline void beamforming::loop(float dt)
{
	if (mouse_1()) { phase_shift += dt; }
	if (mouse_2()) { phase_shift -= dt; }
	if (key_W()) { shift_Y += scale * dt; }
	if (key_S()) { shift_Y -= scale * dt; }
	if (key_A()) { shift_X -= scale * dt; }
	if (key_D()) { shift_X += scale * dt; }
	if (key_space_press()) { scale *= 0.8; }
	if (key_ctrl_press() || key_shift_press()) { scale *= 1.25; }

	call_display();
}

inline void beamforming::display()
{
	clear_window();
	lnd::set_uniform_1f(beamforming_prog, "scale", scale);
	lnd::set_uniform_2f(beamforming_prog, "shift", shift_X, shift_Y);
	lnd::set_uniform_1f(beamforming_prog, "dir", phase_shift);
	draw_quad(quad, beamforming_prog);
}

int main()
{
	lnd::window<beamforming> main_window;
	main_window.show(1600, 960, true, 0.02,
		"Beamforming shader ! (WSAD for moving, space for zooming, "
		"ctrl or shift for unzooming, left or right click for steering the direction, "
		"escape for exit)"
	);
	return 0;
}
