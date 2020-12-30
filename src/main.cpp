#include "loopndisplay.hpp"

class my_prog : protected lnd::looper
{

protected:

	void setup() { }
	inline void loop(float dt) { call_display(); }
	inline void display() { clear_window(); }
	void exit() { }
	bool exit_condition() { return key_escape(); }
};

int main()
{
	lnd::window<my_prog> main_window;
	main_window.show(640, 480, true, 0.02,
		"My program ! (press escape to exit)");
	return 0;
}
