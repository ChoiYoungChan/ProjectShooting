#include "DxLib.h"
#include "..\Scene\Manager\InputKey.h"
#include "Bullet.h"
#include "..\Scene\Manager\BaseObject.h"

namespace play_user
{
	class Player : public base::BaseObject
	{
	public:
		Player()
		{
			shoot_count = 0;

			player_pos_x = 300;
			player_pos_y = 600;

			PLAYER_MAX_POS_X = WINDOW_SIZE_X - 10;
			PLAYER_MAX_POS_Y = WINDOW_SIZE_Y - 10;
		}
		~Player() = default;

	public:

		void Initialize();
		void Update();
		void DrawTask();
		void Finalize();

		//========================================
		//-----Bullet
		bullet::Bullet player_bullet[50];

	public:
		int player_pos_x, player_pos_y, shoot_count;					//�v���C���[�̈ʒu�ƈړ��X�s�[�h�A�ł����R���g���[������ϐ�
		const int MAX_BULLET_COUNT = 50;									//�e�ۂ̍ő吔

		//========================================
		//-----Bullet
		int bullet_pos_x, bullet_pos_y;			//�e�ۂ̈ʒu���W

	private:
		void CalkTask();

	private:
		int _Player_img;													//�v���C���[�̃C���[�W
		int PLAYER_MAX_POS_X;												//�v���C���[��X���̈ړ���������
		int PLAYER_MAX_POS_Y;												//�v���C���[��Y���̈ړ���������

		//========================================
		//-----Bullet
		int _Bullet_img;						//�e�ۂ̃C���[�W
		int shootnumber;						//�e�ۂ̐��Ƒ��x
	};
}