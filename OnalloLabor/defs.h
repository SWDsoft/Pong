#pragma once
#include <iostream>
#define DEBUG(arg) { std::cout << arg << std::endl; }

namespace CONFIG
{

	extern float paddle_h;
	extern float paddle_w;

	namespace left_paddle {
		extern float x;
		extern float y;
	};

	namespace right_paddle {
		extern float x;
		extern float y;
	};

	namespace ball {
		extern float x;
		extern float y;

		extern float w;
		extern float h;

		extern float min_speed;
		extern float max_speed;

		extern float max_lifetime;
		extern float spawn_afterPop;
	};

	namespace screen {
		extern float w;
		extern float h;
	};

}
