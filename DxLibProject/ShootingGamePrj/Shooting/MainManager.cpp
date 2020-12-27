//--------------------------------------------------------------
//------------include
#include <cassert>
#include "MainManager.h"
#include "Scene/BaseSceneController.h"
#include "Scene/Title.h"



namespace MainManager
{
	bool MainManager::Initialize()
	{
		_scene = scene::MakeScene::create(scene::State::Title);
		return true;
	}
	int MainManager::MainLoop()
	{
		_loopcount = 0;
		_scene->Update();
		if (_scene->isSetNextState())
		{
			_scene->Finalize();
			_scene = scene::MakeScene::create(_scene->Nextstate());
		}
		return (_scene->state() != scene::State::Exit);
	}
	void MainManager::Finalize()
	{
		_scene ->Finalize();
	}
}