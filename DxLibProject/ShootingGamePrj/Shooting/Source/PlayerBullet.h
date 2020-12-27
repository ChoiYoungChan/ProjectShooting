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
			bullet_pos_x = 300;
			bullet_pos_y = 600;
			_damage = 100;
		}
		~PlayerBullet() = default;

		void Initialize();
		void GetPosition(int,int);
		void Update();
		void Finalize();
		void DrawTask();
	public:
		int bullet_pos_x, bullet_pos_y;			//弾丸の位置座標

	private:
		int _Bullet_img;						//弾丸のイメージ
		int shootnumber, bullet_speed;			//弾丸の数と速度
		int _damage;							//弾丸のダメージ
	};
}