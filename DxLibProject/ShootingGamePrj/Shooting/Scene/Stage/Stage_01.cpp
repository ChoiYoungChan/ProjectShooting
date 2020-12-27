#include "Stage_01.h"

namespace game
{
	void Stage01::Initialize()
	{
		player.Initialize();						//�v���C���[��Initialize����
		enemy.Initialize();						//�����X�^�[��Initialize����
	}

	void Stage01::Update()
	{
		_time_count = GetNowCount();			//Stage01�̎��Ԃ�����Ēe����������ۂɎg���ϐ�
		CalkTask();								//�Փ˔�����v�Z����֐�
		Draw();									//�����X�^�[�ƃv���C���[��\������֐�
	}

	void Stage01::Finalize()
	{
		
	}

	void Stage01::Draw()
	{
		player.Update();							//�v���C���[�̈ړ���\���Ȃǂ�K�p����
		enemy.Update();							//�����X�^�[�̈ړ���\���Ȃǂ�K�p����
	}
	void Stage01::CalkTask()
	{
		ImpactCalk();							//�Փ˔��������֐�
		monster_bullet.CalkBullet(player.player_pos_x, player.player_pos_y);
	}
	void Stage01::ImpactCalk()
	{
		//distance_01�����X�^�[�ƃv���C���[�̊Ԃ̋���->�Փ˔���Ɏg�p
		//distance_02�����X�^�[�ƃv���C���[�e�̊Ԃ̋���->�Փ˔���Ɏg�p
		//distance_03�����X�^�[�e�ƃv���C���[�̊Ԃ̋���->�Փ˔���Ɏg�p

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