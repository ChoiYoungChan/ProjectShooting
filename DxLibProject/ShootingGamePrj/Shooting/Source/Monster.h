#include "DxLib.h"

namespace monster
{
	class Monster
	{
	public:
		Monster()
		{
			monster_radius = 1;
			monster_bullet_radius = 1;
			MONSTER_COUNT = 5;
		}

		~Monster() = default;
	public:
		void Initialize();
		void Update();
		void CalkTask();
		void Draw();
		void Finalize();

	public:
		int monster_radius, monster_bullet_radius;		//�����X�^�[�̔��a�ƒe�ۂ̔��a��ݒ�
		int monster_pos_x, monster_pos_y, speed;		//�����X�^�[�̈ʒu�ƈړ����x
		int _Monster_img;								//�����X�^�[�̃C���[�W
		int MONSTER_COUNT;								//���ɕ\�����郂���X�^�[�̐�

		MonsterBullet _bullet[5];
	};
	class MonsterBullet
	{
	public:
		MonsterBullet()
		{
			bullet_speed = 20;
			bullet_pos_x = -100;
			bullet_pos_y = -100;
			_damage = 100;
		}
		~MonsterBullet() = default;

		void Initialize(int,int);
		void Update();
		void Finalize();

	private:
		int _Bullet_img;						//�����X�^�[�̒e�ۃ��\�[�X��Load
		int bullet_pos_x, bullet_pos_y;			//�����X�^�[�e�ۂ̏����ʒu��ݒ�
		int shootnumber, bullet_speed;			//�e�ۂ�ł��������敪���鐔���ƒe�ۂ̑��x
		int _damage;							//�_���[�W
	};
}