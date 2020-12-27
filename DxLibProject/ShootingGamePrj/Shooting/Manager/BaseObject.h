#pragma once
#include <math.h>

#define BULLET_MAX 1000

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

		~BaseObject() = default;

	public:
		TYPE _type;
		int _radius = 10;
		const int damage = 10;
		int pos_x, pos_y;
		bool isActive = false, isPlayer = true;
		float distance;
		int bullet_shooter;

	public:
		bool ConfirmImpact(BaseObject* otherobj);

	};
}
