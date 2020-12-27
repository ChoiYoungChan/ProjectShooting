#include "StageManager.h"

//--------------------------------------------------------------
//------------include Header
#include "Stage/Stage_01.h"
#include "Stage/Stage_02.h"
#include "Stage/Stage_03.h"


namespace scene
{
	game::Stage01 stage01;
	game::Stage02 stage02;
	game::Stage03 stage03;

	void StageManager::Initialize()
	{
		_stagestate = StageState::Stage01;
		stage01.Initialize();
		stage02.Initialize();
		stage03.Initialize();
	}
	void StageManager::Update()
	{
		switch (_stagestate)
		{
		case StageState::Stage01 :
			stage01.Update();
			break;

		case StageState::Stage02:
			stage02.Update();
			break;

		case StageState::Stage03:
			stage03.Update();
			break;
		}
	}
	void StageManager::Finalize()
	{
		SetNextState(State::Result);
	}
}