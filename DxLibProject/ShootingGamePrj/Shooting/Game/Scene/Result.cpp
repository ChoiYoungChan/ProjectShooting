#include "Result.h"

namespace scene
{
	void Result::Initialize()
	{
		PlayMusic("000.mp3", DX_PLAYTYPE_LOOP);
	}
	void Result::Update()
	{
		DrawTask();
		Finalize();
	}
	void Result::DrawTask()
	{
		DrawFormatString(350, 50, GetColor(255, 255, 255), "Result \n", StrWidth);
		DrawBox(0,10,WINDOW_SIZE_X,(WINDOW_SIZE_Y - 10), GetColor(0,200,0), TRUE);
		DrawFormatString(150, 350, GetColor(255,255,255), "Level = %d , Score = %d", 
						 result_stage_number, result_score);
	}
	void Result::Finalize()
	{
		SetNextState(State::Title);
	}
	void Result::GetGameData(bool status ,int stage_number, int score)
	{
		winorlose = status;
		if(winorlose)
		{
			StrLen = strlen("U WIN");
			StrWidth = GetDrawStringWidth("U WIN", StrLen);
		}
		else
		{ 
			StrLen = strlen("U LOSE");
			StrWidth = GetDrawStringWidth("U WIN", StrLen);
		}
		result_stage_number = stage_number;
		result_score = score;
	}
}