#include "BossMonster.h"
#include "..\..\Manager\BulletManager.h"


namespace monster
{
	void BossMonster::Initialize()
	{
		isActive = true;
	}

	void BossMonster::Draw()
	{
		if (isActive)
		{
			DrawRotaGraph(pos_x, pos_y, 1.0, 0, _img, true);
		}
	}
	void BossMonster::SetBossMonster(int image, int get_pos_x, int get_pos_y, int destnation_pos_x, int destnation_pos_y)
	{
		_img = image;
		pos_x = get_pos_x;
		pos_y = get_pos_y;

		get_monster_pos_y = get_pos_y;

		dest_pos_y = destnation_pos_y;

		float distance = (float)sqrt(pow(dest_pos_y - get_monster_pos_y, 2));

		if (distance)
		{
			monster_speed_y = (int)((get_monster_pos_y - dest_pos_y) / distance * monster_speed);
		}
	}
	void BossMonster::CalkTask()
	{
		pos_y -= monster_speed_y;
		if (isActive && (pos_x > 0 && pos_x < WINDOW_SIZE_X &&
			pos_y > 0 && pos_y < WINDOW_SIZE_Y))
		{
			pos_y = dest_pos_y;
			bulletmanager::BulletManager::Instance().SetBullet(false, Monster_ID, pos_x, pos_y);
		}
	}
	void BossMonster::Finalize()
	{
		isActive = false;
		Monster_ID++;
	}
}