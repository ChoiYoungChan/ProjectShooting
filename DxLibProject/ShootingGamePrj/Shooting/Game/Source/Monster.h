//--------------------------------------------------------------
//------------include Header
#include "DxLib.h"
#include "..\..\Manager\BaseObject.h"

namespace monster
{
	class Monster : public base::BaseObject
	{
	public:
		Monster() : BaseObject(base::TYPE::Enemy)
		{
			_Monster_ID = 0;
			_speed = 15;

			_isPlayer = false;
		}
		~Monster() = default;

	public:
		void Initialize();
		void CalkTask();
		void GetPosition(int, int, int, int, int, int);
		void ShootBullet();
		void Draw();
		void Finalize();

		void NormalMonsterMove();
		void BossMonsterMove();

	public:
		int _Monster_ID, Monster_HP;

	private:
		int _img;								//モンスターのイメージ
		float monster_speed_x, monster_speed_y;
		int dest_pos_x, dest_pos_y, get_monster_pos_x, get_monster_pos_y;
	};
}