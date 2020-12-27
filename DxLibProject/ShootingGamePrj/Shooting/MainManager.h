#pragma once
//--------------------------------------------------------------
//------------include
#include <memory>
#include "Game/Scene/BaseSceneController.h"
#include "Manager/InputKey.h"

namespace MainManager
{
	class MainManager
	{
	public:
		MainManager()
		{
			_loopcount = 0;
		}
		~MainManager() = default;

		bool Initialize();
		int MainLoop();
		void Finalize();

	public:
		int _loopcount;					//loop��������Count����Initialize����񂾂����s���邽�߂ɐݒ�

	private:
		std::unique_ptr<scene::BaseScene> _scene;		//���s����scene
	};
}