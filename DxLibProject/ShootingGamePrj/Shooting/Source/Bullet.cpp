#include "Bullet.h"

namespace bullet
{
	void Bullet::Initialize(int object_img)
	{
		image = object_img;
	}
	void Bullet::Update()
	{

	}
	void Bullet::CalkTask()
	{

	}

	void Bullet::DrawTask(int bullet_pos_x, int bullet_pos_y)
	{
		DrawRotaGraph(pos_x, pos_y, 0.05, 0, image, true);
	}

	void Bullet::GetPosition(int set_pos_x, int set_pos_y)
	{
		pos_x = set_pos_x;
		pos_x = set_pos_y;
	}
	void Bullet::SetTargetPosition(int set_target_pos_x, int set_target_pos_y)
	{
		target_pos_x = set_target_pos_x;
		target_pos_y = set_target_pos_y;
	}

	void Bullet::Finalize()
	{

	}


	void Bullet::NormalPattern()
	{

	}
	void Bullet::FirstPattern()
	{

	}
	void Bullet::SecondPattern()
	{

	}
	void Bullet::ThirdPattern()
	{

	}
	void Bullet::ForthPattern()
	{

	}
	void Bullet::FifthPattern()
	{

	}
}