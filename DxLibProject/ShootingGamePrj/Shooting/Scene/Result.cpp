#include "Result.h"

namespace scene
{
	void Result::Initialize()
	{
		printfDx("Result - Initialize");
	}
	void Result::Update()
	{
		printfDx("Result - Update");
	}
	void Result::Finalize()
	{
		printfDx("Result - Good Bye");
	}
	void Result::GetGameData(int stage_number, int score)
	{
		result_stage_number = stage_number;
		result_score = score;
	}
}