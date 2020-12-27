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
		BaseScene(const State state) : _state(state) {}
		virtual ~BaseScene() = default;

	private:
		BaseScene(const BaseScene&) = delete;
		BaseScene& operator = (const BaseScene&) = delete;
		BaseScene(BaseScene&&) = delete;
		BaseScene& operator = (BaseScene&&) = delete;

	public:
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Finalize() = 0;

		State state() const
		{
			return _state;
		}
		State Nextstate() const
		{
			return _NextState;
		}
		void SetNextState(const State next)
		{
			_NextState = next;
		}
		bool isSetNextState() const
		{
			return (_NextState != State::None && _NextState != State::SceneCount);
		}
	private:
		State _state = State::None;
		State _NextState = State::None;
	};

	class MakeScene
	{
	public:
		static std::unique_ptr<BaseScene> create(const State state);

	private:
		MakeScene() = delete;
		~MakeScene() = delete;

		MakeScene(const MakeScene&) = delete;
		MakeScene& operatior(const MakeScene&) = delete;
		MakeScene(MakeScene&&) = delete;
		MakeScene& operatior(MakeScene&&) = delete;

	};
}