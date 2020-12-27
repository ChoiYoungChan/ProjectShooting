#include "DxLib.h"
#include "..\Scene\Manager\InputKey.h"
#include "PlayerBullet.h"

namespace play_user
{
	class Player
	{
	public:
		Player()
		{
			player_radius =	1;
			player_bullet_radius = 1;
			shoot_count = 0;
			player_pos_x = 300;
			player_pos_y = 600;
			speed = 15;
			Player_HP = 3;
			_WINDOW_SIZE_X = 720;
			_WINDOW_SIZE_Y = 720;
			PLAYER_MAX_POS_X = _WINDOW_SIZE_X - 10;
			PLAYER_MAX_POS_Y = _WINDOW_SIZE_Y - 10;
		}
		~Player() = default;

	public:

		void Initialize();
		void Update();
		void Finalize();

	public:
		int Player_HP;														//�v���C���[��HP

	private:

		PlayerBullet shoot[50];

	private:
		int player_radius, player_bullet_radius;							//�v���C���[�̔��a�ƒe�ۂ̔��a
		int player_pos_x, player_pos_y, speed, shoot_count;					//�v���C���[�̈ʒu�ƈړ��X�s�[�h�A�ł����R���g���[������ϐ�
		int _Player_img;													//�v���C���[�̃C���[�W
		int _WINDOW_SIZE_X, _WINDOW_SIZE_Y;									//�v���C���[�̈ړ��������邽�߂̉�ʃT�C�Y
		int PLAYER_MAX_POS_X;												//�v���C���[��X���̈ړ���������
		int PLAYER_MAX_POS_Y;												//�v���C���[��Y���̈ړ���������
	};
}