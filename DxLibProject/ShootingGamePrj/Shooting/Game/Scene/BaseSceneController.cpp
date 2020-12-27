//--------------------------------------------------------------
//------------include
#include <cassert>
#include "BaseSceneController.h"

//--------------------------------------------------------------
//------------include header
#include "Title.h"
#include "Result.h"
#include "Option.h"
#include "StageManager.h"
#include "Exit.h"

using namespace std;

namespace scene
{
	//stateにアタッチするsceneクラスを生成して返す
	unique_ptr<BaseScene> MakeScene::create(const State state)
	{
		unique_ptr<BaseScene> move_scene;	// 生成scene

		switch (state)
		{
		case State::Title :
			move_scene = make_unique<Title>();
			break;
		case State::InGame:
			move_scene = make_unique<StageManager>();
			break;
		case State::Result:
			move_scene = make_unique<Result>();
			break;
		case State::Options:
			move_scene = make_unique<Option>();
			break;
		case State::Exit:
			move_scene = make_unique<Exit>();
			break;
		default:
			assert(false);							//対応していないクラスはassertする
			break;
		}
		move_scene->Initialize();					//Sceneを初期化する
		return move_scene;
	}
}