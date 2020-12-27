#include "StageManager.h"

//--------------------------------------------------------------
//------------include Header
#include "..\Stage\Stage.h"



namespace scene
{
	game::Stage stage;

	/// <summary>
	/// 最初のステージをInitializeする。
	/// </summary>
	void StageManager::Initialize()			
	{
		_stagestate = StageState::Stage01;	//最初のステージを指定する。
		stage.Initialize();
	}

	/// <summary>
	/// Stageの状態によって呼び出すStageを切り替える
	/// </summary>
	void StageManager::Update()
	{
		stage.Update();

		if (this->Stage() == StageState::Result)
		{
			this->Finalize();
		}
	}

	/// <summary>
	/// 最後のStageまでクリア出来たら結果画面を表示する
	/// </summary>
	void StageManager::Finalize()
	{
		SetNextState(State::Result);		//位置最後に結果画面を出す。
	}
}