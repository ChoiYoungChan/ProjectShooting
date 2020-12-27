//=================================
// include
#include "Option.h"
#include "Title.h"
#include "StageManager.h"
#include "Result.h"

namespace scene
{
	Title title;
	StageManager st_manager;
	Result result;

	void Option::Initialize()
	{
		SetBackgroundColor(0, 200, 0);
		Select_menu_num = 0;
		PlaySound("", DX_PLAYTYPE_BACK);
	}
	void Option::Update()
	{
		if (keyboard::GetKey(KEY_INPUT_DOWN))
		{
			Select_menu_num = (Select_menu_num + 1) % OPTION_MEUNU;
		}
		if (keyboard::GetKey(KEY_INPUT_UP))
		{
			Select_menu_num = (Select_menu_num + 1) % OPTION_MEUNU;
		}
		if (keyboard::GetKey(KEY_INPUT_LEFT))
		{

		}
		if (keyboard::GetKey(KEY_INPUT_RIGHT))
		{

		}
		for (int _menu_number = 0; _menu_number < OPTION_MEUNU; _menu_number++)
		{
			if (_menu_number == Select_menu_num)
			{
				OptionMenuElement[_menu_number].menu_pos_x = MENU_SELECT_POS_X;
				option[_menu_number].menu_pos_y = MUTE_SELECT_POS_Y;
			}
			else
			{
				OptionMenuElement[_menu_number].menu_pos_x = MENU_UNSELECT_POS_Y;
				option[_menu_number].menu_pos_y = MUTE_UNSELECT_POS_Y;
			}

			DrawFormatString(OptionMenuElement[_menu_number].menu_pos_x, OptionMenuElement[_menu_number].menu_pos_y,
				GetColor(255, 255, 255), OptionMenuElement[_menu_number].name);
			DrawFormatString(option[Select_menu_num].menu_pos_x, option[Select_menu_num].menu_pos_y,
				GetColor(255, 255, 255), option[Select_menu_num].name);
		}
		

		if (keyboard::GetKey(KEY_INPUT_SPACE) == 1)
		{
			switch (Select_menu_num)
			{
			case 0:
				for (int _menu_number = 0; _menu_number < MUTE_MENU; _menu_number++)
				{
					if (_menu_number == Select_menu_num)
					{
						option[_menu_number].menu_pos_y = MUTE_SELECT_POS_Y;
					}
					else
					{
						option[_menu_number].menu_pos_x = MUTE_UNSELECT_POS_Y;
					}
					DrawFormatString(option[_menu_number].menu_pos_x, option[_menu_number].menu_pos_y,
						GetColor(255, 255, 255), option[_menu_number].name);
				}
				break;
			case 1:
				Finalize();
				break;

			default:
				assert(false);
				break;
			}
		}
	}
	void Option::Finalize()
	{
		SetNextState(State::Title);
	}
	void Option::MuteFunction()
	{
		title.SoundController();

	}
}