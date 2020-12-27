#pragma once
//--------------------------------------------------------------
//------------include
#include "SceneStateh.h"
#include <memory>
#include "DxLib.h"
#include "Manager/InputKey.h"

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
		virtual ~BaseScene() = default;

	private:
		BaseScene(const BaseScene&) = delete;					//�d���֎~
		BaseScene& operator = (const BaseScene&) = delete;
		BaseScene(BaseScene&&) = delete;
		BaseScene& operator = (BaseScene&&) = delete;

	public:
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Finalize() = 0;

		State state() const										//���݂�State
		{
			return _state;
		}
		State Nextstate() const									//����State
		{
			return _NextState;
		}
		void SetNextState(const State next)						//����State���w��
		{
			_NextState = next;
		}
		bool isSetNextState() const						//State::None�ȊO���Ԃ��Ă����炱�̃V�[���ɍ����ւ���
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
		// Scene�N���X �C���X�^���X����
		static std::unique_ptr<BaseScene> create(const State state);

	private:
		MakeScene() = delete;
		~MakeScene() = delete;

		MakeScene(const MakeScene&) = delete;									//�d���֎~
		MakeScene& operatior(const MakeScene&) = delete;
		MakeScene(MakeScene&&) = delete;
		MakeScene& operatior(MakeScene&&) = delete;

	};
}