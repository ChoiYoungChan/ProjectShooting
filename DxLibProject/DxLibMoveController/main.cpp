//======================================================
//======= include

#include "DxLib.h"
#include "Source/Bullet.h"
#include "Source/Monster.h"
#include "Source/PlayerController.h"

//======================================================
//======= namespace
using namespace std;

//======================================================
//======= Class and Function

void SetWindowMode(int , int);
void LoadResource();

void InputTask(int, int, int);
void DrawTask();
void CalculateTask();
void MenuTask();

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

//======================================================
//=======Global Variable

int player_pos_x = 240, player_pos_y= 600;
int WINDOW_SIZE_X = 480, WINDOW_SIZE_Y = 720;
int Monster_img, Monster_Bullet_img;

bullet::Bullet shoot[50];
monster::Monster enemy[20];
player::PlayerController Player;

int shoot_count = 0, spawn_count = 0;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	int PLAYER_MIN_POS_X = (WINDOW_SIZE_X / 2);
	int PLAYER_MIN_POS_Y = 100;
	int PLAYER_MAX_POS_X = WINDOW_SIZE_X - 10;
	int PLAYER_MAX_POS_Y = WINDOW_SIZE_Y - 10;
	
	SetWindowMode(WINDOW_SIZE_X, WINDOW_SIZE_Y);
	if (DxLib_Init() == -1) { return -1;}

	LoadResource();
	int speed = 15, time_count = 0;
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && InputKeyValue() == 0)
	{
		time_count = GetNowCount();

		InputTask(speed, PLAYER_MAX_POS_X, PLAYER_MAX_POS_Y);
		CalculateTask();
		DrawTask();

		int last_time_count = (1000 / 60);
		last_time_count -= (GetNowCount() - time_count);
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
	Monster_img = LoadGraph("Monster_0001.png");
	Monster_Bullet_img = LoadGraph("Bullet_0005.png");

	enemy[spawn_count].Start(Monster_img, Monster_Bullet_img);
}

void InputTask(int speed, int player_max_pos_x, int player_max_pos_y)
{
	
	Player.Initialize(player_max_pos_x,player_max_pos_y, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	/*
	for (int count = 0; count < 50; count++)
	{
		shoot[count].BulletMovement();
	
	
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
		shoot[shoot_count].Start(player_pos_x, player_pos_y, speed, Player_Bullet_img);
		shoot_count++;
		if (shoot_count >= 50)
		{
			shoot_count = 0;
		}
	}

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
	}*/
}

void DrawTask()
{
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);

	//Player.Draw();

	for (int count = 0; count < 50; count++)
	{
		shoot[count].BulletMovement();
	}

	for (int count = 0; count < 20; count++)
	{
		enemy[spawn_count].RandomMovePos();
		if (enemy[spawn_count].IsInScreen() == 1)
		{
			enemy[spawn_count].SpawnPattern();	
		}
	}
}

void CalculateTask()
{
	Player.Controller();
}

void MenuTask()
{

}