#pragma once

#include "DxLib.h"
#include "Bullet.h"

namespace controller
{
	class PlayerController
	{
	public:
		PlayerController()
		{
			shoot_count = 0;
			player_pos_x = 240;
			player_pos_y = 600;
			speed = 15;
		}
		~PlayerController() = default;
		void Start(int, int, int, int);
		void Controller();
	private:
		int player_pos_x, player_pos_y, speed, shoot_count;
		int _Player_img, _Bullet_img;

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
	private:
		int _WINDOW_SIZE_X, _WINDOW_SIZE_Y;
		int PLAYER_MIN_POS_X = 0;
		int PLAYER_MIN_POS_Y = 100;
		int PLAYER_MAX_POS_X = _WINDOW_SIZE_X - 10;
		int PLAYER_MAX_POS_Y = _WINDOW_SIZE_Y - 10;
	};
}

