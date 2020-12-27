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
			pos_x = -100;
			pos_y = -100;
		}

		~Bullet() = default;

	public:
		void Initialize();
		void CalkTask();
		void DrawTask();
		void Finalize();

		void PlayerBulletUpdate();
		void MonsterBulletUpdate();
		void SetBullet(bool, int,int,int, double);
		BulletHell _bullethell;

	private:
		int image, target_pos_x, target_pos_y;
		const int bullet_speed = 30;
		double bullet_size;
		bool _isplayer;
		
	};
}