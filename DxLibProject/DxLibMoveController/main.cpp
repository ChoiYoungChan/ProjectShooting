#include "DxLib.h"

void WindowTask();
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

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	WindowTask();

	if (DxLib_Init() == -1)
	{
		return -1;
	}

	int speed = 30;
	int pos_x = 200, pos_y = 200;
	int image = LoadGraph("Bullet_0001.png");

	while (ScreenFlip() == 0 && ClearDrawScreen() == 0 && ProcessMessage() == 0 && InputKeyValue() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);
		if (key[KEY_INPUT_RIGHT] >= 1) { 
			pos_x += speed;                      
		}
		if (key[KEY_INPUT_DOWN] >= 1) { 
			pos_y += speed;
		}
		if (key[KEY_INPUT_LEFT] >= 1) { 
			pos_x -= speed;
		}
		if (key[KEY_INPUT_UP] >= 1) { 
			pos_y -= speed;
		}

		DrawRotaGraph(pos_x, pos_y, 1, 0, image, true);

		ScreenFlip();

		if (pos_y <= 0)
			pos_y = 720;

		Sleep(1000 / 60);
	}

	DxLib_End();
	return 0;
}
void WindowTask()
{
	ChangeWindowMode(true);
	SetGraphMode(480, 680, 32);
}