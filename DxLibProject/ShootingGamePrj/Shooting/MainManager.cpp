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
		// Title scene作成
		_scene = scene::MakeScene::create(scene::State::Title);
		return true;
	}
	int MainManager::MainLoop()
	{
		_loopcount = 0;
		_scene->Update();
		if (_scene->isSetNextState())									//次のsceneが準備されていたらsceneを切り替え
		{
			_scene->Finalize();											//現在のsceneをFinalizeする
			_scene = scene::MakeScene::create(_scene->Nextstate());		//次のsceneを作成
		}
		return (_scene->state() != scene::State::Exit);					//Exit sceneになるまでに実行する
	}
	void MainManager::Finalize()
	{
		_scene ->Finalize();
	}
}