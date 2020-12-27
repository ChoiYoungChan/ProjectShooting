#include "DxLib.h"

void DrawTask();

int WINDOW_SIZE_X = 720, WINDOW_SIZE_Y = 720;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32);

	if (DxLib_Init() == -1) { return -1; }

	while (ScreenFlip() == 0 && ProcessMessage() == 0)
	{
		DrawTask();



	}

	DxLib_End();
	return 0;
}
void DrawTask()
{
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);
}