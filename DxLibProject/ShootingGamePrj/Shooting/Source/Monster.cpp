#include "Monster.h"

namespace monster
{
	void Monster::Initialize()
	{
		_Monster_img = LoadGraph("Resource/Monster_0001.png");
	}
	/// <summary>
	/// モンスターを呼び出せば実行続ける関数
	/// </summary>
	void Monster::Update()
	{
		CalkTask();
		if(monster_pos_x > 0 && monster_pos_x < WINDOW_SIZE_X &&
			monster_pos_y < 0 && monster_pos_y < WINDOW_SIZE_Y)
		{
			ShootBullet();
		}
		Draw();
	}
	/// <summary>
	/// モンスターを表示する関数
	/// </summary>
	void Monster::Draw()
	{
		DrawRotaGraph(monster_pos_x, monster_pos_y, 1.0, 0, _Monster_img, true);
	}
	void Monster::GetPosition(int get_pos_x, int get_pos_y)
	{
		monster_pos_x = get_pos_x;
		monster_pos_y = get_pos_y;
	}
	/// <summary>
	/// モンスターで計算が必要な処理(弾を打つこと)をまとめた関数
	/// </summary>
	void Monster::CalkTask()
	{
		
	}
	void Monster::ShootBullet()
	{
		monster_bullet[_monster_shoot_count].Initialize(monster_pos_x, monster_pos_y);
		_monster_shoot_count++;
		if (_monster_shoot_count >= 5)
		{
			_monster_shoot_count = 0;
		}
	}
	void Monster::Finalize()
	{

	}
}