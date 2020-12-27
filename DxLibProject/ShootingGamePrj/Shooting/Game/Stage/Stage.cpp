#include "Stage.h"

namespace game
{
	void Stage::Initialize()
	{
		_begin_time = GetNowCount();
	}

	void Stage::Update()
	{
		SpawnMonster();
		CalkTask();								//衝突判定を計算する関数
		Draw();									//モンスターとプレイヤーを表示する関数
		_time_count = GetNowCount();			//Stage01の時間を取って弾幕生成する際に使う変数
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

		playermanager::PlayerManager::Instance().DrawTask();
		monstermanager::MonsterManager::Instance().DrawTask();
		bulletmanager::BulletManager::Instance().DrawTask();
	}

	void Stage::SpawnMonster()
	{
		int nowSecond = (_time_count - _begin_time) / 1000;

		for (int count = 0; count < MOVE_COUNTER; count++)
		{
			if ((monster_table[StageID][count].isActive) &&
				(monster_table[StageID][count].type_boss == false) &&
				nowSecond == (monster_table[StageID][count].monster_spawn_time))
			{
				monster_table[StageID][count].isActive = false;

				monstermanager::MonsterManager::Instance().MonsterGetPos(monster_table[StageID][count].monster_pos_x,
								 monster_table[StageID][count].monster_pos_y,
								 monster_table[StageID][count].destination_pos_x, 
								 monster_table[StageID][count].destination_pos_y);
			}

			if ((monster_table[StageID][count].isActive) &&
				(monster_table[StageID][count].type_boss) &&
				nowSecond == (monster_table[StageID][count].monster_spawn_time))
			{
				monster_table[StageID][count].isActive = false;
				monstermanager::MonsterManager::Instance().GetBoss()->isActive = true;
				monstermanager::MonsterManager::Instance().BossGetPos(monster_table[StageID][count].monster_pos_x,
					monster_table[StageID][count].monster_pos_y,
					monster_table[StageID][count].destination_pos_x,
					monster_table[StageID][count].destination_pos_y);
			}
		}
	}

	/// <summary>
	/// 計算をするTaskをまとめた関数
	/// </summary>
	void Stage::CalkTask()
	{
		playermanager::PlayerManager::Instance().CalkTask();
		monstermanager::MonsterManager::Instance().CalkTask();
		bulletmanager::BulletManager::Instance().CalkTask();

		ResetFunc();
		ImpactCheck();
		CheckGameOver();
	}

	void Stage::ImpactCheck()
	{
		if (playermanager::PlayerManager::Instance().GetPlayer()->player_invi_count > 0)
		{ 
			playermanager::PlayerManager::Instance().GetPlayer()->player_invi_count --;
		}

		//Playerとモンスターの衝突判定
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			if (playermanager::PlayerManager::Instance().GetPlayer()->player_invi_count <= 0)
			{
				if ((monstermanager::MonsterManager::Instance().GetEnemy(index)->isActive) &&
					(base::TYPE::Enemy == monstermanager::MonsterManager::Instance().GetEnemy(index)->_type) &&
					(playermanager::PlayerManager::Instance().GetPlayer()->
						ConfirmImpact(monstermanager::MonsterManager::Instance().GetEnemy(index))))
				{
					gamedata.Player_HP -= 1;
					monstermanager::MonsterManager::Instance().GetEnemy(index)->isActive = false;
					playermanager::PlayerManager::Instance().GetPlayer()->player_invi_count = 100;
				}
			}
		}

		//Playerとモンスター弾丸と衝突判定
		for (int count = 0; count < BULLET_MAX; count++)
		{
			if (playermanager::PlayerManager::Instance().GetPlayer()->player_invi_count > 0) { break; }

			if ((bulletmanager::BulletManager::Instance().Getbullet(count)->isActive) &&
				(base::TYPE::EnemyBullet == bulletmanager::BulletManager::Instance().Getbullet(count)->_type) &&
				(playermanager::PlayerManager::Instance().GetPlayer()->
					ConfirmImpact(bulletmanager::BulletManager::Instance().Getbullet(count))))
			{
				gamedata.Player_HP -= 1;
				bulletmanager::BulletManager::Instance().Getbullet(count)->isActive = false;
				playermanager::PlayerManager::Instance().GetPlayer()->player_invi_count = 100;
			}
			
			//モンスターとPlayer弾丸と衝突判定
			for (int index = 0; index < ENEMY_MAX; index++)
			{
				if (monstermanager::MonsterManager::Instance().GetEnemy(index)->isActive != false)
				{
					if ((bulletmanager::BulletManager::Instance().Getbullet(count)->isActive) &&
						(base::TYPE::PlayerBullet == bulletmanager::BulletManager::Instance().Getbullet(count)->_type) &&
						(monstermanager::MonsterManager::Instance().GetEnemy(index)->ConfirmImpact(bulletmanager::BulletManager::Instance().Getbullet(count))))
					{
						gamedata.Score += 10;
						monstermanager::MonsterManager::Instance().GetEnemy(index)->isActive = false;
						bulletmanager::BulletManager::Instance().Getbullet(count)->isActive = false;
					}
					break;
				}
			}
		}
		for (int count = 0; count < BULLET_MAX; count++)
		{
			if ((bulletmanager::BulletManager::Instance().Getbullet(count)->isActive) &&
				(base::TYPE::EnemyBullet == bulletmanager::BulletManager::Instance().Getbullet(count)->_type) &&
				(bulletmanager::BulletManager::Instance().Getbullet(count)->
					ConfirmImpact(bulletmanager::BulletManager::Instance().Getbullet(count))))
			{
				for (int index = 0; index < ENEMY_MAX; index++)
				{
					if (monstermanager::MonsterManager::Instance().GetEnemy(index)->isActive != false)
					{
						if ((bulletmanager::BulletManager::Instance().Getbullet(count)->isActive) &&
							(base::TYPE::PlayerBullet == bulletmanager::BulletManager::Instance().Getbullet(count)->_type) &&
							(monstermanager::MonsterManager::Instance().GetEnemy(index)->ConfirmImpact(bulletmanager::BulletManager::Instance().Getbullet(count))))
						{
							gamedata.Score += 10;
							monstermanager::MonsterManager::Instance().GetEnemy(index)->isActive = false;
							bulletmanager::BulletManager::Instance().Getbullet(count)->isActive = false;
						}
						break;
					}
				}
				break;
			}
		}

		//BossモンスターがPlayerの弾丸と衝突判定
		for (int count = 0; count < BULLET_MAX; count++)
		{
			if ((bulletmanager::BulletManager::Instance().Getbullet(count)->isActive) &&
				(base::TYPE::PlayerBullet == bulletmanager::BulletManager::Instance().Getbullet(count)->_type) &&
				(monstermanager::MonsterManager::Instance().GetBoss()->ConfirmImpact(bulletmanager::BulletManager::Instance().Getbullet(count))))
			{
				monstermanager::MonsterManager::Instance().GetBoss()->Monster_HP -=
				playermanager::PlayerManager::Instance().GetPlayer()->damage;
				bulletmanager::BulletManager::Instance().Getbullet(count)->isActive = false;

				if (monstermanager::MonsterManager::Instance().GetBoss()->Monster_HP <= 0)
				{
					monstermanager::MonsterManager::Instance().GetBoss()->isActive = false;
					gamedata.Score += 1294404;
					ResetFunc();
				}
			}
		}
	}

	void Stage::CheckFinalize()
	{
		
	}

	void Stage::ResetFunc()
	{
		int nowSecond = (_time_count - _begin_time) / 1000;
		if (nowSecond > (END_TIME + (StageID * 10)))
		{
			_begin_time = 0;
			_time_count = 0;
			nowSecond = 0;
			StageID++;
			Initialize();
			if (StageID == (STAGE_MAX - 3))
			{
				stagemanager.SetNextStage(StageState::Stage02);
			}
			else if (StageID == (STAGE_MAX - 2))
			{
				monstermanager::MonsterManager::Instance().GetBoss()->Monster_ID++;
				monstermanager::MonsterManager::Instance().GetBoss()->Monster_HP = BOSS_HP;
				stagemanager.SetNextStage(StageState::Stage03);
			}
			else if ((StageID == (STAGE_MAX - 1)) || ((StageID == STAGE_MAX)))
			{
				stagemanager.SetNextStage(StageState::Result);
			}
		}
	}

	void Stage::CheckGameOver()
	{
		if (gamedata.Player_HP <= 0)
		{
			_begin_time = 0;
			_time_count = 0;
			stagemanager.SetNextStage(StageState::Result);
		}
	}

	void Stage::Finalize()
	{

	}
}