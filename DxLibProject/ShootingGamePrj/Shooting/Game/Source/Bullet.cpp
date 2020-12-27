#include "Bullet.h"

namespace bullet
{
	void Bullet::Initialize(int object_img)
	{
		image = object_img;
		isActive = true;
	}
	void Bullet::Update()
	{

	}
	void Bullet::CalkTask()
	{

	}

	void Bullet::DrawTask()
	{
		DrawRotaGraph(pos_x, pos_y, 0.05, 0, image, true);
	}

	void Bullet::PlayerBulletUpdate()
	{
		pos_y -= bullet_speed;
	}

	void Bullet::SetPosition(int set_pos_x, int set_pos_y)
	{
		pos_x = set_pos_x;
		pos_y = set_pos_y;
	}
	void Bullet::SetTargetPosition(int set_target_pos_x, int set_target_pos_y)
	{
		target_pos_x = set_target_pos_x;
		target_pos_y = set_target_pos_y;
	}
	void Bullet::MonsterBulletUpdate()
	{
		int get_pos_x = pos_x;
		int get_pos_y = pos_y;
		int bullet_speed_x, bullet_speed_y;

		float distance = sqrt(pow(target_pos_x - get_pos_x, 2) + pow(target_pos_y - get_pos_y, 2));

		if (distance)
		{
			int bullet_speed_x = (get_pos_x - target_pos_x) / distance * bullet_speed;
			int bullet_speed_y = (get_pos_y - target_pos_y) / distance * bullet_speed;
			if (bullet_speed_x <= 0)
			{
				bullet_speed_x * -1;
			}
		}
		else
		{
			bullet_speed_x = 0;
			bullet_speed_y = bullet_speed;
		}
		pos_x += bullet_speed_x;
		pos_y -= bullet_speed_y;
	}
	void Bullet::Finalize()
	{
		isActive = false;
	}
}