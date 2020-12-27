//======================================================
//======= include

#include "DxLib.h"

//======================================================
//======= namespace
using namespace std;

//======================================================
//======= Class and Function

namespace bullet
{
	class Bullet
	{
	public:
		Bullet()
		{
			shootnumber = 1;
		}

		~Bullet() = default;

		void Start(int pos_x, int pos_y, int speed, int Bullet_img)
		{
			if (shootnumber == 1)
			{
				bullet_pos_x = pos_x;
				bullet_pos_y = pos_y;
				bullet_speed = speed;
				bullet_img = Bullet_img;
			}
		}

		void BulletMovement()
		{
			if (bullet_pos_y > 0)
			{
				DrawRotaGraph(bullet_pos_x, bullet_pos_y - 50, 0.3, 0, bullet_img, true);
				bullet_pos_y -= bullet_speed;
				shootnumber = 0;
			}
			else
			{
				bullet_pos_y = -5;
				shootnumber = 1;
			}
		}

	private:
		int bullet_pos_x = -100, bullet_pos_y = -100, bullet_speed, bullet_img;
		int shootnumber;
	};
}

void WindowMode();
void LoadResource();
void FirstDraw();
void PlayerController();

int key[256];

void InputKeyValue()
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
}

//======================================================
//=======Global Variable

int player_pos_x = 240, player_pos_y = 600, bullet_pos_y;
int Player_img, Bullet_img;
int speed = 15;
int WINDOW_SIZE_X = 480, WINDOW_SIZE_Y = 680;
int PLAYER_MAX_POS_X = WINDOW_SIZE_X - 10;
int PLAYER_MAX_POS_Y = WINDOW_SIZE_Y - 10;
bullet::Bullet shoot[50];
int shoot_count = 0;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	WindowMode();
	
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	LoadResource();
	bullet_pos_y = player_pos_y;
	int time_count = 0;

	while (ProcessMessage() == 0)
	{
		InputKeyValue();
		FirstDraw();
		time_count = GetNowCount();
		
		PlayerController();

		DrawRotaGraph(player_pos_x, player_pos_y, 1, 0, Player_img, true);
		for (int count = 0; count < 50; count++)
		{
			shoot[count].BulletMovement();
		}

		int last_time_count = (1000 / 60);
		last_time_count -= (GetNowCount() - time_count);

		ScreenFlip();
		Sleep(last_time_count);
	}
	DxLib_End();
	return 0;
}
void WindowMode()
{
	ChangeWindowMode(true);
	SetGraphMode(WINDOW_SIZE_X, WINDOW_SIZE_Y, 32);
}

void LoadResource()
{
	Player_img = LoadGraph("Bullet_0001.png");
	Bullet_img = LoadGraph("Bullet_0003.png");
}

void FirstDraw()
{
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_BACK);
}

void PlayerController()
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
	if (player_pos_x < 0)
	{
		player_pos_x = 10;
	}
	if (player_pos_x >= WINDOW_SIZE_X)
	{
		player_pos_x = PLAYER_MAX_POS_X;
	}
	if (player_pos_y <= 100)
	{
		player_pos_y = 100;
	}
	if (player_pos_y >= WINDOW_SIZE_Y)
	{
		player_pos_y = PLAYER_MAX_POS_Y;
	}
}