#pragma once
#include "DxLib.h"

namespace play_user
{
	class PlayerBullet
	{
	public:
		PlayerBullet()
		{
			shootnumber = 1;
			bullet_speed = 20;
			bullet_pos_x = -100;
			bullet_pos_y = -100;
			_damage = 100;
		}
		~PlayerBullet() = default;

		void Initialize(int, int, int);
		void Update();
		void Finalize();

	private:
		int _Bullet_img;
		int bullet_pos_x, bullet_pos_y;
		int shootnumber, bullet_speed;
		int _damage;
	};
}