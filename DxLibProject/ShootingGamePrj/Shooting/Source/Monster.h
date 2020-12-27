#include "DxLib.h"
#include "MonsterBullet.h"

extern int WINDOW_SIZE_X;
extern int WINDOW_SIZE_Y;

namespace monster
{
	class Monster
	{
	public:
		Monster()
		{
			monster_pos_x = -100;
			monster_pos_y = -100;

			_monster_shoot_count = 0;
		}

		~Monster() = default;
	public:
		void Initialize();
		void Update();
		void CalkTask();
		void GetPosition(int, int);
		void Draw();
		void Finalize();

	public:
		int monster_pos_x, monster_pos_y;								//�����X�^�[�̈ʒu
		const int monster_radius = 25, monster_bullet_radius = 30;		//�����X�^�[�̔��a�ƒe�ۂ̔��a��ݒ�

		Bullet monster_bullet[5];
		const int MONSTER_BULLET_COUNT = 5;
		const int MONSTER_COUNT = 5;							//���ɕ\������郂���X�^�[�̐�

	private:
		int _Monster_img;								//�����X�^�[�̃C���[�W
		int _monster_shoot_count;
	private:
		void ShootBullet();

	};
}