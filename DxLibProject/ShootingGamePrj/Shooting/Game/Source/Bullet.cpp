#include "Bullet.h"

namespace bullet
{
	void Bullet::Initialize()
	{
		isActive = true;
	}

	void Bullet::CalkTask()
	{
		(isPlayer) ? (PlayerBulletUpdate()) : (MonsterBulletUpdate());
	}

	void Bullet::DrawTask()
	{
		if (isActive == true)
		{
			DrawRotaGraph(pos_x, pos_y, bullet_size, 0, image, true);
		}
	}

	void Bullet::PlayerBulletUpdate()
	{
		pos_y -= bullet_speed;
		if (pos_y <= 0)
		{
			isActive = false;
		}
	}

	void Bullet::MonsterBulletUpdate()
	{
		_bullethell.Pattern();
	}

	void Bullet::SetBullet(bool status, int set_pos_x, int set_pos_y, int img, double size)
	{
		isPlayer = status;
		pos_x = set_pos_x;
		pos_y = set_pos_y;
		image = img;
		bullet_size = size;
	}

	void Bullet::Finalize()
	{
		
	}
}