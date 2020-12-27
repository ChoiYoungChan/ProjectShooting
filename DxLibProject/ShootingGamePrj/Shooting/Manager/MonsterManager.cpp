#include "MonsterManager.h"

namespace monstermanager
{
	void MonsterManager::Initialize()
	{
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			_p_enemy[index] = new monster::Monster();
			_p_enemy[index]->Initialize();
		}
		_p_boss = new monster::BossMonster();
		_p_boss->Initialize();

		MiddleBoss_img = LoadGraph("Resource/MiddleBoss.jpg");
		LastBoss_img = LoadGraph("Resource/LastBoss.jpg");
	}
	void MonsterManager::DrawTask()
	{
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			_p_enemy[index]->Draw();
		}
		_p_boss->Draw();
	}
	void MonsterManager::CalkTask()
	{
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			_p_enemy[index]->CalkTask();
		}
		_p_boss->CalkTask();
	}

	void MonsterManager::MonsterGetPos(int get_pos_x, int get_pos_y, int destination_pos_x, int destination_pos_y)
	{
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			_p_enemy[index]->isActive = true;
			_p_enemy[index]->GetPosition(get_pos_x + (index * 50), get_pos_y + (index * 50),
					   				 destination_pos_x, destination_pos_y);
		}
	}

	void MonsterManager::BossGetPos(int get_pos_x, int get_pos_y, int destination_pos_x, int destination_pos_y)
	{
		_p_boss->isActive = true;
		_p_boss->SetBossMonster((_p_boss->Monster_ID == 1) ? (MiddleBoss_img) : (LastBoss_img) ,
								get_pos_x, get_pos_y,
								destination_pos_x, destination_pos_y);
	}

	void MonsterManager::Finalize()
	{
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			_p_enemy[index]->isActive = false;
		}
		_p_boss->Monster_ID++;
		_p_boss->isActive = false;
	}

	monster::Monster * MonsterManager::GetEnemy(int index)
	{
		return _p_enemy[index];
	}

	monster::BossMonster* MonsterManager::GetBoss()
	{
		return _p_boss;
	}
}