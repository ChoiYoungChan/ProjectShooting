#include "Monster.h"

namespace monster
{
	void Monster::Initialize()
	{
		_Monster_img = LoadGraph("Resource/Monster_0001.png");
	}
	/// <summary>
	/// モンスターを呼び出せば実行続ける関数
	/// </summary>
	void Monster::Update()
	{
		ShootBullet();
		CalkTask();
	}
	/// <summary>
	/// モンスターを表示する関数
	/// </summary>
	void Monster::Draw()
	{
		DrawRotaGraph(monster_pos_x, monster_pos_y, 1.0, 0, _Monster_img, true);
	}

	void Monster::GetPosition(int get_pos_x, int get_pos_y, int destnation_pos_x, int destnation_pos_y, 
							  int target_x, int target_y)
	{
		monster_pos_x = get_pos_x;
		monster_pos_y = get_pos_y;

		get_monster_pos_x = get_pos_x;
		get_monster_pos_y = get_pos_y;

		dest_pos_x = destnation_pos_x;
		dest_pos_y = destnation_pos_y;

		bullet_target_pos_x = target_x;
		bullet_target_pos_y = target_y;

		int distance = (int)sqrt(pow(dest_pos_x - get_monster_pos_x, 2) + pow(dest_pos_y - get_monster_pos_y, 2));

		if (distance)
		{
			monster_speed_x = (dest_pos_x - get_monster_pos_x) / distance * monster_speed;
			monster_speed_y = (dest_pos_y - get_monster_pos_y) / distance * monster_speed;
		}
	}
	/// <summary>
	/// モンスターで計算が必要な処理(弾を打つこと)をまとめた関数
	/// </summary>
	void Monster::CalkTask()
	{
		monster_pos_x += monster_speed_x;
		monster_pos_y += monster_speed_y;
	}
	void Monster::ShootBullet()
	{

	}
	void Monster::Finalize()
	{
		isActive = false;
	}
}