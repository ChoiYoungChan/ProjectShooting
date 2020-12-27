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
		BaseScene(const BaseScene&) = delete;					//重複禁止
		BaseScene& operator = (const BaseScene&) = delete;
		BaseScene(BaseScene&&) = delete;
		BaseScene& operator = (BaseScene&&) = delete;

	public:
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Finalize() = 0;

		State state() const										//現在のState
		{
			return _state;
		}
		State Nextstate() const									//次のState
		{
			return _NextState;
		}
		void SetNextState(const State next)						//次のStateを指定
		{
			_NextState = next;
		}
		bool isSetNextState() const						//State::None以外が返ってきたらこのシーンに差し替える
		{
			return (_NextState != State::None);
		}
	private:
		State _state = State::None;						//担当するシーン
		State _NextState = State::None;					//次に実行するシーン
	};

	class MakeScene
	{
	public:
		// Sceneクラス インスタンス生成
		static std::unique_ptr<BaseScene> create(const State state);

	private:
		MakeScene() = delete;
		~MakeScene() = delete;

		MakeScene(const MakeScene&) = delete;									//重複禁止
		MakeScene& operatior(const MakeScene&) = delete;
		MakeScene(MakeScene&&) = delete;
		MakeScene& operatior(MakeScene&&) = delete;

	};
}