#include "DxLib.h"
#include "MonsterBullet.h"

extern int WINDOW_SIZE_X;
extern int WINDOW_SIZE_Y;

namespace monster
{
	class Monster
	{
	public:
		Monster()
		{
			monster_pos_x = -100;
			monster_pos_y = -100;

			_monster_shoot_count = 0;
		}

		~Monster() = default;
	public:
		void Initialize();
		void Update();
		void CalkTask();
		void GetPosition(int, int);
		void Draw();
		void Finalize();

	public:
		int monster_pos_x, monster_pos_y;								//モンスターの位置
		const int monster_radius = 25, monster_bullet_radius = 30;		//モンスターの半径と弾丸の半径を設定

		Bullet monster_bullet[5];
		const int MONSTER_BULLET_COUNT = 5;
		const int MONSTER_COUNT = 5;							//一回に表示されるモンスターの数

	private:
		int _Monster_img;								//モンスターのイメージ
		int _monster_shoot_count;
	private:
		void ShootBullet();

	};
}