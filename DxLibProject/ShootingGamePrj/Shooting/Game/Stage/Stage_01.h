//--------------------------------------------------------------
//------------include Lib
#include "DxLib.h"
#include <math.h>
#include <vector>

//--------------------------------------------------------------
//------------include Header
#include "..\Source\Player.h"
#include "..\Source\Monster.h"

#include "..\Scene\StageManager.h"
#include "..\Scene\Result.h"

namespace game
{
	class Stage01 : public scene::StageManager
	{
	public:
		Stage01()
		{
			_begin_time = 0;
			_time_count = 0;

			StageID = 1;
		}
		~Stage01() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;

	private:
		play_user::Player player;
		monster::Monster enemy[5];

		std::vector<base::BaseObject> listObjects;

		data::GameData gamedata;
		scene::StageManager stagemanager;

		void Draw();
		void CalkTask();
		//bool ImpactCalk(int);
		void SpawnMonster();
		void ImpactCheck();

	private:

		typedef struct								//モンスターの移動をパターン化するためのStruct
		{
			bool isActive;
			int monster_spawn_time;					//モンスターを表示するタイミング
			int monster_pos_x;						//モンスターのｘとｙ軸の座標
			int monster_pos_y;
			int destination_pos_x;
			int destination_pos_y;

		}MonsterMovement;

		MonsterMovement monster_move[11]
		{
			{true,5, -200,-200, 500, 780},							//第一移動パターン
			{true,10,-300, 400, 880, 650},							//第二移動パターン
			{true,15, 800,-200, -50, 500},							//第三移動パターン
			{true,20,-300, 300, 800, 300},							//第四移動パターン
			{true,25, 300,-200, 300, 800},							//第五移動パターン
			{true,30,-150,-200, 600, 600},							//第六移動パターン
			{true,35, 800,-500,-200, 600},							//第七移動パターン
			{true,40, 800, 500,-800, 500},							//第八移動パターン
			{true,45,-400, 750, 600,-800},							//第九移動パターン
			{true,50, 700, 880,-300,-100},							//第十移動パターン
			{true,55, 600, 750, 600,-500},							//第十一移動パターン

		};


		int _begin_time;							//Stageを始めった瞬間の時間
		int _time_count;							//現在の時間を入れてモンスターが表示されるタイミングを特定するための変数
		
		int distance_01;							//モンスターとプレイヤーの間の距離->衝突判定に使用
		int distance_02;							//モンスターとプレイヤー弾の間の距離->衝突判定に使用
		int distance_03;							//モンスター弾とプレイヤーの間の距離->衝突判定に使用

		const int move_counter = 11;
		const int MONSTER_COUNT = 5;							//一回に表示されるモンスターの数
		int StageID;

		scene::Result result;
	};
	
}