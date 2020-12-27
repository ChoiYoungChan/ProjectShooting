#include "MonsterBullet.h"

extern int WINDOW_SIZE_Y;

namespace monster
{
	void Bullet::Initialize(int monster_pos_x, int monster_pos_y)
	{
		_Bullet_img = LoadGraph("Resource/Bullet_0005.png");
		bullet_pos_x = monster_pos_x;
		bullet_pos_y = monster_pos_y;
	}
	void Bullet::Update()
	{
		
	}
	void Bullet::Finalize()
	{

	}
	/// <summary>
	/// �����X�^�[�̊�{�I�Ȓe��Sample�̎���
	/// </summary>
	/// <param name="player_pos_x">�ړI�nPlayer��X�����W</param>
	/// <param name="player_pos_y">�ړI�nPlayer��Y�����W</param>
	/// �����X�^�[����ʓ��Ɉړ�������v���C���[�ɒe��ł��Ɓ[���\��
	void Bullet::CalkBullet(int player_pos_x, int player_pos_y)
	{
		float distance = sqrt(pow(player_pos_x - bullet_pos_x, 2) + pow(player_pos_y - bullet_pos_y, 2));
		if (bullet_pos_y < WINDOW_SIZE_Y && bullet_pos_y > 0)
		{
			if (distance != 0)
			{
				bullet_speed_x = (player_pos_x - bullet_pos_x) / distance * bullet_speed;
				bullet_speed_y = (bullet_pos_y - player_pos_y) / distance * bullet_speed;
			}
			else
			{
				bullet_speed_x = 0;
				bullet_speed_y = bullet_speed;
			}

			DrawRotaGraph(bullet_pos_x, bullet_pos_y + 50, 0.3, 0, _Bullet_img, true);
			bullet_pos_x += bullet_speed_x;
			bullet_pos_y -= bullet_speed_y;

			shootnumber = 0;
		}
		else
		{
			bullet_pos_y = -10;
			shootnumber = 1;
		}
	}
}