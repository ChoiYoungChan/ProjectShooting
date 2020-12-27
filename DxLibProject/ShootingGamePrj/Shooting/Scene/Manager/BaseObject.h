#pragma once

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
		const int bullet_radius = 30;
		const int Player_radius = 30;
		const int Monster_radius = 30;
		const int bullet_speed = 30;
		const int speed = 20;

		bool isActive = false;

	public:
		void ConfirmImpact();
	};
}
