#pragma once
#include "..\Game\Source\Monster.h"
#include "..\Game\Source\BossMonster.h"

#define ENEMY_MAX 6

namespace monstermanager
{
	class MonsterManager
	{
	public:
		MonsterManager(bulletmanager::BulletManager * bulletManager)
			: _bulletmanager(bulletManager)
		{ }
		~MonsterManager() = default;

	public:
		void Initialize();
		void Update();
		void DrawTask();
		void MonsterGetPos(int, int, int, int);
		void CalkTask();
		void Finalize();
		monster::Monster * GetEnemy(int);

	private:
		monster::Monster _enemy[ENEMY_MAX];
		bulletmanager::BulletManager * _bulletmanager = NULL;
		monster::BossMonster boss;

		int target_x, target_y;
	};
}