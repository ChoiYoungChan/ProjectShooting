#include "Player.h"

namespace play_user
{
	void Player::Initialize()
	{
		_Player_img = LoadGraph("Resource/Player.png");
		_Bullet_img = LoadGraph("Resource/Moriya.png");

		for (int index = 0; index < MAX_BULLET_COUNT; index++)
		{
			player_bullet[index].Initialize(_Bullet_img);
		}
	}

	/// <summary>
	/// プレイヤーのコントロールと表示すること
	/// ZKeyを押した際に弾を打つこと
	/// </summary>
	void Player::Update()
	{
		CalkTask();
		DrawTask();
	}
	/// <summary>
	/// プレイヤーの移動制限
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
			player_bullet[shoot_count].SetPosition(pos_x, pos_y);
			shoot_count++;
			if (shoot_count >= MAX_BULLET_COUNT)
			{
				shoot_count = 0;
			}
		}
		for (int count = 0; count < MAX_BULLET_COUNT; count++)
		{
			player_bullet[count].PlayerBulletUpdate();
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
	/// プレイヤーと弾を表示する関数
	/// </summary>
	void Player::DrawTask()
	{
		DrawRotaGraph(pos_x, pos_y, 1, 0, _Player_img, true);

		for (int count = 0; count < MAX_BULLET_COUNT; count++)
		{
			player_bullet[count].DrawTask();
		}
	}

	void Player::Finalize()
	{
		isActive = false;
	}
}
