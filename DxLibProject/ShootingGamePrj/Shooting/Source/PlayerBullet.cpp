#include "PlayerBullet.h"

namespace play_user
{
	void PlayerBullet::Initialize(int pos_x, int pos_y, int speed)
	{
		if (shootnumber == 1)
		{
			bullet_pos_x = pos_x;
			bullet_pos_y = pos_y;
			bullet_speed = speed;
			_Bullet_img = LoadGraph("Moriya.png");
		}
	}
	void PlayerBullet::Update()
	{
		if (bullet_pos_y > 0)
		{
			DrawRotaGraph(bullet_pos_x, bullet_pos_y - 50, 0.05, 0, _Bullet_img, true);
			bullet_pos_y -= bullet_speed;
			shootnumber = 0;
		}
		else
		{
			bullet_pos_y = -5;
			shootnumber = 1;
		}
	}

	void PlayerBullet::Finalize()
	{

	}
}