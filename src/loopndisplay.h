// loopndisplay.h - last update : 04 / 10 / 2020
// License <http://unlicense.org/> (statement below at the end of the file)

// Needs GLFW and GLEW installed
// https://www.glfw.org/
// http://glew.sourceforge.net/



////// API //////

// write the following methods in a derived class (looper_derived_class for an example)
// putting the looper as protected:

// void setup() { your code here in the derived class ... }
// inline void loop(float time_elapsed) { your code here in the derived class ... }
// inline void display() { your code here in the derived class ... }
// void exit() { your code here in the derived class ... }
// inline bool exit_condition() { your code here in the derived class ... }

// the method call_display() runs the method display(), must be called in the loop(float time_elapsed) method


// as an example, you can enter the following code in the main:

// lnd::window<looper_derived_class> window_example;
// window_example.show(640, 480, true, 0.02, "My program !");



#ifndef LOOPNDISPLAY_H
#define LOOPNDISPLAY_H


////// OPTIONS //////

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
#define LND_COS std::cosf
#endif // LND_COS

#ifndef LND_SIN
#define LND_SIN std::sinf
#endif // LND_SIN

#ifndef LND_SQRT
#define LND_SQRT std::sqrtf
#endif // LND_SQRT

#ifndef LND_ALLOCATOR
#define LND_ALLOCATOR std::allocator
#endif // LND_ALLOCATOR


////// INCLUDES //////

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif // GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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

#ifdef LND_INCLUDE_AVX
#include <immintrin.h>
#endif // LND_INCLUDE_AVX


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

	int  padding0[8] = { 0 };
	GLFWwindow* __window_ptr = nullptr;
	int  padding1[8] = { 0 };
	lnd::user_key_input __user_key_input;
	int  padding2[8] = { 0 };
	lnd::user_mouse_input __user_mouse_input;
	int  padding3[8] = { 0 };
	GLbitfield __clear_window = GL_COLOR_BUFFER_BIT;
	int  padding4[8] = { 0 };


	// ON CALLBACK

	void key_callback(GLFWwindow* window_ptr, int key, int scancode, int action, int mods)
	{
		switch (key)
		{

		case GLFW_KEY_SPACE:
			lnd::__user_key_input.space_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.space_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_APOSTROPHE:
			lnd::__user_key_input.apostrophe_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.apostrophe_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_COMMA:
			lnd::__user_key_input.comma_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.comma_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_MINUS:
			lnd::__user_key_input.minus_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.minus_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_PERIOD:
			lnd::__user_key_input.period_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.period_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_SLASH:
			lnd::__user_key_input.slash_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.slash_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_A:
			lnd::__user_key_input.A_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.A_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_B:
			lnd::__user_key_input.B_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.B_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_C:
			lnd::__user_key_input.C_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.C_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_D:
			lnd::__user_key_input.D_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.D_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_E:
			lnd::__user_key_input.E_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.E_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F:
			lnd::__user_key_input.F_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.F_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_G:
			lnd::__user_key_input.G_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.G_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_H:
			lnd::__user_key_input.H_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.H_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_I:
			lnd::__user_key_input.I_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.I_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_J:
			lnd::__user_key_input.J_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.J_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_K:
			lnd::__user_key_input.K_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.K_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_L:
			lnd::__user_key_input.L_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.L_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_M:
			lnd::__user_key_input.M_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.M_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_N:
			lnd::__user_key_input.N_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.N_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_O:
			lnd::__user_key_input.O_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.O_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_P:
			lnd::__user_key_input.P_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.P_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_Q:
			lnd::__user_key_input.Q_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.Q_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_R:
			lnd::__user_key_input.R_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.R_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_S:
			lnd::__user_key_input.S_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.S_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_T:
			lnd::__user_key_input.T_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.T_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_U:
			lnd::__user_key_input.U_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.U_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_V:
			lnd::__user_key_input.V_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.V_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_W:
			lnd::__user_key_input.W_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.W_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_X:
			lnd::__user_key_input.X_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.X_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_Y:
			lnd::__user_key_input.Y_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.Y_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_Z:
			lnd::__user_key_input.Z_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.Z_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_0:
			lnd::__user_key_input.num0_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.num0_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_1:
			lnd::__user_key_input.num1_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.num1_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_2:
			lnd::__user_key_input.num2_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.num2_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_3:
			lnd::__user_key_input.num3_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.num3_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_4:
			lnd::__user_key_input.num4_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.num4_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_5:
			lnd::__user_key_input.num5_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.num5_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_6:
			lnd::__user_key_input.num6_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.num6_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_7:
			lnd::__user_key_input.num7_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.num7_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_8:
			lnd::__user_key_input.num8_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.num8_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_9:
			lnd::__user_key_input.num9_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.num9_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_0:
			lnd::__user_key_input.numpad0_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.numpad0_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_1:
			lnd::__user_key_input.numpad1_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.numpad1_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_2:
			lnd::__user_key_input.numpad2_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.numpad2_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_3:
			lnd::__user_key_input.numpad3_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.numpad3_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_4:
			lnd::__user_key_input.numpad4_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.numpad4_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_5:
			lnd::__user_key_input.numpad5_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.numpad5_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_6:
			lnd::__user_key_input.numpad6_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.numpad6_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_7:
			lnd::__user_key_input.numpad7_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.numpad7_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_8:
			lnd::__user_key_input.numpad8_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.numpad8_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_9:
			lnd::__user_key_input.numpad9_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.numpad9_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_ADD:
			lnd::__user_key_input.add_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.add_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_SUBTRACT:
			lnd::__user_key_input.sub_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.sub_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_MULTIPLY:
			lnd::__user_key_input.mul_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.mul_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_DIVIDE:
			lnd::__user_key_input.div_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.div_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_KP_ENTER:
			lnd::__user_key_input.enter_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.enter_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F1:
			lnd::__user_key_input.f1_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f1_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F2:
			lnd::__user_key_input.f2_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f2_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F3:
			lnd::__user_key_input.f3_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f3_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F4:
			lnd::__user_key_input.f4_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f4_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F5:
			lnd::__user_key_input.f5_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f5_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F6:
			lnd::__user_key_input.f6_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f6_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F7:
			lnd::__user_key_input.f7_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f7_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F8:
			lnd::__user_key_input.f8_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f8_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F9:
			lnd::__user_key_input.f9_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f9_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F10:
			lnd::__user_key_input.f10_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f10_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F11:
			lnd::__user_key_input.f11_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f11_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_F12:
			lnd::__user_key_input.f12_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.f12_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_ESCAPE:
			lnd::__user_key_input.escape_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.escape_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_ENTER:
			lnd::__user_key_input.enter_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.enter_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_TAB:
			lnd::__user_key_input.tab_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.tab_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_BACKSPACE:
			lnd::__user_key_input.backspace_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.backspace_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_INSERT:
			lnd::__user_key_input.insert_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.insert_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_DELETE:
			lnd::__user_key_input.delete__press.store(action == GLFW_PRESS);
			lnd::__user_key_input.delete__release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_RIGHT:
			lnd::__user_key_input.right_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.right_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_LEFT:
			lnd::__user_key_input.left_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.left_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_DOWN:
			lnd::__user_key_input.down_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.down_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_UP:
			lnd::__user_key_input.up_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.up_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_LEFT_ALT:
			lnd::__user_key_input.alt_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.alt_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_RIGHT_ALT:
			lnd::__user_key_input.alt_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.alt_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_LEFT_SHIFT:
			lnd::__user_key_input.shift_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.shift_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_RIGHT_SHIFT:
			lnd::__user_key_input.shift_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.shift_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_LEFT_CONTROL:
			lnd::__user_key_input.ctrl_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.ctrl_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_KEY_RIGHT_CONTROL:
			lnd::__user_key_input.ctrl_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.ctrl_release.store(action == GLFW_RELEASE);
			break;

		default:
			break;
		}
	}
	void mouse_button_callback(GLFWwindow* window_ptr, int button, int action, int mods)
	{
		switch (button)
		{

		case GLFW_MOUSE_BUTTON_1:
			lnd::__user_key_input.mouse_1_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.mouse_1_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_2:
			lnd::__user_key_input.mouse_2_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.mouse_2_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_3:
			lnd::__user_key_input.mouse_3_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.mouse_3_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_4:
			lnd::__user_key_input.mouse_4_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.mouse_4_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_5:
			lnd::__user_key_input.mouse_5_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.mouse_5_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_6:
			lnd::__user_key_input.mouse_6_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.mouse_6_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_7:
			lnd::__user_key_input.mouse_7_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.mouse_7_release.store(action == GLFW_RELEASE);
			break;
		case GLFW_MOUSE_BUTTON_8:
			lnd::__user_key_input.mouse_8_press.store(action == GLFW_PRESS);
			lnd::__user_key_input.mouse_8_release.store(action == GLFW_RELEASE);
			break;

		default:
			break;
		}
	}
	void mouse_position_callback(GLFWwindow* window_ptr, double input_mouse_X, double input_mouse_Y)
	{
		lnd::__user_mouse_input.mouse_X.store(static_cast<float>(lnd::__user_mouse_input.X_scale * (input_mouse_X - lnd::__user_mouse_input.X_shift)));
		lnd::__user_mouse_input.mouse_Y.store(static_cast<float>(lnd::__user_mouse_input.Y_scale * (lnd::__user_mouse_input.Y_shift - input_mouse_Y)));
	}
}


// BUFFERS

namespace lnd
{
	class buffer_vertex
	{

	private:

		unsigned int buffer_index = 0;
		int objects = 0;

	public:

		buffer_vertex() = default;
		~buffer_vertex() { delete_id(); }

		inline const unsigned int get() const noexcept { return buffer_index; }
		inline void bind() const { glBindBuffer(GL_ARRAY_BUFFER, buffer_index); }
		inline void unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

		inline void new_id(int number_of_objects)
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

		unsigned int buffer_index = 0;
		int objects = 0;

	public:

		buffer_color() = default;
		~buffer_color() { delete_id(); }

		inline const unsigned int get() const noexcept { return buffer_index; }
		inline void bind() const { glBindBuffer(GL_ARRAY_BUFFER, buffer_index); }
		inline void unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

		inline void new_id(int number_of_objects)
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

		unsigned int _buffer_index = 0;
		int objects = 0;

	public:

		buffer_index() = default;
		~buffer_index() { delete_id(); }

		inline const unsigned int get() const noexcept { return _buffer_index; }
		inline void bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _buffer_index); }
		inline void unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

		void new_id(int number_of_objects)
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

		unsigned int buffer_index = 0;
		int objects = 0;

	public:

		buffer_texture() = default;
		~buffer_texture() { delete_id(); }

		inline const unsigned int get() const noexcept { return buffer_index; }
		inline void bind() const { glBindTexture(GL_TEXTURE_2D, buffer_index); }
		inline void unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }

		inline void new_id(int number_of_objects)
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

		unsigned int shader_index = 0;

	public:

		shader_vertex() = default;
		~shader_vertex() { delete_shader(); }

		inline const unsigned int get() const noexcept { return shader_index; }

		void new_shader(const std::string& shader_text)
		{
			shader_index = glCreateShader(GL_VERTEX_SHADER);
			const char* src = shader_text.c_str();
			glShaderSource(shader_index, 1, &src, nullptr);
			glCompileShader(shader_index);

			int result;
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

		unsigned int shader_index = 0;

	public:

		shader_fragment() = default;
		~shader_fragment() { delete_shader(); }

		inline const unsigned int get() const noexcept { return shader_index; }

		void new_shader(const std::string& shader_text)
		{
			shader_index = glCreateShader(GL_FRAGMENT_SHADER);
			const char* src = shader_text.c_str();
			glShaderSource(shader_index, 1, &src, nullptr);
			glCompileShader(shader_index);

			int result;
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

		unsigned int program_index = 0;
		unsigned int vertex_shader_index = 0;
		unsigned int fragment_shader_index = 0;

	public:

		program() = default;
		~program() { delete_program(); }

		inline const unsigned int get() const noexcept { return program_index; }
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
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (in_X[0] + u_X[0]),				\n"
					"		in_X[1] + u_X[1], in_X[2], in_X[3]);			\n"
					"		X = vec2(in_X); }								\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	out vec2 X;											\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		in_X[0] + u_X[0],								\n"
					"		" + ratio + " * (in_X[1] + u_X[1]),				\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X); }								\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core						\n"
				"	layout (location = 0) in vec4 in_X;		\n"
				"	out vec2 X;								\n"
				"	uniform vec2 u_X;						\n"
				"	void main() { gl_Position = vec4(		\n"
				"		in_X[0] + u_X[0],					\n"
				"		in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X); }					\n"
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
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (u_X[2] * in_X[0] + u_X[0]),	\n"
					"		u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X); }								\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core									\n"
					"	layout (location = 0) in vec4 in_X;					\n"
					"	out vec2 X;											\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		u_X[2] * in_X[0] + u_X[0],						\n"
					"		" + ratio + " * (u_X[2] * in_X[1] + u_X[1]),	\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X); }								\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core						\n"
				"	layout (location = 0) in vec4 in_X;		\n"
				"	out vec2 X;								\n"
				"	uniform vec3 u_X;						\n"
				"	void main() { gl_Position = vec4(		\n"
				"		u_X[2] * in_X[0] + u_X[0],			\n"
				"		u_X[2] * in_X[1] + u_X[1],			\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X); }					\n"
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
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		" + ratio + " * (u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0]),		\n"
					"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X); }													\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core														\n"
					"	layout (location = 0) in vec4 in_X;										\n"
					"	out vec2 X;																\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],						\n"
					"		" + ratio + " * (u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1]),		\n"
					"		in_X[2], in_X[3]);													\n"
					"		X = vec2(in_X); }													\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core									\n"
				"	layout (location = 0) in vec4 in_X;					\n"
				"	out vec2 X;											\n"
				"	uniform vec4 u_X;									\n"
				"	void main() { gl_Position = vec4(					\n"
				"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],	\n"
				"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1],	\n"
				"		in_X[2], in_X[3]);								\n"
				"		X = vec2(in_X); }								\n"
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
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		" + ratio + " * (u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3]))),	\n"
					"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])), in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X); }																				\n"
					;
			}
			else
			{
				std::string ratio = std::to_string(screen_width / screen_height);
				return
					"	#version 330 core																					\n"
					"	layout (location = 0) in vec4 in_X;																	\n"
					"	out vec2 X;																							\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),						\n"
					"		" + ratio + " * (u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3]))),	\n"
					"		in_X[2], in_X[3]);																				\n"
					"		X = vec2(in_X); }																				\n"
					;
			}
		}
		else
		{
			return
				"	#version 330 core																\n"
				"	layout (location = 0) in vec4 in_X;												\n"
				"	out vec2 X;																		\n"
				"	uniform vec4 u_X0;																\n"
				"	uniform vec4 u_X1;																\n"
				"	void main() { gl_Position  = vec4(												\n"
				"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),	\n"
				"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])),	\n"
				"		in_X[2], in_X[3]);															\n"
				"		X = vec2(in_X); }															\n"
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
					"	out vec2 X;													\n"
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
					"	out vec3 C;												\n"
					"	uniform vec2 u_X;										\n"
					"	void main() { gl_Position = vec4(						\n"
					"		" + ratio + " * (in_X[0] + u_X[0]),					\n"
					"		in_X[1] + u_X[1], in_X[2], in_X[3]);				\n"
					"		X = vec2(in_X);										\n"
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
					"	out vec3 C;											\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		in_X[0] + u_X[0],								\n"
					"		" + ratio + " * (in_X[1] + u_X[1]),				\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
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
				"   out vec3 C;								\n"
				"   uniform vec2 u_X;						\n"
				"   void main() { gl_Position = vec4(		\n"
				"       in_X[0] + u_X[0],					\n"
				"       in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
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
					"	out vec3 C;											\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (u_X[2] * in_X[0] + u_X[0]),	\n"
					"		u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);									\n"
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
					"	out vec3 C;											\n"
					"	uniform vec4 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		u_X[2] * in_X[0] + u_X[0],						\n"
					"		" + ratio + " * (u_X[2] * in_X[1] + u_X[1]),	\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
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
				"   out vec3 C;								\n"
				"   uniform vec2 u_X;						\n"
				"   void main() { gl_Position = vec4(		\n"
				"       in_X[0] + u_X[0],					\n"
				"       in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
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
					"	out vec3 C;																\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		" + ratio + " * (u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0]),		\n"
					"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);														\n"
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
					"	out vec3 C;																\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],						\n"
					"		" + ratio + " * (u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1]),		\n"
					"		in_X[2], in_X[3]);													\n"
					"		X = vec2(in_X);														\n"
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
				"	out vec3 C;											\n"
				"	uniform vec4 u_X;									\n"
				"	void main() { gl_Position = vec4(					\n"
				"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],	\n"
				"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1],	\n"
				"		in_X[2], in_X[3]);								\n"
				"		X = vec2(in_X);									\n"
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
					"	out vec3 C;																							\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		" + ratio + " * (u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3]))),	\n"
					"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])), in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);																					\n"
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
					"	out vec3 C;																							\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),						\n"
					"		" + ratio + " * (u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3]))),	\n"
					"		in_X[2], in_X[3]);																				\n"
					"		X = vec2(in_X);																					\n"
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
				"	out vec3 C;																		\n"
				"	uniform vec4 u_X0;																\n"
				"	uniform vec4 u_X1;																\n"
				"	void main() { gl_Position  = vec4(												\n"
				"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),	\n"
				"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])),	\n"
				"		in_X[2], in_X[3]);															\n"
				"		X = vec2(in_X);																\n"
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
					"	out vec4 C;											\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (in_X[0] + u_X[0]),				\n"
					"		in_X[1] + u_X[1], in_X[2], in_X[3]);			\n"
					"		X = vec2(in_X);									\n"
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
					"	out vec4 C;											\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		in_X[0] + u_X[0],								\n"
					"		" + ratio + " * (in_X[1] + u_X[1]),				\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
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
				"   out vec4 C;								\n"
				"   uniform vec2 u_X;						\n"
				"   void main() { gl_Position = vec4(		\n"
				"       in_X[0] + u_X[0],					\n"
				"       in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
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
					"	out vec4 C;											\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (u_X[2] * in_X[0] + u_X[0]),	\n"
					"		u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);									\n"
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
					"	out vec4 C;											\n"
					"	uniform vec4 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		u_X[2] * in_X[0] + u_X[0],						\n"
					"		" + ratio + " * (u_X[2] * in_X[1] + u_X[1]),	\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
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
				"   out vec4 C;								\n"
				"   uniform vec2 u_X;						\n"
				"   void main() { gl_Position = vec4(		\n"
				"       in_X[0] + u_X[0],					\n"
				"       in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
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
					"	out vec4 C;																\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		" + ratio + " * (u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0]),		\n"
					"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);														\n"
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
					"	out vec4 C;																\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],						\n"
					"		" + ratio + " * (u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1]),		\n"
					"		in_X[2], in_X[3]);													\n"
					"		X = vec2(in_X);														\n"
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
				"	out vec4 C;											\n"
				"	uniform vec4 u_X;									\n"
				"	void main() { gl_Position = vec4(					\n"
				"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],	\n"
				"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1],	\n"
				"		in_X[2], in_X[3]);								\n"
				"		X = vec2(in_X);									\n"
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
					"	out vec4 C;																							\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		" + ratio + " * (u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3]))),	\n"
					"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])), in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);																					\n"
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
					"	out vec4 C;																							\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),						\n"
					"		" + ratio + " * (u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3]))),	\n"
					"		in_X[2], in_X[3]);																				\n"
					"		X = vec2(in_X);																					\n"
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
				"	out vec4 C;																		\n"
				"	uniform vec4 u_X0;																\n"
				"	uniform vec4 u_X1;																\n"
				"	void main() { gl_Position  = vec4(												\n"
				"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),	\n"
				"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])),	\n"
				"		in_X[2], in_X[3]);															\n"
				"		X = vec2(in_X);																\n"
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
					"	out vec2 UV;										\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (in_X[0] + u_X[0]),				\n"
					"		in_X[1] + u_X[1], in_X[2], in_X[3]);			\n"
					"		X = vec2(in_X);									\n"
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
					"	out vec2 UV;										\n"
					"	uniform vec2 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		in_X[0] + u_X[0],								\n"
					"		" + ratio + " * (in_X[1] + u_X[1]),				\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
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
				"	out vec2 UV;							\n"
				"	uniform vec2 u_X;						\n"
				"	void main() { gl_Position = vec4(		\n"
				"		in_X[0] + u_X[0],					\n"
				"		in_X[1] + u_X[1],					\n"
				"		in_X[2], in_X[3]);					\n"
				"		X = vec2(in_X);						\n"
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
					"	out vec2 UV;										\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		" + ratio + " * (u_X[2] * in_X[0] + u_X[0]),	\n"
					"		u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);									\n"
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
					"	out vec2 UV;										\n"
					"	uniform vec3 u_X;									\n"
					"	void main() { gl_Position = vec4(					\n"
					"		u_X[2] * in_X[0] + u_X[0],						\n"
					"		" + ratio + " * (u_X[2] * in_X[1] + u_X[1]),	\n"
					"		in_X[2], in_X[3]);								\n"
					"		X = vec2(in_X);									\n"
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
				"	out vec2 UV;										\n"
				"	uniform vec3 u_X;									\n"
				"	void main() { gl_Position = vec4(					\n"
				"		u_X[2] * in_X[0] + u_X[0],						\n"
				"		u_X[2] * in_X[1] + u_X[1],						\n"
				"		in_X[2], in_X[3]);								\n"
				"		X = vec2(in_X);									\n"
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
					"	out vec2 UV;															\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		" + ratio + " * (u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0]),		\n"
					"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1], in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);														\n"
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
					"	out vec2 UV;															\n"
					"	uniform vec4 u_X;														\n"
					"	void main() { gl_Position = vec4(										\n"
					"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],						\n"
					"		" + ratio + " * (u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1]),		\n"
					"		in_X[2], in_X[3]);													\n"
					"		X = vec2(in_X);														\n"
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
				"	out vec2 UV;										\n"
				"	uniform vec4 u_X;									\n"
				"	void main() { gl_Position = vec4(					\n"
				"		u_X[2] * in_X[0] - u_X[3] * in_X[1] + u_X[0],	\n"
				"		u_X[3] * in_X[0] + u_X[2] * in_X[1] + u_X[1],	\n"
				"		in_X[2], in_X[3]);								\n"
				"		X = vec2(in_X);									\n"
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
					"	out vec2 UV;																						\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		" + ratio + " * (u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3]))),	\n"
					"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])), in_X[2], in_X[3]);	\n"
					"		X = vec2(in_X);																					\n"
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
					"	out vec2 UV;																						\n"
					"	uniform vec4 u_X0;																					\n"
					"	uniform vec4 u_X1;																					\n"
					"	void main() { gl_Position  = vec4(																	\n"
					"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),						\n"
					"		" + ratio + " * (u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3]))),	\n"
					"		in_X[2], in_X[3]);																				\n"
					"		X = vec2(in_X);																					\n"
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
				"	out vec2 UV;																	\n"
				"	uniform vec4 u_X0;																\n"
				"	uniform vec4 u_X1;																\n"
				"	void main() { gl_Position  = vec4(												\n"
				"		u_X0[0] + (u_X1[0] * (in_X[0] - u_X0[2]) + u_X1[2] * (in_X[1] - u_X0[3])),	\n"
				"		u_X0[1] + (u_X1[1] * (in_X[0] - u_X0[2]) + u_X1[3] * (in_X[1] - u_X0[3])),	\n"
				"		in_X[2], in_X[3]);															\n"
				"		X = vec2(in_X);																\n"
				"		UV = in_UV; }																\n"
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
			"	out vec2 UV;									\n"
			"	out vec3 X;										\n"
			"	out vec3 N;										\n"
			"	uniform mat4 u_mvp_M;							\n"
			"	void main() {									\n"
			"		gl_Position = u_mvp_M * vec4(in_X, 1);		\n"
			"		UV = in_UV;									\n"
			"		X = in_X;									\n"
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
			"		float face = 0.5 - 0.5 * dot(view_dir, N);										\n"
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
			"		float face = 0.5 - 0.5 * dot(view_dir, N);										\n"
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
			"		float face = 0.5 - 0.5 * dot(view_dir, N);										\n"
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
			"		float face = 0.5 - 0.5 * dot(view_dir, N);										\n"
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

	std::string source_fragment_color_pointlights_3d(int _number_of_pointlights)
	{
		std::string number_of_pointlights = std::to_string(_number_of_pointlights);

		return
			"	#version 330 core																		\n"
			"	in vec3 X;																				\n"
			"	in vec3 N;																				\n"
			"	out vec4 color;																			\n"
			"	uniform float u_diff;																	\n"
			"	uniform float u_spec;																	\n"
			"	uniform float u_conc;																	\n"
			"	uniform vec3 u_view_pos;																\n"
			"	uniform vec3 u_amb;																		\n"

			"	uniform vec3 u_plight_pos[" + number_of_pointlights + "];								\n"
			"	uniform vec4 u_plight_C[" + number_of_pointlights + "];									\n"
			"	uniform vec3 u_plight_att[" + number_of_pointlights + "];								\n"
			"	uniform int first_light;																\n"
			"	uniform int end_light;																	\n"

			"	uniform mat4 u_m_M;																		\n"
			"	uniform vec4 u_C;																		\n"

			"	void main()																				\n"
			"	{																						\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 													\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 											\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, N);											\n"

			"		vec3 color3 = vec3(0.0, 0.0, 0.0);													\n"

			"		for (int k = first_light; k < end_light; k++)										\n"
			"		{																					\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);								\n"
			"			float light_dist = length(X - u_plight_pos[k]);									\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist								\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));					\n"
			"			float dot_diff = dot(rotated_N, light_dir);										\n"

			"			float diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);		\n"
			"			float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);		\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * vec3(u_C));			\n"
			"		}																					\n"
			"		color = max(vec4(color3, u_C[3]), face * vec4(u_amb, 0.0));							\n"
			"	}																						\n"
			;
	}
	std::string source_fragment_RGB_pointlights_3d(int _number_of_pointlights)
	{
		std::string number_of_pointlights = std::to_string(_number_of_pointlights);

		return
			"	#version 330 core																		\n"
			"	in vec3 X;																				\n"
			"	in vec3 C;																				\n"
			"	in vec3 N;																				\n"
			"	out vec4 color;																			\n"
			"	uniform float u_diff;																	\n"
			"	uniform float u_spec;																	\n"
			"	uniform float u_conc;																	\n"
			"	uniform vec3 u_view_pos;																\n"
			"	uniform vec3 u_amb;																		\n"

			"	uniform vec3 u_plight_pos[" + number_of_pointlights + "];								\n"
			"	uniform vec4 u_plight_C[" + number_of_pointlights + "];									\n"
			"	uniform vec3 u_plight_att[" + number_of_pointlights + "];								\n"
			"	uniform int first_light;																\n"
			"	uniform int end_light;																	\n"

			"	uniform mat4 u_m_M;																		\n"

			"	void main()																				\n"
			"	{																						\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 													\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 											\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, N);											\n"

			"		vec3 color3 = vec3(0.0, 0.0, 0.0);													\n"

			"		for (int k = first_light; k < end_light; k++)										\n"
			"		{																					\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);								\n"
			"			float light_dist = length(X - u_plight_pos[k]);									\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist								\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));					\n"
			"			float dot_diff = dot(rotated_N, light_dir);										\n"

			"			float diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);		\n"
			"			float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);		\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * C);					\n"
			"		}																					\n"
			"		color = max(vec4(color3, 1.0), face * vec4(u_amb, 0.0));							\n"
			"	}																						\n"
			;
	}
	std::string source_fragment_RGBA_pointlights_3d(int _number_of_pointlights)
	{
		std::string number_of_pointlights = std::to_string(_number_of_pointlights);

		return
			"	#version 330 core																		\n"
			"	in vec3 X;																				\n"
			"	in vec4 C;																				\n"
			"	in vec3 N;																				\n"
			"	out vec4 color;																			\n"
			"	uniform float u_diff;																	\n"
			"	uniform float u_spec;																	\n"
			"	uniform float u_conc;																	\n"
			"	uniform vec3 u_view_pos;																\n"
			"	uniform vec3 u_amb;																		\n"

			"	uniform vec3 u_plight_pos[" + number_of_pointlights + "];								\n"
			"	uniform vec4 u_plight_C[" + number_of_pointlights + "];									\n"
			"	uniform vec3 u_plight_att[" + number_of_pointlights + "];								\n"
			"	uniform int first_light;																\n"
			"	uniform int end_light;																	\n"

			"	uniform mat4 u_m_M;																		\n"

			"	void main()																				\n"
			"	{																						\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 													\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 											\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, N);											\n"
			"		vec3 C3 = vec3(C);																	\n"

			"		vec3 color3 = vec3(0.0, 0.0, 0.0);													\n"

			"		for (int k = first_light; k < end_light; k++)										\n"
			"		{																					\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);								\n"
			"			float light_dist = length(X - u_plight_pos[k]);									\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist								\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));					\n"
			"			float dot_diff = dot(rotated_N, light_dir);										\n"

			"			float diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);		\n"
			"			float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);		\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * C3);					\n"
			"		}																					\n"
			"		color = max(vec4(color3, C[3]), face * vec4(u_amb, 0.0));							\n"
			"	}																						\n"
			;
	}
	std::string source_fragment_texture_pointlights_3d(int _number_of_pointlights)
	{
		std::string number_of_pointlights = std::to_string(_number_of_pointlights);

		return
			"	#version 330 core																		\n"
			"	in vec3 X;																				\n"
			"	in vec2 UV;																				\n"
			"	in vec3 N;																				\n"
			"	out vec4 color;																			\n"
			"	uniform float u_diff;																	\n"
			"	uniform float u_spec;																	\n"
			"	uniform float u_conc;																	\n"
			"	uniform vec3 u_view_pos;																\n"
			"	uniform vec3 u_amb;																		\n"

			"	uniform vec3 u_plight_pos[" + number_of_pointlights + "];								\n"
			"	uniform vec4 u_plight_C[" + number_of_pointlights + "];									\n"
			"	uniform vec3 u_plight_att[" + number_of_pointlights + "];								\n"
			"	uniform int first_light;																\n"
			"	uniform int end_light;																	\n"

			"	uniform mat4 u_m_M;																		\n"
			"	uniform sampler2D Tx;																	\n"

			"	void main()																				\n"
			"	{																						\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 													\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 											\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, N);											\n"
			"		vec4 in_C = texture(Tx, UV);														\n"
			"		vec3 in_C3 = vec3(in_C);															\n"

			"		vec3 color3 = vec3(0.0, 0.0, 0.0);													\n"

			"		for (int k = first_light; k < end_light; k++)										\n"
			"		{																					\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);								\n"
			"			float light_dist = length(X - u_plight_pos[k]);									\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist								\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));					\n"
			"			float dot_diff = dot(rotated_N, light_dir);										\n"

			"			float diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);		\n"
			"			float spec = max(sign(-dot_diff), 0.0) * u_spec									\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);		\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * in_C3);				\n"
			"		}																					\n"
			"		color = max(vec4(color3, in_C[3]), face * vec4(u_amb, 0.0));						\n"
			"	}																						\n"
			;
	}

	std::string source_fragment_color_combolights_3d(int _number_of_pointlights)
	{
		std::string number_of_pointlights = std::to_string(_number_of_pointlights);

		return
			"	#version 330 core																		\n"
			"	in vec3 X;																				\n"
			"	in vec3 N;																				\n"
			"	out vec4 color;																			\n"
			"	uniform float u_diff;																	\n"
			"	uniform float u_spec;																	\n"
			"	uniform float u_conc;																	\n"
			"	uniform vec3 u_view_pos;																\n"
			"	uniform vec3 u_amb;																		\n"

			"	uniform vec3 u_slight_dir;																\n"
			"	uniform vec3 u_slight_C;																\n"

			"	uniform vec3 u_plight_pos[" + number_of_pointlights + "];								\n"
			"	uniform vec4 u_plight_C[" + number_of_pointlights + "];									\n"
			"	uniform vec3 u_plight_att[" + number_of_pointlights + "];								\n"
			"	uniform int first_light;																\n"
			"	uniform int end_light;																	\n"

			"	uniform mat4 u_m_M;																		\n"
			"	uniform vec4 u_C;																		\n"

			"	void main()																				\n"
			"	{																						\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 													\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 											\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, N);											\n"

			"		float dot_diff = dot(rotated_N, u_slight_dir);										\n"
			"		float diff = u_diff * max(-dot_diff, 0.0);											\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec										\n"
			"			* pow(max(dot(normalize(u_view_pos - X),										\n"
			"			reflect(u_slight_dir, rotated_N)), 0.0), u_conc);								\n"
			"		vec3 color3 = (diff + spec) * (u_slight_C * vec3(u_C));								\n"

			"		for (int k = first_light; k < end_light; k++)										\n"
			"		{																					\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);								\n"
			"			float light_dist = length(X - u_plight_pos[k]);									\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist								\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));					\n"
			"			dot_diff = dot(rotated_N, light_dir);											\n"

			"			diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);				\n"
			"			spec = max(sign(-dot_diff), 0.0) * u_spec										\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);		\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * vec3(u_C));			\n"
			"		}																					\n"
			"		color = max(vec4(color3, u_C[3]), face * vec4(u_amb, 0.0));							\n"
			"	}																						\n"
			;
	}
	std::string source_fragment_RGB_combolights_3d(int _number_of_pointlights)
	{
		std::string number_of_pointlights = std::to_string(_number_of_pointlights);

		return
			"	#version 330 core																		\n"
			"	in vec3 X;																				\n"
			"	in vec3 C;																				\n"
			"	in vec3 N;																				\n"
			"	out vec4 color;																			\n"
			"	uniform float u_diff;																	\n"
			"	uniform float u_spec;																	\n"
			"	uniform float u_conc;																	\n"
			"	uniform vec3 u_view_pos;																\n"
			"	uniform vec3 u_amb;																		\n"

			"	uniform vec3 u_slight_dir;																\n"
			"	uniform vec3 u_slight_C;																\n"

			"	uniform vec3 u_plight_pos[" + number_of_pointlights + "];								\n"
			"	uniform vec4 u_plight_C[" + number_of_pointlights + "];									\n"
			"	uniform vec3 u_plight_att[" + number_of_pointlights + "];								\n"
			"	uniform int first_light;																\n"
			"	uniform int end_light;																	\n"

			"	uniform mat4 u_m_M;																		\n"

			"	void main()																				\n"
			"	{																						\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 													\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 											\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, N);											\n"

			"		float dot_diff = dot(rotated_N, u_slight_dir);										\n"
			"		float diff = u_diff * max(-dot_diff, 0.0);											\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec										\n"
			"			* pow(max(dot(normalize(u_view_pos - X),										\n"
			"			reflect(u_slight_dir, rotated_N)), 0.0), u_conc);								\n"
			"		vec3 color3 = (diff + spec) * (u_slight_C * C);										\n"

			"		for (int k = first_light; k < end_light; k++)										\n"
			"		{																					\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);								\n"
			"			float light_dist = length(X - u_plight_pos[k]);									\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist								\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));					\n"
			"			dot_diff = dot(rotated_N, light_dir);											\n"

			"			diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);				\n"
			"			spec = max(sign(-dot_diff), 0.0) * u_spec										\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);		\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * C);					\n"
			"		}																					\n"
			"		color = max(vec4(color3, 1.0), face * vec4(u_amb, 0.0));							\n"
			"	}																						\n"
			;
	}
	std::string source_fragment_RGBA_combolights_3d(int _number_of_pointlights)
	{
		std::string number_of_pointlights = std::to_string(_number_of_pointlights);

		return
			"	#version 330 core																		\n"
			"	in vec3 X;																				\n"
			"	in vec4 C;																				\n"
			"	in vec3 N;																				\n"
			"	out vec4 color;																			\n"
			"	uniform float u_diff;																	\n"
			"	uniform float u_spec;																	\n"
			"	uniform float u_conc;																	\n"
			"	uniform vec3 u_view_pos;																\n"
			"	uniform vec3 u_amb;																		\n"

			"	uniform vec3 u_slight_dir;																\n"
			"	uniform vec3 u_slight_C;																\n"

			"	uniform vec3 u_plight_pos[" + number_of_pointlights + "];								\n"
			"	uniform vec4 u_plight_C[" + number_of_pointlights + "];									\n"
			"	uniform vec3 u_plight_att[" + number_of_pointlights + "];								\n"
			"	uniform int first_light;																\n"
			"	uniform int end_light;																	\n"

			"	uniform mat4 u_m_M;																		\n"

			"	void main()																				\n"
			"	{																						\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 													\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 											\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, N);											\n"
			"		vec3 C3 = vec3(C);																	\n"

			"		float dot_diff = dot(rotated_N, u_slight_dir);										\n"
			"		float diff = u_diff * max(-dot_diff, 0.0);											\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec										\n"
			"			* pow(max(dot(normalize(u_view_pos - X),										\n"
			"			reflect(u_slight_dir, rotated_N)), 0.0), u_conc);								\n"
			"		vec3 color3 = (diff + spec) * (u_slight_C * C3);									\n"

			"		for (int k = first_light; k < end_light; k++)										\n"
			"		{																					\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);								\n"
			"			float light_dist = length(X - u_plight_pos[k]);									\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist								\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));					\n"
			"			dot_diff = dot(rotated_N, light_dir);											\n"

			"			diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);				\n"
			"			spec = max(sign(-dot_diff), 0.0) * u_spec										\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);		\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * C3);					\n"
			"		}																					\n"
			"		color = max(vec4(color3, C[3]), face * vec4(u_amb, 0.0));							\n"
			"	}																						\n"
			;
	}
	std::string source_fragment_texture_combolights_3d(int _number_of_pointlights)
	{
		std::string number_of_pointlights = std::to_string(_number_of_pointlights);

		return
			"	#version 330 core																		\n"
			"	in vec3 X;																				\n"
			"	in vec2 UV;																				\n"
			"	in vec3 N;																				\n"
			"	out vec4 color;																			\n"
			"	uniform float u_diff;																	\n"
			"	uniform float u_spec;																	\n"
			"	uniform float u_conc;																	\n"
			"	uniform vec3 u_view_pos;																\n"
			"	uniform vec3 u_amb;																		\n"

			"	uniform vec3 u_slight_dir;																\n"
			"	uniform vec3 u_slight_C;																\n"

			"	uniform vec3 u_plight_pos[" + number_of_pointlights + "];								\n"
			"	uniform vec4 u_plight_C[" + number_of_pointlights + "];									\n"
			"	uniform vec3 u_plight_att[" + number_of_pointlights + "];								\n"
			"	uniform int first_light;																\n"
			"	uniform int end_light;																	\n"

			"	uniform mat4 u_m_M;																		\n"
			"	uniform sampler2D Tx;																	\n"

			"	void main()																				\n"
			"	{																						\n"
			"		vec3 rotated_N = mat3(u_m_M) * N; 													\n"
			"		vec3 view_dir = normalize(X - u_view_pos); 											\n"
			"		float face = 0.5 - 0.5 * dot(view_dir, N);											\n"
			"		vec4 in_C = texture(Tx, UV);														\n"
			"		vec3 in_C3 = vec3(in_C);															\n"

			"		float dot_diff = dot(rotated_N, u_slight_dir);										\n"
			"		float diff = u_diff * max(-dot_diff, 0.0);											\n"
			"		float spec = max(sign(-dot_diff), 0.0) * u_spec										\n"
			"			* pow(max(dot(normalize(u_view_pos - X),										\n"
			"			reflect(u_slight_dir, rotated_N)), 0.0), u_conc);								\n"
			"		vec3 color3 = (diff + spec) * (u_slight_C * in_C3);									\n"

			"		for (int k = first_light; k < end_light; k++)										\n"
			"		{																					\n"
			"			vec3 light_dir = normalize(X - u_plight_pos[k]);								\n"
			"			float light_dist = length(X - u_plight_pos[k]);									\n"
			"			float att = u_plight_att[k][0] / (1.0 + light_dist								\n"
			"				* (u_plight_att[k][1] + light_dist * u_plight_att[k][2]));					\n"
			"			dot_diff = dot(rotated_N, light_dir);											\n"

			"			diff = max(u_diff * max(-dot_diff, 0.0), face * u_plight_C[k][3]);				\n"
			"			spec = max(sign(-dot_diff), 0.0) * u_spec										\n"
			"				* pow(max(-dot(view_dir, reflect(light_dir, rotated_N)), 0.0), u_conc);		\n"
			"			color3 += (att * (diff + spec)) * (vec3(u_plight_C[k]) * in_C3);				\n"
			"		}																					\n"
			"		color = max(vec4(color3, in_C[3]), face * vec4(u_amb, 0.0));						\n"
			"	}																						\n"
			;
	}


	inline const lnd::program& set_uniform_1f(const lnd::program& program, const char* const uniform_variable,
		float u0)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform1f(location, u0);
		return program;
	}
	inline const lnd::program& set_uniform_2f(const lnd::program& program, const char* const uniform_variable,
		float u0, float u1)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform2f(location, u0, u1);
		return program;
	}
	inline const lnd::program& set_uniform_3f(const lnd::program& program, const char* const uniform_variable,
		float u0, float u1, float u2)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform3f(location, u0, u1, u2);
		return program;
	}
	inline const lnd::program& set_uniform_4f(const lnd::program& program, const char* const uniform_variable,
		float u0, float u1, float u2, float u3)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform4f(location, u0, u1, u2, u3);
		return program;
	}

	inline const lnd::program& set_uniform_2fv(const lnd::program& program, const char* const uniform_variable,
		const float* const values_ptr)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform2fv(location, 1, values_ptr);
		return program;
	}
	inline const lnd::program& set_uniform_3fv(const lnd::program& program, const char* const uniform_variable,
		const float* const values_ptr)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform3fv(location, 1, values_ptr);
		return program;
	}
	inline const lnd::program& set_uniform_4fv(const lnd::program& program, const char* const uniform_variable,
		const float* const values_ptr)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform4fv(location, 1, values_ptr);
		return program;
	}

	inline const lnd::program& set_uniform_1i(const lnd::program& program, const char* const uniform_variable,
		int u0)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform1i(location, u0);
		return program;
	}
	inline const lnd::program& set_uniform_2i(const lnd::program& program, const char* const uniform_variable,
		int u0, int u1)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform2i(location, u0, u1);
		return program;
	}
	inline const lnd::program& set_uniform_3i(const lnd::program& program, const char* const uniform_variable,
		int u0, int u1, int u2)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform3i(location, u0, u1, u2);
		return program;
	}
	inline const lnd::program& set_uniform_4i(const lnd::program& program, const char* const uniform_variable,
		int u0, int u1, int u2, int u3)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform4i(location, u0, u1, u2, u3);
		return program;
	}
	inline const lnd::program& set_uniform_1ui(const lnd::program& program, const char* const uniform_variable,
		unsigned int u0)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform1ui(location, u0);
		return program;
	}
	inline const lnd::program& set_uniform_2ui(const lnd::program& program, const char* const uniform_variable,
		unsigned int u0, unsigned int u1)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform2ui(location, u0, u1);
		return program;
	}
	inline const lnd::program& set_uniform_3ui(const lnd::program& program, const char* const uniform_variable,
		unsigned int u0, unsigned int u1, unsigned int u2)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform3ui(location, u0, u1, u2);
		return program;
	}
	inline const lnd::program& set_uniform_4ui(const lnd::program& program, const char* const uniform_variable,
		unsigned int u0, unsigned int u1, unsigned int u2, unsigned int u3)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), uniform_variable);
		glUniform4ui(location, u0, u1, u2, u3);
		return program;
	}

	inline const lnd::program& set_fragment_color(const lnd::program& program, float c0, float c1, float c2, float c3)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_C");
		glUniform4f(location, c0, c1, c2, c3);
		return program;
	}
	inline const lnd::program& set_fragment_color(const lnd::program& program, const float* const color_ptr)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_C");
		glUniform4fv(location, 1, color_ptr);
		return program;
	}
	inline const lnd::program& set_vertex_shift(const lnd::program& program, float T0, float T1)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_X");
		glUniform2f(location, T0, T1);
		return program;
	}
	inline const lnd::program& set_vertex_shift_scale(const lnd::program& program, float T0, float T1, float scale)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_X");
		glUniform3f(location, T0, T1, scale);
		return program;
	}
	inline const lnd::program& set_vertex_shift_rotate_rad(const lnd::program& program, float T0, float T1, float angle)
	{
		float C = LND_COS(angle);
		float S = LND_SIN(angle);
		program.use();
		int location = glGetUniformLocation(program.get(), "u_X");
		glUniform4f(location, T0, T1, C, S);
		return program;
	}
	inline const lnd::program& set_vertex_shift_rotate_deg(const lnd::program& program, float T0, float T1, float angle)
	{
		constexpr float deg_to_float = 3.14159265358979323846f / 180.0f;
		angle *= deg_to_float;
		float C = LND_COS(angle);
		float S = LND_SIN(angle);
		program.use();
		int location = glGetUniformLocation(program.get(), "u_X");
		glUniform4f(location, T0, T1, C, S);
		return program;
	}
	inline const lnd::program& set_vertex_affine(const lnd::program& program, float T0, float T1, float orig0, float orig1,
		float A00, float A10, float A01, float A11)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_X0");
		glUniform4f(location, T0, T1, orig0, orig1);
		location = glGetUniformLocation(program.get(), "u_X1");
		glUniform4f(location, A00, A10, A01, A11);
		return program;
	}

	inline const lnd::program& set_mvp_matrix_3d(const lnd::program& program, const float* const mvp_matrix_ptr)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_mvp_M");
		glUniformMatrix4fv(location, 1, GL_FALSE, mvp_matrix_ptr);
		return program;
	}
	inline const lnd::program& set_m_matrix_3d(const lnd::program& program, const float* const m_matrix_ptr)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_m_M");
		glUniformMatrix4fv(location, 1, GL_FALSE, m_matrix_ptr);
		return program;
	}
	inline const lnd::program& set_position_3d(const lnd::program& program, const float* const position_ptr)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_view_pos");
		glUniform3fv(location, 1, position_ptr);
		return program;
	}
	inline const lnd::program& set_mvp_position_3d(const lnd::program& program, const float* const mvp_matrix_ptr,
		const float* const position_ptr)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_mvp_M");
		glUniformMatrix4fv(location, 1, GL_FALSE, mvp_matrix_ptr);
		location = glGetUniformLocation(program.get(), "u_view_pos");
		glUniform3fv(location, 1, position_ptr);
		return program;
	}
	inline const lnd::program& set_mvp_m_position_3d(const lnd::program& program, const float* const mvp_matrix_ptr,
		const float* const m_matrix_ptr, const float* const position_ptr)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_mvp_M");
		glUniformMatrix4fv(location, 1, GL_FALSE, mvp_matrix_ptr);
		location = glGetUniformLocation(program.get(), "u_m_M");
		glUniformMatrix4fv(location, 1, GL_FALSE, m_matrix_ptr);
		location = glGetUniformLocation(program.get(), "u_view_pos");
		glUniform3fv(location, 1, position_ptr);
		return program;
	}
	inline const lnd::program& set_ambient_light_3d(const lnd::program& program, const float* const ambient_light_ptr)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_amb");
		glUniform3fv(location, 1, ambient_light_ptr);
		return program;
	}
	inline const lnd::program& set_skylight_3d(const lnd::program& program, const float* const light_direction_ptr,
		const float* const light_color_ptr)
	{
		float factor = 1.0f / LND_SQRT(light_direction_ptr[0] * light_direction_ptr[0]
			+ light_direction_ptr[1] * light_direction_ptr[1]
			+ light_direction_ptr[2] * light_direction_ptr[2]);
		float light_direction_normalized[3] = {
			factor * light_direction_ptr[0],
			factor * light_direction_ptr[1],
			factor * light_direction_ptr[2]
		};
		program.use();
		int location = glGetUniformLocation(program.get(), "u_slight_dir");
		glUniform3fv(location, 1, static_cast<float*>(light_direction_normalized));
		location = glGetUniformLocation(program.get(), "u_slight_C");
		glUniform3fv(location, 1, light_color_ptr);
		return program;
	}
	inline const lnd::program& set_material_3d(const lnd::program& program, float diff_coeff, float spec_coeff, float concentration_coeff)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "u_diff");
		glUniform1f(location, diff_coeff);
		location = glGetUniformLocation(program.get(), "u_spec");
		glUniform1f(location, spec_coeff);
		location = glGetUniformLocation(program.get(), "u_conc");
		glUniform1f(location, concentration_coeff);
		return program;
	}
	inline const lnd::program& set_pointlight_pos_3d(lnd::program& program, unsigned int light_number, const float* const light_position_ptr)
	{
		std::string light_number_str = std::to_string(light_number);
		program.use();
		int location = glGetUniformLocation(program.get(), ("u_plight_pos[" + light_number_str + "]").c_str());
		glUniform3fv(location, 1, light_position_ptr);
		return program;
	}
	inline const lnd::program& set_pointlight_prop_3d(lnd::program& program, int light_number, const float* const light_color_ptr,
		const float* const light_attenuation_ptr)
	{
		std::string light_number_str = std::to_string(light_number);
		program.use();
		if ((light_color_ptr != nullptr) && (light_attenuation_ptr != nullptr))
		{
			int location = glGetUniformLocation(program.get(), ("u_plight_C[" + light_number_str + "]").c_str());
			glUniform4fv(location, 1, light_color_ptr);
			location = glGetUniformLocation(program.get(), ("u_plight_att[" + light_number_str + "]").c_str());
			glUniform3fv(location, 1, light_attenuation_ptr);
		}
		else
		{
			float null_array[4] = { 0.0f };
			int location = glGetUniformLocation(program.get(), ("u_plight_C[" + light_number_str + "]").c_str());
			glUniform4fv(location, 1, static_cast<float*>(null_array));
		}
		return program;
	}
	inline const lnd::program& set_pointlights_range_3d(lnd::program& program, int first_light, int end_light)
	{
		program.use();
		int location = glGetUniformLocation(program.get(), "first_light");
		glUniform1i(location, first_light);
		location = glGetUniformLocation(program.get(), "end_light");
		glUniform1i(location, end_light);
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
		lnd::__clear_window = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
	}
	inline void disable_3d()
	{
		glDisable(GL_DEPTH_TEST);
		lnd::__clear_window = GL_COLOR_BUFFER_BIT;
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
			display_condition_var.notify_one();
		}
		inline void clear_window()
		{
			glClear(lnd::__clear_window);
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
			return lnd::__window_ptr;
		}

		// INPUTS

		inline float mouse_X() const noexcept { return lnd::__user_mouse_input.mouse_X; }
		inline float mouse_Y() const noexcept { return lnd::__user_mouse_input.mouse_Y; }
		inline bool mouse_in_box(float X_min, float Y_min, float X_max, float Y_max) const noexcept
		{
			return (((X_min < lnd::__user_mouse_input.mouse_X) && (lnd::__user_mouse_input.mouse_X < X_max))
				&& ((Y_min < lnd::__user_mouse_input.mouse_Y) && (lnd::__user_mouse_input.mouse_Y < Y_max)));
		}
		inline bool mouse_in_tri(float X0, float Y0, float X1, float Y1, float X2, float Y2) const noexcept
		{
			float s = Y0 * X2 - X0 * Y2 + (Y2 - Y0) * lnd::__user_mouse_input.mouse_X
				+ (X0 - X2) * lnd::__user_mouse_input.mouse_Y;
			float t = X0 * Y1 - Y0 * X1 + (Y0 - Y1) * lnd::__user_mouse_input.mouse_X
				+ (X1 - X0) * lnd::__user_mouse_input.mouse_Y;

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
				+ (*(tri_ptr + 5) - *(tri_ptr + 1)) * lnd::__user_mouse_input.mouse_X
				+ (*tri_ptr - *(tri_ptr + 4)) * lnd::__user_mouse_input.mouse_Y;
			float t = *tri_ptr * *(tri_ptr + 3) - *(tri_ptr + 1) * *(tri_ptr + 2)
				+ (*(tri_ptr + 1) - *(tri_ptr + 3)) * lnd::__user_mouse_input.mouse_X
				+ (*(tri_ptr + 2) - *tri_ptr) * lnd::__user_mouse_input.mouse_Y;

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
			float dx = lnd::__user_mouse_input.mouse_X - X_orig;
			float dy = lnd::__user_mouse_input.mouse_Y - Y_orig;
			return (dx * dx + dy * dy < radius* radius);
		}


		inline bool mouse_1() const noexcept { return glfwGetMouseButton(lnd::__window_ptr, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS; }
		inline bool mouse_2() const noexcept { return glfwGetMouseButton(lnd::__window_ptr, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS; }
		inline bool mouse_3() const noexcept { return glfwGetMouseButton(lnd::__window_ptr, GLFW_MOUSE_BUTTON_3) == GLFW_PRESS; }
		inline bool mouse_4() const noexcept { return glfwGetMouseButton(lnd::__window_ptr, GLFW_MOUSE_BUTTON_4) == GLFW_PRESS; }
		inline bool mouse_5() const noexcept { return glfwGetMouseButton(lnd::__window_ptr, GLFW_MOUSE_BUTTON_5) == GLFW_PRESS; }
		inline bool mouse_6() const noexcept { return glfwGetMouseButton(lnd::__window_ptr, GLFW_MOUSE_BUTTON_6) == GLFW_PRESS; }
		inline bool mouse_7() const noexcept { return glfwGetMouseButton(lnd::__window_ptr, GLFW_MOUSE_BUTTON_7) == GLFW_PRESS; }
		inline bool mouse_8() const noexcept { return glfwGetMouseButton(lnd::__window_ptr, GLFW_MOUSE_BUTTON_8) == GLFW_PRESS; }

		inline bool key_space() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_SPACE) == GLFW_PRESS; }
		inline bool key_apostrophe() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_APOSTROPHE) == GLFW_PRESS; }
		inline bool key_comma() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_COMMA) == GLFW_PRESS; }
		inline bool key_minus() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_MINUS) == GLFW_PRESS; }
		inline bool key_period() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_PERIOD) == GLFW_PRESS; }
		inline bool key_slash() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_SLASH) == GLFW_PRESS; }

		inline bool key_A() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_A) == GLFW_PRESS; }
		inline bool key_B() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_B) == GLFW_PRESS; }
		inline bool key_C() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_C) == GLFW_PRESS; }
		inline bool key_D() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_D) == GLFW_PRESS; }
		inline bool key_E() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_E) == GLFW_PRESS; }
		inline bool key_F() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F) == GLFW_PRESS; }
		inline bool key_G() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_G) == GLFW_PRESS; }
		inline bool key_H() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_H) == GLFW_PRESS; }
		inline bool key_I() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_I) == GLFW_PRESS; }
		inline bool key_J() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_J) == GLFW_PRESS; }
		inline bool key_K() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_K) == GLFW_PRESS; }
		inline bool key_L() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_L) == GLFW_PRESS; }
		inline bool key_M() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_M) == GLFW_PRESS; }
		inline bool key_N() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_N) == GLFW_PRESS; }
		inline bool key_O() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_O) == GLFW_PRESS; }
		inline bool key_P() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_P) == GLFW_PRESS; }
		inline bool key_Q() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_Q) == GLFW_PRESS; }
		inline bool key_R() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_R) == GLFW_PRESS; }
		inline bool key_S() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_S) == GLFW_PRESS; }
		inline bool key_T() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_T) == GLFW_PRESS; }
		inline bool key_U() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_U) == GLFW_PRESS; }
		inline bool key_V() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_V) == GLFW_PRESS; }
		inline bool key_W() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_W) == GLFW_PRESS; }
		inline bool key_X() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_X) == GLFW_PRESS; }
		inline bool key_Y() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_Y) == GLFW_PRESS; }
		inline bool key_Z() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_Z) == GLFW_PRESS; }

		inline bool key_0() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_0) == GLFW_PRESS; }
		inline bool key_1() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_1) == GLFW_PRESS; }
		inline bool key_2() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_2) == GLFW_PRESS; }
		inline bool key_3() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_3) == GLFW_PRESS; }
		inline bool key_4() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_4) == GLFW_PRESS; }
		inline bool key_5() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_5) == GLFW_PRESS; }
		inline bool key_6() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_6) == GLFW_PRESS; }
		inline bool key_7() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_7) == GLFW_PRESS; }
		inline bool key_8() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_8) == GLFW_PRESS; }
		inline bool key_9() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_9) == GLFW_PRESS; }

		inline bool key_pad0() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_0) == GLFW_PRESS; }
		inline bool key_pad1() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_1) == GLFW_PRESS; }
		inline bool key_pad2() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_2) == GLFW_PRESS; }
		inline bool key_pad3() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_3) == GLFW_PRESS; }
		inline bool key_pad4() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_4) == GLFW_PRESS; }
		inline bool key_pad5() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_5) == GLFW_PRESS; }
		inline bool key_pad6() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_6) == GLFW_PRESS; }
		inline bool key_pad7() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_7) == GLFW_PRESS; }
		inline bool key_pad8() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_8) == GLFW_PRESS; }
		inline bool key_pad9() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_9) == GLFW_PRESS; }

		inline bool key_add() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_ADD) == GLFW_PRESS; }
		inline bool key_sub() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS; }
		inline bool key_mul() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_MULTIPLY) == GLFW_PRESS; }
		inline bool key_div() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_DIVIDE) == GLFW_PRESS; }

		inline bool key_F1() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F1) == GLFW_PRESS; }
		inline bool key_F2() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F2) == GLFW_PRESS; }
		inline bool key_F3() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F3) == GLFW_PRESS; }
		inline bool key_F4() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F4) == GLFW_PRESS; }
		inline bool key_F5() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F5) == GLFW_PRESS; }
		inline bool key_F6() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F6) == GLFW_PRESS; }
		inline bool key_F7() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F7) == GLFW_PRESS; }
		inline bool key_F8() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F8) == GLFW_PRESS; }
		inline bool key_F9() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F9) == GLFW_PRESS; }
		inline bool key_F10() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F10) == GLFW_PRESS; }
		inline bool key_F11() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F11) == GLFW_PRESS; }
		inline bool key_F12() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_F12) == GLFW_PRESS; }

		inline bool key_escape() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_ESCAPE) == GLFW_PRESS; }
		inline bool key_enter() const noexcept {
			return (glfwGetKey(lnd::__window_ptr, GLFW_KEY_ENTER) == GLFW_PRESS)
				|| (glfwGetKey(lnd::__window_ptr, GLFW_KEY_KP_ENTER) == GLFW_PRESS);
		}
		inline bool key_tab() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_TAB) == GLFW_PRESS; }
		inline bool key_backspace() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_BACKSPACE) == GLFW_PRESS; }
		inline bool key_insert() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_INSERT) == GLFW_PRESS; }
		inline bool key_delete() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_DELETE) == GLFW_PRESS; }
		inline bool key_right() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_RIGHT) == GLFW_PRESS; }
		inline bool key_left() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_LEFT) == GLFW_PRESS; }
		inline bool key_down() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_DOWN) == GLFW_PRESS; }
		inline bool key_up() const noexcept { return glfwGetKey(lnd::__window_ptr, GLFW_KEY_UP) == GLFW_PRESS; }
		inline bool key_alt() const noexcept {
			return (glfwGetKey(lnd::__window_ptr, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
				|| (glfwGetKey(lnd::__window_ptr, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS);
		}
		inline bool key_shift() const noexcept {
			return (glfwGetKey(lnd::__window_ptr, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
				|| (glfwGetKey(lnd::__window_ptr, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS);
		}
		inline bool key_ctrl() const noexcept {
			return (glfwGetKey(lnd::__window_ptr, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
				|| (glfwGetKey(lnd::__window_ptr, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS);
		}


		inline bool mouse_1_press() const noexcept { return lnd::__user_key_input.mouse_1_press.load(); }
		inline bool mouse_2_press() const noexcept { return lnd::__user_key_input.mouse_2_press.load(); }
		inline bool mouse_3_press() const noexcept { return lnd::__user_key_input.mouse_3_press.load(); }
		inline bool mouse_4_press() const noexcept { return lnd::__user_key_input.mouse_4_press.load(); }
		inline bool mouse_5_press() const noexcept { return lnd::__user_key_input.mouse_5_press.load(); }
		inline bool mouse_6_press() const noexcept { return lnd::__user_key_input.mouse_6_press.load(); }
		inline bool mouse_7_press() const noexcept { return lnd::__user_key_input.mouse_7_press.load(); }
		inline bool mouse_8_press() const noexcept { return lnd::__user_key_input.mouse_8_press.load(); }

		inline bool key_space_press() const noexcept { return lnd::__user_key_input.space_press.load(); }
		inline bool key_apostrophe_press() const noexcept { return lnd::__user_key_input.apostrophe_press.load(); }
		inline bool key_comma_press() const noexcept { return lnd::__user_key_input.comma_press.load(); }
		inline bool key_minus_press() const noexcept { return lnd::__user_key_input.minus_press.load(); }
		inline bool key_period_press() const noexcept { return lnd::__user_key_input.period_press.load(); }
		inline bool key_slash_press() const noexcept { return lnd::__user_key_input.slash_press.load(); }

		inline bool key_A_press() const noexcept { return lnd::__user_key_input.A_press.load(); }
		inline bool key_B_press() const noexcept { return lnd::__user_key_input.B_press.load(); }
		inline bool key_C_press() const noexcept { return lnd::__user_key_input.C_press.load(); }
		inline bool key_D_press() const noexcept { return lnd::__user_key_input.D_press.load(); }
		inline bool key_E_press() const noexcept { return lnd::__user_key_input.E_press.load(); }
		inline bool key_F_press() const noexcept { return lnd::__user_key_input.F_press.load(); }
		inline bool key_G_press() const noexcept { return lnd::__user_key_input.G_press.load(); }
		inline bool key_H_press() const noexcept { return lnd::__user_key_input.H_press.load(); }
		inline bool key_I_press() const noexcept { return lnd::__user_key_input.I_press.load(); }
		inline bool key_J_press() const noexcept { return lnd::__user_key_input.J_press.load(); }
		inline bool key_K_press() const noexcept { return lnd::__user_key_input.K_press.load(); }
		inline bool key_L_press() const noexcept { return lnd::__user_key_input.L_press.load(); }
		inline bool key_M_press() const noexcept { return lnd::__user_key_input.M_press.load(); }
		inline bool key_N_press() const noexcept { return lnd::__user_key_input.N_press.load(); }
		inline bool key_O_press() const noexcept { return lnd::__user_key_input.O_press.load(); }
		inline bool key_P_press() const noexcept { return lnd::__user_key_input.P_press.load(); }
		inline bool key_Q_press() const noexcept { return lnd::__user_key_input.Q_press.load(); }
		inline bool key_R_press() const noexcept { return lnd::__user_key_input.R_press.load(); }
		inline bool key_S_press() const noexcept { return lnd::__user_key_input.S_press.load(); }
		inline bool key_T_press() const noexcept { return lnd::__user_key_input.T_press.load(); }
		inline bool key_U_press() const noexcept { return lnd::__user_key_input.U_press.load(); }
		inline bool key_V_press() const noexcept { return lnd::__user_key_input.V_press.load(); }
		inline bool key_W_press() const noexcept { return lnd::__user_key_input.W_press.load(); }
		inline bool key_X_press() const noexcept { return lnd::__user_key_input.X_press.load(); }
		inline bool key_Y_press() const noexcept { return lnd::__user_key_input.Y_press.load(); }
		inline bool key_Z_press() const noexcept { return lnd::__user_key_input.Z_press.load(); }

		inline bool key_0_press() const noexcept { return __user_key_input.num0_press.load(); }
		inline bool key_1_press() const noexcept { return __user_key_input.num1_press.load(); }
		inline bool key_2_press() const noexcept { return __user_key_input.num2_press.load(); }
		inline bool key_3_press() const noexcept { return __user_key_input.num3_press.load(); }
		inline bool key_4_press() const noexcept { return __user_key_input.num4_press.load(); }
		inline bool key_5_press() const noexcept { return __user_key_input.num5_press.load(); }
		inline bool key_6_press() const noexcept { return __user_key_input.num6_press.load(); }
		inline bool key_7_press() const noexcept { return __user_key_input.num7_press.load(); }
		inline bool key_8_press() const noexcept { return __user_key_input.num8_press.load(); }
		inline bool key_9_press() const noexcept { return __user_key_input.num9_press.load(); }

		inline bool key_pad0_press() const noexcept { return __user_key_input.numpad0_press.load(); }
		inline bool key_pad1_press() const noexcept { return __user_key_input.numpad1_press.load(); }
		inline bool key_pad2_press() const noexcept { return __user_key_input.numpad2_press.load(); }
		inline bool key_pad3_press() const noexcept { return __user_key_input.numpad3_press.load(); }
		inline bool key_pad4_press() const noexcept { return __user_key_input.numpad4_press.load(); }
		inline bool key_pad5_press() const noexcept { return __user_key_input.numpad5_press.load(); }
		inline bool key_pad6_press() const noexcept { return __user_key_input.numpad6_press.load(); }
		inline bool key_pad7_press() const noexcept { return __user_key_input.numpad7_press.load(); }
		inline bool key_pad8_press() const noexcept { return __user_key_input.numpad8_press.load(); }
		inline bool key_pad9_press() const noexcept { return __user_key_input.numpad9_press.load(); }

		inline bool key_add_press() const noexcept { return __user_key_input.add_press.load(); }
		inline bool key_sub_press() const noexcept { return __user_key_input.sub_press.load(); }
		inline bool key_mul_press() const noexcept { return __user_key_input.mul_press.load(); }
		inline bool key_div_press() const noexcept { return __user_key_input.div_press.load(); }

		inline bool key_F1_press() const noexcept { return __user_key_input.f1_press.load(); }
		inline bool key_F2_press() const noexcept { return __user_key_input.f2_press.load(); }
		inline bool key_F3_press() const noexcept { return __user_key_input.f3_press.load(); }
		inline bool key_F4_press() const noexcept { return __user_key_input.f4_press.load(); }
		inline bool key_F5_press() const noexcept { return __user_key_input.f5_press.load(); }
		inline bool key_F6_press() const noexcept { return __user_key_input.f6_press.load(); }
		inline bool key_F7_press() const noexcept { return __user_key_input.f7_press.load(); }
		inline bool key_F8_press() const noexcept { return __user_key_input.f8_press.load(); }
		inline bool key_F9_press() const noexcept { return __user_key_input.f9_press.load(); }
		inline bool key_F10_press() const noexcept { return __user_key_input.f10_press.load(); }
		inline bool key_F11_press() const noexcept { return __user_key_input.f11_press.load(); }
		inline bool key_F12_press() const noexcept { return __user_key_input.f12_press.load(); }

		inline bool key_escape_press() const noexcept { return __user_key_input.escape_press.load(); }
		inline bool key_enter_press() const noexcept { return __user_key_input.enter_press.load(); }
		inline bool key_tab_press() const noexcept { return __user_key_input.tab_press.load(); }
		inline bool key_backspace_press() const noexcept { return __user_key_input.backspace_press.load(); }
		inline bool key_insert_press() const noexcept { return __user_key_input.insert_press.load(); }
		inline bool key_delete_press() const noexcept { return __user_key_input.delete__press.load(); }
		inline bool key_right_press() const noexcept { return __user_key_input.right_press.load(); }
		inline bool key_left_press() const noexcept { return __user_key_input.left_press.load(); }
		inline bool key_down_press() const noexcept { return __user_key_input.down_press.load(); }
		inline bool key_up_press() const noexcept { return __user_key_input.up_press.load(); }
		inline bool key_alt_press() const noexcept { return __user_key_input.alt_press.load(); }
		inline bool key_shift_press() const noexcept { return __user_key_input.shift_press.load(); }
		inline bool key_ctrl_press() const noexcept { return __user_key_input.ctrl_press.load(); }


		inline bool mouse_1_release() const noexcept { return lnd::__user_key_input.mouse_1_release.load(); }
		inline bool mouse_2_release() const noexcept { return lnd::__user_key_input.mouse_2_release.load(); }
		inline bool mouse_3_release() const noexcept { return lnd::__user_key_input.mouse_3_release.load(); }
		inline bool mouse_4_release() const noexcept { return lnd::__user_key_input.mouse_4_release.load(); }
		inline bool mouse_5_release() const noexcept { return lnd::__user_key_input.mouse_5_release.load(); }
		inline bool mouse_6_release() const noexcept { return lnd::__user_key_input.mouse_6_release.load(); }
		inline bool mouse_7_release() const noexcept { return lnd::__user_key_input.mouse_7_release.load(); }
		inline bool mouse_8_release() const noexcept { return lnd::__user_key_input.mouse_8_release.load(); }

		inline bool key_space_release() const noexcept { return lnd::__user_key_input.space_release.load(); }
		inline bool key_apostrophe_release() const noexcept { return lnd::__user_key_input.apostrophe_release.load(); }
		inline bool key_comma_release() const noexcept { return lnd::__user_key_input.comma_release.load(); }
		inline bool key_minus_release() const noexcept { return lnd::__user_key_input.minus_release.load(); }
		inline bool key_period_release() const noexcept { return lnd::__user_key_input.period_release.load(); }
		inline bool key_slash_release() const noexcept { return lnd::__user_key_input.slash_release.load(); }

		inline bool key_A_release() const noexcept { return lnd::__user_key_input.A_release.load(); }
		inline bool key_B_release() const noexcept { return lnd::__user_key_input.B_release.load(); }
		inline bool key_C_release() const noexcept { return lnd::__user_key_input.C_release.load(); }
		inline bool key_D_release() const noexcept { return lnd::__user_key_input.D_release.load(); }
		inline bool key_E_release() const noexcept { return lnd::__user_key_input.E_release.load(); }
		inline bool key_F_release() const noexcept { return lnd::__user_key_input.F_release.load(); }
		inline bool key_G_release() const noexcept { return lnd::__user_key_input.G_release.load(); }
		inline bool key_H_release() const noexcept { return lnd::__user_key_input.H_release.load(); }
		inline bool key_I_release() const noexcept { return lnd::__user_key_input.I_release.load(); }
		inline bool key_J_release() const noexcept { return lnd::__user_key_input.J_release.load(); }
		inline bool key_K_release() const noexcept { return lnd::__user_key_input.K_release.load(); }
		inline bool key_L_release() const noexcept { return lnd::__user_key_input.L_release.load(); }
		inline bool key_M_release() const noexcept { return lnd::__user_key_input.M_release.load(); }
		inline bool key_N_release() const noexcept { return lnd::__user_key_input.N_release.load(); }
		inline bool key_O_release() const noexcept { return lnd::__user_key_input.O_release.load(); }
		inline bool key_P_release() const noexcept { return lnd::__user_key_input.P_release.load(); }
		inline bool key_Q_release() const noexcept { return lnd::__user_key_input.Q_release.load(); }
		inline bool key_R_release() const noexcept { return lnd::__user_key_input.R_release.load(); }
		inline bool key_S_release() const noexcept { return lnd::__user_key_input.S_release.load(); }
		inline bool key_T_release() const noexcept { return lnd::__user_key_input.T_release.load(); }
		inline bool key_U_release() const noexcept { return lnd::__user_key_input.U_release.load(); }
		inline bool key_V_release() const noexcept { return lnd::__user_key_input.V_release.load(); }
		inline bool key_W_release() const noexcept { return lnd::__user_key_input.W_release.load(); }
		inline bool key_X_release() const noexcept { return lnd::__user_key_input.X_release.load(); }
		inline bool key_Y_release() const noexcept { return lnd::__user_key_input.Y_release.load(); }
		inline bool key_Z_release() const noexcept { return lnd::__user_key_input.Z_release.load(); }

		inline bool key_0_release() const noexcept { return __user_key_input.num0_release.load(); }
		inline bool key_1_release() const noexcept { return __user_key_input.num1_release.load(); }
		inline bool key_2_release() const noexcept { return __user_key_input.num2_release.load(); }
		inline bool key_3_release() const noexcept { return __user_key_input.num3_release.load(); }
		inline bool key_4_release() const noexcept { return __user_key_input.num4_release.load(); }
		inline bool key_5_release() const noexcept { return __user_key_input.num5_release.load(); }
		inline bool key_6_release() const noexcept { return __user_key_input.num6_release.load(); }
		inline bool key_7_release() const noexcept { return __user_key_input.num7_release.load(); }
		inline bool key_8_release() const noexcept { return __user_key_input.num8_release.load(); }
		inline bool key_9_release() const noexcept { return __user_key_input.num9_release.load(); }

		inline bool key_pad0_release() const noexcept { return __user_key_input.numpad0_release.load(); }
		inline bool key_pad1_release() const noexcept { return __user_key_input.numpad1_release.load(); }
		inline bool key_pad2_release() const noexcept { return __user_key_input.numpad2_release.load(); }
		inline bool key_pad3_release() const noexcept { return __user_key_input.numpad3_release.load(); }
		inline bool key_pad4_release() const noexcept { return __user_key_input.numpad4_release.load(); }
		inline bool key_pad5_release() const noexcept { return __user_key_input.numpad5_release.load(); }
		inline bool key_pad6_release() const noexcept { return __user_key_input.numpad6_release.load(); }
		inline bool key_pad7_release() const noexcept { return __user_key_input.numpad7_release.load(); }
		inline bool key_pad8_release() const noexcept { return __user_key_input.numpad8_release.load(); }
		inline bool key_pad9_release() const noexcept { return __user_key_input.numpad9_release.load(); }

		inline bool key_add_release() const noexcept { return __user_key_input.add_release.load(); }
		inline bool key_sub_release() const noexcept { return __user_key_input.sub_release.load(); }
		inline bool key_mul_release() const noexcept { return __user_key_input.mul_release.load(); }
		inline bool key_div_release() const noexcept { return __user_key_input.div_release.load(); }

		inline bool key_F1_release() const noexcept { return __user_key_input.f1_release.load(); }
		inline bool key_F2_release() const noexcept { return __user_key_input.f2_release.load(); }
		inline bool key_F3_release() const noexcept { return __user_key_input.f3_release.load(); }
		inline bool key_F4_release() const noexcept { return __user_key_input.f4_release.load(); }
		inline bool key_F5_release() const noexcept { return __user_key_input.f5_release.load(); }
		inline bool key_F6_release() const noexcept { return __user_key_input.f6_release.load(); }
		inline bool key_F7_release() const noexcept { return __user_key_input.f7_release.load(); }
		inline bool key_F8_release() const noexcept { return __user_key_input.f8_release.load(); }
		inline bool key_F9_release() const noexcept { return __user_key_input.f9_release.load(); }
		inline bool key_F10_release() const noexcept { return __user_key_input.f10_release.load(); }
		inline bool key_F11_release() const noexcept { return __user_key_input.f11_release.load(); }
		inline bool key_F12_release() const noexcept { return __user_key_input.f12_release.load(); }

		inline bool key_escape_release() const noexcept { return __user_key_input.escape_release.load(); }
		inline bool key_enter_release() const noexcept { return __user_key_input.enter_release.load(); }
		inline bool key_tab_release() const noexcept { return __user_key_input.tab_release.load(); }
		inline bool key_backspace_release() const noexcept { return __user_key_input.backspace_release.load(); }
		inline bool key_insert_release() const noexcept { return __user_key_input.insert_release.load(); }
		inline bool key_delete_release() const noexcept { return __user_key_input.delete__release.load(); }
		inline bool key_right_release() const noexcept { return __user_key_input.right_release.load(); }
		inline bool key_left_release() const noexcept { return __user_key_input.left_release.load(); }
		inline bool key_down_release() const noexcept { return __user_key_input.down_release.load(); }
		inline bool key_up_release() const noexcept { return __user_key_input.up_release.load(); }
		inline bool key_alt_release() const noexcept { return __user_key_input.alt_release.load(); }
		inline bool key_shift_release() const noexcept { return __user_key_input.shift_release.load(); }
		inline bool key_ctrl_release() const noexcept { return __user_key_input.ctrl_release.load(); }


		inline void reset_key_events() const noexcept { lnd::__user_key_input.reset_key_events(); }


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

		inline void draw_line(const float* const vertex_ptr, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_3d(const float* const vertex_ptr, const lnd::program& program, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_RGB(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_RGB_3d(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_RGBA(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_RGBA_3d(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, 2);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri(const float* const vertex_ptr, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_3d(const float* const vertex_ptr, const lnd::program& program, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_hollow(const float* const vertex_ptr, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, 3);
			lnd::__default_vertex_buffer.bind();
		}
		inline void draw_tri_hollow_3d(const float* const vertex_ptr, const lnd::program& program, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_LOOP, 0, 3);
			lnd::__default_vertex_buffer.bind();
		}
		inline void draw_tri_RGB(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_RGB_3d(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_RGBA(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_RGBA_3d(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quad(const float* const vertex_ptr, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_quad_3d(const float* const vertex_ptr, const lnd::program& program, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_quad_hollow(const float* const vertex_ptr, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, 4);
			lnd::__default_vertex_buffer.bind();
		}
		inline void draw_quad_hollow_3d(const float* const vertex_ptr, const lnd::program& program, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_LOOP, 0, 4);
			lnd::__default_vertex_buffer.bind();
		}
		inline void draw_quad_RGB(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quad_RGB_3d(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quad_RGBA(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quad_RGBA_3d(const float* const vertex_ptr, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_QUADS, 0, 4);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}

		inline void draw_lines(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_lines_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_lines_RGB(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_lines_RGB_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_lines_RGBA(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_lines_RGBA_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tris(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tris_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tris_RGB(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tris_RGB_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tris_RGBA(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tris_RGBA_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLES, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quads(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_quads_RGB(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_quads_RGBA(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_QUADS, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_strip(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_strip_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINES, 0, vertex_count);
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_strip_RGB(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_strip_RGB_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_strip_RGBA(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_strip_RGBA_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_loop(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_loop_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_line_loop_RGB(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_loop_RGB_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_loop_RGBA(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_line_loop_RGBA_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_strip(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_strip_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_strip_RGB(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_strip_RGB_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_strip_RGBA(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_strip_RGBA_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_fan(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_fan_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
		}
		inline void draw_tri_fan_RGB(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_fan_RGB_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			program.use();
			set_mvp_matrix_3d(program, mvp_matrix_ptr);
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_fan_RGBA(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
			lnd::__default_vertex_buffer.unbind();
			lnd::__default_color_buffer.bind();
		}
		inline void draw_tri_fan_RGBA_3d(const float* const vertex_ptr, GLsizei vertex_count, const lnd::program& program, const float* const color_ptr, const float* const mvp_matrix_ptr)
		{
			lnd::__default_vertex_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), vertex_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
			lnd::__default_color_buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), color_ptr, GL_STATIC_DRAW);
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
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


		// LAUNCH ASYNC TASK

		bool async_task(std::function<void()> task)
		{
			std::unique_lock<std::mutex> lock(auxiliary_task_mutex);
			if ((last_task_ptr + 1 != next_task_ptr)
				&& ((next_task_ptr != task_buffer_data_ptr) || (last_task_ptr + 1 != task_buffer_end_ptr)))
			{
				*last_task_ptr++ = std::move(task);
				if (last_task_ptr == task_buffer_end_ptr) { last_task_ptr = task_buffer_data_ptr; }

				auxiliary_task_condition_var.notify_one();

				return true;
			}
			else
			{
				return false;
			}
		}


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

		std::vector<std::thread> auxiliary_threads;
		std::condition_variable auxiliary_task_condition_var;
		std::mutex auxiliary_task_mutex;
		bool stop_auxiliary_threads = false;
		std::vector<std::function<void()>> async_task_buffer;
		std::function<void()>* next_task_ptr = nullptr;
		std::function<void()>* last_task_ptr = nullptr;
		std::function<void()>* task_buffer_data_ptr = nullptr;
		std::function<void()>* task_buffer_end_ptr = nullptr;

	protected:

		std::condition_variable display_condition_var;

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
		void _setup_auxiliary_threads(size_t number_of_threads, size_t async_task_buffer_size)
		{
			auxiliary_threads.resize(number_of_threads);
			auxiliary_threads.shrink_to_fit();
			async_task_buffer.resize(async_task_buffer_size);
			async_task_buffer.shrink_to_fit();

			task_buffer_data_ptr = async_task_buffer.data();
			task_buffer_end_ptr = task_buffer_data_ptr + async_task_buffer_size;

			last_task_ptr = task_buffer_data_ptr;
			next_task_ptr = task_buffer_data_ptr;

			for (size_t k = 0; k < number_of_threads; k++)
			{
				auxiliary_threads[k] = std::thread([=]()
					{
						while (true)
						{
							std::function<void()> task;

							{
								std::unique_lock<std::mutex> lock(auxiliary_task_mutex);
								auxiliary_task_condition_var.wait(lock, [=]() { return stop_auxiliary_threads || last_task_ptr != next_task_ptr; });
								if (stop_auxiliary_threads && last_task_ptr == next_task_ptr) { break; }

								task = std::move(*next_task_ptr++);
								if (next_task_ptr == task_buffer_end_ptr) { next_task_ptr = task_buffer_data_ptr; }
							}

							task();
						}
					}
				);
			}
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

		// do not call this function in a derived class
		void _stop_auxiliary_threads() noexcept
		{
			{
				std::unique_lock<std::mutex> lock(auxiliary_task_mutex);
				stop_auxiliary_threads = true;
			}

			auxiliary_task_condition_var.notify_all();

			size_t number_of_threads = auxiliary_threads.size();
			for (size_t k = 0; k < number_of_threads; k++)
			{
				auxiliary_threads[k].join();
			}
		}
	};


	template <class _looper> class window : public _looper
	{

	public:

		bool show(int new_screen_width, int new_screen_height, bool rescale_screen_coordinates,
			double new_timeframe, const char* new_title)
		{
			this->_setup_basic_infos(new_screen_width, new_screen_height,
				rescale_screen_coordinates, static_cast<float>(new_timeframe));

			if (rescale_screen_coordinates)
			{
				if (new_screen_width >= new_screen_height)
				{
					lnd::__user_mouse_input.X_shift = 0.5 * static_cast<double>(new_screen_width);
					lnd::__user_mouse_input.Y_shift = 0.5 * static_cast<double>(new_screen_height);
					lnd::__user_mouse_input.X_scale = 1.0 / lnd::__user_mouse_input.Y_shift;
					lnd::__user_mouse_input.Y_scale = 1.0 / lnd::__user_mouse_input.Y_shift;
				}
				else
				{
					lnd::__user_mouse_input.X_shift = 0.5 * static_cast<double>(new_screen_width);
					lnd::__user_mouse_input.Y_shift = 0.5 * static_cast<double>(new_screen_height);
					lnd::__user_mouse_input.X_scale = 1.0 / lnd::__user_mouse_input.X_shift;
					lnd::__user_mouse_input.Y_scale = 1.0 / lnd::__user_mouse_input.X_shift;
				}
			}
			else
			{
				lnd::__user_mouse_input.X_shift = 0.5 * static_cast<double>(new_screen_width);
				lnd::__user_mouse_input.Y_shift = 0.5 * static_cast<double>(new_screen_height);
				lnd::__user_mouse_input.X_scale = 1.0 / lnd::__user_mouse_input.X_shift;
				lnd::__user_mouse_input.Y_scale = 1.0 / lnd::__user_mouse_input.Y_shift;
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

			this->_setup_auxiliary_threads(number_of_threads, task_buffer_size);
			clock_sleep_time = static_cast<long long>(static_cast<double>(1000000000) * new_timeframe);
			_start = std::chrono::LND_CLOCK::now();

			// loop

			while (!display_running.load()) {}

			lnd::__user_key_input.reset_key_events();

			if (new_timeframe > 0.0)
			{
				while (true)
				{
					// frame scheduling
					while ((_stop - _start).count() < clock_sleep_time)
					{
						_stop = std::chrono::LND_CLOCK::now();
					}
					time_elapsed = 0.000000001f * static_cast<float>((_stop - _start).count());
					_start = std::chrono::LND_CLOCK::now();

					// loop content
					this->loop(time_elapsed);

					if (this->exit_condition() || glfwWindowShouldClose(lnd::__window_ptr))
					{
						// exit
						display_running.store(false);
						this->display_condition_var.notify_one();
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
					time_elapsed = 0.000000001f * static_cast<float>((_stop - _start).count());
					_start = std::chrono::LND_CLOCK::now();

					// loop content
					this->loop(time_elapsed);

					if (this->exit_condition() || glfwWindowShouldClose(lnd::__window_ptr))
					{
						// exit
						display_running.store(false);
						this->display_condition_var.notify_one();
						break;
					}
				}
			}

			// exit
			this->_stop_auxiliary_threads();
			display_thread.join();
			lnd::__user_key_input.reset_key_events();
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
		void set_auxiliary_threads(size_t new_number_of_threads)
		{
			if (new_number_of_threads > 0) { number_of_threads = new_number_of_threads; }
			else { number_of_threads = 0; }
		}
		void set_task_buffer(size_t new_task_buffer_size)
		{
			if (new_task_buffer_size > 0) { task_buffer_size = new_task_buffer_size; }
			else { task_buffer_size = 0; }
		}

		window() = default;
		~window()
		{
			glfwInit();
			lnd::__window_ptr = glfwCreateWindow(1, 1, "", nullptr, nullptr);
			glfwDestroyWindow(lnd::__window_ptr);
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
				lnd::__window_ptr = glfwCreateWindow(new_screen_width, new_screen_height,
					new_title, glfwGetPrimaryMonitor(), nullptr);
			}
			else
			{
				lnd::__window_ptr = glfwCreateWindow(new_screen_width, new_screen_height,
					new_title, nullptr, nullptr);
			}

			if (lnd::__window_ptr == nullptr)
			{
				glfwTerminate();
				display_init_failed.store(true);
				display_init_finished.store(true);
				return;
			}
			glfwMakeContextCurrent(lnd::__window_ptr);
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

			glfwSetInputMode(lnd::__window_ptr, GLFW_STICKY_KEYS, GLFW_TRUE);
			glfwSetInputMode(lnd::__window_ptr, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
			glfwSetKeyCallback(lnd::__window_ptr, &lnd::key_callback);
			glfwSetMouseButtonCallback(lnd::__window_ptr, &lnd::mouse_button_callback);
			glfwSetCursorPosCallback(lnd::__window_ptr, &lnd::mouse_position_callback);

			// display

			glEnable(GL_BLEND);
			glBlendFunc(GL_ONE, GL_ZERO);
			if (window_anti_aliasing) { glEnable(GL_MULTISAMPLE); }

			this->_setup_basic_shaders_and_buffers(rescale_screen_coordinates);
			this->setup();
			display_running.store(true);

			lnd::__user_key_input.reset_key_events();

			while (true)
			{
				{
					std::unique_lock<std::mutex> lock(display_mutex);
					this->display_condition_var.wait(lock);
				}

				lnd::__user_key_input.reset_key_events();
				glfwPollEvents();

				this->display();

				glfwSwapBuffers(lnd::__window_ptr);

				if (!display_running.load())
				{
					this->exit();
					this->_delete_basic_shaders_and_buffers();
					glfwDestroyWindow(lnd::__window_ptr);
					glfwTerminate();
					break;
				}
			}

			lnd::__user_key_input.reset_key_events();
		}

		// window
		bool window_resizable = false;
		bool window_fullscreen = false;
		bool window_anti_aliasing = false;

		// time elapsed since last frame
		float time_elapsed = 0.0f;

		// clock
		std::chrono::time_point<std::chrono::steady_clock> _start;
		std::chrono::time_point<std::chrono::steady_clock> _stop;
		long long clock_sleep_time = 0;

		// other specs
		size_t number_of_threads = 0;
		size_t task_buffer_size = 0;

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

	template <size_t _index_count> class cluster_index
	{

	private:

		LND_INDEX(unsigned int, _index_count) m;

	public:

		cluster_index() = default;
		~cluster_index() = default;
		cluster_index(const cluster_index<_index_count>&) = default;
		cluster_index& operator=(const cluster_index<_index_count>&) = default;
		cluster_index(cluster_index<_index_count>&&) = default;
		cluster_index& operator=(cluster_index<_index_count>&&) = default;

		cluster_index(std::initializer_list<unsigned int> L)
		{
			std::copy(L.begin(), L.end(), static_cast<unsigned int*>(static_cast<void*>(m.data())));
		}
		cluster_index& operator=(std::initializer_list<unsigned int> L)
		{
			std::copy(L.begin(), L.end(), static_cast<unsigned int*>(static_cast<void*>(m.data())));
			return *this;
		}

		inline const unsigned int* data() const noexcept { return static_cast<const unsigned int*>(static_cast<const void*>(m.data())); }
		inline unsigned int* data() noexcept { return static_cast<unsigned int*>(static_cast<void*>(m.data())); }
		inline const unsigned int& operator[](size_t offset) const noexcept
		{
			return *(static_cast<const unsigned int*>(static_cast<const void*>(m.data())) + offset);
		}
		inline unsigned int& operator[](size_t offset) noexcept
		{
			return *(static_cast<unsigned int*>(static_cast<void*>(m.data())) + offset);
		}
		inline const unsigned int& operator()(size_t index) const noexcept
		{
			return *(static_cast<const unsigned int*>(static_cast<const void*>(m.data())) + index);
		}
		inline unsigned int& operator()(size_t index) noexcept
		{
			return *(static_cast<unsigned int*>(static_cast<void*>(m.data())) + index);
		}

		constexpr size_t index_count() const noexcept
		{
			return _index_count;
		}
		constexpr size_t size() const noexcept
		{
			return _index_count;
		}
	};

	template <size_t _index_count_pc, class _Allocator = LND_ALLOCATOR<lnd::cluster_index<_index_count_pc>>> class group_cluster_index
	{

	private:

		std::vector<lnd::cluster_index<_index_count_pc>, _Allocator> m;
		lnd::buffer_index buffer;

	public:

		group_cluster_index() = default;
		~group_cluster_index() = default;
		group_cluster_index(size_t n)
		{
			m = std::vector<const lnd::cluster_index<_index_count_pc>>(n, lnd::cluster_index<_index_count_pc>());
		}
		group_cluster_index(size_t n, const lnd::cluster_index<_index_count_pc>& rhs)
		{
			m = std::vector<const lnd::cluster_index<_index_count_pc>>(n, rhs);
		}
		template <class _rhs_Allocator> group_cluster_index(const group_cluster_index<_index_count_pc, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
		}
		template <class _rhs_Allocator> group_cluster_index& operator=(const group_cluster_index<_index_count_pc, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
			return *this;
		}
		template <class _rhs_Allocator> group_cluster_index(group_cluster_index<_index_count_pc, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
		}
		template <class _rhs_Allocator> group_cluster_index& operator=(group_cluster_index<_index_count_pc, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
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
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->size() * sizeof(unsigned int), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const unsigned int* const ptr, size_t cluster_count) const
		{
			constexpr size_t n = _index_count_pc * sizeof(unsigned int);
			buffer.bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, n * cluster_count, ptr, GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(unsigned int), this->data());
		}
		inline void buffer_update_from(const unsigned int* const ptr, size_t cluster_count) const
		{
			constexpr size_t n = _index_count_pc * sizeof(unsigned int);
			glNamedBufferSubData(buffer.get(), 0, n * cluster_count, ptr);
		}


		inline const unsigned int* data() const noexcept { return static_cast<const unsigned int*>(static_cast<const void*>(m.data())); }
		inline unsigned int* data() noexcept { return static_cast<unsigned int*>(static_cast<void*>(m.data())); }
		inline const unsigned int& operator[](size_t offset) const noexcept
		{
			return *(static_cast<const unsigned int*>(static_cast<const void*>(m.data())) + offset);
		}
		inline unsigned int& operator[](size_t offset) noexcept
		{
			return *(static_cast<unsigned int*>(static_cast<void*>(m.data())) + offset);
		}
		inline const unsigned int& operator()(size_t cluster, size_t index) const noexcept
		{
			return *(static_cast<const unsigned int*>(static_cast<const void*>(m.data())) + index + _index_count_pc * cluster);
		}
		inline unsigned int& operator()(size_t cluster, size_t index) noexcept
		{
			return *(static_cast<unsigned int*>(static_cast<void*>(m.data())) + index + _index_count_pc * cluster);
		}

		inline const lnd::cluster_index<_index_count_pc>* data_cluster() const noexcept
		{
			return static_cast<const lnd::cluster_index<_index_count_pc>*>(static_cast<const void*>(m.data()));
		}
		inline lnd::cluster_index<_index_count_pc>* data_cluster() noexcept
		{
			return static_cast<lnd::cluster_index<_index_count_pc>*>(static_cast<void*>(m.data()));
		}
		inline const lnd::cluster_index<_index_count_pc>& operator()(size_t cluster) const noexcept
		{
			return *(m.data() + cluster);
		}
		inline lnd::cluster_index<_index_count_pc>& operator()(size_t cluster) noexcept
		{
			return *(m.data() + cluster);
		}

		inline void resize_cluster_count(size_t n)
		{
			m.resize(n);
		}
		inline void reserve_cluster_count(size_t n)
		{
			m.reserve(n);
		}
		inline void push_back_cluster(const lnd::cluster_index<_index_count_pc>& new_cluster)
		{
			m.push_back(new_cluster);
		}
		inline void push_front_cluster(const lnd::cluster_index<_index_count_pc>& new_cluster)
		{
			m.push_front(new_cluster);
		}
		inline void pop_back_cluster()
		{
			m.pop_back();
		}
		inline void pop_front_cluster()
		{
			m.pop_front();
		}
		inline size_t cluster_count() const noexcept
		{
			return m.size();
		}
		inline size_t cluster_capacity() const noexcept
		{
			return m.capacity();
		}
		inline size_t index_count() const noexcept
		{
			return _index_count_pc * m.size();
		}
		constexpr size_t index_count_per_cluster() const noexcept
		{
			return _index_count_pc;
		}
		inline size_t size() const noexcept
		{
			return _index_count_pc * m.size();
		}
		inline void shrink_to_fit()
		{
			m.shrink_to_fit();
		}

		inline void propagate_with_offset(unsigned int offset)
		{
			size_t n = m.size();
			size_t k;
			unsigned int* pf = static_cast<unsigned int*>(static_cast<void*>(m.data()));
			unsigned int* p;
			unsigned int* q = pf + _index_count_pc;
			unsigned int acc = 0;
			for (size_t j = 1; j < n; j++)
			{
				p = pf; acc += offset;
				for (k = 0; k < _index_count_pc; k++)
				{
					*q++ = acc + (*p++);
				}
			}
		}
	};

	template <class _Allocator = LND_ALLOCATOR<unsigned int>> class group_index
	{

	private:

		std::vector<unsigned int, _Allocator> m;
		lnd::buffer_index buffer;

	public:

		group_index() = default;
		~group_index() = default;
		group_index(size_t n)
		{
			m = std::vector<unsigned int>(n, 0);
		}
		group_index(size_t n, unsigned int x)
		{
			m = std::vector<unsigned int>(n, x);
		}
		template <class _rhs_Allocator> group_index(const group_index<_rhs_Allocator>& rhs)
		{
			m = rhs.m;
		}
		template <class _rhs_Allocator> group_index& operator=(const group_index<_rhs_Allocator>& rhs)
		{
			m = rhs.m;
			return *this;
		}
		template <class _rhs_Allocator> group_index(group_index<_rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
		}
		template <class _rhs_Allocator> group_index& operator=(group_index<_rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
			return *this;
		}

		group_index(std::initializer_list<unsigned int> L)
		{
			m = std::vector<unsigned int, _Allocator>(L.size());
			std::copy(L.begin(), L.end(), static_cast<unsigned int*>(static_cast<void*>(m.data())));
		}
		group_index& operator=(std::initializer_list<unsigned int> L)
		{
			m.resize(L.size());
			std::copy(L.begin(), L.end(), static_cast<unsigned int*>(static_cast<void*>(m.data())));
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
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->size() * sizeof(unsigned int), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const unsigned int* const ptr, size_t vertex_count) const
		{
			buffer.bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertex_count * sizeof(unsigned int), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(unsigned int), this->data());
		}
		inline void buffer_update_from(const unsigned int* const ptr, size_t vertex_count) const
		{
			glNamedBufferSubData(buffer.get(), 0, vertex_count * sizeof(unsigned int), ptr);
		}

		inline const unsigned int* data() const noexcept { return static_cast<const unsigned int*>(static_cast<const void*>(m.data())); }
		inline unsigned int* data() noexcept { return static_cast<unsigned int*>(static_cast<void*>(m.data())); }
		inline const unsigned int& operator[](size_t offset) const noexcept
		{
			return *(static_cast<const unsigned int*>(static_cast<const void*>(m.data())) + offset);
		}
		inline unsigned int& operator[](size_t offset) noexcept
		{
			return *(static_cast<unsigned int*>(static_cast<void*>(m.data())) + offset);
		}
		inline const unsigned int& operator()(size_t index) const noexcept
		{
			return *(static_cast<const unsigned int*>(static_cast<const void*>(m.data())) + index);
		}
		inline unsigned int& operator()(size_t index) noexcept
		{
			return *(static_cast<unsigned int*>(static_cast<void*>(m.data())) + index);
		}

		inline void resize_index_count(size_t n)
		{
			m.resize(n);
		}
		inline void reserve_index_count(size_t n)
		{
			m.reserve(n);
		}
		inline void push_back_index(unsigned int new_index)
		{
			m.push_back(new_index);
		}
		inline void push_front_index(unsigned int new_index)
		{
			m.push_front(new_index);
		}
		inline void pop_back_index()
		{
			m.pop_back();
		}
		inline void pop_front_index()
		{
			m.pop_front();
		}
		inline size_t index_count() const noexcept
		{
			return m.size();
		}
		inline size_t index_capacity() const noexcept
		{
			return m.capacity();
		}
		inline size_t size() const noexcept
		{
			return m.size();
		}
		inline void shrink_to_fit()
		{
			m.shrink_to_fit();
		}
	};


	// COLOR STORAGE CLASSES

	template <size_t _color_count_pc, size_t _dim> class cluster_color
	{

	private:

		std::array<LND_COLOR(float, _dim), _color_count_pc> m;

	public:

		cluster_color() = default;
		~cluster_color() = default;
		cluster_color(const cluster_color<_color_count_pc, _dim>&) = default;
		cluster_color& operator=(const cluster_color<_color_count_pc, _dim>&) = default;
		cluster_color(cluster_color<_color_count_pc, _dim>&&) = default;
		cluster_color& operator=(cluster_color<_color_count_pc, _dim>&&) = default;

		cluster_color(std::initializer_list<float> L)
		{
			std::copy(L.begin(), L.end(), static_cast<float*>(static_cast<void*>(m.data())));
		}
		cluster_color& operator=(std::initializer_list<float> L)
		{
			std::copy(L.begin(), L.end(), static_cast<float*>(static_cast<void*>(m.data())));
			return *this;
		}

		inline const float* data() const noexcept { return static_cast<const float*>(static_cast<const void*>(m.data())); }
		inline float* data() noexcept { return static_cast<float*>(static_cast<void*>(m.data())); }
		inline const float& operator[](size_t offset) const noexcept
		{
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + offset);
		}
		inline float& operator[](size_t offset) noexcept
		{
			return *(static_cast<float*>(static_cast<void*>(m.data())) + offset);
		}
		inline const float& operator()(size_t color, size_t coord) const noexcept
		{
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + coord + _dim * color);
		}
		inline float& operator()(size_t color, size_t coord) noexcept
		{
			return *(static_cast<float*>(static_cast<void*>(m.data())) + coord + _dim * color);
		}

		inline const LND_COLOR(float, _dim)* data_color() const noexcept
		{
			return static_cast<const LND_COLOR(float, _dim)*>(static_cast<const void*>(m.data()));
		}
		inline LND_COLOR(float, _dim)* data_color() noexcept
		{
			return static_cast<LND_COLOR(float, _dim)*>(static_cast<void*>(m.data()));
		}
		inline const LND_COLOR(float, _dim)& operator()(size_t color) const noexcept
		{
			return *(static_cast<const LND_COLOR(float, _dim)*>(static_cast<const void*>(m.data())) + color);
		}
		inline LND_COLOR(float, _dim)& operator()(size_t color) noexcept
		{
			return *(static_cast<LND_COLOR(float, _dim)*>(static_cast<void*>(m.data())) + color);
		}

		constexpr size_t color_count() const noexcept
		{
			return _color_count_pc;
		}
		constexpr size_t dim() const noexcept
		{
			return _dim;
		}
		constexpr size_t size() const noexcept
		{
			return _color_count_pc * _dim;
		}
	};

	template <size_t _color_count_pc, size_t _dim, class _Allocator
		= LND_ALLOCATOR<lnd::cluster_color<_color_count_pc, _dim>>>
		class group_cluster_color
	{

	private:

		std::vector<lnd::cluster_color<_color_count_pc, _dim>, _Allocator> m;
		lnd::buffer_color buffer;

	public:

		group_cluster_color() = default;
		~group_cluster_color() = default;
		group_cluster_color(size_t n)
		{
			m = std::vector<const lnd::cluster_color<_color_count_pc, _dim>, _Allocator>(n, lnd::cluster_color<_color_count_pc, _dim>());
		}
		group_cluster_color(size_t n, const lnd::cluster_color<_color_count_pc, _dim>& rhs)
		{
			m = std::vector<const lnd::cluster_color<_color_count_pc, _dim>, _Allocator>(n, rhs);
		}
		template <class _rhs_Allocator> group_cluster_color(const group_cluster_color<_color_count_pc, _dim, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
		}
		template <class _rhs_Allocator> group_cluster_color& operator=(const group_cluster_color<_color_count_pc, _dim, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
			return *this;
		}
		template <class _rhs_Allocator> group_cluster_color(group_cluster_color<_color_count_pc, _dim, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
		}
		template <class _rhs_Allocator> group_cluster_color& operator=(group_cluster_color<_color_count_pc, _dim, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
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
			glBufferData(GL_ARRAY_BUFFER, this->size() * sizeof(float), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const float* const ptr, size_t cluster_count) const
		{
			constexpr size_t n = _color_count_pc * _dim * sizeof(float);
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, n * cluster_count, ptr, GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(float), this->data());
		}
		inline void buffer_update_from(const float* const ptr, size_t cluster_count) const
		{
			constexpr size_t n = _color_count_pc * _dim * sizeof(float);
			glNamedBufferSubData(buffer.get(), 0, n * cluster_count, ptr);
		}

		inline const float* data() const noexcept { return static_cast<const float*>(static_cast<const void*>(m.data())); }
		inline float* data() noexcept { return static_cast<float*>(static_cast<void*>(m.data())); }
		inline const float& operator[](size_t offset) const noexcept
		{
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + offset);
		}
		inline float& operator[](size_t offset) noexcept
		{
			return *(static_cast<float*>(static_cast<void*>(m.data())) + offset);
		}
		inline const float& operator()(size_t cluster, size_t color, size_t coord) const noexcept
		{
			constexpr size_t n = _color_count_pc * _dim;
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + coord + _dim * color + n * cluster);
		}
		inline float& operator()(size_t cluster, size_t color, size_t coord) noexcept
		{
			constexpr size_t n = color_count * _dim;
			return *(static_cast<float*>(static_cast<void*>(m.data())) + coord + _dim * color + n * cluster);
		}

		inline const LND_COLOR(float, _dim)* data_color() const noexcept
		{
			return static_cast<const LND_COLOR(float, _dim)*>(static_cast<const void*>(m.data()));
		}
		inline LND_COLOR(float, _dim)* data_color() noexcept
		{
			return static_cast<LND_COLOR(float, _dim)*>(static_cast<void*>(m.data()));
		}
		inline const LND_COLOR(float, _dim)& operator()(size_t cluster, size_t color) const noexcept
		{
			return *(static_cast<const LND_COLOR(float, _dim)*>(static_cast<const void*>(m.data())) + color + _color_count_pc * cluster);
		}
		inline LND_COLOR(float, _dim)& operator()(size_t cluster, size_t color) noexcept
		{
			return *(static_cast<LND_COLOR(float, _dim)*>(static_cast<void*>(m.data())) + color + _color_count_pc * cluster);
		}

		inline const lnd::cluster_color<_color_count_pc, _dim>* data_cluster() const noexcept
		{
			return static_cast<const lnd::cluster_color<_color_count_pc, _dim>*>(static_cast<const void*>(m.data()));
		}
		inline lnd::cluster_color<_color_count_pc, _dim>* data_cluster() noexcept
		{
			return static_cast<lnd::cluster_color<_color_count_pc, _dim>*>(static_cast<void*>(m.data()));
		}
		inline const lnd::cluster_color<_color_count_pc, _dim>& operator()(size_t cluster) const noexcept
		{
			return *(m.data() + cluster);
		}
		inline lnd::cluster_color<_color_count_pc, _dim>& operator()(size_t cluster) noexcept
		{
			return *(m.data() + cluster);
		}

		inline void resize_cluster_count(size_t n)
		{
			m.resize(n);
		}
		inline void reserve_cluster_count(size_t n)
		{
			m.reserve(n);
		}
		inline void push_back_cluster(const lnd::cluster_color<_color_count_pc, _dim>& new_cluster)
		{
			m.push_back(new_cluster);
		}
		inline void push_front_cluster(const lnd::cluster_color<_color_count_pc, _dim>& new_cluster)
		{
			m.push_front(new_cluster);
		}
		inline void pop_back_cluster()
		{
			m.pop_back();
		}
		inline void pop_front_cluster()
		{
			m.pop_front();
		}
		inline size_t cluster_count() const noexcept
		{
			return m.size();
		}
		inline size_t cluster_capacity() const noexcept
		{
			return m.capacity();
		}
		inline size_t color_count() const noexcept
		{
			return _color_count_pc * m.size();
		}
		constexpr size_t color_count_per_cluster() const noexcept
		{
			return _color_count_pc;
		}
		constexpr size_t dim() const noexcept
		{
			return _dim;
		}
		inline size_t size() const noexcept
		{
			constexpr size_t n = _color_count_pc * _dim;
			return n * m.size();
		}
		inline void shrink_to_fit()
		{
			m.shrink_to_fit();
		}
	};

	template <size_t _dim, class _Allocator = LND_ALLOCATOR<LND_COLOR(float, _dim)>> class group_color
	{

	private:

		std::vector<LND_COLOR(float, _dim), _Allocator> m;
		lnd::buffer_color buffer;

	public:

		group_color() = default;
		~group_color() = default;
		group_color(size_t n)
		{
			m = std::vector<LND_COLOR(float, _dim)>(n, 0.0f);
		}
		group_color(size_t n, const LND_COLOR(float, _dim)& x)
		{
			m = std::vector<unsigned int>(n, x);
		}
		template <class _rhs_Allocator> group_color(const group_color<_dim, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
		}
		template <class _rhs_Allocator> group_color& operator=(const group_color<_dim, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
			return *this;
		}
		template <class _rhs_Allocator> group_color(group_color<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
		}
		template <class _rhs_Allocator> group_color& operator=(group_color<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
			return *this;
		}

		group_color(std::initializer_list<float> L)
		{
			m = std::vector<LND_COLOR(float, _dim), _Allocator>(L.size() / _dim);
			std::copy(L.begin(), L.end(), static_cast<float*>(static_cast<void*>(m.data())));
		}
		group_color& operator=(std::initializer_list<float> L)
		{
			m.resize(L.size() / _dim);
			std::copy(L.begin(), L.end(), static_cast<float*>(static_cast<void*>(m.data())));
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
			glBufferData(GL_ARRAY_BUFFER, this->size() * sizeof(float), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const float* const ptr, size_t vertex_count) const
		{
			constexpr size_t n = _dim * sizeof(float);
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, n * vertex_count, ptr, GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(float), this->data());
		}
		inline void buffer_update_from(const float* const ptr, size_t vertex_count) const
		{
			constexpr size_t n = _dim * sizeof(float);
			glNamedBufferSubData(buffer.get(), 0, n * vertex_count, ptr);
		}


		inline const float* data() const noexcept { return static_cast<const float*>(static_cast<const void*>(m.data())); }
		inline float* data() noexcept { return static_cast<float*>(static_cast<void*>(m.data())); }
		inline const float& operator[](size_t offset) const noexcept
		{
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + offset);
		}
		inline float& operator[](size_t offset) noexcept
		{
			return *(static_cast<float*>(static_cast<void*>(m.data())) + offset);
		}
		inline const float& operator()(size_t color, size_t coord) const noexcept
		{
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + coord + _dim * color);
		}
		inline float& operator()(size_t color, size_t coord) noexcept
		{
			return *(static_cast<float*>(static_cast<void*>(m.data())) + coord + _dim * color);
		}

		inline const LND_COLOR(float, _dim)* data_color() const noexcept
		{
			return static_cast<const LND_COLOR(float, _dim)*>(static_cast<const void*>(m.data()));
		}
		inline LND_COLOR(float, _dim)* data_color() noexcept
		{
			return static_cast<LND_COLOR(float, _dim)*>(static_cast<void*>(m.data()));
		}
		inline const LND_COLOR(float, _dim)& operator()(size_t color) const noexcept
		{
			return *(static_cast<const LND_COLOR(float, _dim)*>(static_cast<const void*>(m.data())) + color);
		}
		inline LND_COLOR(float, _dim)& operator()(size_t color) noexcept
		{
			return *(static_cast<LND_COLOR(float, _dim)*>(static_cast<void*>(m.data())) + color);
		}

		inline void resize_color_count(size_t n)
		{
			m.resize(n);
		}
		inline void reserve_color_count(size_t n)
		{
			m.reserve(n);
		}
		inline void push_back_color(const LND_COLOR(float, _dim)& new_color)
		{
			m.push_back(new_color);
		}
		inline void push_front_color(const LND_COLOR(float, _dim)& new_color)
		{
			m.push_front(new_color);
		}
		inline void pop_back_color()
		{
			m.pop_back();
		}
		inline void pop_front_color()
		{
			m.pop_front();
		}
		inline size_t color_count() const noexcept
		{
			return m.size();
		}
		inline size_t color_capacity() const noexcept
		{
			return m.capacity();
		}
		constexpr size_t dim() const noexcept
		{
			return _dim;
		}
		inline size_t size() const noexcept
		{
			return _dim * m.size();
		}
		inline size_t shrink_to_fit()
		{
			m.shrink_to_fit();
		}
	};


	// TEXTURE STORAGE CLASSES

	template <size_t _dim, class _texture_Allocator = LND_ALLOCATOR<LND_PIXEL(unsigned char, _dim)>> class texture
	{

	private:

		std::vector<LND_PIXEL(unsigned char, _dim), _texture_Allocator> m;
		size_t _width = 0;
		size_t _height = 0;
		lnd::buffer_texture buffer;
		int mapping = GL_NEAREST;
		int edges = GL_REPEAT;

	public:

		texture() = default;
		~texture() = default;
		texture(size_t new_width, size_t new_height)
		{
			m = std::vector<LND_PIXEL(unsigned char, _dim)>(new_width * new_height,
				LND_PIXEL(unsigned char, _dim){ static_cast<unsigned char>(0) });
			_width = new_width;
			_height = new_height;
		}
		texture(size_t new_width, size_t new_height, const LND_PIXEL(float, _dim)& x)
		{
			m = std::vector<LND_PIXEL(unsigned char, _dim)>(new_width * new_height, x);
			_width = new_width;
			_height = new_height;
		}
		template <class _rhs_Allocator> texture(const texture<_dim, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
			_width = rhs._width;
			_height = rhs._height;
		}
		template <class _rhs_Allocator> texture& operator=(const texture<_dim, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
			_width = rhs._width;
			_height = rhs._height;
			return *this;
		}
		template <class _rhs_Allocator> texture(texture<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
			_width = rhs._width;
			_height = rhs._height;
		}
		template <class _rhs_Allocator> texture& operator=(texture<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
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
		inline void buffer_unbind() const
		{
			buffer.unbind();
		}
		inline void buffer_allocate() const
		{
			buffer.bind();
			switch (_dim)
			{

			case 1:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE,
					static_cast<const unsigned char*>(static_cast<const void*>(m.data())));
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mapping);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mapping);
				break;

			case 2:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), 0, GL_RG, GL_UNSIGNED_BYTE,
					static_cast<const unsigned char*>(static_cast<const void*>(m.data())));
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mapping);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mapping);
				break;

			case 3:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), 0, GL_RGB, GL_UNSIGNED_BYTE,
					static_cast<const unsigned char*>(static_cast<const void*>(m.data())));
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, mapping);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, mapping);
				break;

			case 4:
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), 0, GL_RGBA, GL_UNSIGNED_BYTE,
					static_cast<const unsigned char*>(static_cast<const void*>(m.data())));
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
					static_cast<const void*>(m.data()));
				break;

			case 2:
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), GL_RG, GL_UNSIGNED_BYTE,
					static_cast<const void*>(m.data()));
				break;

			case 3:
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), GL_RGB, GL_UNSIGNED_BYTE,
					static_cast<const void*>(m.data()));
				break;

			case 4:
				glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), GL_RGBA, GL_UNSIGNED_BYTE,
					static_cast<const void*>(m.data()));
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

		inline size_t width() const noexcept { return _width; }
		inline size_t height() const noexcept { return _height; }

		inline void flip()
		{
			LND_PIXEL(unsigned char, _dim) temp;
			LND_PIXEL(unsigned char, _dim)* p = m.data();
			LND_PIXEL(unsigned char, _dim)* q = m.data() + _width * (_height - 1);
			size_t j;
			size_t jump = 2 * _width;
			for (size_t i = _height / 2; i > 0; i--)
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

		inline const unsigned char* data() const noexcept { return static_cast<const unsigned char*>(static_cast<const void*>(m.data())); }
		inline unsigned char* data() noexcept { return static_cast<unsigned char*>(static_cast<void*>(m.data())); }
		inline const unsigned char& operator[](size_t offset) const noexcept
		{
			return *(static_cast<const unsigned char*>(static_cast<const void*>(m.data())) + offset);
		}
		inline unsigned char& operator[](size_t offset) noexcept
		{
			return *(static_cast<unsigned char*>(static_cast<void*>(m.data())) + offset);
		}

		inline const LND_PIXEL(unsigned char, _dim)* data_pixel() const noexcept
		{
			return static_cast<const LND_PIXEL(unsigned char, _dim)*>(static_cast<const void*>(m.data()));
		}
		inline LND_PIXEL(unsigned char, _dim)* data_pixel() noexcept
		{
			return static_cast<LND_PIXEL(unsigned char, _dim)*>(static_cast<void*>(m.data()));
		}
		inline const LND_PIXEL(unsigned char, _dim)& operator()(size_t position) const noexcept
		{
			return *(static_cast<const LND_PIXEL(unsigned char, _dim)*>(static_cast<const void*>(m.data())) + position);
		}
		inline LND_PIXEL(unsigned char, _dim)& operator()(size_t position) noexcept
		{
			return *(static_cast<LND_PIXEL(unsigned char, _dim)*>(static_cast<void*>(m.data())) + position);
		}
		inline const LND_PIXEL(unsigned char, _dim)& operator()(size_t position_X, size_t position_Y) const noexcept
		{
			return *(static_cast<const LND_PIXEL(unsigned char, _dim)*>(static_cast<const void*>(m.data())) + position_X + _width * position_Y);
		}
		inline LND_PIXEL(unsigned char, _dim)& operator()(size_t position_X, size_t position_Y) noexcept
		{
			return *(static_cast<LND_PIXEL(unsigned char, _dim)*>(static_cast<void*>(m.data())) + position_X + _width * position_Y);
		}

		inline size_t size() const noexcept
		{
			return _dim * m.size();
		}
		inline size_t pixel_count() const noexcept
		{
			return m.size();
		}
		inline size_t pixel_capacity() const noexcept
		{
			return m.capacity();
		}
		inline void resize(size_t new_width, size_t  new_height)
		{
			m.resize(new_width * new_height);
			_width = new_width;
			_height = new_height;
		}
		inline void reserve_pixel_count(size_t n)
		{
			m.reserve(n);
		}
		inline void shrink_to_fit()
		{
			m.shrink_to_fit();
		}
	};


	// VERTEX STORAGE CLASSES

	template <size_t _vertex_count_pc, size_t _dim> class cluster_vertex
	{

	private:

		std::array<LND_VERTEX(float, _dim), _vertex_count_pc> m;

	public:

		cluster_vertex() = default;
		~cluster_vertex() = default;
		cluster_vertex(const cluster_vertex<_vertex_count_pc, _dim>&) = default;
		cluster_vertex& operator=(const cluster_vertex<_vertex_count_pc, _dim>&) = default;
		cluster_vertex(cluster_vertex<_vertex_count_pc, _dim>&&) = default;
		cluster_vertex& operator=(cluster_vertex<_vertex_count_pc, _dim>&&) = default;

		cluster_vertex(std::initializer_list<float> L)
		{
			std::copy(L.begin(), L.end(), static_cast<float*>(static_cast<void*>(m.data())));
		}
		cluster_vertex& operator=(std::initializer_list<float> L)
		{
			std::copy(L.begin(), L.end(), static_cast<float*>(static_cast<void*>(m.data())));
			return *this;
		}

		inline const float* data() const noexcept { return static_cast<const float*>(static_cast<const void*>(m.data())); }
		inline float* data() noexcept { return static_cast<float*>(static_cast<void*>(m.data())); }
		inline const float& operator[](size_t offset) const noexcept
		{
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + offset);
		}
		inline float& operator[](size_t offset) noexcept
		{
			return *(static_cast<float*>(static_cast<void*>(m.data())) + offset);
		}
		inline const float& operator()(size_t vertex, size_t coord) const noexcept
		{
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + coord + _dim * vertex);
		}
		inline float& operator()(size_t vertex, size_t coord) noexcept
		{
			return *(static_cast<float*>(static_cast<void*>(m.data())) + coord + _dim * vertex);
		}

		inline const LND_VERTEX(float, _dim)* data_vertex() const noexcept
		{
			return static_cast<const LND_VERTEX(float, _dim)*>(static_cast<const void*>(m.data()));
		}
		inline LND_VERTEX(float, _dim)* data_vertex() noexcept
		{
			return static_cast<LND_VERTEX(float, _dim)*>(static_cast<void*>(m.data()));
		}
		inline const LND_VERTEX(float, _dim)& operator()(size_t vertex) const noexcept
		{
			return *(static_cast<const LND_VERTEX(float, _dim)*>(static_cast<const void*>(m.data())) + vertex);
		}
		inline LND_VERTEX(float, _dim)& operator()(size_t vertex) noexcept
		{
			return *(static_cast<LND_VERTEX(float, _dim)*>(static_cast<void*>(m.data())) + vertex);
		}

		constexpr size_t vertex_count() const noexcept
		{
			return _vertex_count_pc;
		}
		constexpr size_t dim() const noexcept
		{
			return _dim;
		}
		constexpr size_t size() const noexcept
		{
			return _vertex_count_pc * _dim;
		}
	};

	template <size_t _vertex_count_pc, size_t _dim, class _Allocator
		= LND_ALLOCATOR<lnd::cluster_vertex<_vertex_count_pc, _dim>>>
		class group_cluster_vertex
	{

	private:

		std::vector<lnd::cluster_vertex<_vertex_count_pc, _dim>, _Allocator> m;
		lnd::buffer_vertex buffer;

	public:

		group_cluster_vertex() = default;
		~group_cluster_vertex() = default;
		group_cluster_vertex(size_t n)
		{
			m = std::vector<const lnd::cluster_vertex<_vertex_count_pc, _dim>, _Allocator>(n, lnd::cluster_vertex<_vertex_count_pc, _dim>());
		}
		group_cluster_vertex(size_t n, const lnd::cluster_vertex<_vertex_count_pc, _dim>& rhs)
		{
			m = std::vector<const lnd::cluster_vertex<_vertex_count_pc, _dim>, _Allocator>(n, rhs);
		}
		template <class _rhs_Allocator> group_cluster_vertex(const group_cluster_vertex<_vertex_count_pc, _dim, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
		}
		template <class _rhs_Allocator> group_cluster_vertex& operator=(const group_cluster_vertex<_vertex_count_pc, _dim, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
			return *this;
		}
		template <class _rhs_Allocator> group_cluster_vertex(group_cluster_vertex<_vertex_count_pc, _dim, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
		}
		template <class _rhs_Allocator> group_cluster_vertex& operator=(group_cluster_vertex<_vertex_count_pc, _dim, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
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
			glBufferData(GL_ARRAY_BUFFER, this->size() * sizeof(float), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const float* const ptr, size_t cluster_count) const
		{
			constexpr size_t n = _vertex_count_pc * _dim * sizeof(float);
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, n * cluster_count, ptr, GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(float), this->data());
		}
		inline void buffer_update_from(const float* const ptr, size_t cluster_count) const
		{
			constexpr size_t n = _vertex_count_pc * _dim * sizeof(float);
			glNamedBufferSubData(buffer.get(), 0, n * cluster_count, ptr);
		}

		inline const float* data() const noexcept { return static_cast<const float*>(static_cast<const void*>(m.data())); }
		inline float* data() noexcept { return static_cast<float*>(static_cast<void*>(m.data())); }
		inline const float& operator[](size_t offset) const noexcept
		{
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + offset);
		}
		inline float& operator[](size_t offset) noexcept
		{
			return *(static_cast<float*>(static_cast<void*>(m.data())) + offset);
		}
		inline const float& operator()(size_t cluster, size_t vertex, size_t coord) const noexcept
		{
			constexpr size_t n = _vertex_count_pc * _dim;
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + coord + _dim * vertex + n * cluster);
		}
		inline float& operator()(size_t cluster, size_t vertex, size_t coord) noexcept
		{
			constexpr size_t n = _vertex_count_pc * _dim;
			return *(static_cast<float*>(static_cast<void*>(m.data())) + coord + _dim * vertex + n * cluster);
		}

		inline const LND_VERTEX(float, _dim)* data_vertex() const noexcept
		{
			return static_cast<const LND_VERTEX(float, _dim)*>(static_cast<const void*>(m.data()));
		}
		inline LND_VERTEX(float, _dim)* data_vertex() noexcept
		{
			return static_cast<LND_VERTEX(float, _dim)*>(static_cast<void*>(m.data()));
		}
		inline const LND_VERTEX(float, _dim)& operator()(size_t cluster, size_t vertex) const noexcept
		{
			return *(static_cast<const LND_VERTEX(float, _dim)*>(static_cast<const void*>(m.data())) + vertex + _vertex_count_pc * cluster);
		}
		inline LND_VERTEX(float, _dim)& operator()(size_t cluster, size_t vertex) noexcept
		{
			return *(static_cast<LND_VERTEX(float, _dim)*>(static_cast<void*>(m.data())) + vertex + _vertex_count_pc * cluster);
		}

		inline const lnd::cluster_vertex<_vertex_count_pc, _dim>* data_cluster() const noexcept
		{
			return static_cast<const lnd::cluster_vertex<_vertex_count_pc, _dim>*>(static_cast<const void*>(m.data()));
		}
		inline lnd::cluster_vertex<_vertex_count_pc, _dim>* data_cluster() noexcept
		{
			return static_cast<lnd::cluster_vertex<_vertex_count_pc, _dim>*>(static_cast<void*>(m.data()));
		}
		inline const lnd::cluster_vertex<_vertex_count_pc, _dim>& operator()(size_t cluster) const noexcept
		{
			return *(m.data() + cluster);
		}
		inline lnd::cluster_vertex<_vertex_count_pc, _dim>& operator()(size_t cluster) noexcept
		{
			return *(m.data() + cluster);
		}

		inline void resize_cluster_count(size_t n)
		{
			m.resize(n);
		}
		inline void reserve_cluster_count(size_t n)
		{
			m.reserve(n);
		}
		inline void push_back_cluster(const lnd::cluster_vertex<_vertex_count_pc, _dim>& new_cluster)
		{
			m.push_back(new_cluster);
		}
		inline void push_front_cluster(const lnd::cluster_vertex<_vertex_count_pc, _dim>& new_cluster)
		{
			m.push_front(new_cluster);
		}
		inline void pop_back_cluster()
		{
			m.pop_back();
		}
		inline void pop_front_cluster()
		{
			m.pop_front();
		}
		inline size_t cluster_count() const noexcept
		{
			return m.size();
		}
		inline size_t cluster_capacity() const noexcept
		{
			return m.capacity();
		}
		inline size_t vertex_count() const noexcept
		{
			return _vertex_count_pc * m.size();
		}
		constexpr size_t vertex_count_per_cluster() const noexcept
		{
			return _vertex_count_pc;
		}
		constexpr size_t dim() const noexcept
		{
			return _dim;
		}
		inline size_t size() const noexcept
		{
			constexpr size_t n = _vertex_count_pc * _dim;
			return n * m.size();
		}
		inline void shrink_to_fit()
		{
			m.shrink_to_fit();
		}


		// makes normals

		inline void make_normals_from(const lnd::group_cluster_vertex<_vertex_count_pc, _dim>& vertex, bool trigonometric_orientation) noexcept
		{
			m.resize(vertex.m.size());
			constexpr size_t _offset = _vertex_count_pc * _dim;
			float* p = static_cast<float*>(static_cast<void*>(m.data()));
			const float* q = static_cast<const float*>(static_cast<const void*>(vertex.m.data()));
			float factor;
			size_t n = m.size();

			switch (trigonometric_orientation)
			{

			case true:

				switch (_dim)
				{

				case 2:
					for (size_t j = 0; j < n; j++)
					{
						*p = -*(q + 1);
						*(p + 1) = *q;
						factor = 1.0f / LND_SQRT((*p) * (*p) + (*q) * (*q));
						*p *= factor;
						*(p + 1) *= factor;
						for (size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 2 * k, p, 2 * sizeof(float));
						}
						p += _offset; q += _offset;
					}
					break;

				case 3:
#ifdef LND_INCLUDE_AVX
					__m128 u;
					__m128 v;
					__m128 w;
					for (size_t j = 0; j < n; j++)
					{
						w = _mm_loadu_ps(q);
						u = _mm_sub_ps(_mm_loadu_ps(q + 3), w);
						v = _mm_sub_ps(_mm_loadu_ps(q + 6), w);
						w = _mm_fnmadd_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2)),
							_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
							_mm_mul_ps(_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
								_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2))));
						_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
						w = _mm_mul_ps(w, _mm_set1_ps(1.0f / LND_SQRT(*p)));
						_mm_storeu_ps(p, w);
						for (size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 3 * k, p, 3 * sizeof(float));
						}
						p += _offset; q += _offset;
					}
#else // LND_INCLUDE_AVX
					float u3[3];
					float v3[3];
					for (size_t j = 0; j < n; j++)
					{
						u3[0] = *(q + 3) - *(q);
						u3[1] = *(q + 4) - *(q + 1);
						u3[2] = *(q + 5) - *(q + 2);
						v3[0] = *(q + 6) - *(q + 0);
						v3[1] = *(q + 7) - *(q + 1);
						v3[2] = *(q + 8) - *(q + 2);
						*p = u3[1] * v3[2] - u3[2] * v3[1];
						*(p + 1) = u3[2] * v3[0] - u3[0] * v3[2];
						*(p + 2) = u3[0] * v3[1] - u3[1] * v3[0];
						factor = 1.0f / LND_SQRT((*p) * (*p)
							+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
						*p *= factor;
						*(p + 1) *= factor;
						*(p + 2) *= factor;
						for (size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 3 * k, p, 3 * sizeof(float));
						}
						p += _offset; q += _offset;
					}
#endif // LND_INCLUDE_AVX
					break;

				default:
					break;
				}

				break;

			case false:

				switch (_dim)
				{

				case 2:
					for (size_t j = 0; j < n; j++)
					{
						*p = *(q + 1);
						*(p + 1) = -*q;
						factor = 1.0f / LND_SQRT((*p) * (*p) + (*q) * (*q));
						*p *= factor;
						*(p + 1) *= factor;
						for (size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 2 * k, p, 2 * sizeof(float));
						}
						p += _offset; q += _offset;
					}
					break;

				case 3:
#ifdef LND_INCLUDE_AVX
					__m128 v;
					__m128 u;
					__m128 w;
					for (size_t j = 0; j < n; j++)
					{
						w = _mm_loadu_ps(q);
						u = _mm_sub_ps(_mm_loadu_ps(q + 6), w);
						v = _mm_sub_ps(_mm_loadu_ps(q + 3), w);
						w = _mm_fnmadd_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 1, 0, 2)),
							_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 0, 2, 1)),
							_mm_mul_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(3, 0, 2, 1)),
								_mm_shuffle_ps(u, u, _MM_SHUFFLE(3, 1, 0, 2))));
						_mm_storeu_ps(p, _mm_dp_ps(w, w, 0x7f));
						w = _mm_mul_ps(w, _mm_set1_ps(1.0f / LND_SQRT(*p)));
						_mm_storeu_ps(p, w);
						for (size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 3 * k, p, 3 * sizeof(float));
						}
						p += _offset; q += _offset;
					}
#else // LND_INCLUDE_AVX
					float u3[3];
					float v3[3];
					for (size_t j = 0; j < n; j++)
					{
						u3[0] = *(q + 3) - *(q);
						u3[1] = *(q + 4) - *(q + 1);
						u3[2] = *(q + 5) - *(q + 2);
						v3[0] = *(q + 6) - *(q + 0);
						v3[1] = *(q + 7) - *(q + 1);
						v3[2] = *(q + 8) - *(q + 2);
						*p = u3[2] * v3[1] - u3[1] * v3[2];
						*(p + 1) = u3[0] * v3[2] - u3[2] * v3[0];
						*(p + 2) = u3[1] * v3[0] - u3[0] * v3[1];
						factor = 1.0f / LND_SQRT((*p) * (*p)
							+ (*(p + 1)) * (*(p + 1)) + (*(p + 2)) * (*(p + 2)));
						*p *= factor;
						*(p + 1) *= factor;
						*(p + 2) *= factor;
						for (size_t k = 1; k < _vertex_count_pc; k++)
						{
							memcpy(p + 3 * k, p, 3 * sizeof(float));
						}
						p += _offset; q += _offset;
					}
#endif // LND_INCLUDE_AVX
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
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				normals.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_LINES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_LINES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				normals.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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

		template <size_t _color_dim, class _color_Allocator> inline void draw_RGBa(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring)
		{
			switch (_vertex_count_pc)
			{

			case 1:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <size_t _color_dim, class _color_Allocator> inline void draw_RGBa_3d(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring)
		{
			switch (_vertex_count_pc)
			{

			case 1:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			default:
				break;
			}
		}

		template <size_t _color_dim, class _color_Allocator, class _normal_Allocator> inline void draw_RGBa_normals_3d(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_vertex<_vertex_count_pc, _dim, _normal_Allocator>& normals)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				coloring.buffer_unbind();
				normals.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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


		template <size_t _color_dim, class _color_Allocator> inline void draw_ranged_RGBa(
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
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_LINES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
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

		template <size_t _color_dim, class _color_Allocator> inline void draw_ranged_RGBa_3d(
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_POINTS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 2:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_LINES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				program.use();
				glDrawArrays(GL_TRIANGLES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
					static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
				buffer.unbind();
				coloring.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
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

		template <size_t _color_dim, class _color_Allocator, class _normal_Allocator> inline void draw_ranged_RGBa_normals_3d(
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				coloring.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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

		template <class _vertex_Allocator, size_t _pixel_dim, class _texture_Allocator> inline void draw_tex(
			const lnd::program& program,
			const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
			const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
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
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
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

		template <class _vertex_Allocator, size_t _pixel_dim, class _texture_Allocator> inline void draw_tex_3d(
			const lnd::program& program,
			const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
			const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image)
		{
			switch (_vertex_count_pc)
			{

			case 3:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
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

		template <size_t _pixel_dim, class _vertex_Allocator, class _texture_Allocator, class _normals_Allocator> inline void draw_tex_normals_3d(
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				normals.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
				buffer.unbind();
				texture_coord.buffer_unbind();
				normals.buffer_unbind();
				break;

			default:
				break;
			}
		}


		template <class _vertex_Allocator, size_t _pixel_dim, class _texture_Allocator> inline void draw_ranged_tex(
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
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
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
				glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
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

		template <class _vertex_Allocator, size_t _pixel_dim, class _texture_Allocator> inline void draw_ranged_tex_3d(
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
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

		template <size_t _pixel_dim, class _vertex_Allocator, class _texture_Allocator, class _normals_Allocator> inline void draw_ranged_tex_normals_3d(
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
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, _vertex_count_pc * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				normals.buffer_unbind();
				break;

			case 4:
				buffer.bind();
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_coord.buffer_bind();
				glEnableVertexAttribArray(1);
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
				normals.buffer_bind();
				glEnableVertexAttribArray(2);
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
				texture_image.buffer_bind();
				program.use();
				glDrawArrays(GL_QUADS, _vertex_count_pc * first_cluster, _vertex_count_pc * (end_cluster - first_cluster));
				buffer.unbind();
				texture_coord.buffer_unbind();
				normals.buffer_unbind();
				break;

			default:
				break;
			}
		}


		// draw indexed clusters

		template <size_t _index_count_pc, class _index_Allocator> inline void draw_lines_indexed(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, static_cast<GLsizei>(indexing.size()), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <size_t _index_count_pc, class _index_Allocator> inline void draw_lines_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, static_cast<GLsizei>(indexing.size()), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}


		template <size_t _index_count_pc, class _index_Allocator> inline void draw_ranged_lines_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, static_cast<GLsizei>(_index_count_pc) * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <size_t _index_count_pc, class _index_Allocator> inline void draw_ranged_lines_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, static_cast<GLsizei>(_index_count_pc) * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}


		template <size_t _index_count_pc, class _index_Allocator> inline void draw_tris_indexed(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <size_t _index_count_pc, class _index_Allocator> inline void draw_tris_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}


		template <size_t _index_count_pc, class _index_Allocator> inline void draw_ranged_tris_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <size_t _index_count_pc, class _index_Allocator> inline void draw_tris_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}


		template <size_t _index_count_pc, class _index_Allocator> inline void draw_quads_indexed(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <size_t _index_count_pc, class _index_Allocator> inline void draw_quads_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			indexing.buffer_unbind();
		}


		template <size_t _index_count_pc, class _index_Allocator> inline void draw_ranged_quads_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}

		template <size_t _index_count_pc, class _index_Allocator> inline void draw_ranged_quads_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			indexing.buffer_unbind();
		}


		// draw indexed clusters with RGB/RGBA gradient colors

		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_lines_RGBa_indexed(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_lines_RGBa_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}


		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_lines_RGBa_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_lines_RGBa_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_LINES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}


		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_tris_RGBa_indexed(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_tris_RGBa_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}


		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_tris_RGBa_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_tris_RGBa_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_TRIANGLES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}


		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_quads_RGBa_indexed(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_quads_RGBa_indexed_3d(
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, indexing.size(), GL_UNSIGNED_INT, nullptr);
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}


		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_quads_RGBa_indexed(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}

		template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_ranged_quads_RGBa_indexed_3d(
			GLsizei first_cluster,
			GLsizei end_cluster,
			const lnd::program& program,
			const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
			const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			indexing.buffer_bind();
			program.use();
			glDrawElements(GL_QUADS, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
				reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
			buffer.unbind();
			coloring.buffer_bind();
			indexing.buffer_unbind();
		}
	};

	template <size_t _dim, class _Allocator = LND_ALLOCATOR<LND_VERTEX(float, _dim)>> class group_vertex
	{

	private:

		std::vector<LND_VERTEX(float, _dim), _Allocator> m;
		lnd::buffer_vertex buffer;

	public:

		group_vertex() = default;
		~group_vertex() = default;
		group_vertex(size_t n)
		{
			m = std::vector<LND_VERTEX(float, _dim)>(n, LND_VERTEX(float, _dim){ 0.0f });
		}
		group_vertex(size_t n, const LND_VERTEX(float, _dim)& x)
		{
			m = std::vector<LND_VERTEX(float, _dim)>(n, x);
		}
		template <class _rhs_Allocator> group_vertex(const group_vertex<_dim, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
		}
		template <class _rhs_Allocator> group_vertex(group_vertex<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
		}
		template <class _rhs_Allocator> group_vertex& operator=(const group_vertex<_dim, _rhs_Allocator>& rhs)
		{
			m = rhs.m;
			return *this;
		}
		template <class _rhs_Allocator> group_vertex& operator=(group_vertex<_dim, _rhs_Allocator>&& rhs) noexcept
		{
			m = std::move(rhs.m);
			return *this;
		}

		group_vertex(std::initializer_list<float> L)
		{
			m = std::vector<LND_VERTEX(float, _dim), _Allocator>(L.size() / _dim);
			std::copy(L.begin(), L.end(), static_cast<float*>(static_cast<void*>(m.data())));
		}
		group_vertex& operator=(std::initializer_list<float> L)
		{
			m.resize(L.size() / _dim);
			std::copy(L.begin(), L.end(), static_cast<float*>(static_cast<void*>(m.data())));
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
			glBufferData(GL_ARRAY_BUFFER, this->size() * sizeof(float), this->data(), GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_allocate_from(const float* const ptr, size_t vertex_count) const
		{
			constexpr size_t n = _dim * sizeof(float);
			buffer.bind();
			glBufferData(GL_ARRAY_BUFFER, n * vertex_count, ptr, GL_STATIC_DRAW);
			buffer.unbind();
		}
		inline void buffer_update() const
		{
			glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(float), this->data());
		}
		inline void buffer_update_from(const float* const ptr, size_t vertex_count) const
		{
			constexpr size_t n = _dim * sizeof(float);
			glNamedBufferSubData(buffer.get(), 0, n * vertex_count, ptr);
		}

		inline const float* data() const noexcept { return static_cast<const float*>(static_cast<const void*>(m.data())); }
		inline float* data() noexcept { return static_cast<float*>(static_cast<void*>(m.data())); }
		inline const float& operator[](size_t offset) const noexcept
		{
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + offset);
		}
		inline float& operator[](size_t offset) noexcept
		{
			return *(static_cast<float*>(static_cast<void*>(m.data())) + offset);
		}
		inline const float& operator()(size_t vertex, size_t coord) const noexcept
		{
			return *(static_cast<const float*>(static_cast<const void*>(m.data())) + coord + _dim * vertex);
		}
		inline float& operator()(size_t vertex, size_t coord) noexcept
		{
			return *(static_cast<float*>(static_cast<void*>(m.data())) + coord + _dim * vertex);
		}

		inline const LND_VERTEX(float, _dim)* data_vertex() const noexcept
		{
			return static_cast<const LND_VERTEX(float, _dim)*>(static_cast<const void*>(m.data()));
		}
		inline LND_VERTEX(float, _dim)* data_vertex() noexcept
		{
			return static_cast<LND_VERTEX(float, _dim)*>(static_cast<void*>(m.data()));
		}
		inline const LND_VERTEX(float, _dim)& operator()(size_t vertex) const noexcept
		{
			return *(static_cast<const LND_VERTEX(float, _dim)*>(static_cast<const void*>(m.data())) + vertex);
		}
		inline LND_VERTEX(float, _dim)& operator()(size_t vertex) noexcept
		{
			return *(static_cast<LND_VERTEX(float, _dim)*>(static_cast<void*>(m.data())) + vertex);
		}

		inline void resize_vertex_count(size_t n)
		{
			m.resize(n);
		}
		inline void reserve_vertex_count(size_t n)
		{
			m.reserve(n);
		}
		inline void push_back_vertex(const LND_VERTEX(float, _dim)& new_vertex)
		{
			m.push_back(new_vertex);
		}
		inline void push_front_vertex(const LND_VERTEX(float, _dim)& new_vertex)
		{
			m.push_front(new_vertex);
		}
		inline void pop_back_vertex()
		{
			m.pop_back();
		}
		inline void pop_front_vertex()
		{
			m.pop_front();
		}
		inline size_t vertex_count() const noexcept
		{
			return m.size();
		}
		inline size_t vertex_capacity() const noexcept
		{
			return m.capacity();
		}
		constexpr size_t dim() const noexcept
		{
			return _dim;
		}
		inline size_t size() const noexcept
		{
			return _dim * m.size();
		}
		inline void shrink_to_fit()
		{
			m.shrink_to_fit();
		}


		// draw with solid colors

		template <class _index_Allocator> inline void draw_lines_indexed(
			const lnd::program& program,
			const lnd::group_index<_index_Allocator>& indexing)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}

		inline void draw_line_strip_3d(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
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
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, first_vertex, last_vertex - first_vertex);
			buffer.unbind();
		}


		inline void draw_line_loop(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}

		inline void draw_line_loop_3d(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}


		inline void draw_tri_strip(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}

		inline void draw_tri_strip_3d(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}


		inline void draw_tri_fan(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}

		inline void draw_tri_fan_3d(
			const lnd::program& program)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
		}


		// draw with RGB/RGBA gradient colors

		template <size_t _color_dim, class _color_Allocator> inline void draw_line_strip_RGBa(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
		}

		template <size_t _color_dim, class _color_Allocator> inline void draw_line_strip_RGBa_3d(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
			break;
		}


		template <size_t _color_dim, class _color_Allocator> inline void draw_ranged_line_strip_RGBa(
			GLsizei first_vertex,
			GLsizei last_vertex,
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, first_vertex, last_vertex - first_vertex);
			buffer.unbind();
			coloring.buffer_unbind();
		}

		template <size_t _color_dim, class _color_Allocator> inline void draw_ranged_line_strip_RGBa_3d(
			GLsizei first_vertex,
			GLsizei last_vertex,
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_STRIP, first_vertex, last_vertex - first_vertex);
			buffer.unbind();
			coloring.buffer_unbind();
		}


		template <size_t _color_dim, class _color_Allocator> inline void draw_line_loop_RGBa(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
		}

		template <size_t _color_dim, class _color_Allocator> inline void draw_line_loop_RGB_3d(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_LINE_LOOP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
		}


		template <size_t _color_dim, class _color_Allocator> inline void draw_tri_strip_RGBa(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
		}

		template <size_t _color_dim, class _color_Allocator> inline void draw_tri_strip_RGBa_3d(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_STRIP, 0, this->vertex_count());
			buffer.unbind();
			coloring.buffer_unbind();
		}


		template <size_t _color_dim, class _color_Allocator> inline void draw_tri_fan_RGBa(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
			coloring.buffer_unbind();
		}

		template <size_t _color_dim, class _color_Allocator> inline void draw_tri_fan_RGBa_3d(
			const lnd::program& program,
			const lnd::group_color<_color_dim, _color_Allocator>& coloring)
		{
			buffer.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
			coloring.buffer_bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, _color_dim, GL_FLOAT, GL_FALSE, _color_dim * sizeof(float), nullptr);
			program.use();
			glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(this->vertex_count()));
			buffer.unbind();
			coloring.buffer_unbind();
		}
	};


	// TEXT

	template <class _vertex_Allocator = LND_ALLOCATOR<float>> class text
	{

	private:

		inline const float* data_screen_vertex() const noexcept
		{
			return screen_vertex.data();
		}
		inline float* data_screen_vertex() noexcept
		{
			return screen_vertex.data();
		}

		inline const float* data_atlas_vertex() const noexcept
		{
			return atlas_vertex.data();
		}
		inline float* data_atlas_vertex() noexcept
		{
			return atlas_vertex.data();
		}

		std::vector<float, _vertex_Allocator> screen_vertex;
		std::vector<float, _vertex_Allocator> atlas_vertex;

		lnd::buffer_vertex buffer_screen_vertex;
		lnd::buffer_vertex buffer_atlas_vertex;

		size_t _capacity = 0;
		size_t _size = 0;

		float X0 = 0.0f;
		float Y0 = 0.0f;
		float dX = 0.0f;

		float screen_w = 0.0f;
		float screen_h = 0.0f;

		float atlas_w = 0.0f;
		float atlas_h = 0.0f;

	public:

		text() = default;
		~text() = default;
		text(size_t n)
		{
			_capacity = n;
			screen_vertex = std::vector<float, _vertex_Allocator>(n, 0.0f);
			atlas_vertex = std::vector<float, _vertex_Allocator>(n, 0.0f);
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

		inline void set_position_in_screen(float X, float Y, float delta_X) noexcept
		{
			X0 = X;
			Y0 = Y;
			dX = delta_X;
		}
		inline void set_size_in_screen(float new_width, float new_height) noexcept
		{
			screen_w = new_width;
			screen_h = new_height;
		}
		inline void set_size_in_atlas(float new_width, float new_height) noexcept
		{
			atlas_w = new_width;
			atlas_h = new_height;
		}

		inline size_t capacity() const noexcept
		{
			return _capacity;
		}
		inline size_t size() const noexcept
		{
			return _size;
		}
		inline void reserve(size_t new_capacity)
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
			float* ptr = screen_vertex.data();
			float X;

			for (size_t k = 0; k < _capacity; k++)
			{
				X = X0 + static_cast<float>(k) * dX;

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
			glBufferData(GL_ARRAY_BUFFER, _capacity * (8 * sizeof(float)), screen_vertex.data(), GL_STATIC_DRAW);
			buffer_screen_vertex.unbind();

			buffer_atlas_vertex.bind();
			glBufferData(GL_ARRAY_BUFFER, _capacity * (8 * sizeof(float)), atlas_vertex.data(), GL_STATIC_DRAW);
			buffer_atlas_vertex.unbind();
		}

		inline void buffer_update_screen_vertex() const
		{
			screen_vertex.resize(8 * _capacity);
			float* ptr = screen_vertex.data();
			float X;

			for (size_t k = 0; k < _capacity; k++)
			{
				X = X0 + static_cast<float>(k) * dX;

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

			glNamedBufferSubData(buffer_screen_vertex.get(), 0, _capacity * (8 * sizeof(float)), screen_vertex.data());
		}

		template <typename Ty, class data_to_atlas>
		inline void buffer_update_atlas_vertex(const Ty* text_ptr, size_t text_size, data_to_atlas atlas_XY)
		{
			atlas_vertex.resize(8 * text_size);
			float* ptr = atlas_vertex.data();
			float X;
			float Y;

			for (size_t k = text_size; k > 0; k--)
			{
				LND_VERTEX(float, 2) XY = atlas_XY(*text_ptr);

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

			glNamedBufferSubData(buffer_atlas_vertex.get(), 0, text_size * (8 * sizeof(float)), atlas_vertex.data());
		}

		template <size_t _dim, class _atlas_Allocator> inline  void draw(const lnd::program& program,
			const lnd::texture<_dim, _atlas_Allocator>& atlas)
		{
			buffer_screen_vertex.bind();
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
			buffer_atlas_vertex.bind();
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
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

		float mvp_matrix[16] = { 0.0f };
		float vp_matrix[16] = { 0.0f };
		float p_matrix[16] = {
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};
		float v_matrix[16] = { 0.0f };
		float mskybox_matrix[16] = { 0.0f };
		float skybox_matrix[16] = { 0.0f };

	public:

		camera_3d() = default;
		~camera_3d() = default;
		camera_3d(const lnd::camera_3d&) = default;
		lnd::camera_3d& operator=(const lnd::camera_3d&) = default;
		camera_3d(lnd::camera_3d&&) = default;
		lnd::camera_3d& operator=(lnd::camera_3d&&) = default;

		float position[4] = { 0.0f };
		float direction[4] = { 1.0f };

		float yaw = 0.0f;
		float pitch = 0.0f;

	private:

		float cos_yaw = 1.0f;
		float sin_yaw = 0.0f;
		float cos_pitch = 1.0f;
		float sin_pitch = 0.0f;

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

		inline void compute_p_matrix(float screen_ratio, float fov, float z_far, float z_near) noexcept
		{
			if (screen_ratio >= 1.0f)
			{
				float tan_half_fov_y = std::tanf(0.5f * fov);
				float dz_inv = 1.0f / (z_far - z_near);
				p_matrix[0] = 1.0f / (screen_ratio * tan_half_fov_y);
				p_matrix[5] = 1.0f / tan_half_fov_y;
				p_matrix[10] = (z_far + z_near) * dz_inv;
				p_matrix[14] = ((-2.0f) * z_near) * (z_far * dz_inv);
			}
			else
			{
				float tan_half_fov_x = std::tanf(0.5f * fov);
				float dz_inv = 1.0f / (z_far - z_near);
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
			m44xm44(static_cast<float*>(vp_matrix), static_cast<const float*>(p_matrix),
				static_cast<const float*>(v_matrix));
		}
		inline void compute_mvp_matrix(const float* const m_matrix_ptr) noexcept
		{
			m44xm44(static_cast<float*>(mvp_matrix), static_cast<const float*>(vp_matrix), m_matrix_ptr);
		}
		inline void compute_skybox_matrix() noexcept
		{
			m33hxm44(static_cast<float*>(skybox_matrix), static_cast<const float*>(p_matrix),
				static_cast<const float*>(v_matrix));
		}
		inline void compute_mskybox_matrix(const float* const m_matrix_ptr) noexcept
		{
			m44xm44(static_cast<float*>(mskybox_matrix), static_cast<const float*>(skybox_matrix), m_matrix_ptr);
		}

		inline const float* position_data() const noexcept
		{
			return static_cast<const float*>(position);
		}
		inline float* position_data() noexcept
		{
			return static_cast<float*>(position);
		}

		inline const float* direction_data() const noexcept
		{
			return static_cast<const float*>(direction);
		}
		inline float* direction_data() noexcept
		{
			return static_cast<float*>(direction);
		}

		inline const float* v_matrix_data() const noexcept
		{
			return static_cast<const float*>(v_matrix);
		}
		inline float* v_matrix_data() noexcept
		{
			return static_cast<float*>(v_matrix);
		}

		inline const float* p_matrix_data() const noexcept
		{
			return static_cast<const float*>(p_matrix);
		}
		inline float* p_matrix_data() noexcept
		{
			return static_cast<float*>(p_matrix);
		}

		inline const float* vp_matrix_data() const noexcept
		{
			return static_cast<const float*>(vp_matrix);
		}
		inline float* vp_matrix_data() noexcept
		{
			return static_cast<float*>(vp_matrix);
		}

		inline const float* mvp_matrix_data() const noexcept
		{
			return static_cast<const float*>(mvp_matrix);
		}
		inline float* mvp_matrix_data() noexcept
		{
			return static_cast<float*>(mvp_matrix);
		}

		inline const float* skybox_matrix_data() const noexcept
		{
			return static_cast<const float*>(skybox_matrix);
		}
		inline float* skybox_matrix_data() noexcept
		{
			return static_cast<float*>(skybox_matrix);
		}

		inline const float* mskybox_matrix_data() const noexcept
		{
			return static_cast<const float*>(mskybox_matrix);
		}
		inline float* mskybox_matrix_data() noexcept
		{
			return static_cast<float*>(mskybox_matrix);
		}

		inline void move_forward(float distance) noexcept
		{
			position[0] += distance * cos_yaw;
			position[1] += distance * sin_yaw;
		}
		inline void move_backward(float distance) noexcept
		{
			position[0] -= distance * cos_yaw;
			position[1] -= distance * sin_yaw;
		}
		inline void move_left(float distance) noexcept
		{
			position[0] -= distance * sin_yaw;
			position[1] += distance * cos_yaw;
		}
		inline void move_right(float distance) noexcept
		{
			position[0] += distance * sin_yaw;
			position[1] -= distance * cos_yaw;
		}
		inline void move_up(float distance) noexcept
		{
			position[2] += distance;
		}
		inline void move_down(float distance) noexcept
		{
			position[2] -= distance;
		}

		inline void turn_up_rad(float angle) noexcept
		{
			constexpr float pi_d2 = 0.5f * 3.14159265358979f;
			pitch += angle;
			if (pitch > pi_d2) { pitch = pi_d2; }
		}
		inline void turn_down_rad(float angle) noexcept
		{
			constexpr float pi_d2 = 0.5f * 3.14159265358979f;
			pitch -= angle;
			if (pitch < -pi_d2) { pitch = -pi_d2; }
		}
		inline void turn_left_rad(float angle) noexcept
		{
			constexpr float pi = 3.14159265358979f;
			constexpr float pi_m2 = 2.0f * 3.14159265358979f;
			yaw += angle;
			if (yaw > pi) { yaw -= pi_m2; }
		}
		inline void turn_right_rad(float angle) noexcept
		{
			constexpr float pi = 3.14159265358979f;
			constexpr float pi_m2 = 2.0f * 3.14159265358979f;
			yaw -= angle;
			if (yaw < -pi) { yaw += pi_m2; }
		}
		inline void turn_up_deg(float angle) noexcept
		{
			constexpr float pi_d2 = 0.5f * 3.14159265358979f;
			constexpr float coeff = 3.14159265358979f / 180.0f;
			pitch += coeff * angle;
			if (pitch > pi_d2) { pitch = pi_d2; }
		}
		inline void turn_down_deg(float angle) noexcept
		{
			constexpr float pi_d2 = 0.5f * 3.14159265358979f;
			constexpr float coeff = 3.14159265358979f / 180.0f;
			pitch -= coeff * angle;
			if (pitch < -pi_d2) { pitch = -pi_d2; }
		}
		inline void turn_left_deg(float angle) noexcept
		{
			constexpr float pi = 3.14159265358979f;
			constexpr float pi_m2 = 2.0f * 3.14159265358979f;
			constexpr float coeff = 3.14159265358979f / 180.0f;
			yaw += coeff * angle;
			if (yaw > pi) { yaw -= pi_m2; }
		}
		inline void turn_right_deg(float angle) noexcept
		{
			constexpr float pi = 3.14159265358979f;
			constexpr float pi_m2 = 2.0f * 3.14159265358979f;
			constexpr float coeff = 3.14159265358979f / 180.0f;
			yaw -= coeff * angle;
			if (yaw < -pi) { yaw += pi_m2; }
		}

	private:

		inline void m44xm44(float* const pC, const float* const pA, const float* const pB) noexcept
		{
#ifdef LND_INCLUDE_AVX
			__m128 vregA0 = _mm_loadu_ps(pA);
			__m128 vregA1 = _mm_loadu_ps(pA + 4);
			__m128 vregA2 = _mm_loadu_ps(pA + 8);
			__m128 vregA3 = _mm_loadu_ps(pA + 12);

			__m128 vregC = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB));
			vregC = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 1), vregC);
			vregC = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 2), vregC);
			vregC = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 3), vregC);
			_mm_storeu_ps(pC, vregC);

			vregC = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 4));
			vregC = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 5), vregC);
			vregC = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 6), vregC);
			vregC = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 7), vregC);
			_mm_storeu_ps(pC + 4, vregC);

			vregC = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 8));
			vregC = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 9), vregC);
			vregC = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 10), vregC);
			vregC = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 11), vregC);
			_mm_storeu_ps(pC + 8, vregC);

			vregC = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 12));
			vregC = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 13), vregC);
			vregC = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 14), vregC);
			vregC = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 15), vregC);
			_mm_storeu_ps(pC + 12, vregC);
#else // LND_INCLUDE_AVX
			float regB0; float regB1; size_t offset;
			for (size_t j = 0; j < 4; j++)
			{
				offset = 4 * j;
				regB0 = pB[offset];
				pC[offset] = pA[0] * regB0;
				pC[offset + 1] = pA[1] * regB0;
				pC[offset + 2] = pA[2] * regB0;
				pC[offset + 3] = pA[3] * regB0;
				regB1 = pB[offset + 1];
				pC[offset] += pA[4] * regB1;
				pC[offset + 1] += pA[5] * regB1;
				pC[offset + 2] += pA[6] * regB1;
				pC[offset + 3] += pA[7] * regB1;
				regB0 = pB[offset + 2];
				pC[offset] += pA[8] * regB0;
				pC[offset + 1] += pA[9] * regB0;
				pC[offset + 2] += pA[10] * regB0;
				pC[offset + 3] += pA[11] * regB0;
				regB1 = pB[offset + 3];
				pC[offset] += pA[12] * regB1;
				pC[offset + 1] += pA[13] * regB1;
				pC[offset + 2] += pA[14] * regB1;
				pC[offset + 3] += pA[15] * regB1;
			}
#endif // LND_INCLUDE_AVX
		}
		inline void m33hxm44(float* const pC, const float* const pA, const float* const pB) noexcept
		{
#ifdef LND_INCLUDE_AVX
			__m128 vregA0 = _mm_loadu_ps(pA);
			__m128 vregA1 = _mm_loadu_ps(pA + 4);
			__m128 vregA2 = _mm_loadu_ps(pA + 8);
			__m128 vregA3 = _mm_loadu_ps(pA + 12);

			__m128 vregC = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB));
			vregC = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 1), vregC);
			vregC = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 2), vregC);
			vregC = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 3), vregC);
			_mm_storeu_ps(pC, vregC);

			vregC = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 4));
			vregC = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 5), vregC);
			vregC = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 6), vregC);
			vregC = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 7), vregC);
			_mm_storeu_ps(pC + 4, vregC);

			vregC = _mm_mul_ps(vregA0, _mm_broadcast_ss(pB + 8));
			vregC = _mm_fmadd_ps(vregA1, _mm_broadcast_ss(pB + 9), vregC);
			vregC = _mm_fmadd_ps(vregA2, _mm_broadcast_ss(pB + 10), vregC);
			vregC = _mm_fmadd_ps(vregA3, _mm_broadcast_ss(pB + 11), vregC);
			_mm_storeu_ps(pC + 8, vregC);

			_mm_storeu_ps(pC + 12, vregA3);
#else // LND_INCLUDE_AVX
			float regB0; float regB1; size_t offset;
			for (size_t j = 0; j < 3; j++)
			{
				offset = 4 * j;
				regB0 = pB[offset];
				pC[offset] = pA[0] * regB0;
				pC[offset + 1] = pA[1] * regB0;
				pC[offset + 2] = pA[2] * regB0;
				pC[offset + 3] = pA[3] * regB0;
				regB1 = pB[offset + 1];
				pC[offset] += pA[4] * regB1;
				pC[offset + 1] += pA[5] * regB1;
				pC[offset + 2] += pA[6] * regB1;
				pC[offset + 3] += pA[7] * regB1;
				regB0 = pB[offset + 2];
				pC[offset] += pA[8] * regB0;
				pC[offset + 1] += pA[9] * regB0;
				pC[offset + 2] += pA[10] * regB0;
				pC[offset + 3] += pA[11] * regB0;
				regB1 = pB[offset + 3];
				pC[offset] += pA[12] * regB1;
				pC[offset + 1] += pA[13] * regB1;
				pC[offset + 2] += pA[14] * regB1;
				pC[offset + 3] += pA[15] * regB1;
			}
			memcpy(pC + 12, pA + 12, 4 * sizeof(float));
#endif // LND_INCLUDE_AVX
		}
	};

	class model_3d
	{

	private:

		float m_matrix[16] = {
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

		inline const float* m_matrix_data() const noexcept
		{
			return static_cast<const float*>(m_matrix);
		}
		inline float* m_matrix_data() noexcept
		{
			return static_cast<float*>(m_matrix);
		}

		inline void set_position(float x, float y, float z) noexcept
		{
			m_matrix[12] = x;
			m_matrix[13] = y;
			m_matrix[14] = z;
		}
		inline void set_position(const float* const position_ptr)
		{
			memcpy(static_cast<float*>(m_matrix) + 12, position_ptr, 3 * sizeof(float));
		}

		inline void set_angles_rad(float yaw, float pitch, float roll) noexcept
		{
			float cos_yaw = LND_COS(yaw);
			float sin_yaw = LND_SIN(yaw);

			float cos_pitch = LND_COS(pitch);
			float sin_pitch = LND_SIN(pitch);

			float cos_roll = LND_COS(roll);
			float sin_roll = LND_SIN(roll);

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
		inline void set_angles_deg(float yaw, float pitch, float roll) noexcept
		{
			constexpr float coeff = 3.14159265358979f / 180.0f;

			yaw *= coeff;
			pitch *= coeff;
			roll *= coeff;

			float cos_yaw = LND_COS(yaw);
			float sin_yaw = LND_SIN(yaw);

			float cos_pitch = LND_COS(pitch);
			float sin_pitch = LND_SIN(pitch);

			float cos_roll = LND_COS(roll);
			float sin_roll = LND_SIN(roll);

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


#endif // LOOPNDISPLAY_H


// loopndisplay.h
// 
// This is free software released into the public domain.
// 
// Anyone is free to copy, modify, publish, use, compile, sell, or
// distribute this software for any purpose and by any means.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
// IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
// OTHER LIABILITY IN CONNECTION WITH THE SOFTWARE.
