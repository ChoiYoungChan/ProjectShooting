#include "PlayerController.h"

/*
namespace controller
{
	void PlayerController::Controller(int speed, int player_min_pos_x, int player_min_pos_y, int player_max_pos_x, int player_max_pos_y)
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
}*/