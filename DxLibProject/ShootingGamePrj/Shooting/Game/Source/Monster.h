#include "DxLib.h"
#include "..\..\Manager\BaseObject.h"
#include "..\Source\Bullet.h"

namespace monster
{
	class Monster : public base::BaseObject
	{
	public:
		Monster()
		{
			pos_x = 500;
			pos_y = 1000;
			shoot = true;
		}

		~Monster() = default;

	public:
		void Initialize();
		void Update();
		void CalkTask();
		void GetPosition(int, int, int, int,int,int);
		void Draw();
		void Finalize();
		void ShootBullet();

	private:
		bullet::Bullet monster_bullet[10];
		const int MONSTER_BULLET_COUNT = 5;

	private:
		int _Monster_img, _Bullet_img;									//モンスターのイメージ
		int monster_speed_x, monster_speed_y;
		const int monster_speed = 15;
		int dest_pos_x, dest_pos_y, get_monster_pos_x, get_monster_pos_y;
		int bullet_target_pos_x, bullet_target_pos_y;
		bool shoot;
	};
}