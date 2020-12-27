#include "Monster.h"

namespace monster
{
	void Monster::Initialize()
	{
		_Monster_img = LoadGraph("Monster_0001.png");

	}
	/// <summary>
	/// モンスターを呼び出せば実行続ける関数
	/// </summary>
	void Monster::Update()
	{
		CalkTask();
		Draw();
	}
	void Monster::Finalize()
	{

	}
	/// <summary>
	/// モンスターの初期位置座標
	/// モンスターを表示する関数
	/// </summary>
	void Monster::Draw()
	{
		monster_pos_x = 300; monster_pos_y = 300;

		DrawRotaGraph(monster_pos_x, monster_pos_y, 1.0, 0, _Monster_img, true);
	}
	/// <summary>
	/// モンスターで計算が必要な処理(弾を打つこと)をまとめた関数
	/// </summary>
	void Monster::CalkTask()
	{
		_bullet[_monster_shoot_count].Initialize(monster_pos_x, monster_pos_y);
		_monster_shoot_count++;
		if (_monster_shoot_count > 5)
		{
			_monster_shoot_count = 0;
		}
	}
}