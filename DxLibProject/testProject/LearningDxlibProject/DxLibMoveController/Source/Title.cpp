#include "Dxlib.h"

namespace scene
{/*
	typedef struct
	{
		int menu_x, menu_y;
		char name[128];

	}MenuElement_type;

	int key[256];

	int InputKeyValue()
	{
		char tmpkey[256];
		GetHitKeyStateAll(tmpkey);
		for (int index = 0; index < 256; index++)
		{
			if (tmpkey[index] != 0)
				key[index] = 1;
			else
				key[index] = 0;
		}
		return 0;
	}
	int Menu_number;
	
	int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
	{
		MenuElement_type element[3] =
		{
			{80,100,"GameStart"},
			{100,150,"BGM Mute"},
			{100, 200, "Exit Game"}
		};
		int SelectNum = 0;

		while (ProcessMessage() == 0)
		{
			if (key[KEY_INPUT_DOWN] >= 1)
			{
				SelectNum = (SelectNum + 1) % Menu_number;
			}
			if (key[KEY_INPUT_UP] >= 1)
			{
				SelectNum = (SelectNum + 2) % Menu_number;
			}
			if (key[KEY_INPUT_DOWN] >= 1 || key[KEY_INPUT_UP] >= 1)
			{
				for (int index = 0; index < Menu_number; index++)
				{
					if (index == SelectNum)
					{
						element[index].menu_x = 80;
					}
					else
					{
						element[index].menu_x = 100;
					}
				}
			}

			for (int index = 0; index < Menu_number; index++)
			{
				DrawFormatString(element[index].menu_x, element[index].menu_y,
					GetColor(255, 255, 255), element[index].name);
			}

		}
	}*/
}
