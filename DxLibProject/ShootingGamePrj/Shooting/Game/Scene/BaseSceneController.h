#pragma once
//--------------------------------------------------------------
//------------include
#include "SceneStateh.h"
#include <memory>
#include "DxLib.h"
#include "..\..\Manager\InputKey.h"

extern int WINDOW_SIZE_X;
extern int WINDOW_SIZE_Y;


namespace scene
{
	class BaseScene
	{
	public:
		BaseScene() = default;
		BaseScene(const State state)
		{
			_state = state;
		}
		~BaseScene() = default;

	private:
		//�d���֎~
		BaseScene(const BaseScene&) = delete;
		BaseScene& operator = (const BaseScene&) = delete;
		BaseScene(BaseScene&&) = delete;
		BaseScene& operator = (BaseScene&&) = delete;

	public:
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Finalize() = 0;

		//���݂�State
		State state() const
		{
			return _state;
		}
		//����State
		State Nextstate() const
		{
			return _NextState;
		}
		//����State���w��
		void SetNextState(const State next)
		{
			_NextState = next;
		}
		//State::None�ȊO���Ԃ��Ă����炱�̃V�[���ɍ����ւ��邱�Ƃ𔻕�
		bool isSetNextState() const
		{
			return (_NextState != State::None);
		}
	private:
		State _state = State::None;						//�S������V�[��
		State _NextState = State::None;					//���Ɏ��s����V�[��
	};

	class MakeScene
	{
	public:
		MakeScene() = delete;
		~MakeScene() = delete;

		// Scene�N���X �C���X�^���X����
		static std::unique_ptr<BaseScene> create(const State state);

	private:
		//�d���֎~
		MakeScene(const MakeScene&) = delete;
		MakeScene& operatior(const MakeScene&) = delete;
		MakeScene(MakeScene&&) = delete;
		MakeScene& operatior(MakeScene&&) = delete;

	};
}