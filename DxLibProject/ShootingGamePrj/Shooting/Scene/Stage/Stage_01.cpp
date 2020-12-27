#include "Stage_01.h"

namespace game
{
	void Stage01::Initialize()
	{
		user.Initialize();						//�v���C���[��Initialize����
		monster_enemy.Initialize();				//�����X�^�[��Initialize����
	}

	void Stage01::Update()
	{
		_time_count = GetNowCount();			//Stage01�̎��Ԃ�����Ēe����������ۂɎg���ϐ�
		CalkTask();								//�Փ˔�����v�Z����֐�
		Draw();									//�����X�^�[�ƃv���C���[��\������֐�
	}

	void Stage01::Finalize()
	{
		
	}

	void Stage01::Draw()
	{
		user.Update();							//�v���C���[�̈ړ���\���Ȃǂ�K�p����
		monster_enemy.Update();					//�����X�^�[�̈ړ���\���Ȃǂ�K�p����
	}
	void Stage01::CalkTask()
	{
		ImpackCalk();

	}
	void Stage01::ImpackCalk()
	{

	}
}