
#include "DxLib.h"
#include "..\..\Manager\BaseObject.h"
#include "..\..\Manager\Singleton.h"

#define BOSS_HP 5000

namespace monster
{
	class BossMonster : public base::BaseObject
	{
	public:
		BossMonster() : BaseObject(base::TYPE::Enemy)
		{
			_radius = 80;
			Monster_ID = 1;
			Monster_HP = BOSS_HP;

			bullet_shooter = 2;

			pos_x = 1000;
			pos_y = 1000;
			
			isActive = false;
			isPlayer = false;
		}
		~BossMonster() = default;

	public:
		void Initialize();
		void CalkTask();
		void SetBossMonster(int, int, int, int, int);
		void Draw();
		void Finalize();
		int Monster_ID, Monster_HP;
	private:
		int _img;				//モンスターのイメージ
		int monster_speed_x, monster_speed_y;
		const int monster_speed = 15;
		int dest_pos_x, dest_pos_y, get_monster_pos_x, get_monster_pos_y;
	};
}