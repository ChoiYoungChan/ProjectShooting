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

		for (int index = 0; index < MONSTER_COUNT; index++)
		{
			DrawRotaGraph(monster_pos_x, monster_pos_y, 1.0, 0, _Monster_img, true);
			monster_pos_x += 150;
		}
	}
	void Monster::CalkTask()
	{
		_bullet[].Initialize(monster_pos_x, monster_pos_y);
	}
	void MonsterBullet::Initialize(int monster_pos_x, int monster_pos_y)
	{
		_Bullet_img = LoadGraph("Bullet_0003.png");
	}
	void MonsterBullet::Update()
	{
		DrawRotaGraph();
	}
	void MonsterBullet::Finalize()
	{

	}
}