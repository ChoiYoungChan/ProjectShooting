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
		int bullet_pos_x, bullet_pos_y;			//�e�ۂ̈ʒu���W

	private:
		int _Bullet_img;						//�e�ۂ̃C���[�W
		int shootnumber, bullet_speed;			//�e�ۂ̐��Ƒ��x
		int _damage;							//�e�ۂ̃_���[�W
	};
}