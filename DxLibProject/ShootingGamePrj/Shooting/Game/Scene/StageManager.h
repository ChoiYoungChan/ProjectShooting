//--------------------------------------------------------------
//------------include
#pragma once
#include "BaseSceneController.h"
#include "..\..\Manager\GameData.h"

namespace scene
{
	class StageManager : public BaseScene
	{
	public:
		StageManager() : BaseScene(State::InGame) {}
		~StageManager() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;

		enum class StageState							//Œ»İ‚ÌStage‚ğŠÇ—‚·‚é‚½‚ß‚Ìenum class
		{
			None,

			Stage01,
			Stage02,
			Stage03,
			Result
		};
		StageState _stagestate = StageState::None;
	private:
		

	};
}