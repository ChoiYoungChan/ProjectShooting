//=================================
// include
#include "DxLib.h"
//=================================
// include header

//=================================
// function& struct
int key[256];
int InputKeyValue()
{
	char tmpkey[256];
	GetHitKeyStateAll(tmpkey);
	for (int index = 0; index < 256; index++)
	{
		if (tmpkey[index] != 0)
			key[index] ++;
		else
			key[index] = 0;
	}
	return 0;
}
typedef struct
{
	int menu_pos_x, menu_pos_y;
	char name[256];

}MenuElement_t;

//=================================
// Global var

int SelectNumber;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);
	SetGraphMode(480, 680, 32);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	
	MenuElement_t MenuElement[3] =
	{
		{80,200, "Start Game"},
		{100, 300, "Options"},
		{100, 400, "Exit Game"},
	};
	SelectNumber = 0;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && InputKeyValue() == 0)
	{
		SetDrawScreen(DX_SCREEN_BACK);		
		if (key[KEY_INPUT_DOWN] == 1)
		{
			SelectNumber = (SelectNumber + 1) % 3;
		}
		if (key[KEY_INPUT_UP] == 1)
		{
			SelectNumber = (SelectNumber + 2) % 3;
		}
		if (key[KEY_INPUT_DOWN] == 1 || key[KEY_INPUT_UP] == 1)
		{
			for (int menu_number = 0; menu_number < 3; menu_number++)
			{
				if (menu_number == SelectNumber)
				{
					MenuElement[menu_number].menu_pos_x = 80;
				}
				else
					MenuElement[menu_number].menu_pos_x = 100;
			}
		}
		for (int draw_menu = 0; draw_menu < 3; draw_menu++)
		{
			DrawFormatString(MenuElement[draw_menu].menu_pos_x, MenuElement[draw_menu].menu_pos_y,
				GetColor(255, 255, 255), MenuElement[draw_menu].name);
		}
	}

	DxLib_End();
	return 0;
}