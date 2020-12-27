#include "DxLib.h"

namespace monster
{
	class Monster
	{
	public:
		Monster()
		{
			monster_radius = 1;
			monster_bullet_radius = 1;
			MONSTER_COUNT = 5;
		}

		~Monster() = default;
	public:
		void Initialize();
		void Update();
		void CalkTask();
		void Draw();
		void Finalize();

	public:
		int monster_radius, monster_bullet_radius;		//モンスターの半径と弾丸の半径を設定
		int monster_pos_x, monster_pos_y, speed;		//モンスターの位置と移動速度
		int _Monster_img;								//モンスターのイメージ
		int MONSTER_COUNT;								//一回に表示するモンスターの数

		MonsterBullet _bullet[5];
	};
	class MonsterBullet
	{
	public:
		MonsterBullet()
		{
			bullet_speed = 20;
			bullet_pos_x = -100;
			bullet_pos_y = -100;
			_damage = 100;
		}
		~MonsterBullet() = default;

		void Initialize(int,int);
		void Update();
		void Finalize();

	private:
		int _Bullet_img;						//モンスターの弾丸リソースをLoad
		int bullet_pos_x, bullet_pos_y;			//モンスター弾丸の初期位置を設定
		int shootnumber, bullet_speed;			//弾丸を打った時を区分する数字と弾丸の速度
		int _damage;							//ダメージ
	};
}