//--------------------------------------------------------------
//------------include Header
#include "PlayerManager.h"

namespace playermanager
{
	void PlayerManager::Initialize()
	{
		_player = new play_user::Player();
		_player->Initialize();
	}
	void PlayerManager::CalkTask()
	{
		_player->CalkTask();
	}

	void PlayerManager::DrawTask()
	{
		_player->DrawTask();
	}

	play_user::Player*PlayerManager::GetPlayer()
	{
		return _player;
	}
	void PlayerManager::Finalize()
	{
		_player->Finalize();
	}
}