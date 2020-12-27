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
	/// 使用中の弾丸の中でisActiveがFalseになってFreeな弾丸を探す関数
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
	/// 弾丸を生成する関数
	/// </summary>
	/// <param name="isplayer">Playerなのかを鑑定</param>
	/// <param name="bullet_pos_x">最初の弾丸のX軸座標</param>
	/// <param name="bullet_pos_y">最初の弾丸のY軸座標</param>
	void BulletManager::SetBullet(bool status,int shooter, int bullet_pos_x, int bullet_pos_y)
	{
		//Freeな弾丸を持って来て
		bullet::Bullet* bullet_ = FindFreeBullet();
		if (bullet_ == NULL)
		{
			return;
		}

		//弾丸を打つTypeによってPlayerが打つのかMonsterが打つのかを識別
		bullet_->_type = (status) ? (base::TYPE::PlayerBullet) : (base::TYPE::EnemyBullet);

		////弾丸を打つTypeによってPlayerイメージとMonsterイメージを区分しれ入れる
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