#include "BulletHell.h"

namespace bullet
{
	static void( * BulletPattern[PATTERN_COUNT])() =
	{
		BulletHell::NormalMonster,
		BulletHell::FirstBoss,
		BulletHell::LastBoss
	};

	void BulletHell::NormalMonster()
	{
		monster_x += speed_x;
		monster_x += speed_y;
	}

	void BulletHell::FirstBoss()
	{

	}

	void BulletHell::LastBoss()
	{

	}

	void BulletHell::Pattern()
	{
		BulletPattern[monsterID]();
	}

	void BulletHell::SetTargetPosition(int monster_id, int player_pos_x, int player_pos_y, int monster_pos_x, int monster_pos_y)
	{
		monsterID = monster_id;
		target_pos_x = player_pos_x;
		target_pos_y = player_pos_y;

		float distance = (float)sqrt(pow(target_pos_x - monster_pos_x, 2) + 
									 pow(target_pos_y - monster_pos_y, 2));

		if (distance)
		{
			speed_x = (int)((target_pos_x - monster_pos_x) / distance * bullet_speed);
			speed_y = (int)((target_pos_y - monster_pos_y) / distance * bullet_speed);
		}
		else
		{
			speed_x = 0;
			speed_y = bullet_speed;
		}
	}
}