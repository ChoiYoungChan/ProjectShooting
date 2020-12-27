#pragma once
//--------------------------------------------------------------
//------------include Header
#include "DxLib.h"
#include "..\Game\Source\Player.h"
#include "Singleton.h"

namespace playermanager
{
	class  PlayerManager : public singleton::Singleton<PlayerManager>
	{
	public:
		 PlayerManager() = default;
		~ PlayerManager() = default;

	public:
		void Initialize();
		void DrawTask();
		void CalkTask();
		void Finalize();

		play_user::Player* GetPlayer();

	private:
		play_user::Player* _player;
		friend class singleton::Singleton<PlayerManager>;

	};
}