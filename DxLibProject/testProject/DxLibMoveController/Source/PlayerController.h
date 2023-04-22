#pragma once
#include "DxLib.h"
#include "Bullet.h"

namespace player
{
	class PlayerController
	{
	public:
		PlayerController()
		{
			player_pos_x = 240;
			player_pos_y = 600;
			player_speed = 15;
			_Player_img = LoadGraph("Bullet_0001.png");
			shoot_count = 0;
		}
		~PlayerController() = default;

		void Initialize(int,int,int,int);
		void Controller();
		void Draw();
		void Finalize();

	private:
		int player_speed, _Player_img;
		int player_pos_x, player_pos_y, _player_max_pos_x, _player_max_pos_y;
		int shoot_count;
		int _WINDOW_SIZE_X, _WINDOW_SIZE_Y;

	private:

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
	};
}

