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
	/// g—p’†‚Ì’eŠÛ‚Ì’†‚ÅisActive‚ªFalse‚É‚È‚Á‚ÄFree‚È’eŠÛ‚ğ’T‚·ŠÖ”
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
	/// ’eŠÛ‚ğ¶¬‚·‚éŠÖ”
	/// </summary>
	/// <param name="isplayer">Player‚È‚Ì‚©‚ğŠÓ’è</param>
	/// <param name="bullet_pos_x">Å‰‚Ì’eŠÛ‚ÌX²À•W</param>
	/// <param name="bullet_pos_y">Å‰‚Ì’eŠÛ‚ÌY²À•W</param>
	void BulletManager::SetBullet(bool status,int shooter, int bullet_pos_x, int bullet_pos_y)
	{
		//Free‚È’eŠÛ‚ğ‚Á‚Ä—ˆ‚Ä
		bullet::Bullet* bullet_ = FindFreeBullet();
		if (bullet_ == NULL)
		{
			return;
		}

		//’eŠÛ‚ğ‘Å‚ÂType‚É‚æ‚Á‚ÄPlayer‚ª‘Å‚Â‚Ì‚©Monster‚ª‘Å‚Â‚Ì‚©‚ğ¯•Ê
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
		////’eŠÛ‚ğ‘Å‚ÂType‚É‚æ‚Á‚ÄPlayerƒCƒ[ƒW‚ÆMonsterƒCƒ[ƒW‚ğ‹æ•ª‚µ‚ê“ü‚ê‚é
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