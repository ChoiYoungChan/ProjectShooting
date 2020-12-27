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
			bullet_pos_x = -100;
			bullet_pos_y = -100;
		}
		~Bullet() = default;

		void Initialize();
		void GetPos(int, int);
		void Draw();
		void Update();
		void Finalize();
		void CalkBullet(int, int);

	public:
		int bullet_pos_x, bullet_pos_y;			//�����X�^�[�e�ۂ̏����ʒu��ݒ�
		int get_pos_x, get_pos_y;

	private:
		int _Bullet_img;						//�����X�^�[�̒e�ۃ��\�[�X��Load
		const int bullet_speed = 20;			//�e�ۂ�ł��������敪���鐔����default�̒e�ۂ̑��x
		const int _damage = 100;				//�_���[�W
		float bullet_speed_x, bullet_speed_y;

	};
}