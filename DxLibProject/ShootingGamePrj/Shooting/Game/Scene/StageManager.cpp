#include "StageManager.h"

//--------------------------------------------------------------
//------------include Header
#include "..\Stage\Stage.h"



namespace scene
{
	game::Stage stage;

	/// <summary>
	/// �ŏ��̃X�e�[�W��Initialize����B
	/// </summary>
	void StageManager::Initialize()			
	{
		_stagestate = StageState::Stage01;	//�ŏ��̃X�e�[�W���w�肷��B
		stage.Initialize();
	}

	/// <summary>
	/// Stage�̏�Ԃɂ���ČĂяo��Stage��؂�ւ���
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
	/// �Ō��Stage�܂ŃN���A�o�����猋�ʉ�ʂ�\������
	/// </summary>
	void StageManager::Finalize()
	{
		SetNextState(State::Result);		//�ʒu�Ō�Ɍ��ʉ�ʂ��o���B
	}
}