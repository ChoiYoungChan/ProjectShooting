#include "Monster.h"

namespace monster
{
	void Monster::Initialize()
	{
		_Monster_img = LoadGraph("Monster_0001.png");
	}
	void Monster::Update()
	{
		CalkTask();
		Draw();
	}
	void Monster::Finalize()
	{

	}
	void Monster::Draw()
	{
		monster_pos_x = 100; monster_pos_y = 150;

		for (int i = 0; i < 5; i++)
		{
			DrawRotaGraph(monster_pos_x, monster_pos_y, 1.0, 0, _Monster_img, true);
			monster_pos_x += 150;
		}
	}
	void Monster::CalkTask()
	{

	}
	void MonsterBullet::Initialize()
	{

	}
	void MonsterBullet::Update()
	{

	}
	void MonsterBullet::Finalize()
	{

	}
}