#include "Monster.h"

namespace monster
{
	void Monster::Initialize()
	{
		isActive = true;
		_Monster_img = LoadGraph("Resource/Monster_0001.png");
		_Bullet_img = LoadGraph("Resource/Bullet_0005.png");
	}
	/// <summary>
	/// モンスターを呼び出せば実行続ける関数
	/// </summary>
	void Monster::Update()
	{
		//if(shoot = true)
		//{ ShootBullet();}

		CalkTask();
	}
	/// <summary>
	/// モンスターを表示する関数
	/// </summary>
	void Monster::Draw()
	{
		DrawRotaGraph(pos_x, pos_y, 1.0, 0, _Monster_img, true);
	}

	void Monster::GetPosition(int get_pos_x, int get_pos_y, int destnation_pos_x, int destnation_pos_y, 
							  int target_x, int target_y)
	{
		pos_x = get_pos_x;
		pos_y = get_pos_y;

		get_monster_pos_x = get_pos_x;
		get_monster_pos_y = get_pos_y;

		dest_pos_x = destnation_pos_x;
		dest_pos_y = destnation_pos_y;

		bullet_target_pos_x = target_x;
		bullet_target_pos_y = target_y;

		float distance = sqrt(pow(dest_pos_x - get_monster_pos_x, 2) + pow(dest_pos_y - get_monster_pos_y, 2));

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
		pos_x += monster_speed_x;
		pos_y += monster_speed_y;
	}

	void Monster::ShootBullet()
	{
		for (int bullet_count = 0; bullet_count < MONSTER_BULLET_COUNT; bullet_count++)
		{
			monster_bullet[bullet_count].Initialize(_Bullet_img);
			monster_bullet[bullet_count].SetPosition(pos_x, pos_y);
			monster_bullet[bullet_count].SetTargetPosition(bullet_target_pos_x, bullet_target_pos_y);

			monster_bullet[bullet_count].MonsterBulletUpdate();
			if (bullet_count == MONSTER_BULLET_COUNT)
			{shoot = false;}
		}
	}
	void Monster::Finalize()
	{
		isActive = false;
	}
}