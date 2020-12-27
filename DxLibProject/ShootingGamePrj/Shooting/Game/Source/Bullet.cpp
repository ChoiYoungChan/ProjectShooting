#include "Bullet.h"

namespace bullet
{
	void Bullet::Initialize()
	{
		isActive = true;
	}

	void Bullet::CalkTask()
	{
		if (isActive == true)
		{
			(isPlayer) ? (PlayerBulletUpdate()) : (MonsterBulletUpdate());
		}
		if (pos_x > WINDOW_SIZE_X || pos_x < 0 || pos_y > WINDOW_SIZE_Y || pos_y < 0)
		{
			isActive = false;
		}
		
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
		if (isActive == true)
		{
			pos_y -= bullet_speed;
			if (pos_y <= 0)
			{
				isActive = false;
			}
		}
	}

	void Bullet::MonsterBulletUpdate()
	{
		
		if (isActive == true)
		{
			_bullethell.SetPosition(this, shooter,count);
			_bullethell.Pattern(this);
			count++;
		}
	}

	void Bullet::SetBullet(bool status, int whoshoot, int set_pos_x, int set_pos_y, int img, double size, int target_x, int target_y)
	{
		isPlayer = status;
		shooter = whoshoot;
		pos_x = set_pos_x;
		pos_y = set_pos_y;
		image = img;
		bullet_size = size;
		target_pos_x = target_x;
		target_pos_y = target_y;
	}

	void Bullet::Finalize()
	{
		isActive = false;
	}
}