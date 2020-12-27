#include "DxLib.h"

void WindowTask();
void InputTask();
int image;

int key[];

int InputKeyValue()
{
	char KeyValue[256];
	GetHitKeyStateAll(KeyValue);
	for (int index = 0; index < 256; index++)
	{
		if (KeyValue[index] != 0)
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

	int pos_x = 200, pos_y = 200;
	image = LoadGraph("Bullet_0001.png");

	while (ProcessMessage() == 0 && InputKeyValue() == 0)
	{
		ClearDrawScreen();
		SetDrawScreen(DX_SCREEN_BACK);
		if (key[KEY_INPUT_RIGHT] >= 1) { // �E�L�[��������Ă�����
			pos_x++;                       // �E�ֈړ�
		}
		if (key[KEY_INPUT_DOWN] >= 1) { // ���L�[��������Ă�����
			pos_y++;                       // ���ֈړ�
		}
		if (key[KEY_INPUT_LEFT] >= 1) { // ���L�[��������Ă�����
			pos_x--;                       // ���ֈړ�
		}
		if (key[KEY_INPUT_UP] >= 1) { // ��L�[��������Ă�����
			pos_y--;                       // ��ֈړ�
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
void InputTask()
{

}
