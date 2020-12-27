#include "Stage.h"

namespace game
{
	void Stage::Initialize()
	{
		_begin_time = GetNowCount();

		bulletManager = new bulletmanager::BulletManager();
		player = new play_user::Player(bulletManager);
		enemyManager = new monstermanager::MonsterManager(bulletManager);


		player->Initialize();						//プレイヤーをInitializeする	
		enemyManager->Initialize();
		bulletManager->Initialize();
	}

	void Stage::Update()
	{
		_time_count = GetNowCount();			//Stage01の時間を取って弾幕生成する際に使う変数

		player->Update();						//プレイヤーの移動や表示などを適用する
		enemyManager->Update();
		bulletManager->Update();

		SpawnMonster();
		CalkTask();								//衝突判定を計算する関数
		Draw();									//モンスターとプレイヤーを表示する関数
	}

	void Stage::Finalize()
	{
		stagemanager.SetNextStage(StageState::Stage02);
		StageID++;
		Initialize();
	}

	/// <summary>
	/// Playerとモンスターを表示するための関数
	/// </summary>
	void Stage::Draw()
	{
		DrawFormatString(20, 10, GetColor(255, 255, 255), "Stage0%d ", StageID + 1);
		DrawFormatString(20, WINDOW_SIZE_Y - 20, GetColor(0, 255, 0), "Score : %d", gamedata.Score);
		DrawFormatString(300, WINDOW_SIZE_Y - 20, GetColor(0, 255, 0), "Life : %d", gamedata.Player_HP);
		DrawFormatString(600, WINDOW_SIZE_Y - 20, GetColor(0, 255, 0), "Time : %d", (_time_count - _begin_time));

		if (player_invi_count%2 == 0)
		{
			player->DrawTask();
		}
		enemyManager->DrawTask();
		bulletManager->DrawTask();
	}

	void Stage::SpawnMonster()
	{
		int nowSecond = (_time_count - _begin_time) / 1000;
		for (int count = 0; count < MOVE_COUNTER; count++)
		{
			if ((monster_table[StageID][count].isActive) && nowSecond == (monster_table[StageID][count].monster_spawn_time))
			{
				monster_table[StageID][count].isActive = false;

				enemyManager->MonsterGetPos(monster_table[StageID][count].monster_pos_x, monster_table[StageID][count].monster_pos_y,
					monster_table[StageID][count].destination_pos_x, monster_table[StageID][count].destination_pos_y
				);
				bulletManager->SetTarget(player->pos_x, player->pos_y);
			}
		}
	}

	/// <summary>
	/// 計算をするTaskをまとめた関数
	/// </summary>
	void Stage::CalkTask()
	{
		CheckFinalize();
		ImpactCheck();
	}

	void Stage::ImpactCheck()
	{
		if (player_invi_count > 0)
		{
			player_invi_count--;
		}

		for (int index = 0; index < BULLET_MAX; index++)
		{
			if (player_invi_count > 0)
			{
				break;
			}
			if ((bulletManager->Getbullet(index)->isActive) &&
				(base::TYPE::EnemyBullet == bulletManager->Getbullet(index)->_type) &&
				(player->ConfirmImpact(bulletManager->Getbullet(index))))
			{
				gamedata.Player_HP -= 1;
				bulletManager->Getbullet(index)->isActive = false;
				player_invi_count = 100;
			}
		}
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			if (player_invi_count <= 0)
			{
				if ((enemyManager->GetEnemy(index)->isActive) &&
					(base::TYPE::Enemy == enemyManager->GetEnemy(index)->_type) &&
					(player->ConfirmImpact(enemyManager->GetEnemy(index))))
				{
					gamedata.Player_HP -= 1;
					player_invi_count = 100;
				}
			}

			for (int count = 0; count < BULLET_MAX; count++)
			{
				if ((bulletManager->Getbullet(count)->isActive) &&
					(base::TYPE::PlayerBullet == bulletManager->Getbullet(count)->_type) &&
					(enemyManager->GetEnemy(index)->ConfirmImpact(bulletManager->Getbullet(count))))
				{
					gamedata.Score += 10;
				}
			}
		}
	}

	void Stage::CheckFinalize()
	{
		int nowSecond = (_time_count - _begin_time) / 1000;
		if (nowSecond == (END_TIME + StageID * 10))
		{
			Finalize();
		}

	}

}