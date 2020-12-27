#include "Stage_01.h"

namespace game
{
	void Stage01::Initialize()
	{
		player.Initialize();						//プレイヤーをInitializeする
		enemy.Initialize();						//モンスターをInitializeする
	}

	void Stage01::Update()
	{
		_time_count = GetNowCount();			//Stage01の時間を取って弾幕生成する際に使う変数
		CalkTask();								//衝突判定を計算する関数
		Draw();									//モンスターとプレイヤーを表示する関数
	}

	void Stage01::Finalize()
	{
		
	}

	void Stage01::Draw()
	{
		player.Update();							//プレイヤーの移動や表示などを適用する
		enemy.Update();							//モンスターの移動や表示などを適用する
	}
	void Stage01::CalkTask()
	{
		ImpactCalk();							//衝突判定をする関数
		monster_bullet.CalkBullet(player.player_pos_x, player.player_pos_y);
	}
	void Stage01::ImpactCalk()
	{
		//distance_01モンスターとプレイヤーの間の距離->衝突判定に使用
		//distance_02モンスターとプレイヤー弾の間の距離->衝突判定に使用
		//distance_03モンスター弾とプレイヤーの間の距離->衝突判定に使用

		distance_01 = sqrt(pow(enemy.monster_pos_x - player.player_pos_x,2) + pow(enemy.monster_pos_y - player.player_pos_y, 2));
		distance_02 = sqrt(pow(enemy.monster_pos_x - player_bullet.bullet_pos_x, 2) + pow(enemy.monster_pos_y - player_bullet.bullet_pos_y, 2));
		distance_03 = sqrt(pow(monster_bullet.bullet_pos_x - player.player_pos_x, 2) + pow(monster_bullet.bullet_pos_y - player.player_pos_y, 2));

		if (distance_01 < (player.player_radius + enemy.monster_radius))
		{
			printfDx("Impact!\n");
			player.Player_HP -= 1;
			if (player.Player_HP == 0)
			{
				printfDx("U Lose!!");
			}
		}
		if (player_bullet.bullet_pos_y > 0 || monster_bullet.bullet_pos_y > 0)
		{
			if (distance_02 < (player.player_bullet_radius + enemy.monster_radius))
			{
				printfDx("distance_02 = %d", distance_02);
			}
			if (distance_03 < (player.player_radius + enemy.monster_bullet_radius))
			{
				printfDx("distance_03 = %d", distance_03);
				player.Player_HP -= 1;
				if (player.Player_HP == 0)
				{
					printfDx("U Lose!!");
				}
			}
		}
	}
}