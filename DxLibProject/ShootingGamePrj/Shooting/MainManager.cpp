//--------------------------------------------------------------
//------------include
#include "MainManager.h"
#include "Game/Scene/BaseSceneController.h"
#include "Game/Scene/Title.h"

namespace MainManager
{
	bool MainManager::Initialize()
	{
		// Title sceneì¬
		_scene = scene::MakeScene::create(scene::State::Title);			//Å‰‚ÌState‚Íƒƒjƒ…Title
		return true;
	}
	
	int MainManager::MainLoop()
	{
		_scene->Update();
		if (_scene->isSetNextState())									//ŽŸ‚Ìscene‚ª€”õ‚³‚ê‚Ä‚¢‚½‚çscene‚ðØ‚è‘Ö‚¦
		{
			_scene->Finalize();											//Œ»Ý‚Ìscene‚ðFinalize‚·‚é
			_scene = scene::MakeScene::create(_scene->Nextstate());		//ŽŸ‚Ìscene‚ðì¬
		}
		return (_scene->state() != scene::State::Exit);					//Exit scene‚É‚È‚é‚Ü‚Å‚ÉŽÀs‚·‚é
	}
	void MainManager::Finalize()
	{
		_scene ->Finalize();
	}
}