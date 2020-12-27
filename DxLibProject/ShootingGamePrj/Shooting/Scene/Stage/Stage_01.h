//--------------------------------------------------------------
//------------include Lib
#include "DxLib.h"
#include <math.h>

//--------------------------------------------------------------
//------------include Header
#include "..\..\Source\Player.h"
#include "..\..\Source\Monster.h"
#include "..\StageManager.h"


namespace game
{
	class Stage01 : public scene::StageManager
	{
	public:
		Stage01()
		{
			_time_count = 0;
		}
		~Stage01() = default;

	public:

		void Initialize() override;
		void Update() override;
		void Finalize() override;

	private:
		play_user::Player player;
		play_user::PlayerBullet player_bullet;
		monster::Monster enemy;
		monster::Bullet monster_bullet;

		void Draw();
		void CalkTask();
		void ImpactCalk();

	private:
		int _time_count;							//現在の時間を入れてモンスターが表示されるタイミングを特定するための変数
		int distance_01;							//モンスターとプレイヤーの間の距離->衝突判定に使用
		int distance_02;							//モンスターとプレイヤー弾の間の距離->衝突判定に使用
		int distance_03;							//モンスター弾とプレイヤーの間の距離->衝突判定に使用

	};
}