#pragma once
#include "..\Game\Source\Bullet.h"
#include "BaseObject.h"
#include "Singleton.h"

namespace bulletmanager
{
	class BulletManager : public singleton::Singleton<BulletManager>
	{
	public:
		BulletManager() = default;
		~BulletManager() = default;

	public:
		void Initialize();
		void DrawTask();
		void CalkTask();
		void Finalize();

		void SetBullet(bool, int, int, int);
		bullet::Bullet * FindFreeBullet();
		bullet::Bullet * Getbullet(int);
		void GetTargetPos(int, int);

	private:
		bullet::Bullet _bullet[BULLET_MAX];
		int player_bullet_img, monster_bullet_img;
		const double player_bullet_size = 0.05, monster_bullet_size = 0.3;
		bool _isPlayer;

		int _monster_id, _monster_HP;

		int _player_pos_x = 0;
		int _player_pos_y = 0;

	private:
		friend class singleton::Singleton<BulletManager>;
	};
}