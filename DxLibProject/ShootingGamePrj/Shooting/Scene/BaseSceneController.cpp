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

using namespace std;

namespace scene
{
	unique_ptr<BaseScene> MakeScene::create(const State state)
	{
		unique_ptr<BaseScene> move_scene;

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
		default:
			assert(false);
			break;
		}
		move_scene->Initialize();
		return move_scene;
	}
}