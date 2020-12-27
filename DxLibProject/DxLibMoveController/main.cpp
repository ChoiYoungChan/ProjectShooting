#include "DxLib.h"

namespace bullet
{
	class Bullet
	{
	public:
		Bullet() = default;
		~Bullet() = default;
		void(*funcpointer)();

		void Start(int pos_x, int pos_y, int speed, int Bullet_img, int timecount)
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
				DrawRotaGraph(bullet_pos_x, bullet_pos_y, 1, 0, bullet_img, true);
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
		int bullet_pos_x, bullet_pos_y, bullet_speed, bullet_img;
		int shootnumber;
	};
}

void WindowMode();
void LoadResource();

int pos_x = 200, pos_y = 200, bullet_pos_y;

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

int Player_img;
int Bullet_img;
int speed = 15;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	WindowMode();

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	LoadResource();
	bullet_pos_y = pos_y;
	int timecount = 0;
	
	while (ProcessMessage() == 0 && InputKeyValue() == 0)
	{
		//timecount = GetNowCount();
		bullet::Bullet shoot;
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
		if (key[KEY_INPUT_Z] >= 1)
		{
			shoot.Start(pos_x, pos_y, speed, Bullet_img, timecount);
		}

		DrawRotaGraph(pos_x, pos_y, 1, 0, Player_img, true);

		shoot.BulletMovement();
		ScreenFlip();

		if (bullet_pos_y <= 0)
		{
			bullet_pos_y = -5;
			timecount = 1;
		}
		Sleep(1000 / 60);
	}

	DxLib_End();
	return 0;
}
void WindowMode()
{
	ChangeWindowMode(true);
	SetGraphMode(480, 680, 32);
}

void LoadResource()
{
	Player_img = LoadGraph("Bullet_0001.png");
	Bullet_img = LoadGraph("Bullet_0003.png");
}