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
	/// �ŏ��ɑS�ẴX�e�[�W��Initialize����B
	/// </summary>
	void StageManager::Initialize()			
	{
		_stagestate = StageState::Stage01;	//�ŏ��̃X�e�[�W���w�肷��B
		stage01.Initialize();
		stage02.Initialize();
		stage03.Initialize();
	}

	/// <summary>
	/// Stage�̏�Ԃɂ���ČĂяo��Stage��؂�ւ���
	/// </summary>
	void StageManager::Update()
	{
		switch (_stagestate)				//���݂̃X�e�[�W�󋵂ɂ����InGame��؂�ւ���
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
	/// �Ō��Stage�܂ŃN���A�o�����猋�ʉ�ʂ�\������
	/// </summary>
	void StageManager::Finalize()
	{
		SetNextState(State::Result);		//�ʒu�Ō�Ɍ��ʉ�ʂ��o���B
	}
}