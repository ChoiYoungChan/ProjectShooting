#pragma once
//--------------------------------------------------------------
//------------include
#include <memory>
#include "Scene/BaseSceneController.h"
#include "Scene/Manager/Singleton.h"
#include "Scene/Manager/InputKey.h"


namespace MainManager
{
	class MainManager : public manager::Singleton<MainManager>
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
		int _loopcount;					//loopした数をCountしてInitializeを一回だけ実行するために設定

	private:
		friend class manager::Singleton<MainManager>;

	private:
		std::unique_ptr<scene::BaseScene> _scene;		//実行中のscene
	};
}