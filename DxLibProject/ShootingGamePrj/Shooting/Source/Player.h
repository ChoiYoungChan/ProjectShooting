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
			player_radius =	25;
			player_bullet_radius = 30;
			shoot_count = 0;
			player_pos_x = 300;
			player_pos_y = 600;
			_WINDOW_SIZE_X = 720;
			_WINDOW_SIZE_Y = 720;
			PLAYER_MAX_POS_X = _WINDOW_SIZE_X - 10;
			PLAYER_MAX_POS_Y = _WINDOW_SIZE_Y - 10;

			MAX_BULLET_COUNT = 50;
		}
		~Player() = default;

	public:

		void Initialize();
		void Update();
		void Finalize();

	public:
		int Player_HP;														//プレイヤーのHP
		int player_pos_x, player_pos_y, speed, shoot_count;					//プレイヤーの位置と移動スピード、打つ事をコントロールする変数
		int player_radius, player_bullet_radius;							//プレイヤーの半径と弾丸の半径

	private:

		PlayerBullet shoot[50];

	private:
		int MAX_BULLET_COUNT;												//弾丸の最大数
		int _Player_img;													//プレイヤーのイメージ
		int _WINDOW_SIZE_X, _WINDOW_SIZE_Y;									//プレイヤーの移動制限するための画面サイズ
		int PLAYER_MAX_POS_X;												//プレイヤーのX軸の移動制限する
		int PLAYER_MAX_POS_Y;												//プレイヤーのY軸の移動制限する
	};
}