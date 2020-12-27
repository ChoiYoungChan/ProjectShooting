//--------------------------------------------------------------
//------------include Header
#include "Bullet.h"

namespace bullet
{
	void Bullet::Initialize()
	{
		_isActive = false;
	}

	void Bullet::CalkTask()
	{
		if (_isActive == true)
		{
			(_isPlayer) ? (PlayerBulletUpdate()) : (MonsterBulletUpdate());
		}
	}

	void Bullet::DrawTask()
	{
		if (_isActive == true)
		{
			DrawCircle(_pos_x, _pos_y, _radius, GetColor(200, 200, 0), false);
			DrawRotaGraph(_pos_x, _pos_y, _bullet_size, 0, _image, true);
		}
	}

	void Bullet::PlayerBulletUpdate()
	{
		if (_isActive == true)
		{
			_pos_y -= _speed;
			if (_pos_y <= 0)
			{
				_isActive = false;
			}
		}
	}

	void Bullet::MonsterBulletUpdate()
	{
		if (_isActive == true)
		{
			_pos_y += _speed;
			if (_pos_y < 0 ||_pos_y > WINDOW_SIZE_Y)
			{
				_isActive = false;
			}
		}
	}

	void Bullet::SetBullet(bool status, int whoshoot, int set_pos_x, int set_pos_y, int img, double size, int target_x, int target_y)
	{
		_isPlayer = status;
		(_isPlayer) ? (_radius = PLAYER_BULLET_RADIUS) : (_radius = MONSTER_BULLET_RADIUS);
		_shooter = whoshoot;
		_pos_x = set_pos_x;
		_pos_y = set_pos_y;
		_image = img;
		_bullet_size = size;
		_target_pos_x = target_x;
		_target_pos_y = target_y;
	}

	void Bullet::Finalize()
	{
		_isActive = false;
	}
}