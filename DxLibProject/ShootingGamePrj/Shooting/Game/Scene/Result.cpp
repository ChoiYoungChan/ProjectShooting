#include "Result.h"

namespace scene
{
	void Result::Initialize()
	{
		_begin_time = GetNowCount();
		PlayMusic("000.mp3", DX_PLAYTYPE_LOOP);
	}
	void Result::Update()
	{
		_inLoop_time = GetNowCount();
		CalkTask();
		DrawTask();
	}
	void Result::DrawTask()
	{
		DrawBox(0,10,WINDOW_SIZE_X,WINDOW_SIZE_Y, GetColor(0,200,0), TRUE);

		SetFontSize(40);
		DrawFormatString(300, 50, GetColor(255, 255, 255), "Result \n");

		SetFontSize(30);
		DrawFormatString(250, 300, GetColor(255,255,255), "Level = %d\nScore = %d", 
			data::GameData::Instance().Stage_Level,
			data::GameData::Instance().Score);
		SetFontSize(15);
		DrawFormatString(250, 400, GetColor(255, 255, 255), "15ïbå„TitleÇ…ñﬂÇËÇ‹Ç∑");

		for (int _menu_number = 0; _menu_number < _RESULT_MENU; _menu_number++)
		{
			if (_menu_number == _G_SelectNumber)
			{
				_COLOR = _MENU_SELECT;
			}
			else
				_COLOR = _MENU_UNSELECT;

			DrawFormatString(MenuElement[_menu_number].menu_pos_x, MenuElement[_menu_number].menu_pos_y,
				_COLOR, MenuElement[_menu_number].name);
		}
	}

	void Result::CalkTask()
	{
		if (keyboard::GetKey(KEY_INPUT_RIGHT) == 1)
		{
			_G_SelectNumber = (_G_SelectNumber + 1) % _RESULT_MENU;
		}
		if (keyboard::GetKey(KEY_INPUT_LEFT) == 1)
		{
			_G_SelectNumber = (_G_SelectNumber + 1) % _RESULT_MENU;
		}
		if (keyboard::GetKey(KEY_INPUT_SPACE) == 1)
		{
			switch (_G_SelectNumber)
			{
			case 0:
				SetNextState(State::Title);
				break;
			case 1:
				SetNextState(State::Exit);
				break;
			default:
				break;
			}
		}
		int nowtime = (_inLoop_time - _begin_time) / 1000;

		if (nowtime == BACK_TO_TITLE)
		{
 			SetNextState(State::Title);
		}
	}

	void Result::Finalize()
	{
		
	}
}