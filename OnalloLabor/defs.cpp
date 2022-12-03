#include "defs.h"

namespace CONFIG
{

	float paddle_h = 100;
	float paddle_w = 20;

	namespace left_paddle {
		float x = 0;
		float y = 5;
	};

	namespace right_paddle {
		float x = 980;
		float y = 5;
	};

	namespace ball {
		float x = 500;
		float y = 500;

		float w = 10;
		float h = 10;

		float min_speed = 450;
		float max_speed = 480;

		float max_lifetime = 10;
		float spawn_afterPop = 7;
	};

	namespace screen {
		float w = 1000;
		float h = 800;
	};

}