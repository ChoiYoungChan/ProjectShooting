#include "Result.h"

namespace scene
{
	void Result::Initialize()
	{
		printfDx("Result - Initialize");
		PlayMusic("000.mp3", DX_PLAYTYPE_LOOP);
	}
	void Result::Update()
	{
		DrawTask();
		Sleep(10000);
		Finalize();
	}
	void Result::DrawTask()
	{
		printfDx("Result - Update");
	}
	void Result::Finalize()
	{
		SetNextState(State::Title);
	}
	void Result::GetGameData(int stage_number, int score)
	{
		result_stage_number = stage_number;
		result_score = score;
	}
}