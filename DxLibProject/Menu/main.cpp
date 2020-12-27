#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	ChangeWindowMode(true);
	SetGraphMode(480,680,32);

	while (ProcessMessage() == 0 )
	{

	}

	return 0;
}