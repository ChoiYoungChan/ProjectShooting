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
		// Title scene�쐬
		_scene = scene::MakeScene::create(scene::State::Title);
		return true;
	}
	int MainManager::MainLoop()
	{
		_loopcount = 0;
		_scene->Update();
		if (_scene->isSetNextState())									//����scene����������Ă�����scene��؂�ւ�
		{
			_scene->Finalize();											//���݂�scene��Finalize����
			_scene = scene::MakeScene::create(_scene->Nextstate());		//����scene���쐬
		}
		return (_scene->state() != scene::State::Exit);					//Exit scene�ɂȂ�܂łɎ��s����
	}
	void MainManager::Finalize()
	{
		_scene ->Finalize();
	}
}