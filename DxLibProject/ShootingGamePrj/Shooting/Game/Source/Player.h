#include "DxLib.h"

#include "..\..\Manager\InputKey.h"
#include "..\..\Manager\BaseObject.h"
#include "..\..\Manager\BulletManager.h"

namespace play_user
{
	class Player : public base::BaseObject
	{
	public:
		Player() : BaseObject(base::TYPE::Player)
		{
			bullet_shooter = 0;

			isActive = true;
			isPlayer = true;

			pos_x = 350;
			pos_y = 600;

			PLAYER_MAX_POS_X = WINDOW_SIZE_X - 10;
			PLAYER_MAX_POS_Y = WINDOW_SIZE_Y - 10;
		}

		~Player() = default;

	public:
		void Initialize();
		void CalkTask();
		void DrawTask();
		void Finalize();
	public:
		int player_invi_count = 0;

	private:
		int _Player_img;													//プレイヤーのイメージ
		int PLAYER_MAX_POS_X;												//プレイヤーのX軸の移動制限する
		int PLAYER_MAX_POS_Y;												//プレイヤーのY軸の移動制限する
		const int speed = 20;
	};
}