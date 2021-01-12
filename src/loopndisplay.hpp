// loopndisplay.hpp - last update : 11 / 01 / 2021
// License <http://unlicense.org/> (statement below at the end of the file)

// Needs GLFW and GLEW set up
// GLFW : https://www.glfw.org/
// GLEW : http://glew.sourceforge.net/



////// API //////

// write the following methods of my_prog as a derived class of lnd::looper
// with lnd::looper as protected :

// void setup() { your code here in the derived class ... }
// inline void loop(float time_elapsed) { your code here in the derived class ... }
// inline void display() { your code here in the derived class ... }
// void exit() { your code here in the derived class ... }
// inline bool exit_condition() { your code here in the derived class ... }

// the method call_display() runs the method display(), must be called in the loop(float time_elapsed) method


// as an example, you can enter the following code in the main function :

// lnd::window<my_prog> window_example;
// window_example.show(640, 480, true, 0.02, "My program !");


// the main cpp file would result in the following :

//	#include "loopndisplay.hpp"
//	
//	class my_program : protected lnd::looper
//	{
//	
//	protected:
//	
//		void setup() { }
//		inline void loop(float dt) { call_display(); }
//		inline void display() { clear_window(); }
//		void exit() { }
//		bool exit_condition() { return key_escape(); }
//	};
//	
//	int main()
//	{
//		lnd::window<my_program> main_window;
//		main_window.show(640, 480, true, 0.02,
//			"My program ! (press escape to exit)");
//		return 0;
//	}



#ifndef LOOPNDISPLAY_HPP
#define LOOPNDISPLAY_HPP


////// OPTIONS //////

#ifdef LND_AVX_EXT
#include <immintrin.h>
#endif // LND_AVX_EXT

#ifndef LND_DEFAULT_ALLOCATOR
#define LND_DEFAULT_ALLOCATOR std::allocator
#endif // LND_DEFAULT_ALLOCATOR

#ifndef LND_VERTEX
#define LND_VERTEX(Ty, N) std::array<Ty, N>
#endif // LND_VERTEX

#ifndef LND_INDEX
#define LND_INDEX(Ty, N) std::array<Ty, N>
#endif // LND_INDEX

#ifndef LND_COLOR
#define LND_COLOR(Ty, N) std::array<Ty, N>
#endif // LND_COLOR

#ifndef LND_PIXEL
#define LND_PIXEL(Ty, N) std::array<Ty, N>
#endif // LND_PIXEL

#ifndef LND_CLOCK
#define LND_CLOCK steady_clock
#endif // LND_CLOCK

#ifndef LND_COS
#define LND_COS std::cos
#endif // LND_COS

#ifndef LND_SIN
#define LND_SIN std::sin
#endif // LND_SIN

#ifndef LND_SQRT
#define LND_SQRT std::sqrt
#endif // LND_SQRT


////// INCLUDES //////

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif // GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <cstring>
#include <vector>
#include <array>
#include <string>
#include <functional>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>


////// IMPLEMENTATION //////


// INPUTS

namespace lnd
{
	class user_key_input
	{

	public:

		// event press

		std::atomic<bool> mouse_1_press{ false };
		std::atomic<bool> mouse_2_press{ false };
		std::atomic<bool> mouse_3_press{ false };
		std::atomic<bool> mouse_4_press{ false };
		std::atomic<bool> mouse_5_press{ false };
		std::atomic<bool> mouse_6_press{ false };
		std::atomic<bool> mouse_7_press{ false };
		std::atomic<bool> mouse_8_press{ false };

		std::atomic<bool> space_press{ false };
		std::atomic<bool> apostrophe_press{ false };
		std::atomic<bool> comma_press{ false };
		std::atomic<bool> minus_press{ false };
		std::atomic<bool> period_press{ false };
		std::atomic<bool> slash_press{ false };

		std::atomic<bool> A_press{ false };
		std::atomic<bool> B_press{ false };
		std::atomic<bool> C_press{ false };
		std::atomic<bool> D_press{ false };
		std::atomic<bool> E_press{ false };
		std::atomic<bool> F_press{ false };
		std::atomic<bool> G_press{ false };
		std::atomic<bool> H_press{ false };
		std::atomic<bool> I_press{ false };
		std::atomic<bool> J_press{ false };
		std::atomic<bool> K_press{ false };
		std::atomic<bool> L_press{ false };
		std::atomic<bool> M_press{ false };
		std::atomic<bool> N_press{ false };
		std::atomic<bool> O_press{ false };
		std::atomic<bool> P_press{ false };
		std::atomic<bool> Q_press{ false };
		std::atomic<bool> R_press{ false };
		std::atomic<bool> S_press{ false };
		std::atomic<bool> T_press{ false };
		std::atomic<bool> U_press{ false };
		std::atomic<bool> V_press{ false };
		std::atomic<bool> W_press{ false };
		std::atomic<bool> X_press{ false };
		std::atomic<bool> Y_press{ false };
		std::atomic<bool> Z_press{ false };

		std::atomic<bool> num0_press{ false };
		std::atomic<bool> num1_press{ false };
		std::atomic<bool> num2_press{ false };
		std::atomic<bool> num3_press{ false };
		std::atomic<bool> num4_press{ false };
		std::atomic<bool> num5_press{ false };
		std::atomic<bool> num6_press{ false };
		std::atomic<bool> num7_press{ false };
		std::atomic<bool> num8_press{ false };
		std::atomic<bool> num9_press{ false };

		std::atomic<bool> numpad0_press{ false };
		std::atomic<bool> numpad1_press{ false };
		std::atomic<bool> numpad2_press{ false };
		std::atomic<bool> numpad3_press{ false };
		std::atomic<bool> numpad4_press{ false };
		std::atomic<bool> numpad5_press{ false };
		std::atomic<bool> numpad6_press{ false };
		std::atomic<bool> numpad7_press{ false };
		std::atomic<bool> numpad8_press{ false };
		std::atomic<bool> numpad9_press{ false };

		std::atomic<bool> add_press{ false };
		std::atomic<bool> sub_press{ false };
		std::atomic<bool> mul_press{ false };
		std::atomic<bool> div_press{ false };

		std::atomic<bool> f1_press{ false };
		std::atomic<bool> f2_press{ false };
		std::atomic<bool> f3_press{ false };
		std::atomic<bool> f4_press{ false };
		std::atomic<bool> f5_press{ false };
		std::atomic<bool> f6_press{ false };
		std::atomic<bool> f7_press{ false };
		std::atomic<bool> f8_press{ false };
		std::atomic<bool> f9_press{ false };
		std::atomic<bool> f10_press{ false };
		std::atomic<bool> f11_press{ false };
		std::atomic<bool> f12_press{ false };

		std::atomic<bool> escape_press{ false };
		std::atomic<bool> enter_press{ false };
		std::atomic<bool> tab_press{ false };
		std::atomic<bool> backspace_press{ false };
		std::atomic<bool> insert_press{ false };
		std::atomic<bool> delete__press{ false };
		std::atomic<bool> right_press{ false };
		std::atomic<bool> left_press{ false };
		std::atomic<bool> down_press{ false };
		std::atomic<bool> up_press{ false };
		std::atomic<bool> alt_press{ false };
		std::atomic<bool> shift_press{ false };
		std::atomic<bool> ctrl_press{ false };

		// event release

		std::atomic<bool> mouse_1_release{ false };
		std::atomic<bool> mouse_2_release{ false };
		std::atomic<bool> mouse_3_release{ false };
		std::atomic<bool> mouse_4_release{ false };
		std::atomic<bool> mouse_5_release{ false };
		std::atomic<bool> mouse_6_release{ false };
		std::atomic<bool> mouse_7_release{ false };
		std::atomic<bool> mouse_8_release{ false };

		std::atomic<bool> space_release{ false };
		std::atomic<bool> apostrophe_release{ false };
		std::atomic<bool> comma_release{ false };
		std::atomic<bool> minus_release{ false };
		std::atomic<bool> period_release{ false };
		std::atomic<bool> slash_release{ false };

		std::atomic<bool> A_release{ false };
		std::atomic<bool> B_release{ false };
		std::atomic<bool> C_release{ false };
		std::atomic<bool> D_release{ false };
		std::atomic<bool> E_release{ false };
		std::atomic<bool> F_release{ false };
		std::atomic<bool> G_release{ false };
		std::atomic<bool> H_release{ false };
		std::atomic<bool> I_release{ false };
		std::atomic<bool> J_release{ false };
		std::atomic<bool> K_release{ false };
		std::atomic<bool> L_release{ false };
		std::atomic<bool> M_release{ false };
		std::atomic<bool> N_release{ false };
		std::atomic<bool> O_release{ false };
		std::atomic<bool> P_release{ false };
		std::atomic<bool> Q_release{ false };
		std::atomic<bool> R_release{ false };
		std::atomic<bool> S_release{ false };
		std::atomic<bool> T_release{ false };
		std::atomic<bool> U_release{ false };
		std::atomic<bool> V_release{ false };
		std::atomic<bool> W_release{ false };
		std::atomic<bool> X_release{ false };
		std::atomic<bool> Y_release{ false };
		std::atomic<bool> Z_release{ false };

		std::atomic<bool> num0_release{ false };
		std::atomic<bool> num1_release{ false };
		std::atomic<bool> num2_release{ false };
		std::atomic<bool> num3_release{ false };
		std::atomic<bool> num4_release{ false };
		std::atomic<bool> num5_release{ false };
		std::atomic<bool> num6_release{ false };
		std::atomic<bool> num7_release{ false };
		std::atomic<bool> num8_release{ false };
		std::atomic<bool> num9_release{ false };

		std::atomic<bool> numpad0_release{ false };
		std::atomic<bool> numpad1_release{ false };
		std::atomic<bool> numpad2_release{ false };
		std::atomic<bool> numpad3_release{ false };
		std::atomic<bool> numpad4_release{ false };
		std::atomic<bool> numpad5_release{ false };
		std::atomic<bool> numpad6_release{ false };
		std::atomic<bool> numpad7_release{ false };
		std::atomic<bool> numpad8_release{ false };
		std::atomic<bool> numpad9_release{ false };

		std::atomic<bool> add_release{ false };
		std::atomic<bool> sub_release{ false };
		std::atomic<bool> mul_release{ false };
		std::atomic<bool> div_release{ false };

		std::atomic<bool> f1_release{ false };
		std::atomic<bool> f2_release{ false };
		std::atomic<bool> f3_release{ false };
		std::atomic<bool> f4_release{ false };
		std::atomic<bool> f5_release{ false };
		std::atomic<bool> f6_release{ false };
		std::atomic<bool> f7_release{ false };
		std::atomic<bool> f8_release{ false };
		std::atomic<bool> f9_release{ false };
		std::atomic<bool> f10_release{ false };
		std::atomic<bool> f11_release{ false };
		std::atomic<bool> f12_release{ false };

		std::atomic<bool> escape_release{ false };
		std::atomic<bool> enter_release{ false };
		std::atomic<bool> tab_release{ false };
		std::atomic<bool> backspace_release{ false };
		std::atomic<bool> insert_release{ false };
		std::atomic<bool> delete__release{ false };
		std::atomic<bool> right_release{ false };
		std::atomic<bool> left_release{ false };
		std::atomic<bool> down_release{ false };
		std::atomic<bool> up_release{ false };
		std::atomic<bool> alt_release{ false };
		std::atomic<bool> shift_release{ false };
		std::atomic<bool> ctrl_release{ false };

		inline void reset_key_events()
		{
			memset(this, 0, sizeof(lnd::user_key_input));
		}
	};

	class user_mouse_input
	{

	public:

		double X_shift = 0.0;
		double Y_shift = 0.0;
		double X_scale = 1.0;
		double Y_scale = 1.0;

		std::atomic<float> mouse_X{ 0.0f };
		std::atomic<float> mouse_Y{ 0.0f };
	};


	// INSTANCES

	class _state_instance
	{

	public:

		int padding0[16] = { 0 };
		GLFWwindow* window_ptr = nullptr;
		int padding1[16] = { 0 };
		lnd::user_key_input user_key_input;
		int padding2[16] = { 0 };
		lnd::user_mouse_input user_mouse_input;
		int padding3[16] = { 0 };
		GLbitfield clear_window = GL_COLOR_BUFFER_BIT;
		int padding4[16] = { 0 };
	} __state_instance;


	// ON CALLBACK

	void key_callback(GLFWwindow*, int key, int, int action, int)
	{
		switch (key)
		{

		case GLFW_KEY_SPACE:
			lnd::__state_instance.user_key_input.space_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.space_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_APOSTROPHE:
			lnd::__state_instance.user_key_input.apostrophe_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.apostrophe_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_COMMA:
			lnd::__state_instance.user_key_input.comma_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.comma_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_MINUS:
			lnd::__state_instance.user_key_input.minus_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.minus_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_PERIOD:
			lnd::__state_instance.user_key_input.period_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.period_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_SLASH:
			lnd::__state_instance.user_key_input.slash_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.slash_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_A:
			lnd::__state_instance.user_key_input.A_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.A_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_B:
			lnd::__state_instance.user_key_input.B_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.B_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_C:
			lnd::__state_instance.user_key_input.C_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.C_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_D:
			lnd::__state_instance.user_key_input.D_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.D_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_E:
			lnd::__state_instance.user_key_input.E_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.E_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F:
			lnd::__state_instance.user_key_input.F_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.F_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_G:
			lnd::__state_instance.user_key_input.G_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.G_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_H:
			lnd::__state_instance.user_key_input.H_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.H_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_I:
			lnd::__state_instance.user_key_input.I_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.I_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_J:
			lnd::__state_instance.user_key_input.J_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.J_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_K:
			lnd::__state_instance.user_key_input.K_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.K_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_L:
			lnd::__state_instance.user_key_input.L_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.L_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_M:
			lnd::__state_instance.user_key_input.M_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.M_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_N:
			lnd::__state_instance.user_key_input.N_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.N_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_O:
			lnd::__state_instance.user_key_input.O_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.O_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_P:
			lnd::__state_instance.user_key_input.P_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.P_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_Q:
			lnd::__state_instance.user_key_input.Q_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.Q_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_R:
			lnd::__state_instance.user_key_input.R_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.R_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_S:
			lnd::__state_instance.user_key_input.S_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.S_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_T:
			lnd::__state_instance.user_key_input.T_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.T_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_U:
			lnd::__state_instance.user_key_input.U_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.U_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_V:
			lnd::__state_instance.user_key_input.V_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.V_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_W:
			lnd::__state_instance.user_key_input.W_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.W_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_X:
			lnd::__state_instance.user_key_input.X_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.X_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_Y:
			lnd::__state_instance.user_key_input.Y_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.Y_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_Z:
			lnd::__state_instance.user_key_input.Z_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.Z_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_0:
			lnd::__state_instance.user_key_input.num0_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.num0_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_1:
			lnd::__state_instance.user_key_input.num1_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.num1_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_2:
			lnd::__state_instance.user_key_input.num2_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.num2_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_3:
			lnd::__state_instance.user_key_input.num3_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.num3_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_4:
			lnd::__state_instance.user_key_input.num4_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.num4_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_5:
			lnd::__state_instance.user_key_input.num5_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.num5_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_6:
			lnd::__state_instance.user_key_input.num6_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.num6_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_7:
			lnd::__state_instance.user_key_input.num7_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.num7_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_8:
			lnd::__state_instance.user_key_input.num8_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.num8_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_9:
			lnd::__state_instance.user_key_input.num9_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.num9_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_0:
			lnd::__state_instance.user_key_input.numpad0_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.numpad0_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_1:
			lnd::__state_instance.user_key_input.numpad1_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.numpad1_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_2:
			lnd::__state_instance.user_key_input.numpad2_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.numpad2_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_3:
			lnd::__state_instance.user_key_input.numpad3_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.numpad3_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_4:
			lnd::__state_instance.user_key_input.numpad4_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.numpad4_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_5:
			lnd::__state_instance.user_key_input.numpad5_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.numpad5_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_6:
			lnd::__state_instance.user_key_input.numpad6_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.numpad6_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_7:
			lnd::__state_instance.user_key_input.numpad7_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.numpad7_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_8:
			lnd::__state_instance.user_key_input.numpad8_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.numpad8_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_9:
			lnd::__state_instance.user_key_input.numpad9_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.numpad9_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_ADD:
			lnd::__state_instance.user_key_input.add_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.add_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_SUBTRACT:
			lnd::__state_instance.user_key_input.sub_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.sub_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_MULTIPLY:
			lnd::__state_instance.user_key_input.mul_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.mul_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_DIVIDE:
			lnd::__state_instance.user_key_input.div_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.div_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_ENTER:
			lnd::__state_instance.user_key_input.enter_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.enter_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F1:
			lnd::__state_instance.user_key_input.f1_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f1_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F2:
			lnd::__state_instance.user_key_input.f2_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f2_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F3:
			lnd::__state_instance.user_key_input.f3_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f3_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F4:
			lnd::__state_instance.user_key_input.f4_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f4_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F5:
			lnd::__state_instance.user_key_input.f5_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f5_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F6:
			lnd::__state_instance.user_key_input.f6_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f6_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F7:
			lnd::__state_instance.user_key_input.f7_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f7_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F8:
			lnd::__state_instance.user_key_input.f8_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f8_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F9:
			lnd::__state_instance.user_key_input.f9_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f9_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F10:
			lnd::__state_instance.user_key_input.f10_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f10_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F11:
			lnd::__state_instance.user_key_input.f11_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f11_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F12:
			lnd::__state_instance.user_key_input.f12_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.f12_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_ESCAPE:
			lnd::__state_instance.user_key_input.escape_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.escape_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_ENTER:
			lnd::__state_instance.user_key_input.enter_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.enter_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_TAB:
			lnd::__state_instance.user_key_input.tab_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.tab_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_BACKSPACE:
			lnd::__state_instance.user_key_input.backspace_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.backspace_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_INSERT:
			lnd::__state_instance.user_key_input.insert_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.insert_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_DELETE:
			lnd::__state_instance.user_key_input.delete__press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.delete__release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_RIGHT:
			lnd::__state_instance.user_key_input.right_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.right_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_LEFT:
			lnd::__state_instance.user_key_input.left_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.left_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_DOWN:
			lnd::__state_instance.user_key_input.down_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.down_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_UP:
			lnd::__state_instance.user_key_input.up_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.up_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_LEFT_ALT:
			lnd::__state_instance.user_key_input.alt_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.alt_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_RIGHT_ALT:
			lnd::__state_instance.user_key_input.alt_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.alt_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_LEFT_SHIFT:
			lnd::__state_instance.user_key_input.shift_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.shift_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_RIGHT_SHIFT:
			lnd::__state_instance.user_key_input.shift_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.shift_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_LEFT_CONTROL:
			lnd::__state_instance.user_key_input.ctrl_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.ctrl_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_RIGHT_CONTROL:
			lnd::__state_instance.user_key_input.ctrl_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.ctrl_release.store(action == GLFW_RELEASE);
			break;

		default:
			break;
		}
	}
	void mouse_button_callback(GLFWwindow*, int button, int action, int)
	{
		switch (button)
		{

		case GLFW_MOUSE_BUTTON_1:
			lnd::__state_instance.user_key_input.mouse_1_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.mouse_1_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_2:
			lnd::__state_instance.user_key_input.mouse_2_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.mouse_2_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_3:
			lnd::__state_instance.user_key_input.mouse_3_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.mouse_3_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_4:
			lnd::__state_instance.user_key_input.mouse_4_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.mouse_4_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_5:
			lnd::__state_instance.user_key_input.mouse_5_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.mouse_5_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_6:
			lnd::__state_instance.user_key_input.mouse_6_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.mouse_6_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_7:
			lnd::__state_instance.user_key_input.mouse_7_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.mouse_7_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_8:
			lnd::__state_instance.user_key_input.mouse_8_press.store(action == GLFW_PRESS);
			lnd::__state_instance.user_key_input.mouse_8_release.store(action == GLFW_RELEASE);
			break;

		default:
			break;
		}
	}
	void mouse_position_callback(GLFWwindow*, double input_mouse_X, double input_mouse_Y)
	{
		lnd::__state_instance.user_mouse_input.mouse_X.store(static_cast<float>(lnd::__state_instance.user_mouse_input.X_scale * (input_mouse_X - lnd::__state_instance.user_mouse_input.X_shift)));
		lnd::__state_instance.user_mouse_input.mouse_Y.store(static_cast<float>(lnd::__state_instance.user_mouse_input.Y_scale * (lnd::__state_instance.user_mouse_input.Y_shift - input_mouse_Y)));
	}
}


// BUFFERS

namespace lnd
{
	class buffer_vertex
	{

	private:

		GLuint buffer_index = 0;
		GLsizei objects = 0;

	public:

		buffer_vertex() = default;
		~buffer_vertex() { delete_id(); }

		inline unsigned int get() const noexcept { return buffer_index; }
		inline void bind() const { glBindBuffer(GL_ARRAY_BUFFER, buffer_index); }
		inline void unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

		inline void new_id(GLsizei number_of_objects)
		{
			if (buffer_index == 0)
			{
				glGenBuffers(number_of_objects, &buffer_index);
				objects = number_of_objects;
			}
		}
		inline void delete_id()
		{
			if (buffer_index != 0)
			{
				glDeleteBuffers(objects, &buffer_index);
				buffer_index = 0; objects = 0;
			}
		}

	private:

		buffer_vertex(const buffer_vertex&) = delete;
		buffer_vertex& operator=(const buffer_vertex&) = delete;
		buffer_vertex(buffer_vertex&&) = delete;
		buffer_vertex& operator=(buffer_vertex&&) = delete;
	};

	class buffer_color
	{

	private:

		GLuint buffer_index = 0;
		GLsizei objects = 0;

	public:

		buffer_color() = default;
		~buffer_color() { delete_id(); }

		inline unsigned int get() const noexcept { return buffer_index; }
		inline void bind() const { glBindBuffer(GL_ARRAY_BUFFER, buffer_index); }
		inline void unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

		inline void new_id(GLsizei number_of_objects)
		{
			if (buffer_index == 0)
			{
				glGenBuffers(number_of_objects, &buffer_index);
				objects = number_of_objects;
			}
		}
		inline void delete_id()
		{
			if (buffer_index != 0)
			{
				glDeleteBuffers(objects, &buffer_index);
				buffer_index = 0; objects = 0;
			}
		}

	private:

		buffer_color(const buffer_color&) = delete;
		buffer_color& operator=(const buffer_color&) = delete;
		buffer_color(buffer_color&&) = delete;
		buffer_color& operator=(buffer_color&&) = delete;
	};

	class buffer_index
	{

	private:

		GLuint _buffer_index = 0;
		GLsizei objects = 0;

	public:

		buffer_index() = default;
		~buffer_index() { delete_id(); }

		inline unsigned int get() const noexcept { return _buffer_index; }
		inline void bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffer_index); }
		inline void unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

		void new_id(GLsizei number_of_objects)
		{
			if (_buffer_index == 0)
			{
				glGenBuffers(number_of_objects, &_buffer_index);
				objects = number_of_objects;
			}
		}
		void delete_id()
		{
			if (_buffer_index != 0)
			{
				glDeleteBuffers(objects, &_buffer_index);
				_buffer_index = 0; objects = 0;
			}
		}

	private:

		buffer_index(const buffer_index&) = delete;
		buffer_index& operator=(const buffer_index&) = delete;
		buffer_index(buffer_index&&) = delete;
		buffer_index& operator=(buffer_index&&) = delete;
	};

	class buffer_texture
	{

	private:

		GLuint buffer_index = 0;
		GLsizei objects = 0;

	public:

		buffer_texture() = default;
		~buffer_texture() { delete_id(); }

		inline unsigned int get() const noexcept { return buffer_index; }
		inline void bind() const { glBindTexture(GL_TEXTURE_2D, buffer_index); }
		inline void bind(GLenum slot) const
		{
			switch (slot)
			{
			case 0: glActiveTexture(GL_TEXTURE0); break;
			case 1: glActiveTexture(GL_TEXTURE1); break;
			case 2: glActiveTexture(GL_TEXTURE2); break;
			case 3: glActiveTexture(GL_TEXTURE3); break;
			case 4: glActiveTexture(GL_TEXTURE4); break;
			case 5: glActiveTexture(GL_TEXTURE5); break;
			case 6: glActiveTexture(GL_TEXTURE6); break;
			case 7: glActiveTexture(GL_TEXTURE7); break;
			case 8: glActiveTexture(GL_TEXTURE8); break;
			case 9: glActiveTexture(GL_TEXTURE9); break;
			case 10: glActiveTexture(GL_TEXTURE10); break;
			case 11: glActiveTexture(GL_TEXTURE11); break;
			case 12: glActiveTexture(GL_TEXTURE12); break;
			case 13: glActiveTexture(GL_TEXTURE13); break;
			case 14: glActiveTexture(GL_TEXTURE14); break;
			case 15: glActiveTexture(GL_TEXTURE15); break;
			case 16: glActiveTexture(GL_TEXTURE16); break;
			case 17: glActiveTexture(GL_TEXTURE17); break;
			case 18: glActiveTexture(GL_TEXTURE18); break;
			case 19: glActiveTexture(GL_TEXTURE19); break;
			case 20: glActiveTexture(GL_TEXTURE20); break;
			case 21: glActiveTexture(GL_TEXTURE21); break;
			case 22: glActiveTexture(GL_TEXTURE22); break;
			case 23: glActiveTexture(GL_TEXTURE23); break;
			case 24: glActiveTexture(GL_TEXTURE24); break;
			case 25: glActiveTexture(GL_TEXTURE25); break;
			case 26: glActiveTexture(GL_TEXTURE26); break;
			case 27: glActiveTexture(GL_TEXTURE27); break;
			case 28: glActiveTexture(GL_TEXTURE28); break;
			case 29: glActiveTexture(GL_TEXTURE29); break;
			case 30: glActiveTexture(GL_TEXTURE30); break;
			case 31: glActiveTexture(GL_TEXTURE31); break;
			default: break;
			}
			glBindTexture(GL_TEXTURE_2D, buffer_index);
		}
		inline void unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }
		inline void unbind(GLenum slot) const
		{
			switch (slot)
			{
			case 0: glActiveTexture(GL_TEXTURE0); break;
			case 1: glActiveTexture(GL_TEXTURE1); break;
			case 2: glActiveTexture(GL_TEXTURE2); break;
			case 3: glActiveTexture(GL_TEXTURE3); break;
			case 4: glActiveTexture(GL_TEXTURE4); break;
			case 5: glActiveTexture(GL_TEXTURE5); break;
			case 6: glActiveTexture(GL_TEXTURE6); break;
			case 7: glActiveTexture(GL_TEXTURE7); break;
			case 8: glActiveTexture(GL_TEXTURE8); break;
			case 9: glActiveTexture(GL_TEXTURE9); break;
			case 10: glActiveTexture(GL_TEXTURE10); break;
			case 11: glActiveTexture(GL_TEXTURE11); break;
			case 12: glActiveTexture(GL_TEXTURE12); break;
			case 13: glActiveTexture(GL_TEXTURE13); break;
			case 14: glActiveTexture(GL_TEXTURE14); break;
			case 15: glActiveTexture(GL_TEXTURE15); break;
			case 16: glActiveTexture(GL_TEXTURE16); break;
			case 17: glActiveTexture(GL_TEXTURE17); break;
			case 18: glActiveTexture(GL_TEXTURE18); break;
			case 19: glActiveTexture(GL_TEXTURE19); break;
			case 20: glActiveTexture(GL_TEXTURE20); break;
			case 21: glActiveTexture(GL_TEXTURE21); break;
			case 22: glActiveTexture(GL_TEXTURE22); break;
			case 23: glActiveTexture(GL_TEXTURE23); break;
			case 24: glActiveTexture(GL_TEXTURE24); break;
			case 25: glActiveTexture(GL_TEXTURE25); break;
			case 26: glActiveTexture(GL_TEXTURE26); break;
			case 27: glActiveTexture(GL_TEXTURE27); break;
			case 28: glActiveTexture(GL_TEXTURE28); break;
			case 29: glActiveTexture(GL_TEXTURE29); break;
			case 30: glActiveTexture(GL_TEXTURE30); break;
			case 31: glActiveTexture(GL_TEXTURE31); break;
			default: break;
			}
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		inline void new_id(GLsizei number_of_objects)
		{
			if (buffer_index == 0)
			{
				glGenTextures(number_of_objects, &buffer_index);
				objects = number_of_objects;
			}
		}
		inline void delete_id()
		{
			if (buffer_index != 0)
			{
				glDeleteTextures(objects, &buffer_index);
				buffer_index = 0; objects = 0;
			}
		}

	private:

		buffer_texture(const buffer_texture&) = delete;
		buffer_texture& operator=(const buffer_texture&) = delete;
		buffer_texture(buffer_texture&&) = delete;
		buffer_texture& operator=(buffer_texture&&) = delete;
	};

	class shader_vertex
	{

	private:

		GLuint shader_index = 0;

	public:

		shader_vertex() = default;
		~shader_vertex() { delete_shader(); }

		inline GLuint get() const noexcept { return shader_index; }

		void new_shader(const std::string& shader_text)
		{
			shader_index = glCreateShader(GL_VERTEX_SHADER);
			const char* src = shader_text.c_str();
			glShaderSource(shader_index, 1, &src, nullptr);
			glCompileShader(shader_index);

			GLint result;
			glGetShaderiv(shader_index, GL_COMPILE_STATUS, &result);

			if (result == 0)
			{
				std::cout << "vertex shader compilation failed !\n" << std::endl;
				std::cout << shader_text << "\n" << std::endl;
				shader_index = 0;
			}
		}
		void delete_shader()
		{
			if (shader_index != 0)
			{
				glDeleteShader(shader_index);
				shader_index = 0;
			}
		}

	private:

		shader_vertex(const shader_vertex&) = delete;
		shader_vertex& operator=(const shader_vertex&) = delete;
		shader_vertex(shader_vertex&&) = delete;
		shader_vertex& operator=(shader_vertex&&) = delete;
	};

	class shader_fragment
	{

	private:

		GLuint shader_index = 0;

	public:

		shader_fragment() = default;
		~shader_fragment() { delete_shader(); }

		inline GLuint get() const noexcept { return shader_index; }

		void new_shader(const std::string& shader_text)
		{
			shader_index = glCreateShader(GL_FRAGMENT_SHADER);
			const char* src = shader_text.c_str();
			glShaderSource(shader_index, 1, &src, nullptr);
			glCompileShader(shader_index);

			GLint result;
			glGetShaderiv(shader_index, GL_COMPILE_STATUS, &result);

			if (result == 0)
			{
				std::cout << "vertex shader compilation failed !\n" << std::endl;
				std::cout << shader_text << "\n" << std::endl;
				shader_index = 0;
			}
		}
		void delete_shader()
		{
			if (shader_index != 0)
			{
				glDeleteShader(shader_index);
				shader_index = 0;
			}
		}

	private:

		shader_fragment(const shader_fragment&) = delete;
		shader_fragment& operator=(const shader_fragment&) = delete;
		shader_fragment(shader_fragment&&) = delete;
		shader_fragment& operator=(shader_fragment&&) = delete;
	};

	class program
	{

	private:

		GLuint program_index = 0;
		GLuint vertex_shader_index = 0;
		GLuint fragment_shader_index = 0;

	public:

		program() = default;
		~program() { delete_program(); }

		inline GLuint get() const noexcept { return program_index; }
		inline void use() const { glUseProgram(program_index); }

		void new_program(const lnd::shader_vertex& vertex_shader, const lnd::shader_fragment& fragment_shader)
		{
			if (program_index == 0)
			{
				vertex_shader_index = vertex_shader.get();
				fragment_shader_index = fragment_shader.get();

				program_index = glCreateProgram();

				glAttachShader(program_index, vertex_shader_index);
				glAttachShader(program_index, fragment_shader_index);

				glLinkProgram(program_index);
				glValidateProgram(program_index);
			}
		}
		void delete_program()
		{
			if (program_index != 0)
			{
				glDetachShader(program_index, vertex_shader_index);
				glDetachShader(program_index, fragment_shader_index);

				glDeleteProgram(program_index);

				program_index = 0;
				vertex_shader_index = 0;
				fragment_shader_index = 0;
			}
		}

	private:

		program(const program&) = delete;
		program& operator=(const program&) = delete;
		program(program&&) = delete;
		program& operator=(program&&) = delete;
	};

	buffer_vertex __default_vertex_buffer;
	buffer_index __default_index_buffer;
	buffer_color __default_color_buffer;
	buffer_vertex __default_texture_coord_buffer;
}


// SHADER SOURCES

namespace lnd
{
	std::string source_vertex_identity(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core											\n"
					"	layout (location = 0) in vec4 in_X;							\n"
					"	out vec2 X;													\n"
					"	void main() { gl_Position = vec4(							\n"
					"		" + ratio + " * in_X[0], in_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X); }										\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core											\n"
					"	layout (location = 0) in vec4 in_X;							\n"
					"	out vec2 X;													\n"
					"	void main() { gl_Position = vec4(							\n"
					"		in_X[0], " + ratio + " * in_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X); }										\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core							\n"
				"	layout (location = 0) in vec4 in_X;			\n"
				"	out vec2 X;									\n"
				"	void main() { gl_Position = in_X;			\n"
				"		X = vec2(in_X); }						\n"
				;
		}
	}
	std::string source_vertex_shift(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (in_X[0] + u_X[0]),				\n"
					"		in_X[1] + u_X[1], in_X[2], in_X[3]);			\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position); }					\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		in_X[0] + u_X[0],								\n"
					"		" + ratio + " * (in_X[1] + u_X[1]),				\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position); }					\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core						\n"
				"	layout (location = 0) in vec4 in_X;		\n"
				"	out vec2 X;								\n"
				"	out vec2 X_mov;							\n"
				"	uniform vec2 u_X;						\n"
				"	void main() { gl_Position = vec4(		\n"
				"		in_X[0] + u_X[0],					\n"
				"		in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
				"		X_mov = vec2(gl_Position); }		\n"
				;
		}
	}
	std::string source_vertex_shift_scale(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (u_X[2] * in_X[0] + u_X[0]),	\n"
					"		u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position); }					\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		u_X[2] * in_X[0] + u_X[0],						\n"
					"		" + ratio + " * (u_X[2] * in_X[1] + u_X[1]),	\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position); }					\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core						\n"
				"	layout (location = 0) in vec4 in_X;		\n"
				"	out vec2 X;								\n"
				"	out vec2 X_mov;							\n"
				"	uniform vec3 u_X;						\n"
				"	void main() { gl_Position = vec4(		\n"
				"		u_X[2] * in_X[0] + u_X[0],			\n"
				"		u_X[2] * in_X[1] + u_X[1],			\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
				"		X_mov = vec2(gl_Position); }		\n"
				;
		}
	}
	std::string source_vertex_shift_rotate(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core														\n"
					"	layout (location = 0) in vec4 in_X;										\n"
					"	out vec2 X;																\n"
					"	out vec2 X_mov;															\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		" + ratio + " * (u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0]),		\n"
					"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);														\n"
					"		X_mov = vec2(gl_Position); }										\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core														\n"
					"	layout (location = 0) in vec4 in_X;										\n"
					"	out vec2 X;																\n"
					"	out vec2 X_mov;															\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],						\n"
					"		" + ratio + " * (u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1]),		\n"
					"		in_X[2], in_X[3]);													\n"
					"		X = vec2(in_X);														\n"
					"		X_mov = vec2(gl_Position); }										\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core									\n"
				"	layout (location = 0) in vec4 in_X;					\n"
				"	out vec2 X;											\n"
				"	out vec2 X_mov;										\n"
				"	uniform vec4 u_X;									\n"
				"	void main() { gl_Position = vec4(					\n"
				"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],	\n"
				"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1],	\n"
				"		in_X[2], in_X[3]);								\n"
				"		X = vec2(in_X);									\n"
				"		X_mov = vec2(gl_Position); }					\n"
				;
		}
	}
	std::string source_vertex_affine(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core																					\n"
					"	layout (location = 0) in vec4 in_X;																	\n"
					"	out vec2 X;																							\n"
					"	out vec2 X_mov;																						\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		" + ratio + " * (u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3]))),	\n"
					"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])), in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);																					\n"
					"		X_mov = vec2(gl_Position); }																	\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core																					\n"
					"	layout (location = 0) in vec4 in_X;																	\n"
					"	out vec2 X;																							\n"
					"	out vec2 X_mov;																						\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),						\n"
					"		" + ratio + " * (u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3]))),	\n"
					"		in_X[2], in_X[3]);																				\n"
					"		X = vec2(in_X);																					\n"
					"		X_mov = vec2(gl_Position); }																	\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core																\n"
				"	layout (location = 0) in vec4 in_X;												\n"
				"	out vec2 X;																		\n"
				"	out vec2 X_mov;																	\n"
				"	uniform vec4 u_X0;																\n"
				"	uniform vec4 u_X1;																\n"
				"	void main() { gl_Position  = vec4(												\n"
				"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),	\n"
				"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])),	\n"
				"		in_X[2], in_X[3]);															\n"
				"		X = vec2(in_X);																\n"
				"		X_mov = vec2(gl_Position); }												\n"
				;
		}
	}

	std::string source_vertex_RGB_identity(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core											\n"
					"	layout (location = 0) in vec4 in_X;							\n"
					"	layout (location = 1) in vec3 in_C;							\n"
					"	out vec2 X;												\n"
					"	out vec3 C;													\n"
					"	void main() { gl_Position = vec4(							\n"
					"		" + ratio + " * in_X[0], in_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);											\n"
					"		C = in_C; }												\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core											\n"
					"	layout (location = 0) in vec4 in_X;							\n"
					"	layout (location = 1) in vec3 in_C;							\n"
					"	out vec2 X;													\n"
					"	out vec3 C;													\n"
					"	void main() { gl_Position = vec4(							\n"
					"		in_X[0], " + ratio + " * in_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);											\n"
					"		C = in_C; }												\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core						\n"
				"	layout (location = 0) in vec4 in_X;		\n"
				"	layout (location = 1) in vec3 in_C;		\n"
				"	out vec2 X;								\n"
				"	out vec3 C;								\n"
				"	void main() { gl_Position = in_X;		\n"
				"		X = vec2(in_X);						\n"
				"		C = in_C; }							\n"
				;
		}
	}
	std::string source_vertex_RGB_shift(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core										\n"
					"	layout (location = 0) in vec4 in_X;						\n"
					"	layout (location = 1) in vec3 in_C;						\n"
					"	out vec2 X;												\n"
					"	out vec2 X_mov;											\n"
					"	out vec3 C;												\n"
					"	uniform vec2 u_X;										\n"
					"	void main() { gl_Position = vec4(						\n"
					"		" + ratio + " * (in_X[0] + u_X[0]),					\n"
					"		in_X[1] + u_X[1], in_X[2], in_X[3]);				\n"
					"		X = vec2(in_X);										\n"
					"		X_mov = vec2(gl_Position);							\n"
					"		C = in_C; }											\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec3 in_C;					\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec3 C;											\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		in_X[0] + u_X[0],								\n"
					"		" + ratio + " * (in_X[1] + u_X[1]),				\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		C = in_C; }										\n"
					;
			}
		}
		else
		{
			return
				"   #version 330 core						\n"
				"   layout (location = 0) in vec4 in_X;		\n"
				"   layout (location = 1) in vec3 in_C;		\n"
				"	out vec2 X;								\n"
				"	out vec2 X_mov;							\n"
				"   out vec3 C;								\n"
				"   uniform vec2 u_X;						\n"
				"   void main() { gl_Position = vec4(		\n"
				"       in_X[0] + u_X[0],					\n"
				"       in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
				"		X_mov = vec2(gl_Position);			\n"
				"		C = in_C; }							\n"
				;
		}
	}
	std::string source_vertex_RGB_shift_scale(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec3 in_C;					\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec3 C;											\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (u_X[2] * in_X[0] + u_X[0]),	\n"
					"		u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		C = in_C; }										\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec3 in_C;					\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec3 C;											\n"
					"	uniform vec4 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		u_X[2] * in_X[0] + u_X[0],						\n"
					"		" + ratio + " * (u_X[2] * in_X[1] + u_X[1]),	\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		C = in_C; }										\n"
					;
			}
		}
		else
		{
			return
				"   #version 330 core						\n"
				"   layout (location = 0) in vec4 in_X;		\n"
				"   layout (location = 1) in vec3 in_C;		\n"
				"	out vec2 X;								\n"
				"	out vec2 X_mov;							\n"
				"   out vec3 C;								\n"
				"   uniform vec2 u_X;						\n"
				"   void main() { gl_Position = vec4(		\n"
				"       in_X[0] + u_X[0],					\n"
				"       in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
				"		X_mov = vec2(gl_Position);			\n"
				"		C = in_C; }							\n"
				;
		}
	}
	std::string source_vertex_RGB_shift_rotate(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core														\n"
					"	layout (location = 0) in vec4 in_X;										\n"
					"	layout (location = 1) in vec3 in_C;										\n"
					"	out vec2 X;																\n"
					"	out vec2 X_mov;															\n"
					"	out vec3 C;																\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		" + ratio + " * (u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0]),		\n"
					"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);														\n"
					"		X_mov = vec2(gl_Position);											\n"
					"		C = in_C; }															\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core														\n"
					"	layout (location = 0) in vec4 in_X;										\n"
					"	layout (location = 1) in vec3 in_C;										\n"
					"	out vec2 X;																\n"
					"	out vec2 X_mov;															\n"
					"	out vec3 C;																\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],						\n"
					"		" + ratio + " * (u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1]),		\n"
					"		in_X[2], in_X[3]);													\n"
					"		X = vec2(in_X);														\n"
					"		X_mov = vec2(gl_Position);											\n"
					"		C = in_C; }															\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core									\n"
				"	layout (location = 0) in vec4 in_X;					\n"
				"	layout (location = 1) in vec3 in_C;					\n"
				"	out vec2 X;											\n"
				"	out vec2 X_mov;										\n"
				"	out vec3 C;											\n"
				"	uniform vec4 u_X;									\n"
				"	void main() { gl_Position = vec4(					\n"
				"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],	\n"
				"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1],	\n"
				"		in_X[2], in_X[3]);								\n"
				"		X = vec2(in_X);									\n"
				"		X_mov = vec2(gl_Position);						\n"
				"		C = in_C; }										\n"
				;
		}
	}
	std::string source_vertex_RGB_affine(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core																					\n"
					"	layout (location = 0) in vec4 in_X;																	\n"
					"	layout (location = 1) in vec3 in_C;																	\n"
					"	out vec2 X;																							\n"
					"	out vec2 X_mov;																						\n"
					"	out vec3 C;																							\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		" + ratio + " * (u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3]))),	\n"
					"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])), in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);																					\n"
					"		X_mov = vec2(gl_Position);																		\n"
					"		C = in_C; }																						\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core																					\n"
					"	layout (location = 0) in vec4 in_X;																	\n"
					"	layout (location = 1) in vec3 in_C;																	\n"
					"	out vec2 X;																							\n"
					"	out vec2 X_mov;																						\n"
					"	out vec3 C;																							\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),						\n"
					"		" + ratio + " * (u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3]))),	\n"
					"		in_X[2], in_X[3]);																				\n"
					"		X = vec2(in_X);																					\n"
					"		X_mov = vec2(gl_Position);																		\n"
					"		C = in_C; }																						\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core																\n"
				"	layout (location = 0) in vec4 in_X;												\n"
				"	layout (location = 1) in vec3 in_C;												\n"
				"	out vec2 X;																		\n"
				"	out vec2 X_mov;																	\n"
				"	out vec3 C;																		\n"
				"	uniform vec4 u_X0;																\n"
				"	uniform vec4 u_X1;																\n"
				"	void main() { gl_Position  = vec4(												\n"
				"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),	\n"
				"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])),	\n"
				"		in_X[2], in_X[3]);															\n"
				"		X = vec2(in_X);																\n"
				"		X_mov = vec2(gl_Position);													\n"
				"		C = in_C; }																	\n"
				;
		}
	}

	std::string source_vertex_RGBA_identity(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core											\n"
					"	layout (location = 0) in vec4 in_X;							\n"
					"	layout (location = 1) in vec4 in_C;							\n"
					"	out vec2 X;													\n"
					"	out vec4 C;													\n"
					"	void main() { gl_Position = vec4(							\n"
					"		" + ratio + " * in_X[0], in_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);											\n"
					"		C = in_C; }												\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core											\n"
					"	layout (location = 0) in vec4 in_X;							\n"
					"	layout (location = 1) in vec3 in_C;							\n"
					"	out vec2 X;													\n"
					"	out vec3 C;													\n"
					"	void main() { gl_Position = vec4(							\n"
					"		in_X[0], " + ratio + " * in_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);											\n"
					"		C = in_C; }												\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core						\n"
				"	layout (location = 0) in vec4 in_X;		\n"
				"	layout (location = 1) in vec4 in_C;		\n"
				"	out vec2 X;								\n"
				"	out vec4 C;								\n"
				"	void main() { gl_Position = in_X;		\n"
				"		X = vec2(in_X);						\n"
				"		C = in_C; }							\n"
				;
		}
	}
	std::string source_vertex_RGBA_shift(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec4 in_C;					\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec4 C;											\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (in_X[0] + u_X[0]),				\n"
					"		in_X[1] + u_X[1], in_X[2], in_X[3]);			\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		C = in_C; }										\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec4 in_C;					\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec4 C;											\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		in_X[0] + u_X[0],								\n"
					"		" + ratio + " * (in_X[1] + u_X[1]),				\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		C = in_C; }										\n"
					;
			}
		}
		else
		{
			return
				"   #version 330 core						\n"
				"   layout (location = 0) in vec4 in_X;		\n"
				"   layout (location = 1) in vec4 in_C;		\n"
				"	out vec2 X;								\n"
				"	out vec2 X_mov;							\n"
				"   out vec4 C;								\n"
				"   uniform vec2 u_X;						\n"
				"   void main() { gl_Position = vec4(		\n"
				"       in_X[0] + u_X[0],					\n"
				"       in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
				"		X_mov = vec2(gl_Position);			\n"
				"		C = in_C; }							\n"
				;
		}
	}
	std::string source_vertex_RGBA_shift_scale(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec4 in_C;					\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec4 C;											\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (u_X[2] * in_X[0] + u_X[0]),	\n"
					"		u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		C = in_C; }										\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec4 in_C;					\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec4 C;											\n"
					"	uniform vec4 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		u_X[2] * in_X[0] + u_X[0],						\n"
					"		" + ratio + " * (u_X[2] * in_X[1] + u_X[1]),	\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		C = in_C; }										\n"
					;
			}
		}
		else
		{
			return
				"   #version 330 core						\n"
				"   layout (location = 0) in vec4 in_X;		\n"
				"   layout (location = 1) in vec4 in_C;		\n"
				"	out vec2 X;								\n"
				"	out vec2 X_mov;							\n"
				"   out vec4 C;								\n"
				"   uniform vec2 u_X;						\n"
				"   void main() { gl_Position = vec4(		\n"
				"       in_X[0] + u_X[0],					\n"
				"       in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
				"		X_mov = vec2(gl_Position);			\n"
				"		C = in_C; }							\n"
				;
		}
	}
	std::string source_vertex_RGBA_shift_rotate(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core														\n"
					"	layout (location = 0) in vec4 in_X;										\n"
					"	layout (location = 1) in vec4 in_C;										\n"
					"	out vec2 X;																\n"
					"	out vec2 X_mov;															\n"
					"	out vec4 C;																\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		" + ratio + " * (u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0]),		\n"
					"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);														\n"
					"		X_mov = vec2(gl_Position);											\n"
					"		C = in_C; }															\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core														\n"
					"	layout (location = 0) in vec4 in_X;										\n"
					"	layout (location = 1) in vec4 in_C;										\n"
					"	out vec2 X;																\n"
					"	out vec2 X_mov;															\n"
					"	out vec4 C;																\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],						\n"
					"		" + ratio + " * (u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1]),		\n"
					"		in_X[2], in_X[3]);													\n"
					"		X = vec2(in_X);														\n"
					"		X_mov = vec2(gl_Position);											\n"
					"		C = in_C; }															\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core									\n"
				"	layout (location = 0) in vec4 in_X;					\n"
				"	layout (location = 1) in vec4 in_C;					\n"
				"	out vec2 X;											\n"
				"	out vec2 X_mov;										\n"
				"	out vec4 C;											\n"
				"	uniform vec4 u_X;									\n"
				"	void main() { gl_Position = vec4(					\n"
				"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],	\n"
				"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1],	\n"
				"		in_X[2], in_X[3]);								\n"
				"		X = vec2(in_X);									\n"
				"		X_mov = vec2(gl_Position);						\n"
				"		C = in_C; }										\n"
				;
		}
	}
	std::string source_vertex_RGBA_affine(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core																					\n"
					"	layout (location = 0) in vec4 in_X;																	\n"
					"	layout (location = 1) in vec4 in_C;																	\n"
					"	out vec2 X;																							\n"
					"	out vec2 X_mov;																						\n"
					"	out vec4 C;																							\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		" + ratio + " * (u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3]))),	\n"
					"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])), in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);																					\n"
					"		X_mov = vec2(gl_Position);																		\n"
					"		C = in_C; }																						\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core																					\n"
					"	layout (location = 0) in vec4 in_X;																	\n"
					"	layout (location = 1) in vec4 in_C;																	\n"
					"	out vec2 X;																							\n"
					"	out vec2 X_mov;																						\n"
					"	out vec4 C;																							\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),						\n"
					"		" + ratio + " * (u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3]))),	\n"
					"		in_X[2], in_X[3]);																				\n"
					"		X = vec2(in_X);																					\n"
					"		X_mov = vec2(gl_Position);																		\n"
					"		C = in_C; }																						\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core																\n"
				"	layout (location = 0) in vec4 in_X;												\n"
				"	layout (location = 1) in vec4 in_C;												\n"
				"	out vec2 X;																		\n"
				"	out vec2 X_mov;																	\n"
				"	out vec4 C;																		\n"
				"	uniform vec4 u_X0;																\n"
				"	uniform vec4 u_X1;																\n"
				"	void main() { gl_Position  = vec4(												\n"
				"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),	\n"
				"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])),	\n"
				"		in_X[2], in_X[3]);															\n"
				"		X = vec2(in_X);																\n"
				"		X_mov = vec2(gl_Position);													\n"
				"		C = in_C; }																	\n"
				;
		}
	}

	std::string source_vertex_texture_identity(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core											\n"
					"	layout (location = 0) in vec4 in_X;							\n"
					"	layout (location = 1) in vec2 in_UV;						\n"
					"	out vec2 X;													\n"
					"	out vec2 UV;												\n"
					"	void main() { gl_Position = vec4(							\n"
					"		" + ratio + " * in_X[0], in_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);											\n"
					"		UV = in_UV; }											\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"   #version 330 core											\n"
					"   layout (location = 0) in vec4 in_X;							\n"
					"   layout (location = 1) in vec2 in_UV;						\n"
					"	out vec2 X;													\n"
					"   out vec2 UV;												\n"
					"   void main() { gl_Position = vec4(							\n"
					"       in_X[0], " + ratio + " * in_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);											\n"
					"		UV = in_UV; }											\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core						\n"
				"	layout (location = 0) in vec4 in_X;		\n"
				"	layout (location = 1) in vec2 in_UV;	\n"
				"	out vec2 X;								\n"
				"	out vec2 UV;							\n"
				"	void main() {							\n"
				"		gl_Position = in_X;					\n"
				"		X = vec2(in_X);						\n"
				"		UV = in_UV; }						\n"
				;
		}
	}
	std::string source_vertex_texture_shift(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec2 in_UV;				\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec2 UV;										\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (in_X[0] + u_X[0]),				\n"
					"		in_X[1] + u_X[1], in_X[2], in_X[3]);			\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		UV = in_UV; }									\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec2 in_UV;				\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec2 UV;										\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		in_X[0] + u_X[0],								\n"
					"		" + ratio + " * (in_X[1] + u_X[1]),				\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		UV = in_UV; }									\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core						\n"
				"	layout (location = 0) in vec4 in_X;		\n"
				"	layout (location = 1) in vec2 in_UV;	\n"
				"	out vec2 X;								\n"
				"	out vec2 X_mov;							\n"
				"	out vec2 UV;							\n"
				"	uniform vec2 u_X;						\n"
				"	void main() { gl_Position = vec4(		\n"
				"		in_X[0] + u_X[0],					\n"
				"		in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
				"		X_mov = vec2(gl_Position);			\n"
				"		UV = in_UV; }						\n"
				;
		}
	}
	std::string source_vertex_texture_shift_scale(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec2 in_UV;				\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec2 UV;										\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (u_X[2] * in_X[0] + u_X[0]),	\n"
					"		u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		UV = in_UV; }									\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec2 in_UV;				\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec2 UV;										\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		u_X[2] * in_X[0] + u_X[0],						\n"
					"		" + ratio + " * (u_X[2] * in_X[1] + u_X[1]),	\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		UV = in_UV; }									\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core									\n"
				"	layout (location = 0) in vec4 in_X;					\n"
				"	layout (location = 1) in vec2 in_UV;				\n"
				"	out vec2 X;											\n"
				"	out vec2 X_mov;										\n"
				"	out vec2 UV;										\n"
				"	uniform vec3 u_X;									\n"
				"	void main() { gl_Position = vec4(					\n"
				"		u_X[2] * in_X[0] + u_X[0],						\n"
				"		u_X[2] * in_X[1] + u_X[1],						\n"
				"		in_X[2], in_X[3]);								\n"
				"		X = vec2(in_X);									\n"
				"		X_mov = vec2(gl_Position);						\n"
				"		UV = in_UV; }									\n"
				;
		}
	}
	std::string source_vertex_texture_shift_rotate(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core														\n"
					"	layout (location = 0) in vec4 in_X;										\n"
					"	layout (location = 1) in vec2 in_UV;									\n"
					"	out vec2 X;																\n"
					"	out vec2 X_mov;															\n"
					"	out vec2 UV;															\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		" + ratio + " * (u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0]),		\n"
					"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);														\n"
					"		X_mov = vec2(gl_Position);											\n"
					"		UV = in_UV; }														\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core														\n"
					"	layout (location = 0) in vec4 in_X;										\n"
					"	layout (location = 1) in vec2 in_UV;									\n"
					"	out vec2 X;																\n"
					"	out vec2 X_mov;															\n"
					"	out vec2 UV;															\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],						\n"
					"		" + ratio + " * (u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1]),		\n"
					"		in_X[2], in_X[3]);													\n"
					"		X = vec2(in_X);														\n"
					"		X_mov = vec2(gl_Position);											\n"
					"		UV = in_UV; }														\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core									\n"
				"	layout (location = 0) in vec4 in_X;					\n"
				"	layout (location = 1) in vec2 in_UV;				\n"
				"	out vec2 X;											\n"
				"	out vec2 X_mov;										\n"
				"	out vec2 UV;										\n"
				"	uniform vec4 u_X;									\n"
				"	void main() { gl_Position = vec4(					\n"
				"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],	\n"
				"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1],	\n"
				"		in_X[2], in_X[3]);								\n"
				"		X = vec2(in_X);									\n"
				"		X_mov = vec2(gl_Position);						\n"
				"		UV = in_UV; }									\n"
				;
		}
	}
	std::string source_vertex_texture_affine(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core																					\n"
					"	layout (location = 0) in vec4 in_X;																	\n"
					"	layout (location = 1) in vec2 in_UV;																\n"
					"	out vec2 X;																							\n"
					"	out vec2 X_mov;																						\n"
					"	out vec2 UV;																						\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		" + ratio + " * (u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3]))),	\n"
					"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])), in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);																					\n"
					"		X_mov = vec2(gl_Position);																		\n"
					"		UV = in_UV; }																					\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core																					\n"
					"	layout (location = 0) in vec4 in_X;																	\n"
					"	layout (location = 1) in vec2 in_UV;																\n"
					"	out vec2 X;																							\n"
					"	out vec2 X_mov;																						\n"
					"	out vec2 UV;																						\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),						\n"
					"		" + ratio + " * (u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3]))),	\n"
					"		in_X[2], in_X[3]);																				\n"
					"		X = vec2(in_X);																					\n"
					"		X_mov = vec2(gl_Position);																		\n"
					"		UV = in_UV; }																					\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core																\n"
				"	layout (location = 0) in vec4 in_X;												\n"
				"	layout (location = 1) in vec2 in_UV;											\n"
				"	out vec2 X;																		\n"
				"	out vec2 X_mov;																	\n"
				"	out vec2 UV;																	\n"
				"	uniform vec4 u_X0;																\n"
				"	uniform vec4 u_X1;																\n"
				"	void main() { gl_Position  = vec4(												\n"
				"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),	\n"
				"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])),	\n"
				"		in_X[2], in_X[3]);															\n"
				"		X = vec2(in_X);																\n"
				"		X_mov = vec2(gl_Position);													\n"
				"		UV = in_UV; }																\n"
				;
		}
	}

	std::string source_vertex_mapped_identity(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core											\n"
					"	layout (location = 0) in vec4 in_X;							\n"
					"	layout (location = 1) in vec2 in_UV;						\n"
					"	layout (location = 2) in vec2 in_T0;						\n"
					"	layout (location = 3) in vec2 in_T1;						\n"
					"	out vec2 X;													\n"
					"	out vec2 UV;												\n"
					"   out vec2 T0;												\n"
					"   out vec2 T1;												\n"
					"	void main() { gl_Position = vec4(							\n"
					"		" + ratio + " * in_X[0], in_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);											\n"
					"		UV = in_UV;												\n"
					"		T0 = in_T0;												\n"
					"		T1 = in_T1; }											\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"   #version 330 core											\n"
					"   layout (location = 0) in vec4 in_X;							\n"
					"   layout (location = 1) in vec2 in_UV;						\n"
					"	layout (location = 2) in vec2 in_T0;						\n"
					"	layout (location = 3) in vec2 in_T1;						\n"
					"	out vec2 X;													\n"
					"   out vec2 UV;												\n"
					"   out vec2 T0;												\n"
					"   out vec2 T1;												\n"
					"	void main() { gl_Position = vec4(							\n"
					"		in_X[0], " + ratio + " * in_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);											\n"
					"		UV = in_UV;												\n"
					"		T0 = in_T0;												\n"
					"		T1 = in_T1; }											\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core						\n"
				"	layout (location = 0) in vec4 in_X;		\n"
				"	layout (location = 1) in vec2 in_UV;	\n"
				"	layout (location = 2) in vec2 in_T0;	\n"
				"	layout (location = 3) in vec2 in_T1;	\n"
				"	out vec2 X;								\n"
				"	out vec2 UV;							\n"
				"   out vec2 T0;							\n"
				"   out vec2 T1;							\n"
				"	void main() {							\n"
				"		gl_Position = in_X;					\n"
				"		X = vec2(in_X);						\n"
				"		UV = in_UV;							\n"
				"		T0 = in_T0;							\n"
				"		T1 = in_T1; }						\n"
				;
		}
	}
	std::string source_vertex_mapped_shift(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec2 in_UV;				\n"
					"	layout (location = 2) in vec2 in_T0;				\n"
					"	layout (location = 3) in vec2 in_T1;				\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec2 UV;										\n"
					"   out vec2 T0;										\n"
					"   out vec2 T1;										\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (in_X[0] + u_X[0]),				\n"
					"		in_X[1] + u_X[1], in_X[2], in_X[3]);			\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		UV = in_UV;										\n"
					"		T0 = in_T0;										\n"
					"		T1 = in_T1; }									\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec2 in_UV;				\n"
					"	layout (location = 2) in vec2 in_T0;				\n"
					"	layout (location = 3) in vec2 in_T1;				\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec2 UV;										\n"
					"   out vec2 T0;										\n"
					"   out vec2 T1;										\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		in_X[0] + u_X[0],								\n"
					"		" + ratio + " * (in_X[1] + u_X[1]),				\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		UV = in_UV;										\n"
					"		T0 = in_T0;										\n"
					"		T1 = in_T1; }									\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core						\n"
				"	layout (location = 0) in vec4 in_X;		\n"
				"	layout (location = 1) in vec2 in_UV;	\n"
				"	layout (location = 2) in vec2 in_T0;	\n"
				"	layout (location = 3) in vec2 in_T1;	\n"
				"	out vec2 X;								\n"
				"	out vec2 X_mov;							\n"
				"	out vec2 UV;							\n"
				"   out vec2 T0;							\n"
				"   out vec2 T1;							\n"
				"	uniform vec2 u_X;						\n"
				"	void main() { gl_Position = vec4(		\n"
				"		in_X[0] + u_X[0],					\n"
				"		in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
				"		X_mov = vec2(gl_Position);			\n"
				"		UV = in_UV;							\n"
				"		T0 = in_T0;							\n"
				"		T1 = in_T1; }						\n"
				;
		}
	}
	std::string source_vertex_mapped_shift_scale(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec2 in_UV;				\n"
					"	layout (location = 2) in vec2 in_T0;				\n"
					"	layout (location = 3) in vec2 in_T1;				\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec2 UV;										\n"
					"   out vec2 T0;										\n"
					"   out vec2 T1;										\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (u_X[2] * in_X[0] + u_X[0]),	\n"
					"		u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		UV = in_UV;										\n"
					"		T0 = in_T0;										\n"
					"		T1 = in_T1; }									\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	layout (location = 1) in vec2 in_UV;				\n"
					"	layout (location = 2) in vec2 in_T0;				\n"
					"	layout (location = 3) in vec2 in_T1;				\n"
					"	out vec2 X;											\n"
					"	out vec2 X_mov;										\n"
					"	out vec2 UV;										\n"
					"   out vec2 T0;										\n"
					"   out vec2 T1;										\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		u_X[2] * in_X[0] + u_X[0],						\n"
					"		" + ratio + " * (u_X[2] * in_X[1] + u_X[1]),	\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
					"		X_mov = vec2(gl_Position);						\n"
					"		UV = in_UV;										\n"
					"		T1 = in_T1;										\n"
					"		T0 = in_T0; }									\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core									\n"
				"	layout (location = 0) in vec4 in_X;					\n"
				"	layout (location = 1) in vec2 in_UV;				\n"
				"	layout (location = 2) in vec2 in_T0;				\n"
				"	layout (location = 3) in vec2 in_T1;				\n"
				"	out vec2 X;											\n"
				"	out vec2 X_mov;										\n"
				"	out vec2 UV;										\n"
				"   out vec2 T0;										\n"
				"   out vec2 T1;										\n"
				"	uniform vec3 u_X;									\n"
				"	void main() { gl_Position = vec4(					\n"
				"		u_X[2] * in_X[0] + u_X[0],						\n"
				"		u_X[2] * in_X[1] + u_X[1],						\n"
				"		in_X[2], in_X[3]);								\n"
				"		X = vec2(in_X);									\n"
				"		X_mov = vec2(gl_Position);						\n"
				"		UV = in_UV;										\n"
				"		T1 = in_T1;										\n"
				"		T0 = in_T0; }									\n"
				;
		}
	}
	std::string source_vertex_mapped_shift_rotate(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core														\n"
					"	layout (location = 0) in vec4 in_X;										\n"
					"	layout (location = 1) in vec2 in_UV;									\n"
					"	layout (location = 2) in vec2 in_T0;									\n"
					"	layout (location = 3) in vec2 in_T1;									\n"
					"	out vec2 X;																\n"
					"	out vec2 X_mov;															\n"
					"	out vec2 UV;															\n"
					"   out vec2 T0;															\n"
					"   out vec2 T1;															\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		" + ratio + " * (u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0]),		\n"
					"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);														\n"
					"		X_mov = vec2(gl_Position);											\n"
					"		UV = in_UV;															\n"
					"		T0 = vec2(u_X[2] * in_T0[0] - u_X[3] * in_T0[1],					\n"
					"			u_X[3] * in_T0[0] + u_X[2] * in_T0[1]);							\n"
					"		T1 = vec2(u_X[2] * in_T1[0] - u_X[3] * in_T1[1],					\n"
					"			u_X[3] * in_T1[0] + u_X[2] * in_T1[1]); }						\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core														\n"
					"	layout (location = 0) in vec4 in_X;										\n"
					"	layout (location = 1) in vec2 in_UV;									\n"
					"	layout (location = 2) in vec2 in_T0;									\n"
					"	layout (location = 3) in vec2 in_T1;									\n"
					"	out vec2 X;																\n"
					"	out vec2 X_mov;															\n"
					"	out vec2 UV;															\n"
					"   out vec2 T0;															\n"
					"   out vec2 T1;															\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],						\n"
					"		" + ratio + " * (u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1]),		\n"
					"		in_X[2], in_X[3]);													\n"
					"		X = vec2(in_X);														\n"
					"		X_mov = vec2(gl_Position);											\n"
					"		UV = in_UV;															\n"
					"		T0 = vec2(u_X[2] * in_T0[0] - u_X[3] * in_T0[1],					\n"
					"			u_X[3] * in_T0[0] + u_X[2] * in_T0[1]);							\n"
					"		T1 = vec2(u_X[2] * in_T1[0] - u_X[3] * in_T1[1],					\n"
					"			u_X[3] * in_T1[0] + u_X[2] * in_T1[1]); }						\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core										\n"
				"	layout (location = 0) in vec4 in_X;						\n"
				"	layout (location = 1) in vec2 in_UV;					\n"
				"	layout (location = 2) in vec2 in_T0;					\n"
				"	layout (location = 3) in vec2 in_T1;					\n"
				"	out vec2 X;												\n"
				"	out vec2 X_mov;											\n"
				"	out vec2 UV;											\n"
				"   out vec2 T0;											\n"
				"   out vec2 T1;											\n"
				"	uniform vec4 u_X;										\n"
				"	void main() { gl_Position = vec4(						\n"
				"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],		\n"
				"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1],		\n"
				"		in_X[2], in_X[3]);									\n"
				"		X = vec2(in_X);										\n"
				"		X_mov = vec2(gl_Position);							\n"
				"		UV = in_UV;											\n"
				"		T0 = vec2(u_X[2] * in_T0[0] - u_X[3] * in_T0[1],	\n"
				"			u_X[3] * in_T0[0] + u_X[2] * in_T0[1]);			\n"
				"		T1 = vec2(u_X[2] * in_T1[0] - u_X[3] * in_T1[1],	\n"
				"			u_X[3] * in_T1[0] + u_X[2] * in_T1[1]); }		\n"
				;
		}
	}
	std::string source_vertex_mapped_affine(float screen_width, float screen_height, bool rescale_screen_coordinates)
	{
		if (rescale_screen_coordinates)
		{
			if (screen_width >= screen_height)
			{
				std::string ratio = std::to_string(screen_height / screen_width);
				return
					"	#version 330 core																					\n"
					"	layout (location = 0) in vec4 in_X;																	\n"
					"	layout (location = 1) in vec2 in_UV;																\n"
					"	layout (location = 2) in vec2 in_T0;																\n"
					"	layout (location = 3) in vec2 in_T1;																\n"
					"	out vec2 X;																							\n"
					"	out vec2 X_mov;																						\n"
					"	out vec2 UV;																						\n"
					"   out vec2 T0;																						\n"
					"   out vec2 T1;																						\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		" + ratio + " * (u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3]))),	\n"
					"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])), in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);																					\n"
					"		X_mov = vec2(gl_Position);																		\n"
					"		UV = in_UV;																						\n"
					"		T0 = vec2(u_X1[0] * in_T0[0] + u_X1[2] * in_T0[1],												\n"
					"			u_X1[1] * in_T0[0] + u_X1[3] * in_T0[1]);													\n"
					"		T1 = vec2(u_X1[0] * in_T1[0] + u_X1[2] * in_T1[1],												\n"
					"			u_X1[1] * in_T1[0] + u_X1[3] * in_T1[1]); }													\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core																					\n"
					"	layout (location = 0) in vec4 in_X;																	\n"
					"	layout (location = 1) in vec2 in_UV;																\n"
					"	layout (location = 2) in vec2 in_T0;																\n"
					"	layout (location = 3) in vec2 in_T1;																\n"
					"	out vec2 X;																							\n"
					"	out vec2 X_mov;																						\n"
					"	out vec2 UV;																						\n"
					"   out vec2 T0;																						\n"
					"   out vec2 T1;																						\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),						\n"
					"		" + ratio + " * (u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3]))),	\n"
					"		in_X[2], in_X[3]);																				\n"
					"		X = vec2(in_X);																					\n"
					"		X_mov = vec2(gl_Position);																		\n"
					"		UV = in_UV;																						\n"
					"		T0 = vec2(u_X1[0] * in_T0[0] + u_X1[2] * in_T0[1],												\n"
					"			u_X1[1] * in_T0[0] + u_X1[3] * in_T0[1]);													\n"
					"		T1 = vec2(u_X1[0] * in_T1[0] + u_X1[2] * in_T1[1],												\n"
					"			u_X1[1] * in_T1[0] + u_X1[3] * in_T1[1]); }													\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core																\n"
				"	layout (location = 0) in vec4 in_X;												\n"
				"	layout (location = 1) in vec2 in_UV;											\n"
				"	layout (location = 2) in vec2 in_T0;											\n"
				"	layout (location = 3) in vec2 in_T1;											\n"
				"	out vec2 X;																		\n"
				"	out vec2 X_mov;																	\n"
				"	out vec2 UV;																	\n"
				"   out vec2 T0;																	\n"
				"   out vec2 T1;																	\n"
				"	uniform vec4 u_X0;																\n"
				"	uniform vec4 u_X1;																\n"
				"	void main() { gl_Position  = vec4(												\n"
				"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),	\n"
				"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])),	\n"
				"		in_X[2], in_X[3]);															\n"
				"		X = vec2(in_X);																\n"
				"		X_mov = vec2(gl_Position);													\n"
				"		UV = in_UV;																	\n"
				"		T0 = vec2(u_X1[0] * in_T0[0] + u_X1[2] * in_T0[1],							\n"
				"			u_X1[1] * in_T0[0] + u_X1[3] * in_T0[1]);								\n"
				"		T1 = vec2(u_X1[0] * in_T1[0] + u_X1[2] * in_T1[1],							\n"
				"			u_X1[1] * in_T1[0] + u_X1[3] * in_T1[1]); }								\n"
				;
		}
	}


	std::string source_vertex_3d()
	{
		return
			"	#version 330 core								\n"
			"	layout (location = 0) in vec3 in_X;				\n"
			"	out vec3 X;										\n"
			"	uniform mat4 u_mvp_M;							\n"
			"	void main() {									\n"
			"		gl_Position = u_mvp_M * vec4(in_X, 1);		\n"
			"		X = in_X; }									\n"
			;
	}
	std::string source_vertex_RGB_3d()
	{
		return
			"	#version 330 core								\n"
			"	layout (location = 0) in vec3 in_X;				\n"
			"	layout (location = 1) in vec3 in_C;				\n"
			"	out vec3 X;										\n"
			"	out vec3 C;										\n"
			"	uniform mat4 u_mvp_M;							\n"
			"	void main() {									\n"
			"		gl_Position = u_mvp_M * vec4(in_X, 1);		\n"
			"		X = in_X;									\n"
			"		C = in_C; }									\n"
			;
	}
	std::string source_vertex_RGBA_3d()
	{
		return
			"	#version 330 core								\n"
			"	layout (location = 0) in vec3 in_X;				\n"
			"	layout (location = 1) in vec4 in_C;				\n"
			"	out vec3 X;										\n"
			"	out vec4 C;										\n"
			"	uniform mat4 u_mvp_M;							\n"
			"	void main() {									\n"
			"		gl_Position = u_mvp_M * vec4(in_X, 1);		\n"
			"		X = in_X;									\n"
			"		C = in_C; }									\n"
			;
	}
	std::string source_vertex_texture_3d()
	{
		return
			"	#version 330 core								\n"
			"	layout (location = 0) in vec3 in_X;				\n"
			"	layout (location = 1) in vec2 in_UV;			\n"
			"	out vec3 X;										\n"
			"	out vec2 UV;									\n"
			"	uniform mat4 u_mvp_M;							\n"
			"	void main() {									\n"
			"		gl_Position = u_mvp_M * vec4(in_X, 1);		\n"
			"		X = in_X;									\n"
			"		UV = in_UV; }								\n"
			;
	}

	std::string source_vertex_normals_3d()
	{
		return
			"	#version 330 core								\n"
			"	layout (location = 0) in vec3 in_X;				\n"
			"	layout (location = 1) in vec3 in_N;				\n"
			"	out vec3 X;										\n"
			"	out vec3 N;										\n"
			"	uniform mat4 u_mvp_M;							\n"
			"	void main() {									\n"
			"		gl_Position = u_mvp_M * vec4(in_X, 1);		\n"
			"		X = in_X;									\n"
			"		N = in_N; }									\n"
			;
	}
	std::string source_vertex_RGB_normals_3d()
	{
		return
			"	#version 330 core								\n"
			"	layout (location = 0) in vec3 in_X;				\n"
			"	layout (location = 1) in vec3 in_C;				\n"
			"	layout (location = 2) in vec3 in_N;				\n"
			"	out vec3 X;										\n"
			"	out vec3 C;										\n"
			"	out vec3 N;										\n"
			"	uniform mat4 u_mvp_M;							\n"
			"	void main() {									\n"
			"		gl_Position = u_mvp_M * vec4(in_X, 1);		\n"
			"		X = in_X;									\n"
			"		C = in_C;									\n"
			"		N = in_N; }									\n"
			;
	}
	std::string source_vertex_RGBA_normals_3d()
	{
		return
			"	#version 330 core								\n"
			"	layout (location = 0) in vec3 in_X;				\n"
			"	layout (location = 1) in vec4 in_C;				\n"
			"	layout (location = 2) in vec3 in_N;				\n"
			"	out vec3 X;										\n"
			"	out vec4 C;										\n"
			"	out vec3 N;										\n"
			"	uniform mat4 M;									\n"
			"	void main() {									\n"
			"		gl_Position = M * vec4(in_X, 1);			\n"
			"		X = in_X;									\n"
			"		C = in_C;									\n"
			"		N = in_N; }									\n"
			;
	}
	std::string source_vertex_texture_normals_3d()
	{
		return
			"	#version 330 core								\n"
			"	layout (location = 0) in vec3 in_X;				\n"
			"	layout (location = 1) in vec2 in_UV;			\n"
			"	layout (location = 2) in vec3 in_N;				\n"
			"	out vec3 X;										\n"
			"	out vec2 UV;									\n"
			"	out vec3 N;										\n"
			"	uniform mat4 u_mvp_M;							\n"
			"	void main() {									\n"
			"		gl_Position = u_mvp_M * vec4(in_X, 1);		\n"
			"		UV = in_UV;									\n"
			"		X = in_X;									\n"
			"		N = in_N; }									\n"
			;
	}
	std::string source_vertex_mapped_3d()
	{
		return
			"	#version 330 core								\n"
			"	layout (location = 0) in vec3 in_X;				\n"
			"	layout (location = 1) in vec2 in_UV;			\n"
			"	layout (location = 2) in vec3 in_T0;			\n"
			"	layout (location = 3) in vec3 in_T1;			\n"
			"	layout (location = 4) in vec3 in_N;				\n"
			"	out vec3 X;										\n"
			"	out vec2 UV;									\n"
			"	out vec3 T0;									\n"
			"	out vec3 T1;									\n"
			"	out vec3 N;										\n"
			"	uniform mat4 u_mvp_M;							\n"
			"	void main() {									\n"
			"		gl_Position = u_mvp_M * vec4(in_X, 1);		\n"
			"		X = in_X;									\n"
			"		UV = in_UV;									\n"
			"		T0 = in_T0;									\n"
			"		T1 = in_T1;									\n"
			"		N = in_N; }									\n"
			;
	}
	std::string source_vertex_lightmapped_3d()
	{
		return
			"	#version 330 core								\n"
			"	layout (location = 0) in vec3 in_X;				\n"
			"	layout (location = 1) in vec2 in_UV;			\n"
			"	layout (location = 2) in vec2 in_UV_lmap;		\n"
			"	layout (location = 3) in vec3 in_T0;			\n"
			"	layout (location = 4) in vec3 in_T1;			\n"
			"	layout (location = 5) in vec3 in_N;				\n"
			"	out vec3 X;										\n"
			"	out vec2 UV;									\n"
			"	out vec2 UV_lmap;								\n"
			"	out vec3 T0;									\n"
			"	out vec3 T1;									\n"
			"	out vec3 N;										\n"
			"	uniform mat4 u_mvp_M;							\n"
			"	void main() {									\n"
			"		gl_Position = u_mvp_M * vec4(in_X, 1);		\n"
			"		X = in_X;									\n"
			"		UV = in_UV;									\n"
			"		UV_lmap = in_UV_lmap;						\n"
			"		T0 = in_T0;									\n"
			"		T1 = in_T1;									\n"
			"		N = in_N; }									\n"
			;
	}

	std::string source_fragment_fixed_color(float R, float G, float B, float A)
	{
		std::string r = std::to_string(R);
		std::string g = std::to_string(G);
		std::string b = std::to_string(B);
		std::string a = std::to_string(A);
		return
			"	#version 330 core												\n"
			"	out vec4 color;													\n"
			"	uniform vec4 u_C;												\n"
			"	void main() {													\n"
			"		color = vec4(" + r + ", " + g + ", " + b + ", " + a + "); }	\n"
			;
	}
	std::string source_fragment_color()
	{
		return
			"	#version 330 core							\n"
			"	out vec4 color;								\n"
			"	uniform vec4 u_C;							\n"
			"	void main() { color = u_C; }				\n"
			;
	}
	std::string source_fragment_RGB()
	{
		return
			"	#version 330 core							\n"
			"	in vec3 C;									\n"
			"	out vec3 color;								\n"
			"	void main() { color = C; }					\n"
			;
	}
	std::string source_fragment_RGBA()
	{
		return
			"	#version 330 core							\n"
			"	in vec4 C;									\n"
			"	out vec4 color;								\n"
			"	void main() { color = C; }					\n"
			;
	}
	std::string source_fragment_texture()
	{
		return
			"	#version 330 core							\n"
			"	in vec2 UV;									\n"
			"	out vec4 color;								\n"
			"	uniform sampler2D Tx;						\n"
			"	void main() { color = texture(Tx, UV); }	\n"
			;
	}

	std::string source_fragment_mapped_skylight()
	{
		return
			"	#version 420 core																		\n"
			"	in vec2 UV;																				\n"
			"	in vec2 T0;																				\n"
			"	in vec2 T1;																				\n"
			"	out vec4 color;																			\n"
			"	layout (binding = 0) uniform sampler2D Tx;												\n"
			"	layout (binding = 1) uniform sampler2D nmap_Tx;											\n"
			"	uniform vec3 u_slight_dir;																\n"
			"	uniform vec3 u_slight_C;																\n"
			"	void main() 																			\n"
			"	{																						\n"
			"		vec4 nmap = texture(nmap_Tx, UV);													\n"
			"		vec3 N;																				\n"
			"		{																					\n"
			"			float coeff_T0 = nmap[0] + nmap[0] - 1.0;										\n"
			"			float coeff_T1 = nmap[1] + nmap[1] - 1.0;										\n"
			"			float coeff_2 = nmap[2] + nmap[2] - 1.0;										\n"
			"			N = normalize(vec3(coeff_T0 * T0 + coeff_T1 * T1, coeff_2));					\n"
			"		}																					\n"
			"		vec4 in_C = texture(Tx, UV);														\n"
			"		color = vec4(max(-dot(N, u_slight_dir), 0.0) * u_slight_C * vec3(in_C), in_C[3]);	\n"
			"	}																						\n"
			;
	}
	std::string source_fragment_mapped_mixlights(int number_of_pointlights)
	{
		std::string _number_of_pointlights = std::to_string(number_of_pointlights);

		return
			"	#version 420 core																		\n"
			"	in vec2 X_mov;																			\n"
			"	in vec2 UV;																				\n"
			"	in vec2 T0;																				\n"
			"	in vec2 T1;																				\n"
			"	out vec4 color;																			\n"
			"	layout (binding = 0) uniform sampler2D Tx;												\n"
			"	layout (binding = 1) uniform sampler2D nmap_Tx;											\n"
			"	uniform vec3 u_slight_dir;																\n"
			"	uniform vec3 u_slight_C;																\n"
			"	uniform vec3 u_plight_pos[" + _number_of_pointlights + "];								\n"
			"	uniform vec3 u_plight_C[" + _number_of_pointlights + "];								\n"
			"	uniform vec3 u_plight_att[" + _number_of_pointlights + "];								\n"
			"	uniform int u_first_light;																\n"
			"	uniform int u_end_light;																\n"
			"	void main() 																			\n"
			"	{																						\n"
			"		vec4 nmap = texture(nmap_Tx, UV);													\n"
			"		vec3 N;																				\n"
			"		{																					\n"
			"			float coeff_T0 = nmap[0] + nmap[0] - 1.0;										\n"
			"			float coeff_T1 = nmap[1] + nmap[1] - 1.0;										\n"
			"			float coeff_2 = nmap[2] + nmap[2] - 1.0;										\n"
			"			N = normalize(vec3(coeff_T0 * T0 + coeff_T1 * T1, coeff_2));					\n"
			"		}																					\n"

			"		vec4 in_C = texture(Tx, UV);														\n"
			"		vec3 in_C3 = vec3(in_C);															\n"

			"		vec3 color3 = max(-dot(N, u_slight_dir), 0.0) * u_slight_C * vec3(in_C);			\n"
			"		vec3 X_mov3 = vec3(X_mov, 0.0);														\n"

			"		for (int k = u_first_light; k < u_end_light; k++)									\n"
			"		{																					\n"
			"			vec3 light_dir = normalize(X_mov3 - u_plight_pos[k]);							\n"
			"			float light_dist = length(X_mov3 - u_plight_pos[k]);							\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist								\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));					\n"
			"			color3 += (att * max(-dot(N, light_dir), 0.0)) * (vec3(u_plight_C[k]) * in_C3);	\n"
			"		}																					\n"
			"		color = vec4(color3, in_C[3]);														\n"
			"	}																						\n"
			;
	}

	std::string source_fragment_color_skylight_3d()
	{
		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"
			"	uniform vec3 u_slight_dir;															\n"
			"	uniform vec3 u_slight_C;															\n"
			"	uniform mat4 u_m_M;																	\n"
			"	uniform vec4 u_C;																	\n"
			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"
			"		float dot_diff = dot(rotated_N, u_slight_dir);									\n"

			"		float diff = u_diff * max(-dot_diff, 0.0);										\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"			* pow(max(dot(normalize(u_view_pos - X),									\n"
			"			reflect(u_slight_dir, rotated_N)), 0.0), u_conc);							\n"
			"		color = max(vec4((diff + spec)													\n"
			"			* (u_slight_C * vec3(u_C)), u_C[3]), face * vec4(u_amb, 0.0));				\n"
			"	}																					\n"
			;
	}
	std::string source_fragment_RGB_skylight_3d()
	{
		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec3 N;																			\n"
			"	in vec3 C;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"
			"	uniform vec3 u_slight_dir;															\n"
			"	uniform vec3 u_slight_C;															\n"
			"	uniform mat4 u_m_M;																	\n"
			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"
			"		float dot_diff = dot(rotated_N, u_slight_dir);									\n"

			"		float diff = u_diff * max(-dot_diff, 0.0);										\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"			* pow(max(dot(normalize(u_view_pos - X),									\n"
			"			reflect(u_slight_dir, mat3(u_m_M) * N)), 0.0), u_conc);						\n"
			"		color = max(vec4((diff + spec)													\n"
			"			* (u_slight_C * C), 1.0), face * vec4(u_amb, 0.0));							\n"
			"	}																					\n"
			;
	}
	std::string source_fragment_RGBA_skylight_3d()
	{
		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec3 N;																			\n"
			"	in vec4 C;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"
			"	uniform vec3 u_slight_dir;															\n"
			"	uniform vec3 u_slight_C;															\n"
			"	uniform mat4 u_m_M;																	\n"
			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"
			"		float dot_diff = dot(rotated_N, u_slight_dir);									\n"

			"		float diff = u_diff * max(-dot_diff, 0.0);										\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"			* pow(max(dot(normalize(u_view_pos - X),									\n"
			"			reflect(u_slight_dir, mat3(u_m_M) * N)), 0.0), u_conc);						\n"
			"		color = max(vec4((diff + spec)													\n"
			"			* (u_slight_C * vec3(C)), C[3]), face * vec4(u_amb, 0.0));					\n"
			"	}																					\n"
			;
	}
	std::string source_fragment_texture_skylight_3d()
	{
		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec2 UV;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"
			"	uniform vec3 u_slight_dir;															\n"
			"	uniform vec3 u_slight_C;															\n"
			"	uniform mat4 u_m_M;																	\n"
			"	uniform sampler2D Tx;																\n"
			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"
			"		float dot_diff = dot(rotated_N, u_slight_dir);									\n"

			"		vec4 in_C = texture(Tx, UV);													\n"
			"		float diff = u_diff * max(-dot_diff, 0.0);										\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"			* pow(max(dot(normalize(u_view_pos - X),									\n"
			"			reflect(u_slight_dir, mat3(u_m_M) * N)), 0.0), u_conc);						\n"
			"		color = max(vec4((diff + spec)													\n"
			"			* (u_slight_C * vec3(in_C)), in_C[3]), face * vec4(u_amb, 0.0));			\n"
			"	}																					\n"
			;
	}

	std::string source_fragment_color_pointlights_3d(int number_of_pointlights)
	{
		std::string _number_of_pointlights = std::to_string(number_of_pointlights);

		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"

			"	uniform vec3 u_plight_pos[" + _number_of_pointlights + "];							\n"
			"	uniform vec4 u_plight_C[" + _number_of_pointlights + "];							\n"
			"	uniform vec3 u_plight_att[" + _number_of_pointlights + "];							\n"
			"	uniform int u_first_light;															\n"
			"	uniform int u_end_light;															\n"

			"	uniform mat4 u_m_M;																	\n"
			"	uniform vec4 u_C;																	\n"

			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"

			"		vec3 color3 = vec3(0.0, 0.0, 0.0);												\n"

			"		for (int k = u_first_light; k < u_end_light; k++)								\n"
			"		{																				\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);							\n"
			"			float light_dist = length(X - u_plight_pos[k]);								\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist							\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));				\n"

			"			float dot_diff = dot(rotated_N, light_dir);									\n"
			"			float diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);	\n"
			"			float spec = max(sign(-dot_diff), 0.0) * u_spec								\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);	\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * vec3(u_C));		\n"
			"		}																				\n"
			"		color = max(vec4(color3, u_C[3]), face * vec4(u_amb, 0.0));						\n"
			"	}																					\n"
			;
	}
	std::string source_fragment_RGB_pointlights_3d(int number_of_pointlights)
	{
		std::string _number_of_pointlights = std::to_string(number_of_pointlights);

		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec3 C;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"

			"	uniform vec3 u_plight_pos[" + _number_of_pointlights + "];							\n"
			"	uniform vec4 u_plight_C[" + _number_of_pointlights + "];							\n"
			"	uniform vec3 u_plight_att[" + _number_of_pointlights + "];							\n"
			"	uniform int u_first_light;															\n"
			"	uniform int u_end_light;															\n"

			"	uniform mat4 u_m_M;																	\n"

			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"

			"		vec3 color3 = vec3(0.0, 0.0, 0.0);												\n"

			"		for (int k = u_first_light; k < u_end_light; k++)								\n"
			"		{																				\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);							\n"
			"			float light_dist = length(X - u_plight_pos[k]);								\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist							\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));				\n"

			"			float dot_diff = dot(rotated_N, light_dir);									\n"
			"			float diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);	\n"
			"			float spec = max(sign(-dot_diff), 0.0) * u_spec								\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);	\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * C);				\n"
			"		}																				\n"
			"		color = max(vec4(color3, 1.0), face * vec4(u_amb, 0.0));						\n"
			"	}																					\n"
			;
	}
	std::string source_fragment_RGBA_pointlights_3d(int number_of_pointlights)
	{
		std::string _number_of_pointlights = std::to_string(number_of_pointlights);

		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec4 C;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"

			"	uniform vec3 u_plight_pos[" + _number_of_pointlights + "];							\n"
			"	uniform vec4 u_plight_C[" + _number_of_pointlights + "];							\n"
			"	uniform vec3 u_plight_att[" + _number_of_pointlights + "];							\n"
			"	uniform int u_first_light;															\n"
			"	uniform int u_end_light;															\n"

			"	uniform mat4 u_m_M;																	\n"

			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"
			"		vec3 C3 = vec3(C);																\n"

			"		vec3 color3 = vec3(0.0, 0.0, 0.0);												\n"

			"		for (int k = u_first_light; k < u_end_light; k++)								\n"
			"		{																				\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);							\n"
			"			float light_dist = length(X - u_plight_pos[k]);								\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist							\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));				\n"

			"			float dot_diff = dot(rotated_N, light_dir);									\n"
			"			float diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);	\n"
			"			float spec = max(sign(-dot_diff), 0.0) * u_spec								\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);	\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * C3);				\n"
			"		}																				\n"
			"		color = max(vec4(color3, C[3]), face * vec4(u_amb, 0.0));						\n"
			"	}																					\n"
			;
	}
	std::string source_fragment_texture_pointlights_3d(int number_of_pointlights)
	{
		std::string _number_of_pointlights = std::to_string(number_of_pointlights);

		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec2 UV;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"

			"	uniform vec3 u_plight_pos[" + _number_of_pointlights + "];							\n"
			"	uniform vec4 u_plight_C[" + _number_of_pointlights + "];							\n"
			"	uniform vec3 u_plight_att[" + _number_of_pointlights + "];							\n"
			"	uniform int u_first_light;															\n"
			"	uniform int u_end_light;															\n"

			"	uniform mat4 u_m_M;																	\n"
			"	uniform sampler2D Tx;																\n"

			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"
			"		vec4 in_C = texture(Tx, UV);													\n"
			"		vec3 in_C3 = vec3(in_C);														\n"

			"		vec3 color3 = vec3(0.0, 0.0, 0.0);												\n"

			"		for (int k = u_first_light; k < u_end_light; k++)								\n"
			"		{																				\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);							\n"
			"			float light_dist = length(X - u_plight_pos[k]);								\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist							\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));				\n"

			"			float dot_diff = dot(rotated_N, light_dir);									\n"
			"			float diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);	\n"
			"			float spec = max(sign(-dot_diff), 0.0) * u_spec								\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);	\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * in_C3);			\n"
			"		}																				\n"
			"		color = max(vec4(color3, in_C[3]), face * vec4(u_amb, 0.0));					\n"
			"	}																					\n"
			;
	}

	std::string source_fragment_color_mixlights_3d(int number_of_pointlights)
	{
		std::string _number_of_pointlights = std::to_string(number_of_pointlights);

		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"

			"	uniform vec3 u_slight_dir;															\n"
			"	uniform vec3 u_slight_C;															\n"

			"	uniform vec3 u_plight_pos[" + _number_of_pointlights + "];							\n"
			"	uniform vec4 u_plight_C[" + _number_of_pointlights + "];							\n"
			"	uniform vec3 u_plight_att[" + _number_of_pointlights + "];							\n"
			"	uniform int u_first_light;															\n"
			"	uniform int u_end_light;															\n"

			"	uniform mat4 u_m_M;																	\n"
			"	uniform vec4 u_C;																	\n"

			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"

			"		float dot_diff = dot(rotated_N, u_slight_dir);									\n"
			"		float diff = u_diff * max(-dot_diff, 0.0);										\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"			* pow(max(dot(normalize(u_view_pos - X),									\n"
			"			reflect(u_slight_dir, rotated_N)), 0.0), u_conc);							\n"
			"		vec3 color3 = (diff + spec) * (u_slight_C * vec3(u_C));							\n"

			"		for (int k = u_first_light; k < u_end_light; k++)								\n"
			"		{																				\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);							\n"
			"			float light_dist = length(X - u_plight_pos[k]);								\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist							\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));				\n"

			"			dot_diff = dot(rotated_N, light_dir);										\n"
			"			diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);			\n"
			"			spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);	\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * vec3(u_C));		\n"
			"		}																				\n"
			"		color = max(vec4(color3, u_C[3]), face * vec4(u_amb, 0.0));						\n"
			"	}																					\n"
			;
	}
	std::string source_fragment_RGB_mixlights_3d(int number_of_pointlights)
	{
		std::string _number_of_pointlights = std::to_string(number_of_pointlights);

		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec3 C;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"

			"	uniform vec3 u_slight_dir;															\n"
			"	uniform vec3 u_slight_C;															\n"

			"	uniform vec3 u_plight_pos[" + _number_of_pointlights + "];							\n"
			"	uniform vec4 u_plight_C[" + _number_of_pointlights + "];							\n"
			"	uniform vec3 u_plight_att[" + _number_of_pointlights + "];							\n"
			"	uniform int u_first_light;															\n"
			"	uniform int u_end_light;															\n"

			"	uniform mat4 u_m_M;																	\n"

			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"

			"		float dot_diff = dot(rotated_N, u_slight_dir);									\n"
			"		float diff = u_diff * max(-dot_diff, 0.0);										\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"			* pow(max(dot(normalize(u_view_pos - X),									\n"
			"			reflect(u_slight_dir, rotated_N)), 0.0), u_conc);							\n"
			"		vec3 color3 = (diff + spec) * (u_slight_C * C);									\n"

			"		for (int k = u_first_light; k < u_end_light; k++)								\n"
			"		{																				\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);							\n"
			"			float light_dist = length(X - u_plight_pos[k]);								\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist							\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));				\n"

			"			dot_diff = dot(rotated_N, light_dir);										\n"
			"			diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);			\n"
			"			spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);	\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * C);				\n"
			"		}																				\n"
			"		color = max(vec4(color3, 1.0), face * vec4(u_amb, 0.0));						\n"
			"	}																					\n"
			;
	}
	std::string source_fragment_RGBA_mixlights_3d(int number_of_pointlights)
	{
		std::string _number_of_pointlights = std::to_string(number_of_pointlights);

		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec4 C;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"

			"	uniform vec3 u_slight_dir;															\n"
			"	uniform vec3 u_slight_C;															\n"

			"	uniform vec3 u_plight_pos[" + _number_of_pointlights + "];							\n"
			"	uniform vec4 u_plight_C[" + _number_of_pointlights + "];							\n"
			"	uniform vec3 u_plight_att[" + _number_of_pointlights + "];							\n"
			"	uniform int u_first_light;															\n"
			"	uniform int u_end_light;															\n"

			"	uniform mat4 u_m_M;																	\n"

			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"
			"		vec3 C3 = vec3(C);																\n"

			"		float dot_diff = dot(rotated_N, u_slight_dir);									\n"
			"		float diff = u_diff * max(-dot_diff, 0.0);										\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"			* pow(max(dot(normalize(u_view_pos - X),									\n"
			"			reflect(u_slight_dir, rotated_N)), 0.0), u_conc);							\n"
			"		vec3 color3 = (diff + spec) * (u_slight_C * C3);								\n"

			"		for (int k = u_first_light; k < u_end_light; k++)								\n"
			"		{																				\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);							\n"
			"			float light_dist = length(X - u_plight_pos[k]);								\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist							\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));				\n"

			"			dot_diff = dot(rotated_N, light_dir);										\n"
			"			diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);			\n"
			"			spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);	\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * C3);				\n"
			"		}																				\n"
			"		color = max(vec4(color3, C[3]), face * vec4(u_amb, 0.0));						\n"
			"	}																					\n"
			;
	}
	std::string source_fragment_texture_mixlights_3d(int number_of_pointlights)
	{
		std::string _number_of_pointlights = std::to_string(number_of_pointlights);

		return
			"	#version 330 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec2 UV;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_spec;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"

			"	uniform vec3 u_slight_dir;															\n"
			"	uniform vec3 u_slight_C;															\n"

			"	uniform vec3 u_plight_pos[" + _number_of_pointlights + "];							\n"
			"	uniform vec4 u_plight_C[" + _number_of_pointlights + "];							\n"
			"	uniform vec3 u_plight_att[" + _number_of_pointlights + "];							\n"
			"	uniform int u_first_light;															\n"
			"	uniform int u_end_light;															\n"

			"	uniform mat4 u_m_M;																	\n"
			"	uniform sampler2D Tx;																\n"

			"	void main()																			\n"
			"	{																					\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 												\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"
			"		vec4 in_C = texture(Tx, UV);													\n"
			"		vec3 in_C3 = vec3(in_C);														\n"

			"		float dot_diff = dot(rotated_N, u_slight_dir);									\n"
			"		float diff = u_diff * max(-dot_diff, 0.0);										\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"			* pow(max(dot(normalize(u_view_pos - X),									\n"
			"			reflect(u_slight_dir, rotated_N)), 0.0), u_conc);							\n"
			"		vec3 color3 = (diff + spec) * (u_slight_C * in_C3);								\n"

			"		for (int k = u_first_light; k < u_end_light; k++)								\n"
			"		{																				\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);							\n"
			"			float light_dist = length(X - u_plight_pos[k]);								\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist							\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));				\n"

			"			dot_diff = dot(rotated_N, light_dir);										\n"
			"			diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);			\n"
			"			spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);	\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * in_C3);			\n"
			"		}																				\n"
			"		color = max(vec4(color3, in_C[3]), face * vec4(u_amb, 0.0));					\n"
			"	}																					\n"
			;
	}

	std::string source_fragment_mapped_3d(int number_of_pointlights)
	{
		std::string _number_of_pointlights = std::to_string(number_of_pointlights);

		return
			"	#version 420 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec2 UV;																			\n"
			"	in vec3 T0;																			\n"
			"	in vec3 T1;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"

			"	uniform vec3 u_slight_dir;															\n"
			"	uniform vec3 u_slight_C;															\n"

			"	uniform vec3 u_plight_pos[" + _number_of_pointlights + "];							\n"
			"	uniform vec4 u_plight_C[" + _number_of_pointlights + "];							\n"
			"	uniform vec3 u_plight_att[" + _number_of_pointlights + "];							\n"
			"	uniform int u_first_light;															\n"
			"	uniform int u_end_light;															\n"

			"	uniform mat4 u_m_M;																	\n"
			"	layout (binding = 0) uniform sampler2D Tx;											\n"
			"	layout (binding = 1) uniform sampler2D spec_Tx;										\n"
			"	layout (binding = 2) uniform sampler2D nmap_Tx;										\n"

			"	void main()																			\n"
			"	{																					\n"
			"		float u_spec = texture(spec_Tx, UV)[0];											\n"

			"		vec3 rotated_N; 																\n"
			"		{																				\n"
			"			mat3 u_m_M3 = mat3(u_m_M);													\n"
			"			vec4 nmap = texture(nmap_Tx, UV);											\n"
			"			float coeff_T0 = (nmap[0] + nmap[0]) - 1.0;									\n"
			"			float coeff_T1 = (nmap[1] + nmap[1]) - 1.0;									\n"
			"			rotated_N = u_m_M3 * normalize(coeff_T0 * T0 + coeff_T1 * T1 + nmap[2] * N);\n"
			"		}																				\n"

			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"
			"		vec4 in_C = texture(Tx, UV);													\n"
			"		vec3 in_C3 = vec3(in_C);														\n"

			"		float dot_diff = dot(rotated_N, u_slight_dir);									\n"
			"		float diff = u_diff * max(-dot_diff, 0.0);										\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"			* pow(max(dot(normalize(u_view_pos - X),									\n"
			"			reflect(u_slight_dir, rotated_N)), 0.0), u_conc);							\n"
			"		vec3 color3 = (diff + spec) * (u_slight_C * in_C3);								\n"

			"		for (int k = u_first_light; k < u_end_light; k++)								\n"
			"		{																				\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);							\n"
			"			float light_dist = length(X - u_plight_pos[k]);								\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist							\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));				\n"
			"			dot_diff = dot(rotated_N, light_dir);										\n"

			"			diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);			\n"
			"			spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);	\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * in_C3);			\n"
			"		}																				\n"
			"		color = max(vec4(color3, in_C[3]), face * vec4(u_amb, 0.0));					\n"
			"	}																					\n"
			;
	}
	std::string source_fragment_lightmapped_3d(int number_of_pointlights)
	{
		std::string _number_of_pointlights = std::to_string(number_of_pointlights);

		return
			"	#version 420 core																	\n"
			"	in vec3 X;																			\n"
			"	in vec2 UV;																			\n"
			"	in vec2 UV_lmap;																	\n"
			"	in vec3 T0;																			\n"
			"	in vec3 T1;																			\n"
			"	in vec3 N;																			\n"
			"	out vec4 color;																		\n"
			"	uniform float u_diff;																\n"
			"	uniform float u_conc;																\n"
			"	uniform vec3 u_view_pos;															\n"
			"	uniform vec3 u_amb;																	\n"

			"	uniform vec3 u_slight_dir;															\n"
			"	uniform vec3 u_slight_C;															\n"

			"	uniform vec3 u_plight_pos[" + _number_of_pointlights + "];							\n"
			"	uniform vec4 u_plight_C[" + _number_of_pointlights + "];							\n"
			"	uniform vec3 u_plight_att[" + _number_of_pointlights + "];							\n"
			"	uniform int u_first_light;															\n"
			"	uniform int u_end_light;															\n"

			"	uniform mat4 u_m_M;																	\n"
			"	layout (binding = 0) uniform sampler2D Tx;											\n"
			"	layout (binding = 1) uniform sampler2D spec_Tx;										\n"
			"	layout (binding = 2) uniform sampler2D nmap_Tx;										\n"
			"	layout (binding = 3) uniform sampler2D lmap_Tx;										\n"

			"	void main()																			\n"
			"	{																					\n"
			"		float u_spec = texture(spec_Tx, UV)[0];											\n"

			"		vec3 rotated_N; 																\n"
			"		{																				\n"
			"			mat3 u_m_M3 = mat3(u_m_M);													\n"
			"			vec4 nmap = texture(nmap_Tx, UV);											\n"
			"			float coeff_T0 = (nmap[0] + nmap[0]) - 1.0;									\n"
			"			float coeff_T1 = (nmap[1] + nmap[1]) - 1.0;									\n"
			"			rotated_N = u_m_M3 * normalize(coeff_T0 * T0 + coeff_T1 * T1 + nmap[2] * N);\n"
			"		}																				\n"

			"		vec3 view_dir = normalize(X - u_view_pos); 										\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, rotated_N);								\n"
			"		vec4 in_C = texture(Tx, UV);													\n"
			"		vec3 in_C3 = vec3(in_C);														\n"

			"		float dot_diff = dot(rotated_N, u_slight_dir);									\n"
			"		float diff = u_diff * max(-dot_diff, 0.0);										\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"			* pow(max(dot(normalize(u_view_pos - X),									\n"
			"			reflect(u_slight_dir, rotated_N)), 0.0), u_conc);							\n"
			"		vec3 color3 = (diff + spec) * (u_slight_C * in_C3);								\n"

			"		for (int k = u_first_light; k < u_end_light; k++)								\n"
			"		{																				\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);							\n"
			"			float light_dist = length(X - u_plight_pos[k]);								\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist							\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));				\n"
			"			dot_diff = dot(rotated_N, light_dir);										\n"

			"			diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);			\n"
			"			spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);	\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * in_C3);			\n"
			"		}																				\n"
			"		color = max(vec4(color3, in_C[3]), face * vec4(u_amb, 0.0))						\n"
			"			+ texture(lmap_Tx, UV_lmap) * in_C;											\n"
			"	}																					\n"
			;
	}


	template <class program_Ty>
	inline const program_Ty& set_uniform_1f(const program_Ty& program, const char* const uniform_variable,
		GLfloat u0)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform1f(location, u0);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_2f(const program_Ty& program, const char* const uniform_variable,
		GLfloat u0, GLfloat u1)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform2f(location, u0, u1);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_3f(const program_Ty& program, const char* const uniform_variable,
		GLfloat u0, GLfloat u1, GLfloat u2)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform3f(location, u0, u1, u2);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_4f(const program_Ty& program, const char* const uniform_variable,
		GLfloat u0, GLfloat u1, GLfloat u2, GLfloat u3)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform4f(location, u0, u1, u2, u3);
		return program;
	}

	template <class program_Ty>
	inline const program_Ty& set_uniform_2fv(const program_Ty& program, const char* const uniform_variable,
		const GLfloat* const values_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform2fv(location, 1, values_ptr);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_3fv(const program_Ty& program, const char* const uniform_variable,
		const GLfloat* const values_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform3fv(location, 1, values_ptr);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_4fv(const program_Ty& program, const char* const uniform_variable,
		const GLfloat* const values_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform4fv(location, 1, values_ptr);
		return program;
	}

	template <class program_Ty>
	inline const program_Ty& set_uniform_1i(const program_Ty& program, const char* const uniform_variable,
		GLint u0)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform1i(location, u0);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_2i(const program_Ty& program, const char* const uniform_variable,
		GLint u0, GLint u1)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform2i(location, u0, u1);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_3i(const program_Ty& program, const char* const uniform_variable,
		GLint u0, GLint u1, GLint u2)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform3i(location, u0, u1, u2);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_4i(const program_Ty& program, const char* const uniform_variable,
		GLint u0, GLint u1, GLint u2, GLint u3)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform4i(location, u0, u1, u2, u3);
		return program;
	}

	template <class program_Ty>
	inline const program_Ty& set_uniform_2iv(const program_Ty& program, const char* const uniform_variable,
		const GLint* const values_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform2iv(location, 1, values_ptr);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_3iv(const program_Ty& program, const char* const uniform_variable,
		const GLint* const values_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform3iv(location, 1, values_ptr);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_4iv(const program_Ty& program, const char* const uniform_variable,
		const GLint* const values_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform4iv(location, 1, values_ptr);
		return program;
	}

	template <class program_Ty>
	inline const program_Ty& set_uniform_1ui(const program_Ty& program, const char* const uniform_variable,
		GLuint u0)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform1ui(location, u0);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_2ui(const program_Ty& program, const char* const uniform_variable,
		GLuint u0, GLuint u1)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform2ui(location, u0, u1);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_3ui(const program_Ty& program, const char* const uniform_variable,
		GLuint u0, GLuint u1, GLuint u2)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform3ui(location, u0, u1, u2);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_4ui(const program_Ty& program, const char* const uniform_variable,
		GLuint u0, GLuint u1, GLuint u2, GLuint u3)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform4ui(location, u0, u1, u2, u3);
		return program;
	}

	template <class program_Ty>
	inline const program_Ty& set_uniform_2uiv(const program_Ty& program, const char* const uniform_variable,
		const GLuint* const values_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform2uiv(location, 1, values_ptr);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_3uiv(const program_Ty& program, const char* const uniform_variable,
		const GLuint* const values_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform3uiv(location, 1, values_ptr);
		return program;
	}
	template <class program_Ty>
	inline const program_Ty& set_uniform_4uiv(const program_Ty& program, const char* const uniform_variable,
		const GLuint* const values_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform4uiv(location, 1, values_ptr);
		return program;
	}

	inline const lnd::program& set_fragment_color(const lnd::program& program, GLfloat c0, GLfloat c1, GLfloat c2, GLfloat c3)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_C");
		glUniform4f(location, c0, c1, c2, c3);
		return program;
	}
	inline const lnd::program& set_fragment_color(const lnd::program& program, const GLfloat* const color_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_C");
		glUniform4fv(location, 1, color_ptr);
		return program;
	}
	inline const lnd::program& set_vertex_shift(const lnd::program& program, GLfloat T0, GLfloat T1)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_X");
		glUniform2f(location, T0, T1);
		return program;
	}
	inline const lnd::program& set_vertex_shift_scale(const lnd::program& program, GLfloat T0, GLfloat T1, GLfloat scale)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_X");
		glUniform3f(location, T0, T1, scale);
		return program;
	}
	inline const lnd::program& set_vertex_shift_rotate_rad(const lnd::program& program, GLfloat T0, GLfloat T1, GLfloat angle)
	{
		GLfloat C = LND_COS(angle);
		GLfloat S = LND_SIN(angle);
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_X");
		glUniform4f(location, T0, T1, C, S);
		return program;
	}
	inline const lnd::program& set_vertex_shift_rotate_deg(const lnd::program& program, GLfloat T0, GLfloat T1, GLfloat angle)
	{
		constexpr GLfloat deg_to_GLfloat = 3.14159265358979323846f / 180.0f;
		angle *= deg_to_GLfloat;
		GLfloat C = LND_COS(angle);
		GLfloat S = LND_SIN(angle);
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_X");
		glUniform4f(location, T0, T1, C, S);
		return program;
	}
	inline const lnd::program& set_vertex_affine(const lnd::program& program, GLfloat T0, GLfloat T1, GLfloat orig0, GLfloat orig1,
		GLfloat A00, GLfloat A10, GLfloat A01, GLfloat A11)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_X0");
		glUniform4f(location, T0, T1, orig0, orig1);
		location = glGetUniformLocation(program.get(), "u_X1");
		glUniform4f(location, A00, A10, A01, A11);
		return program;
	}

	inline const lnd::program& set_mvp_matrix_3d(const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_mvp_M");
		glUniformMatrix4fv(location, 1, GL_FALSE, mvp_matrix_ptr);
		return program;
	}
	inline const lnd::program& set_m_matrix_3d(const lnd::program& program, const GLfloat* const m_matrix_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_m_M");
		glUniformMatrix4fv(location, 1, GL_FALSE, m_matrix_ptr);
		return program;
	}
	inline const lnd::program& set_position_3d(const lnd::program& program, const GLfloat* const position_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_view_pos");
		glUniform3fv(location, 1, position_ptr);
		return program;
	}
	inline const lnd::program& set_mvp_position_3d(const lnd::program& program, const GLfloat* const mvp_matrix_ptr,
		const GLfloat* const position_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_mvp_M");
		glUniformMatrix4fv(location, 1, GL_FALSE, mvp_matrix_ptr);
		location = glGetUniformLocation(program.get(), "u_view_pos");
		glUniform3fv(location, 1, position_ptr);
		return program;
	}
	inline const lnd::program& set_mvp_m_position_3d(const lnd::program& program, const GLfloat* const mvp_matrix_ptr,
		const GLfloat* const m_matrix_ptr, const GLfloat* const position_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_mvp_M");
		glUniformMatrix4fv(location, 1, GL_FALSE, mvp_matrix_ptr);
		location = glGetUniformLocation(program.get(), "u_m_M");
		glUniformMatrix4fv(location, 1, GL_FALSE, m_matrix_ptr);
		location = glGetUniformLocation(program.get(), "u_view_pos");
		glUniform3fv(location, 1, position_ptr);
		return program;
	}
	inline const lnd::program& set_ambient_light_3d(const lnd::program& program, const GLfloat* const ambient_light_ptr)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_amb");
		glUniform3fv(location, 1, ambient_light_ptr);
		return program;
	}
	inline const lnd::program& set_skylight(const lnd::program& program, const GLfloat* const light_direction_ptr,
		const GLfloat* const light_color_ptr)
	{
		GLfloat factor = 1.0f / LND_SQRT(light_direction_ptr[0] * light_direction_ptr[0]
			+ light_direction_ptr[1] * light_direction_ptr[1]
			+ light_direction_ptr[2] * light_direction_ptr[2]);
		GLfloat light_direction_normalized[3] = {
			factor * light_direction_ptr[0],
			factor * light_direction_ptr[1],
			factor * light_direction_ptr[2]
		};
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_slight_dir");
		glUniform3fv(location, 1, static_cast<GLfloat*>(light_direction_normalized));
		location = glGetUniformLocation(program.get(), "u_slight_C");
		glUniform3fv(location, 1, light_color_ptr);
		return program;
	}
	inline const lnd::program& set_material_3d(const lnd::program& program, GLfloat diff_coeff, GLfloat spec_coeff, GLfloat concentration_coeff)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_diff");
		glUniform1f(location, diff_coeff);
		location = glGetUniformLocation(program.get(), "u_spec");
		glUniform1f(location, spec_coeff);
		location = glGetUniformLocation(program.get(), "u_conc");
		glUniform1f(location, concentration_coeff);
		return program;
	}
	inline const lnd::program& set_pointlight_position_3d(lnd::program& program, GLint light_number, const GLfloat* const light_position_ptr)
	{
		std::string light_number_str = std::to_string(light_number);
		program.use();
		GLint location = glGetUniformLocation(program.get(), ("u_plight_pos[" + light_number_str + "]").c_str());
		glUniform3fv(location, 1, light_position_ptr);
		return program;
	}
	inline const lnd::program& set_pointlight_properties_3d(lnd::program& program, GLint light_number, const GLfloat* const light_color_ptr,
		const GLfloat* const light_attenuation_ptr)
	{
		std::string light_number_str = std::to_string(light_number);
		program.use();
		if ((light_color_ptr != nullptr) && (light_attenuation_ptr != nullptr))
		{
			GLint location = glGetUniformLocation(program.get(), ("u_plight_C[" + light_number_str + "]").c_str());
			glUniform4fv(location, 1, light_color_ptr);
			location = glGetUniformLocation(program.get(), ("u_plight_att[" + light_number_str + "]").c_str());
			glUniform3fv(location, 1, light_attenuation_ptr);
		}
		else
		{
			GLfloat null_array[4] = { 0.0f };
			GLint location = glGetUniformLocation(program.get(), ("u_plight_C[" + light_number_str + "]").c_str());
			glUniform4fv(location, 1, static_cast<GLfloat*>(null_array));
		}
		return program;
	}
	inline const lnd::program& set_pointlights_index_range_3d(lnd::program& program, GLint u_first_light, GLint u_end_light)
	{
		program.use();
		GLint location = glGetUniformLocation(program.get(), "u_first_light");
		glUniform1i(location, u_first_light);
		location = glGetUniformLocation(program.get(), "u_end_light");
		glUniform1i(location, u_end_light);
		return program;
	}
}


// OPENGL MODES

namespace lnd
{
	// set transparency

	inline void enable_transparency()
	{
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}
	inline void disable_transparency()
	{
		glBlendFunc(GL_ONE, GL_ZERO);
	}

	// set dim

	inline void enable_3d()
	{
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		lnd::__state_instance.clear_window = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
	}
	inline void disable_3d()
	{
		glDisable(GL_DEPTH_TEST);
		lnd::__state_instance.clear_window = GL_COLOR_BUFFER_BIT;
	}

	// depth mask and buffer

	inline void enable_depth_buffer()
	{
		glDepthMask(GL_TRUE);
	}
	inline void disable_depth_buffer()
	{
		glDepthMask(GL_FALSE);
	}
	inline void reset_depth_buffer()
	{
		glClear(GL_DEPTH_BUFFER_BIT);
	}

	// face culling

	inline void enable_face_culling(bool counter_clockwise_front_faces, bool cull_back_faces)
	{
		glEnable(GL_CULL_FACE);

		if (counter_clockwise_front_faces)
		{
			glFrontFace(GL_CCW);
		}
		else
		{
			glFrontFace(GL_CW);
		}

		if (cull_back_faces)
		{
			glCullFace(GL_BACK);
		}
		else
		{
			glCullFace(GL_FRONT);
		}
	}
	inline void disable_face_culling()
	{
		glDisable(GL_CULL_FACE);
	}
}


// LOOPER AND WINDOW

namespace lnd
{
	class looper
	{

	protected:

		// calling a new frame to display

		inline void call_display()
		{
			_display_condition_var.notify_one();
		}
		inline void clear_window()
		{
			glClear(lnd::__state_instance.clear_window);
		}

		// subwindow

		inline void enter_subwindow(float X_min, float Y_min, float X_max, float Y_max)
		{
			if (_screen_width >= _screen_height)
			{
				float factor_X = 0.5f * static_cast<float>(_screen_width) * _screen_ratio_inv;
				float factor_Y = 0.5f * static_cast<float>(_screen_height);
				glViewport(static_cast<int>(factor_X * (X_min - _min_X)), static_cast<int>(factor_Y * (Y_min - _min_Y)),
					static_cast<GLsizei>(factor_X * (X_max - X_min)), static_cast<GLsizei>(factor_Y * (Y_max - Y_min)));
			}
			else
			{
				float factor_X = 0.5f * static_cast<float>(_screen_width);
				float factor_Y = 0.5f * static_cast<float>(_screen_height) * _screen_ratio;
				glViewport(static_cast<int>(factor_X * (X_min - _min_X)), static_cast<int>(factor_Y * (Y_min - _min_Y)),
					static_cast<GLsizei>(factor_X * (X_max - X_min)), static_cast<GLsizei>(factor_Y * (Y_max - Y_min)));
			}
		}
		inline void exit_subwindow()
		{
			glViewport(0, 0, static_cast<GLsizei>(_screen_width), static_cast<GLsizei>(_screen_height));
		}

		// pointer to window

		inline GLFWwindow* window_ptr() const noexcept
		{
			return lnd::__state_instance.window_ptr;
		}

		// INPUTS

		inline float mouse_X() const noexcept { return lnd::__state_instance.user_mouse_input.mouse_X; }
		inline float mouse_Y() const noexcept { return lnd::__state_instance.user_mouse_input.mouse_Y; }
		inline bool mouse_in_box(float X_min, float Y_min, float X_max, float Y_max) const noexcept
		{
			return (((X_min < lnd::__state_instance.user_mouse_input.mouse_X) && (lnd::__state_instance.user_mouse_input.mouse_X < X_max))
				&& ((Y_min < lnd::__state_instance.user_mouse_input.mouse_Y) && (lnd::__state_instance.user_mouse_input.mouse_Y < Y_max)));
		}
		inline bool mouse_in_tri(float X0, float Y0, float X1, float Y1, float X2, float Y2) const noexcept
		{
			float s = Y0 * X2 - X0 * Y2 + (Y2 - Y0) * lnd::__state_instance.user_mouse_input.mouse_X
				+ (X0 - X2) * lnd::__state_instance.user_mouse_input.mouse_Y;
			float t = X0 * Y1 - Y0 * X1 + (Y0 - Y1) * lnd::__state_instance.user_mouse_input.mouse_X
				+ (X1 - X0) * lnd::__state_instance.user_mouse_input.mouse_Y;

			if ((s < 0) != (t < 0)) { return false; }
			else
			{
				float A = Y0 * (X2 - X1) + X0 * (Y1 - Y2) + X1 * Y2 - Y1 * X2;
				return A < 0 ? (s < 0 && s + t > A) : (s > 0 && s + t < A);
			}
		}
		inline bool mouse_in_tri(const float* const tri_ptr) const noexcept
		{
			float s = *(tri_ptr + 1) * *(tri_ptr + 4) - *tri_ptr * *(tri_ptr + 5)
				+ (*(tri_ptr + 5) - *(tri_ptr + 1)) * lnd::__state_instance.user_mouse_input.mouse_X
				+ (*tri_ptr - *(tri_ptr + 4)) * lnd::__state_instance.user_mouse_input.mouse_Y;
			float t = *tri_ptr * *(tri_ptr + 3) - *(tri_ptr + 1) * *(tri_ptr + 2)
				+ (*(tri_ptr + 1) - *(tri_ptr + 3)) * lnd::__state_instance.user_mouse_input.mouse_X
				+ (*(tri_ptr + 2) - *tri_ptr) * lnd::__state_instance.user_mouse_input.mouse_Y;

			if ((s < 0) != (t < 0)) { return false; }
			else
			{
				float A = *(tri_ptr + 1) * (*(tri_ptr + 4) - *(tri_ptr + 2)) + *tri_ptr * (*(tri_ptr + 3)
					- *(tri_ptr + 5)) + *(tri_ptr + 2) * *(tri_ptr + 5) - *(tri_ptr + 3) * *(tri_ptr + 4);
				return A < 0 ? (s < 0 && s + t > A) : (s > 0 && s + t < A);
			}
		}
		inline bool mouse_in_circle(float X_orig, float Y_orig, float radius) const
		{
			float dx = lnd::__state_instance.user_mouse_input.mouse_X - X_orig;
			float dy = lnd::__state_instance.user_mouse_input.mouse_Y - Y_orig;
			return (dx * dx + dy * dy < radius* radius);
		}


		inline bool mouse_1() const noexcept { return glfwGetMouseButton(lnd::__state_instance.window_ptr, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS; }
		inline bool mouse_2() const noexcept { return glfwGetMouseButton(lnd::__state_instance.window_ptr, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS; }
		inline bool mouse_3() const noexcept { return glfwGetMouseButton(lnd::__state_instance.window_ptr, GLFW_MOUSE_BUTTON_3) == GLFW_PRESS; }
		inline bool mouse_4() const noexcept { return glfwGetMouseButton(lnd::__state_instance.window_ptr, GLFW_MOUSE_BUTTON_4) == GLFW_PRESS; }
		inline bool mouse_5() const noexcept { return glfwGetMouseButton(lnd::__state_instance.window_ptr, GLFW_MOUSE_BUTTON_5) == GLFW_PRESS; }
		inline bool mouse_6() const noexcept { return glfwGetMouseButton(lnd::__state_instance.window_ptr, GLFW_MOUSE_BUTTON_6) == GLFW_PRESS; }
		inline bool mouse_7() const noexcept { return glfwGetMouseButton(lnd::__state_instance.window_ptr, GLFW_MOUSE_BUTTON_7) == GLFW_PRESS; }
		inline bool mouse_8() const noexcept { return glfwGetMouseButton(lnd::__state_instance.window_ptr, GLFW_MOUSE_BUTTON_8) == GLFW_PRESS; }

		inline bool key_space() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_SPACE) == GLFW_PRESS; }
		inline bool key_apostrophe() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_APOSTROPHE) == GLFW_PRESS; }
		inline bool key_comma() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_COMMA) == GLFW_PRESS; }
		inline bool key_minus() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_MINUS) == GLFW_PRESS; }
		inline bool key_period() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_PERIOD) == GLFW_PRESS; }
		inline bool key_slash() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_SLASH) == GLFW_PRESS; }

		inline bool key_A() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_A) == GLFW_PRESS; }
		inline bool key_B() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_B) == GLFW_PRESS; }
		inline bool key_C() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_C) == GLFW_PRESS; }
		inline bool key_D() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_D) == GLFW_PRESS; }
		inline bool key_E() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_E) == GLFW_PRESS; }
		inline bool key_F() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F) == GLFW_PRESS; }
		inline bool key_G() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_G) == GLFW_PRESS; }
		inline bool key_H() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_H) == GLFW_PRESS; }
		inline bool key_I() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_I) == GLFW_PRESS; }
		inline bool key_J() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_J) == GLFW_PRESS; }
		inline bool key_K() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_K) == GLFW_PRESS; }
		inline bool key_L() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_L) == GLFW_PRESS; }
		inline bool key_M() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_M) == GLFW_PRESS; }
		inline bool key_N() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_N) == GLFW_PRESS; }
		inline bool key_O() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_O) == GLFW_PRESS; }
		inline bool key_P() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_P) == GLFW_PRESS; }
		inline bool key_Q() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_Q) == GLFW_PRESS; }
		inline bool key_R() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_R) == GLFW_PRESS; }
		inline bool key_S() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_S) == GLFW_PRESS; }
		inline bool key_T() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_T) == GLFW_PRESS; }
		inline bool key_U() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_U) == GLFW_PRESS; }
		inline bool key_V() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_V) == GLFW_PRESS; }
		inline bool key_W() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_W) == GLFW_PRESS; }
		inline bool key_X() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_X) == GLFW_PRESS; }
		inline bool key_Y() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_Y) == GLFW_PRESS; }
		inline bool key_Z() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_Z) == GLFW_PRESS; }

		inline bool key_0() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_0) == GLFW_PRESS; }
		inline bool key_1() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_1) == GLFW_PRESS; }
		inline bool key_2() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_2) == GLFW_PRESS; }
		inline bool key_3() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_3) == GLFW_PRESS; }
		inline bool key_4() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_4) == GLFW_PRESS; }
		inline bool key_5() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_5) == GLFW_PRESS; }
		inline bool key_6() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_6) == GLFW_PRESS; }
		inline bool key_7() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_7) == GLFW_PRESS; }
		inline bool key_8() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_8) == GLFW_PRESS; }
		inline bool key_9() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_9) == GLFW_PRESS; }

		inline bool key_pad0() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_0) == GLFW_PRESS; }
		inline bool key_pad1() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_1) == GLFW_PRESS; }
		inline bool key_pad2() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_2) == GLFW_PRESS; }
		inline bool key_pad3() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_3) == GLFW_PRESS; }
		inline bool key_pad4() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_4) == GLFW_PRESS; }
		inline bool key_pad5() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_5) == GLFW_PRESS; }
		inline bool key_pad6() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_6) == GLFW_PRESS; }
		inline bool key_pad7() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_7) == GLFW_PRESS; }
		inline bool key_pad8() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_8) == GLFW_PRESS; }
		inline bool key_pad9() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_9) == GLFW_PRESS; }

		inline bool key_add() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_ADD) == GLFW_PRESS; }
		inline bool key_sub() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS; }
		inline bool key_mul() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_MULTIPLY) == GLFW_PRESS; }
		inline bool key_div() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_DIVIDE) == GLFW_PRESS; }

		inline bool key_F1() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F1) == GLFW_PRESS; }
		inline bool key_F2() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F2) == GLFW_PRESS; }
		inline bool key_F3() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F3) == GLFW_PRESS; }
		inline bool key_F4() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F4) == GLFW_PRESS; }
		inline bool key_F5() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F5) == GLFW_PRESS; }
		inline bool key_F6() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F6) == GLFW_PRESS; }
		inline bool key_F7() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F7) == GLFW_PRESS; }
		inline bool key_F8() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F8) == GLFW_PRESS; }
		inline bool key_F9() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F9) == GLFW_PRESS; }
		inline bool key_F10() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F10) == GLFW_PRESS; }
		inline bool key_F11() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F11) == GLFW_PRESS; }
		inline bool key_F12() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_F12) == GLFW_PRESS; }

		inline bool key_escape() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_ESCAPE) == GLFW_PRESS; }
		inline bool key_enter() const noexcept {
			return (glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_ENTER) == GLFW_PRESS)
				|| (glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_KP_ENTER) == GLFW_PRESS);
		}
		inline bool key_tab() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_TAB) == GLFW_PRESS; }
		inline bool key_backspace() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_BACKSPACE) == GLFW_PRESS; }
		inline bool key_insert() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_INSERT) == GLFW_PRESS; }
		inline bool key_delete() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_DELETE) == GLFW_PRESS; }
		inline bool key_right() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_RIGHT) == GLFW_PRESS; }
		inline bool key_left() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_LEFT) == GLFW_PRESS; }
		inline bool key_down() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_DOWN) == GLFW_PRESS; }
		inline bool key_up() const noexcept { return glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_UP) == GLFW_PRESS; }
		inline bool key_alt() const noexcept {
			return (glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
				|| (glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS);
		}
		inline bool key_shift() const noexcept {
			return (glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
				|| (glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS);
		}
		inline bool key_ctrl() const noexcept {
			return (glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
				|| (glfwGetKey(lnd::__state_instance.window_ptr, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS);
		}


		inline bool mouse_1_press() const noexcept { return lnd::__state_instance.user_key_input.mouse_1_press.load(); }
		inline bool mouse_2_press() const noexcept { return lnd::__state_instance.user_key_input.mouse_2_press.load(); }
		inline bool mouse_3_press() const noexcept { return lnd::__state_instance.user_key_input.mouse_3_press.load(); }
		inline bool mouse_4_press() const noexcept { return lnd::__state_instance.user_key_input.mouse_4_press.load(); }
		inline bool mouse_5_press() const noexcept { return lnd::__state_instance.user_key_input.mouse_5_press.load(); }
		inline bool mouse_6_press() const noexcept { return lnd::__state_instance.user_key_input.mouse_6_press.load(); }
		inline bool mouse_7_press() const noexcept { return lnd::__state_instance.user_key_input.mouse_7_press.load(); }
		inline bool mouse_8_press() const noexcept { return lnd::__state_instance.user_key_input.mouse_8_press.load(); }

		inline bool key_space_press() const noexcept { return lnd::__state_instance.user_key_input.space_press.load(); }
		inline bool key_apostrophe_press() const noexcept { return lnd::__state_instance.user_key_input.apostrophe_press.load(); }
		inline bool key_comma_press() const noexcept { return lnd::__state_instance.user_key_input.comma_press.load(); }
		inline bool key_minus_press() const noexcept { return lnd::__state_instance.user_key_input.minus_press.load(); }
		inline bool key_period_press() const noexcept { return lnd::__state_instance.user_key_input.period_press.load(); }
		inline bool key_slash_press() const noexcept { return lnd::__state_instance.user_key_input.slash_press.load(); }

		inline bool key_A_press() const noexcept { return lnd::__state_instance.user_key_input.A_press.load(); }
		inline bool key_B_press() const noexcept { return lnd::__state_instance.user_key_input.B_press.load(); }
		inline bool key_C_press() const noexcept { return lnd::__state_instance.user_key_input.C_press.load(); }
		inline bool key_D_press() const noexcept { return lnd::__state_instance.user_key_input.D_press.load(); }
		inline bool key_E_press() const noexcept { return lnd::__state_instance.user_key_input.E_press.load(); }
		inline bool key_F_press() const noexcept { return lnd::__state_instance.user_key_input.F_press.load(); }
		inline bool key_G_press() const noexcept { return lnd::__state_instance.user_key_input.G_press.load(); }
		inline bool key_H_press() const noexcept { return lnd::__state_instance.user_key_input.H_press.load(); }
		inline bool key_I_press() const noexcept { return lnd::__state_instance.user_key_input.I_press.load(); }
		inline bool key_J_press() const noexcept { return lnd::__state_instance.user_key_input.J_press.load(); }
		inline bool key_K_press() const noexcept { return lnd::__state_instance.user_key_input.K_press.load(); }
		inline bool key_L_press() const noexcept { return lnd::__state_instance.user_key_input.L_press.load(); }
		inline bool key_M_press() const noexcept { return lnd::__state_instance.user_key_input.M_press.load(); }
		inline bool key_N_press() const noexcept { return lnd::__state_instance.user_key_input.N_press.load(); }
		inline bool key_O_press() const noexcept { return lnd::__state_instance.user_key_input.O_press.load(); }
		inline bool key_P_press() const noexcept { return lnd::__state_instance.user_key_input.P_press.load(); }
		inline bool key_Q_press() const noexcept { return lnd::__state_instance.user_key_input.Q_press.load(); }
		inline bool key_R_press() const noexcept { return lnd::__state_instance.user_key_input.R_press.load(); }
		inline bool key_S_press() const noexcept { return lnd::__state_instance.user_key_input.S_press.load(); }
		inline bool key_T_press() const noexcept { return lnd::__state_instance.user_key_input.T_press.load(); }
		inline bool key_U_press() const noexcept { return lnd::__state_instance.user_key_input.U_press.load(); }
		inline bool key_V_press() const noexcept { return lnd::__state_instance.user_key_input.V_press.load(); }
		inline bool key_W_press() const noexcept { return lnd::__state_instance.user_key_input.W_press.load(); }
		inline bool key_X_press() const noexcept { return lnd::__state_instance.user_key_input.X_press.load(); }
		inline bool key_Y_press() const noexcept { return lnd::__state_instance.user_key_input.Y_press.load(); }
		inline bool key_Z_press() const noexcept { return lnd::__state_instance.user_key_input.Z_press.load(); }

		inline bool key_0_press() const noexcept { return lnd::__state_instance.user_key_input.num0_press.load(); }
		inline bool key_1_press() const noexcept { return lnd::__state_instance.user_key_input.num1_press.load(); }
		inline bool key_2_press() const noexcept { return lnd::__state_instance.user_key_input.num2_press.load(); }
		inline bool key_3_press() const noexcept { return lnd::__state_instance.user_key_input.num3_press.load(); }
		inline bool key_4_press() const noexcept { return lnd::__state_instance.user_key_input.num4_press.load(); }
		inline bool key_5_press() const noexcept { return lnd::__state_instance.user_key_input.num5_press.load(); }
		inline bool key_6_press() const noexcept { return lnd::__state_instance.user_key_input.num6_press.load(); }
		inline bool key_7_press() const noexcept { return lnd::__state_instance.user_key_input.num7_press.load(); }
		inline bool key_8_press() const noexcept { return lnd::__state_instance.user_key_input.num8_press.load(); }
		inline bool key_9_press() const noexcept { return lnd::__state_instance.user_key_input.num9_press.load(); }

		inline bool key_pad0_press() const noexcept { return lnd::__state_instance.user_key_input.numpad0_press.load(); }
		inline bool key_pad1_press() const noexcept { return lnd::__state_instance.user_key_input.numpad1_press.load(); }
		inline bool key_pad2_press() const noexcept { return lnd::__state_instance.user_key_input.numpad2_press.load(); }
		inline bool key_pad3_press() const noexcept { return lnd::__state_instance.user_key_input.numpad3_press.load(); }
		inline bool key_pad4_press() const noexcept { return lnd::__state_instance.user_key_input.numpad4_press.load(); }
		inline bool key_pad5_press() const noexcept { return lnd::__state_instance.user_key_input.numpad5_press.load(); }
		inline bool key_pad6_press() const noexcept { return lnd::__state_instance.user_key_input.numpad6_press.load(); }
		inline bool key_pad7_press() const noexcept { return lnd::__state_instance.user_key_input.numpad7_press.load(); }
		inline bool key_pad8_press() const noexcept { return lnd::__state_instance.user_key_input.numpad8_press.load(); }
		inline bool key_pad9_press() const noexcept { return lnd::__state_instance.user_key_input.numpad9_press.load(); }

		inline bool key_add_press() const noexcept { return lnd::__state_instance.user_key_input.add_press.load(); }
		inline bool key_sub_press() const noexcept { return lnd::__state_instance.user_key_input.sub_press.load(); }
		inline bool key_mul_press() const noexcept { return lnd::__state_instance.user_key_input.mul_press.load(); }
		inline bool key_div_press() const noexcept { return lnd::__state_instance.user_key_input.div_press.load(); }

		inline bool key_F1_press() const noexcept { return lnd::__state_instance.user_key_input.f1_press.load(); }
		inline bool key_F2_press() const noexcept { return lnd::__state_instance.user_key_input.f2_press.load(); }
		inline bool key_F3_press() const noexcept { return lnd::__state_instance.user_key_input.f3_press.load(); }
		inline bool key_F4_press() const noexcept { return lnd::__state_instance.user_key_input.f4_press.load(); }
		inline bool key_F5_press() const noexcept { return lnd::__state_instance.user_key_input.f5_press.load(); }
		inline bool key_F6_press() const noexcept { return lnd::__state_instance.user_key_input.f6_press.load(); }
		inline bool key_F7_press() const noexcept { return lnd::__state_instance.user_key_input.f7_press.load(); }
		inline bool key_F8_press() const noexcept { return lnd::__state_instance.user_key_input.f8_press.load(); }
		inline bool key_F9_press() const noexcept { return lnd::__state_instance.user_key_input.f9_press.load(); }
		inline bool key_F10_press() const noexcept { return lnd::__state_instance.user_key_input.f10_press.load(); }
		inline bool key_F11_press() const noexcept { return lnd::__state_instance.user_key_input.f11_press.load(); }
		inline bool key_F12_press() const noexcept { return lnd::__state_instance.user_key_input.f12_press.load(); }

		inline bool key_escape_press() const noexcept { return lnd::__state_instance.user_key_input.escape_press.load(); }
		inline bool key_enter_press() const noexcept { return lnd::__state_instance.user_key_input.enter_press.load(); }
		inline bool key_tab_press() const noexcept { return lnd::__state_instance.user_key_input.tab_press.load(); }
		inline bool key_backspace_press() const noexcept { return lnd::__state_instance.user_key_input.backspace_press.load(); }
		inline bool key_insert_press() const noexcept { return lnd::__state_instance.user_key_input.insert_press.load(); }
		inline bool key_delete_press() const noexcept { return lnd::__state_instance.user_key_input.delete__press.load(); }
		inline bool key_right_press() const noexcept { return lnd::__state_instance.user_key_input.right_press.load(); }
		inline bool key_left_press() const noexcept { return lnd::__state_instance.user_key_input.left_press.load(); }
		inline bool key_down_press() const noexcept { return lnd::__state_instance.user_key_input.down_press.load(); }
		inline bool key_up_press() const noexcept { return lnd::__state_instance.user_key_input.up_press.load(); }
		inline bool key_alt_press() const noexcept { return lnd::__state_instance.user_key_input.alt_press.load(); }
		inline bool key_shift_press() const noexcept { return lnd::__state_instance.user_key_input.shift_press.load(); }
		inline bool key_ctrl_press() const noexcept { return lnd::__state_instance.user_key_input.ctrl_press.load(); }


		inline bool mouse_1_release() const noexcept { return lnd::__state_instance.user_key_input.mouse_1_release.load(); }
		inline bool mouse_2_release() const noexcept { return lnd::__state_instance.user_key_input.mouse_2_release.load(); }
		inline bool mouse_3_release() const noexcept { return lnd::__state_instance.user_key_input.mouse_3_release.load(); }
		inline bool mouse_4_release() const noexcept { return lnd::__state_instance.user_key_input.mouse_4_release.load(); }
		inline bool mouse_5_release() const noexcept { return lnd::__state_instance.user_key_input.mouse_5_release.load(); }
		inline bool mouse_6_release() const noexcept { return lnd::__state_instance.user_key_input.mouse_6_release.load(); }
		inline bool mouse_7_release() const noexcept { return lnd::__state_instance.user_key_input.mouse_7_release.load(); }
		inline bool mouse_8_release() const noexcept { return lnd::__state_instance.user_key_input.mouse_8_release.load(); }

		inline bool key_space_release() const noexcept { return lnd::__state_instance.user_key_input.space_release.load(); }
		inline bool key_apostrophe_release() const noexcept { return lnd::__state_instance.user_key_input.apostrophe_release.load(); }
		inline bool key_comma_release() const noexcept { return lnd::__state_instance.user_key_input.comma_release.load(); }
		inline bool key_minus_release() const noexcept { return lnd::__state_instance.user_key_input.minus_release.load(); }
		inline bool key_period_release() const noexcept { return lnd::__state_instance.user_key_input.period_release.load(); }
		inline bool key_slash_release() const noexcept { return lnd::__state_instance.user_key_input.slash_release.load(); }

		inline bool key_A_release() const noexcept { return lnd::__state_instance.user_key_input.A_release.load(); }
		inline bool key_B_release() const noexcept { return lnd::__state_instance.user_key_input.B_release.load(); }
		inline bool key_C_release() const noexcept { return lnd::__state_instance.user_key_input.C_release.load(); }
		inline bool key_D_release() const noexcept { return lnd::__state_instance.user_key_input.D_release.load(); }
		inline bool key_E_release() const noexcept { return lnd::__state_instance.user_key_input.E_release.load(); }
		inline bool key_F_release() const noexcept { return lnd::__state_instance.user_key_input.F_release.load(); }
		inline bool key_G_release() const noexcept { return lnd::__state_instance.user_key_input.G_release.load(); }
		inline bool key_H_release() const noexcept { return lnd::__state_instance.user_key_input.H_release.load(); }
		inline bool key_I_release() const noexcept { return lnd::__state_instance.user_key_input.I_release.load(); }
		inline bool key_J_release() const noexcept { return lnd::__state_instance.user_key_input.J_release.load(); }
		inline bool key_K_release() const noexcept { return lnd::__state_instance.user_key_input.K_release.load(); }
		inline bool key_L_release() const noexcept { return lnd::__state_instance.user_key_input.L_release.load(); }
		inline bool key_M_release() const noexcept { return lnd::__state_instance.user_key_input.M_release.load(); }
		inline bool key_N_release() const noexcept { return lnd::__state_instance.user_key_input.N_release.load(); }
		inline bool key_O_release() const noexcept { return lnd::__state_instance.user_key_input.O_release.load(); }
		inline bool key_P_release() const noexcept { return lnd::__state_instance.user_key_input.P_release.load(); }
		inline bool key_Q_release() const noexcept { return lnd::__state_instance.user_key_input.Q_release.load(); }
		inline bool key_R_release() const noexcept { return lnd::__state_instance.user_key_input.R_release.load(); }
		inline bool key_S_release() const noexcept { return lnd::__state_instance.user_key_input.S_release.load(); }
		inline bool key_T_release() const noexcept { return lnd::__state_instance.user_key_input.T_release.load(); }
		inline bool key_U_release() const noexcept { return lnd::__state_instance.user_key_input.U_release.load(); }
		inline bool key_V_release() const noexcept { return lnd::__state_instance.user_key_input.V_release.load(); }
		inline bool key_W_release() const noexcept { return lnd::__state_instance.user_key_input.W_release.load(); }
		inline bool key_X_release() const noexcept { return lnd::__state_instance.user_key_input.X_release.load(); }
		inline bool key_Y_release() const noexcept { return lnd::__state_instance.user_key_input.Y_release.load(); }
		inline bool key_Z_release() const noexcept { return lnd::__state_instance.user_key_input.Z_release.load(); }

		inline bool key_0_release() const noexcept { return lnd::__state_instance.user_key_input.num0_release.load(); }
		inline bool key_1_release() const noexcept { return lnd::__state_instance.user_key_input.num1_release.load(); }
		inline bool key_2_release() const noexcept { return lnd::__state_instance.user_key_input.num2_release.load(); }
		inline bool key_3_release() const noexcept { return lnd::__state_instance.user_key_input.num3_release.load(); }
		inline bool key_4_release() const noexcept { return lnd::__state_instance.user_key_input.num4_release.load(); }
		inline bool key_5_release() const noexcept { return lnd::__state_instance.user_key_input.num5_release.load(); }
		inline bool key_6_release() const noexcept { return lnd::__state_instance.user_key_input.num6_release.load(); }
		inline bool key_7_release() const noexcept { return lnd::__state_instance.user_key_input.num7_release.load(); }
		inline bool key_8_release() const noexcept { return lnd::__state_instance.user_key_input.num8_release.load(); }
		inline bool key_9_release() const noexcept { return lnd::__state_instance.user_key_input.num9_release.load(); }

		inline bool key_pad0_release() const noexcept { return lnd::__state_instance.user_key_input.numpad0_release.load(); }
		inline bool key_pad1_release() const noexcept { return lnd::__state_instance.user_key_input.numpad1_release.load(); }
		inline bool key_pad2_release() const noexcept { return lnd::__state_instance.user_key_input.numpad2_release.load(); }
		inline bool key_pad3_release() const noexcept { return lnd::__state_instance.user_key_input.numpad3_release.load(); }
		inline bool key_pad4_release() const noexcept { return lnd::__state_instance.user_key_input.numpad4_release.load(); }
		inline bool key_pad5_release() const noexcept { return lnd::__state_instance.user_key_input.numpad5_release.load(); }
		inline bool key_pad6_release() const noexcept { return lnd::__state_instance.user_key_input.numpad6_release.load(); }
		inline bool key_pad7_release() const noexcept { return lnd::__state_instance.user_key_input.numpad7_release.load(); }
		inline bool key_pad8_release() const noexcept { return lnd::__state_instance.user_key_input.numpad8_release.load(); }
		inline bool key_pad9_release() const noexcept { return lnd::__state_instance.user_key_input.numpad9_release.load(); }

		inline bool key_add_release() const noexcept { return lnd::__state_instance.user_key_input.add_release.load(); }
		inline bool key_sub_release() const noexcept { return lnd::__state_instance.user_key_input.sub_release.load(); }
		inline bool key_mul_release() const noexcept { return lnd::__state_instance.user_key_input.mul_release.load(); }
		inline bool key_div_release() const noexcept { return lnd::__state_instance.user_key_input.div_release.load(); }

		inline bool key_F1_release() const noexcept { return lnd::__state_instance.user_key_input.f1_release.load(); }
		inline bool key_F2_release() const noexcept { return lnd::__state_instance.user_key_input.f2_release.load(); }
		inline bool key_F3_release() const noexcept { return lnd::__state_instance.user_key_input.f3_release.load(); }
		inline bool key_F4_release() const noexcept { return lnd::__state_instance.user_key_input.f4_release.load(); }
		inline bool key_F5_release() const noexcept { return lnd::__state_instance.user_key_input.f5_release.load(); }
		inline bool key_F6_release() const noexcept { return lnd::__state_instance.user_key_input.f6_release.load(); }
		inline bool key_F7_release() const noexcept { return lnd::__state_instance.user_key_input.f7_release.load(); }
		inline bool key_F8_release() const noexcept { return lnd::__state_instance.user_key_input.f8_release.load(); }
		inline bool key_F9_release() const noexcept { return lnd::__state_instance.user_key_input.f9_release.load(); }
		inline bool key_F10_release() const noexcept { return lnd::__state_instance.user_key_input.f10_release.load(); }
		inline bool key_F11_release() const noexcept { return lnd::__state_instance.user_key_input.f11_release.load(); }
		inline bool key_F12_release() const noexcept { return lnd::__state_instance.user_key_input.f12_release.load(); }

		inline bool key_escape_release() const noexcept { return lnd::__state_instance.user_key_input.escape_release.load(); }
		inline bool key_enter_release() const noexcept { return lnd::__state_instance.user_key_input.enter_release.load(); }
		inline bool key_tab_release() const noexcept { return lnd::__state_instance.user_key_input.tab_release.load(); }
		inline bool key_backspace_release() const noexcept { return lnd::__state_instance.user_key_input.backspace_release.load(); }
		inline bool key_insert_release() const noexcept { return lnd::__state_instance.user_key_input.insert_release.load(); }
		inline bool key_delete_release() const noexcept { return lnd::__state_instance.user_key_input.delete__release.load(); }
		inline bool key_right_release() const noexcept { return lnd::__state_instance.user_key_input.right_release.load(); }
		inline bool key_left_release() const noexcept { return lnd::__state_instance.user_key_input.left_release.load(); }
		inline bool key_down_release() const noexcept { return lnd::__state_instance.user_key_input.down_release.load(); }
		inline bool key_up_release() const noexcept { return lnd::__state_instance.user_key_input.up_release.load(); }
		inline bool key_alt_release() const noexcept { return lnd::__state_instance.user_key_input.alt_release.load(); }
		inline bool key_shift_release() const noexcept { return lnd::__state_instance.user_key_input.shift_release.load(); }
		inline bool key_ctrl_release() const noexcept { return lnd::__state_instance.user_key_input.ctrl_release.load(); }


		inline void reset_key_events() const noexcept { lnd::__state_instance.user_key_input.reset_key_events(); }


		// WINDOW INFOS

		inline int screen_width() const noexcept { return _screen_width; }
		inline int screen_height() const noexcept { return _screen_height; }
		inline float timeframe() const noexcept { return _timeframe; }
		inline float screen_ratio() const noexcept { return _screen_ratio; }
		inline float screen_ratio_inv() const noexcept { return _screen_ratio_inv; }
		inline float min_X() const noexcept { return _min_X; }
		inline float max_X() const noexcept { return _max_X; }
		inline float min_Y() const noexcept { return _min_Y; }
		inline float max_Y() const noexcept { return _max_Y; }
		inline float pixel_X() const noexcept { return _pixel_X; }
		inline float pixel_Y() const noexcept { return _pixel_Y; }

		inline void clear_color(float R, float G, float B, float A)
		{
			glClearColor(R, G, B, A);
		}


		// BASIC DRAW CALLS

		inline void draw_line(const GLfloat* const vertex_ptr, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_3d(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_RGB(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_RGB_3d(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_RGBA(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_RGBA_3d(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri(const GLfloat* const vertex_ptr, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_3d(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_hollow(const GLfloat* const vertex_ptr, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, 3);
			lnd::__default_vertex_buffer.bind();
		}
		inline void draw_tri_hollow_3d(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_LOOP, 0, 3);
			lnd::__default_vertex_buffer.bind();
		}
		inline void draw_tri_RGB(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_RGB_3d(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_RGBA(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_RGBA_3d(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quad(const GLfloat* const vertex_ptr, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_quad_3d(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_quad_hollow(const GLfloat* const vertex_ptr, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, 4);
			lnd::__default_vertex_buffer.bind();
		}
		inline void draw_quad_hollow_3d(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_LOOP, 0, 4);
			lnd::__default_vertex_buffer.bind();
		}
		inline void draw_quad_RGB(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quad_RGB_3d(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quad_RGBA(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quad_RGBA_3d(const GLfloat* const vertex_ptr, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(GLfloat), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(GLfloat), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}

		inline void draw_lines(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_lines_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_lines_RGB(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_lines_RGB_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_lines_RGBA(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_lines_RGBA_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tris(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tris_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tris_RGB(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tris_RGB_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tris_RGBA(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tris_RGBA_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quads(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_quads_RGB(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quads_RGBA(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_strip(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_strip_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, vertex_count);
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_strip_RGB(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_strip_RGB_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_strip_RGBA(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_strip_RGBA_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_loop(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_loop_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_loop_RGB(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_loop_RGB_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_loop_RGBA(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_loop_RGBA_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_strip(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_strip_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_strip_RGB(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_strip_RGB_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_strip_RGBA(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_strip_RGBA_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_fan(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_fan_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_fan_RGB(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_fan_RGB_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_fan_RGBA(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_fan_RGBA_3d(const GLfloat* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const GLfloat* const color_ptr, const GLfloat* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(GLfloat)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(GLfloat)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}


		// BASIC SHADERS

		const inline lnd::shader_vertex& vertex_identity() const noexcept { return _vertex_identity; }
		const inline lnd::shader_vertex& vertex_shift() const noexcept { return _vertex_shift; } // takes uniforms
		const inline lnd::shader_vertex& vertex_shift_scale() const noexcept { return _vertex_shift_scale; } // takes uniforms
		const inline lnd::shader_vertex& vertex_shift_rotate() const noexcept { return _vertex_shift_rotate; } // takes uniforms
		const inline lnd::shader_vertex& vertex_affine() const noexcept { return _vertex_affine; } // takes uniforms
		const inline lnd::shader_vertex& vertex_3d() const noexcept { return _vertex_3d; } // takes uniforms
		const inline lnd::shader_vertex& vertex_normals_3d() const noexcept { return _vertex_normals_3d; } // takes uniforms

		const inline lnd::shader_vertex& vertex_RGB_identity() const noexcept { return _vertex_RGB_identity; }
		const inline lnd::shader_vertex& vertex_RGB_shift() const noexcept { return _vertex_RGB_shift; } // takes uniforms
		const inline lnd::shader_vertex& vertex_RGB_shift_scale() const noexcept { return _vertex_RGB_shift_scale; } // takes uniforms
		const inline lnd::shader_vertex& vertex_RGB_shift_rotate() const noexcept { return _vertex_RGB_shift_rotate; } // takes uniforms
		const inline lnd::shader_vertex& vertex_RGB_affine() const noexcept { return _vertex_RGB_affine; } // takes uniforms
		const inline lnd::shader_vertex& vertex_RGB_3d() const noexcept { return _vertex_RGB_3d; } // takes uniforms
		const inline lnd::shader_vertex& vertex_RGB_normals_3d() const noexcept { return _vertex_RGB_normals_3d; } // takes uniforms

		const inline lnd::shader_vertex& vertex_RGBA_identity() const noexcept { return _vertex_RGBA_identity; }
		const inline lnd::shader_vertex& vertex_RGBA_shift() const noexcept { return _vertex_RGBA_shift; } // takes uniforms
		const inline lnd::shader_vertex& vertex_RGBA_shift_scale() const noexcept { return _vertex_RGBA_shift_scale; } // takes uniforms
		const inline lnd::shader_vertex& vertex_RGBA_shift_rotate() const noexcept { return _vertex_RGBA_shift_rotate; } // takes uniforms
		const inline lnd::shader_vertex& vertex_RGBA_affine() const noexcept { return _vertex_RGBA_affine; } // takes uniforms
		const inline lnd::shader_vertex& vertex_RGBA_3d() const noexcept { return _vertex_RGBA_3d; } // takes uniforms
		const inline lnd::shader_vertex& vertex_RGBA_normals_3d() const noexcept { return _vertex_RGBA_normals_3d; } // takes uniforms

		const inline lnd::shader_vertex& vertex_texture_identity() const noexcept { return _vertex_texture_identity; }
		const inline lnd::shader_vertex& vertex_texture_shift() const noexcept { return _vertex_texture_shift; } // takes uniforms
		const inline lnd::shader_vertex& vertex_texture_shift_scale() const noexcept { return _vertex_texture_shift_scale; } // takes uniforms
		const inline lnd::shader_vertex& vertex_texture_shift_rotate() const noexcept { return _vertex_texture_shift_rotate; } // takes uniforms
		const inline lnd::shader_vertex& vertex_texture_affine() const noexcept { return _vertex_texture_affine; } // takes uniforms
		const inline lnd::shader_vertex& vertex_texture_3d() const noexcept { return _vertex_texture_3d; } // takes uniforms
		const inline lnd::shader_vertex& vertex_texture_normals_3d() const noexcept { return _vertex_texture_normals_3d; } // takes uniforms
		const inline lnd::shader_vertex& vertex_mapped_3d() const noexcept { return _vertex_mapped_3d; } // takes uniforms

		const inline lnd::shader_fragment& fragment_black() const noexcept { return _fragment_black; }
		const inline lnd::shader_fragment& fragment_red() const noexcept { return _fragment_red; }
		const inline lnd::shader_fragment& fragment_green() const noexcept { return _fragment_green; }
		const inline lnd::shader_fragment& fragment_blue() const noexcept { return _fragment_blue; }
		const inline lnd::shader_fragment& fragment_yellow() const noexcept { return _fragment_yellow; }
		const inline lnd::shader_fragment& fragment_magenta() const noexcept { return _fragment_magenta; }
		const inline lnd::shader_fragment& fragment_cyan() const noexcept { return _fragment_cyan; }
		const inline lnd::shader_fragment& fragment_orange() const noexcept { return _fragment_orange; }
		const inline lnd::shader_fragment& fragment_white() const noexcept { return _fragment_white; }
		const inline lnd::shader_fragment& fragment_color() const noexcept { return _fragment_color; } // takes uniforms
		const inline lnd::shader_fragment& fragment_RGB() const noexcept { return _fragment_RGB; }
		const inline lnd::shader_fragment& fragment_RGBA() const noexcept { return _fragment_RGBA; }
		const inline lnd::shader_fragment& fragment_texture() const noexcept { return _fragment_texture; }
		const inline lnd::shader_fragment& fragment_color_skylight_3d() const noexcept { return _fragment_color_skylight_3d; } // takes uniforms
		const inline lnd::shader_fragment& fragment_RGB_skylight_3d() const noexcept { return _fragment_RGB_skylight_3d; } // takes uniforms
		const inline lnd::shader_fragment& fragment_RGBA_skylight_3d() const noexcept { return _fragment_RGBA_skylight_3d; } // takes uniforms
		const inline lnd::shader_fragment& fragment_texture_skylight_3d() const noexcept { return _fragment_texture_skylight_3d; } // takes uniforms

		const inline lnd::program& program_black() const noexcept { return _program_black; }
		const inline lnd::program& program_red() const noexcept { return _program_red; }
		const inline lnd::program& program_green() const noexcept { return _program_green; }
		const inline lnd::program& program_blue() const noexcept { return _program_blue; }
		const inline lnd::program& program_yellow() const noexcept { return _program_yellow; }
		const inline lnd::program& program_magenta() const noexcept { return _program_magenta; }
		const inline lnd::program& program_cyan() const noexcept { return _program_cyan; }
		const inline lnd::program& program_orange() const noexcept { return _program_orange; }
		const inline lnd::program& program_white() const noexcept { return _program_white; }
		const inline lnd::program& program_color() const noexcept { return _program_color; } // takes uniforms
		const inline lnd::program& program_RGB() const noexcept { return _program_RGB; }
		const inline lnd::program& program_RGB_3d() const noexcept { return _program_RGB_3d; } // takes uniforms
		const inline lnd::program& program_RGBA() const noexcept { return _program_RGBA; }
		const inline lnd::program& program_RGBA_3d() const noexcept { return _program_RGBA_3d; } // takes uniforms
		const inline lnd::program& program_texture() const noexcept { return _program_texture; }
		const inline lnd::program& program_texture_3d() const noexcept { return _program_texture_3d; } // takes uniforms
		const inline lnd::program& program_color_skylight_3d() const noexcept { return _program_color_skylight_3d; } // takes uniforms
		const inline lnd::program& program_RGB_skylight_3d() const noexcept { return _program_RGB_skylight_3d; } // takes uniforms
		const inline lnd::program& program_RGBA_skylight_3d() const noexcept { return _program_RGBA_skylight_3d; } // takes uniforms
		const inline lnd::program& program_texture_skylight_3d() const noexcept { return _program_texture_skylight_3d; } // takes uniforms


		// CONSTRUCTORS AND DESTRUCTORS

		looper() = default;
		~looper() = default;
		looper(const lnd::looper&) = delete;
		lnd::looper& operator=(const lnd::looper&) = delete;
		looper(lnd::looper&&) = delete;
		lnd::looper& operator=(lnd::looper&&) = delete;

	private:

		int _screen_width = 200;
		int _screen_height = 200;
		float _timeframe = 1.0f;
		float _screen_ratio = 1.0f;
		float _screen_ratio_inv = 1.0f;
		float _min_X = -1.0f;
		float _max_X = 1.0f;
		float _min_Y = -1.0f;
		float _max_Y = 1.0f;
		float _pixel_X = 0.01f;
		float _pixel_Y = 0.01f;


		lnd::shader_vertex _vertex_identity;
		lnd::shader_vertex _vertex_shift; // takes uniforms
		lnd::shader_vertex _vertex_shift_scale; // takes uniforms
		lnd::shader_vertex _vertex_shift_rotate; // takes uniforms
		lnd::shader_vertex _vertex_affine; // takes uniforms
		lnd::shader_vertex _vertex_3d; // takes uniforms
		lnd::shader_vertex _vertex_normals_3d; // takes uniforms

		lnd::shader_vertex _vertex_RGB_identity;
		lnd::shader_vertex _vertex_RGB_shift; // takes uniforms
		lnd::shader_vertex _vertex_RGB_shift_scale; // takes uniforms
		lnd::shader_vertex _vertex_RGB_shift_rotate; // takes uniforms
		lnd::shader_vertex _vertex_RGB_affine; // takes uniforms
		lnd::shader_vertex _vertex_RGB_3d; // takes uniforms
		lnd::shader_vertex _vertex_RGB_normals_3d; // takes uniforms

		lnd::shader_vertex _vertex_RGBA_identity;
		lnd::shader_vertex _vertex_RGBA_shift; // takes uniforms
		lnd::shader_vertex _vertex_RGBA_shift_scale; // takes uniforms
		lnd::shader_vertex _vertex_RGBA_shift_rotate; // takes uniforms
		lnd::shader_vertex _vertex_RGBA_affine; // takes uniforms
		lnd::shader_vertex _vertex_RGBA_3d; // takes uniforms
		lnd::shader_vertex _vertex_RGBA_normals_3d; // takes uniforms

		lnd::shader_vertex _vertex_texture_identity;
		lnd::shader_vertex _vertex_texture_shift; // takes uniforms
		lnd::shader_vertex _vertex_texture_shift_scale; // takes uniforms
		lnd::shader_vertex _vertex_texture_shift_rotate; // takes uniforms
		lnd::shader_vertex _vertex_texture_affine; // takes uniforms
		lnd::shader_vertex _vertex_texture_3d; // takes uniforms
		lnd::shader_vertex _vertex_texture_normals_3d; // takes uniforms
		lnd::shader_vertex _vertex_mapped_3d; // takes uniforms

		lnd::shader_fragment _fragment_black;
		lnd::shader_fragment _fragment_red;
		lnd::shader_fragment _fragment_green;
		lnd::shader_fragment _fragment_blue;
		lnd::shader_fragment _fragment_yellow;
		lnd::shader_fragment _fragment_magenta;
		lnd::shader_fragment _fragment_cyan;
		lnd::shader_fragment _fragment_orange;
		lnd::shader_fragment _fragment_white;
		lnd::shader_fragment _fragment_color; // takes uniforms
		lnd::shader_fragment _fragment_RGB;
		lnd::shader_fragment _fragment_RGBA;
		lnd::shader_fragment _fragment_texture;
		lnd::shader_fragment _fragment_color_skylight_3d; // takes uniforms
		lnd::shader_fragment _fragment_RGB_skylight_3d; // takes uniforms
		lnd::shader_fragment _fragment_RGBA_skylight_3d; // takes uniforms
		lnd::shader_fragment _fragment_texture_skylight_3d; // takes uniforms

		lnd::program _program_black;
		lnd::program _program_red;
		lnd::program _program_green;
		lnd::program _program_blue;
		lnd::program _program_yellow;
		lnd::program _program_magenta;
		lnd::program _program_cyan;
		lnd::program _program_orange;
		lnd::program _program_white;
		lnd::program _program_color;
		lnd::program _program_RGB;
		lnd::program _program_RGB_3d;
		lnd::program _program_RGBA;
		lnd::program _program_RGBA_3d;
		lnd::program _program_texture;
		lnd::program _program_texture_3d;
		lnd::program _program_color_skylight_3d;
		lnd::program _program_RGB_skylight_3d;
		lnd::program _program_RGBA_skylight_3d;
		lnd::program _program_texture_skylight_3d;

	protected:

		std::condition_variable _display_condition_var;

		// do not call this function in a derived class
		void _setup_basic_infos(int new_screen_width, int new_screen_height, bool rescale_screen_coordinates, float timeframe)
		{
			_screen_width = new_screen_width;
			_screen_height = new_screen_height;
			_timeframe = timeframe;
			_screen_ratio = static_cast<float>(_screen_width) / static_cast<float>(_screen_height);
			_screen_ratio_inv = static_cast<float>(_screen_height) / static_cast<float>(_screen_width);

			if (rescale_screen_coordinates)
			{
				if (_screen_width >= _screen_height)
				{
					_min_X = -_screen_ratio;
					_max_X = _screen_ratio;
					_min_Y = -1.0f;
					_max_Y = 1.0f;
					_pixel_X = 2.0f / _screen_height;
					_pixel_Y = _pixel_X;
				}
				else
				{
					_min_X = -1.0f;
					_max_X = 1.0f;
					_min_Y = -_screen_ratio_inv;
					_max_Y = _screen_ratio_inv;
					_pixel_X = 2.0f / _screen_width;
					_pixel_Y = _pixel_X;
				}
			}
			else
			{
				_min_X = -1.0f;
				_max_X = 1.0f;
				_min_Y = -1.0f;
				_max_Y = 1.0f;
				_pixel_X = 2.0f / _screen_width;
				_pixel_Y = 2.0f / _screen_height;
			}
		}

		// do not call this function in a derived class
		void _setup_basic_shaders_and_buffers(bool rescale_screen_coordinates)
		{
			float screen_width_ps = static_cast<float>(_screen_width);
			float screen_height_ps = static_cast<float>(_screen_height);

			_vertex_identity.new_shader(lnd::source_vertex_identity(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_shift.new_shader(lnd::source_vertex_shift(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_shift_scale.new_shader(lnd::source_vertex_shift_scale(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_shift_rotate.new_shader(lnd::source_vertex_shift_rotate(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_affine.new_shader(lnd::source_vertex_affine(screen_width_ps, screen_height_ps, rescale_screen_coordinates));

			_vertex_RGB_identity.new_shader(lnd::source_vertex_RGB_identity(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_RGB_shift.new_shader(lnd::source_vertex_RGB_shift(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_RGB_shift_scale.new_shader(lnd::source_vertex_RGB_shift_scale(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_RGB_shift_rotate.new_shader(lnd::source_vertex_RGB_shift_rotate(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_RGB_affine.new_shader(lnd::source_vertex_RGB_affine(screen_width_ps, screen_height_ps, rescale_screen_coordinates));

			_vertex_RGBA_identity.new_shader(lnd::source_vertex_RGBA_identity(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_RGBA_shift.new_shader(lnd::source_vertex_RGBA_shift(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_RGBA_shift_scale.new_shader(lnd::source_vertex_RGBA_shift_scale(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_RGBA_shift_rotate.new_shader(lnd::source_vertex_RGBA_shift_rotate(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_RGBA_affine.new_shader(lnd::source_vertex_RGBA_affine(screen_width_ps, screen_height_ps, rescale_screen_coordinates));

			_vertex_texture_identity.new_shader(lnd::source_vertex_texture_identity(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_texture_shift.new_shader(lnd::source_vertex_texture_shift(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_texture_shift_scale.new_shader(lnd::source_vertex_texture_shift_scale(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_texture_shift_rotate.new_shader(lnd::source_vertex_texture_shift_rotate(screen_width_ps, screen_height_ps, rescale_screen_coordinates));
			_vertex_texture_affine.new_shader(lnd::source_vertex_texture_affine(screen_width_ps, screen_height_ps, rescale_screen_coordinates));


			_vertex_3d.new_shader(lnd::source_vertex_3d());
			_vertex_RGB_3d.new_shader(lnd::source_vertex_RGB_3d());
			_vertex_RGBA_3d.new_shader(lnd::source_vertex_RGBA_3d());
			_vertex_texture_3d.new_shader(lnd::source_vertex_texture_3d());
			_vertex_normals_3d.new_shader(lnd::source_vertex_normals_3d());
			_vertex_RGB_normals_3d.new_shader(lnd::source_vertex_RGB_normals_3d());
			_vertex_RGBA_normals_3d.new_shader(lnd::source_vertex_RGBA_normals_3d());
			_vertex_texture_normals_3d.new_shader(lnd::source_vertex_texture_normals_3d());

			_fragment_black.new_shader(source_fragment_fixed_color(0.0f, 0.0f, 0.0f, 1.0f));
			_fragment_red.new_shader(source_fragment_fixed_color(1.0f, 0.0f, 0.0f, 1.0f));
			_fragment_green.new_shader(source_fragment_fixed_color(0.0f, 1.0f, 0.0f, 1.0f));
			_fragment_blue.new_shader(source_fragment_fixed_color(0.0f, 0.0f, 1.0f, 1.0f));
			_fragment_yellow.new_shader(source_fragment_fixed_color(1.0f, 1.0f, 0.0f, 1.0f));
			_fragment_magenta.new_shader(source_fragment_fixed_color(1.0f, 0.0f, 1.0f, 1.0f));
			_fragment_cyan.new_shader(source_fragment_fixed_color(0.0f, 1.0f, 1.0f, 1.0f));
			_fragment_orange.new_shader(source_fragment_fixed_color(1.0f, 0.5f, 0.0f, 1.0f));
			_fragment_white.new_shader(source_fragment_fixed_color(1.0f, 1.0f, 1.0f, 1.0f));

			_fragment_color.new_shader(lnd::source_fragment_color());
			_fragment_RGB.new_shader(lnd::source_fragment_RGB());
			_fragment_RGBA.new_shader(lnd::source_fragment_RGBA());
			_fragment_texture.new_shader(lnd::source_fragment_texture());
			_vertex_mapped_3d.new_shader(lnd::source_vertex_mapped_3d());

			_fragment_color_skylight_3d.new_shader(lnd::source_fragment_color_skylight_3d());
			_fragment_RGB_skylight_3d.new_shader(lnd::source_fragment_RGB_skylight_3d());
			_fragment_RGBA_skylight_3d.new_shader(lnd::source_fragment_RGBA_skylight_3d());
			_fragment_texture_skylight_3d.new_shader(lnd::source_fragment_texture_skylight_3d());

			_program_black.new_program(_vertex_identity, _fragment_black);
			_program_red.new_program(_vertex_identity, _fragment_red);
			_program_green.new_program(_vertex_identity, _fragment_green);
			_program_blue.new_program(_vertex_identity, _fragment_blue);
			_program_yellow.new_program(_vertex_identity, _fragment_yellow);
			_program_magenta.new_program(_vertex_identity, _fragment_magenta);
			_program_cyan.new_program(_vertex_identity, _fragment_cyan);
			_program_orange.new_program(_vertex_identity, _fragment_orange);
			_program_white.new_program(_vertex_identity, _fragment_white);
			_program_white.new_program(_vertex_identity, _fragment_color);
			_program_RGB.new_program(_vertex_RGB_identity, _fragment_RGB);
			_program_RGB_3d.new_program(_vertex_RGB_3d, _fragment_RGB);
			_program_RGBA.new_program(_vertex_RGBA_identity, _fragment_RGBA);
			_program_RGBA_3d.new_program(_vertex_RGBA_3d, _fragment_RGBA);
			_program_texture.new_program(_vertex_texture_identity, _fragment_texture);
			_program_texture_3d.new_program(_vertex_texture_3d, _fragment_texture);
			_program_color_skylight_3d.new_program(_vertex_normals_3d, _fragment_color_skylight_3d);
			_program_RGB_skylight_3d.new_program(_vertex_RGB_normals_3d, _fragment_RGB_skylight_3d);
			_program_RGBA_skylight_3d.new_program(_vertex_RGBA_normals_3d, _fragment_RGBA_skylight_3d);
			_program_texture_skylight_3d.new_program(_vertex_texture_normals_3d, _fragment_texture_skylight_3d);

			lnd::__default_vertex_buffer.new_id(1);
			lnd::__default_index_buffer.new_id(1);
			lnd::__default_color_buffer.new_id(1);
			lnd::__default_texture_coord_buffer.new_id(1);
		}

		// do not call this function in a derived class
		void _delete_basic_shaders_and_buffers()
		{
			_vertex_identity.delete_shader();
			_vertex_shift.delete_shader();
			_vertex_shift_scale.delete_shader();
			_vertex_shift_rotate.delete_shader();
			_vertex_affine.delete_shader();
			_vertex_3d.delete_shader();
			_vertex_normals_3d.delete_shader();

			_vertex_RGB_identity.delete_shader();
			_vertex_RGB_shift.delete_shader();
			_vertex_RGB_shift_scale.delete_shader();
			_vertex_RGB_shift_rotate.delete_shader();
			_vertex_RGB_affine.delete_shader();
			_vertex_RGB_3d.delete_shader();
			_vertex_RGB_normals_3d.delete_shader();

			_vertex_RGBA_identity.delete_shader();
			_vertex_RGBA_shift.delete_shader();
			_vertex_RGBA_shift_scale.delete_shader();
			_vertex_RGBA_shift_rotate.delete_shader();
			_vertex_RGBA_affine.delete_shader();
			_vertex_RGBA_3d.delete_shader();
			_vertex_RGBA_normals_3d.delete_shader();

			_vertex_texture_identity.delete_shader();
			_vertex_texture_shift.delete_shader();
			_vertex_texture_shift_scale.delete_shader();
			_vertex_texture_shift_rotate.delete_shader();
			_vertex_texture_affine.delete_shader();
			_vertex_texture_3d.delete_shader();
			_vertex_texture_normals_3d.delete_shader();

			_fragment_black.delete_shader();
			_fragment_red.delete_shader();
			_fragment_green.delete_shader();
			_fragment_blue.delete_shader();
			_fragment_yellow.delete_shader();
			_fragment_magenta.delete_shader();
			_fragment_cyan.delete_shader();
			_fragment_orange.delete_shader();
			_fragment_white.delete_shader();
			_fragment_color.delete_shader();
			_fragment_RGB.delete_shader();
			_fragment_RGBA.delete_shader();
			_fragment_texture.delete_shader();
			_fragment_color_skylight_3d.delete_shader();
			_fragment_RGB_skylight_3d.delete_shader();
			_fragment_RGBA_skylight_3d.delete_shader();
			_fragment_texture_skylight_3d.delete_shader();

			_program_black.delete_program();
			_program_red.delete_program();
			_program_green.delete_program();
			_program_blue.delete_program();
			_program_yellow.delete_program();
			_program_magenta.delete_program();
			_program_cyan.delete_program();
			_program_orange.delete_program();
			_program_white.delete_program();
			_program_color.delete_program();
			_program_RGB.delete_program();
			_program_RGB_3d.delete_program();
			_program_RGBA.delete_program();
			_program_RGBA_3d.delete_program();
			_program_texture.delete_program();
			_program_texture_3d.delete_program();
			_program_color_skylight_3d.delete_program();
			_program_RGB_skylight_3d.delete_program();
			_program_RGBA_skylight_3d.delete_program();
			_program_texture_skylight_3d.delete_program();

			lnd::__default_vertex_buffer.delete_id();
			lnd::__default_index_buffer.delete_id();
			lnd::__default_color_buffer.delete_id();
			lnd::__default_texture_coord_buffer.delete_id();
		}
	};


	template <class _looper> class window : public _looper
	{

	public:

		bool show(int new_screen_width, int new_screen_height, bool rescale_screen_coordinates,
			double new_timeframe, const char* new_title)
		{
			constexpr double factor_tick_per_s = static_cast<double>(
				std::chrono::LND_CLOCK::duration::period::den
				/ std::chrono::LND_CLOCK::duration::period::num);

			constexpr double factor_s_per_tick =
				static_cast<double>(std::chrono::LND_CLOCK::duration::period::num)
				/ static_cast<double>(std::chrono::LND_CLOCK::duration::period::den);

			this->_setup_basic_infos(new_screen_width, new_screen_height,
				rescale_screen_coordinates, static_cast<float>(new_timeframe));

			if (rescale_screen_coordinates)
			{
				if (new_screen_width >= new_screen_height)
				{
					lnd::__state_instance.user_mouse_input.X_shift = 0.5 * static_cast<double>(new_screen_width);
					lnd::__state_instance.user_mouse_input.Y_shift = 0.5 * static_cast<double>(new_screen_height);
					lnd::__state_instance.user_mouse_input.X_scale = 1.0 / lnd::__state_instance.user_mouse_input.Y_shift;
					lnd::__state_instance.user_mouse_input.Y_scale = 1.0 / lnd::__state_instance.user_mouse_input.Y_shift;
				}
				else
				{
					lnd::__state_instance.user_mouse_input.X_shift = 0.5 * static_cast<double>(new_screen_width);
					lnd::__state_instance.user_mouse_input.Y_shift = 0.5 * static_cast<double>(new_screen_height);
					lnd::__state_instance.user_mouse_input.X_scale = 1.0 / lnd::__state_instance.user_mouse_input.X_shift;
					lnd::__state_instance.user_mouse_input.Y_scale = 1.0 / lnd::__state_instance.user_mouse_input.X_shift;
				}
			}
			else
			{
				lnd::__state_instance.user_mouse_input.X_shift = 0.5 * static_cast<double>(new_screen_width);
				lnd::__state_instance.user_mouse_input.Y_shift = 0.5 * static_cast<double>(new_screen_height);
				lnd::__state_instance.user_mouse_input.X_scale = 1.0 / lnd::__state_instance.user_mouse_input.X_shift;
				lnd::__state_instance.user_mouse_input.Y_scale = 1.0 / lnd::__state_instance.user_mouse_input.Y_shift;
			}

			if (!display_thread.joinable())
			{
				display_thread = std::thread(&lnd::window<_looper>::display_function, this,
					new_screen_width, new_screen_height, rescale_screen_coordinates, new_title);
			}

			while (!display_init_finished.load()) {}

			if (display_init_failed.load())
			{
				display_thread.join();
				return false;
			}

			clock_sleep_time = static_cast<std::chrono::time_point<std::chrono::LND_CLOCK>::rep>(factor_tick_per_s * new_timeframe);
			_start = std::chrono::LND_CLOCK::now();

			// loop

			while (!display_running.load()) {}

			lnd::__state_instance.user_key_input.reset_key_events();

			if (new_timeframe > 0.0)
			{
				while (true)
				{
					// frame scheduling
					while ((_stop - _start).count() < clock_sleep_time)
					{
						_stop = std::chrono::LND_CLOCK::now();
					}
					time_elapsed = factor_s_per_tick * static_cast<float>((_stop - _start).count());
					_start = std::chrono::LND_CLOCK::now();

					// loop content
					this->loop(time_elapsed);

					if (this->exit_condition() || glfwWindowShouldClose(lnd::__state_instance.window_ptr))
					{
						// exit
						display_running.store(false);
						this->_display_condition_var.notify_one();
						break;
					}
				}
			}
			else
			{
				while (true)
				{
					// frame
					_stop = std::chrono::LND_CLOCK::now();
					time_elapsed = factor_s_per_tick * static_cast<float>((_stop - _start).count());
					_start = std::chrono::LND_CLOCK::now();

					// loop content
					this->loop(time_elapsed);

					if (this->exit_condition() || glfwWindowShouldClose(lnd::__state_instance.window_ptr))
					{
						// exit
						display_running.store(false);
						this->_display_condition_var.notify_one();
						break;
					}
				}
			}

			// exit
			display_thread.join();
			lnd::__state_instance.user_key_input.reset_key_events();
			return true;
		}

		void set_window_resizable(bool _is_window_resizable)
		{
			window_resizable = _is_window_resizable;
		}
		void set_window_fullscreen(bool _is_window_fullscreen)
		{
			window_fullscreen = _is_window_fullscreen;
		}
		void set_anti_aliasing(bool _is_anti_aliasing_enabled)
		{
			window_anti_aliasing = _is_anti_aliasing_enabled;
		}

		window() = default;
		~window()
		{
			glfwInit();
			lnd::__state_instance.window_ptr = glfwCreateWindow(1, 1, "", nullptr, nullptr);
			glfwDestroyWindow(lnd::__state_instance.window_ptr);
			glfwTerminate();
			static_cast<_looper*>(static_cast<void*>(this))->~_looper();
		}
		window(const lnd::window<_looper>&) = delete;
		lnd::window<_looper>& operator=(const lnd::window<_looper>&) = delete;
		window(lnd::window<_looper>&&) = delete;
		lnd::window<_looper>& operator=(lnd::window<_looper>&&) = delete;

	private:

		void display_function(int new_screen_width, int new_screen_height,
			bool rescale_screen_coordinates, const char* new_title)
		{
			// init display

			if (!glfwInit())
			{
				display_init_failed.store(true);
				display_init_finished.store(true);
				return;
			}

			if (window_resizable) { glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE); }
			else { glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); }

			if (window_anti_aliasing) { glfwWindowHint(GLFW_SAMPLES, 4); }

			if (window_fullscreen)
			{
				lnd::__state_instance.window_ptr = glfwCreateWindow(new_screen_width, new_screen_height,
					new_title, glfwGetPrimaryMonitor(), nullptr);
			}
			else
			{
				lnd::__state_instance.window_ptr = glfwCreateWindow(new_screen_width, new_screen_height,
					new_title, nullptr, nullptr);
			}

			if (lnd::__state_instance.window_ptr == nullptr)
			{
				glfwTerminate();
				display_init_failed.store(true);
				display_init_finished.store(true);
				return;
			}
			glfwMakeContextCurrent(lnd::__state_instance.window_ptr);
			if (glewInit() != GLEW_OK)
			{
				glfwTerminate();
				display_init_failed.store(true);
				display_init_finished.store(true);
				return;
			}
			display_init_failed.store(false);
			display_init_finished.store(true);

			// inputs

			glfwSetInputMode(lnd::__state_instance.window_ptr, GLFW_STICKY_KEYS, GLFW_TRUE);
			glfwSetInputMode(lnd::__state_instance.window_ptr, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
			glfwSetKeyCallback(lnd::__state_instance.window_ptr, &lnd::key_callback);
			glfwSetMouseButtonCallback(lnd::__state_instance.window_ptr, &lnd::mouse_button_callback);
			glfwSetCursorPosCallback(lnd::__state_instance.window_ptr, &lnd::mouse_position_callback);

			// display

			glEnable(GL_BLEND);
			glBlendFunc(GL_ONE, GL_ZERO);
			if (window_anti_aliasing) { glEnable(GL_MULTISAMPLE); }

			this->_setup_basic_shaders_and_buffers(rescale_screen_coordinates);
			this->setup();
			display_running.store(true);

			lnd::__state_instance.user_key_input.reset_key_events();

			while (true)
			{
				{
					std::unique_lock<std::mutex> lock(display_mutex);
					this->_display_condition_var.wait(lock);
				}

				lnd::__state_instance.user_key_input.reset_key_events();
				glfwPollEvents();

				this->display();

				glfwSwapBuffers(lnd::__state_instance.window_ptr);

				if (!display_running.load())
				{
					this->exit();
					this->_delete_basic_shaders_and_buffers();
					glfwDestroyWindow(lnd::__state_instance.window_ptr);
					glfwTerminate();
					break;
				}
			}

			lnd::__state_instance.user_key_input.reset_key_events();
		}

		// window
		bool window_resizable = false;
		bool window_fullscreen = false;
		bool window_anti_aliasing = false;

		// time elapsed since last frame
		float time_elapsed = 0.0f;

		// clock
		std::chrono::time_point<std::chrono::LND_CLOCK> _start;
		std::chrono::time_point<std::chrono::LND_CLOCK> _stop;
		std::chrono::time_point<std::chrono::LND_CLOCK>::rep clock_sleep_time = 0;

		//display
		std::thread display_thread;
		std::mutex display_mutex;
		std::atomic<bool> display_running{ false };
		std::atomic<bool> display_init_finished{ false };
		std::atomic<bool> display_init_failed{ false };
	};
}


// STORAGE CLASSES

namespace lnd
{
	// INDEX STORAGE CLASSES

	template <std::size_t _index_count> class cluster_index
	{

	private:

		LND_INDEX(GLuint, _index_count) _storage;

	public:

		cluster_index() = default;
		~cluster_index() = default;
		cluster_index(const cluster_index<_index_count>&) = default;
		cluster_index& operator=(const cluster_index<_index_count>&) = default;
		cluster_index(cluster_index<_index_count>&&) = default;
		cluster_index& operator=(cluster_index<_index_count>&&) = default;

		cluster_index(std::initializer_list<GLuint> L)
		{
			std::copy(L.begin(), L.end(), static_cast<GLuint*>(static_cast<void*>(_storage.data())));
		}
		cluster_index& operator=(std::initializer_list<GLuint> L)
		{
			std::copy(L.begin(), L.end(), static_cast<GLuint*>(static_cast<void*>(_storage.data())));
			return *this;
		}

		inline const GLuint* data() const noexcept { return static_cast<const GLuint*>(static_cast<const void*>(_storage.data())); }
		inline GLuint* data() noexcept { return static_cast<GLuint*>(static_cast<void*>(_storage.data())); }
		inline const GLuint& operator[](std::size_t offset) const noexcept
		{
			return *(static_cast<const GLuint*>(static_cast<const void*>(_storage.data())) + offset);
		}
		inline GLuint& operator[](std::size_t offset) noexcept
		{
			return *(static_cast<GLuint*>(static_cast<void*>(_storage.data())) + offset);
		}
		inline const GLuint& operator()(std::size_t index) const noexcept
		{
			return *(static_cast<const GLuint*>(static_cast<const void*>(_storage.data())) + index);
		}
		inline GLuint& operator()(std::size_t index) noexcept
		{
			return *(static_cast<GLuint*>(static_cast<void*>(_storage.data())) + index);
		}

		constexpr std::size_t index_count() const noexcept
		{
			return _index_count;
		}
		constexpr std::size_t size() const noexcept
		{
			return _index_count;
		}
	};

	template <std::size_t _index_count_pc, class _Allocator = LND_DEFAULT_ALLOCATOR<lnd::cluster_index<_index_count_pc>>> class group_cluster_index
	{

	private:

		std::vector<lnd::cluster_index<_index_count_pc>, _Allocator> _storage;
		lnd::buffer_index buffer;

	public:

		group_cluster_index() = default;
		~group_cluster_index() = default;
		group_cluster_index(std::size_t n)
		{
			_storage = std::vector<const lnd::cluster_index<_index_count_pc>>(n, lnd::cluster_index<_index_count_pc>());
		}
		group_cluster_index(std::size_t n, const lnd::cluster_index<_index_count_pc>& rhs)
		{
			_storage = std::vector<const lnd::cluster_index<_index_count_pc>>(n, rhs);
		}
		template <class _rhs_Allocator> group_cluster_index(const group_cluster_index<_index_count_pc, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
		}
		template <class _rhs_Allocator> group_cluster_index& operator=(const group_cluster_index<_index_count_pc, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
			return *this;
		}
		template <class _rhs_Allocator> group_cluster_index(group_cluster_index<_index_count_pc, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
		}
		template <class _rhs_Allocator> group_cluster_index& operator=(group_cluster_index<_index_count_pc, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
			return *this;
		}

		inline void buffer_new_id()
		{
			buffer.new_id(1);
		}
		inline void buffer_delete_id()
		{
			buffer.delete_id();
		}
		inline void buffer_bind() const
		{
			buffer.bind();
		}
		inline void buffer_unbind() const
		{
			buffer.unbind();
		}
		inline void buffer_allocate() const
		{
			buffer.bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->size() * sizeof(GLuint), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const GLuint* const ptr, std::size_t cluster_count) const
		{
			constexpr std::size_t n = _index_count_pc * sizeof(GLuint);
			buffer.bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, n * cluster_count, ptr, GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(GLuint), this->data());
		}
		inline void buffer_update_from(const GLuint* const ptr, std::size_t cluster_count) const
		{
			constexpr std::size_t n = _index_count_pc * sizeof(GLuint);
			glNamedBufferSubData(buffer.get(), 0, n * cluster_count, ptr);
		}


		inline const GLuint* data() const noexcept { return static_cast<const GLuint*>(static_cast<const void*>(_storage.data())); }
		inline GLuint* data() noexcept { return static_cast<GLuint*>(static_cast<void*>(_storage.data())); }
		inline const GLuint& operator[](std::size_t offset) const noexcept
		{
			return *(static_cast<const GLuint*>(static_cast<const void*>(_storage.data())) + offset);
		}
		inline GLuint& operator[](std::size_t offset) noexcept
		{
			return *(static_cast<GLuint*>(static_cast<void*>(_storage.data())) + offset);
		}
		inline const GLuint& operator()(std::size_t cluster, std::size_t index) const noexcept
		{
			return *(static_cast<const GLuint*>(static_cast<const void*>(_storage.data())) + index + _index_count_pc * cluster);
		}
		inline GLuint& operator()(std::size_t cluster, std::size_t index) noexcept
		{
			return *(static_cast<GLuint*>(static_cast<void*>(_storage.data())) + index + _index_count_pc * cluster);
		}

		inline const lnd::cluster_index<_index_count_pc>* data_cluster() const noexcept
		{
			return static_cast<const lnd::cluster_index<_index_count_pc>*>(static_cast<const void*>(_storage.data()));
		}
		inline lnd::cluster_index<_index_count_pc>* data_cluster() noexcept
		{
			return static_cast<lnd::cluster_index<_index_count_pc>*>(static_cast<void*>(_storage.data()));
		}
		inline const lnd::cluster_index<_index_count_pc>& operator()(std::size_t cluster) const noexcept
		{
			return *(_storage.data() + cluster);
		}
		inline lnd::cluster_index<_index_count_pc>& operator()(std::size_t cluster) noexcept
		{
			return *(_storage.data() + cluster);
		}

		inline void resize_cluster_count(std::size_t n)
		{
			_storage.resize(n);
		}
		inline void reserve_cluster_count(std::size_t n)
		{
			_storage.reserve(n);
		}
		inline void push_back_cluster(const lnd::cluster_index<_index_count_pc>& new_cluster)
		{
			_storage.push_back(new_cluster);
		}
		inline void push_front_cluster(const lnd::cluster_index<_index_count_pc>& new_cluster)
		{
			_storage.push_front(new_cluster);
		}
		inline void pop_back_cluster()
		{
			_storage.pop_back();
		}
		inline void pop_front_cluster()
		{
			_storage.pop_front();
		}
		inline std::size_t cluster_count() const noexcept
		{
			return _storage.size();
		}
		inline std::size_t cluster_capacity() const noexcept
		{
			return _storage.capacity();
		}
		inline std::size_t index_count() const noexcept
		{
			return _index_count_pc * _storage.size();
		}
		constexpr std::size_t index_count_per_cluster() const noexcept
		{
			return _index_count_pc;
		}
		inline std::size_t size() const noexcept
		{
			return _index_count_pc * _storage.size();
		}
		inline void shrink_to_fit()
		{
			_storage.shrink_to_fit();
		}

		inline void propagate_with_offset(GLuint offset)
		{
			std::size_t n = _storage.size();
			std::size_t k;
			GLuint* pf = static_cast<GLuint*>(static_cast<void*>(_storage.data()));
			GLuint* p;
			GLuint* q = pf + _index_count_pc;
			GLuint acc = 0;
			for (std::size_t j = 1; j < n; j++)
			{
				p = pf; acc += offset;
				for (k = 0; k < _index_count_pc; k++)
				{
					*q++ = acc + (*p++);
				}
			}
		}
	};

	template <class _Allocator = LND_DEFAULT_ALLOCATOR<GLuint>> class group_index
	{

	private:

		std::vector<GLuint, _Allocator> _storage;
		lnd::buffer_index buffer;

	public:

		group_index() = default;
		~group_index() = default;
		group_index(std::size_t n)
		{
			_storage = std::vector<GLuint>(n, 0);
		}
		group_index(std::size_t n, GLuint x)
		{
			_storage = std::vector<GLuint>(n, x);
		}
		template <class _rhs_Allocator> group_index(const group_index<_rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
		}
		template <class _rhs_Allocator> group_index& operator=(const group_index<_rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
			return *this;
		}
		template <class _rhs_Allocator> group_index(group_index<_rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
		}
		template <class _rhs_Allocator> group_index& operator=(group_index<_rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
			return *this;
		}

		group_index(std::initializer_list<GLuint> L)
		{
			_storage = std::vector<GLuint, _Allocator>(L.size());
			std::copy(L.begin(), L.end(), static_cast<GLuint*>(static_cast<void*>(_storage.data())));
		}
		group_index& operator=(std::initializer_list<GLuint> L)
		{
			_storage.resize(L.size());
			std::copy(L.begin(), L.end(), static_cast<GLuint*>(static_cast<void*>(_storage.data())));
			return *this;
		}

		inline void buffer_new_id()
		{
			buffer.new_id(1);
		}
		inline void buffer_delete_id()
		{
			buffer.delete_id();
		}
		inline void buffer_bind() const
		{
			buffer.bind();
		}
		inline void buffer_unbind() const
		{
			buffer.unbind();
		}
		inline void buffer_allocate() const
		{
			buffer.bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->size() * sizeof(GLuint), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const GLuint* const ptr, std::size_t vertex_count) const
		{
			buffer.bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertex_count * sizeof(GLuint), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(GLuint), this->data());
		}
		inline void buffer_update_from(const GLuint* const ptr, std::size_t vertex_count) const
		{
			glNamedBufferSubData(buffer.get(), 0, vertex_count * sizeof(GLuint), ptr);
		}

		inline const GLuint* data() const noexcept { return static_cast<const GLuint*>(static_cast<const void*>(_storage.data())); }
		inline GLuint* data() noexcept { return static_cast<GLuint*>(static_cast<void*>(_storage.data())); }
		inline const GLuint& operator[](std::size_t offset) const noexcept
		{
			return *(static_cast<const GLuint*>(static_cast<const void*>(_storage.data())) + offset);
		}
		inline GLuint& operator[](std::size_t offset) noexcept
		{
			return *(static_cast<GLuint*>(static_cast<void*>(_storage.data())) + offset);
		}
		inline const GLuint& operator()(std::size_t index) const noexcept
		{
			return *(static_cast<const GLuint*>(static_cast<const void*>(_storage.data())) + index);
		}
		inline GLuint& operator()(std::size_t index) noexcept
		{
			return *(static_cast<GLuint*>(static_cast<void*>(_storage.data())) + index);
		}

		inline void resize_index_count(std::size_t n)
		{
			_storage.resize(n);
		}
		inline void reserve_index_count(std::size_t n)
		{
			_storage.reserve(n);
		}
		inline void push_back_index(GLuint new_index)
		{
			_storage.push_back(new_index);
		}
		inline void push_front_index(GLuint new_index)
		{
			_storage.push_front(new_index);
		}
		inline void pop_back_index()
		{
			_storage.pop_back();
		}
		inline void pop_front_index()
		{
			_storage.pop_front();
		}
		inline std::size_t index_count() const noexcept
		{
			return _storage.size();
		}
		inline std::size_t index_capacity() const noexcept
		{
			return _storage.capacity();
		}
		inline std::size_t size() const noexcept
		{
			return _storage.size();
		}
		inline void shrink_to_fit()
		{
			_storage.shrink_to_fit();
		}
	};

	// COLOR STORAGE CLASSES

	template <std::size_t _color_count_pc, std::size_t _dim> class cluster_color
	{

	private:

		std::array<LND_COLOR(GLfloat, _dim), _color_count_pc> _storage;

	public:

		cluster_color() = default;
		~cluster_color() = default;
		cluster_color(const cluster_color<_color_count_pc, _dim>&) = default;
		cluster_color& operator=(const cluster_color<_color_count_pc, _dim>&) = default;
		cluster_color(cluster_color<_color_count_pc, _dim>&&) = default;
		cluster_color& operator=(cluster_color<_color_count_pc, _dim>&&) = default;

		cluster_color(std::initializer_list<GLfloat> L)
		{
			std::copy(L.begin(), L.end(), static_cast<GLfloat*>(static_cast<void*>(_storage.data())));
		}
		cluster_color& operator=(std::initializer_list<GLfloat> L)
		{
			std::copy(L.begin(), L.end(), static_cast<GLfloat*>(static_cast<void*>(_storage.data())));
			return *this;
		}

		inline const GLfloat* data() const noexcept { return static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())); }
		inline GLfloat* data() noexcept { return static_cast<GLfloat*>(static_cast<void*>(_storage.data())); }
		inline const GLfloat& operator[](std::size_t offset) const noexcept
		{
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + offset);
		}
		inline GLfloat& operator[](std::size_t offset) noexcept
		{
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + offset);
		}
		inline const GLfloat& operator()(std::size_t color, std::size_t coord) const noexcept
		{
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + coord + _dim * color);
		}
		inline GLfloat& operator()(std::size_t color, std::size_t coord) noexcept
		{
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + coord + _dim * color);
		}

		inline const LND_COLOR(GLfloat, _dim)* data_color() const noexcept
		{
			return static_cast<const LND_COLOR(GLfloat, _dim)*>(static_cast<const void*>(_storage.data()));
		}
		inline LND_COLOR(GLfloat, _dim)* data_color() noexcept
		{
			return static_cast<LND_COLOR(GLfloat, _dim)*>(static_cast<void*>(_storage.data()));
		}
		inline const LND_COLOR(GLfloat, _dim)& operator()(std::size_t color) const noexcept
		{
			return *(static_cast<const LND_COLOR(GLfloat, _dim)*>(static_cast<const void*>(_storage.data())) + color);
		}
		inline LND_COLOR(GLfloat, _dim)& operator()(std::size_t color) noexcept
		{
			return *(static_cast<LND_COLOR(GLfloat, _dim)*>(static_cast<void*>(_storage.data())) + color);
		}

		constexpr std::size_t color_count() const noexcept
		{
			return _color_count_pc;
		}
		constexpr std::size_t dim() const noexcept
		{
			return _dim;
		}
		constexpr std::size_t size() const noexcept
		{
			return _color_count_pc * _dim;
		}
	};

	template <std::size_t _color_count_pc, std::size_t _dim, class _Allocator
		= LND_DEFAULT_ALLOCATOR<lnd::cluster_color<_color_count_pc, _dim>>>
		class group_cluster_color
	{

	private:

		std::vector<lnd::cluster_color<_color_count_pc, _dim>, _Allocator> _storage;
		lnd::buffer_color buffer;

	public:

		group_cluster_color() = default;
		~group_cluster_color() = default;
		group_cluster_color(std::size_t n)
		{
			_storage = std::vector<const lnd::cluster_color<_color_count_pc, _dim>, _Allocator>(n, lnd::cluster_color<_color_count_pc, _dim>());
		}
		group_cluster_color(std::size_t n, const lnd::cluster_color<_color_count_pc, _dim>& rhs)
		{
			_storage = std::vector<const lnd::cluster_color<_color_count_pc, _dim>, _Allocator>(n, rhs);
		}
		template <class _rhs_Allocator> group_cluster_color(const group_cluster_color<_color_count_pc, _dim, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
		}
		template <class _rhs_Allocator> group_cluster_color& operator=(const group_cluster_color<_color_count_pc, _dim, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
			return *this;
		}
		template <class _rhs_Allocator> group_cluster_color(group_cluster_color<_color_count_pc, _dim, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
		}
		template <class _rhs_Allocator> group_cluster_color& operator=(group_cluster_color<_color_count_pc, _dim, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
			return *this;
		}

		inline void buffer_new_id()
		{
			buffer.new_id(1);
		}
		inline void buffer_delete_id()
		{
			buffer.delete_id();
		}
		inline void buffer_bind() const
		{
			buffer.bind();
		}
		inline void buffer_unbind() const
		{
			buffer.unbind();
		}
		inline void buffer_allocate() const
		{
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, this->size() * sizeof(GLfloat), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const GLfloat* const ptr, std::size_t cluster_count) const
		{
			constexpr std::size_t n = _color_count_pc * _dim * sizeof(GLfloat);
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, n * cluster_count, ptr, GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(GLfloat), this->data());
		}
		inline void buffer_update_from(const GLfloat* const ptr, std::size_t cluster_count) const
		{
			constexpr std::size_t n = _color_count_pc * _dim * sizeof(GLfloat);
			glNamedBufferSubData(buffer.get(), 0, n * cluster_count, ptr);
		}

		inline const GLfloat* data() const noexcept { return static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())); }
		inline GLfloat* data() noexcept { return static_cast<GLfloat*>(static_cast<void*>(_storage.data())); }
		inline const GLfloat& operator[](std::size_t offset) const noexcept
		{
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + offset);
		}
		inline GLfloat& operator[](std::size_t offset) noexcept
		{
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + offset);
		}
		inline const GLfloat& operator()(std::size_t cluster, std::size_t color, std::size_t coord) const noexcept
		{
			constexpr std::size_t n = _color_count_pc * _dim;
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + coord + _dim * color + n * cluster);
		}
		inline GLfloat& operator()(std::size_t cluster, std::size_t color, std::size_t coord) noexcept
		{
			constexpr std::size_t n = color_count * _dim;
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + coord + _dim * color + n * cluster);
		}

		inline const LND_COLOR(GLfloat, _dim)* data_color() const noexcept
		{
			return static_cast<const LND_COLOR(GLfloat, _dim)*>(static_cast<const void*>(_storage.data()));
		}
		inline LND_COLOR(GLfloat, _dim)* data_color() noexcept
		{
			return static_cast<LND_COLOR(GLfloat, _dim)*>(static_cast<void*>(_storage.data()));
		}
		inline const LND_COLOR(GLfloat, _dim)& operator()(std::size_t cluster, std::size_t color) const noexcept
		{
			return *(static_cast<const LND_COLOR(GLfloat, _dim)*>(static_cast<const void*>(_storage.data())) + color + _color_count_pc * cluster);
		}
		inline LND_COLOR(GLfloat, _dim)& operator()(std::size_t cluster, std::size_t color) noexcept
		{
			return *(static_cast<LND_COLOR(GLfloat, _dim)*>(static_cast<void*>(_storage.data())) + color + _color_count_pc * cluster);
		}

		inline const lnd::cluster_color<_color_count_pc, _dim>* data_cluster() const noexcept
		{
			return static_cast<const lnd::cluster_color<_color_count_pc, _dim>*>(static_cast<const void*>(_storage.data()));
		}
		inline lnd::cluster_color<_color_count_pc, _dim>* data_cluster() noexcept
		{
			return static_cast<lnd::cluster_color<_color_count_pc, _dim>*>(static_cast<void*>(_storage.data()));
		}
		inline const lnd::cluster_color<_color_count_pc, _dim>& operator()(std::size_t cluster) const noexcept
		{
			return *(_storage.data() + cluster);
		}
		inline lnd::cluster_color<_color_count_pc, _dim>& operator()(std::size_t cluster) noexcept
		{
			return *(_storage.data() + cluster);
		}

		inline void resize_cluster_count(std::size_t n)
		{
			_storage.resize(n);
		}
		inline void reserve_cluster_count(std::size_t n)
		{
			_storage.reserve(n);
		}
		inline void push_back_cluster(const lnd::cluster_color<_color_count_pc, _dim>& new_cluster)
		{
			_storage.push_back(new_cluster);
		}
		inline void push_front_cluster(const lnd::cluster_color<_color_count_pc, _dim>& new_cluster)
		{
			_storage.push_front(new_cluster);
		}
		inline void pop_back_cluster()
		{
			_storage.pop_back();
		}
		inline void pop_front_cluster()
		{
			_storage.pop_front();
		}
		inline std::size_t cluster_count() const noexcept
		{
			return _storage.size();
		}
		inline std::size_t cluster_capacity() const noexcept
		{
			return _storage.capacity();
		}
		inline std::size_t color_count() const noexcept
		{
			return _color_count_pc * _storage.size();
		}
		constexpr std::size_t color_count_per_cluster() const noexcept
		{
			return _color_count_pc;
		}
		constexpr std::size_t dim() const noexcept
		{
			return _dim;
		}
		inline std::size_t size() const noexcept
		{
			constexpr std::size_t n = _color_count_pc * _dim;
			return n * _storage.size();
		}
		inline void shrink_to_fit()
		{
			_storage.shrink_to_fit();
		}
	};

	template <std::size_t _dim, class _Allocator = LND_DEFAULT_ALLOCATOR<LND_COLOR(GLfloat, _dim)>> class group_color
	{

	private:

		std::vector<LND_COLOR(GLfloat, _dim), _Allocator> _storage;
		lnd::buffer_color buffer;

	public:

		group_color() = default;
		~group_color() = default;
		group_color(std::size_t n)
		{
			_storage = std::vector<LND_COLOR(GLfloat, _dim)>(n, 0.0f);
		}
		group_color(std::size_t n, const LND_COLOR(GLfloat, _dim)& x)
		{
			_storage = std::vector<unsigned int>(n, x);
		}
		template <class _rhs_Allocator> group_color(const group_color<_dim, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
		}
		template <class _rhs_Allocator> group_color& operator=(const group_color<_dim, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
			return *this;
		}
		template <class _rhs_Allocator> group_color(group_color<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
		}
		template <class _rhs_Allocator> group_color& operator=(group_color<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
			return *this;
		}

		group_color(std::initializer_list<GLfloat> L)
		{
			_storage = std::vector<LND_COLOR(GLfloat, _dim), _Allocator>(L.size() / _dim);
			std::copy(L.begin(), L.end(), static_cast<GLfloat*>(static_cast<void*>(_storage.data())));
		}
		group_color& operator=(std::initializer_list<GLfloat> L)
		{
			_storage.resize(L.size() / _dim);
			std::copy(L.begin(), L.end(), static_cast<GLfloat*>(static_cast<void*>(_storage.data())));
			return *this;
		}

		inline void buffer_new_id()
		{
			buffer.new_id(1);
		}
		inline void buffer_delete_id()
		{
			buffer.delete_id();
		}
		inline void buffer_bind() const
		{
			buffer.bind();
		}
		inline void buffer_unbind() const
		{
			buffer.unbind();
		}
		inline void buffer_allocate() const
		{
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, this->size() * sizeof(GLfloat), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const GLfloat* const ptr, std::size_t vertex_count) const
		{
			constexpr std::size_t n = _dim * sizeof(GLfloat);
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, n * vertex_count, ptr, GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(GLfloat), this->data());
		}
		inline void buffer_update_from(const GLfloat* const ptr, std::size_t vertex_count) const
		{
			constexpr std::size_t n = _dim * sizeof(GLfloat);
			glNamedBufferSubData(buffer.get(), 0, n * vertex_count, ptr);
		}


		inline const GLfloat* data() const noexcept { return static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())); }
		inline GLfloat* data() noexcept { return static_cast<GLfloat*>(static_cast<void*>(_storage.data())); }
		inline const GLfloat& operator[](std::size_t offset) const noexcept
		{
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + offset);
		}
		inline GLfloat& operator[](std::size_t offset) noexcept
		{
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + offset);
		}
		inline const GLfloat& operator()(std::size_t color, std::size_t coord) const noexcept
		{
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + coord + _dim * color);
		}
		inline GLfloat& operator()(std::size_t color, std::size_t coord) noexcept
		{
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + coord + _dim * color);
		}

		inline const LND_COLOR(GLfloat, _dim)* data_color() const noexcept
		{
			return static_cast<const LND_COLOR(GLfloat, _dim)*>(static_cast<const void*>(_storage.data()));
		}
		inline LND_COLOR(GLfloat, _dim)* data_color() noexcept
		{
			return static_cast<LND_COLOR(GLfloat, _dim)*>(static_cast<void*>(_storage.data()));
		}
		inline const LND_COLOR(GLfloat, _dim)& operator()(std::size_t color) const noexcept
		{
			return *(static_cast<const LND_COLOR(GLfloat, _dim)*>(static_cast<const void*>(_storage.data())) + color);
		}
		inline LND_COLOR(GLfloat, _dim)& operator()(std::size_t color) noexcept
		{
			return *(static_cast<LND_COLOR(GLfloat, _dim)*>(static_cast<void*>(_storage.data())) + color);
		}

		inline void resize_color_count(std::size_t n)
		{
			_storage.resize(n);
		}
		inline void reserve_color_count(std::size_t n)
		{
			_storage.reserve(n);
		}
		inline void push_back_color(const LND_COLOR(GLfloat, _dim)& new_color)
		{
			_storage.push_back(new_color);
		}
		inline void push_front_color(const LND_COLOR(GLfloat, _dim)& new_color)
		{
			_storage.push_front(new_color);
		}
		inline void pop_back_color()
		{
			_storage.pop_back();
		}
		inline void pop_front_color()
		{
			_storage.pop_front();
		}
		inline std::size_t color_count() const noexcept
		{
			return _storage.size();
		}
		inline std::size_t color_capacity() const noexcept
		{
			return _storage.capacity();
		}
		constexpr std::size_t dim() const noexcept
		{
			return _dim;
		}
		inline std::size_t size() const noexcept
		{
			return _dim * _storage.size();
		}
		inline std::size_t shrink_to_fit()
		{
			_storage.shrink_to_fit();
		}
	};


	// TEXTURE STORAGE CLASSES

	template <std::size_t _dim, class _texture_Allocator = LND_DEFAULT_ALLOCATOR<LND_PIXEL(unsigned char, _dim)>> class texture
	{

	private:

		std::vector<LND_PIXEL(unsigned char, _dim), _texture_Allocator> _storage;
		std::size_t _width = 0;
		std::size_t _height = 0;
		lnd::buffer_texture buffer;
		int mapping = GL_NEAREST;
		int edges = GL_REPEAT;

	public:

		texture() = default;
		~texture() = default;
		texture(std::size_t new_width, std::size_t new_height)
		{
			_storage = std::vector<LND_PIXEL(unsigned char, _dim)>(new_width * new_height,
				LND_PIXEL(unsigned char, _dim){ static_cast<unsigned char>(0) });
			_width = new_width;
			_height = new_height;
		}
		texture(std::size_t new_width, std::size_t new_height, const LND_PIXEL(unsigned char, _dim)& x)
		{
			_storage = std::vector<LND_PIXEL(unsigned char, _dim)>(new_width * new_height, x);
			_width = new_width;
			_height = new_height;
		}
		template <class _rhs_Allocator> texture(const texture<_dim, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
			_width = rhs._width;
			_height = rhs._height;
		}
		template <class _rhs_Allocator> texture& operator=(const texture<_dim, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
			_width = rhs._width;
			_height = rhs._height;
			return *this;
		}
		template <class _rhs_Allocator> texture(texture<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
			_width = rhs._width;
			_height = rhs._height;
		}
		template <class _rhs_Allocator> texture& operator=(texture<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
			_width = rhs._width;
			_height = rhs._height;
			return *this;
		}

		inline void buffer_new_id()
		{
			buffer.new_id(1);
		}
		inline void buffer_delete_id()
		{
			buffer.delete_id();
		}
		inline void buffer_bind() const
		{
			buffer.bind();
		}
		inline void buffer_bind(GLenum slot) const
		{
			buffer.bind(slot);
		}
		inline void buffer_unbind() const
		{
			buffer.unbind();
		}
		inline void buffer_unbind(GLenum slot) const
		{
			buffer.unbind(slot);
		}
		inline void buffer_allocate() const
		{
			buffer.bind();
			switch (_dim)
			{

			case 1:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE,
					static_cast<const unsigned char*>(static_cast<const void*>(_storage.data())));
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mapping);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mapping);
				break;

			case 2:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), 0, GL_RG, GL_UNSIGNED_BYTE,
					static_cast<const unsigned char*>(static_cast<const void*>(_storage.data())));
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mapping);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mapping);
				break;

			case 3:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), 0, GL_RGB, GL_UNSIGNED_BYTE,
					static_cast<const unsigned char*>(static_cast<const void*>(_storage.data())));
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mapping);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mapping);
				break;

			case 4:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), 0, GL_RGBA, GL_UNSIGNED_BYTE,
					static_cast<const unsigned char*>(static_cast<const void*>(_storage.data())));
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mapping);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mapping);
				break;

			default:
				break;
			}
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, edges);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, edges);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const unsigned char* const ptr, GLsizei width, GLsizei height) const
		{
			buffer.bind();
			switch (_dim)
			{

			case 1:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, ptr);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mapping);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mapping);
				break;

			case 2:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, width, height, 0, GL_RG, GL_UNSIGNED_BYTE, ptr);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mapping);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mapping);
				break;

			case 3:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, ptr);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mapping);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mapping);
				break;

			case 4:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, ptr);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mapping);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mapping);
				break;

			default:
				break;
			}
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, edges);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, edges);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			buffer.bind();
			switch (_dim)
			{

			case 1:
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE,
					static_cast<const void*>(_storage.data()));
				break;

			case 2:
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), GL_RG, GL_UNSIGNED_BYTE,
					static_cast<const void*>(_storage.data()));
				break;

			case 3:
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), GL_RGB, GL_UNSIGNED_BYTE,
					static_cast<const void*>(_storage.data()));
				break;

			case 4:
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), GL_RGBA, GL_UNSIGNED_BYTE,
					static_cast<const void*>(_storage.data()));
				break;

			default:
				break;
			}
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, edges);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, edges);
			buffer.unbind();
		}
		inline void buffer_update_from(const unsigned char* const ptr, GLsizei width, GLsizei height) const
		{
			buffer.bind();
			switch (_dim)
			{

			case 1:
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, static_cast<const void*>(ptr));
				break;

			case 2:
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RG, GL_UNSIGNED_BYTE, static_cast<const void*>(ptr));
				break;

			case 3:
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, static_cast<const void*>(ptr));
				break;

			case 4:
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, static_cast<const void*>(ptr));
				break;

			default:
				break;
			}
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, edges);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, edges);
			buffer.unbind();
		}

		inline void map_nearest() noexcept
		{
			mapping = GL_NEAREST;
		}
		inline void map_linear() noexcept
		{
			mapping = GL_LINEAR;
		}
		inline void edges_repeat()
		{
			edges = GL_REPEAT;
		}
		inline void edges_mirrored_repeat()
		{
			edges = GL_MIRRORED_REPEAT;
		}
		inline void edges_clamp()
		{
			edges = GL_CLAMP_TO_EDGE;
		}

		inline std::size_t width() const noexcept { return _width; }
		inline std::size_t height() const noexcept { return _height; }

		inline void flip()
		{
			LND_PIXEL(unsigned char, _dim) temp;
			LND_PIXEL(unsigned char, _dim)* p = _storage.data();
			LND_PIXEL(unsigned char, _dim)* q = _storage.data() + _width * (_height - 1);
			std::size_t j;
			std::size_t jump = 2 * _width;
			for (std::size_t i = _height / 2; i > 0; i--)
			{
				for (j = _width; j > 0; j--)
				{
					temp = *p;
					*p = *q;
					*q = temp;
					p++; q++;
				}
				q -= jump;
			}
		}

		inline const unsigned char* data() const noexcept { return static_cast<const unsigned char*>(static_cast<const void*>(_storage.data())); }
		inline unsigned char* data() noexcept { return static_cast<unsigned char*>(static_cast<void*>(_storage.data())); }
		inline const unsigned char& operator[](std::size_t offset) const noexcept
		{
			return *(static_cast<const unsigned char*>(static_cast<const void*>(_storage.data())) + offset);
		}
		inline unsigned char& operator[](std::size_t offset) noexcept
		{
			return *(static_cast<unsigned char*>(static_cast<void*>(_storage.data())) + offset);
		}

		inline const LND_PIXEL(unsigned char, _dim)* data_pixel() const noexcept
		{
			return static_cast<const LND_PIXEL(unsigned char, _dim)*>(static_cast<const void*>(_storage.data()));
		}
		inline LND_PIXEL(unsigned char, _dim)* data_pixel() noexcept
		{
			return static_cast<LND_PIXEL(unsigned char, _dim)*>(static_cast<void*>(_storage.data()));
		}
		inline const LND_PIXEL(unsigned char, _dim)& operator()(std::size_t position) const noexcept
		{
			return *(static_cast<const LND_PIXEL(unsigned char, _dim)*>(static_cast<const void*>(_storage.data())) + position);
		}
		inline LND_PIXEL(unsigned char, _dim)& operator()(std::size_t position) noexcept
		{
			return *(static_cast<LND_PIXEL(unsigned char, _dim)*>(static_cast<void*>(_storage.data())) + position);
		}
		inline const LND_PIXEL(unsigned char, _dim)& operator()(std::size_t position_X, std::size_t position_Y) const noexcept
		{
			return *(static_cast<const LND_PIXEL(unsigned char, _dim)*>(static_cast<const void*>(_storage.data())) + position_X + _width * position_Y);
		}
		inline LND_PIXEL(unsigned char, _dim)& operator()(std::size_t position_X, std::size_t position_Y) noexcept
		{
			return *(static_cast<LND_PIXEL(unsigned char, _dim)*>(static_cast<void*>(_storage.data())) + position_X + _width * position_Y);
		}

		inline std::size_t size() const noexcept
		{
			return _dim * _storage.size();
		}
		inline std::size_t pixel_count() const noexcept
		{
			return _storage.size();
		}
		inline std::size_t pixel_capacity() const noexcept
		{
			return _storage.capacity();
		}
		inline void resize(std::size_t new_width, std::size_t  new_height)
		{
			_storage.resize(new_width * new_height);
			_width = new_width;
			_height = new_height;
		}
		inline void reserve_pixel_count(std::size_t n)
		{
			_storage.reserve(n);
		}
		inline void shrink_to_fit()
		{
			_storage.shrink_to_fit();
		}
	};


	// VERTEX STORAGE CLASSES

	template <std::size_t _vertex_count_pc, std::size_t _dim> class cluster_vertex
	{

	private:

		std::array<LND_VERTEX(GLfloat, _dim), _vertex_count_pc> _storage;

	public:

		cluster_vertex() = default;
		~cluster_vertex() = default;
		cluster_vertex(const cluster_vertex<_vertex_count_pc, _dim>&) = default;
		cluster_vertex& operator=(const cluster_vertex<_vertex_count_pc, _dim>&) = default;
		cluster_vertex(cluster_vertex<_vertex_count_pc, _dim>&&) = default;
		cluster_vertex& operator=(cluster_vertex<_vertex_count_pc, _dim>&&) = default;

		cluster_vertex(std::initializer_list<GLfloat> L)
		{
			std::copy(L.begin(), L.end(), static_cast<GLfloat*>(static_cast<void*>(_storage.data())));
		}
		cluster_vertex& operator=(std::initializer_list<GLfloat> L)
		{
			std::copy(L.begin(), L.end(), static_cast<GLfloat*>(static_cast<void*>(_storage.data())));
			return *this;
		}

		inline const GLfloat* data() const noexcept { return static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())); }
		inline GLfloat* data() noexcept { return static_cast<GLfloat*>(static_cast<void*>(_storage.data())); }
		inline const GLfloat& operator[](std::size_t offset) const noexcept
		{
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + offset);
		}
		inline GLfloat& operator[](std::size_t offset) noexcept
		{
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + offset);
		}
		inline const GLfloat& operator()(std::size_t vertex, std::size_t coord) const noexcept
		{
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + coord + _dim * vertex);
		}
		inline GLfloat& operator()(std::size_t vertex, std::size_t coord) noexcept
		{
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + coord + _dim * vertex);
		}

		inline const LND_VERTEX(GLfloat, _dim)* data_vertex() const noexcept
		{
			return static_cast<const LND_VERTEX(GLfloat, _dim)*>(static_cast<const void*>(_storage.data()));
		}
		inline LND_VERTEX(GLfloat, _dim)* data_vertex() noexcept
		{
			return static_cast<LND_VERTEX(GLfloat, _dim)*>(static_cast<void*>(_storage.data()));
		}
		inline const LND_VERTEX(GLfloat, _dim)& operator()(std::size_t vertex) const noexcept
		{
			return *(static_cast<const LND_VERTEX(GLfloat, _dim)*>(static_cast<const void*>(_storage.data())) + vertex);
		}
		inline LND_VERTEX(GLfloat, _dim)& operator()(std::size_t vertex) noexcept
		{
			return *(static_cast<LND_VERTEX(GLfloat, _dim)*>(static_cast<void*>(_storage.data())) + vertex);
		}

		constexpr std::size_t vertex_count() const noexcept
		{
			return _vertex_count_pc;
		}
		constexpr std::size_t dim() const noexcept
		{
			return _dim;
		}
		constexpr std::size_t size() const noexcept
		{
			return _vertex_count_pc * _dim;
		}
	};

	template <std::size_t _vertex_count_pc, std::size_t _dim, class _Allocator
		= LND_DEFAULT_ALLOCATOR<lnd::cluster_vertex<_vertex_count_pc, _dim>>>
		class group_cluster_vertex
	{

	private:

		std::vector<lnd::cluster_vertex<_vertex_count_pc, _dim>, _Allocator> _storage;
		lnd::buffer_vertex buffer;

	public:

		group_cluster_vertex() = default;
		~group_cluster_vertex() = default;
		group_cluster_vertex(std::size_t n)
		{
			_storage = std::vector<const lnd::cluster_vertex<_vertex_count_pc, _dim>, _Allocator>(n, lnd::cluster_vertex<_vertex_count_pc, _dim>());
		}
		group_cluster_vertex(std::size_t n, const lnd::cluster_vertex<_vertex_count_pc, _dim>& rhs)
		{
			_storage = std::vector<const lnd::cluster_vertex<_vertex_count_pc, _dim>, _Allocator>(n, rhs);
		}
		template <class _rhs_Allocator> group_cluster_vertex(const group_cluster_vertex<_vertex_count_pc, _dim, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
		}
		template <class _rhs_Allocator> group_cluster_vertex& operator=(const group_cluster_vertex<_vertex_count_pc, _dim, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
			return *this;
		}
		template <class _rhs_Allocator> group_cluster_vertex(group_cluster_vertex<_vertex_count_pc, _dim, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
		}
		template <class _rhs_Allocator> group_cluster_vertex& operator=(group_cluster_vertex<_vertex_count_pc, _dim, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
			return *this;
		}

		inline void buffer_new_id()
		{
			buffer.new_id(1);
		}
		inline void buffer_delete_id()
		{
			buffer.delete_id();
		}
		inline void buffer_bind() const
		{
			buffer.bind();
		}
		inline void buffer_unbind() const
		{
			buffer.unbind();
		}
		inline void buffer_allocate() const
		{
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, this->size() * sizeof(GLfloat), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const GLfloat* const ptr, std::size_t cluster_count) const
		{
			constexpr std::size_t n = _vertex_count_pc * _dim * sizeof(GLfloat);
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, n * cluster_count, ptr, GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(GLfloat), this->data());
		}
		inline void buffer_update_from(const GLfloat* const ptr, std::size_t cluster_count) const
		{
			constexpr std::size_t n = _vertex_count_pc * _dim * sizeof(GLfloat);
			glNamedBufferSubData(buffer.get(), 0, n * cluster_count, ptr);
		}

		inline const GLfloat* data() const noexcept { return static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())); }
		inline GLfloat* data() noexcept { return static_cast<GLfloat*>(static_cast<void*>(_storage.data())); }
		inline const GLfloat& operator[](std::size_t offset) const noexcept
		{
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + offset);
		}
		inline GLfloat& operator[](std::size_t offset) noexcept
		{
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + offset);
		}
		inline const GLfloat& operator()(std::size_t cluster, std::size_t vertex, std::size_t coord) const noexcept
		{
			constexpr std::size_t n = _vertex_count_pc * _dim;
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + coord + _dim * vertex + n * cluster);
		}
		inline GLfloat& operator()(std::size_t cluster, std::size_t vertex, std::size_t coord) noexcept
		{
			constexpr std::size_t n = _vertex_count_pc * _dim;
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + coord + _dim * vertex + n * cluster);
		}

		inline const LND_VERTEX(GLfloat, _dim)* data_vertex() const noexcept
		{
			return static_cast<const LND_VERTEX(GLfloat, _dim)*>(static_cast<const void*>(_storage.data()));
		}
		inline LND_VERTEX(GLfloat, _dim)* data_vertex() noexcept
		{
			return static_cast<LND_VERTEX(GLfloat, _dim)*>(static_cast<void*>(_storage.data()));
		}
		inline const LND_VERTEX(GLfloat, _dim)& operator()(std::size_t cluster, std::size_t vertex) const noexcept
		{
			return *(static_cast<const LND_VERTEX(GLfloat, _dim)*>(static_cast<const void*>(_storage.data())) + vertex + _vertex_count_pc * cluster);
		}
		inline LND_VERTEX(GLfloat, _dim)& operator()(std::size_t cluster, std::size_t vertex) noexcept
		{
			return *(static_cast<LND_VERTEX(GLfloat, _dim)*>(static_cast<void*>(_storage.data())) + vertex + _vertex_count_pc * cluster);
		}

		inline const lnd::cluster_vertex<_vertex_count_pc, _dim>* data_cluster() const noexcept
		{
			return static_cast<const lnd::cluster_vertex<_vertex_count_pc, _dim>*>(static_cast<const void*>(_storage.data()));
		}
		inline lnd::cluster_vertex<_vertex_count_pc, _dim>* data_cluster() noexcept
		{
			return static_cast<lnd::cluster_vertex<_vertex_count_pc, _dim>*>(static_cast<void*>(_storage.data()));
		}
		inline const lnd::cluster_vertex<_vertex_count_pc, _dim>& operator()(std::size_t cluster) const noexcept
		{
			return *(_storage.data() + cluster);
		}
		inline lnd::cluster_vertex<_vertex_count_pc, _dim>& operator()(std::size_t cluster) noexcept
		{
			return *(_storage.data() + cluster);
		}

		inline void resize_cluster_count(std::size_t n)
		{
			_storage.resize(n);
		}
		inline void reserve_cluster_count(std::size_t n)
		{
			_storage.reserve(n);
		}
		inline void push_back_cluster(const lnd::cluster_vertex<_vertex_count_pc, _dim>& new_cluster)
		{
			_storage.push_back(new_cluster);
		}
		inline void push_front_cluster(const lnd::cluster_vertex<_vertex_count_pc, _dim>& new_cluster)
		{
			_storage.push_front(new_cluster);
		}
		inline void pop_back_cluster()
		{
			_storage.pop_back();
		}
		inline void pop_front_cluster()
		{
			_storage.pop_front();
		}
		inline std::size_t cluster_count() const noexcept
		{
			return _storage.size();
		}
		inline std::size_t cluster_capacity() const noexcept
		{
			return _storage.capacity();
		}
		inline std::size_t vertex_count() const noexcept
		{
			return _vertex_count_pc * _storage.size();
		}
		constexpr std::size_t vertex_count_per_cluster() const noexcept
		{
			return _vertex_count_pc;
		}
		constexpr std::size_t dim() const noexcept
		{
			return _dim;
		}
		inline std::size_t size() const noexcept
		{
			constexpr std::size_t n = _vertex_count_pc * _dim;
			return n * _storage.size();
		}
		inline void shrink_to_fit()
		{
			_storage.shrink_to_fit();
		}


		// makes normals

		template <class _vertex_Allocator>
		inline void make_normals_from(const lnd::group_cluster_vertex<_vertex_count_pc, _dim, _vertex_Allocator>& vertex, bool counter_clockwise_orientation) noexcept
		{
			_storage.resize(vertex._storage.size());
			constexpr std::size_t _offset = _vertex_count_pc * _dim;
			GLfloat* p = static_cast<GLfloat*>(static_cast<void*>(_storage.data()));
			const GLfloat* q = static_cast<const GLfloat*>(static_cast<const void*>(vertex._storage.data()));
			GLfloat factor;
			std::size_t n = _storage.size();

			switch (counter_clockwise_orientation)
			{

			case true:

				switch (_dim)
				{

				case 2:
				{
					for (std::size_t j = 0; j < n; j++)
					{
						*p = *(q + 1) - *(q + 3);
						*(p + 1) = *(q + 2) - *q;
						factor = 1.0f / LND_SQRT((*p) * (*p) + (*(p + 1)) * (*(p + 1)));
						*p *= factor;
						*(p + 1) *= factor;
						for (std::size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 2 * k, p, 2 * sizeof(GLfloat));
						}
						p += _offset; q += _offset;
					}
				}
				break;

				case 3:
#ifdef LND_AVX_EXT
				{
					__m128 u;
					__m128 v;
					__m128 w;
					for (std::size_t j = 0; j < n; j++)
					{
						w = _mm_loadu_ps(q + 3);
						u = _mm_sub_ps(w, _mm_loadu_ps(q));
						v = _mm_sub_ps(_mm_loadu_ps(q + 6), w);
						w = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
							_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
							_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
								_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
						_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
						w = _mm_mul_ps(w, _mm_set1_ps(1.0f / LND_SQRT(*p)));
						_mm_storeu_ps(p, w);
						for (std::size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 3 * k, p, 3 * sizeof(GLfloat));
						}
						p += _offset; q += _offset;
					}
				}
#else // LND_AVX_EXT
				{
					GLfloat u3[3];
					GLfloat v3[3];
					for (std::size_t j = 0; j < n; j++)
					{
						u3[0] = *(q + 3) - *q;
						u3[1] = *(q + 4) - *(q + 1);
						u3[2] = *(q + 5) - *(q + 2);
						v3[0] = *(q + 6) - *(q + 3);
						v3[1] = *(q + 7) - *(q + 4);
						v3[2] = *(q + 8) - *(q + 5);
						*p = u3[1] * v3[2] - u3[2] * v3[1];
						*(p + 1) = u3[2] * v3[0] - u3[0] * v3[2];
						*(p + 2) = u3[0] * v3[1] - u3[1] * v3[0];
						factor = 1.0f / LND_SQRT((*p) * (*p)
							+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
						*p *= factor;
						*(p + 1) *= factor;
						*(p + 2) *= factor;
						for (std::size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 3 * k, p, 3 * sizeof(GLfloat));
						}
						p += _offset; q += _offset;
					}
				}
#endif // LND_AVX_EXT
				break;

				default:
					break;
				}

				break;

			case false:

				switch (_dim)
				{

				case 2:
				{
					for (std::size_t j = 0; j < n; j++)
					{
						*p = *(q + 3) - *(q + 1);
						*(p + 1) = *q - *(q + 2);
						factor = 1.0f / LND_SQRT((*p) * (*p) + (*(p + 1)) * (*(p + 1)));
						*p *= factor;
						*(p + 1) *= factor;
						for (std::size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 2 * k, p, 2 * sizeof(GLfloat));
						}
						p += _offset; q += _offset;
					}
				}
				break;

				case 3:
#ifdef LND_AVX_EXT
				{
					__m128 v;
					__m128 u;
					__m128 w;
					for (std::size_t j = 0; j < n; j++)
					{
						w = _mm_loadu_ps(q + 3);
						u = _mm_sub_ps(_mm_loadu_ps(q + 6), w);
						v = _mm_sub_ps(w, _mm_loadu_ps(q));
						w = _mm_fnmadd_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2)),
							_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
							_mm_mul_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
								_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2))));
						_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
						w = _mm_mul_ps(w, _mm_set1_ps(1.0f / LND_SQRT(*p)));
						_mm_storeu_ps(p, w);
						for (std::size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 3 * k, p, 3 * sizeof(GLfloat));
						}
						p += _offset; q += _offset;
					}
				}
#else // LND_AVX_EXT
				{
					GLfloat u3[3];
					GLfloat v3[3];
					for (std::size_t j = 0; j < n; j++)
					{
						u3[0] = *(q + 3) - *q;
						u3[1] = *(q + 4) - *(q + 1);
						u3[2] = *(q + 5) - *(q + 2);
						v3[0] = *(q + 6) - *(q + 3);
						v3[1] = *(q + 7) - *(q + 4);
						v3[2] = *(q + 8) - *(q + 5);
						*p = u3[2] * v3[1] - u3[1] * v3[2];
						*(p + 1) = u3[0] * v3[2] - u3[2] * v3[0];
						*(p + 2) = u3[1] * v3[0] - u3[0] * v3[1];
						factor = 1.0f / LND_SQRT((*p) * (*p)
							+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
						*p *= factor;
						*(p + 1) *= factor;
						*(p + 2) *= factor;
						for (std::size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 3 * k, p, 3 * sizeof(GLfloat));
						}
						p += _offset; q += _offset;
					}
				}
#endif // LND_AVX_EXT
				break;

				default:
					break;
				}

				break;
			}
		}


		// make frames

		template <std::size_t _vertex_count_pc2, std::size_t _vertex_count_pc3, class _vertex_Allocator, class _tex_coord_Allocator> inline void make_frames_from(
			const lnd::group_cluster_vertex<_vertex_count_pc2, _dim, _vertex_Allocator>& vertex,
			const lnd::group_cluster_vertex<_vertex_count_pc3, 2, _tex_coord_Allocator>& tex_coord,
			bool counter_clockwise_orientation) noexcept
		{
			_storage.resize(vertex.cluster_count());
			constexpr std::size_t _offset = _vertex_count_pc * _dim;
			constexpr std::size_t _vertex_offset = _vertex_count_pc2 * _dim;
			constexpr std::size_t _tex_coord_offset = _vertex_count_pc3 * 2;
			GLfloat* p = static_cast<GLfloat*>(static_cast<void*>(_storage.data()));
			const GLfloat* q = static_cast<const GLfloat*>(static_cast<const void*>(vertex.data()));
			const GLfloat* r = static_cast<const GLfloat*>(static_cast<const void*>(tex_coord.data()));
			GLfloat temp;
			GLfloat ut[4];

			std::size_t n = _storage.size();

			switch (counter_clockwise_orientation)
			{

			case true:

				switch (_dim)
				{

				case 2:
				{
					GLfloat a0;
					GLfloat b0;
					GLfloat a1;
					GLfloat b1;
					for (std::size_t j = 0; j < n; j++)
					{
						ut[0] = *(r + 2) - *r;
						ut[1] = *(r + 3) - *(r + 1);
						ut[2] = *(r + 4) - *(r + 2);
						ut[3] = *(r + 5) - *(r + 3);

						temp = 1.0f / (ut[0] * ut[3] - ut[1] * ut[2]);

						a0 = ut[3] * temp;
						b0 = -ut[1] * temp;
						a1 = -ut[2] * temp;
						b1 = ut[0] * temp;

						ut[0] = *(q + 2) - *q;
						ut[1] = *(q + 3) - *(q + 1);

						ut[2] = *(q + 4) - *(q + 2);
						ut[3] = *(q + 5) - *(q + 3);

						*p = a0 * ut[0] + b0 * ut[2];
						*(p + 1) = a0 * ut[1] + b0 * ut[3];

						temp = 1.0f / LND_SQRT((*p) * (*p) + (*(p + 1)) * (*(p + 1)));
						*p *= temp;
						*(p + 1) *= temp;

						*(p + 2) = a1 * ut[0] + b1 * ut[2];
						*(p + 3) = a1 * ut[1] + b1 * ut[3];

						temp = 1.0f / LND_SQRT((*(p + 2)) * (*(p + 2)) + (*(p + 3)) * (*(p + 3)));
						*(p + 2) *= temp;
						*(p + 3) *= temp;

						for (std::size_t k = 1; k < _vertex_count_pc2; k++)
						{
							memcpy(p + 4 * k, p, 4 * sizeof(GLfloat));
						}
						p += _offset; q += _vertex_offset; r += _tex_coord_offset;
					}
				}
				break;

				case 3:
#ifdef LND_AVX_EXT
				{
					__m128 u;
					__m128 v;
					__m128 w;
					__m128 a0;
					__m128 b0;
					__m128 a1;
					__m128 b1;
					for (std::size_t j = 0; j < n; j++)
					{
						_mm_storeu_ps(static_cast<GLfloat*>(ut), _mm_sub_ps(_mm_loadu_ps(r + 2), _mm_loadu_ps(r)));

						temp = 1.0f / (ut[0] * ut[3] - ut[1] * ut[2]);

						a0 = _mm_set1_ps(ut[3] * temp);
						b0 = _mm_set1_ps(-ut[1] * temp);
						a1 = _mm_set1_ps(-ut[2] * temp);
						b1 = _mm_set1_ps(ut[0] * temp);

						w = _mm_loadu_ps(q + 3);
						u = _mm_sub_ps(w, _mm_loadu_ps(q));
						v = _mm_sub_ps(_mm_loadu_ps(q + 6), w);

						w = _mm_fmadd_ps(b0, v, _mm_mul_ps(a0, u));
						_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
						w = _mm_mul_ps(w, _mm_set1_ps(1.0f / LND_SQRT(*p)));
						_mm_storeu_ps(p, w);

						w = _mm_fmadd_ps(b1, v, _mm_mul_ps(a1, u));
						_mm_storeu_ps(p + 3, _mm_dp_ps(w, w, 0x7f));
						w = _mm_mul_ps(w, _mm_set1_ps(1.0f / LND_SQRT(*(p + 3))));
						_mm_storeu_ps(p + 3, w);

						w = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
							_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
							_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
								_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
						_mm_storeu_ps(p + 6, _mm_dp_ps(w, w, 0x7f));
						w = _mm_mul_ps(w, _mm_set1_ps(1.0f / LND_SQRT(*(p + 6))));
						_mm_storeu_ps(p + 6, w);
						for (std::size_t k = 1; k < _vertex_count_pc2; k++)
						{
							memcpy(p + 9 * k, p, 9 * sizeof(GLfloat));
						}
						p += _offset; q += _vertex_offset; r += _tex_coord_offset;
					}
				}
#else // LND_AVX_EXT
				{
					GLfloat a0;
					GLfloat b0;
					GLfloat a1;
					GLfloat b1;
					GLfloat vt[3];
					for (std::size_t j = 0; j < n; j++)
					{
						ut[0] = *(r + 2) - *r;
						ut[1] = *(r + 3) - *(r + 1);
						ut[2] = *(r + 4) - *(r + 2);
						ut[3] = *(r + 5) - *(r + 3);

						temp = 1.0f / (ut[0] * ut[3] - ut[1] * ut[2]);

						a0 = ut[3] * temp;
						b0 = -ut[1] * temp;
						a1 = -ut[2] * temp;
						b1 = ut[0] * temp;

						ut[0] = *(q + 3) - *q;
						ut[1] = *(q + 4) - *(q + 1);
						ut[2] = *(q + 5) - *(q + 2);

						vt[0] = *(q + 6) - *(q + 3);
						vt[1] = *(q + 7) - *(q + 4);
						vt[2] = *(q + 8) - *(q + 5);

						*p = a0 * ut[0] + b0 * vt[0];
						*(p + 1) = a0 * ut[1] + b0 * vt[1];
						*(p + 2) = a0 * ut[2] + b0 * vt[2];

						temp = 1.0f / LND_SQRT((*p) * (*p)
							+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
						*p *= temp;
						*(p + 1) *= temp;
						*(p + 2) *= temp;

						*(p + 3) = a1 * ut[0] + b1 * vt[0];
						*(p + 4) = a1 * ut[1] + b1 * vt[1];
						*(p + 5) = a1 * ut[2] + b1 * vt[2];

						temp = 1.0f / LND_SQRT((*(p + 3)) * (*(p + 3))
							+ (*(p + 4)) * (*(p + 4)) + (*(p + 5)) * (*(p + 5)));
						*(p + 3) *= temp;
						*(p + 4) *= temp;
						*(p + 5) *= temp;

						*(p + 6) = (*(ut + 1)) * (*(vt + 2)) - (*(ut + 2)) * (*(vt + 1));
						*(p + 7) = (*(ut + 2)) * (*(vt + 0)) - (*ut) * (*(vt + 2));
						*(p + 8) = (*ut) * (*(vt + 1)) - (*(ut + 1)) * (*(vt + 0));

						temp = 1.0f / LND_SQRT((*(p + 6)) * (*(p + 6))
							+ (*(p + 7)) * (*(p + 7)) + (*(p + 8)) * (*(p + 8)));
						*(p + 6) *= temp;
						*(p + 7) *= temp;
						*(p + 8) *= temp;

						for (std::size_t k = 1; k < _vertex_count_pc2; k++)
						{
							memcpy(p + 9 * k, p, 9 * sizeof(GLfloat));
						}
						p += _offset; q += _vertex_offset; r += _tex_coord_offset;
					}
				}
#endif // LND_AVX_EXT
				break;

				default:
					break;
				}

				break;

			case false:

				switch (_dim)
				{

				case 2:
				{
					GLfloat a0;
					GLfloat b0;
					GLfloat a1;
					GLfloat b1;
					for (std::size_t j = 0; j < n; j++)
					{
						ut[0] = *(r + 2) - *r;
						ut[1] = *(r + 3) - *(r + 1);
						ut[2] = *(r + 4) - *(r + 2);
						ut[3] = *(r + 5) - *(r + 3);

						temp = 1.0f / (ut[0] * ut[3] - ut[1] * ut[2]);

						a0 = ut[3] * temp;
						b0 = -ut[1] * temp;
						a1 = -ut[2] * temp;
						b1 = ut[0] * temp;

						ut[0] = *(q + 2) - *(q);
						ut[1] = *(q + 3) - *(q + 1);

						ut[2] = *(q + 4) - *(q + 2);
						ut[3] = *(q + 5) - *(q + 3);

						*p = a0 * ut[0] + b0 * ut[2];
						*(p + 1) = a0 * ut[1] + b0 * ut[3];

						temp = 1.0f / LND_SQRT((*p) * (*p) + (*(p + 1)) * (*(p + 1)));
						*p *= temp;
						*(p + 1) *= temp;

						*(p + 2) = a1 * ut[0] + b1 * ut[2];
						*(p + 3) = a1 * ut[1] + b1 * ut[3];

						temp = 1.0f / LND_SQRT((*(p + 2)) * (*(p + 2)) + (*(p + 3)) * (*(p + 3)));
						*(p + 2) *= temp;
						*(p + 3) *= temp;

						for (std::size_t k = 1; k < _vertex_count_pc2; k++)
						{
							memcpy(p + 4 * k, p, 4 * sizeof(GLfloat));
						}
						p += _offset; q += _vertex_offset; r += _tex_coord_offset;
					}
				}
				break;

				case 3:
#ifdef LND_AVX_EXT
				{
					__m128 u;
					__m128 v;
					__m128 w;
					__m128 a0;
					__m128 b0;
					__m128 a1;
					__m128 b1;
					for (std::size_t j = 0; j < n; j++)
					{
						_mm_storeu_ps(static_cast<GLfloat*>(ut), _mm_sub_ps(_mm_loadu_ps(r + 2), _mm_loadu_ps(r)));

						temp = 1.0f / (ut[0] * ut[3] - ut[1] * ut[2]);

						a0 = _mm_set1_ps(ut[3] * temp);
						b0 = _mm_set1_ps(-ut[1] * temp);
						a1 = _mm_set1_ps(-ut[2] * temp);
						b1 = _mm_set1_ps(ut[0] * temp);

						w = _mm_loadu_ps(q + 3);
						u = _mm_sub_ps(w, _mm_loadu_ps(q));
						v = _mm_sub_ps(_mm_loadu_ps(q + 6), w);

						w = _mm_fmadd_ps(b0, v, _mm_mul_ps(a0, u));
						_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
						w = _mm_mul_ps(w, _mm_set1_ps(1.0f / LND_SQRT(*p)));
						_mm_storeu_ps(p, w);

						w = _mm_fmadd_ps(b1, v, _mm_mul_ps(a1, u));
						_mm_storeu_ps(p + 3, _mm_dp_ps(w, w, 0x7f));
						w = _mm_mul_ps(w, _mm_set1_ps(1.0f / LND_SQRT(*(p + 3))));
						_mm_storeu_ps(p + 3, w);

						w = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
							_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2)),
							_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
								_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1))));
						_mm_storeu_ps(p + 6, _mm_dp_ps(w, w, 0x7f));
						w = _mm_mul_ps(w, _mm_set1_ps(1.0f / LND_SQRT(*(p + 6))));
						_mm_storeu_ps(p + 6, w);
						for (std::size_t k = 1; k < _vertex_count_pc2; k++)
						{
							memcpy(p + 9 * k, p, 9 * sizeof(GLfloat));
						}
						p += _offset; q += _vertex_offset; r += _tex_coord_offset;
					}
				}
#else // LND_AVX_EXT
				{
					GLfloat a0;
					GLfloat b0;
					GLfloat a1;
					GLfloat b1;
					GLfloat vt[3];
					for (std::size_t j = 0; j < n; j++)
					{
						ut[0] = *(r + 2) - *r;
						ut[1] = *(r + 3) - *(r + 1);
						ut[2] = *(r + 4) - *(r + 2);
						ut[3] = *(r + 5) - *(r + 3);

						temp = 1.0f / (ut[0] * ut[3] - ut[1] * ut[2]);

						a0 = ut[3] * temp;
						b0 = -ut[1] * temp;
						a1 = -ut[2] * temp;
						b1 = ut[0] * temp;

						ut[0] = *(q + 3) - *(q);
						ut[1] = *(q + 4) - *(q + 1);
						ut[2] = *(q + 5) - *(q + 2);

						vt[0] = *(q + 6) - *(q + 3);
						vt[1] = *(q + 7) - *(q + 4);
						vt[2] = *(q + 8) - *(q + 5);

						*p = a0 * ut[0] + b0 * vt[0];
						*(p + 1) = a0 * ut[1] + b0 * vt[1];
						*(p + 2) = a0 * ut[2] + b0 * vt[2];

						temp = 1.0f / LND_SQRT((*p) * (*p)
							+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
						*p *= temp;
						*(p + 1) *= temp;
						*(p + 2) *= temp;

						*(p + 3) = a1 * ut[0] + b1 * vt[0];
						*(p + 4) = a1 * ut[1] + b1 * vt[1];
						*(p + 5) = a1 * ut[2] + b1 * vt[2];

						temp = 1.0f / LND_SQRT((*(p + 3)) * (*(p + 3))
							+ (*(p + 4)) * (*(p + 4)) + (*(p + 5)) * (*(p + 5)));
						*(p + 3) *= temp;
						*(p + 4) *= temp;
						*(p + 5) *= temp;

						*(p + 6) = (*(ut + 2)) * (*(vt + 1)) - (*(ut + 1)) * (*(vt + 2));
						*(p + 7) = (*ut) * (*(vt + 2)) - (*(ut + 2)) * (*(vt + 0));
						*(p + 8) = (*(ut + 1)) * (*(vt + 0)) - (*ut) * (*(vt + 1));

						temp = 1.0f / LND_SQRT((*(p + 6)) * (*(p + 6))
							+ (*(p + 7)) * (*(p + 7)) + (*(p + 8)) * (*(p + 8)));
						*(p + 6) *= temp;
						*(p + 7) *= temp;
						*(p + 8) *= temp;

						for (std::size_t k = 1; k < _vertex_count_pc2; k++)
						{
							memcpy(p + 9 * k, p, 9 * sizeof(GLfloat));
						}
						p += _offset; q += _vertex_offset; r += _tex_coord_offset;
					}
				}
#endif // LND_AVX_EXT
				break;

				default:
					break;
				}

				break;
			}
		}


		// draw with solid colors

		inline void draw(
			const lnd::program& program)
		{
			switch (_vertex_count_pc)
			{

			case 1:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			default:
				break;
			}
		}

		inline void draw_3d(
			const lnd::program& program)
		{
			switch (_vertex_count_pc)
			{

			case 1:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			default:
				break;
			}
		}

		template <class _normal_Allocator> inline void draw_normals_3d(
			const lnd::program& program,
			const lnd::group_cluster_vertex<_vertex_count_pc, _dim, _normal_Allocator>& normals)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				normals.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				normals.buffer_unbind();
				break;

			default:
				break;
			}
		}


		inline void draw_ranged(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program)
		{
			switch (_vertex_count_pc)
			{

			case 1:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_LINES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			default:
				break;
			}
		}

		inline void draw_ranged_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program)
		{
			switch (_vertex_count_pc)
			{

			case 1:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_LINES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			default:
				break;
			}
		}

		template <class _normal_Allocator> inline void draw_ranged_normals_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_vertex<_vertex_count_pc, _dim, _normal_Allocator>& normals)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				normals.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				normals.buffer_unbind();
				break;

			default:
				break;
			}
		}


		// draw with RGB/RGBA gradient colors

		template <std::size_t _color_dim, class _color_Allocator> inline void draw_RGBA(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring)
		{
			switch (_vertex_count_pc)
			{

			case 1:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <std::size_t _color_dim, class _color_Allocator> inline void draw_RGBA_3d(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring)
		{
			switch (_vertex_count_pc)
			{

			case 1:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <std::size_t _color_dim, class _color_Allocator, class _normal_Allocator> inline void draw_RGBA_normals_3d(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_vertex<_vertex_count_pc, _dim, _normal_Allocator>& normals)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				normals.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				normals.buffer_unbind();
				break;

			default:
				break;
			}
		}


		template <std::size_t _color_dim, class _color_Allocator> inline void draw_ranged_RGBA(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring)
		{
			switch (_vertex_count_pc)
			{

			case 1:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_LINES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <std::size_t _color_dim, class _color_Allocator> inline void draw_ranged_RGBA_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring)
		{
			switch (_vertex_count_pc)
			{

			case 1:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_LINES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <std::size_t _color_dim, class _color_Allocator, class _normal_Allocator> inline void draw_ranged_RGBA_normals_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_vertex<_vertex_count_pc, _dim, _normal_Allocator>& normals)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				normals.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				normals.buffer_unbind();
				break;

			default:
				break;
			}
		}


		// draw with textures

		template <class _vertex_Allocator, std::size_t _pixel_dim, class _texture_Allocator> inline void draw_tex(
			const lnd::program& program,
			const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
			const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <std::size_t _pixel_dim, std::size_t _frame_pixel_dim, std::size_t _vertex_count_pc2,
			class _vertex_Allocator, class _texture_Allocator, class _frame_tex_Allocator, class _frame_Allocator> inline void draw_mapped(
				const lnd::program& program,
				const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
				const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image,
				const lnd::texture<_frame_pixel_dim, _frame_tex_Allocator>& frame_texture_image,
				const lnd::group_cluster_vertex<_vertex_count_pc2, _dim, _frame_Allocator>& frames)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), reinterpret_cast<void*>(2 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				frame_texture_image.buffer_bind(1);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				frame_texture_image.buffer_unbind(1);
				frames.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), reinterpret_cast<void*>(2 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				frame_texture_image.buffer_bind(1);
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				frame_texture_image.buffer_unbind(1);
				frames.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <class _vertex_Allocator, std::size_t _pixel_dim, class _texture_Allocator> inline void draw_tex_3d(
			const lnd::program& program,
			const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
			const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <std::size_t _pixel_dim, class _vertex_Allocator, class _texture_Allocator, class _normals_Allocator> inline void draw_tex_normals_3d(
			const lnd::program& program,
			const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
			const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image,
			const lnd::group_cluster_vertex<_vertex_count_pc, _dim, _normals_Allocator>& normals)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				normals.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				normals.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <std::size_t _pixel_dim, std::size_t _spec_pixel_dim, std::size_t _frame_pixel_dim, std::size_t _vertex_count_pc2,
			class _vertex_Allocator, class _texture_Allocator, class _spec_tex_Allocator,
			class _frame_tex_Allocator, class _frame_Allocator> inline void draw_mapped_3d(
				const lnd::program& program,
				const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
				const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image,
				const lnd::texture<_spec_pixel_dim, _spec_tex_Allocator>& spec_texture_image,
				const lnd::texture<_frame_pixel_dim, _frame_tex_Allocator>& frame_texture_image,
				const lnd::group_cluster_vertex<_vertex_count_pc2, _dim, _frame_Allocator>& frames)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(4);
				glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(6 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				spec_texture_image.buffer_bind(1);
				frame_texture_image.buffer_bind(2);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				spec_texture_image.buffer_unbind(1);
				frame_texture_image.buffer_unbind(2);
				frames.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(4);
				glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(6 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				spec_texture_image.buffer_bind(1);
				frame_texture_image.buffer_bind(2);
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				spec_texture_image.buffer_unbind(1);
				frame_texture_image.buffer_unbind(2);
				frames.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <std::size_t _pixel_dim, std::size_t _spec_pixel_dim, std::size_t _frame_pixel_dim, std::size_t _light_pixel_dim, std::size_t _vertex_count_pc2,
			class _vertex_Allocator, class _light_vertex_Allocator, class _texture_Allocator, class _spec_tex_Allocator,
			class _frame_tex_Allocator, class _light_tex_Allocator, class _frame_Allocator> inline void draw_lightmapped_3d(
				const lnd::program& program,
				const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
				const lnd::group_cluster_vertex<_vertex_count_pc, 2, _light_vertex_Allocator>& lightmap_coord,
				const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image,
				const lnd::texture<_spec_pixel_dim, _spec_tex_Allocator>& spec_texture_image,
				const lnd::texture<_frame_pixel_dim, _frame_tex_Allocator>& frame_texture_image,
				const lnd::texture<_light_pixel_dim, _light_tex_Allocator>& light_texture_image,
				const lnd::group_cluster_vertex<_vertex_count_pc2, _dim, _frame_Allocator>& frames)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				lightmap_coord.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(4);
				glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(5);
				glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(6 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				spec_texture_image.buffer_bind(1);
				frame_texture_image.buffer_bind(2);
				light_texture_image.buffer_bind(3);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				lightmap_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				spec_texture_image.buffer_unbind(1);
				frame_texture_image.buffer_unbind(2);
				light_texture_image.buffer_unbind(3);
				frames.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				lightmap_coord.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(4);
				glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(5);
				glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(6 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				spec_texture_image.buffer_bind(1);
				frame_texture_image.buffer_bind(2);
				light_texture_image.buffer_bind(3);
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				lightmap_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				spec_texture_image.buffer_unbind(1);
				frame_texture_image.buffer_unbind(2);
				light_texture_image.buffer_unbind(3);
				frames.buffer_unbind();
				break;

			default:
				break;
			}
		}


		template <class _vertex_Allocator, std::size_t _pixel_dim, class _texture_Allocator> inline void draw_ranged_tex(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
			const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_TRIANGLES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_QUADS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <std::size_t _pixel_dim, std::size_t _frame_pixel_dim, std::size_t _vertex_count_pc2,
			class _vertex_Allocator, class _texture_Allocator, class _frame_tex_Allocator, class _frame_Allocator> inline void draw_ranged_mapped(
				GLsizei first_cluster,
				GLsizei end_cluster,
				const lnd::program& program,
				const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
				const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image,
				const lnd::texture<_frame_pixel_dim, _frame_tex_Allocator>& frame_texture_image,
				const lnd::group_cluster_vertex<_vertex_count_pc2, _dim, _frame_Allocator>& frames)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), reinterpret_cast<void*>(2 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				frame_texture_image.buffer_bind(1);
				program.use();
				glDrawArrays(GL_TRIANGLES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				frame_texture_image.buffer_unbind(1);
				frames.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), reinterpret_cast<void*>(2 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				frame_texture_image.buffer_bind(1);
				program.use();
				glDrawArrays(GL_QUADS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				frame_texture_image.buffer_unbind(1);
				frames.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <class _vertex_Allocator, std::size_t _pixel_dim, class _texture_Allocator> inline void draw_ranged_tex_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
			const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_TRIANGLES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_QUADS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <std::size_t _pixel_dim, class _vertex_Allocator, class _texture_Allocator, class _normals_Allocator> inline void draw_ranged_tex_normals_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
			const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image,
			const lnd::group_cluster_vertex<_vertex_count_pc, _dim, _normals_Allocator>& normals)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, _vertex_count_pc * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				normals.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_QUADS, _vertex_count_pc * first_cluster, _vertex_count_pc * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind();
				normals.buffer_unbind();
				break;

			default:
				break;
			}
		}


		template <std::size_t _pixel_dim, std::size_t _spec_pixel_dim, std::size_t _frame_pixel_dim, std::size_t _vertex_count_pc2,
			class _vertex_Allocator, class _texture_Allocator, class _spec_tex_Allocator,
			class _frame_tex_Allocator, class _frame_Allocator> inline void draw_ranged_mapped_3d(
				GLsizei first_cluster,
				GLsizei end_cluster,
				const lnd::program& program,
				const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
				const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image,
				const lnd::texture<_spec_pixel_dim, _spec_tex_Allocator>& spec_texture_image,
				const lnd::texture<_frame_pixel_dim, _frame_tex_Allocator>& frame_texture_image,
				const lnd::group_cluster_vertex<_vertex_count_pc2, _dim, _frame_Allocator>& frames)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(4);
				glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(6 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				spec_texture_image.buffer_bind(1);
				frame_texture_image.buffer_bind(2);
				program.use();
				glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, _vertex_count_pc * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				spec_texture_image.buffer_unbind(1);
				frame_texture_image.buffer_unbind(2);
				frames.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(4);
				glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(6 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				spec_texture_image.buffer_bind(1);
				frame_texture_image.buffer_bind(2);
				program.use();
				glDrawArrays(GL_QUADS, _vertex_count_pc * first_cluster, _vertex_count_pc * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				spec_texture_image.buffer_unbind(1);
				frame_texture_image.buffer_unbind(2);
				frames.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <std::size_t _pixel_dim, std::size_t _spec_pixel_dim, std::size_t _frame_pixel_dim, std::size_t _light_pixel_dim, std::size_t _vertex_count_pc2,
			class _vertex_Allocator, class _light_vertex_Allocator, class _texture_Allocator, class _spec_tex_Allocator,
			class _frame_tex_Allocator, class _light_tex_Allocator, class _frame_Allocator> inline void draw_ranged_lightmapped_3d(
				GLsizei first_cluster,
				GLsizei end_cluster,
				const lnd::program& program,
				const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
				const lnd::group_cluster_vertex<_vertex_count_pc, 2, _light_vertex_Allocator>& lightmap_coord,
				const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image,
				const lnd::texture<_spec_pixel_dim, _spec_tex_Allocator>& spec_texture_image,
				const lnd::texture<_frame_pixel_dim, _frame_tex_Allocator>& frame_texture_image,
				const lnd::texture<_light_pixel_dim, _light_tex_Allocator>& light_texture_image,
				const lnd::group_cluster_vertex<_vertex_count_pc2, _dim, _frame_Allocator>& frames)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				lightmap_coord.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(4);
				glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(5);
				glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(6 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				spec_texture_image.buffer_bind(1);
				frame_texture_image.buffer_bind(2);
				light_texture_image.buffer_bind(3);
				program.use();
				glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, _vertex_count_pc * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				lightmap_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				spec_texture_image.buffer_unbind(1);
				frame_texture_image.buffer_unbind(2);
				light_texture_image.buffer_unbind(3);
				frames.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				lightmap_coord.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
				frames.buffer_bind();
				glEnableVertexAttribArray(3);
				glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), nullptr);
				glEnableVertexAttribArray(4);
				glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(3 * sizeof(GLfloat)));
				glEnableVertexAttribArray(5);
				glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), reinterpret_cast<void*>(6 * sizeof(GLfloat)));
				texture_image.buffer_bind(0);
				spec_texture_image.buffer_bind(1);
				frame_texture_image.buffer_bind(2);
				light_texture_image.buffer_bind(3);
				program.use();
				glDrawArrays(GL_QUADS, _vertex_count_pc * first_cluster, _vertex_count_pc * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				lightmap_coord.buffer_unbind();
				texture_image.buffer_unbind(0);
				spec_texture_image.buffer_unbind(1);
				frame_texture_image.buffer_unbind(2);
				light_texture_image.buffer_unbind(3);
				frames.buffer_unbind();
				break;

			default:
				break;
			}
		}


		// draw indexed clusters

		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_lines_indexed(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, static_cast<GLsizei>(indexing.size()), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_lines_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, static_cast<GLsizei>(indexing.size()), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}


		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_ranged_lines_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, static_cast<GLsizei>(_index_count_pc) * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_ranged_lines_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, static_cast<GLsizei>(_index_count_pc) * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}


		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_tris_indexed(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_tris_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}


		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_ranged_tris_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_tris_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}


		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_quads_indexed(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_quads_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}


		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_ranged_quads_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <std::size_t _index_count_pc, class _index_Allocator> inline void draw_ranged_quads_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}


		// draw indexed clusters with RGB/RGBA gradient colors

		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_lines_RGBA_indexed(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_lines_RGBA_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}


		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_lines_RGBA_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_lines_RGBA_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}


		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_tris_RGBA_indexed(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_tris_RGBA_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}


		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_tris_RGBA_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_tris_RGBA_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}


		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_quads_RGBA_indexed(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_quads_RGBA_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}


		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_quads_RGBA_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <std::size_t _color_dim, std::size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_quads_RGBA_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}
	};

	template <std::size_t _dim, class _Allocator = LND_DEFAULT_ALLOCATOR<LND_VERTEX(GLfloat, _dim)>> class group_vertex
	{

	private:

		std::vector<LND_VERTEX(GLfloat, _dim), _Allocator> _storage;
		lnd::buffer_vertex buffer;

	public:

		group_vertex() = default;
		~group_vertex() = default;
		group_vertex(std::size_t n)
		{
			_storage = std::vector<LND_VERTEX(GLfloat, _dim)>(n, LND_VERTEX(GLfloat, _dim){ 0.0f });
		}
		group_vertex(std::size_t n, const LND_VERTEX(GLfloat, _dim)& x)
		{
			_storage = std::vector<LND_VERTEX(GLfloat, _dim)>(n, x);
		}
		template <class _rhs_Allocator> group_vertex(const group_vertex<_dim, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
		}
		template <class _rhs_Allocator> group_vertex(group_vertex<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
		}
		template <class _rhs_Allocator> group_vertex& operator=(const group_vertex<_dim, _rhs_Allocator>& rhs)
		{
			_storage = rhs._storage;
			return *this;
		}
		template <class _rhs_Allocator> group_vertex& operator=(group_vertex<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			_storage = std::move(rhs._storage);
			return *this;
		}

		group_vertex(std::initializer_list<GLfloat> L)
		{
			_storage = std::vector<LND_VERTEX(GLfloat, _dim), _Allocator>(L.size() / _dim);
			std::copy(L.begin(), L.end(), static_cast<GLfloat*>(static_cast<void*>(_storage.data())));
		}
		group_vertex& operator=(std::initializer_list<GLfloat> L)
		{
			_storage.resize(L.size() / _dim);
			std::copy(L.begin(), L.end(), static_cast<GLfloat*>(static_cast<void*>(_storage.data())));
			return *this;
		}

		inline void buffer_new_id()
		{
			buffer.new_id(1);
		}
		inline void buffer_delete_id()
		{
			buffer.delete_id();
		}
		inline void buffer_bind() const
		{
			buffer.bind();
		}
		inline void buffer_unbind() const
		{
			buffer.unbind();
		}
		inline void buffer_allocate() const
		{
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, this->size() * sizeof(GLfloat), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const GLfloat* const ptr, std::size_t vertex_count) const
		{
			constexpr std::size_t n = _dim * sizeof(GLfloat);
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, n * vertex_count, ptr, GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(GLfloat), this->data());
		}
		inline void buffer_update_from(const GLfloat* const ptr, std::size_t vertex_count) const
		{
			constexpr std::size_t n = _dim * sizeof(GLfloat);
			glNamedBufferSubData(buffer.get(), 0, n * vertex_count, ptr);
		}

		inline const GLfloat* data() const noexcept { return static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())); }
		inline GLfloat* data() noexcept { return static_cast<GLfloat*>(static_cast<void*>(_storage.data())); }
		inline const GLfloat& operator[](std::size_t offset) const noexcept
		{
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + offset);
		}
		inline GLfloat& operator[](std::size_t offset) noexcept
		{
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + offset);
		}
		inline const GLfloat& operator()(std::size_t vertex, std::size_t coord) const noexcept
		{
			return *(static_cast<const GLfloat*>(static_cast<const void*>(_storage.data())) + coord + _dim * vertex);
		}
		inline GLfloat& operator()(std::size_t vertex, std::size_t coord) noexcept
		{
			return *(static_cast<GLfloat*>(static_cast<void*>(_storage.data())) + coord + _dim * vertex);
		}

		inline const LND_VERTEX(GLfloat, _dim)* data_vertex() const noexcept
		{
			return static_cast<const LND_VERTEX(GLfloat, _dim)*>(static_cast<const void*>(_storage.data()));
		}
		inline LND_VERTEX(GLfloat, _dim)* data_vertex() noexcept
		{
			return static_cast<LND_VERTEX(GLfloat, _dim)*>(static_cast<void*>(_storage.data()));
		}
		inline const LND_VERTEX(GLfloat, _dim)& operator()(std::size_t vertex) const noexcept
		{
			return *(static_cast<const LND_VERTEX(GLfloat, _dim)*>(static_cast<const void*>(_storage.data())) + vertex);
		}
		inline LND_VERTEX(GLfloat, _dim)& operator()(std::size_t vertex) noexcept
		{
			return *(static_cast<LND_VERTEX(GLfloat, _dim)*>(static_cast<void*>(_storage.data())) + vertex);
		}

		inline void resize_vertex_count(std::size_t n)
		{
			_storage.resize(n);
		}
		inline void reserve_vertex_count(std::size_t n)
		{
			_storage.reserve(n);
		}
		inline void push_back_vertex(const LND_VERTEX(GLfloat, _dim)& new_vertex)
		{
			_storage.push_back(new_vertex);
		}
		inline void push_front_vertex(const LND_VERTEX(GLfloat, _dim)& new_vertex)
		{
			_storage.push_front(new_vertex);
		}
		inline void pop_back_vertex()
		{
			_storage.pop_back();
		}
		inline void pop_front_vertex()
		{
			_storage.pop_front();
		}
		inline std::size_t vertex_count() const noexcept
		{
			return _storage.size();
		}
		inline std::size_t vertex_capacity() const noexcept
		{
			return _storage.capacity();
		}
		constexpr std::size_t dim() const noexcept
		{
			return _dim;
		}
		inline std::size_t size() const noexcept
		{
			return _dim * _storage.size();
		}
		inline void shrink_to_fit()
		{
			_storage.shrink_to_fit();
		}


		// draw with solid colors

		template <class _index_Allocator> inline void draw_lines_indexed(
			const lnd::program& program,
			const lnd::group_index<_index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			indexing.buffer_bind();
			glDrawElements(GL_LINES, static_cast<GLsizei>(indexing.size()), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <class _index_Allocator> inline void draw_lines_indexed_3d(
			const lnd::program& program,
			const lnd::group_index<_index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			indexing.buffer_bind();
			glDrawElements(GL_LINES, static_cast<GLsizei>(indexing.size()), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}


		template <class _index_Allocator> inline void draw_tris_indexed(
			const lnd::program& program,
			const lnd::group_index<_index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			indexing.buffer_bind();
			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indexing.size()), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <class _index_Allocator> inline void draw_tris_indexed_3d(
			const lnd::program& program,
			const lnd::group_index<_index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			indexing.buffer_bind();
			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indexing.size()), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}


		inline void draw_line_strip(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}

		inline void draw_line_strip_3d(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}


		inline void draw_ranged_line_strip(
			GLsizei first_vertex,
			GLsizei last_vertex,
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, first_vertex, last_vertex - first_vertex);
			buffer.unbind();
		}

		inline void draw_ranged_line_strip_3d(
			GLsizei first_vertex,
			GLsizei last_vertex,
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, first_vertex, last_vertex - first_vertex);
			buffer.unbind();
		}


		inline void draw_line_loop(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}

		inline void draw_line_loop_3d(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}


		inline void draw_tri_strip(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}

		inline void draw_tri_strip_3d(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}


		inline void draw_tri_fan(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}

		inline void draw_tri_fan_3d(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}


		// draw with RGB/RGBA gradient colors

		template <std::size_t _color_dim, class _color_Allocator> inline void draw_line_strip_RGBA(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
		}

		template <std::size_t _color_dim, class _color_Allocator> inline void draw_line_strip_RGBA_3d(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
			break;
		}


		template <std::size_t _color_dim, class _color_Allocator> inline void draw_ranged_line_strip_RGBA(
			GLsizei first_vertex,
			GLsizei last_vertex,
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, first_vertex, last_vertex - first_vertex);
			buffer.unbind();
			coloring.buffer_unbind();
		}

		template <std::size_t _color_dim, class _color_Allocator> inline void draw_ranged_line_strip_RGBA_3d(
			GLsizei first_vertex,
			GLsizei last_vertex,
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, first_vertex, last_vertex - first_vertex);
			buffer.unbind();
			coloring.buffer_unbind();
		}


		template <std::size_t _color_dim, class _color_Allocator> inline void draw_line_loop_RGBA(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
		}

		template <std::size_t _color_dim, class _color_Allocator> inline void draw_line_loop_RGB_3d(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
		}


		template <std::size_t _color_dim, class _color_Allocator> inline void draw_tri_strip_RGBA(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
		}

		template <std::size_t _color_dim, class _color_Allocator> inline void draw_tri_strip_RGBA_3d(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
		}


		template <std::size_t _color_dim, class _color_Allocator> inline void draw_tri_fan_RGBA(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
			coloring.buffer_unbind();
		}

		template <std::size_t _color_dim, class _color_Allocator> inline void draw_tri_fan_RGBA_3d(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(GLfloat), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(GLfloat), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
			coloring.buffer_unbind();
		}
	};


	// TEXT

	template <class _vertex_Allocator = LND_DEFAULT_ALLOCATOR<GLfloat>> class text
	{

	private:

		std::vector<GLfloat, _vertex_Allocator> screen_vertex;
		std::vector<GLfloat, _vertex_Allocator> atlas_vertex;

		lnd::buffer_vertex buffer_screen_vertex;
		lnd::buffer_vertex buffer_atlas_vertex;

		std::size_t _capacity = 0;
		std::size_t _size = 0;

		GLfloat X0 = 0.0f;
		GLfloat Y0 = 0.0f;
		GLfloat dX = 0.0f;

		GLfloat screen_w = 0.0f;
		GLfloat screen_h = 0.0f;

		GLfloat atlas_w = 0.0f;
		GLfloat atlas_h = 0.0f;

	public:

		text() = default;
		~text() = default;
		text(std::size_t n)
		{
			_capacity = n;
			screen_vertex = std::vector<GLfloat, _vertex_Allocator>(n, 0.0f);
			atlas_vertex = std::vector<GLfloat, _vertex_Allocator>(n, 0.0f);
		}
		template <class _rhs_Allocator> text(const text<_rhs_Allocator>& rhs)
		{
			screen_vertex = rhs.screen_vertex;
			atlas_vertex = rhs.screen_vertex;

			X0 = rhs.X0;
			Y0 = rhs.Y0;
			dX = rhs.dX;

			screen_w = rhs.screen_w;
			screen_h = rhs.screen_h;

			atlas_w = rhs.atlas_w;
			atlas_h = rhs.atlas_h;

			_capacity = rhs._capacity;
		}
		template <class _rhs_Allocator> text& operator=(const text<_rhs_Allocator>& rhs)
		{
			screen_vertex = rhs.screen_vertex;
			atlas_vertex = rhs.screen_vertex;

			X0 = rhs.X0;
			Y0 = rhs.Y0;
			dX = rhs.dX;

			screen_w = rhs.screen_w;
			screen_h = rhs.screen_h;

			atlas_w = rhs.atlas_w;
			atlas_h = rhs.atlas_h;

			_capacity = rhs._capacity;
		}
		template <class _rhs_Allocator> text(text<_rhs_Allocator>&& rhs) noexcept
		{
			screen_vertex = std::move(rhs.screen_vertex);
			atlas_vertex = std::move(rhs.screen_vertex);

			X0 = rhs.X0;
			Y0 = rhs.Y0;
			dX = rhs.dX;

			screen_w = rhs.screen_w;
			screen_h = rhs.screen_h;

			atlas_w = rhs.atlas_w;
			atlas_h = rhs.atlas_h;

			_capacity = rhs._capacity;
		}
		template <class _rhs_Allocator> text& operator=(text<_rhs_Allocator>&& rhs) noexcept
		{
			screen_vertex = std::move(rhs.screen_vertex);
			atlas_vertex = std::move(rhs.screen_vertex);

			X0 = rhs.X0;
			Y0 = rhs.Y0;
			dX = rhs.dX;

			screen_w = rhs.screen_w;
			screen_h = rhs.screen_h;

			atlas_w = rhs.atlas_w;
			atlas_h = rhs.atlas_h;

			_capacity = rhs._capacity;
		}

		inline const GLfloat* data_screen_vertex() const noexcept
		{
			return screen_vertex.data();
		}
		inline GLfloat* data_screen_vertex() noexcept
		{
			return screen_vertex.data();
		}

		inline const GLfloat* data_atlas_vertex() const noexcept
		{
			return atlas_vertex.data();
		}
		inline GLfloat* data_atlas_vertex() noexcept
		{
			return atlas_vertex.data();
		}

		inline void set_position_in_screen(GLfloat X, GLfloat Y, GLfloat delta_X) noexcept
		{
			X0 = X;
			Y0 = Y;
			dX = delta_X;
		}
		inline void set_size_in_screen(GLfloat new_width, GLfloat new_height) noexcept
		{
			screen_w = new_width;
			screen_h = new_height;
		}
		inline void set_size_in_atlas(GLfloat new_width, GLfloat new_height) noexcept
		{
			atlas_w = new_width;
			atlas_h = new_height;
		}

		inline std::size_t capacity() const noexcept
		{
			return _capacity;
		}
		inline std::size_t size() const noexcept
		{
			return _size;
		}
		inline void reserve(std::size_t new_capacity)
		{
			_capacity = new_capacity;
			screen_vertex.resize(8 * new_capacity);
			screen_vertex.shrink_to_fit();
			atlas_vertex.resize(8 * new_capacity);
			atlas_vertex.shrink_to_fit();
		}

		inline void buffer_new_id()
		{
			buffer_screen_vertex.new_id(1);
			buffer_atlas_vertex.new_id(1);
		}
		inline void buffer_delete_id()
		{
			buffer_screen_vertex.delete_id();
			buffer_atlas_vertex.delete_id();
		}
		inline void buffer_bind() const
		{
			buffer_screen_vertex.bind();
			buffer_atlas_vertex.bind();
		}
		inline void buffer_unbind() const
		{
			buffer_screen_vertex.unbind();
			buffer_atlas_vertex.unbind();
		}
		inline void buffer_allocate()
		{
			screen_vertex.resize(8 * _capacity);
			GLfloat* ptr = screen_vertex.data();
			GLfloat X;

			for (std::size_t k = 0; k < _capacity; k++)
			{
				X = X0 + static_cast<GLfloat>(k) * dX;

				*ptr = X;
				*(ptr + 1) = Y0;
				*(ptr + 2) = X + screen_w;
				*(ptr + 3) = Y0;
				*(ptr + 4) = X + screen_w;
				*(ptr + 5) = Y0 + screen_h;
				*(ptr + 6) = X;
				*(ptr + 7) = Y0 + screen_h;

				ptr += 8;
			}

			buffer_screen_vertex.bind();
			glBufferData(GL_ARRAY_BUFFER, _capacity * (8 * sizeof(GLfloat)), screen_vertex.data(), GL_STATIC_DRAW);
			buffer_screen_vertex.unbind();

			buffer_atlas_vertex.bind();
			glBufferData(GL_ARRAY_BUFFER, _capacity * (8 * sizeof(GLfloat)), atlas_vertex.data(), GL_STATIC_DRAW);
			buffer_atlas_vertex.unbind();
		}

		inline void buffer_update_screen_vertex() const
		{
			screen_vertex.resize(8 * _capacity);
			GLfloat* ptr = screen_vertex.data();
			GLfloat X;

			for (std::size_t k = 0; k < _capacity; k++)
			{
				X = X0 + static_cast<GLfloat>(k) * dX;

				*ptr = X;
				*(ptr + 1) = Y0;
				*(ptr + 2) = X + screen_w;
				*(ptr + 3) = Y0;
				*(ptr + 4) = X + screen_w;
				*(ptr + 5) = Y0 + screen_h;
				*(ptr + 6) = X;
				*(ptr + 7) = Y0 + screen_h;

				ptr += 8;
			}

			glNamedBufferSubData(buffer_screen_vertex.get(), 0, _capacity * (8 * sizeof(GLfloat)), screen_vertex.data());
		}

		template <typename Ty, class data_to_atlas>
		inline void buffer_update_atlas_vertex(const Ty* text_ptr, std::size_t text_size, data_to_atlas atlas_XY)
		{
			atlas_vertex.resize(8 * text_size);
			GLfloat* ptr = atlas_vertex.data();
			GLfloat X;
			GLfloat Y;

			for (std::size_t k = text_size; k > 0; k--)
			{
				LND_VERTEX(GLfloat, 2) XY = atlas_XY(*text_ptr);

				*ptr = XY[0];
				*(ptr + 1) = XY[1];
				*(ptr + 2) = XY[0] + atlas_w;
				*(ptr + 3) = XY[1];
				*(ptr + 4) = XY[0] + atlas_w;
				*(ptr + 5) = XY[1] + atlas_h;
				*(ptr + 6) = XY[0];
				*(ptr + 7) = XY[1] + atlas_h;

				text_ptr++; ptr += 8;
			}

			_size = text_size;

			glNamedBufferSubData(buffer_atlas_vertex.get(), 0, text_size * (8 * sizeof(GLfloat)), atlas_vertex.data());
		}

		template <std::size_t _dim, class _atlas_Allocator> inline  void draw(const lnd::program& program,
			const lnd::texture<_dim, _atlas_Allocator>& atlas)
		{
			buffer_screen_vertex.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			buffer_atlas_vertex.bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), nullptr);
			atlas.buffer_bind();
			program.use();
			glDrawArrays(GL_QUADS, 0, 4 * static_cast<GLsizei>(_size));
			buffer_screen_vertex.unbind();
			buffer_atlas_vertex.unbind();
			atlas.buffer_unbind();
		}
	};
}


// CAMERA 3D

namespace lnd
{
	class camera_3d
	{

	private:

		GLfloat mvp_matrix[16] = { 0.0f };
		GLfloat vp_matrix[16] = { 0.0f };
		GLfloat p_matrix[16] = {
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};
		GLfloat v_matrix[16] = { 0.0f };
		GLfloat mskybox_matrix[16] = { 0.0f };
		GLfloat skybox_matrix[16] = { 0.0f };

	public:

		camera_3d() = default;
		~camera_3d() = default;
		camera_3d(const lnd::camera_3d&) = default;
		lnd::camera_3d& operator=(const lnd::camera_3d&) = default;
		camera_3d(lnd::camera_3d&&) = default;
		lnd::camera_3d& operator=(lnd::camera_3d&&) = default;

		GLfloat position[4] = { 0.0f };
		GLfloat direction[4] = { 1.0f };

		GLfloat yaw = 0.0f;
		GLfloat pitch = 0.0f;

	private:

		GLfloat cos_yaw = 1.0f;
		GLfloat sin_yaw = 0.0f;
		GLfloat cos_pitch = 1.0f;
		GLfloat sin_pitch = 0.0f;

	public:

		inline void compute_trig() noexcept
		{
			cos_yaw = LND_COS(yaw);
			sin_yaw = LND_SIN(yaw);
			cos_pitch = LND_COS(pitch);
			sin_pitch = LND_SIN(pitch);

			direction[0] = cos_yaw * cos_pitch;
			direction[1] = sin_yaw * cos_pitch;
			direction[2] = sin_pitch;
		}

		inline void compute_p_matrix(GLfloat screen_ratio, GLfloat fov, GLfloat z_far, GLfloat z_near) noexcept
		{
			if (screen_ratio >= 1.0f)
			{
				GLfloat tan_half_fov_y = std::tanf(0.5f * fov);
				GLfloat dz_inv = 1.0f / (z_far - z_near);
				p_matrix[0] = 1.0f / (screen_ratio * tan_half_fov_y);
				p_matrix[5] = 1.0f / tan_half_fov_y;
				p_matrix[10] = (z_far + z_near) * dz_inv;
				p_matrix[14] = ((-2.0f) * z_near) * (z_far * dz_inv);
			}
			else
			{
				GLfloat tan_half_fov_x = std::tanf(0.5f * fov);
				GLfloat dz_inv = 1.0f / (z_far - z_near);
				p_matrix[0] = 1.0f / tan_half_fov_x;
				p_matrix[5] = screen_ratio / tan_half_fov_x;
				p_matrix[10] = (z_far + z_near) * dz_inv;
				p_matrix[14] = ((-2.0f) * z_near) * (z_far * dz_inv);
			}
		}
		inline void compute_v_matrix() noexcept
		{
			v_matrix[0] = sin_yaw;
			v_matrix[1] = -cos_yaw * sin_pitch;
			v_matrix[2] = cos_yaw * cos_pitch;
			v_matrix[3] = 0.0f;

			v_matrix[4] = -cos_yaw;
			v_matrix[5] = -sin_yaw * sin_pitch;
			v_matrix[6] = sin_yaw * cos_pitch;
			v_matrix[7] = 0.0f;

			v_matrix[8] = 0.0f;
			v_matrix[9] = cos_pitch;
			v_matrix[10] = sin_pitch;
			v_matrix[11] = 0.0f;

			v_matrix[12] = cos_yaw * position[1] - sin_yaw * position[0];
			v_matrix[13] = cos_yaw * sin_pitch * position[0] + sin_yaw * sin_pitch * position[1] - cos_pitch * position[2];
			v_matrix[14] = -cos_yaw * cos_pitch * position[0] - sin_yaw * cos_pitch * position[1] - sin_pitch * position[2];
			v_matrix[15] = 1.0f;
		}
		inline void compute_vp_matrix() noexcept
		{
			m44xm44(static_cast<GLfloat*>(vp_matrix), static_cast<const GLfloat*>(p_matrix),
				static_cast<const GLfloat*>(v_matrix));
		}
		inline void compute_mvp_matrix(const GLfloat* const m_matrix_ptr) noexcept
		{
			m44xm44(static_cast<GLfloat*>(mvp_matrix), static_cast<const GLfloat*>(vp_matrix), m_matrix_ptr);
		}
		inline void compute_skybox_matrix() noexcept
		{
			m33hxm44(static_cast<GLfloat*>(skybox_matrix), static_cast<const GLfloat*>(p_matrix),
				static_cast<const GLfloat*>(v_matrix));
		}
		inline void compute_mskybox_matrix(const GLfloat* const m_matrix_ptr) noexcept
		{
			m44xm44(static_cast<GLfloat*>(mskybox_matrix), static_cast<const GLfloat*>(skybox_matrix), m_matrix_ptr);
		}

		inline const GLfloat* position_data() const noexcept
		{
			return static_cast<const GLfloat*>(position);
		}
		inline GLfloat* position_data() noexcept
		{
			return static_cast<GLfloat*>(position);
		}

		inline const GLfloat* direction_data() const noexcept
		{
			return static_cast<const GLfloat*>(direction);
		}
		inline GLfloat* direction_data() noexcept
		{
			return static_cast<GLfloat*>(direction);
		}

		inline const GLfloat* v_matrix_data() const noexcept
		{
			return static_cast<const GLfloat*>(v_matrix);
		}
		inline GLfloat* v_matrix_data() noexcept
		{
			return static_cast<GLfloat*>(v_matrix);
		}

		inline const GLfloat* p_matrix_data() const noexcept
		{
			return static_cast<const GLfloat*>(p_matrix);
		}
		inline GLfloat* p_matrix_data() noexcept
		{
			return static_cast<GLfloat*>(p_matrix);
		}

		inline const GLfloat* vp_matrix_data() const noexcept
		{
			return static_cast<const GLfloat*>(vp_matrix);
		}
		inline GLfloat* vp_matrix_data() noexcept
		{
			return static_cast<GLfloat*>(vp_matrix);
		}

		inline const GLfloat* mvp_matrix_data() const noexcept
		{
			return static_cast<const GLfloat*>(mvp_matrix);
		}
		inline GLfloat* mvp_matrix_data() noexcept
		{
			return static_cast<GLfloat*>(mvp_matrix);
		}

		inline const GLfloat* skybox_matrix_data() const noexcept
		{
			return static_cast<const GLfloat*>(skybox_matrix);
		}
		inline GLfloat* skybox_matrix_data() noexcept
		{
			return static_cast<GLfloat*>(skybox_matrix);
		}

		inline const GLfloat* mskybox_matrix_data() const noexcept
		{
			return static_cast<const GLfloat*>(mskybox_matrix);
		}
		inline GLfloat* mskybox_matrix_data() noexcept
		{
			return static_cast<GLfloat*>(mskybox_matrix);
		}

		inline void move_forward(GLfloat distance) noexcept
		{
			position[0] += distance * cos_yaw;
			position[1] += distance * sin_yaw;
		}
		inline void move_backward(GLfloat distance) noexcept
		{
			position[0] -= distance * cos_yaw;
			position[1] -= distance * sin_yaw;
		}
		inline void move_left(GLfloat distance) noexcept
		{
			position[0] -= distance * sin_yaw;
			position[1] += distance * cos_yaw;
		}
		inline void move_right(GLfloat distance) noexcept
		{
			position[0] += distance * sin_yaw;
			position[1] -= distance * cos_yaw;
		}
		inline void move_up(GLfloat distance) noexcept
		{
			position[2] += distance;
		}
		inline void move_down(GLfloat distance) noexcept
		{
			position[2] -= distance;
		}

		inline void turn_up_rad(GLfloat angle) noexcept
		{
			constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
			pitch += angle;
			if (pitch > pi_d2) { pitch = pi_d2; }
		}
		inline void turn_down_rad(GLfloat angle) noexcept
		{
			constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
			pitch -= angle;
			if (pitch < -pi_d2) { pitch = -pi_d2; }
		}
		inline void turn_left_rad(GLfloat angle) noexcept
		{
			constexpr GLfloat pi = 3.14159265358979f;
			constexpr GLfloat pi_m2 = 2.0f * 3.14159265358979f;
			yaw += angle;
			if (yaw > pi) { yaw -= pi_m2; }
		}
		inline void turn_right_rad(GLfloat angle) noexcept
		{
			constexpr GLfloat pi = 3.14159265358979f;
			constexpr GLfloat pi_m2 = 2.0f * 3.14159265358979f;
			yaw -= angle;
			if (yaw < -pi) { yaw += pi_m2; }
		}
		inline void turn_up_deg(GLfloat angle) noexcept
		{
			constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
			constexpr GLfloat coeff = 3.14159265358979f / 180.0f;
			pitch += coeff * angle;
			if (pitch > pi_d2) { pitch = pi_d2; }
		}
		inline void turn_down_deg(GLfloat angle) noexcept
		{
			constexpr GLfloat pi_d2 = 0.5f * 3.14159265358979f;
			constexpr GLfloat coeff = 3.14159265358979f / 180.0f;
			pitch -= coeff * angle;
			if (pitch < -pi_d2) { pitch = -pi_d2; }
		}
		inline void turn_left_deg(GLfloat angle) noexcept
		{
			constexpr GLfloat pi = 3.14159265358979f;
			constexpr GLfloat pi_m2 = 2.0f * 3.14159265358979f;
			constexpr GLfloat coeff = 3.14159265358979f / 180.0f;
			yaw += coeff * angle;
			if (yaw > pi) { yaw -= pi_m2; }
		}
		inline void turn_right_deg(GLfloat angle) noexcept
		{
			constexpr GLfloat pi = 3.14159265358979f;
			constexpr GLfloat pi_m2 = 2.0f * 3.14159265358979f;
			constexpr GLfloat coeff = 3.14159265358979f / 180.0f;
			yaw -= coeff * angle;
			if (yaw < -pi) { yaw += pi_m2; }
		}

	private:

		inline void m44xm44(GLfloat* const pC, const GLfloat* const pA, const GLfloat* const pB) noexcept
		{
#ifdef LND_AVX_EXT
			__m128 vregA0 = _mm_loadu_ps(pA);
			__m128 vregA1 = _mm_loadu_ps(pA + 4);
			__m128 vregA2 = _mm_loadu_ps(pA + 8);
			__m128 vregA3 = _mm_loadu_ps(pA + 12);

			__m128 vregC0 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB));
			__m128 vregC1 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 4));
			vregC0 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 1), vregC0);
			vregC1 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 5), vregC1);
			vregC0 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 2), vregC0);
			vregC1 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 6), vregC1);
			vregC0 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 3), vregC0);
			vregC1 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 7), vregC1);
			_mm_storeu_ps(pC, vregC0);
			_mm_storeu_ps(pC + 4, vregC1);

			vregC0 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 8));
			vregC1 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 12));
			vregC0 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 9), vregC0);
			vregC1 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 13), vregC1);
			vregC0 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 10), vregC0);
			vregC1 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 14), vregC1);
			vregC0 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 11), vregC0);
			vregC1 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 15), vregC1);
			_mm_storeu_ps(pC + 8, vregC0);
			_mm_storeu_ps(pC + 12, vregC1);
#else // LND_AVX_EXT
			GLfloat regB0; GLfloat regB1; std::size_t offset;
			for (std::size_t j = 0; j < 4; j++)
			{
				offset = 4 * j;
				regB0 = *(pB + offset);
				*(pC + offset) = *pA * regB0;
				*(pC + (offset + 1)) = *(pA + 1) * regB0;
				*(pC + (offset + 2)) = *(pA + 2) * regB0;
				*(pC + (offset + 3)) = *(pA + 3) * regB0;
				regB1 = *(pB + (offset + 1));
				*(pC + offset) += *(pA + 4) * regB1;
				*(pC + (offset + 1)) += *(pA + 5) * regB1;
				*(pC + (offset + 2)) += *(pA + 6) * regB1;
				*(pC + (offset + 3)) += *(pA + 7) * regB1;
				regB0 = *(pB + (offset + 2));
				*(pC + offset) += *(pA + 8) * regB0;
				*(pC + (offset + 1)) += *(pA + 9) * regB0;
				*(pC + (offset + 2)) += *(pA + 10) * regB0;
				*(pC + (offset + 3)) += *(pA + 11) * regB0;
				regB1 = *(pB + (offset + 3));
				*(pC + offset) += *(pA + 12) * regB1;
				*(pC + (offset + 1)) += *(pA + 13) * regB1;
				*(pC + (offset + 2)) += *(pA + 14) * regB1;
				*(pC + (offset + 3)) += *(pA + 15) * regB1;
			}
#endif // LND_AVX_EXT
		}
		inline void m33hxm44(GLfloat* const pC, const GLfloat* const pA, const GLfloat* const pB) noexcept
		{
#ifdef LND_AVX_EXT
			__m128 vregA0 = _mm_loadu_ps(pA);
			__m128 vregA1 = _mm_loadu_ps(pA + 4);
			__m128 vregA2 = _mm_loadu_ps(pA + 8);
			__m128 vregA3 = _mm_loadu_ps(pA + 12);

			__m128 vregC0 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB));
			__m128 vregC1 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 4));
			vregC0 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 1), vregC0);
			vregC1 = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 5), vregC1);
			vregC0 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 2), vregC0);
			vregC1 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 6), vregC1);
			vregC0 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 3), vregC0);
			vregC1 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 7), vregC1);
			_mm_storeu_ps(pC, vregC0);
			_mm_storeu_ps(pC + 4, vregC1);

			vregC0 = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 8));
			vregC1 = _mm_mul_ps(vregA1, _mm_broadcast_ss(pB + 9));
			vregC0 = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 10), vregC0);
			vregC1 = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 11), vregC1);
			_mm_storeu_ps(pC + 12, vregA3);
			_mm_storeu_ps(pC + 8, _mm_add_ps(vregC0, vregC1));
#else // LND_AVX_EXT
			GLfloat regB0; GLfloat regB1; std::size_t offset;
			for (std::size_t j = 0; j < 3; j++)
			{
				offset = 4 * j;
				regB0 = *(pB + offset);
				*(pC + offset) = *pA * regB0;
				*(pC + (offset + 1)) = *(pA + 1) * regB0;
				*(pC + (offset + 2)) = *(pA + 2) * regB0;
				*(pC + (offset + 3)) = *(pA + 3) * regB0;
				regB1 = *(pB + (offset + 1));
				*(pC + offset) += *(pA + 4) * regB1;
				*(pC + (offset + 1)) += *(pA + 5) * regB1;
				*(pC + (offset + 2)) += *(pA + 6) * regB1;
				*(pC + (offset + 3)) += *(pA + 7) * regB1;
				regB0 = *(pB + (offset + 2));
				*(pC + offset) += *(pA + 8) * regB0;
				*(pC + (offset + 1)) += *(pA + 9) * regB0;
				*(pC + (offset + 2)) += *(pA + 10) * regB0;
				*(pC + (offset + 3)) += *(pA + 11) * regB0;
				regB1 = *(pB + (offset + 3));
				*(pC + offset) += *(pA + 12) * regB1;
				*(pC + (offset + 1)) += *(pA + 13) * regB1;
				*(pC + (offset + 2)) += *(pA + 14) * regB1;
				*(pC + (offset + 3)) += *(pA + 15) * regB1;
			}
			memcpy(pC + 12, pA + 12, 4 * sizeof(GLfloat));
#endif // LND_AVX_EXT
		}
	};

	class model_3d
	{

	private:

		GLfloat m_matrix[16] = {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f,
		};

	public:

		model_3d() = default;
		~model_3d() = default;
		model_3d(const lnd::model_3d&) = default;
		lnd::model_3d& operator=(const lnd::model_3d&) = default;
		model_3d(lnd::model_3d&&) = default;
		lnd::model_3d& operator=(lnd::model_3d&&) = default;

		inline const GLfloat* m_matrix_data() const noexcept
		{
			return static_cast<const GLfloat*>(m_matrix);
		}
		inline GLfloat* m_matrix_data() noexcept
		{
			return static_cast<GLfloat*>(m_matrix);
		}

		inline void set_position(GLfloat x, GLfloat y, GLfloat z) noexcept
		{
			m_matrix[12] = x;
			m_matrix[13] = y;
			m_matrix[14] = z;
		}
		inline void set_position(const GLfloat* const position_ptr)
		{
			memcpy(static_cast<GLfloat*>(m_matrix) + 12, position_ptr, 3 * sizeof(GLfloat));
		}

		inline void set_angles_rad(GLfloat yaw, GLfloat pitch, GLfloat roll) noexcept
		{
			GLfloat cos_yaw = LND_COS(yaw);
			GLfloat sin_yaw = LND_SIN(yaw);

			GLfloat cos_pitch = LND_COS(pitch);
			GLfloat sin_pitch = LND_SIN(pitch);

			GLfloat cos_roll = LND_COS(roll);
			GLfloat sin_roll = LND_SIN(roll);

			m_matrix[0] = cos_yaw * cos_pitch;
			m_matrix[1] = sin_yaw * cos_pitch;
			m_matrix[2] = sin_pitch;

			m_matrix[4] = cos_yaw * sin_pitch * sin_roll - sin_yaw * cos_roll;
			m_matrix[5] = cos_yaw * cos_roll + sin_yaw * sin_pitch * sin_roll;
			m_matrix[6] = -cos_pitch * sin_roll;

			m_matrix[8] = -(sin_yaw * sin_roll + cos_yaw * sin_pitch * cos_roll);
			m_matrix[9] = cos_yaw * sin_roll - sin_yaw * sin_pitch * cos_roll;
			m_matrix[10] = cos_pitch * cos_roll;
		}
		inline void set_angles_deg(GLfloat yaw, GLfloat pitch, GLfloat roll) noexcept
		{
			constexpr GLfloat coeff = 3.14159265358979f / 180.0f;

			yaw *= coeff;
			pitch *= coeff;
			roll *= coeff;

			GLfloat cos_yaw = LND_COS(yaw);
			GLfloat sin_yaw = LND_SIN(yaw);

			GLfloat cos_pitch = LND_COS(pitch);
			GLfloat sin_pitch = LND_SIN(pitch);

			GLfloat cos_roll = LND_COS(roll);
			GLfloat sin_roll = LND_SIN(roll);

			m_matrix[0] = cos_yaw * cos_pitch;
			m_matrix[1] = sin_yaw * cos_pitch;
			m_matrix[2] = sin_pitch;

			m_matrix[4] = cos_yaw * sin_pitch * sin_roll - sin_yaw * cos_roll;
			m_matrix[5] = cos_yaw * cos_roll + sin_yaw * sin_pitch * sin_roll;
			m_matrix[6] = -cos_pitch * sin_roll;

			m_matrix[8] = -(sin_yaw * sin_roll + cos_yaw * sin_pitch * cos_roll);
			m_matrix[9] = cos_yaw * sin_roll - sin_yaw * sin_pitch * cos_roll;
			m_matrix[10] = cos_pitch * cos_roll;
		}
	};
}


#undef LND_VERTEX
#undef LND_CLOCK
#undef LND_COS
#undef LND_SIN
#undef LND_SQRT


#endif // LOOPNDISPLAY_HPP


// loopndisplay.hpp
// 
// This is free software released into the public domain.
// 
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software for any purpose and by any means.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY IN CONNECTION WITH THE SOFTWARE.
