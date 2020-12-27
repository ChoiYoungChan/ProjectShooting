#pragma once
#include "Singleton.h"

namespace data
{
	class GameData : public singleton::Singleton
	{
	public:
		GameData()
		{
			Score = 0;
			Player_HP = 3;
		}
		~GameData() = default;
	public:
		void Reset();

	public:
		int Score;
		int Player_HP;

	private:
		friend class singleton::Singleton;
	};
}