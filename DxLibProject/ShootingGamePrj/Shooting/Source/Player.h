#include "DxLib.h"
#include "..\Scene\Manager\InputKey.h"
#include "PlayerBullet.h"

extern int WINDOW_SIZE_X;
extern int WINDOW_SIZE_Y;

namespace play_user
{
	class Player
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

		PlayerBullet shoot[50];

	public:
		int Player_HP;														//�v���C���[��HP
		int player_pos_x, player_pos_y, speed, shoot_count;					//�v���C���[�̈ʒu�ƈړ��X�s�[�h�A�ł����R���g���[������ϐ�
		const int player_radius = 25, player_bullet_radius = 30;			//�v���C���[�̔��a�ƒe�ۂ̔��a
		const int MAX_BULLET_COUNT = 50;									//�e�ۂ̍ő吔

	private:

		void CalkTask();

	private:
		int _Player_img;													//�v���C���[�̃C���[�W
		int PLAYER_MAX_POS_X;												//�v���C���[��X���̈ړ���������
		int PLAYER_MAX_POS_Y;												//�v���C���[��Y���̈ړ���������
	};
}