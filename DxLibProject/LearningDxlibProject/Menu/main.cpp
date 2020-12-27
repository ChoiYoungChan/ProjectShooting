//=================================
// include
#include "DxLib.h"
//=================================
// include header

//=================================
// function& struct
void InputKey()
{
	char keyvalue[256];
	GetHitKeyStateAll(keyvalue);
	for (int index = 0; index < 256; index++)
	{
		if (keyvalue[index] != 0)
			keyvalue[index] = 1;
		else
			keyvalue[index] = 0;
	}
}
typedef struct
{
	int menu_pos_x, menu_pos_y;
	char name[256];

}MenuElement_t;

//=================================
// Global var
int key[256];
int SelectNumber;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);
	SetGraphMode(480,680,32);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	

	MenuElement_t MenuElement[5] =
	{
		{80,100, "Start Game"},
		{100, 150, "Options"},
		{100, 200, "Record"},
		{100, 250, "Ranking"},
		{100, 300, "Exit Game"},
	};
	SelectNumber = 0;

	while (ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SetDrawScreen(DX_SCREEN_BACK);
		InputKey();
		if (key[KEY_INPUT_DOWN] == 1)
		{
			SelectNumber = (SelectNumber + 1) % 5;
			for (int menu_number = 0; menu_number < 5; menu_number++)
			{
				if (menu_number == SelectNumber)
				{
					MenuElement[menu_number].menu_pos_x = 80;
				}
				else
					MenuElement[menu_number].menu_pos_x = 100;
			}
		}
		for (int draw_menu = 0; draw_menu < 5; draw_menu++)
		{
			DrawFormatString(MenuElement[draw_menu].menu_pos_x, MenuElement[draw_menu].menu_pos_y,
				             GetColor(255,255,255), MenuElement[draw_menu].name);
		}
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}