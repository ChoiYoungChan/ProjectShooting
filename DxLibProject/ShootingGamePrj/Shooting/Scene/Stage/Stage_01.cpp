#include "Stage_01.h"

namespace game
{
	void Stage01::Initialize()
	{
		_begin_time = GetNowCount();
		player.Initialize();						//プレイヤーをInitializeする	
		enemy.Initialize();							//モンスターをInitializeする
	}

	void Stage01::Update()
	{
		_time_count = GetNowCount();			//Stage01の時間を取って弾幕生成する際に使う変数

		player.Update();						//プレイヤーの移動や表示などを適用する
		SpawnMonster();
		CalkTask();								//衝突判定を計算する関数
		Draw();									//モンスターとプレイヤーを表示する関数
	}

	void Stage01::Finalize()
	{
		stagemanager._stagestate = StageState::Stage02;
	}
	/// <summary>
	/// Playerとモンスターを表示するための関数
	/// </summary>
	void Stage01::Draw()
	{
		player.DrawTask();
	}

	void Stage01::SpawnMonster()
	{
		for (int count = 0; count < move_counter; count++)
		{
			if ((_time_count - _begin_time) == monster_move[count].monster_spawn_time * 1000)
			{
				for (int index = 0; index < enemy.MONSTER_COUNT; index++)
				{
					enemy.GetPosition(monster_move[count].monster_pos_x, monster_move[count].monster_pos_y);
					//モンスターの移動や表示などを適用する
					enemy.Update();
					for (int index = 0; index < enemy.MONSTER_BULLET_COUNT; index++)
					{
						enemy.monster_bullet[index].CalkBullet(player.player_pos_x, player.player_pos_y);
					}
				}
			}
		}
	}
	/// <summary>
	/// 計算をするTaskをまとめた関数
	/// </summary>
	void Stage01::CalkTask()
	{
		ImpactCalk();							//衝突判定をする関数
		
	}
	/// <summary>
	/// 衝突判定をする関数
	/// </summary>
	void Stage01::ImpactCalk()
	{
		
		//distance_01モンスターとプレイヤーの間の距離->衝突判定に使用
		distance_01 = sqrt(pow(enemy.monster_pos_x - player.player_pos_x,2) + pow(enemy.monster_pos_y - player.player_pos_y, 2));
		if (distance_01 < (player.player_radius + enemy.monster_radius))
		{
			printfDx("Impact!\n");
			player.Player_HP -= 1;
			if (player.Player_HP <= 0)
			{
				printfDx("U LOSE !\n");
				result.GetGameData(stagenumber, score);

			}
		}
		
		//distance_02モンスターとプレイヤー弾の間の距離->衝突判定に使用
		for (int index = 0; index < player.MAX_BULLET_COUNT; index++)
		{
			distance_02 = sqrt(pow(enemy.monster_pos_x - player.shoot[index].bullet_pos_x, 2) + pow(enemy.monster_pos_y - player.shoot[index].bullet_pos_y, 2));
			if (distance_02 < (player.player_bullet_radius + enemy.monster_radius))
			{
				printfDx("distance_02 Impact!\n");
			}
		}
		
		//distance_03モンスター弾とプレイヤーの間の距離->衝突判定に使用
		for (int index = 0; index < enemy.MONSTER_BULLET_COUNT; index++)
		{
			distance_03 = sqrt(pow(enemy.monster_bullet[index].bullet_pos_x - player.player_pos_x, 2) + pow(enemy.monster_bullet[index].bullet_pos_y - player.player_pos_y, 2));
			if (distance_03 < (player.player_radius + enemy.monster_bullet_radius))
			{
				printfDx("distance_03 Impact!\n");
				player.Player_HP -= 1;
				if (player.Player_HP <= 0)
				{
					printfDx("U LOSE !\n");
					result.GetGameData(stagenumber, score);

				}
			}
		}
	}
}