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
		int monster_pos_x, monster_pos_y;				//�����X�^�[�̈ʒu
		int monster_radius, monster_bullet_radius;		//�����X�^�[�̔��a�ƒe�ۂ̔��a��ݒ�

	private:
		int _Monster_img;								//�����X�^�[�̃C���[�W
		int MONSTER_COUNT;								//���ɕ\������郂���X�^�[�̐�
		int _monster_shoot_count;

		
		Bullet _bullet[5];
	};
}