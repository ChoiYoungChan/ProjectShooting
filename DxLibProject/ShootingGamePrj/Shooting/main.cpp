//--------------------------------------------------------------
//------------include
#include "DxLib.h"
#include "MainManager.h"
#include "Scene/Manager/InputKey.h"

//--------------------------------------------------------------
//------------function

void SetWindowMode();
void SetUpData();

//--------------------------------------------------------------
//------------Global Variable
int WINDOW_SIZE_X = 720, WINDOW_SIZE_Y = 720;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SetWindowMode();
	SetBackgroundColor(0, 0, 0);
	if (DxLib_Init() == -1) { return -1; }

	SetUpData();
	MainManager::MainManager& manager = MainManager::MainManager::Instance();

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SetDrawScreen(DX_SCREEN_BACK);
		keyboard::KeyUpdate();

		if (manager._loopcount == 0)
		{
			manager.Initialize();
		}
		if (manager._loopcount >= 1)
		{
			if (manager.MainLoop() == 0)
			{
				break;
			}
		}
		manager._loopcount++;
	}
	manager.Finalize();

	DxLib_End();
	return 0;
}


//--------------------------------------------------------------
//------------function
void SetWindowMode()
{
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32);
}
void SetUpData()
{

}