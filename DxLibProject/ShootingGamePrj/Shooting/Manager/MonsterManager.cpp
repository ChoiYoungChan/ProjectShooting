#include "MonsterManager.h"

namespace monstermanager
{
	void MonsterManager::Initialize()
	{
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			_enemy[index].Initialize();
			_enemy[index].isActive = true;
		}
	}
	void MonsterManager::Update()
	{
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			_enemy[index].Update();
		}
		CalkTask();
	}
	void MonsterManager::DrawTask()
	{
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			_enemy[index].Draw();
		}
	}
	void MonsterManager::CalkTask()
	{
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			if (_enemy[index].pos_x > 0 && _enemy[index].pos_x < WINDOW_SIZE_X &&
				_enemy[index].pos_y > 0 && _enemy[index].pos_x < WINDOW_SIZE_Y)
			{
				_bulletmanager->SetBullet(false, _enemy[index].pos_x, _enemy[index].pos_y);
				_bulletmanager->GetMonsterID(_enemy[index].Monster_ID);
			}
		}
	}

	void MonsterManager::MonsterGetPos(int get_pos_x, int get_pos_y, int destination_pos_x, int destination_pos_y)
	{
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			_enemy[index].GetPosition(get_pos_x + (index * 50),
									 get_pos_y + (index * 50),
					   				 destination_pos_x, destination_pos_y);
		}
		boss.GetPosition(get_pos_x, get_pos_y, destination_pos_x, destination_pos_y);
	}

	void MonsterManager::Finalize()
	{
		for (int index = 0; index < ENEMY_MAX; index++)
		{
			_enemy[index].isActive = false;
		}
		boss.isActive = false;
	}

	monster::Monster * MonsterManager::GetEnemy(int index)
	{
		return _enemy + index;
	}
}