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
		int _loopcount;					//loop‚µ‚½”‚ğCount‚µ‚ÄInitialize‚ğˆê‰ñ‚¾‚¯Às‚·‚é‚½‚ß‚Éİ’è

	private:
		std::unique_ptr<scene::BaseScene> _scene;		//Às’†‚Ìscene
	};
}