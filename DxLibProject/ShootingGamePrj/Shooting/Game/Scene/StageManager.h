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

		enum class StageState							//���݂�Stage���Ǘ����邽�߂�enum class
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