#pragma once
//--------------------------------------------------------------
//------------include Header
#include <math.h>
#include "..\System.h"

namespace base
{
	enum TYPE
	{
		Player = 0,
		Enemy,
		PlayerBullet,
		EnemyBullet
	};

	class BaseObject
	{
	public:
		BaseObject() = default;
		BaseObject(TYPE type)
		{
			_type = type;
		}

		~BaseObject() = default;

	public:
		TYPE _type;
		const int _damage = 10;
		int _pos_x, _pos_y, _speed, _radius;
		bool _isActive = false, _isPlayer = true;
		float _distance;

	public:
		bool ConfirmImpact(BaseObject* otherobj);

	};
}
