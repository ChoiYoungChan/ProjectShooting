#pragma once
//====================================================
//===========include Lib
#include "DxLib.h"
#include <math.h>

//====================================================
//===========include header
#include "..\..\Manager\BaseObject.h"
#include "BulletHell.h"

namespace bullet
{
	class Bullet : public base::BaseObject
	{
	public:
		Bullet()
		{
			isActive = false;
			count = 0;
		}

		~Bullet() = default;

	public:
		void Initialize();
		void CalkTask();
		void DrawTask();
		void Finalize();

		void PlayerBulletUpdate();
		void MonsterBulletUpdate();
		void SetBullet(bool, int, int, int, int, double,int,int);
		BulletHell _bullethell;

	public:
		//=========================================================================
		//===============�e���̌v�Z�Ɏg����ϐ�
		float monster_bullet_x, monster_bullet_y;				//�e�ۂ̍��W
		float radi = 10;										//���a
		float vec_radi = 1;										//���a�̕ω�
		float theta = 1;										//�p�x
		float omega = (5.0f * PI/180.0f);					//���̈ړ��ŕω�����p�x
		float* speed_x_new, speed_y_new;
		int target_pos_x, target_pos_y;
		int speed = 15;
		//=========================================================================

	private:
		int image, shooter;
		const int bullet_speed = 30;
		double bullet_size;
		bool _isplayer;
		int count;
	};
}