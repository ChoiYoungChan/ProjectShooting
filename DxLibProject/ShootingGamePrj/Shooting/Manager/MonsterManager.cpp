//--------------------------------------------------------------
//------------include Header
#include "MonsterManager.h"

namespace monstermanager
{
	void MonsterManager::Initialize()
	{
		for (int index = ZERO; index < ENEMY_MAX; index++)
		{
			_enemy[index].Initialize();
		}
		_img[ImageState::Normal_monster] = LoadGraph("Resource/Monster_0001.png");
		_img[ImageState::Middle_Boss_monster] = LoadGraph("Resource/MiddleBoss.jpg");
		_img[ImageState::Last_Boss_monster] = LoadGraph("Resource/LastBoss.jpg");
	}

	/// <summary>
	/// モンスターを描画
	/// </summary>
	void MonsterManager::DrawTask()
	{
		for (int index = ZERO; index < ENEMY_MAX; index++)
		{
			if (!_enemy[index]._isActive)
				continue;
			_enemy[index].Draw();
		}
	}

	/// <summary>
	/// モンスターで計算する関数を呼び出す
	/// </summary>
	void MonsterManager::CalkTask()
	{
		for (int index = ZERO; index < ENEMY_MAX; index++)
		{
			if (!_enemy[index]._isActive)
				continue;
			_enemy[index].CalkTask();
		}
	}

	monster::Monster * MonsterManager::FindFreeMonster()
	{
		for (int count = 0; count < ENEMY_MAX; count++)
		{
			if (!_enemy[count]._isActive)
			{
				return &_enemy[count];
			}
		}
		return NULL;
	}

	/// <summary>
	/// モンスターの数、位置と移動する目的地、イメージを設定する
	/// </summary>
	/// <param name="Enemy_count">表示するモンスターの数</param>
	/// <param name="get_pos_x">モンスターのX軸</param>
	/// <param name="get_pos_y">モンスターのY軸</param>
	/// <param name="destination_pos_x">目的地のX軸</param>
	/// <param name="destination_pos_y">目的地のY軸</param>
	void MonsterManager::MonsterGetPos(int type, int Enemy_count, 
									   int get_pos_x,int get_pos_y, 
									   int destination_pos_x,int destination_pos_y)
	{
		for (int index = ZERO; index < Enemy_count; index++)
		{
			monster::Monster* _monster = FindFreeMonster();

			if (_monster == NULL)
			{
				return;
			}

			int _monster_img;

			switch (type)
			{
			case NORMAL_MONSTER_ID:
				_monster_img = _img[ImageState::Normal_monster];
				break;
			case BOSS_MONSTER_ID:
				_monster_img = _img[ImageState::Middle_Boss_monster];
				break;
			case LAST_BOSS_MONSTER_ID:
				_monster_img = _img[ImageState::Last_Boss_monster];
				break;
			}
			_monster->_isActive = true;
			_monster->GetPosition(type, _monster_img,
				get_pos_x + (index * 61), get_pos_y + (index * 81),
				destination_pos_x, destination_pos_y);
		}
	}

	/// <summary>
	/// モンスターの情報などを受け取るために戻位置としてモンスターを指定
	/// </summary>
	/// <param name="index"></param>
	/// <returns></returns>
	monster::Monster * MonsterManager::GetEnemy(int index)
	{
		return _enemy + index;
	}

	void MonsterManager::Finalize()
	{

	}
}