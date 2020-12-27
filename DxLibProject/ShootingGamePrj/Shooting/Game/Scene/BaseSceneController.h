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
		//重複禁止
		BaseScene(const BaseScene&) = delete;
		BaseScene& operator = (const BaseScene&) = delete;
		BaseScene(BaseScene&&) = delete;
		BaseScene& operator = (BaseScene&&) = delete;

	public:
		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void Finalize() = 0;

		//現在のState
		State state() const
		{
			return _state;
		}
		//次のState
		State Nextstate() const
		{
			return _NextState;
		}
		//次のStateを指定
		void SetNextState(const State next)
		{
			_NextState = next;
		}
		//State::None以外が返ってきたらこのシーンに差し替えることを判別
		bool isSetNextState() const
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
		MakeScene() = delete;
		~MakeScene() = delete;

		// Sceneクラス インスタンス生成
		static std::unique_ptr<BaseScene> create(const State state);

	private:
		//重複禁止
		MakeScene(const MakeScene&) = delete;
		MakeScene& operatior(const MakeScene&) = delete;
		MakeScene(MakeScene&&) = delete;
		MakeScene& operatior(MakeScene&&) = delete;

	};
}