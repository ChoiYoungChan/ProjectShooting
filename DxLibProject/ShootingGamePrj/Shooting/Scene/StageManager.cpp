#include "StageManager.h"

//--------------------------------------------------------------
//------------include Header
#include "Stage/Stage_01.h"
#include "Stage/Stage_02.h"
#include "Stage/Stage_03.h"


namespace scene
{
	game::Stage01 stage01;
	game::Stage02 stage02;
	game::Stage03 stage03;

	/// <summary>
	/// 最初に全てのステージをInitializeする。
	/// </summary>
	void StageManager::Initialize()			
	{
		_stagestate = StageState::Stage01;	//最初のステージを指定する。
		stage01.Initialize();
		stage02.Initialize();
		stage03.Initialize();
	}

	/// <summary>
	/// Stageの状態によって呼び出すStageを切り替える
	/// </summary>
	void StageManager::Update()
	{
		switch (_stagestate)				//現在のステージ状況によってInGameを切り替える
		{
		case StageState::Stage01 :
			stage01.Update();
			break;

		case StageState::Stage02:
			stage02.Update();
			break;

		case StageState::Stage03:
			stage03.Update();
			break;
		case StageState::Result:
			SetNextState(State::Result);
			break;
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