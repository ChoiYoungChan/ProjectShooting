#include "Monster.h"

namespace monster
{
	void Monster::Start(int img, int bullet_img)
	{
		Monster_Image = img;
		Monster_Bullet_Image = bullet_img;
	}
	void Monster::SpawnPattern()
	{
		DrawRotaGraph(_monster_pos_x, _monster_pos_y, 1, 0, Monster_Image, true);
		_monster_pos_y += move_speed;
		if (_monster_pos_y > 700)
		{
			_monster_pos_y = -10;
		}
	}
	void Monster::BulletPattern()
	{
		if (bullet_pos_y > 0)
		{
			DrawRotaGraph(bullet_pos_x, bullet_pos_y - 50, 0.3, 0, Monster_Bullet_Image, true);
			bullet_pos_y -= bullet_speed;
			shootnumber = 0;
		}
		else
		{
			bullet_pos_y = -5;
			shootnumber = 1;
		}
	}
	void Monster::RandomMovePos()
	{
		_monster_pos_x = rand() % (450 - 10 + 1);
	}
	bool Monster::IsInScreen()
	{
		if (_monster_pos_y > -1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
