#pragma once
#define PATTERN_COUNT 3

//====================================================
//===========include Lib
#include <math.h>

static int monster_x, monster_y;
static int target_pos_x, target_pos_y;
static int speed_x, speed_y;
static const int bullet_speed = 30;

namespace bullet
{
	class BulletHell
	{
	public:
		BulletHell()
		{
			pattern_No = 0;
		}
		~BulletHell() = default;

	public:
		static void NormalMonster();
		static void FirstBoss();
		static void LastBoss();
		void SetTargetPosition(int, int, int, int, int);
		void Pattern();

	private:
		int pattern_No, monsterID;
	};

}