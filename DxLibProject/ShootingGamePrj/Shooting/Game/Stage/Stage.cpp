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
			_time_count = GetNowCount();			//Stage01�̎��Ԃ�����Ēe����������ۂɎg���ϐ�
			SpawnMonster();
			CalkTask();								//�Փ˔�����v�Z����֐�
		}
		Draw();									//�����X�^�[�ƃv���C���[��\������֐�
	}
	/// <summary>
	/// Player�ƃ����X�^�[��\�����邽�߂̊֐�
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
			//�����X�^�[��\������
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
			
			//Boss�����X�^�[��\������
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
	/// �v�Z������Task���܂Ƃ߂��֐�
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
	/// ���ꂻ��̏󋵂ɂ��Փ˔���
	/// </summary>
	void Stage::ImpactCheck()
	{
		if (PLAYER_MANAGER().GetPlayer()->player_invi_count > ZERO)
		{ 
			PLAYER_MANAGER().GetPlayer()->player_invi_count --;
		}

		//Player�ƃ����X�^�[�̏Փ˔���
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

		//Player�ƃ����X�^�[�e�ۂƏՓ˔���
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
			
			//�����X�^�[��Player�e�ۂƏՓ˔���
			for (int index = ZERO; index < ENEMY_MAX; index++)
			{
				if (MONSTER_MANAGER().GetEnemy(index)->_isActive != false)
				{
					if ((BULLET_MANAGER().Getbullet(count)->_isActive) &&
						(base::TYPE::PlayerBullet ==BULLET_MANAGER().Getbullet(count)->_type) &&
						(MONSTER_MANAGER().GetEnemy(index)->ConfirmImpact(BULLET_MANAGER().Getbullet(count))))
					{
						MONSTER_MANAGER().GetEnemy(index)->Monster_HP -=PLAYER_MANAGER().GetPlayer()->_damage;

						//�����X�^�[��HP��0�ɂȂ�����
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
	/// ���߂����ԂɂȂ����̂����v�Z���Ď��̒i�K�Ɉړ����邩�𔻒f����
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
	/// ���Ԃ����������ăX�e�[�W��؂�ւ���
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
	/// �v���C���[��HP��0�ȉ��ɂȂ�����Q�[���I�[�o�[
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
	/// �g�p���Ă���ϐ��Ȃǂ�������
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