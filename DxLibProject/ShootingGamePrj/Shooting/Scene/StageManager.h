//--------------------------------------------------------------
//------------include
#pragma once
#include "BaseSceneController.h"

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

	private:
		enum class StageState
		{
			None,

			Stage01,
			Stage02,
			Stage03
		};
		StageState _stagestate = StageState::None;

	};
}