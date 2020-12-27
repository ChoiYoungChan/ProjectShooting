//--------------------------------------------------------------
//------------include Lib
#include "DxLib.h"
#include <math.h>

namespace monster
{
	class Bullet
	{
	public:
		Bullet()
		{
			bullet_speed = 20;
			bullet_pos_x = -100;
			bullet_pos_y = -100;
			_damage = 100;
		}
		~Bullet() = default;

		void Initialize(int, int);
		void Update();
		void Finalize();
		void CalkBullet(int, int);
	public:
		int bullet_pos_x, bullet_pos_y;			//�����X�^�[�e�ۂ̏����ʒu��ݒ�

	private:
		int _Bullet_img;						//�����X�^�[�̒e�ۃ��\�[�X��Load
		int shootnumber, bullet_speed;			//�e�ۂ�ł��������敪���鐔����default�̒e�ۂ̑��x
		int _damage;							//�_���[�W
		int WINDOW_SIZE_X = 720, WINDOW_SIZE_Y = 720;
		float bullet_speed_x, bullet_speed_y;

	};
}