#include "DxLib.h"
#include "MonsterBullet.h"

namespace monster
{
	class Monster
	{
	public:
		Monster()
		{
			monster_radius = 25;
			monster_bullet_radius = 30;
			MONSTER_COUNT = 5;
			_monster_shoot_count = 0;
		}

		~Monster() = default;
	public:
		void Initialize();
		void Update();
		void CalkTask();
		void Draw();
		void Finalize();

	public:
		int monster_pos_x, monster_pos_y;				//モンスターの位置
		int monster_radius, monster_bullet_radius;		//モンスターの半径と弾丸の半径を設定

	private:
		int _Monster_img;								//モンスターのイメージ
		int MONSTER_COUNT;								//一回に表示されるモンスターの数
		int _monster_shoot_count;

		typedef struct								//モンスターの移動をパターン化するためのStruct
		{
			int monster_spawn_time;					//モンスターを表示するタイミング
			int monster_pos_x;						//モンスターのｘとｙ軸の座標
			int monster_pos_y;

		}MonsterMovement;

		MonsterMovement monster_move[5]
		{
			{5,   10, -10},							//第一パターン
			{10, -50,  10},							//第二パターン
			{15, 800,  20},							//第三パターン
			{20, -10, -10},							//第四パターン
			{25, 800, -10},							//第五パターン
		};
		Bullet _bullet[5];
	};
}