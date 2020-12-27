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
		StageState _nextstage = StageState::None;

		void SetNextStage(const StageState nextstage) { _nextstage = nextstage; }
		//bool isNextStage() const { return (_nextstage != StageState::None); }

	private:

		StageState Stage() const { return _stagestate; }
		//StageState NextStage() const { return _nextstage; }
		

	};
}