//======================================================
//======= include

#include "DxLib.h"
#include "Source/Bullet.h"
#include "Source/PlayerController.h"

//======================================================
//======= namespace
using namespace std;

//======================================================
//======= Class and Function

void SetWindowMode(int , int);
void LoadResource();
void FirstDraw();

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

//void PlayerController(int, int, int, int, int);
void InputTask();
void DrawTask();

//======================================================
//=======Global Variable


int WINDOW_SIZE_X = 480, WINDOW_SIZE_Y = 720;
int Player_img, Bullet_img;

controller::PlayerController playerCon;
int shoot_count = 0;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	SetWindowMode(WINDOW_SIZE_X, WINDOW_SIZE_Y);
	if (DxLib_Init() == -1) { return -1;}

	LoadResource();
	int speed = 15, time_count = 0;

	while (ProcessMessage() == 0 && InputKeyValue() == 0)
	{
		FirstDraw();
		time_count = GetNowCount();

		InputTask();
		DrawTask();

		int last_time_count = (1000 / 60);
		last_time_count -= (GetNowCount() - time_count);

		ScreenFlip();
		Sleep(last_time_count);
	}
	DxLib_End();
	return 0;
}
void SetWindowMode(int window_size_x, int window_size_y)
{
	ChangeWindowMode(true);
	SetGraphMode(window_size_x, window_size_y, 32);
}

void LoadResource()
{
	Player_img = LoadGraph("Bullet_0001.png");
	Bullet_img = LoadGraph("Bullet_0003.png");

	playerCon.Start(Player_img, Bullet_img, WINDOW_SIZE_X, WINDOW_SIZE_Y);
}

void FirstDraw()
{
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);
}
/*
void PlayerController(int speed, int player_min_pos_x, int player_min_pos_y, int player_max_pos_x, int player_max_pos_y)
{
	if (key[KEY_INPUT_RIGHT] >= 1) {
		player_pos_x += speed;
	}
	if (key[KEY_INPUT_DOWN] >= 1) {
		player_pos_y += speed;
	}
	if (key[KEY_INPUT_LEFT] >= 1) {
		player_pos_x -= speed;
	}
	if (key[KEY_INPUT_UP] >= 1) {
		player_pos_y -= speed;
	}
	if (key[KEY_INPUT_Z] >= 1)
	{
		shoot[shoot_count].Start(player_pos_x, player_pos_y, speed, Bullet_img);
		shoot_count++;
		if (shoot_count >= 50)
		{
			shoot_count = 0;
		}
	}
	DrawRotaGraph(player_pos_x, player_pos_y, 1, 0, Player_img, true);
	if (player_pos_x < 0)
	{
		player_pos_x = 10;
	}
	if (player_pos_x >= WINDOW_SIZE_X)
	{
		player_pos_x = player_max_pos_x;
	}
	if (player_pos_y <= 200)
	{
		player_pos_y = 200;
	}
	if (player_pos_y >= WINDOW_SIZE_Y)
	{
		player_pos_y = player_max_pos_y;
	}
}
*/
void InputTask()
{
	playerCon.Controller();

	
}
void DrawTask()
{
	
}