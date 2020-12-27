#include "PlayerBullet.h"

namespace play_user
{
	/// <summary>
	/// 初期化する際に弾丸が発射される位置とスピード、弾のイメージを受ける
	/// 
	/// </summary>
	/// <param name="pos_x">弾丸が発射される位置(プレイヤーのX軸座標)</param>
	/// <param name="pos_y">弾丸が発射される位置(プレイヤーのY軸座標)</param>
	void PlayerBullet::Initialize(int pos_x, int pos_y)
	{
		if (shootnumber == 1)
		{
			bullet_pos_x = pos_x;
			bullet_pos_y = pos_y;

			_Bullet_img = LoadGraph("Moriya.png");
		}
	}
	/// <summary>
	/// 弾の移動処理
	/// </summary>
	void PlayerBullet::Update()
	{
		if (bullet_pos_y > 0)
		{
			DrawRotaGraph(bullet_pos_x, bullet_pos_y - 50, 0.05, 0, _Bullet_img, true);
			bullet_pos_y -= bullet_speed;
			shootnumber = 0;
		}
		else
		{
			bullet_pos_y = -5;
			shootnumber = 1;
		}
	}

	void PlayerBullet::Finalize()
	{

	}
}