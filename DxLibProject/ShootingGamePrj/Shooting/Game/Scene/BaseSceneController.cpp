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
	//state�ɃA�^�b�`����scene�N���X�𐶐����ĕԂ�
	unique_ptr<BaseScene> MakeScene::create(const State state)
	{
		unique_ptr<BaseScene> move_scene;	// ����scene

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
			assert(false);							//�Ή����Ă��Ȃ��N���X��assert����
			break;
		}
		move_scene->Initialize();					//Scene������������
		return move_scene;
	}
}