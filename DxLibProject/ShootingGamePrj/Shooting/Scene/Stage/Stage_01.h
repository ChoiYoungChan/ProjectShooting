//--------------------------------------------------------------
//------------include Lib
#include "DxLib.h"
#include <math.h>

//--------------------------------------------------------------
//------------include Header
#include "..\..\Source\Player.h"
#include "..\..\Source\Monster.h"
#include "..\StageManager.h"
#include "..\Result.h"


namespace game
{
	class Stage01 : public scene::StageManager
	{
	public:
		Stage01()
		{
			_begin_time = 0;
			_time_count = 0;
			stagenumber = 1;
			score = 0;
		}
		~Stage01() = default;

	public:

		void Initialize() override;
		void Update() override;
		void Finalize() override;

	private:
		play_user::Player player;
		monster::Monster enemy;
		scene::StageManager stagemanager;

		void Draw();
		void CalkTask();
		void ImpactCalk();
		void SpawnMonster();

	private:

		typedef struct								//モンスターの移動をパターン化するためのStruct
		{
			int monster_spawn_time;					//モンスターを表示するタイミング
			int monster_pos_x;						//モンスターのｘとｙ軸の座標
			int monster_pos_y;

		}MonsterMovement;

		MonsterMovement monster_move[5]
		{
			{5,   10, -10},							//第一移動パターン
			{10, -50,  10},							//第二移動パターン
			{15, 800,  20},							//第三移動パターン
			{20, -10, -10},							//第四移動パターン
			{25, 800, -10},							//第五移動パターン
		};


		int _begin_time;							//Stageを始めった瞬間の時間
		int _time_count;							//現在の時間を入れてモンスターが表示されるタイミングを特定するための変数
		int distance_01;							//モンスターとプレイヤーの間の距離->衝突判定に使用
		int distance_02;							//モンスターとプレイヤー弾の間の距離->衝突判定に使用
		int distance_03;							//モンスター弾とプレイヤーの間の距離->衝突判定に使用
		int stagenumber, score;
		const int move_counter = 5;

		scene::Result result;

	};
}