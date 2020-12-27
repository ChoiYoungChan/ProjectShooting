//--------------------------------------------------------------
//------------include Header
#include "..\Stage\Stage.h"
#include "StageManager.h"

namespace scene
{
	game::Stage stage;

	/// <summary>
	/// �X�e�[�W�Ə��A�I�u�W�F�N�g���������B
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
	/// Stage�̏�Ԃɂ���ČĂяo��Stage��؂�ւ���
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
	/// �Ō��Stage�܂ŃN���A�o�����猋�ʉ�ʂ�\������
	/// </summary>
	void StageManager::Finalize()
	{

	}
}