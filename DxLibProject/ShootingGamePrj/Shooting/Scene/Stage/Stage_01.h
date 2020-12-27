//--------------------------------------------------------------
//------------include DX
#include "DxLib.h"
//--------------------------------------------------------------
//------------include Header
#include "..\..\Source\Player.h"
#include "..\..\Source\Monster.h"
#include "..\StageManager.h"
#include <math.h>


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
		play_user::Player user;
		monster::Monster monster_enemy;

		void Draw();
		void CalkTask();
		void ImpackCalk();

	private:
		int _time_count;
		int distance;

		typedef struct								//モンスターの移動をパターン化するためのStruct
		{
			int monster_spawn_time;					//モンスターを表示するタイミング
			int monster_pos_x;						//モンスターのｘとｙ軸の座標
			int monster_pos_y;

		}MonsterMovement;

		MonsterMovement monster_move[5]
		{
			{5,   10, -10},							//第一パターン
			{10, -50,  10},							//第二パターン
			{15, 800,  20},							//第三パターン
			{20, -10, -10},							//第四パターン
			{25, 800, -10},							//第五パターン
		};

		typedef struct								//モンスターが打つ弾の弾幕の設定をするためのStruct
		{
			int monster_bullet_x;
			int monster_bullet_y;
		}MonsterBullet;

		MonsterBullet monster_bullet[2]
		{
			{},{}
		};

	};
}