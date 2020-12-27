#include "DxLib.h"
#include <memory>
#include "..\..\Manager\InputKey.h"
#include "Bullet.h"
#include "..\..\Manager\BaseObject.h"
#include "..\..\Manager\BulletManager.h"

namespace play_user
{
	class Player : public base::BaseObject
	{
		
	public:
		Player(bulletmanager::BulletManager* bulletManager) : BaseObject(base::TYPE::Player)
		{
			_bulletmanager = bulletManager;

			isActive = true;
			isPlayer = true;

			pos_x = 300;
			pos_y = 600;

			PLAYER_MAX_POS_X = WINDOW_SIZE_X - 10;
			PLAYER_MAX_POS_Y = WINDOW_SIZE_Y - 10;
		}

		~Player() = default;

	public:
		bulletmanager::BulletManager * _bulletmanager = NULL;

		void Initialize();
		void Update();
		void DrawTask();
		void Finalize();

	private:
		void CalkTask();
		

	private:
		int _Player_img;													//プレイヤーのイメージ
		int PLAYER_MAX_POS_X;												//プレイヤーのX軸の移動制限する
		int PLAYER_MAX_POS_Y;												//プレイヤーのY軸の移動制限する
		const int speed = 20;
	};
}