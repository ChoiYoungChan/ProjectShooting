#include "BulletManager.h"
#include "..\Game\Source\Player.h"

namespace bulletmanager
{
	void BulletManager::Initialize()
	{
		for (int index = 0; index < BULLET_MAX; index++)
		{
			_bullet[index].Initialize();
		}
		player_bullet_img = LoadGraph("Resource/Moriya.png");
		monster_bullet_img = LoadGraph("Resource/Bullet_0001.png");
	}

	void BulletManager::CalkTask()
	{
		for (int count = 0; count < BULLET_MAX; count++)
		{
			if (!_bullet[count].isActive)
				continue;
			_bullet[count].CalkTask();

		}
	}

	void BulletManager::DrawTask()
	{
		for (int count = 0; count < BULLET_MAX; count++)
		{
			if (!_bullet[count].isActive)
				continue;

			_bullet[count].DrawTask();
		}
	}

	/// <summary>
	/// �g�p���̒e�ۂ̒���isActive��False�ɂȂ���Free�Ȓe�ۂ�T���֐�
	/// </summary>
	/// <returns></returns>
	bullet::Bullet * BulletManager::FindFreeBullet()
	{
		for (int count = 0; count < BULLET_MAX; count++)
		{
			if (!_bullet[count].isActive)
			{
				return &_bullet[count];
			}
		}
		return NULL;
	}

	/// <summary>
	/// �e�ۂ𐶐�����֐�
	/// </summary>
	/// <param name="isplayer">Player�Ȃ̂����Ӓ�</param>
	/// <param name="bullet_pos_x">�ŏ��̒e�ۂ�X�����W</param>
	/// <param name="bullet_pos_y">�ŏ��̒e�ۂ�Y�����W</param>
	void BulletManager::SetBullet(bool status,int shooter, int bullet_pos_x, int bullet_pos_y)
	{
		//Free�Ȓe�ۂ������ė���
		bullet::Bullet* bullet_ = FindFreeBullet();
		if (bullet_ == NULL)
		{
			return;
		}

		//�e�ۂ�ł�Type�ɂ����Player���ł̂�Monster���ł̂�������
		bullet_->_type = (status) ? (base::TYPE::PlayerBullet) : (base::TYPE::EnemyBullet);

		////�e�ۂ�ł�Type�ɂ����Player�C���[�W��Monster�C���[�W���敪��������
		bullet_->SetBullet(status, shooter, bullet_pos_x, bullet_pos_y,
						  (status) ? (player_bullet_img) : (monster_bullet_img),
						  (status) ? (player_bullet_size) : (monster_bullet_size),
						  _player_pos_x, _player_pos_y);

		bullet_->isActive = true;
	}

	void BulletManager::GetTargetPos(int player_x, int player_y)
	{
		_player_pos_x = player_x;
		_player_pos_y = player_y;
	}

	bullet::Bullet * BulletManager::Getbullet(int index)
	{
		return _bullet + index;
	}

	void BulletManager::Finalize()
	{
		_bullet->isActive = true;
	}
}