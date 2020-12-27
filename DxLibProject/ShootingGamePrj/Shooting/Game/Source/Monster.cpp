#include "Monster.h"
#include "..\..\Manager\BulletManager.h"

namespace monster
{
	void Monster::Initialize()
	{
		_Monster_img = LoadGraph("Resource/Monster_0001.png");
	}

	/// <summary>
	/// モンスターを表示する関数
	/// </summary>
	void Monster::Draw()
	{
		if (isActive == true)
		{
			DrawRotaGraph(pos_x, pos_y, 1.0, 0, _Monster_img, true);
		}
	}

	void Monster::GetPosition(int get_pos_x, int get_pos_y, int destnation_pos_x, int destnation_pos_y)
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
	/// <summary>
	/// モンスターで計算が必要な処理(弾を打つこと)をまとめた関数
	/// </summary>
	void Monster::CalkTask()
	{
		if (isActive == true)
		{
			pos_x += monster_speed_x;
			pos_y += monster_speed_y;
			if (pos_x > 0 && pos_x < WINDOW_SIZE_X && pos_y > 0 && pos_y < WINDOW_SIZE_Y)
			{
				bulletmanager::BulletManager::Instance().SetBullet(false, Monster_ID, pos_x, pos_y);
			}
		}
	}

	void Monster::Finalize()
	{
		isActive = false;
	}
}