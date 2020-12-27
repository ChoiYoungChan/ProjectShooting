#pragma once
#include <cassert>
#include "BaseSceneController.h"
#include "Manager/InputKey.h"

namespace scene
{
	class Option : public BaseScene
	{
	public:
		Option() :BaseScene(State::Options)
		{
			OPTION_MEUNU = 3;
			MUTE_MENU = 2;
			mute_option_menu = 1;
		}
		~Option() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;

	private:
		int Select_menu_num;
		int mute_option_menu;
		int OPTION_MEUNU, MUTE_MENU;
		const int MENU_SELECT_POS_X = 80;
		const int MENU_UNSELECT_POS_Y = 100;
		const int MUTE_SELECT_POS_Y = 200, MUTE_UNSELECT_POS_Y = -50;

	private:
		typedef struct
		{
			int menu_pos_x, menu_pos_y;
			char name[256];

		}OptionMenuElement_t;

		OptionMenuElement_t OptionMenuElement[2] =
		{
			{ MENU_SELECT_POS_X, 200, "BGM MUTE"},
			{100, 400, "Back to Title"},
		};
		OptionMenuElement_t option[3]
		{
			{ 200, 200, "OFF"},
			{ 200, 200, "ON"}
		};

	private:
		void MuteFunction();
		void Draw();
		void CalcTask();


	};
}