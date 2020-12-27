#pragma once
#include "DxLib.h"
#include <random>

namespace monster
{
	class Monster
	{
	public:
		Monster()
		{
			_bullet_speed = 20;
			move_speed = 3;
			spawn_count = 0;
			_monster_pos_y = 0;

			bullet_pos_x = -100;
			bullet_pos_y = -100;
			shootnumber = 1;
		}
		~Monster() = default;

		void Start(int, int);
		void SpawnPattern();
		void RandomMovePos();
		bool IsInScreen();

		void BulletPattern();

	private:
		int Monster_Image;
		int _bullet_speed, move_speed;
		int _bullet_pos_x, _bullet_pos_y;
		int _monster_pos_x, _monster_pos_y;
		int spawn_count;

	private:
		int bullet_pos_x, bullet_pos_y, bullet_speed, Monster_Bullet_Image;
		int shootnumber;
	};
}

