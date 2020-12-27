//--------------------------------------------------------------
//------------include Lib
#include "DxLib.h"
#include <math.h>
#include <vector>

//--------------------------------------------------------------
//------------include Header

#include "..\Scene\StageManager.h"
#include "..\Scene\Result.h"
#include "..\..\Manager\MonsterManager.h"
#include "..\..\Manager\BulletManager.h"
#include "..\..\Manager\PlayerManager.h"

namespace game
{
	class Stage : public scene::StageManager
	{
	public:
		Stage()
		{
			_begin_time = ZERO;
			_time_count = ZERO;
			_NextState = false;
		}
		~Stage() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;
		void InitVar();

	public:
		bool _NextState;

	private:
		playermanager::PlayerManager * playermanager = NULL;
		monstermanager::MonsterManager * enemyManager = NULL;
		bulletmanager::BulletManager * bulletManager = NULL;

		std::vector<base::BaseObject> listObjects;
		data::GameData gamedata;

		void Draw();
		void CalkTask();
		void SpawnMonster();
		void ImpactCheck();
		void CheckFinalize();
		void CheckGameOver();
		void ReadyNextStage();
		void Pause();

	private:

		int _begin_time;							//Stageを始めった瞬間の時間
		int _time_count;							//現在の時間を入れてモンスターが表示されるタイミングを特定するための変数
		int _nowSecond, boss_type;

		bool _isPause=false;

		typedef struct								//モンスターの移動をパターン化するためのStruct
		{
			bool isActive;
			bool type_boss;
			int monster_count;
			int monster_spawn_time;					//モンスターを表示するタイミング
			int shoot_bullet_time;
			int monster_pos_x;						//モンスターのｘとｙ軸の座標
			int monster_pos_y;
			int destination_pos_x;
			int destination_pos_y;

		}MonsterMovement;

		MonsterMovement _monster_table[StageState::Stage_Max][MOVE_COUNTER]
		{
			{ 
				{true, false,10, 5, 6,-400,-400, 500, 780},							//第一移動パターン
				{true, false,6 ,10,11,-300, 400, 880, 650},							//第二移動パターン
				{true, false,4 ,15,16, 800,-300, -50, 500},							//第三移動パターン
				{true, false,16,20,21,-400, 400, 800,-100},							//第四移動パターン
				{true, false,5 ,23,24, 750, 500,-300, 300},							//第五移動パターン
				{true, false,3 ,25,26, 400,-300, 300, 800},							//第六移動パターン
				{true, false,8 ,30,31,-450,-300, 600, 600},							//第七移動パターン
				{true, false,9 ,35,36, 800,-500,-200, 600},							//第八移動パターン
				{true, false,5 ,40,41, 800, 500,-800, 500},							//第九移動パターン
				{true, false,4 ,45,46,-400, 750, 700,-200},							//第十移動パターン
				{true, false,12,50,51, 700, 880, 100,-100},							//第十一移動パターン
				{true, false,1 ,55,56, 300, 750, 300,-500},							//第十二移動パターン
			},
			{
				{true, false,7 , 3, 4, 400,-300, 300, 800},							//第一移動パターン
				{true, false,6 , 8, 9, 800,-500,-200, 600},							//第二移動パターン
				{true, false,4 ,12,13,-300, 400, 880, 650},							//第三移動パターン
				{true, false,16,15,16,-400, 400, 800, 500},							//第四移動パターン
				{true, false,5 ,20,21, 750, 500,-300, 300},							//第五移動パターン
				{true, false,3 ,23,24, 400,-300, 300, 800},							//第六移動パターン
				{true, false,8 ,27,28,-450,-300, 600, 600},							//第七移動パターン
				{true, false,9 ,30,31, 700, 880, 100,-100},							//第八移動パターン
				{true, false,5 ,34,35, 800, 500,-800, 500},							//第九移動パターン
				{true, false,4 ,35,36, 300, 750, 300,-500},							//第十移動パターン
				{true, false,12,41,42, 700, 880, 100,-100},							//第十一移動パターン
				{true, true, 1, 45,46, 350, -50,  350, 80},							//第十二移動パターン
			},
			{
				{true, false,13, 2, 3, 300, 880, 300,-100},							//第一移動パターン
				{true, false,5 , 7, 8, 400,-300, 300, 800},							//第二移動パターン
				{true, false,9 ,11,12, 800,-300, -50, 500},							//第三移動パターン
				{true, false,10,15,16,-400, 400, 800, 500},							//第四移動パターン
				{true, false,8 ,19,20, 300, 750, 300, 300},							//第五移動パターン
				{true, false,4 ,22,23, 400,-300, 300, 800},							//第六移動パターン
				{true, false,5 ,26,27, 400,-300, 300, 800},							//第七移動パターン
				{true, false,6 ,31,32, 800,-500,-200, 600},							//第八移動パターン
				{true, false,8 ,35,36, 300, 750, 300,-500},							//第九移動パターン
				{true, false,9 ,39,40,-400, 750, 700,-200},							//第十移動パターン
				{true, false,10,42,43, 700, 880, 100,-100},							//第十一移動パターン
				{true, true, 1,	45,46, 350, -50,  350, 80},							//第十二移動パターン
			}
		};
	
	};
}