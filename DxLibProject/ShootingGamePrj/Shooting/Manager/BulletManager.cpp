#include "BulletManager.h"

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

	void BulletManager::Update()
	{
		CalkTask();
		DrawTask();
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
	/// g—p’†‚Ì’eŠÛ‚Ì’†‚ÅisActive‚ªFalse‚É‚È‚Á‚ÄFree‚È’eŠÛ‚ğ’T‚·ŠÖ”
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
	/// ’eŠÛ‚ğ¶¬‚·‚éŠÖ”
	/// </summary>
	/// <param name="isplayer">Player‚È‚Ì‚©‚ğŠÓ’è</param>
	/// <param name="bullet_pos_x">Å‰‚Ì’eŠÛ‚ÌX²À•W</param>
	/// <param name="bullet_pos_y">Å‰‚Ì’eŠÛ‚ÌY²À•W</param>
	void BulletManager::SetBullet(bool status, int bullet_pos_x, int bullet_pos_y)
	{
		//Free‚È’eŠÛ‚ğ‚Á‚Ä—ˆ‚Ä
		bullet::Bullet* bullet_ = FindFreeBullet();
		if (bullet_ == NULL)
		{
			for (int count = 0; count < BULLET_MAX; count++)
			{
				if (_bullet[count].isActive)
				{
					_bullet[count].isActive = false;
				}
			}
			bullet_ = _bullet;
		}

		//’eŠÛ‚ğ‘Å‚ÂType‚É‚æ‚Á‚ÄPlayer‚ª‘Å‚Â‚Ì‚©Monster‚ª‘Å‚Â‚Ì‚©‚ğ¯•Ê
		bullet_->_type = (status) ? (base::TYPE::PlayerBullet) : (base::TYPE::EnemyBullet);

		//’eŠÛ‚ğ‘Å‚ÂType‚É‚æ‚Á‚ÄPlayerƒCƒ[ƒW‚ÆMonsterƒCƒ[ƒW‚ğ‹æ•ª‚µ‚ê“ü‚ê‚é
		bullet_->SetBullet(status, bullet_pos_x, bullet_pos_y,
			(status) ? (player_bullet_img) : (monster_bullet_img),
			(status) ? (player_bullet_size) : (monster_bullet_size));

		bullet_->_bullethell.SetTargetPosition(_monster_id, target_pos_x, target_pos_y, bullet_pos_x, bullet_pos_y);

		bullet_->isActive = true;
	}

	void BulletManager::GetMonsterID(int monsterID)
	{
		_monster_id = monsterID;
	}

	void BulletManager::SetTarget(int player_pos_x, int player_pos_y)
	{
		target_pos_x = player_pos_x;
		target_pos_y = player_pos_y;
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