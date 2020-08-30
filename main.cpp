#include "loopndisplay.h"

class my_prog : protected lnd::looper
{

protected:

	void setup() { }
	inline void loop(float dt) { call_display(); }
	inline void display() { }
	void exit() { }
	bool exit_condition() { return key_escape(); }
};

int main()
{
	lnd::window<my_prog> main_window;
	main_window.show(640, 480, true, 100,
		"My program ! (press escape to exit)");
	return 0;
}