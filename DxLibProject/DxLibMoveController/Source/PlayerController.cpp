#include "PlayerController.h"


namespace player
{
	void PlayerController::Initialize
	(int player_max_pos_x, int player_max_pos_y, int WINDOW_SIZE_X, int WINDOW_SIZE_Y)
	{
		_player_max_pos_x = player_max_pos_x;
		_player_max_pos_y = player_max_pos_y;
		_WINDOW_SIZE_X = WINDOW_SIZE_X;
		_WINDOW_SIZE_Y = WINDOW_SIZE_Y;
	}
	void PlayerController::Controller()
	{
		if (key[KEY_INPUT_RIGHT] >= 1) {
			player_pos_x += player_speed;
		}
		if (key[KEY_INPUT_DOWN] >= 1) {
			player_pos_y += player_speed;
		}
		if (key[KEY_INPUT_LEFT] >= 1) {
			player_pos_x -= player_speed;
		}
		if (key[KEY_INPUT_UP] >= 1) {
			player_pos_y -= player_speed;
		}
		if (key[KEY_INPUT_Z] >= 1)
		{
			//shoot[shoot_count].Initialize(player_pos_x, player_pos_y);
			//shoot_count++;
			if (shoot_count >= 50)
			{
		//		shoot_count = 0;
			}
		}
		DrawRotaGraph(player_pos_x, player_pos_y, 1, 0, _Player_img, true);
		if (player_pos_x < 0)
		{
			player_pos_x = 10;
		}
		if (player_pos_x >= _WINDOW_SIZE_X)
		{
			player_pos_x = _player_max_pos_x;
		}
		if (player_pos_y <= 200)
		{
			player_pos_y = 200;
		}
		if (player_pos_y >= _WINDOW_SIZE_Y)
		{
			player_pos_y = _player_max_pos_y;
		}
	}
	void PlayerController::Draw()
	{
		DrawRotaGraph(player_pos_x, player_pos_y, 1, 0, _Player_img, true);
	}
	void PlayerController::Finalize()
	{
		DeleteGraph(_Player_img);
	}
}