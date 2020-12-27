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
			_isActive = false;

			_radius = 25;
			_speed = 30;
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

	public:
		//=========================================================================
		//===============’e–‹‚ÌŒvZ‚Ég‚í‚ê‚é•Ï”
		float _monster_bullet_x, _monster_bullet_y;				//’eŠÛ‚ÌÀ•W
		float _radi = 10;										//”¼Œa
		float _vec_radi = 1;										//”¼Œa‚Ì•Ï‰»
		float _theta = 1;										//Šp“x
		float _omega = (5.0f * PI/180.0f);					//ˆê‰ñ‚ÌˆÚ“®‚Å•Ï‰»‚·‚éŠp“x
		float* _speed_x_new, _speed_y_new;
		int _target_pos_x, _target_pos_y;
		//=========================================================================

	private:
		int _image, _shooter;
		double _bullet_size;
	};
}