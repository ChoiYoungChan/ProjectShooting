#pragma once

#include "Singleton.h"
#include "..\Game\Source\Monster.h"
#include "..\Game\Source\BossMonster.h"

#define ENEMY_MAX 6
#define BOSS 1

namespace monstermanager
{
	class MonsterManager: public singleton::Singleton<MonsterManager>
	{
	public:
		MonsterManager() = default;
		~MonsterManager() = default;

	public:
		void Initialize();
		void DrawTask();
		void MonsterGetPos(int, int, int, int);
		void BossGetPos(int, int, int, int);
		void CalkTask();
		void Finalize();

		monster::Monster * GetEnemy(int);
		monster::BossMonster* GetBoss();

	private:
		monster::Monster* _p_enemy[ENEMY_MAX];
		monster::BossMonster* _p_boss;

		int target_x, target_y;
		int MiddleBoss_img, LastBoss_img;
	private:
		friend class singleton::Singleton<MonsterManager>;

	};
}