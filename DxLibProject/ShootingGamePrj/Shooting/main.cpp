//--------------------------------------------------------------
//------------include Header
#include "DxLib.h"
#include "MainManager.h"
#include "Manager/InputKey.h"
//--------------------------------------------------------------
//------------System Header
#include "System.h"

//--------------------------------------------------------------
//------------function
void SetWindowMode();

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	int First_time;
	int Last_time;
	SetWindowMode();
	SetBackgroundColor(0, 0, 0);
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	MainManager::MainManager manager;
	manager.Initialize();

	while (ProcessMessage() == 0)
	{
		First_time = GetNowCount();

		ClearDrawScreen();
		keyboard::KeyUpdate();

		if (manager.MainLoop() == 0)
		{
			Last_time = (1000 / 60);
			Last_time -= (GetNowCount() - First_time);
			Sleep(Last_time);
			break;
		} 
		ScreenFlip();
		
	}
	manager.Finalize();

	DxLib_End();
	return 0;
}


void SetWindowMode()
{
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32);
}