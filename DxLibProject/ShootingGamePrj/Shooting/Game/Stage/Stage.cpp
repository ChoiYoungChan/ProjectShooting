//--------------------------------------------------------------
//------------include Header
#include "Stage.h"

namespace game
{
	void Stage::Initialize()
	{
		_begin_time = GetNowCount();
	}

	void Stage::Update()
	{
		Pause();
		if (!_isPause)
		{
			_time_count = GetNowCount();			//Stage01の時間を取って弾幕生成する際に使う変数
			SpawnMonster();
			CalkTask();								//衝突判定を計算する関数
		}
		Draw();									//モンスターとプレイヤーを表示する関数
	}
	/// <summary>
	/// Playerとモンスターを表示するための関数
	/// </summary>
	void Stage::Draw()
	{
		DrawFormatString(20, 10, GetColor(255, 255, 255), "Stage0%d ", (_stagestate + 1));
		DrawFormatString(20, WINDOW_SIZE_Y - 20, GetColor(0, 255, 0), "Score : %d", data::GameData::Instance().Score);
		DrawFormatString(300, WINDOW_SIZE_Y - 20, GetColor(0, 255, 0), "Life : %d", data::GameData::Instance().Player_HP);
		DrawFormatString(600, WINDOW_SIZE_Y - 20, GetColor(0, 255, 0), "Time : %d", (_time_count - _begin_time));

		PLAYER_MANAGER().DrawTask();
		MONSTER_MANAGER().DrawTask();
		BULLET_MANAGER().DrawTask();
	}

	void Stage::SpawnMonster()
	{
		_nowSecond = (_time_count - _begin_time) / 1000;

		switch (_stagestate)
		{
		case StageManager::Stage02:
			boss_type = BOSS_MONSTER_ID;
			break;
		case StageManager::Stage03:
			boss_type = LAST_BOSS_MONSTER_ID;
			break;
		}

		for (int count = 0; count < MOVE_COUNTER; count++)
		{
			//モンスターを表示する
			if ((_monster_table[_stagestate][count].isActive) &&
				(_monster_table[_stagestate][count].type_boss == false) &&
				_nowSecond == (_monster_table[_stagestate][count].monster_spawn_time))
			{
				_monster_table[_stagestate][count].isActive = false;

				MONSTER_MANAGER().MonsterGetPos(
								 NORMAL_MONSTER_ID,
								 _monster_table[_stagestate][count].monster_count,
								 _monster_table[_stagestate][count].monster_pos_x,
								 _monster_table[_stagestate][count].monster_pos_y,
								 _monster_table[_stagestate][count].destination_pos_x,
								 _monster_table[_stagestate][count].destination_pos_y);
			}
			for (int index = 0; index < ENEMY_MAX; index++)
			{
				if (_nowSecond == (_monster_table[_stagestate][count].shoot_bullet_time) &&
					MONSTER_MANAGER().GetEnemy(index)->_isActive == true)
				{
					MONSTER_MANAGER().GetEnemy(index)->ShootBullet();
				}
			}
			
			//Bossモンスターを表示する
			if ((_monster_table[_stagestate][count].isActive) &&
				(_monster_table[_stagestate][count].type_boss) &&
				_nowSecond == (_monster_table[_stagestate][count].monster_spawn_time))
			{
				_monster_table[_stagestate][count].isActive = false;
				MONSTER_MANAGER().MonsterGetPos(boss_type,
					_monster_table[_stagestate][count].monster_count,
					_monster_table[_stagestate][count].monster_pos_x,
					_monster_table[_stagestate][count].monster_pos_y,
					_monster_table[_stagestate][count].destination_pos_x,
					_monster_table[_stagestate][count].destination_pos_y);
			}
		}
	}

	/// <summary>
	/// 計算をするTaskをまとめた関数
	/// </summary>
	void Stage::CalkTask()
	{
		PLAYER_MANAGER().CalkTask();
		MONSTER_MANAGER().CalkTask();
		BULLET_MANAGER().CalkTask();

		CheckFinalize();
		ImpactCheck();
		CheckGameOver();
	}

	/// <summary>
	/// それそれの状況による衝突判定
	/// </summary>
	void Stage::ImpactCheck()
	{
		if (PLAYER_MANAGER().GetPlayer()->player_invi_count > ZERO)
		{ 
			PLAYER_MANAGER().GetPlayer()->player_invi_count --;
		}

		//Playerとモンスターの衝突判定
		for (int index = ZERO; index < ENEMY_MAX; index++)
		{
			if (PLAYER_MANAGER().GetPlayer()->player_invi_count <= ZERO)
			{
				if ((MONSTER_MANAGER().GetEnemy(index)->_isActive) &&
					(base::TYPE::Enemy == MONSTER_MANAGER().GetEnemy(index)->_type) &&
					(MONSTER_MANAGER().GetEnemy(index)->_isActive) &&
					(PLAYER_MANAGER().GetPlayer()->ConfirmImpact(MONSTER_MANAGER().GetEnemy(index))))
				{
					GAME_DATA().Player_HP -= 1;
					MONSTER_MANAGER().GetEnemy(index)->_isActive = false;
					PLAYER_MANAGER().GetPlayer()->player_invi_count = 100;
				}
			}
		}

		//Playerとモンスター弾丸と衝突判定
		for (int count = ZERO; count < BULLET_MAX; count++)
		{
			if (PLAYER_MANAGER().GetPlayer()->player_invi_count > ZERO) { break; }

			if ((BULLET_MANAGER().Getbullet(count)->_isActive) &&
				(base::TYPE::EnemyBullet == BULLET_MANAGER().Getbullet(count)->_type) &&
				(PLAYER_MANAGER().GetPlayer()->ConfirmImpact(BULLET_MANAGER().Getbullet(count))))
			{
				GAME_DATA().Player_HP -= 1;
				BULLET_MANAGER().Getbullet(count)->_isActive = false;
				PLAYER_MANAGER().GetPlayer()->player_invi_count = 100;
			}
			
			//モンスターとPlayer弾丸と衝突判定
			for (int index = ZERO; index < ENEMY_MAX; index++)
			{
				if (MONSTER_MANAGER().GetEnemy(index)->_isActive != false)
				{
					if ((BULLET_MANAGER().Getbullet(count)->_isActive) &&
						(base::TYPE::PlayerBullet ==BULLET_MANAGER().Getbullet(count)->_type) &&
						(MONSTER_MANAGER().GetEnemy(index)->ConfirmImpact(BULLET_MANAGER().Getbullet(count))))
					{
						MONSTER_MANAGER().GetEnemy(index)->Monster_HP -=PLAYER_MANAGER().GetPlayer()->_damage;

						//モンスターのHPが0になった時
						if (MONSTER_MANAGER().GetEnemy(index)->Monster_HP <= 0)
						{
							MONSTER_MANAGER().GetEnemy(index)->_isActive = false;
							BULLET_MANAGER().Getbullet(count)->_isActive = false;
							if (MONSTER_MANAGER().GetEnemy(index)->_Monster_ID == NORMAL_MONSTER_ID)
							{
								GAME_DATA().Score += 10;
							}
							else if (MONSTER_MANAGER().GetEnemy(index)->_Monster_ID >= BOSS_MONSTER_ID)
							{
								GAME_DATA().Score += 1294404;
								ReadyNextStage();
							}
						}
					}
				}
			}
		}
	}

	/// <summary>
	/// 決めた時間になったのかを計算して次の段階に移動するかを判断する
	/// </summary>
	void Stage::CheckFinalize()
	{
		switch (_stagestate)
		{
		case StageState::Stage01:
			if (_nowSecond == END_TIME)
			{ReadyNextStage();}
			break;
		case StageState::Stage02:
			if (_nowSecond > (END_TIME + (_stagestate * 10)))
			{ReadyNextStage();}
			break;
		case StageState::Stage03:
			if (_nowSecond > (END_TIME + (_stagestate * 10)))
			{ReadyNextStage();}
			break;
		}
	}
	/// <summary>
	/// 時間を初期化してステージを切り替える
	/// </summary>
	void Stage::ReadyNextStage()
	{
		TIME_RESET;
		Initialize();

		switch (_stagestate)
		{
		case StageState::Stage01:
			_stagestate = StageState::Stage02;
			break;
		case StageState::Stage02:
			_stagestate = StageState::Stage03;
			break;
		case StageState::Stage03:
			_NextState = true;
			Finalize();
			break;
		}
	}

	/// <summary>
	/// プレイヤーのHPが0以下になったらゲームオーバー
	/// </summary>
	void Stage::CheckGameOver()
	{
		if (GAME_DATA().Player_HP == ZERO)
		{
			GAME_DATA().Stage_Level = (_stagestate + 1);
			_NextState = true;
		}
	}

	/// <summary>
	/// 使用している変数などを初期化
	/// </summary>
	void Stage::InitVar()
	{
		TIME_RESET;
		GAME_DATA().Reset();
		_NextState = false;

		for (int index = ZERO; index < StageState::Stage_Max; index++)
		{
			for (int count = ZERO; count < MOVE_COUNTER; count++)
			{
				_monster_table[index][count].isActive = true;
			}
		}
	}

	void Stage::Pause()
	{
		if (keyboard::GetKeyTrigger(KEY_INPUT_P))
		{
			_isPause = !_isPause;
		}
	}

	void Stage::Finalize()
	{
		SetNextState(scene::State::Result);
	}
}