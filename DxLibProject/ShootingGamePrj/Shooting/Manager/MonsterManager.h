#pragma once
//--------------------------------------------------------------
//------------include Header
#include "Singleton.h"
#include "..\Game\Source\Monster.h"

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
		void MonsterGetPos(int, int, int, int, int, int);
		void CalkTask();
		monster::Monster* FindFreeMonster();
		monster::Monster* GetEnemy(int);
		void Finalize();
		
	private:
		monster::Monster _enemy[ENEMY_MAX];

		enum ImageState
		{
			Normal_monster = 0,
			Middle_Boss_monster,
			Last_Boss_monster,
			Image_Max
		};
		ImageState _image = ImageState::Normal_monster;

		int _img[ImageState::Image_Max];

	private:
		friend class singleton::Singleton<MonsterManager>;

	};
}