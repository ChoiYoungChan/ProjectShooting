#pragma once
//--------------------------------------------------------------
//------------include Header
#include "..\Game\Source\Bullet.h"
#include "BaseObject.h"
#include "Singleton.h"
#include <math.h>

#define BULLET_MAX 1000

namespace bulletmanager
{
	class BulletManager : public singleton::Singleton<BulletManager>
	{
	public:
		BulletManager()
		{
			_player_pos_x = 0;
			_player_pos_y = 0;
		}
		~BulletManager() = default;

	public:
		void Initialize();
		void DrawTask();
		void CalkTask();
		void Finalize();

		void SetBullet(bool, int, int, int);
		bullet::Bullet * FindFreeBullet();
		bullet::Bullet * Getbullet(int);

	public:
		static void NormalMonster();
		static void BossMonster();

		static void PhaseOne();
		static void PhaseTwo();
		static void PhaseThree();

		void Pattern();

	private:
		bullet::Bullet _bullet[BULLET_MAX];

		enum BulletImage
		{
			PlayerBullet = 0,
			MonsterBullet,
			BulletMax
		};

		int _img[BulletImage::BulletMax], _bullet_image;
		double _bullet_size;
		bool _isPlayer;

		int _monster_id, _monster_HP;

		int _player_pos_x;
		int _player_pos_y;

	private:
		friend class singleton::Singleton<BulletManager>;
	};
}