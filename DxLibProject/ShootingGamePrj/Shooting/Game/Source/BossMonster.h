#pragma once
#include "..\..\Manager\BaseObject.h"
#include "..\Source\Bullet.h"
#include "..\..\Manager\BulletManager.h"

namespace monster
{
	class BossMonster : public base::BaseObject
	{
	public:
		BossMonster() : BaseObject(base::TYPE::Enemy)
		{

			isActive = false;
			isPlayer = false;
		}
		~BossMonster() = default;

	public:
		void Initialize();
		void Update();
		void CalkTask();
		void GetPosition(int, int, int, int);
		void Draw();
		void Finalize();

	private:
		int Middle_Boss_Monster_img, Last_Boss_Monster_img;				//モンスターのイメージ
		int monster_speed_x, monster_speed_y;
		const int monster_speed = 15;
		int dest_pos_x, dest_pos_y, get_monster_pos_x, get_monster_pos_y;
	};
}