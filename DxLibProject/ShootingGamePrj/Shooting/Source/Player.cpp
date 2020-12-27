#include "Player.h"

namespace play_user
{
	void Player::Initialize()
	{
		_Player_img = LoadGraph("Player.png");
		speed = 15;
		Player_HP = 3;
	}

	/// <summary>
	/// �v���C���[�̃R���g���[���ƕ\�����邱��
	/// ZKey���������ۂɒe��ł���
	/// </summary>
	void Player::Update()
	{
		CalkTask();
		DrawTask();
	}

	/// <summary>
	/// �v���C���[�̈ړ�����
	/// </summary>
	void Player::CalkTask()
	{
		if (keyboard::GetKey(KEY_INPUT_RIGHT) >= 1) {
			player_pos_x += speed;
		}
		if (keyboard::GetKey(KEY_INPUT_DOWN) >= 1) {
			player_pos_y += speed;
		}
		if (keyboard::GetKey(KEY_INPUT_LEFT) >= 1) {
			player_pos_x -= speed;
		}
		if (keyboard::GetKey(KEY_INPUT_UP) >= 1) {
			player_pos_y -= speed;
		}
		if (keyboard::GetKey(KEY_INPUT_Z) >= 1)
		{
			shoot[shoot_count].Initialize(player_pos_x, player_pos_y);
			shoot_count++;
			if (shoot_count >= MAX_BULLET_COUNT)
			{
				shoot_count = 0;
			}
		}
		if (player_pos_x < 0)
		{
			player_pos_x = 10;
		}
		if (player_pos_x >= _WINDOW_SIZE_X)
		{
			player_pos_x = PLAYER_MAX_POS_X;
		}
		if (player_pos_y <= 200)
		{
			player_pos_y = 200;
		}
		if (player_pos_y >= _WINDOW_SIZE_Y)
		{
			player_pos_y = PLAYER_MAX_POS_Y;
		}
	}

	/// <summary>
	/// �v���C���[�ƒe��\������֐�
	/// </summary>
	void Player::DrawTask()
	{
		DrawRotaGraph(player_pos_x, player_pos_y, 1, 0, _Player_img, true);

		for (int count = 0; count < MAX_BULLET_COUNT; count++)
		{
			shoot[count].Update();
		}
	}

	void Player::Finalize()
	{

	}
}
