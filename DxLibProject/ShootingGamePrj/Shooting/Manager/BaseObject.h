#pragma once
#include <math.h>

extern int WINDOW_SIZE_X;
extern int WINDOW_SIZE_Y;

namespace base
{
	enum TYPE
	{
		Player,
		Enemy,
		PlayerBullet,
		EnemyBullet
	};

	class BaseObject
	{
	public:
		BaseObject()
		{
			pos_x = -100;
			pos_y = -100;
		}
		BaseObject(TYPE type)
		{
			_type = type;
		}
		TYPE GetType() {
			return _type;
		}

		~BaseObject() = default;

	public:
		TYPE _type;
		const int _radius = 30;
		int pos_x, pos_y;
		bool isActive = false;
		bool isPlayer = true;
		float distance;

	public:
		bool ConfirmImpact(BaseObject* otherobj);

	};
}
