//-------------------------
//include 

#include "DxLib.h"

//-------------------------
//include.h
void inputTask();
void CalkTask();
void DrawTask();

//-------------------------
//global var 

int pos_x = 200, pos_y = 720;
int speed = 10;
int img;

int sceneState = 0;

//-------------------------
//function 


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(480, 720 ,32);
	
	if (DxLib_Init () == -1)
	{
		return -1;
	}

	int counttime = GetNowCount();

	img = LoadGraph("Bullet_0001.png");	

	int time_st;
	while (true)
	{
		time_st = GetNowCount();

		inputTask();

		CalkTask();

		DrawTask();

		int wait_time = (1000 / 30);
		wait_time	-= (GetNowCount() - time_st);
		Sleep(wait_time);
		if (ProcessMessage() != 0)
		{
			break;
		}	
	}

	//DrawRotaGraph(480, 720, 0.4, 0, img, true);
	//WaitTimer(3000);

	DxLib_End();
	return 0;
}

void inputTask()
{
}

void CalkTask()
{
	pos_y -= speed;
	if (pos_y <= 0)
		pos_y = 720;

	//switch (sceneState)
	//{
	//case 0:
	//	TittleScebe.CalkTask();
	//	break;
	//case 1:
	//	GameScene.CalkTask();
	//	break;
	//}
}


void DrawTask()
{
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	DrawRotaGraph(pos_x, pos_y, 0.4, 0.0, img, true);

	//Sleep(1000 / 60);

	ScreenFlip();

}


