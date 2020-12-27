#include "Stage_01.h"

namespace game
{
	void Stage01::Initialize()
	{
		_begin_time = GetNowCount();

		bulletManager = new bulletmanager::BulletManager();
		player = new play_user::Player(bulletManager);
		enemyManager = new monstermanager::MonsterManager(bulletManager);


		player->Initialize();						//�v���C���[��Initialize����	
		enemyManager->Initialize();
		bulletManager->Initialize();
	}

	void Stage01::Update()
	{
		_time_count = GetNowCount();			//Stage01�̎��Ԃ�����Ēe����������ۂɎg���ϐ�

		player->Update();						//�v���C���[�̈ړ���\���Ȃǂ�K�p����
		enemyManager->Update();
		bulletManager->Update();

		SpawnMonster();
		CalkTask();								//�Փ˔�����v�Z����֐�
		Draw();									//�����X�^�[�ƃv���C���[��\������֐�
	}

	void Stage01::Finalize()
	{
		StageID ++;
		stagemanager._stagestate = StageState::Stage02;
	}

	/// <summary>
	/// Player�ƃ����X�^�[��\�����邽�߂̊֐�
	/// </summary>
	void Stage01::Draw()
	{
		DrawFormatString(20,  WINDOW_SIZE_Y - 20, GetColor(0, 255, 0), "Score : %d", gamedata.Score);
		DrawFormatString(300, WINDOW_SIZE_Y - 20, GetColor(0, 255, 0), "Life : %d", gamedata.Player_HP);
		DrawFormatString(600, WINDOW_SIZE_Y - 20, GetColor(0, 255, 0), "Time : %d", (_time_count - _begin_time));

		player->DrawTask();
		enemyManager->DrawTask();
		bulletManager->DrawTask();
	}

	void Stage01::SpawnMonster()
	{
		
		for (int count = 0; count < MOVE_COUNTER; count++)
		{
			int nowSecond = (_time_count - _begin_time) / 1000;

			if ((monster_table[count].isActive) && nowSecond == (monster_table[count].monster_spawn_time))
			{
				monster_table[count].isActive = false;

				enemyManager->MonsterGetPos(monster_table[count].monster_pos_x,monster_table[count].monster_pos_y,
											monster_table[count].destination_pos_x, monster_table[count].destination_pos_y
											);
				bulletManager->SetTarget(player->pos_x, player->pos_y);
			}
		}
	}

	/// <summary>
	/// �v�Z������Task���܂Ƃ߂��֐�
	/// </summary>
	void Stage01::CalkTask()
	{

	}

	void Stage01::ImpactCheck()
	{
		for (auto it = listObjects.begin(); it != listObjects.end(); ++it)
		{
			for (auto other = listObjects.begin(); other != listObjects.end(); ++other)
			{
				if ((*it).ConfirmImpact(*other))
				{

				}
			}
		}
	}
	/*
	/// <summary>
	/// �Փ˔��������֐�
	/// </summary>
	bool Stage01::ImpactCalk(int index)
	{
		//distance_01�����X�^�[�ƃv���C���[�̊Ԃ̋���->�Փ˔���Ɏg�p
		//distance_02�����X�^�[�ƃv���C���[�e�̊Ԃ̋���->�Փ˔���Ɏg�p
		//distance_03�����X�^�[�e�ƃv���C���[�̊Ԃ̋���->�Փ˔���Ɏg�p
		distance_01 = (int)sqrt(pow(enemy[index].monster_pos_x - player.player_pos_x, 2) + pow(enemy[index].monster_pos_y - player.player_pos_y, 2));
		if (distance_01 < (player.player_radius + enemy[index].monster_radius)) 
		{
			gamedata.Player_HP -= 1;
			return 1;
		}

		for (int count = 0; count < player.MAX_BULLET_COUNT; count++)
		{
			distance_02 = (int)sqrt(pow(enemy[index].monster_pos_x - player.shoot[count].bullet_pos_x, 2) + pow(enemy[index].monster_pos_y - player.shoot[count].bullet_pos_y, 2));
			if (distance_02 < (player.player_bullet_radius + enemy[index].monster_radius))
			{
				enemy[index].Finalize();
				gamedata.Score += 10;
				return 0;
			}
		}

		for (int bullet_count = 0; bullet_count < enemy[index].MONSTER_BULLET_COUNT; bullet_count++)
		{
			distance_03 = (int)sqrt(pow(enemy[index].monster_bullet[bullet_count].bullet_pos_x - player.player_pos_x, 2) + pow(enemy[index].monster_bullet[bullet_count].bullet_pos_y - player.player_pos_y, 2));
			if (distance_03 < (player.player_radius + enemy[index].monster_bullet_radius))
			{
				gamedata.Player_HP -= 1;
				return 1;
			}
		}
	}*/

}