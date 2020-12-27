#include "Player.h"

namespace play_user
{
	void Player::Initialize()
	{
		_Player_img = LoadGraph("Resource/Player.png");
	}

	/// <summary>
	/// �v���C���[�̃R���g���[���ƕ\�����邱��
	/// ZKey���������ۂɒe��ł���
	/// </summary>
	void Player::Update()
	{
		CalkTask();
	}

	/// <summary>
	/// �v���C���[�̈ړ�����
	/// </summary>
	void Player::CalkTask()
	{
		if (keyboard::GetKey(KEY_INPUT_RIGHT) >= 1) {
			pos_x += speed;
		}
		if (keyboard::GetKey(KEY_INPUT_DOWN) >= 1) {
			pos_y += speed;
		}
		if (keyboard::GetKey(KEY_INPUT_LEFT) >= 1) {
			pos_x -= speed;
		}
		if (keyboard::GetKey(KEY_INPUT_UP) >= 1) {
			pos_y -= speed;
		}
		if (keyboard::GetKey(KEY_INPUT_Z) >= 1)
		{
			_bulletmanager -> SetBullet(true, pos_x, (pos_y - 50));
		}
		if (pos_x < 0)
		{
			pos_x = 10;
		}
		if (pos_x >= WINDOW_SIZE_X)
		{
			pos_x = PLAYER_MAX_POS_X;
		}
		if (pos_y <= 200)
		{
			pos_y = 200;
		}
		if (pos_y >= WINDOW_SIZE_Y)
		{
			pos_y = PLAYER_MAX_POS_Y;
		}
	}

	/// <summary>
	/// �v���C���[�ƒe��\������֐�
	/// </summary>
	void Player::DrawTask()
	{
		DrawRotaGraph(pos_x, pos_y, 1, 0, _Player_img, true);
	}

	void Player::Finalize()
	{
		isActive = false;
	}
}
