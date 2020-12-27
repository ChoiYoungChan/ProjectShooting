#include "DxLib.h"
#include "MonsterBullet.h"
#include <math.h>
#include "..\Scene\Manager\BaseObject.h"

namespace monster
{
	class Monster : public base::BaseObject
	{
	public:
		Monster()
		{
			monster_pos_x = 1000;
			monster_pos_y = 1000;

			_monster_shoot_count = 0;
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

	public:
		int monster_pos_x, monster_pos_y;								//モンスターの位置
		int get_monster_pos_x, get_monster_pos_y;
		int dest_pos_x, dest_pos_y;										//目的地の座標

		Bullet monster_bullet[10];

		const int MONSTER_BULLET_COUNT = 5;
		int bullet_target_pos_x, bullet_target_pos_y;

	private:
		int _Monster_img;								//モンスターのイメージ
		int _monster_shoot_count;
		int monster_speed_x, monster_speed_y;
		const int monster_speed = 15;
	};
}