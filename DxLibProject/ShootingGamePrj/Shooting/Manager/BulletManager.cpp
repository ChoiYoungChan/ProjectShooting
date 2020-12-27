//--------------------------------------------------------------
//------------include Header
#include "BulletManager.h"
#include "PlayerManager.h"

namespace bulletmanager
{
	void BulletManager::Initialize()
	{
		for (int index = 0; index < BULLET_MAX; index++)
		{
			_bullet[index].Initialize();
		}
		_img[PlayerBullet] = LoadGraph("Resource/Moriya.png");
		_img[MonsterBullet] = LoadGraph("Resource/Bullet_0001.png");
	}

	void BulletManager::CalkTask()
	{
		for (int count = 0; count < BULLET_MAX; count++)
		{
			if (!_bullet[count]._isActive)
				continue;
			_bullet[count].CalkTask();
		}
		_player_pos_x = playermanager::PlayerManager::Instance().GetPlayer()->_pos_x;
		_player_pos_y = playermanager::PlayerManager::Instance().GetPlayer()->_pos_y;
	}

	void BulletManager::DrawTask()
	{
		for (int count = 0; count < BULLET_MAX; count++)
		{
			if (!_bullet[count]._isActive)
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
			if (!_bullet[count]._isActive)
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

		switch (bullet_->_type)
		{
			case base::TYPE::PlayerBullet:
				_bullet_image = _img[PlayerBullet];
				_bullet_size = PLAYER_BULLET_SIZE;
				break;

			case base::TYPE::EnemyBullet:
				_bullet_image = _img[MonsterBullet];
				_bullet_size = MONSTER_BULLET_SIZE;
				break;
		}
		////�e�ۂ�ł�Type�ɂ����Player�C���[�W��Monster�C���[�W���敪��������
		bullet_->SetBullet(status, shooter, bullet_pos_x, bullet_pos_y,
						   _bullet_image,  _bullet_size,
						   _player_pos_x, _player_pos_y);

		bullet_->_isActive = true;
	}
	
	bullet::Bullet * BulletManager::Getbullet(int index)
	{
		return _bullet + index;
	}

	void BulletManager::Finalize()
	{
		_bullet->_isActive = true;
	}

	static void(*BulletPattern[PATTERN_COUNT])() =
	{
		BulletManager::NormalMonster,
		BulletManager::BossMonster
	};

	void BulletManager::NormalMonster()
	{

	}
	void BulletManager::BossMonster()
	{

	}
	void BulletManager::PhaseOne()
	{

	}
	void BulletManager::PhaseTwo()
	{

	}
	void BulletManager::PhaseThree()
	{

	}
	void BulletManager::Pattern()
	{
		BulletPattern[monsterID]();
	}
}