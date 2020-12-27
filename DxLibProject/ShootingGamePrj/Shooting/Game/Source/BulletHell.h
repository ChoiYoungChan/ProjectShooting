#pragma once
#define PATTERN_COUNT 2
#define BOSS_COUNT 5
#define PI 3.14159265

//====================================================
//===========include Lib
#include <math.h>

		static int shooter,count_x = 0;
		static float center_x, center_y;									//íÜêSÇÃç¿ïW
		static int speed_x, speed_y;
		static const int bullet_speed = 30;
		static int HP, monsterID;

namespace bullet
{
	class Bullet;

	class BulletHell
	{
	public:
		BulletHell() = default;
		~BulletHell() = default;

	public:
		static void NormalMonster(Bullet *bullet);
		static void BossMonster(Bullet *bullet);

		static void PhaseOne(Bullet *bullet, int);
		static void PhaseTwo(Bullet *bullet, int);
		static void PhaseThree(Bullet *bullet, int);

		void SetPosition(Bullet *bullet, int,int);
		void Pattern(Bullet *bullet);

	};

}