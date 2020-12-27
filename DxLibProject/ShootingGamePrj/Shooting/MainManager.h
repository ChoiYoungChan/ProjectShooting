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
		int _loopcount;					//loop‚µ‚½”‚ğCount‚µ‚ÄInitialize‚ğˆê‰ñ‚¾‚¯Às‚·‚é‚½‚ß‚Éİ’è

	private:
		friend class manager::Singleton<MainManager>;

	private:
		std::unique_ptr<scene::BaseScene> _scene;		//Às’†‚Ìscene
	};
}