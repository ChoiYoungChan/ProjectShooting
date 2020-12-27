#include "PlayerBullet.h"

namespace play_user
{
	/// <summary>
	/// ����������ۂɒe�ۂ����˂����ʒu�ƃX�s�[�h�A�e�̃C���[�W���󂯂�
	/// 
	/// </summary>
	/// <param name="pos_x">�e�ۂ����˂����ʒu(�v���C���[��X�����W)</param>
	/// <param name="pos_y">�e�ۂ����˂����ʒu(�v���C���[��Y�����W)</param>
	void PlayerBullet::Initialize(int pos_x, int pos_y)
	{
		if (shootnumber == 1)
		{
			bullet_pos_x = pos_x;
			bullet_pos_y = pos_y;

			_Bullet_img = LoadGraph("Moriya.png");
		}
	}
	/// <summary>
	/// �e�̈ړ�����
	/// </summary>
	void PlayerBullet::Update()
	{
		if (bullet_pos_y > 0)
		{
			DrawRotaGraph(bullet_pos_x, bullet_pos_y - 50, 0.05, 0, _Bullet_img, true);
			bullet_pos_y -= bullet_speed;
			shootnumber = 0;
		}
		else
		{
			bullet_pos_y = -5;
			shootnumber = 1;
		}
	}

	void PlayerBullet::Finalize()
	{

	}
}