#include "BossMonster.h"

namespace monster
{
	void BossMonster::Initialize()
	{
		Middle_Boss_Monster_img = LoadGraph("Resource/Monster_0001.png");
		Last_Boss_Monster_img = LoadGraph("Resource/Monster_0001.png");
	}
	void BossMonster::Update()
	{
		if (isActive == true)
		{
			CalkTask();
		}
	}
	void BossMonster::Draw()
	{
		if (isActive == true)
		{
			DrawRotaGraph(pos_x, pos_y, 1.0, 0, Middle_Boss_Monster_img, true);
		}
	}
	void BossMonster::GetPosition(int get_pos_x, int get_pos_y, int destnation_pos_x, int destnation_pos_y)
	{
		if (isActive == true)
		{
			pos_x = get_pos_x;
			pos_y = get_pos_y;

			get_monster_pos_x = get_pos_x;
			get_monster_pos_y = get_pos_y;

			dest_pos_x = destnation_pos_x;
			dest_pos_y = destnation_pos_y;

			float distance = (float)sqrt(pow(dest_pos_x - get_monster_pos_x, 2) + pow(dest_pos_y - get_monster_pos_y, 2));

			if (distance)
			{
				monster_speed_x = (int)((dest_pos_x - get_monster_pos_x) / distance * monster_speed);
				monster_speed_y = (int)((dest_pos_y - get_monster_pos_y) / distance * monster_speed);
			}
		}
	}
	void BossMonster::CalkTask()
	{
		pos_x += monster_speed_x;
		pos_y += monster_speed_y;
	}
	void BossMonster::Finalize()
	{
		isActive = false;
	}
}