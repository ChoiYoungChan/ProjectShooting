#include "DxLib.h"

namespace bullet
{
	class Bullet
	{
	public:
		Bullet()
		{
			shootnumber = 1;
		}

		~Bullet() = default;

		void Start(int,int,int,int);

		void BulletMovement();

	private:
		int bullet_pos_x = -100, bullet_pos_y = -100, bullet_speed, bullet_img;
		int shootnumber;
	};
}