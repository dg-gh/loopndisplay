// loopndisplay.h - last update : 31 / 08 / 2020
// License <http://unlicense.org/> (statement below at the end of the file)

// Needs GLFW and GLEW installed
// https://www.glfw.org/
// http://glew.sourceforge.net/


#ifndef LOOPNDISPLAY_H
#define LOOPNDISPLAY_H


////// OPTIONS //////

#ifndef LND_ARRAY
#define LND_ARRAY std::array
#endif // LND_ARRAY


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
#include <condition_variable>
#include <iostream>


////// IMPLEMENTATION //////


namespace lnd
{
    class user_key_input
    {

    public:

        bool mouse_1 = false;
        bool mouse_2 = false;
        bool mouse_3 = false;
        bool mouse_4 = false;
        bool mouse_5 = false;
        bool mouse_6 = false;
        bool mouse_7 = false;
        bool mouse_8 = false;

        bool space = false;
        bool apostrophe = false;
        bool comma = false;
        bool minus = false;
        bool period = false;
        bool slash = false;

        bool A = false;
        bool B = false;
        bool C = false;
        bool D = false;
        bool E = false;
        bool F = false;
        bool G = false;
        bool H = false;
        bool I = false;
        bool J = false;
        bool K = false;
        bool L = false;
        bool M = false;
        bool N = false;
        bool O = false;
        bool P = false;
        bool Q = false;
        bool R = false;
        bool S = false;
        bool T = false;
        bool U = false;
        bool V = false;
        bool W = false;
        bool X = false;
        bool Y = false;
        bool Z = false;

        bool num0 = false;
        bool num1 = false;
        bool num2 = false;
        bool num3 = false;
        bool num4 = false;
        bool num5 = false;
        bool num6 = false;
        bool num7 = false;
        bool num8 = false;
        bool num9 = false;

        bool escape = false;
        bool enter = false;
        bool tab = false;
        bool backspace = false;
        bool insert = false;
        bool delete_ = false;
        bool right = false;
        bool left = false;
        bool down = false;
        bool up = false;
        bool alt = false;
        bool shift = false;


        int padding[8] = { 0 };

        inline void reset_keys() { memset(this, 0, sizeof(lnd::user_key_input)); }
    };

    class user_mouse_input
    {

    public:

        double X_shift = 0.0;
        double Y_shift = 0.0;
        double X_scale = 1.0;
        double Y_scale = 1.0;

        float mouse_X = 0.0;
        float mouse_Y = 0.0;

    };


    // INSTANCES

    lnd::user_key_input __user_key_input;
    lnd::user_mouse_input __user_mouse_input;


    // ON CALLBACK

    void key_callback(GLFWwindow* window_ptr, int key, int scancode, int action, int mods)
    {
        switch (key)
        {

        case GLFW_KEY_SPACE:
            lnd::__user_key_input.space = true;
            break;
        case GLFW_KEY_APOSTROPHE:
            lnd::__user_key_input.apostrophe = true;
            break;
        case GLFW_KEY_COMMA:
            lnd::__user_key_input.comma = true;
            break;
        case GLFW_KEY_MINUS:
            lnd::__user_key_input.minus = true;
            break;
        case GLFW_KEY_PERIOD:
            lnd::__user_key_input.period = true;
            break;
        case GLFW_KEY_SLASH:
            lnd::__user_key_input.slash = true;
            break;
        case GLFW_KEY_A:
            lnd::__user_key_input.A = true;
            break;
        case GLFW_KEY_B:
            lnd::__user_key_input.B = true;
            break;
        case GLFW_KEY_C:
            lnd::__user_key_input.C = true;
            break;
        case GLFW_KEY_D:
            lnd::__user_key_input.D = true;
            break;
        case GLFW_KEY_E:
            lnd::__user_key_input.E = true;
            break;
        case GLFW_KEY_F:
            lnd::__user_key_input.F = true;
            break;
        case GLFW_KEY_G:
            lnd::__user_key_input.G = true;
            break;
        case GLFW_KEY_H:
            lnd::__user_key_input.H = true;
            break;
        case GLFW_KEY_I:
            lnd::__user_key_input.I = true;
            break;
        case GLFW_KEY_J:
            lnd::__user_key_input.J = true;
            break;
        case GLFW_KEY_K:
            lnd::__user_key_input.K = true;
            break;
        case GLFW_KEY_L:
            lnd::__user_key_input.L = true;
            break;
        case GLFW_KEY_M:
            lnd::__user_key_input.M = true;
            break;
        case GLFW_KEY_N:
            lnd::__user_key_input.N = true;
            break;
        case GLFW_KEY_O:
            lnd::__user_key_input.O = true;
            break;
        case GLFW_KEY_P:
            lnd::__user_key_input.P = true;
            break;
        case GLFW_KEY_Q:
            lnd::__user_key_input.Q = true;
            break;
        case GLFW_KEY_R:
            lnd::__user_key_input.R = true;
            break;
        case GLFW_KEY_S:
            lnd::__user_key_input.S = true;
            break;
        case GLFW_KEY_T:
            lnd::__user_key_input.T = true;
            break;
        case GLFW_KEY_U:
            lnd::__user_key_input.U = true;
            break;
        case GLFW_KEY_V:
            lnd::__user_key_input.V = true;
            break;
        case GLFW_KEY_W:
            lnd::__user_key_input.W = true;
            break;
        case GLFW_KEY_X:
            lnd::__user_key_input.X = true;
            break;
        case GLFW_KEY_Y:
            lnd::__user_key_input.Y = true;
            break;
        case GLFW_KEY_Z:
            lnd::__user_key_input.Z = true;
            break;
        case GLFW_KEY_0:
            lnd::__user_key_input.num0 = true;
            break;
        case GLFW_KEY_1:
            lnd::__user_key_input.num1 = true;
            break;
        case GLFW_KEY_2:
            lnd::__user_key_input.num2 = true;
            break;
        case GLFW_KEY_3:
            lnd::__user_key_input.num3 = true;
            break;
        case GLFW_KEY_4:
            lnd::__user_key_input.num4 = true;
            break;
        case GLFW_KEY_5:
            lnd::__user_key_input.num5 = true;
            break;
        case GLFW_KEY_6:
            lnd::__user_key_input.num6 = true;
            break;
        case GLFW_KEY_7:
            lnd::__user_key_input.num7 = true;
            break;
        case GLFW_KEY_8:
            lnd::__user_key_input.num8 = true;
            break;
        case GLFW_KEY_9:
            lnd::__user_key_input.num9 = true;
            break;
        case GLFW_KEY_ESCAPE:
            lnd::__user_key_input.escape = true;
            break;
        case GLFW_KEY_ENTER:
            lnd::__user_key_input.enter = true;
            break;
        case GLFW_KEY_TAB:
            lnd::__user_key_input.tab = true;
            break;
        case GLFW_KEY_BACKSPACE:
            lnd::__user_key_input.backspace = true;
            break;
        case GLFW_KEY_INSERT:
            lnd::__user_key_input.insert = true;
            break;
        case GLFW_KEY_DELETE:
            lnd::__user_key_input.delete_ = true;
            break;
        case GLFW_KEY_RIGHT:
            lnd::__user_key_input.right = true;
            break;
        case GLFW_KEY_LEFT:
            lnd::__user_key_input.left = true;
            break;
        case GLFW_KEY_DOWN:
            lnd::__user_key_input.down = true;
            break;
        case GLFW_KEY_UP:
            lnd::__user_key_input.up = true;
            break;
        case GLFW_KEY_LEFT_ALT:
            lnd::__user_key_input.alt = true;
            break;
        case GLFW_KEY_LEFT_SHIFT:
            lnd::__user_key_input.shift = true;
            break;
        case GLFW_KEY_RIGHT_ALT:
            lnd::__user_key_input.alt = true;
            break;
        case GLFW_KEY_RIGHT_SHIFT:
            lnd::__user_key_input.shift = true;
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
            lnd::__user_key_input.mouse_1 = true;
            break;
        case GLFW_MOUSE_BUTTON_2:
            lnd::__user_key_input.mouse_2 = true;
            break;
        case GLFW_MOUSE_BUTTON_3:
            lnd::__user_key_input.mouse_3 = true;
            break;
        case GLFW_MOUSE_BUTTON_4:
            lnd::__user_key_input.mouse_4 = true;
            break;
        case GLFW_MOUSE_BUTTON_5:
            lnd::__user_key_input.mouse_5 = true;
            break;
        case GLFW_MOUSE_BUTTON_6:
            lnd::__user_key_input.mouse_6 = true;
            break;
        case GLFW_MOUSE_BUTTON_7:
            lnd::__user_key_input.mouse_7 = true;
            break;
        case GLFW_MOUSE_BUTTON_8:
            lnd::__user_key_input.mouse_8 = true;
            break;

        default:
            break;
        }
    }
    void mouse_position_callback(GLFWwindow* window_ptr, double input_mouse_X, double input_mouse_Y)
    {
        lnd::__user_mouse_input.mouse_X = static_cast<float>(lnd::__user_mouse_input.X_scale * (input_mouse_X - lnd::__user_mouse_input.X_shift));
        lnd::__user_mouse_input.mouse_Y = static_cast<float>(lnd::__user_mouse_input.Y_scale * (lnd::__user_mouse_input.Y_shift - input_mouse_Y));
    }
}


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
        buffer_vertex(buffer_vertex&&) = delete;
        buffer_vertex& operator=(const buffer_vertex&) = delete;
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
        buffer_color(buffer_color&&) = delete;
        buffer_color& operator=(const buffer_color&) = delete;
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
        buffer_index(buffer_index&&) = delete;
        buffer_index& operator=(const buffer_index&) = delete;
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
        buffer_texture(buffer_texture&&) = delete;
        buffer_texture& operator=(const buffer_texture&) = delete;
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
        shader_vertex(shader_vertex&&) = delete;
        shader_vertex& operator=(const shader_vertex&) = delete;
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
        shader_fragment(shader_fragment&&) = delete;
        shader_fragment& operator=(const shader_fragment&) = delete;
        shader_fragment& operator=(shader_fragment&&) = delete;
    };

    class program_vertex_fragment
    {

    private:

        unsigned int program_index = 0;
        unsigned int vertex_shader_index = 0;
        unsigned int fragment_shader_index = 0;

    public:

        program_vertex_fragment() = default;
        ~program_vertex_fragment() { delete_program(); }

        inline const unsigned int get() const noexcept { return program_index; }

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

        program_vertex_fragment(const program_vertex_fragment&) = delete;
        program_vertex_fragment(program_vertex_fragment&&) = delete;
        program_vertex_fragment& operator=(const program_vertex_fragment&) = delete;
        program_vertex_fragment& operator=(program_vertex_fragment&&) = delete;
    };

    buffer_vertex __default_vertex_buffer;
    buffer_index __default_index_buffer;
    buffer_color __default_color_buffer;
    buffer_vertex __default_texture_coord_buffer;
}


namespace lnd
{
    class looper
    {
        // API

        // write the following methods in a derived class (looper_derived_class for an example)
        // putting the looper as protected:

        // void setup() { your code here in the derived class ... }
        // inline void loop(float time_elapsed) { your code here in the derived class ... }
        // inline void display() { your code here in the derived class ... }
        // void exit() { your code here in the derived class ... }
        // inline bool exit_condition() { your code here in the derived class ... }

        // the method call_display() runs the method display(), preferably call in the loop(float time_elapsed) method


        // as an example, you can enter the following code in the main:

        // lnd::window<looper_derived_class> window_example;
        // window_example.show(640, 480, true, 100, "My program !");

    protected:

        // calling a new frame to display

        inline void call_display()
        {
            display_condition_var.notify_one();
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

        inline bool mouse_1() const noexcept { return lnd::__user_key_input.mouse_1; }
        inline bool mouse_2() const noexcept { return lnd::__user_key_input.mouse_2; }
        inline bool mouse_3() const noexcept { return lnd::__user_key_input.mouse_3; }
        inline bool mouse_4() const noexcept { return lnd::__user_key_input.mouse_4; }
        inline bool mouse_5() const noexcept { return lnd::__user_key_input.mouse_5; }
        inline bool mouse_6() const noexcept { return lnd::__user_key_input.mouse_6; }
        inline bool mouse_7() const noexcept { return lnd::__user_key_input.mouse_7; }
        inline bool mouse_8() const noexcept { return lnd::__user_key_input.mouse_8; }

        inline bool key_space() const noexcept { return lnd::__user_key_input.space; }
        inline bool key_apostrophe() const noexcept { return lnd::__user_key_input.apostrophe; }
        inline bool key_comma() const noexcept { return lnd::__user_key_input.comma; }
        inline bool key_minus() const noexcept { return lnd::__user_key_input.minus; }
        inline bool key_period() const noexcept { return lnd::__user_key_input.period; }
        inline bool key_slash() const noexcept { return lnd::__user_key_input.slash; }

        inline bool key_A() const noexcept { return lnd::__user_key_input.A; }
        inline bool key_B() const noexcept { return lnd::__user_key_input.B; }
        inline bool key_C() const noexcept { return lnd::__user_key_input.C; }
        inline bool key_D() const noexcept { return lnd::__user_key_input.D; }
        inline bool key_E() const noexcept { return lnd::__user_key_input.E; }
        inline bool key_F() const noexcept { return lnd::__user_key_input.F; }
        inline bool key_G() const noexcept { return lnd::__user_key_input.G; }
        inline bool key_H() const noexcept { return lnd::__user_key_input.H; }
        inline bool key_I() const noexcept { return lnd::__user_key_input.I; }
        inline bool key_J() const noexcept { return lnd::__user_key_input.J; }
        inline bool key_K() const noexcept { return lnd::__user_key_input.K; }
        inline bool key_L() const noexcept { return lnd::__user_key_input.L; }
        inline bool key_M() const noexcept { return lnd::__user_key_input.M; }
        inline bool key_N() const noexcept { return lnd::__user_key_input.N; }
        inline bool key_O() const noexcept { return lnd::__user_key_input.O; }
        inline bool key_P() const noexcept { return lnd::__user_key_input.P; }
        inline bool key_Q() const noexcept { return lnd::__user_key_input.Q; }
        inline bool key_R() const noexcept { return lnd::__user_key_input.R; }
        inline bool key_S() const noexcept { return lnd::__user_key_input.S; }
        inline bool key_T() const noexcept { return lnd::__user_key_input.T; }
        inline bool key_U() const noexcept { return lnd::__user_key_input.U; }
        inline bool key_V() const noexcept { return lnd::__user_key_input.V; }
        inline bool key_W() const noexcept { return lnd::__user_key_input.W; }
        inline bool key_X() const noexcept { return lnd::__user_key_input.X; }
        inline bool key_Y() const noexcept { return lnd::__user_key_input.Y; }
        inline bool key_Z() const noexcept { return lnd::__user_key_input.Z; }

        inline bool key_0() const noexcept { return __user_key_input.num0; }
        inline bool key_1() const noexcept { return __user_key_input.num1; }
        inline bool key_2() const noexcept { return __user_key_input.num2; }
        inline bool key_3() const noexcept { return __user_key_input.num3; }
        inline bool key_4() const noexcept { return __user_key_input.num4; }
        inline bool key_5() const noexcept { return __user_key_input.num5; }
        inline bool key_6() const noexcept { return __user_key_input.num6; }
        inline bool key_7() const noexcept { return __user_key_input.num7; }
        inline bool key_8() const noexcept { return __user_key_input.num8; }
        inline bool key_9() const noexcept { return __user_key_input.num9; }

        inline bool key_escape() const noexcept { return __user_key_input.escape; }
        inline bool key_enter() const noexcept { return __user_key_input.enter; }
        inline bool key_tab() const noexcept { return __user_key_input.tab; }
        inline bool key_backspace() const noexcept { return __user_key_input.backspace; }
        inline bool key_insert() const noexcept { return __user_key_input.insert; }
        inline bool key_delete() const noexcept { return __user_key_input.delete_; }
        inline bool key_right() const noexcept { return __user_key_input.right; }
        inline bool key_left() const noexcept { return __user_key_input.left; }
        inline bool key_down() const noexcept { return __user_key_input.down; }
        inline bool key_up() const noexcept { return __user_key_input.up; }
        inline bool key_alt() const noexcept { return __user_key_input.alt; }
        inline bool key_shift() const noexcept { return __user_key_input.shift; }

        inline void reset_keys() const noexcept { lnd::__user_key_input.reset_keys(); }


        // WINDOW INFOS

        inline int screen_width() const noexcept { return _screen_width; }
        inline int screen_height() const noexcept { return _screen_height; }
        inline int timeframe_ms() const noexcept { return _timeframe_ms; }
        inline float screen_ratio() const noexcept { return _screen_ratio; }
        inline float screen_ratio_inv() const noexcept { return _screen_ratio_inv; }
        inline float min_X() const noexcept { return _min_X; }
        inline float max_X() const noexcept { return _max_X; }
        inline float min_Y() const noexcept { return _min_Y; }
        inline float max_Y() const noexcept { return _max_Y; }
        inline float pixel_X() const noexcept { return _pixel_X; }
        inline float pixel_Y() const noexcept { return _pixel_Y; }

        inline void clear_color(float R, float G, float B)
        {
            glClearColor(R, G, B, 1.0f);
        }


        // BASIC DRAW CALLS

        inline void draw_line(const float* const ptr, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_LINES, 0, 2);
            lnd::__default_vertex_buffer.unbind();
        }
        inline void draw_line_RGB(const float* const ptr, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
            glUseProgram(program_RGB().get());
            glDrawArrays(GL_LINES, 0, 2);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_line_RGBA(const float* const ptr, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(float), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glUseProgram(program_RGBA().get());
            glDrawArrays(GL_LINES, 0, 2);
            glBlendFunc(GL_ONE, GL_ZERO);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_tri(const float* const ptr, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_TRIANGLES, 0, 3);
            lnd::__default_vertex_buffer.unbind();
        }
        inline void draw_tri_hollow(const float* const ptr, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_LINE_LOOP, 0, 3);
            lnd::__default_vertex_buffer.bind();
        }
        inline void draw_tri_RGB(const float* const ptr, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
            glUseProgram(program_RGB().get());
            glDrawArrays(GL_TRIANGLES, 0, 3);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_tri_RGBA(const float* const ptr, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glUseProgram(program_RGBA().get());
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glBlendFunc(GL_ONE, GL_ZERO);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_quad(const float* const ptr, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_QUADS, 0, 4);
            lnd::__default_vertex_buffer.unbind();
        }
        inline void draw_quad_hollow(const float* const ptr, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_LINE_LOOP, 0, 4);
            lnd::__default_vertex_buffer.bind();
        }
        inline void draw_quad_RGB(const float* const ptr, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
            glUseProgram(program_RGB().get());
            glDrawArrays(GL_QUADS, 0, 4);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_quad_RGBA(const float* const ptr, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glUseProgram(program_RGBA().get());
            glDrawArrays(GL_QUADS, 0, 4);
            glBlendFunc(GL_ONE, GL_ZERO);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }

        inline void draw_lines(const float* const ptr, GLsizei vertex_count, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_LINES, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
        }
        inline void draw_lines_RGB(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
            glUseProgram(program_RGB().get());
            glDrawArrays(GL_LINES, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_lines_RGBA(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glUseProgram(program_RGBA().get());
            glDrawArrays(GL_LINES, 0, vertex_count);
            glBlendFunc(GL_ONE, GL_ZERO);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_tris(const float* const ptr, GLsizei vertex_count, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_TRIANGLES, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
        }
        inline void draw_tris_RGB(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
            glUseProgram(program_RGB().get());
            glDrawArrays(GL_TRIANGLES, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_tris_RGBA(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glUseProgram(program_RGBA().get());
            glDrawArrays(GL_TRIANGLES, 0, vertex_count);
            glBlendFunc(GL_ONE, GL_ZERO);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_quads(const float* const ptr, GLsizei vertex_count, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_QUADS, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
        }
        inline void draw_quads_RGB(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
            glUseProgram(program_RGB().get());
            glDrawArrays(GL_QUADS, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_quads_RGBA(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glUseProgram(program_RGBA().get());
            glDrawArrays(GL_QUADS, 0, vertex_count);
            glBlendFunc(GL_ONE, GL_ZERO);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_line_strip(const float* const ptr, GLsizei vertex_count, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
        }
        inline void draw_line_strip_RGB(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
            glUseProgram(program_RGB().get());
            glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_line_strip_RGBA(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glUseProgram(program_RGBA().get());
            glDrawArrays(GL_LINE_STRIP, 0, vertex_count);
            glBlendFunc(GL_ONE, GL_ZERO);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_line_loop(const float* const ptr, GLsizei vertex_count, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
        }
        inline void draw_line_loop_RGB(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
            glUseProgram(program_RGB().get());
            glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_line_loop_RGBA(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glUseProgram(program_RGBA().get());
            glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
            glBlendFunc(GL_ONE, GL_ZERO);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_tri_strip(const float* const ptr, GLsizei vertex_count, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
        }
        inline void draw_tri_strip_RGB(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
            glUseProgram(program_RGB().get());
            glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_tri_strip_RGBA(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glUseProgram(program_RGBA().get());
            glDrawArrays(GL_TRIANGLE_STRIP, 0, vertex_count);
            glBlendFunc(GL_ONE, GL_ZERO);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_tri_fan(const float* const ptr, GLsizei vertex_count, const lnd::program_vertex_fragment& program)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
        }
        inline void draw_tri_fan_RGB(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (3 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
            glUseProgram(program_RGB().get());
            glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }
        inline void draw_tri_fan_RGBA(const float* const ptr, GLsizei vertex_count, const float* const ptr_color)
        {
            lnd::__default_vertex_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (2 * sizeof(float)), ptr, GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            lnd::__default_color_buffer.bind();
            glBufferData(GL_ARRAY_BUFFER, vertex_count * (4 * sizeof(float)), ptr_color, GL_STATIC_DRAW);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glUseProgram(program_RGBA().get());
            glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count);
            glBlendFunc(GL_ONE, GL_ZERO);
            lnd::__default_vertex_buffer.unbind();
            lnd::__default_color_buffer.bind();
        }


        // BASIC SHADERS

        const inline lnd::shader_vertex& vertex_identity() const noexcept { return _vertex_identity; }
        const inline lnd::shader_vertex& vertex_shift() const noexcept { return _vertex_shift; } // mutable
        const inline lnd::shader_vertex& vertex_shift_scale() const noexcept { return _vertex_shift_scale; } // mutable
        const inline lnd::shader_vertex& vertex_shift_rotate() const noexcept { return _vertex_shift_rotate; } // mutable
        const inline lnd::shader_vertex& vertex_affine() const noexcept { return _vertex_affine; } // mutable
        const inline lnd::shader_vertex& vertex_RGB_identity() const noexcept { return _vertex_RGB_identity; }
        const inline lnd::shader_vertex& vertex_RGB_shift() const noexcept { return _vertex_RGB_shift; } // mutable
        const inline lnd::shader_vertex& vertex_RGB_shift_scale() const noexcept { return _vertex_RGB_shift_scale; } // mutable
        const inline lnd::shader_vertex& vertex_RGB_shift_rotate() const noexcept { return _vertex_RGB_shift_rotate; } // mutable
        const inline lnd::shader_vertex& vertex_RGB_affine() const noexcept { return _vertex_RGB_affine; } // mutable
        const inline lnd::shader_vertex& vertex_RGBA_identity() const noexcept { return _vertex_RGBA_identity; }
        const inline lnd::shader_vertex& vertex_RGBA_shift() const noexcept { return _vertex_RGBA_shift; } // mutable
        const inline lnd::shader_vertex& vertex_RGBA_shift_scale() const noexcept { return _vertex_RGBA_shift_scale; } // mutable
        const inline lnd::shader_vertex& vertex_RGBA_shift_rotate() const noexcept { return _vertex_RGBA_shift_rotate; } // mutable
        const inline lnd::shader_vertex& vertex_RGBA_affine() const noexcept { return _vertex_RGBA_affine; } // mutable
        const inline lnd::shader_vertex& vertex_texture_identity() const noexcept { return _vertex_texture_identity; }
        const inline lnd::shader_vertex& vertex_texture_shift() const noexcept { return _vertex_texture_shift; } // mutable
        const inline lnd::shader_vertex& vertex_texture_shift_scale() const noexcept { return _vertex_texture_shift_scale; } // mutable
        const inline lnd::shader_vertex& vertex_texture_shift_rotate() const noexcept { return _vertex_texture_shift_rotate; } // mutable
        const inline lnd::shader_vertex& vertex_texture_affine() const noexcept { return _vertex_texture_affine; } // mutable

        const inline lnd::shader_fragment& fragment_black() const noexcept { return _fragment_black; }
        const inline lnd::shader_fragment& fragment_red() const noexcept { return _fragment_red; }
        const inline lnd::shader_fragment& fragment_green() const noexcept { return _fragment_green; }
        const inline lnd::shader_fragment& fragment_blue() const noexcept { return _fragment_blue; }
        const inline lnd::shader_fragment& fragment_yellow() const noexcept { return _fragment_yellow; }
        const inline lnd::shader_fragment& fragment_magenta() const noexcept { return _fragment_magenta; }
        const inline lnd::shader_fragment& fragment_cyan() const noexcept { return _fragment_cyan; }
        const inline lnd::shader_fragment& fragment_orange() const noexcept { return _fragment_orange; }
        const inline lnd::shader_fragment& fragment_white() const noexcept { return _fragment_white; }
        const inline lnd::shader_fragment& fragment_color() const noexcept { return _fragment_color; } // mutable shader
        const inline lnd::shader_fragment& fragment_RGB() const noexcept { return _fragment_RGB; }
        const inline lnd::shader_fragment& fragment_RGBA() const noexcept { return _fragment_RGBA; }
        const inline lnd::shader_fragment& fragment_texture() const noexcept { return _fragment_texture; }

        const inline lnd::program_vertex_fragment& program_black() const noexcept { return _program_black; }
        const inline lnd::program_vertex_fragment& program_red() const noexcept { return _program_red; }
        const inline lnd::program_vertex_fragment& program_green() const noexcept { return _program_green; }
        const inline lnd::program_vertex_fragment& program_blue() const noexcept { return _program_blue; }
        const inline lnd::program_vertex_fragment& program_yellow() const noexcept { return _program_yellow; }
        const inline lnd::program_vertex_fragment& program_magenta() const noexcept { return _program_magenta; }
        const inline lnd::program_vertex_fragment& program_cyan() const noexcept { return _program_cyan; }
        const inline lnd::program_vertex_fragment& program_orange() const noexcept { return _program_orange; }
        const inline lnd::program_vertex_fragment& program_white() const noexcept { return _program_white; }
        const inline lnd::program_vertex_fragment& program_color() const noexcept { return _program_color; } // mutable program
        const inline lnd::program_vertex_fragment& program_RGB() const noexcept { return _program_RGB; }
        const inline lnd::program_vertex_fragment& program_RGBA() const noexcept { return _program_RGBA; }
        const inline lnd::program_vertex_fragment& program_texture() const noexcept { return _program_texture; }

        inline const lnd::program_vertex_fragment& set_fragment_color(const lnd::program_vertex_fragment& program, float c0, float c1, float c2, float c3)
        {
            glUseProgram(program.get());
            int location = glGetUniformLocation(program.get(), "u_C");
            glUniform4f(location, c0, c1, c2, c3);
            return program;
        }
        inline const lnd::program_vertex_fragment& set_vertex_shift(const lnd::program_vertex_fragment& program, float T0, float T1)
        {
            glUseProgram(program.get());
            int location = glGetUniformLocation(program.get(), "u_X");
            glUniform2f(location, T0, T1);
            return program;
        }
        inline const lnd::program_vertex_fragment& set_vertex_shift_scale(const lnd::program_vertex_fragment& program, float T0, float T1, float scale)
        {
            glUseProgram(program.get());
            int location = glGetUniformLocation(program.get(), "u_X");
            glUniform3f(location, T0, T1, scale);
            return program;
        }
        inline const lnd::program_vertex_fragment& set_vertex_shift_rotate_rad(const lnd::program_vertex_fragment& program, float T0, float T1, float angle)
        {
            float C = std::cosf(angle);
            float S = std::sinf(angle);
            glUseProgram(program.get());
            int location = glGetUniformLocation(program.get(), "u_X");
            glUniform4f(location, T0, T1, C, S);
            return program;
        }
        inline const lnd::program_vertex_fragment& set_vertex_shift_rotate_deg(const lnd::program_vertex_fragment& program, float T0, float T1, float angle)
        {
            constexpr float deg_to_float = 3.14159265358979323846f / 180.0f;
            angle *= deg_to_float;
            float C = std::cosf(angle);
            float S = std::sinf(angle);
            glUseProgram(program.get());
            int location = glGetUniformLocation(program.get(), "u_X");
            glUniform4f(location, T0, T1, C, S);
            return program;
        }
        inline const lnd::program_vertex_fragment& set_vertex_affine(const lnd::program_vertex_fragment& program,
            float T0, float T1, float orig0, float orig1, float A00, float A10, float A01, float A11)
        {
            glUseProgram(program.get());
            int location0 = glGetUniformLocation(program.get(), "u_X0");
            glUniform4f(location0, T0, T1, orig0, orig1);
            int location1 = glGetUniformLocation(program.get(), "u_X1");
            glUniform4f(location1, A00, A10, A01, A11);
            return program;
        }


        // CONSTRUCTORS AND DESTRUCTORS

        looper() = default;
        ~looper() = default;
        looper(const looper&) = default;
        looper(looper&&) = default;
        looper& operator=(const looper&) = default;
        looper& operator=(looper&&) = default;


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
        int _timeframe_ms = 100;
        float _screen_ratio = 1.0f;
        float _screen_ratio_inv = 1.0f;
        float _min_X = -1.0f;
        float _max_X = 1.0f;
        float _min_Y = -1.0f;
        float _max_Y = 1.0f;
        float _pixel_X = 0.01f;
        float _pixel_Y = 0.01f;


        unsigned int tri_hollow_index[6] = { 0, 1, 1, 2, 2, 0 };
        unsigned int quad_hollow_index[8] = { 0, 1, 1, 2, 2, 3, 3, 0 };

        lnd::shader_vertex _vertex_identity;
        lnd::shader_vertex _vertex_shift; // mutable
        lnd::shader_vertex _vertex_shift_scale; // mutable
        lnd::shader_vertex _vertex_shift_rotate; // mutable
        lnd::shader_vertex _vertex_affine; // mutable

        lnd::shader_vertex _vertex_RGB_identity;
        lnd::shader_vertex _vertex_RGB_shift; // mutable
        lnd::shader_vertex _vertex_RGB_shift_scale; // mutable
        lnd::shader_vertex _vertex_RGB_shift_rotate; // mutable
        lnd::shader_vertex _vertex_RGB_affine; // mutable

        lnd::shader_vertex _vertex_RGBA_identity;
        lnd::shader_vertex _vertex_RGBA_shift; // mutable
        lnd::shader_vertex _vertex_RGBA_shift_scale; // mutable
        lnd::shader_vertex _vertex_RGBA_shift_rotate; // mutable
        lnd::shader_vertex _vertex_RGBA_affine; // mutable

        lnd::shader_vertex _vertex_texture_identity;
        lnd::shader_vertex _vertex_texture_shift; // mutable
        lnd::shader_vertex _vertex_texture_shift_scale; // mutable
        lnd::shader_vertex _vertex_texture_shift_rotate; // mutable
        lnd::shader_vertex _vertex_texture_affine; // mutable

        lnd::shader_fragment _fragment_black;
        lnd::shader_fragment _fragment_red;
        lnd::shader_fragment _fragment_green;
        lnd::shader_fragment _fragment_blue;
        lnd::shader_fragment _fragment_yellow;
        lnd::shader_fragment _fragment_magenta;
        lnd::shader_fragment _fragment_cyan;
        lnd::shader_fragment _fragment_orange;
        lnd::shader_fragment _fragment_white;
        lnd::shader_fragment _fragment_color; // mutable
        lnd::shader_fragment _fragment_RGB;
        lnd::shader_fragment _fragment_RGBA;
        lnd::shader_fragment _fragment_texture;

        lnd::program_vertex_fragment _program_black;
        lnd::program_vertex_fragment _program_red;
        lnd::program_vertex_fragment _program_green;
        lnd::program_vertex_fragment _program_blue;
        lnd::program_vertex_fragment _program_yellow;
        lnd::program_vertex_fragment _program_magenta;
        lnd::program_vertex_fragment _program_cyan;
        lnd::program_vertex_fragment _program_orange;
        lnd::program_vertex_fragment _program_white;
        lnd::program_vertex_fragment _program_color;
        lnd::program_vertex_fragment _program_RGB;
        lnd::program_vertex_fragment _program_RGBA;
        lnd::program_vertex_fragment _program_texture;

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
        void _setup_basic_infos(int new_screen_width, int new_screen_height, bool rescale_screen_coordinates, int timeframe_ms)
        {
            _screen_width = new_screen_width;
            _screen_height = new_screen_height;
            _timeframe_ms = timeframe_ms;
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
            if (rescale_screen_coordinates)
            {
                if (_screen_width >= _screen_height)
                {
                    std::string ratio = std::to_string(_screen_ratio_inv);

                    _vertex_identity.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * X[0], X[1], X[2], X[3]); }      \n"
                    );

                    _vertex_shift.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   uniform vec2 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * (X[0] + u_X[0]),                \n"
                        "       X[1] + u_X[1],                                  \n"
                        "       X[2], X[3]); }                                  \n"
                    );

                    _vertex_shift_scale.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   uniform vec3 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * (u_X[2] * X[0] + u_X[0]),       \n"
                        "       u_X[2] * X[1] + u_X[1],                         \n"
                        "       X[2], X[3]); }                                  \n"
                    );

                    _vertex_shift_rotate.new_shader(std::string("") +
                        "   #version 330 core                                               \n"
                        "   layout (location = 0) in vec4 X;                                \n"
                        "   uniform vec4 u_X;                                               \n"
                        "   void main() { gl_Position = vec4(                               \n"
                        "       " + ratio + " * (u_X[2] * X[0] - u_X[3] * X[1] + u_X[0]),   \n"
                        "       u_X[3] * X[0] + u_X[2] * X[1] + u_X[1],                     \n"
                        "       X[2], X[3]); }                                              \n"
                    );

                    _vertex_affine.new_shader(std::string("") +
                        "   #version 330 core                                                                           \n"
                        "   layout (location = 0) in vec4 X;                                                            \n"
                        "   uniform vec4 u_X0;                                                                          \n"
                        "   uniform vec4 u_X1;                                                                          \n"
                        "   void main() { gl_Position  = vec4(                                                          \n"
                        "       " + ratio + " * (u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3]))),  \n"
                        "       u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3])),                    \n"
                        "       X[2], X[3]); }                                                                          \n"
                    );

                    _vertex_RGB_identity.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec3 C;                    \n"
                        "   out vec3 forward_C;                                 \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * X[0], X[1], X[2], X[3]);        \n"
                        "       forward_C = C; }                                \n"
                    );

                    _vertex_RGB_shift.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec3 C;                    \n"
                        "   out vec3 forward_C;                                 \n"
                        "   uniform vec2 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * (X[0] + u_X[0]),                \n"
                        "       X[1] + u_X[1],                                  \n"
                        "       X[2], X[3]); forward_C = C; }                   \n"
                    );

                    _vertex_RGB_shift_scale.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec3 C;                    \n"
                        "   out vec3 forward_C;                                 \n"
                        "   uniform vec3 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * (u_X[2] * X[0] + u_X[0]),       \n"
                        "       u_X[2] * X[1] + u_X[1],                         \n"
                        "       X[2], X[3]); forward_C = C; }                   \n"
                    );

                    _vertex_RGB_shift_rotate.new_shader(std::string("") +
                        "   #version 330 core                                               \n"
                        "   layout (location = 0) in vec4 X;                                \n"
                        "   layout (location = 1) in vec3 C;                                \n"
                        "   out vec3 forward_C;                                             \n"
                        "   uniform vec4 u_X;                                               \n"
                        "   void main() { gl_Position = vec4(                               \n"
                        "       " + ratio + " * (u_X[2] * X[0] - u_X[3] * X[1] + u_X[0]),   \n"
                        "       u_X[3] * X[0] + u_X[2] * X[1] + u_X[1],                     \n"
                        "       X[2], X[3]); forward_C = C; }                               \n"
                    );

                    _vertex_RGB_affine.new_shader(std::string("") +
                        "   #version 330 core                                                                           \n"
                        "   layout (location = 0) in vec4 X;                                                            \n"
                        "   layout (location = 1) in vec3 C;                                                            \n"
                        "   uniform vec4 u_X0;                                                                          \n"
                        "   uniform vec4 u_X1;                                                                          \n"
                        "   out vec3 forward_C;                                                                         \n"
                        "   void main() { gl_Position  = vec4(                                                          \n"
                        "       " + ratio + " * (u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3]))),  \n"
                        "       u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3])),                    \n"
                        "       X[2], X[3]); forward_C = C; }                                                           \n"
                    );

                    _vertex_RGBA_identity.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec4 C;                    \n"
                        "   out vec4 forward_C;                                 \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * X[0], X[1], X[2], X[3]);        \n"
                        "       forward_C = C; }                                \n"
                    );

                    _vertex_RGBA_shift.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec4 C;                    \n"
                        "   out vec4 forward_C;                                 \n"
                        "   uniform vec2 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * (X[0] + u_X[0]),                \n"
                        "       X[1] + u_X[1],                                  \n"
                        "       X[2], X[3]); forward_C = C; }                   \n"
                    );

                    _vertex_RGBA_shift_scale.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec4 C;                    \n"
                        "   out vec4 forward_C;                                 \n"
                        "   uniform vec4 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * (u_X[2] * X[0] + u_X[0]),       \n"
                        "       u_X[2] * X[1] + u_X[1],                         \n"
                        "       X[2], X[3]); forward_C = C; }                   \n"
                    );

                    _vertex_RGBA_shift_rotate.new_shader(std::string("") +
                        "   #version 330 core                                               \n"
                        "   layout (location = 0) in vec4 X;                                \n"
                        "   layout (location = 1) in vec4 C;                                \n"
                        "   out vec4 forward_C;                                             \n"
                        "   uniform vec4 u_X;                                               \n"
                        "   void main() { gl_Position = vec4(                               \n"
                        "       " + ratio + " * (u_X[2] * X[0] - u_X[3] * X[1] + u_X[0]),   \n"
                        "       u_X[3] * X[0] + u_X[2] * X[1] + u_X[1],                     \n"
                        "       X[2], X[3]); forward_C = C; }                               \n"
                    );

                    _vertex_RGBA_affine.new_shader(std::string("") +
                        "   #version 330 core                                                                           \n"
                        "   layout (location = 0) in vec4 X;                                                            \n"
                        "   layout (location = 1) in vec4 C;                                                            \n"
                        "   uniform vec4 u_X0;                                                                          \n"
                        "   uniform vec4 u_X1;                                                                          \n"
                        "   out vec4 forward_C;                                                                         \n"
                        "   void main() { gl_Position  = vec4(                                                          \n"
                        "       " + ratio + " * (u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3]))),  \n"
                        "       u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3])),                    \n"
                        "       X[2], X[3]); forward_C = C; }                                                           \n"
                    );

                    _vertex_texture_identity.new_shader(
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec2 UV;                   \n"
                        "   out vec2 forward_UV;                                \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * X[0], X[1], X[2], X[3]);        \n"
                        "	    forward_UV = UV; }                              \n"
                    );

                    _vertex_texture_shift.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec2 UV;                   \n"
                        "   out vec2 forward_UV;                                \n"
                        "   uniform vec2 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * (X[0] + u_X[0]),                \n"
                        "       X[1] + u_X[1],                                  \n"
                        "       X[2], X[3]); forward_UV = UV; }                 \n"
                    );

                    _vertex_texture_shift_scale.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec2 UV;                   \n"
                        "   out vec2 forward_UV;                                \n"
                        "   uniform vec3 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       " + ratio + " * (u_X[2] * X[0] + u_X[0]),       \n"
                        "       u_X[2] * X[1] + u_X[1],                         \n"
                        "       X[2], X[3]); forward_UV = UV; }                 \n"
                    );

                    _vertex_texture_shift_rotate.new_shader(std::string("") +
                        "   #version 330 core                                               \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec2 UV;                   \n"
                        "   out vec2 forward_UV;                                \n"
                        "   uniform vec4 u_X;                                               \n"
                        "   void main() { gl_Position = vec4(                               \n"
                        "       " + ratio + " * (u_X[2] * X[0] - u_X[3] * X[1] + u_X[0]),   \n"
                        "       u_X[3] * X[0] + u_X[2] * X[1] + u_X[1],                     \n"
                        "       X[2], X[3]); forward_UV = UV; }                             \n"
                    );

                    _vertex_texture_affine.new_shader(std::string("") +
                        "   #version 330 core                                                                           \n"
                        "   layout (location = 0) in vec4 X;                                                            \n"
                        "   layout (location = 1) in vec2 UV;                                                           \n"
                        "   out vec2 forward_UV;                                                                        \n"
                        "   uniform vec4 u_X0;                                                                          \n"
                        "   uniform vec4 u_X1;                                                                          \n"
                        "   void main() { gl_Position  = vec4(                                                          \n"
                        "       " + ratio + " * (u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3]))),  \n"
                        "       u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3])),                    \n"
                        "       X[2], X[3]); forward_UV = UV; }                                                         \n"
                    );
                }
                else
                {
                    std::string ratio = std::to_string(_screen_ratio);

                    _vertex_identity.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       X[0], " + ratio + " * X[1], X[2], X[3]); }      \n"
                    );

                    _vertex_shift.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   uniform vec2 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       X[0] + u_X[0],                                  \n"
                        "       " + ratio + " * (X[1] + u_X[1]),                \n"
                        "       X[2], X[3]); }                                  \n"
                    );

                    _vertex_shift_scale.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   uniform vec3 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       u_X[2] * X[0] + u_X[0],                         \n"
                        "       " + ratio + " * (u_X[2] * X[1] + u_X[1]),       \n"
                        "       X[2], X[3]); }                                  \n"
                    );

                    _vertex_shift_rotate.new_shader(std::string("") +
                        "   #version 330 core                                               \n"
                        "   layout (location = 0) in vec4 X;                                \n"
                        "   uniform vec4 u_X;                                               \n"
                        "   void main() { gl_Position = vec4(                               \n"
                        "       u_X[2] * X[0] - u_X[3] * X[1] + u_X[0],                     \n"
                        "       " + ratio + " * (u_X[3] * X[0] + u_X[2] * X[1] + u_X[1]),   \n"
                        "       X[2], X[3]); }                                              \n"
                    );

                    _vertex_affine.new_shader(std::string("") +
                        "   #version 330 core                                                                           \n"
                        "   layout (location = 0) in vec4 X;                                                            \n"
                        "   uniform vec4 u_X0;                                                                          \n"
                        "   uniform vec4 u_X1;                                                                          \n"
                        "   void main() { gl_Position  = vec4(                                                          \n"
                        "       u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3])),                    \n"
                        "       " + ratio + " * (u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3]))),  \n"
                        "       X[2], X[3]); }                                                                          \n"
                    );

                    _vertex_RGB_identity.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec3 C;                    \n"
                        "   out vec3 forward_C;                                 \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       X[0], " + ratio + " * X[1], X[2], X[3]);        \n"
                        "       forward_C = C; }                                \n"
                    );

                    _vertex_RGB_shift.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec3 C;                    \n"
                        "   out vec3 forward_C;                                 \n"
                        "   uniform vec2 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       X[0] + u_X[0],                                  \n"
                        "       " + ratio + " * (X[1] + u_X[1]),                \n"
                        "       X[2], X[3]); forward_C = C; }                   \n"
                    );

                    _vertex_RGB_shift_scale.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec3 C;                    \n"
                        "   out vec3 forward_C;                                 \n"
                        "   uniform vec3 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       u_X[2] * X[0] + u_X[0],                         \n"
                        "       " + ratio + " * (u_X[2] * X[1] + u_X[1]),       \n"
                        "       X[2], X[3]); forward_C = C; }                   \n"
                    );

                    _vertex_RGB_shift_rotate.new_shader(std::string("") +
                        "   #version 330 core                                               \n"
                        "   layout (location = 0) in vec4 X;                                \n"
                        "   layout (location = 1) in vec3 C;                                \n"
                        "   out vec3 forward_C;                                             \n"
                        "   uniform vec4 u_X;                                               \n"
                        "   void main() { gl_Position = vec4(                               \n"
                        "       u_X[2] * X[0] - u_X[3] * X[1] + u_X[0],                     \n"
                        "       " + ratio + " * (u_X[3] * X[0] + u_X[2] * X[1] + u_X[1]),   \n"
                        "       X[2], X[3]); forward_C = C; }                               \n"
                    );

                    _vertex_RGB_affine.new_shader(std::string("") +
                        "   #version 330 core                                                                           \n"
                        "   layout (location = 0) in vec4 X;                                                            \n"
                        "   layout (location = 1) in vec3 C;                                                            \n"
                        "   out vec3 forward_C;                                                                         \n"
                        "   uniform vec4 u_X0;                                                                          \n"
                        "   uniform vec4 u_X1;                                                                          \n"
                        "   void main() { gl_Position  = vec4(                                                          \n"
                        "       u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3])),                    \n"
                        "       " + ratio + " * (u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3]))),  \n"
                        "       X[2], X[3]); forward_C = C; }                                                           \n"
                    );

                    _vertex_RGBA_identity.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec4 C;                    \n"
                        "   out vec4 forward_C;                                 \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       X[0], " + ratio + " * X[1], X[2], X[3]);        \n"
                        "       forward_C = C; }                                \n"
                    );

                    _vertex_RGBA_shift.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec4 C;                    \n"
                        "   out vec4 forward_C;                                 \n"
                        "   uniform vec2 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       X[0] + u_X[0],                                  \n"
                        "       " + ratio + " * (X[1] + u_X[1]),                \n"
                        "       X[2], X[3]); forward_C = C; }                   \n"
                    );

                    _vertex_RGBA_shift_scale.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec4 C;                    \n"
                        "   out vec4 forward_C;                                 \n"
                        "   uniform vec4 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       u_X[2] * X[0] + u_X[0],                         \n"
                        "       " + ratio + " * (u_X[2] * X[1] + u_X[1]),       \n"
                        "       X[2], X[3]); forward_C = C; }                   \n"
                    );

                    _vertex_RGBA_shift_rotate.new_shader(std::string("") +
                        "   #version 330 core                                               \n"
                        "   layout (location = 0) in vec4 X;                                \n"
                        "   layout (location = 1) in vec4 C;                                \n"
                        "   out vec4 forward_C;                                             \n"
                        "   uniform vec4 u_X;                                               \n"
                        "   void main() { gl_Position = vec4(                               \n"
                        "       u_X[2] * X[0] - u_X[3] * X[1] + u_X[0],                     \n"
                        "       " + ratio + " * (u_X[3] * X[0] + u_X[2] * X[1] + u_X[1]),   \n"
                        "       X[2], X[3]); forward_C = C; }                               \n"
                    );

                    _vertex_RGBA_affine.new_shader(std::string("") +
                        "   #version 330 core                                                                           \n"
                        "   layout (location = 0) in vec4 X;                                                            \n"
                        "   layout (location = 1) in vec4 C;                                                            \n"
                        "   out vec4 forward_C;                                                                         \n"
                        "   uniform vec4 u_X0;                                                                          \n"
                        "   uniform vec4 u_X1;                                                                          \n"
                        "   void main() { gl_Position  = vec4(                                                          \n"
                        "       u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3])),                    \n"
                        "       " + ratio + " * (u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3]))),  \n"
                        "       X[2], X[3]); forward_C = C; }                                                           \n"
                    );

                    _vertex_texture_identity.new_shader(
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec2 UV;                   \n"
                        "   out vec2 forward_UV;                                \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       X[0], " + ratio + " * X[1], X[2], X[3]);        \n"
                        "	    forward_UV = UV; }                              \n"
                    );

                    _vertex_texture_shift.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec2 UV;                   \n"
                        "   out vec2 forward_UV;                                \n"
                        "   uniform vec2 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       X[0] + u_X[0],                                  \n"
                        "       " + ratio + " * (X[1] + u_X[1]),                \n"
                        "       X[2], X[3]); forward_UV = UV; }                 \n"
                    );

                    _vertex_texture_shift_scale.new_shader(std::string("") +
                        "   #version 330 core                                   \n"
                        "   layout (location = 0) in vec4 X;                    \n"
                        "   layout (location = 1) in vec2 UV;                   \n"
                        "   out vec2 forward_UV;                                \n"
                        "   uniform vec3 u_X;                                   \n"
                        "   void main() { gl_Position = vec4(                   \n"
                        "       u_X[2] * X[0] + u_X[0],                         \n"
                        "       " + ratio + " * (u_X[2] * X[1] + u_X[1]),       \n"
                        "       X[2], X[3]); forward_UV = UV; }                 \n"
                    );

                    _vertex_texture_shift_rotate.new_shader(std::string("") +
                        "   #version 330 core                                               \n"
                        "   layout (location = 0) in vec4 X;                                \n"
                        "   layout (location = 1) in vec2 UV;                               \n"
                        "   out vec2 forward_UV;                                            \n"
                        "   uniform vec4 u_X;                                               \n"
                        "   void main() { gl_Position = vec4(                               \n"
                        "       u_X[2] * X[0] - u_X[3] * X[1] + u_X[0],                     \n"
                        "       " + ratio + " * (u_X[3] * X[0] + u_X[2] * X[1] + u_X[1]),   \n"
                        "       X[2], X[3]); forward_UV = UV; }                             \n"
                    );

                    _vertex_texture_affine.new_shader(std::string("") +
                        "   #version 330 core                                                                           \n"
                        "   layout (location = 0) in vec4 X;                                                            \n"
                        "   layout (location = 1) in vec2 UV;                                                           \n"
                        "   out vec2 forward_UV;                                                                        \n"
                        "   uniform vec4 u_X0;                                                                          \n"
                        "   uniform vec4 u_X1;                                                                          \n"
                        "   void main() { gl_Position  = vec4(                                                          \n"
                        "       u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3])),                    \n"
                        "       " + ratio + " * (u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3]))),  \n"
                        "       X[2], X[3]); forward_UV = UV; }                                                         \n"
                    );
                }
            }
            else
            {
                _vertex_identity.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   void main() { gl_Position = X; }                    \n"
                );

                _vertex_shift.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   uniform vec2 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       X[0] + u_X[0],                                  \n"
                    "       X[1] + u_X[1],                                  \n"
                    "       X[2], X[3]); }                                  \n"
                );

                _vertex_shift_scale.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   uniform vec3 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       u_X[2] * X[0] + u_X[0],                         \n"
                    "       u_X[2] * X[1] + u_X[1],                         \n"
                    "       X[2], X[3]); }                                  \n"
                );

                _vertex_shift_rotate.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   uniform vec4 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       u_X[2] * X[0] - u_X[3] * X[1] + u_X[0],         \n"
                    "       u_X[3] * X[0] + u_X[2] * X[1] + u_X[1],         \n"
                    "       X[2], X[3]); }                                  \n"
                );

                _vertex_affine.new_shader(
                    "   #version 330 core                                                           \n"
                    "   layout (location = 0) in vec4 X;                                            \n"
                    "   uniform vec4 u_X0;                                                          \n"
                    "   uniform vec4 u_X1;                                                          \n"
                    "   void main() { gl_Position  = vec4(                                          \n"
                    "       u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3])),    \n"
                    "       u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3])),    \n"
                    "       X[2], X[3]); }                                                          \n"
                );

                _vertex_RGB_identity.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec3 C;                    \n"
                    "   out vec3 forward_C;                                 \n"
                    "   void main() { gl_Position = X; forward_C = C; }     \n"
                );

                _vertex_RGB_shift.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec3 C;                    \n"
                    "   out vec3 forward_C;                                 \n"
                    "   uniform vec2 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       X[0] + u_X[0],                                  \n"
                    "       X[1] + u_X[1],                                  \n"
                    "       X[2], X[3]); forward_C = C; }                   \n"
                );

                _vertex_RGB_shift_scale.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec3 C;                    \n"
                    "   out vec3 forward_C;                                 \n"
                    "   uniform vec3 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       u_X[2] * X[0] + u_X[0],                         \n"
                    "       u_X[2] * X[1] + u_X[1],                         \n"
                    "       X[2], X[3]); forward_C = C; }                   \n"
                );

                _vertex_RGB_shift_rotate.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec3 C;                    \n"
                    "   out vec3 forward_C;                                 \n"
                    "   uniform vec4 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       u_X[2] * X[0] - u_X[3] * X[1] + u_X[0],         \n"
                    "       u_X[3] * X[0] + u_X[2] * X[1] + u_X[1],         \n"
                    "       X[2], X[3]); forward_C = C; }                   \n"
                );

                _vertex_RGB_affine.new_shader(
                    "   #version 330 core                                                           \n"
                    "   layout (location = 0) in vec4 X;                                            \n"
                    "   layout (location = 1) in vec3 C;                                            \n"
                    "   out vec3 forward_C;                                                         \n"
                    "   uniform vec4 u_X0;                                                          \n"
                    "   uniform vec4 u_X1;                                                          \n"
                    "   void main() { gl_Position  = vec4(                                          \n"
                    "       u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3])),    \n"
                    "       u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3])),    \n"
                    "       X[2], X[3]); forward_C = C; }                                           \n"
                );

                _vertex_RGBA_identity.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec4 C;                    \n"
                    "   out vec4 forward_C;                                 \n"
                    "   void main() { gl_Position = X; forward_C = C; }     \n"
                );

                _vertex_RGBA_shift.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec4 C;                    \n"
                    "   out vec4 forward_C;                                 \n"
                    "   uniform vec2 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       X[0] + u_X[0],                                  \n"
                    "       X[1] + u_X[1],                                  \n"
                    "       X[2], X[3]); forward_C = C; }                   \n"
                );

                _vertex_RGBA_shift_scale.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec4 C;                    \n"
                    "   out vec4 forward_C;                                 \n"
                    "   uniform vec4 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       u_X[2] * X[0] + u_X[0],                         \n"
                    "       u_X[2] * X[1] + u_X[1],                         \n"
                    "       X[2], X[3]); forward_C = C; }                   \n"
                );

                _vertex_RGBA_shift_rotate.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec4 C;                    \n"
                    "   out vec4 forward_C;                                 \n"
                    "   uniform vec4 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       u_X[2] * X[0] - u_X[3] * X[1] + u_X[0],         \n"
                    "       u_X[3] * X[0] + u_X[2] * X[1] + u_X[1],         \n"
                    "       X[2], X[3]); forward_C = C; }                   \n"
                );

                _vertex_RGBA_affine.new_shader(
                    "   #version 330 core                                                           \n"
                    "   layout (location = 0) in vec4 X;                                            \n"
                    "   layout (location = 1) in vec4 C;                                            \n"
                    "   out vec4 forward_C;                                                         \n"
                    "   uniform vec4 u_X0;                                                          \n"
                    "   uniform vec4 u_X1;                                                          \n"
                    "   void main() { gl_Position  = vec4(                                          \n"
                    "       u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3])),    \n"
                    "       u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3])),    \n"
                    "       X[2], X[3]); forward_C = C; }                                           \n"
                );

                _vertex_texture_identity.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec2 UV;                   \n"
                    "   out vec2 forward_UV;                                \n"
                    "   void main() {                                       \n"
                    "	    gl_Position = X;                                \n"
                    "	    forward_UV = UV; }                              \n"
                );

                _vertex_texture_shift.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec2 UV;                   \n"
                    "   out vec2 forward_UV;                                \n"
                    "   uniform vec2 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       X[0] + u_X[0],                                  \n"
                    "       X[1] + u_X[1],                                  \n"
                    "       X[2], X[3]); forward_UV = UV; }                 \n"
                );

                _vertex_texture_shift_scale.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec2 UV;                   \n"
                    "   out vec2 forward_UV;                                \n"
                    "   uniform vec3 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       u_X[2] * X[0] + u_X[0],                         \n"
                    "       u_X[2] * X[1] + u_X[1],                         \n"
                    "       X[2], X[3]); forward_UV = UV; }                 \n"
                );

                _vertex_texture_shift_rotate.new_shader(
                    "   #version 330 core                                   \n"
                    "   layout (location = 0) in vec4 X;                    \n"
                    "   layout (location = 1) in vec2 UV;                   \n"
                    "   out vec2 forward_UV;                                \n"
                    "   uniform vec4 u_X;                                   \n"
                    "   void main() { gl_Position = vec4(                   \n"
                    "       u_X[2] * X[0] - u_X[3] * X[1] + u_X[0],         \n"
                    "       u_X[3] * X[0] + u_X[2] * X[1] + u_X[1],         \n"
                    "       X[2], X[3]); forward_UV = UV; }                 \n"
                );

                _vertex_texture_affine.new_shader(
                    "   #version 330 core                                                           \n"
                    "   layout (location = 0) in vec4 X;                                            \n"
                    "   layout (location = 1) in vec2 UV;                                           \n"
                    "   out vec2 forward_UV;                                                        \n"
                    "   uniform vec4 u_X0;                                                          \n"
                    "   uniform vec4 u_X1;                                                          \n"
                    "   void main() { gl_Position  = vec4(                                          \n"
                    "       u_X0[0] + (u_X1[0] * (X[0] - u_X0[2]) + u_X1[2] * (X[1] - u_X0[3])),    \n"
                    "       u_X0[1] + (u_X1[1] * (X[0] - u_X0[2]) + u_X1[3] * (X[1] - u_X0[3])),    \n"
                    "       X[2], X[3]); forward_UV = UV; }                                         \n"
                );
            }

            _fragment_black.new_shader(
                "   #version 330 core                                   \n"
                "   layout (location = 0) out vec4 C;                   \n"
                "   void main() { C = vec4(0.0, 0.0, 0.0, 1.0); }       \n"
            );

            _fragment_red.new_shader(
                "   #version 330 core                                   \n"
                "   layout (location = 0) out vec4 C;                   \n"
                "   void main() { C = vec4(1.0, 0.0, 0.0, 1.0); }       \n"
            );

            _fragment_green.new_shader(
                "   #version 330 core                                   \n"
                "   layout (location = 0) out vec4 C;                   \n"
                "   void main() { C = vec4(0.0, 1.0, 0.0, 1.0); }       \n"
            );

            _fragment_blue.new_shader(
                "   #version 330 core                                   \n"
                "   layout (location = 0) out vec4 C;                   \n"
                "   void main() { C = vec4(0.0, 0.0, 1.0, 1.0); }       \n"
            );

            _fragment_yellow.new_shader(
                "   #version 330 core                                   \n"
                "   layout (location = 0) out vec4 C;                   \n"
                "   void main() { C = vec4(1.0, 1.0, 0.0, 1.0); }       \n"
            );

            _fragment_magenta.new_shader(
                "   #version 330 core                                   \n"
                "   layout (location = 0) out vec4 C;                   \n"
                "   void main() { C = vec4(1.0, 0.0, 1.0, 1.0); }       \n"
            );

            _fragment_cyan.new_shader(
                "   #version 330 core                                   \n"
                "   layout (location = 0) out vec4 C;                   \n"
                "   void main() { C = vec4(0.0, 1.0, 1.0, 1.0); }       \n"
            );

            _fragment_orange.new_shader(
                "   #version 330 core                                   \n"
                "   layout (location = 0) out vec4 C;                   \n"
                "   void main() { C = vec4(1.0, 0.5, 0.0, 1.0); }       \n"
            );

            _fragment_white.new_shader(
                "   #version 330 core                                   \n"
                "   layout (location = 0) out vec4 C;                   \n"
                "   void main() { C = vec4(1.0, 1.0, 1.0, 1.0); }       \n"
            );

            _fragment_color.new_shader(
                "   #version 330 core                                   \n"
                "   layout (location = 0) out vec4 C;                   \n"
                "   uniform vec4 u_C;                                   \n"
                "   void main() { C = u_C; }                            \n"
            );

            _fragment_RGB.new_shader(
                "#version 330 core                                      \n"
                "in vec3 forward_C;                                     \n"
                "out vec3 color;                                        \n"
                "void main() { color = forward_C; }                     \n"
            );

            _fragment_RGBA.new_shader(
                "#version 330 core                                      \n"
                "in vec4 forward_C;                                     \n"
                "out vec4 color;                                        \n"
                "void main() { color = forward_C; }                     \n"
            );

            _fragment_texture.new_shader(
                "#version 330 core                                      \n"
                "out vec4 C;                                            \n"
                "in vec2 forward_UV;                                    \n"
                "uniform sampler2D Tx;                                  \n"
                "void main() { C = texture(Tx, forward_UV); }           \n"
            );

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
            _program_RGBA.new_program(_vertex_RGBA_identity, _fragment_RGBA);
            _program_texture.new_program(_vertex_texture_identity, _fragment_texture);

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

            _vertex_RGB_identity.delete_shader();
            _vertex_RGB_shift.delete_shader();
            _vertex_RGB_shift_scale.delete_shader();
            _vertex_RGB_shift_rotate.delete_shader();
            _vertex_RGB_affine.delete_shader();

            _vertex_RGBA_identity.delete_shader();
            _vertex_RGBA_shift.delete_shader();
            _vertex_RGBA_shift_scale.delete_shader();
            _vertex_RGBA_shift_rotate.delete_shader();
            _vertex_RGBA_affine.delete_shader();

            _vertex_texture_identity.delete_shader();
            _vertex_texture_shift.delete_shader();
            _vertex_texture_shift_scale.delete_shader();
            _vertex_texture_shift_rotate.delete_shader();
            _vertex_texture_affine.delete_shader();

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
            _program_RGBA.delete_program();
            _program_texture.delete_program();

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
            long long new_timeframe_ms, const char* new_title)
        {
            this->_setup_basic_infos(new_screen_width, new_screen_height,
                rescale_screen_coordinates, static_cast<int>(new_timeframe_ms));

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
            clock_sleep_time = 1000000 * new_timeframe_ms;
            _start = std::chrono::high_resolution_clock::now();

            // loop

            while (!display_running.load()) {}

            lnd::__user_key_input.reset_keys();

            if (new_timeframe_ms != 0)
            {
                while (true)
                {
                    // frame scheduling
                    while ((_stop - _start).count() < clock_sleep_time)
                    {
                        _stop = std::chrono::steady_clock::now();
                    }
                    time_elapsed = 0.000000001f * static_cast<float>((_stop - _start).count());
                    _start = std::chrono::steady_clock::now();

                    // loop content
                    this->loop(time_elapsed);

                    if (this->exit_condition() || glfwWindowShouldClose(window_ptr))
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
                    _stop = std::chrono::steady_clock::now();
                    time_elapsed = 0.000000001f * static_cast<float>((_stop - _start).count());
                    _start = std::chrono::steady_clock::now();

                    // loop content
                    this->loop(time_elapsed);

                    if (this->exit_condition() || glfwWindowShouldClose(window_ptr))
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
            lnd::__user_key_input.reset_keys();
            return true;
        }

        void set_window_resizable(bool _is_window_resizable)
        {
            window_resizable = _is_window_resizable;
        }
        void  set_window_fullscreen(bool _is_window_fullscreen)
        {
            window_fullscreen = _is_window_fullscreen;
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

        window() : window_ptr(nullptr), clock_sleep_time(0), time_elapsed(0) {};
        ~window()
        {
            glfwInit();
            window_ptr = glfwCreateWindow(1, 1, "", nullptr, nullptr);
            glfwDestroyWindow(window_ptr);
            glfwTerminate();
            static_cast<_looper*>(static_cast<void*>(this))->~_looper();
        }
        window(const window&) = default;
        window(window&&) = default;
        window& operator=(const window&) = default;
        window& operator=(window&&) = default;

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

            if (window_fullscreen) { window_ptr = glfwCreateWindow(new_screen_width, new_screen_height, new_title, glfwGetPrimaryMonitor(), nullptr); }
            else { window_ptr = glfwCreateWindow(new_screen_width, new_screen_height, new_title, nullptr, nullptr); }

            if (window_ptr == nullptr)
            {
                glfwTerminate();
                display_init_failed.store(true);
                display_init_finished.store(true);
                return;
            }
            glfwMakeContextCurrent(window_ptr);
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

            glfwSetKeyCallback(window_ptr, &lnd::key_callback);
            glfwSetMouseButtonCallback(window_ptr, &lnd::mouse_button_callback);
            glfwSetCursorPosCallback(window_ptr, &lnd::mouse_position_callback);

            this->_setup_basic_shaders_and_buffers(rescale_screen_coordinates);
            this->setup();
            display_running.store(true);

            //  display

            glEnable(GL_BLEND);
            glBlendFunc(GL_ONE, GL_ZERO);

            lnd::__user_key_input.reset_keys();

            while (true)
            {
                {
                    std::unique_lock<std::mutex> lock(display_mutex);
                    this->display_condition_var.wait(lock);
                }

                this->reset_keys();
                glfwPollEvents();
                glClear(GL_COLOR_BUFFER_BIT);

                this->display();

                glfwSwapBuffers(window_ptr);

                if (!display_running.load())
                {
                    this->exit();
                    this->_delete_basic_shaders_and_buffers();
                    glfwDestroyWindow(window_ptr);
                    glfwTerminate();
                    break;
                }
            }

            lnd::__user_key_input.reset_keys();
        }

        // window
        GLFWwindow* window_ptr;
        bool window_resizable = false;
        bool window_fullscreen = false;

        // time elapsed since last frame
        float time_elapsed;

        // clock
        std::chrono::time_point<std::chrono::steady_clock> _start;
        std::chrono::time_point<std::chrono::steady_clock> _stop;
        long long clock_sleep_time;

        // other specs
        size_t number_of_threads = 0;
        size_t task_buffer_size = 0;

        //display
        std::thread display_thread;
        std::mutex display_mutex;
        std::atomic<bool> display_running = false;
        std::atomic<bool> display_init_finished = false;
        std::atomic<bool> display_init_failed = false;
    };
}


namespace lnd
{
    // INDEX STORAGE CLASSES

    template <size_t _index_count> class cluster_index
    {

    private:

        std::array<unsigned int, _index_count> m;

    public:

        cluster_index() = default;
        ~cluster_index() = default;
        cluster_index(const cluster_index<_index_count>&) = default;
        cluster_index(cluster_index<_index_count>&&) = default;
        cluster_index& operator=(const cluster_index<_index_count>&) = default;
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

    template <size_t _index_count_pc, class _Allocator = std::allocator<lnd::cluster_index<_index_count_pc>>> class group_cluster_index
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
        template <class _rhs_Allocator> group_cluster_index(group_cluster_index<_index_count_pc, _rhs_Allocator>&& rhs) noexcept
        {
            m = std::move(rhs.m);
        }
        template <class _rhs_Allocator> group_cluster_index& operator=(const group_cluster_index<_index_count_pc, _rhs_Allocator>& rhs)
        {
            m = rhs.m;
            return *this;
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
        inline void buffer_update() const
        {
            glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(unsigned int), this->data());
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

    template <class _Allocator = std::allocator<unsigned int>> class group_index
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
        template <class _rhs_Allocator> group_index(group_index<_rhs_Allocator>&& rhs) noexcept
        {
            m = std::move(rhs.m);
        }
        template <class _rhs_Allocator> group_index& operator=(const group_index<_rhs_Allocator>& rhs)
        {
            m = rhs.m;
            return *this;
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
        inline void buffer_update() const
        {
            glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(unsigned int), this->data());
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

        std::array<LND_ARRAY<float, _dim>, _color_count_pc> m;

    public:

        cluster_color() = default;
        ~cluster_color() = default;
        cluster_color(const cluster_color<_color_count_pc, _dim>&) = default;
        cluster_color(cluster_color<_color_count_pc, _dim>&&) = default;
        cluster_color& operator=(const cluster_color<_color_count_pc, _dim>&) = default;
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

        inline const LND_ARRAY<float, _dim>* data_color() const noexcept
        {
            return static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data()));
        }
        inline LND_ARRAY<float, _dim>* data_color() noexcept
        {
            return static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data()));
        }
        inline const LND_ARRAY<float, _dim>& operator()(size_t color) const noexcept
        {
            return *(static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data())) + color);
        }
        inline LND_ARRAY<float, _dim>& operator()(size_t color) noexcept
        {
            return *(static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data())) + color);
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
        = std::allocator<lnd::cluster_color<_color_count_pc, _dim>>>
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
        template <class _rhs_Allocator> group_cluster_color(group_cluster_color<_color_count_pc, _dim, _rhs_Allocator>&& rhs) noexcept
        {
            m = std::move(rhs.m);
        }
        template <class _rhs_Allocator> group_cluster_color& operator=(const group_cluster_color<_color_count_pc, _dim, _rhs_Allocator>& rhs)
        {
            m = rhs.m;
            return *this;
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
        inline void buffer_update() const
        {
            glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(float), this->data());
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

        inline const LND_ARRAY<float, _dim>* data_color() const noexcept
        {
            return static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data()));
        }
        inline LND_ARRAY<float, _dim>* data_color() noexcept
        {
            return static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data()));
        }
        inline const LND_ARRAY<float, _dim>& operator()(size_t cluster, size_t color) const noexcept
        {
            return *(static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data())) + color + _color_count_pc * cluster);
        }
        inline LND_ARRAY<float, _dim>& operator()(size_t cluster, size_t color) noexcept
        {
            return *(static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data())) + color + _color_count_pc * cluster);
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

    template <size_t _dim, class _Allocator = std::allocator<LND_ARRAY<float, _dim>>> class group_color
    {

    private:

        std::vector<LND_ARRAY<float, _dim>, _Allocator> m;
        lnd::buffer_color buffer;

    public:

        group_color() = default;
        ~group_color() = default;
        group_color(size_t n)
        {
            m = std::vector<LND_ARRAY<float, _dim>>(n, 0.0f);
        }
        group_color(size_t n, const LND_ARRAY<float, _dim>& x)
        {
            m = std::vector<unsigned int>(n, x);
        }
        template <class _rhs_Allocator> group_color(const group_color<_dim, _rhs_Allocator>& rhs)
        {
            m = rhs.m;
        }
        template <class _rhs_Allocator> group_color(group_color<_dim, _rhs_Allocator>&& rhs) noexcept
        {
            m = std::move(rhs.m);
        }
        template <class _rhs_Allocator> group_color& operator=(const group_color<_dim, _rhs_Allocator>& rhs)
        {
            m = rhs.m;
            return *this;
        }
        template <class _rhs_Allocator> group_color& operator=(group_color<_dim, _rhs_Allocator>&& rhs) noexcept
        {
            m = std::move(rhs.m);
            return *this;
        }

        group_color(std::initializer_list<float> L)
        {
            m = std::vector<LND_ARRAY<float, _dim>, _Allocator>(L.size() / _dim);
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
        inline void buffer_update() const
        {
            glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(float), this->data());
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

        inline const LND_ARRAY<float, _dim>* data_color() const noexcept
        {
            return static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data()));
        }
        inline LND_ARRAY<float, _dim>* data_color() noexcept
        {
            return static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data()));
        }
        inline const LND_ARRAY<float, _dim>& operator()(size_t color) const noexcept
        {
            return *(static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data())) + color);
        }
        inline LND_ARRAY<float, _dim>& operator()(size_t color) noexcept
        {
            return *(static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data())) + color);
        }

        inline void resize_color_count(size_t n)
        {
            m.resize(n);
        }
        inline void reserve_color_count(size_t n)
        {
            m.reserve(n);
        }
        inline void push_back_color(const LND_ARRAY<float, _dim>& new_color)
        {
            m.push_back(new_color);
        }
        inline void push_front_color(const LND_ARRAY<float, _dim>& new_color)
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

    template <size_t _dim, class _texture_Allocator = std::allocator<LND_ARRAY<unsigned char, _dim>>> class texture
    {

    private:

        std::vector<LND_ARRAY<unsigned char, _dim>, _texture_Allocator> m;
        size_t _width = 0;
        size_t _height = 0;
        lnd::buffer_texture buffer;
        int map = GL_NEAREST;

    public:

        texture() = default;
        ~texture() = default;
        texture(size_t new_width, size_t new_height)
        {
            m = std::vector<LND_ARRAY<unsigned char, _dim>>(new_width * new_height,
                LND_ARRAY<unsigned char, _dim>{ static_cast<unsigned char>(0) });
            _width = new_width;
            _height = new_height;
        }
        texture(size_t new_width, size_t new_height, const LND_ARRAY<float, _dim>& x)
        {
            m = std::vector<LND_ARRAY<unsigned char, _dim>>(new_width * new_height, x);
            _width = new_width;
            _height = new_height;
        }
        template <class _rhs_Allocator> texture(const texture<_dim, _rhs_Allocator>& rhs)
        {
            m = rhs.m;
            _width = rhs._width;
            _height = rhs._height;
        }
        template <class _rhs_Allocator> texture(texture<_dim, _rhs_Allocator>&& rhs) noexcept
        {
            m = std::move(rhs.m);
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
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, map);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, map);
                break;

            case 2:
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), 0, GL_RG, GL_UNSIGNED_BYTE,
                    static_cast<const unsigned char*>(static_cast<const void*>(m.data())));
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, map);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, map);
                break;

            case 3:
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), 0, GL_RGB, GL_UNSIGNED_BYTE,
                    static_cast<const unsigned char*>(static_cast<const void*>(m.data())));
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, map);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, map);
                break;

            case 4:
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, static_cast<GLsizei>(_width), static_cast<GLsizei>(_height), 0, GL_RGBA, GL_UNSIGNED_BYTE,
                    static_cast<const unsigned char*>(static_cast<const void*>(m.data())));
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, map);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, map);
                break;

            default:
                break;
            }
            buffer.unbind();
        }
        inline void buffer_allocate_from(const unsigned char* ptr, GLsizei width, GLsizei height) const
        {
            buffer.bind();
            switch (_dim)
            {

            case 1:
                glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, width, height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, ptr);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, map);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, map);
                break;

            case 2:
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RG, width, height, 0, GL_RG, GL_UNSIGNED_BYTE, ptr);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, map);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, map);
                break;

            case 3:
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, ptr);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, map);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, map);
                break;

            case 4:
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, ptr);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, map);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, map);
                break;

            default:
                break;
            }
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
            buffer.unbind();
        }
        inline void buffer_update_from(const unsigned char* ptr, GLsizei width, GLsizei height) const
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
            buffer.unbind();
        }

        inline void map_nearest() noexcept
        {
            map = GL_NEAREST;
        }
        inline void map_linear() noexcept
        {
            map = GL_LINEAR;
        }

        inline size_t width() const noexcept { return _width; }
        inline size_t height() const noexcept { return _height; }

        inline void flip()
        {
            LND_ARRAY<unsigned char, _dim> temp;
            LND_ARRAY<unsigned char, _dim>* p = m.data();
            LND_ARRAY<unsigned char, _dim>* q = m.data() + _width * (_height - 1);
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

        inline const LND_ARRAY<unsigned char, _dim>* data_pixel() const noexcept
        {
            return static_cast<const LND_ARRAY<unsigned char, _dim>*>(static_cast<const void*>(m.data()));
        }
        inline LND_ARRAY<unsigned char, _dim>* data_pixel() noexcept
        {
            return static_cast<LND_ARRAY<unsigned char, _dim>*>(static_cast<void*>(m.data()));
        }
        inline const LND_ARRAY<unsigned char, _dim>& operator()(size_t position) const noexcept
        {
            return *(static_cast<const LND_ARRAY<unsigned char, _dim>*>(static_cast<const void*>(m.data())) + position);
        }
        inline LND_ARRAY<unsigned char, _dim>& operator()(size_t position) noexcept
        {
            return *(static_cast<LND_ARRAY<unsigned char, _dim>*>(static_cast<void*>(m.data())) + position);
        }
        inline const LND_ARRAY<unsigned char, _dim>& operator()(size_t position_X, size_t position_Y) const noexcept
        {
            return *(static_cast<const LND_ARRAY<unsigned char, _dim>*>(static_cast<const void*>(m.data())) + position_X + _width * position_Y);
        }
        inline LND_ARRAY<unsigned char, _dim>& operator()(size_t position_X, size_t position_Y) noexcept
        {
            return *(static_cast<LND_ARRAY<unsigned char, _dim>*>(static_cast<void*>(m.data())) + position_X + _width * position_Y);
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

        std::array<LND_ARRAY<float, _dim>, _vertex_count_pc> m;

    public:

        cluster_vertex() = default;
        ~cluster_vertex() = default;
        cluster_vertex(const cluster_vertex<_vertex_count_pc, _dim>&) = default;
        cluster_vertex(cluster_vertex<_vertex_count_pc, _dim>&&) = default;
        cluster_vertex& operator=(const cluster_vertex<_vertex_count_pc, _dim>&) = default;
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

        inline const LND_ARRAY<float, _dim>* data_vertex() const noexcept
        {
            return static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data()));
        }
        inline LND_ARRAY<float, _dim>* data_vertex() noexcept
        {
            return static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data()));
        }
        inline const LND_ARRAY<float, _dim>& operator()(size_t vertex) const noexcept
        {
            return *(static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data())) + vertex);
        }
        inline LND_ARRAY<float, _dim>& operator()(size_t vertex) noexcept
        {
            return *(static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data())) + vertex);
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
        = std::allocator<lnd::cluster_vertex<_vertex_count_pc, _dim>>>
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
        template <class _rhs_Allocator> group_cluster_vertex(group_cluster_vertex<_vertex_count_pc, _dim, _rhs_Allocator>&& rhs) noexcept
        {
            m = std::move(rhs.m);
        }
        template <class _rhs_Allocator> group_cluster_vertex& operator=(const group_cluster_vertex<_vertex_count_pc, _dim, _rhs_Allocator>& rhs)
        {
            m = rhs.m;
            return *this;
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
        inline void buffer_update() const
        {
            glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(float), this->data());
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

        inline const LND_ARRAY<float, _dim>* data_vertex() const noexcept
        {
            return static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data()));
        }
        inline LND_ARRAY<float, _dim>* data_vertex() noexcept
        {
            return static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data()));
        }
        inline const LND_ARRAY<float, _dim>& operator()(size_t cluster, size_t vertex) const noexcept
        {
            return *(static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data())) + vertex + _vertex_count_pc * cluster);
        }
        inline LND_ARRAY<float, _dim>& operator()(size_t cluster, size_t vertex) noexcept
        {
            return *(static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data())) + vertex + _vertex_count_pc * cluster);
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


        inline void draw(const lnd::program_vertex_fragment& program)
        {
            switch (_vertex_count_pc)
            {

            case 1:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(this->vertex_count()));
                buffer.unbind();
                break;

            case 2:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(this->vertex_count()));
                buffer.unbind();
                break;

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
                buffer.unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
                buffer.unbind();
                break;

            default:
                break;
            }
        }

        inline void draw(GLsizei first_cluster, GLsizei end_cluster, const lnd::program_vertex_fragment& program)
        {
            switch (_vertex_count_pc)
            {

            case 1:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_POINTS, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
                buffer.unbind();
                break;

            case 2:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_LINES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
                buffer.unbind();
                break;

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
                buffer.unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_QUADS, _vertex_count_pc * first_cluster, static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
                buffer.unbind();
                break;

            default:
                break;
            }
        }

        template <size_t _color_dim, class _color_Allocator> inline void draw(const lnd::program_vertex_fragment& program,
            const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring)
        {
            switch (_color_dim)
            {

            case 3:
                switch (_vertex_count_pc)
                {

                case 1:
                    buffer.bind();
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                    coloring.buffer_bind();
                    glEnableVertexAttribArray(1);
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                    glUseProgram(program.get());
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
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                    glUseProgram(program.get());
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
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                    glUseProgram(program.get());
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
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                    glUseProgram(program.get());
                    glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
                    buffer.unbind();
                    coloring.buffer_unbind();
                    break;

                default:
                    break;
                }
                break;

            case 4:
                switch (_vertex_count_pc)
                {

                case 1:
                    buffer.bind();
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                    coloring.buffer_bind();
                    glEnableVertexAttribArray(1);
                    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_POINTS, 0, static_cast<GLsizei>(this->vertex_count()));
                    glBlendFunc(GL_ONE, GL_ZERO);
                    buffer.unbind();
                    coloring.buffer_unbind();
                    break;

                case 2:
                    buffer.bind();
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                    coloring.buffer_bind();
                    glEnableVertexAttribArray(1);
                    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(this->vertex_count()));
                    glBlendFunc(GL_ONE, GL_ZERO);
                    buffer.unbind();
                    coloring.buffer_unbind();
                    break;

                case 3:
                    buffer.bind();
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                    coloring.buffer_bind();
                    glEnableVertexAttribArray(1);
                    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
                    glBlendFunc(GL_ONE, GL_ZERO);
                    buffer.unbind();
                    coloring.buffer_unbind();
                    break;

                case 4:
                    buffer.bind();
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                    coloring.buffer_bind();
                    glEnableVertexAttribArray(1);
                    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
                    glBlendFunc(GL_ONE, GL_ZERO);
                    buffer.unbind();
                    coloring.buffer_unbind();
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
        }

        template <size_t _color_dim, class _color_Allocator> inline void draw(GLsizei first_cluster, GLsizei end_cluster,
            const lnd::program_vertex_fragment& program, const lnd::group_cluster_color<_vertex_count_pc,
            _color_dim, _color_Allocator>& coloring)
        {
            switch (_color_dim)
            {

            case 3:
                switch (_vertex_count_pc)
                {

                case 1:
                    buffer.bind();
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                    coloring.buffer_bind();
                    glEnableVertexAttribArray(1);
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                    glUseProgram(program.get());
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
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                    glUseProgram(program.get());
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
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                    glUseProgram(program.get());
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
                    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                    glUseProgram(program.get());
                    glDrawArrays(GL_QUADS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
                        static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
                    buffer.unbind();
                    coloring.buffer_unbind();
                    break;

                default:
                    break;
                }
                break;

            case 4:
                switch (_vertex_count_pc)
                {

                case 1:
                    buffer.bind();
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                    coloring.buffer_bind();
                    glEnableVertexAttribArray(1);
                    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_POINTS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
                        static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
                    glBlendFunc(GL_ONE, GL_ZERO);
                    buffer.unbind();
                    coloring.buffer_unbind();
                    break;

                case 2:
                    buffer.bind();
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                    coloring.buffer_bind();
                    glEnableVertexAttribArray(1);
                    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_LINES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
                        static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
                    glBlendFunc(GL_ONE, GL_ZERO);
                    buffer.unbind();
                    coloring.buffer_unbind();
                    break;

                case 3:
                    buffer.bind();
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                    coloring.buffer_bind();
                    glEnableVertexAttribArray(1);
                    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_TRIANGLES, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
                        static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
                    glBlendFunc(GL_ONE, GL_ZERO);
                    buffer.unbind();
                    coloring.buffer_unbind();
                    break;

                case 4:
                    buffer.bind();
                    glEnableVertexAttribArray(0);
                    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                    coloring.buffer_bind();
                    glEnableVertexAttribArray(1);
                    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_QUADS, static_cast<GLsizei>(_vertex_count_pc) * first_cluster,
                        static_cast<GLsizei>(_vertex_count_pc) * (end_cluster - first_cluster));
                    glBlendFunc(GL_ONE, GL_ZERO);
                    buffer.unbind();
                    coloring.buffer_unbind();
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
        }

        template <class _vertex_Allocator, size_t _pixel_dim, class _texture_Allocator> inline void draw(const lnd::program_vertex_fragment& program,
            const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
            const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image)
        {
            if (_pixel_dim == 4)
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
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->vertex_count()));
                    glBlendFunc(GL_ONE, GL_ZERO);
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
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
                    glBlendFunc(GL_ONE, GL_ZERO);
                    buffer.unbind();
                    texture_coord.buffer_unbind();
                    texture_image.buffer_unbind();
                    break;

                default:
                    break;
                }
            }
            else
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
                    glUseProgram(program.get());
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
                    glUseProgram(program.get());
                    glDrawArrays(GL_QUADS, 0, static_cast<GLsizei>(this->vertex_count()));
                    buffer.unbind();
                    texture_coord.buffer_unbind();
                    texture_image.buffer_unbind();
                    break;

                default:
                    break;
                }
            }
        }

        template <class _vertex_Allocator, size_t _pixel_dim, class _texture_Allocator> inline void draw(GLsizei first_cluster, GLsizei end_cluster,
            const lnd::program_vertex_fragment& program, const lnd::group_cluster_vertex<_vertex_count_pc, 2, _vertex_Allocator>& texture_coord,
            const lnd::texture<_pixel_dim, _texture_Allocator>& texture_image)
        {
            if (_pixel_dim == 4)
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
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_TRIANGLES, _vertex_count_pc * first_cluster, _vertex_count_pc * (end_cluster - first_cluster));
                    glBlendFunc(GL_ONE, GL_ZERO);
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
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glUseProgram(program.get());
                    glDrawArrays(GL_QUADS, 0, _vertex_count_pc * first_cluster, _vertex_count_pc * (end_cluster - first_cluster));
                    glBlendFunc(GL_ONE, GL_ZERO);
                    buffer.unbind();
                    texture_coord.buffer_unbind();
                    texture_image.buffer_unbind();
                    break;

                default:
                    break;
                }
            }
            else
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
                    glUseProgram(program.get());
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
                    glUseProgram(program.get());
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
        }

        template <size_t _index_count_pc, class _index_Allocator> inline void draw_lines(const lnd::program_vertex_fragment& program,
            const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
            indexing.buffer_bind();
            glUseProgram(program.get());
            glDrawElements(GL_LINES, static_cast<GLsizei>(indexing.size()), GL_UNSIGNED_INT, nullptr);
            buffer.unbind();
            indexing.buffer_unbind();
        }

        template <size_t _index_count_pc, class _index_Allocator> inline void draw_lines(GLsizei first_cluster, GLsizei end_cluster,
            const lnd::program_vertex_fragment& program, const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
            indexing.buffer_bind();
            glUseProgram(program.get());
            glDrawElements(GL_LINES, static_cast<GLsizei>(_index_count_pc) * (end_cluster - first_cluster), GL_UNSIGNED_INT,
                reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
            buffer.unbind();
            indexing.buffer_unbind();
        }

        template <size_t _index_count_pc, class _index_Allocator> inline void draw_tris(const lnd::program_vertex_fragment& program,
            const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
            indexing.buffer_bind();
            glUseProgram(program.get());
            glDrawElements(GL_TRIANGLES, indexing.size(), GL_UNSIGNED_INT, nullptr);
            buffer.unbind();
            indexing.buffer_unbind();
        }

        template <size_t _index_count_pc, class _index_Allocator> inline void draw_tris(GLsizei first_cluster, GLsizei end_cluster,
            const lnd::program_vertex_fragment& program, const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
            indexing.buffer_bind();
            glUseProgram(program.get());
            glDrawElements(GL_TRIANGLES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
                reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
            buffer.unbind();
            indexing.buffer_unbind();
        }

        template <size_t _index_count_pc, class _index_Allocator> inline void draw_quads(const lnd::program_vertex_fragment& program,
            const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
            indexing.buffer_bind();
            glUseProgram(program.get());
            glDrawElements(GL_QUADS, indexing.size(), GL_UNSIGNED_INT, nullptr);
            buffer.unbind();
            indexing.buffer_unbind();
        }

        template <size_t _index_count_pc, class _index_Allocator> inline void draw_quads(GLsizei first_cluster, GLsizei end_cluster,
            const lnd::program_vertex_fragment& program, const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
            indexing.buffer_bind();
            glUseProgram(program.get());
            glDrawElements(GL_QUADS, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
                reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
            buffer.unbind();
            indexing.buffer_unbind();
        }

        template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_lines(const lnd::program_vertex_fragment& program,
            const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring, const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            switch (_color_dim)
            {

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glUseProgram(program.get());
                glDrawElements(GL_LINES, indexing.size(), GL_UNSIGNED_INT, nullptr);
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawElements(GL_LINES, indexing.size(), GL_UNSIGNED_INT, nullptr);
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            default:
                break;
            }
        }

        template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_lines(GLsizei first_cluster, GLsizei end_cluster,
            const lnd::program_vertex_fragment& program, const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
            const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            switch (_color_dim)
            {

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glUseProgram(program.get());
                glDrawElements(GL_LINES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
                    reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawElements(GL_LINES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
                    reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            default:
                break;
            }
        }

        template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_tris(const lnd::program_vertex_fragment& program,
            const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring, const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            switch (_color_dim)
            {

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glUseProgram(program.get());
                glDrawElements(GL_TRIANGLES, indexing.size(), GL_UNSIGNED_INT, nullptr);
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawElements(GL_TRIANGLES, indexing.size(), GL_UNSIGNED_INT, nullptr);
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            default:
                break;
            }
        }

        template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_tris(GLsizei first_cluster, GLsizei end_cluster,
            const lnd::program_vertex_fragment& program, const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
            const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            switch (_color_dim)
            {

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glUseProgram(program.get());
                glDrawElements(GL_TRIANGLES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
                    reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawElements(GL_TRIANGLES, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
                    reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            default:
                break;
            }
        }

        template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_quads(const lnd::program_vertex_fragment& program,
            const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring, const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            switch (_color_dim)
            {

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glUseProgram(program.get());
                glDrawElements(GL_QUADS, indexing.size(), GL_UNSIGNED_INT, nullptr);
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawElements(GL_QUADS, indexing.size(), GL_UNSIGNED_INT, nullptr);
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            default:
                break;
            }
        }

        template <size_t _color_dim, size_t _index_count_pc, class _color_Allocator, class _index_Allocator> inline void draw_quads(GLsizei first_cluster, GLsizei end_cluster,
            const lnd::program_vertex_fragment& program, const lnd::group_cluster_color<_vertex_count_pc, _color_dim, _color_Allocator>& coloring,
            const lnd::group_cluster_index<_index_count_pc, _index_Allocator>& indexing)
        {
            switch (_color_dim)
            {

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glUseProgram(program.get());
                glDrawElements(GL_QUADS, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
                    reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                indexing.buffer_bind();
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawElements(GL_QUADS, _index_count_pc * (end_cluster - first_cluster), GL_UNSIGNED_INT,
                    reinterpret_cast<void*>(first_cluster * sizeof(lnd::cluster_index<_index_count_pc>)));
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer.unbind();
                coloring.buffer_bind();
                indexing.buffer_unbind();
                break;

            default:
                break;
            }
        }
    };

    template <size_t _dim, class _Allocator = std::allocator<LND_ARRAY<float, _dim>>> class group_vertex
    {

    private:

        std::vector<LND_ARRAY<float, _dim>, _Allocator> m;
        lnd::buffer_vertex buffer;

    public:

        group_vertex() = default;
        ~group_vertex() = default;
        group_vertex(size_t n)
        {
            m = std::vector<LND_ARRAY<float, _dim>>(n, LND_ARRAY<float, _dim>{ 0.0f });
        }
        group_vertex(size_t n, const LND_ARRAY<float, _dim>& x)
        {
            m = std::vector<LND_ARRAY<float, _dim>>(n, x);
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
            m = std::vector<LND_ARRAY<float, _dim>, _Allocator>(L.size() / _dim);
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
        inline void buffer_update() const
        {
            glNamedBufferSubData(buffer.get(), 0, this->size() * sizeof(float), this->data());
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

        inline const LND_ARRAY<float, _dim>* data_vertex() const noexcept
        {
            return static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data()));
        }
        inline LND_ARRAY<float, _dim>* data_vertex() noexcept
        {
            return static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data()));
        }
        inline const LND_ARRAY<float, _dim>& operator()(size_t vertex) const noexcept
        {
            return *(static_cast<const LND_ARRAY<float, _dim>*>(static_cast<const void*>(m.data())) + vertex);
        }
        inline LND_ARRAY<float, _dim>& operator()(size_t vertex) noexcept
        {
            return *(static_cast<LND_ARRAY<float, _dim>*>(static_cast<void*>(m.data())) + vertex);
        }

        inline void resize_vertex_count(size_t n)
        {
            m.resize(n);
        }
        inline void reserve_vertex_count(size_t n)
        {
            m.reserve(n);
        }
        inline void push_back_vertex(const LND_ARRAY<float, _dim>& new_vertex)
        {
            m.push_back(new_vertex);
        }
        inline void push_front_vertex(const LND_ARRAY<float, _dim>& new_vertex)
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


        template <class _index_Allocator> inline void draw_lines(const lnd::program_vertex_fragment& program,
            const lnd::group_index<_index_Allocator>& indexing)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            indexing.buffer_bind();
            glDrawElements(GL_LINES, static_cast<GLsizei>(indexing.size()), GL_UNSIGNED_INT, nullptr);
            buffer.unbind();
            indexing.buffer_unbind();
        }
        template <class _index_Allocator> inline void draw_tris(const lnd::program_vertex_fragment& program,
            const lnd::group_index<_index_Allocator>& indexing)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            indexing.buffer_bind();
            glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indexing.size()), GL_UNSIGNED_INT, nullptr);
            buffer.unbind();
            indexing.buffer_unbind();
        }
        inline void draw_line_strip(const lnd::program_vertex_fragment& program)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_LINE_STRIP, 0, static_cast<GLsizei>(this->vertex_count()));
            buffer.unbind();
        }
        inline void draw_line_strip(GLsizei first_vertex, GLsizei last_vertex, const lnd::program_vertex_fragment& program)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_LINE_STRIP, first_vertex, last_vertex - first_vertex);
            buffer.unbind();
        }
        inline void draw_line_loop(const lnd::program_vertex_fragment& program)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_LINE_LOOP, 0, static_cast<GLsizei>(this->vertex_count()));
            buffer.unbind();
        }
        inline void draw_tri_strip(const lnd::program_vertex_fragment& program)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_TRIANGLE_STRIP, 0, static_cast<GLsizei>(this->vertex_count()));
            buffer.unbind();
        }
        inline void draw_tri_fan(const lnd::program_vertex_fragment& program)
        {
            buffer.bind();
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
            glUseProgram(program.get());
            glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(this->vertex_count()));
            buffer.unbind();
        }

        template <size_t _color_dim, class _color_Allocator> inline void draw_line_strip(const lnd::program_vertex_fragment& program,
            const lnd::group_color<_color_dim, _color_Allocator>& coloring)
        {
            switch (_color_dim)
            {

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_LINE_STRIP, 0, this->vertex_count());
                buffer.unbind();
                coloring.buffer_unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawArrays(GL_LINE_STRIP, 0, this->vertex_count());
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer.unbind();
                coloring.buffer_unbind();
                break;

            default:
                break;
            }
        }
        template <size_t _color_dim, class _color_Allocator> inline void draw_line_strip(GLsizei first_vertex, GLsizei last_vertex,
            const lnd::program_vertex_fragment& program, const lnd::group_color<_color_dim, _color_Allocator>& coloring)
        {
            switch (_color_dim)
            {

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_LINE_STRIP, first_vertex, last_vertex - first_vertex);
                buffer.unbind();
                coloring.buffer_unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawArrays(GL_LINE_STRIP, first_vertex, last_vertex - first_vertex);
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer.unbind();
                coloring.buffer_unbind();
                break;

            default:
                break;
            }
        }
        template <size_t _color_dim, class _color_Allocator> inline void draw_line_loop(const lnd::program_vertex_fragment& program,
            const lnd::group_color<_color_dim, _color_Allocator>& coloring)
        {
            switch (_color_dim)
            {

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_LINE_LOOP, 0, this->vertex_count());
                buffer.unbind();
                coloring.buffer_unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawArrays(GL_LINE_LOOP, 0, this->vertex_count());
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer.unbind();
                coloring.buffer_unbind();
                break;

            default:
                break;
            }
        }
        template <size_t _color_dim, class _color_Allocator> inline void draw_tri_strip(const lnd::program_vertex_fragment& program,
            const lnd::group_color<_color_dim, _color_Allocator>& coloring)
        {
            switch (_color_dim)
            {

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_TRIANGLE_STRIP, 0, this->vertex_count());
                buffer.unbind();
                coloring.buffer_unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawArrays(GL_TRIANGLE_STRIP, 0, this->vertex_count());
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer.unbind();
                coloring.buffer_unbind();
                break;

            default:
                break;
            }
        }
        template <size_t _color_dim, class _color_Allocator> inline void draw_tri_fan(const lnd::program_vertex_fragment& program,
            const lnd::group_color<_color_dim, _color_Allocator>& coloring)
        {
            switch (_color_dim)
            {

            case 3:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
                glUseProgram(program.get());
                glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(this->vertex_count()));
                buffer.unbind();
                coloring.buffer_unbind();
                break;

            case 4:
                buffer.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, _dim * sizeof(float), nullptr);
                coloring.buffer_bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), nullptr);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawArrays(GL_TRIANGLE_FAN, 0, static_cast<GLsizei>(this->vertex_count()));
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer.unbind();
                coloring.buffer_unbind();
                break;

            default:
                break;
            }
        }
    };


    // TEXT

    template <class _vertex_Allocator = std::allocator<float>> class text
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
                LND_ARRAY<float, 2> XY = atlas_XY(*text_ptr);

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

        template <size_t _dim, class _atlas_Allocator> inline  void draw(const lnd::program_vertex_fragment& program,
            const lnd::texture<_dim, _atlas_Allocator>& atlas)
        {
            if (_dim == 4)
            {
                buffer_screen_vertex.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
                buffer_atlas_vertex.bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
                atlas.buffer_bind();
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glUseProgram(program.get());
                glDrawArrays(GL_QUADS, 0, 4 * static_cast<GLsizei>(_size));
                glBlendFunc(GL_ONE, GL_ZERO);
                buffer_screen_vertex.unbind();
                buffer_atlas_vertex.unbind();
                atlas.buffer_unbind();
            }
            else
            {
                buffer_screen_vertex.bind();
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
                buffer_atlas_vertex.bind();
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
                atlas.buffer_bind();
                glUseProgram(program.get());
                glDrawArrays(GL_QUADS, 0, 4 * static_cast<GLsizei>(_size));
                buffer_screen_vertex.unbind();
                buffer_atlas_vertex.unbind();
                atlas.buffer_unbind();
            }
        }
    };
}


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
