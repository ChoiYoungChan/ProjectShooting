#pragma once
#include "Singleton.h"

namespace data
{
	class GameData
	{
	public:
		GameData()
		{
			Score = 0;
			Player_HP = 30;
		}
		~GameData() = default;
	public:
		void Reset();

	public:
		int Score;
		int Player_HP;

	private:
	};
}