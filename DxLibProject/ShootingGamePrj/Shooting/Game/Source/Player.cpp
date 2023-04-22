//--------------------------------------------------------------
//------------include Header
#include "Player.h"


namespace play_user
{
	void Player::Initialize()
	{
		_Player_img = LoadGraph("Resource/Player.png");
	}

	/// <summary>
	/// プレイヤーの移動制限
	/// </summary>
	void Player::CalkTask()
	{
		if (keyboard::GetKey(KEY_INPUT_RIGHT) >= 1) {
			_pos_x += _speed;
		}
		if (keyboard::GetKey(KEY_INPUT_DOWN) >= 1) {
			_pos_y += _speed;
		}
		if (keyboard::GetKey(KEY_INPUT_LEFT) >= 1) {
			_pos_x -= _speed;
		}
		if (keyboard::GetKey(KEY_INPUT_UP) >= 1) {
			_pos_y -= _speed;
		}
		if (keyboard::GetKey(KEY_INPUT_Z) >= 1)
		{
			BULLET_MANAGER().SetBullet(true, _Player_ID, _pos_x, (_pos_y - 10));
		}
		MoveLimit();
	}

	/// <summary>
	/// 긵깒귽깂?궻댷벍맕뙽
	/// </summary>
	void Player::MoveLimit()
	{
		if (_pos_x < 0)
		{
			_pos_x = 10;
		}
		if (_pos_x >= WINDOW_SIZE_X)
		{
			_pos_x = PLAYER_MAX_POS_X;
		}
		if (_pos_y <= 200)
		{
			_pos_y = 200;
		}
		if (_pos_y >= WINDOW_SIZE_Y)
		{
			_pos_y = PLAYER_MAX_POS_Y;
		}
	}

	/// <summary>
	/// プレイヤーと弾を表示する関数
	/// </summary>
	void Player::DrawTask()
	{
		if (player_invi_count % 2 == 0)
		{
			DrawCircle(_pos_x, _pos_y, _radius, GetColor(255, 0, 0), false);
			DrawRotaGraph(_pos_x, _pos_y, 1, 0, _Player_img, true);
		}
	}

	void Player::Finalize()
	{
		_isActive = false;
	}
}
