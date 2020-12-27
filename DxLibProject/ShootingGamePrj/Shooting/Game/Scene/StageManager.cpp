//--------------------------------------------------------------
//------------include Header
#include "..\Stage\Stage.h"
#include "StageManager.h"

namespace scene
{
	game::Stage stage;

	/// <summary>
	/// ステージと情報、オブジェクトを初期化。
	/// </summary>
	void StageManager::Initialize()			
	{
		_stagestate = StageState::Stage01;

		stage.InitVar();
		PLAYER_MANAGER().Initialize();
		MONSTER_MANAGER().Initialize();
		BULLET_MANAGER().Initialize();

		stage.Initialize();
	}

	/// <summary>
	/// Stageの状態によって呼び出すStageを切り替える
	/// </summary>
	void StageManager::Update()
	{
		stage.Update();

		if (stage._NextState)
		{
			this->Finalize();
			SetNextState(State::Result);
		}
	}

	/// <summary>
	/// 最後のStageまでクリア出来たら結果画面を表示する
	/// </summary>
	void StageManager::Finalize()
	{

	}
}