#include "DxLib.h"
#include "..\..\Manager\BaseObject.h"

namespace monster
{
	class Monster : public base::BaseObject
	{
	public:
		Monster() : BaseObject(base::TYPE::Enemy)
		{

			pos_x = 1000;
			pos_y = 1000;
			isActive = false;
			isPlayer = false;
		}
		~Monster() = default;

	public:
		void Initialize();
		void CalkTask();
		void GetPosition(int, int, int, int);
		void Draw();
		void Finalize();

	public:
		const int Monster_ID = 0;

	private:
		int _Monster_img;								//モンスターのイメージ
		int monster_speed_x, monster_speed_y;
		const int monster_speed = 15;
		int dest_pos_x, dest_pos_y, get_monster_pos_x, get_monster_pos_y;
	};
}