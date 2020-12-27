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
		int player_pos_x, player_pos_y, shoot_count;					//プレイヤーの位置と移動スピード、打つ事をコントロールする変数
		const int MAX_BULLET_COUNT = 50;									//弾丸の最大数

		//========================================
		//-----Bullet
		int bullet_pos_x, bullet_pos_y;			//弾丸の位置座標

	private:
		void CalkTask();

	private:
		int _Player_img;													//プレイヤーのイメージ
		int PLAYER_MAX_POS_X;												//プレイヤーのX軸の移動制限する
		int PLAYER_MAX_POS_Y;												//プレイヤーのY軸の移動制限する

		//========================================
		//-----Bullet
		int _Bullet_img;						//弾丸のイメージ
		int shootnumber;						//弾丸の数と速度
	};
}