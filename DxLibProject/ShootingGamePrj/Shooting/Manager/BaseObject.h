#pragma once
#include <math.h>
extern int WINDOW_SIZE_X;
extern int WINDOW_SIZE_Y;

namespace base
{
	class BaseObject
	{
	public:
		BaseObject() = default;
		~BaseObject() = default;

	public:
		const int radius = 30;
		int pos_x, pos_y;
		bool isActive = false;
		float distance;

	public:
		bool ConfirmImpact(BaseObject otherobj);

	};
}
