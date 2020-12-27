#include "Stage_01.h"

namespace game
{
	void Stage01::Initialize()
	{
		_begin_time = GetNowCount();
		player.Initialize();						//�v���C���[��Initialize����	
		enemy.Initialize();							//�����X�^�[��Initialize����
	}

	void Stage01::Update()
	{
		_time_count = GetNowCount();			//Stage01�̎��Ԃ�����Ēe����������ۂɎg���ϐ�

		player.Update();						//�v���C���[�̈ړ���\���Ȃǂ�K�p����
		SpawnMonster();
		CalkTask();								//�Փ˔�����v�Z����֐�
		Draw();									//�����X�^�[�ƃv���C���[��\������֐�
	}

	void Stage01::Finalize()
	{
		stagemanager._stagestate = StageState::Stage02;
	}
	/// <summary>
	/// Player�ƃ����X�^�[��\�����邽�߂̊֐�
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
					//�����X�^�[�̈ړ���\���Ȃǂ�K�p����
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
	/// �v�Z������Task���܂Ƃ߂��֐�
	/// </summary>
	void Stage01::CalkTask()
	{
		ImpactCalk();							//�Փ˔��������֐�
		
	}
	/// <summary>
	/// �Փ˔��������֐�
	/// </summary>
	void Stage01::ImpactCalk()
	{
		
		//distance_01�����X�^�[�ƃv���C���[�̊Ԃ̋���->�Փ˔���Ɏg�p
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
		
		//distance_02�����X�^�[�ƃv���C���[�e�̊Ԃ̋���->�Փ˔���Ɏg�p
		for (int index = 0; index < player.MAX_BULLET_COUNT; index++)
		{
			distance_02 = sqrt(pow(enemy.monster_pos_x - player.shoot[index].bullet_pos_x, 2) + pow(enemy.monster_pos_y - player.shoot[index].bullet_pos_y, 2));
			if (distance_02 < (player.player_bullet_radius + enemy.monster_radius))
			{
				printfDx("distance_02 Impact!\n");
			}
		}
		
		//distance_03�����X�^�[�e�ƃv���C���[�̊Ԃ̋���->�Փ˔���Ɏg�p
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