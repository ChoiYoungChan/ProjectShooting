#pragma once
//=================================
// include
#include "BaseSceneController.h"
#include <cassert>

namespace scene
{
	class Title : public BaseScene
	{
	public:
		Title() :BaseScene(State::Title) {}
		~Title() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;

	private:
		int G_SelectNumber;											// 選択されたメニュー
		int MENU;													// メニューの数
		int MENU_SELECT_POS_X = 80, MENU_UNSELECT_POS_X = 100;		// 選択されたメニューを区分するためのｘ軸座標
	private:
		typedef struct
		{
			int menu_pos_x, menu_pos_y;
			char name[256];

		}MenuElement_t;

		MenuElement_t MenuElement[3] =
		{
			{ MENU_SELECT_POS_X, 200, "Start Game"},
			{100, 300, "Options"},
			{100, 400, "Exit Game"},
		};
	};
}