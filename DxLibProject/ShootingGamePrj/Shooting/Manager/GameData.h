#pragma once
//--------------------------------------------------------------
//------------include Header
#include "Singleton.h"

namespace data
{
	class GameData : public singleton::Singleton<GameData>
	{
	public:
		GameData() = default;
		~GameData() = default;
	public:
		void Reset();

	public:
		int Score;
		int Player_HP;
		int Stage_Level;
	private:
		friend class singleton::Singleton<GameData>;
	};

}