#include "PlayerController.h"

namespace controller
{
	bullet::Bullet shoot[50];
	void PlayerController::Start(int Player_img, int Bullet_img, int WINDOW_SIZE_X,int WINDOW_SIZE_Y)
	{
		_Player_img = Player_img;
		_Bullet_img = Bullet_img;
		_WINDOW_SIZE_X = WINDOW_SIZE_X;
		_WINDOW_SIZE_Y = WINDOW_SIZE_Y;
	}

	void PlayerController::Controller()
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
			shoot[shoot_count].Start(player_pos_x, player_pos_y, speed, _Bullet_img);
			shoot_count++;
			if (shoot_count >= 50)
			{
				shoot_count = 0;
			}
		}
		for (int count = 0; count < 50; count++)
		{
			shoot[count].BulletMovement();
		}
		DrawRotaGraph(player_pos_x, player_pos_y, 1, 0, _Player_img, true);

		if (player_pos_x < 0)
		{
			player_pos_x = 10;
		}
		if (player_pos_x >= _WINDOW_SIZE_X)
		{
			player_pos_x = PLAYER_MAX_POS_X;
		}
		if (player_pos_y <= 200)
		{
			player_pos_y = 200;
		}
		if (player_pos_y >= _WINDOW_SIZE_Y)
		{
			player_pos_y = PLAYER_MAX_POS_Y;
		}
	}
}