#include "MonsterBullet.h"

extern int WINDOW_SIZE_Y;

namespace monster
{
	void Bullet::Initialize()
	{
		_Bullet_img = LoadGraph("Resource/Bullet_0005.png");
		
	}
	void Bullet::GetPos(int monster_pos_x, int monster_pos_y)
	{
		bullet_pos_x = monster_pos_x;
		bullet_pos_y = monster_pos_y;
	}
	void Bullet::Update()
	{
		bullet_pos_x += bullet_speed;
		bullet_pos_y -= bullet_speed_y;

		Draw();
	}
	void Bullet::Draw()
	{
		DrawRotaGraph(bullet_pos_x, bullet_pos_y + 50, 0.3, 0, _Bullet_img, true);
	}
	void Bullet::Finalize()
	{

	}
	/// <summary>
	/// モンスターの基本的な弾幕Sampleの実装
	/// </summary>
	/// <param name="player_pos_x">目的地PlayerのX軸座標</param>
	/// <param name="player_pos_y">目的地PlayerのY軸座標</param>
	/// モンスターが画面内に移動したらプレイヤーに弾を打つことー＞予定
	void Bullet::CalkBullet(int player_pos_x, int player_pos_y)
	{
		get_pos_x = bullet_pos_x;
		get_pos_y = bullet_pos_y;

		float distance = (int)sqrt(pow(player_pos_x - get_pos_x, 2) + pow(player_pos_y - get_pos_y, 2));

		if (distance)
		{
			bullet_speed_x = (get_pos_x - player_pos_x) / distance * bullet_speed;
			bullet_speed_y = (get_pos_y - player_pos_y) / distance * bullet_speed;
			if (bullet_speed_x <= 0)
			{
				bullet_speed_x * -1;
			}
		}
		else
		{
			bullet_speed_x = 0;
			bullet_speed_y = bullet_speed;
		}
	}
}