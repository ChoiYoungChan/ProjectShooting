//--------------------------------------------------------------
//------------include
#pragma once
#include "BaseSceneController.h"
#include "Result.h"
#include "..\..\Manager\GameData.h"

namespace scene
{
	class StageManager : public BaseScene
	{
	public:
		StageManager() : BaseScene(State::InGame)
		{}
		~StageManager() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;

		enum StageState							//現在のStageを管理するためのenum class
		{
			Stage01 = 0,
			Stage02,
			Stage03,
			Stage_Max
		};
		StageState _stagestate;

		StageState Stage() const { return _stagestate; }

	private:
		
	};
}