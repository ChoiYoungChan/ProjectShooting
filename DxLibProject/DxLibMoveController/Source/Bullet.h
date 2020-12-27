#ifndef AAA_HEADER
#define AAA_HEADER

#include "DxLib.h"

namespace bullet
{
	class Bullet
	{
	public:
		Bullet()
		{
			bullet_pos_x = -100;
			bullet_pos_y = -100;
			bullet_speed = 20;
			shootnumber = 1;
		}

		~Bullet() = default;

		void Initialize(int,int);
		void BulletMovement();
		void Draw();

	private:
		int bullet_pos_x, bullet_pos_y, bullet_speed, bullet_img;
		int shootnumber;
	};
}
#endif