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
		int Player_HP;														//プレイヤーのHP
		int player_pos_x, player_pos_y, speed, shoot_count;					//プレイヤーの位置と移動スピード、打つ事をコントロールする変数
		const int player_radius = 25, player_bullet_radius = 30;			//プレイヤーの半径と弾丸の半径
		const int MAX_BULLET_COUNT = 50;									//弾丸の最大数

	private:

		void CalkTask();

	private:
		int _Player_img;													//プレイヤーのイメージ
		int PLAYER_MAX_POS_X;												//プレイヤーのX軸の移動制限する
		int PLAYER_MAX_POS_Y;												//プレイヤーのY軸の移動制限する
	};
}