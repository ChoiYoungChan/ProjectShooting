#include "Bullet.h"

namespace bullet
{
	void Bullet::Start(int pos_x, int pos_y, int speed, int Bullet_img)
	{
		if (shootnumber == 1)
		{
			bullet_pos_x = pos_x;
			bullet_pos_y = pos_y;
			bullet_speed = speed;
			bullet_img = Bullet_img;
		}
	}

	void Bullet::BulletMovement()
	{
		if (bullet_pos_y > 0)
		{
			DrawRotaGraph(bullet_pos_x, bullet_pos_y - 50, 0.3, 0, bullet_img, true);
			bullet_pos_y -= bullet_speed;
			shootnumber = 0;
		}
		else
		{
			bullet_pos_y = -5;
			shootnumber = 1;
		}
	}
}