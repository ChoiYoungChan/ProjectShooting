#pragma once
#include "..\Game\Source\Bullet.h"
#include "BaseObject.h"
#include "..\Game\Source\BulletHell.h"

#define BULLET_MAX 1000

namespace bulletmanager
{
	class BulletManager
	{
	public:
		BulletManager() = default;
		~BulletManager() = default;

	public:
		void Initialize();
		void Update();
		void DrawTask();
		void CalkTask();
		void Finalize();

		void SetBullet(bool, int, int);
		void SetTarget(int, int);
		void GetMonsterID(int);
		bullet::Bullet * FindFreeBullet();
		bullet::Bullet * Getbullet(int);

	private:
		bullet::Bullet _bullet[BULLET_MAX];
		int player_bullet_img, monster_bullet_img;
		const double player_bullet_size = 0.05, monster_bullet_size = 0.3;
		bool _isPlayer;
		int target_pos_x, target_pos_y;
		int _monster_id;
	};
}