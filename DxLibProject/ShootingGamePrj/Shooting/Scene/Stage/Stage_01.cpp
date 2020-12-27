#include "Stage_01.h"

namespace game
{
	void Stage01::Initialize()
	{
		user.Initialize();						//プレイヤーをInitializeする
		monster_enemy.Initialize();				//モンスターをInitializeする
	}

	void Stage01::Update()
	{
		_time_count = GetNowCount();			//Stage01の時間を取って弾幕生成する際に使う変数
		CalkTask();								//衝突判定を計算する関数
		Draw();									//モンスターとプレイヤーを表示する関数
	}

	void Stage01::Finalize()
	{
		
	}

	void Stage01::Draw()
	{
		user.Update();							//プレイヤーの移動や表示などを適用する
		monster_enemy.Update();					//モンスターの移動や表示などを適用する
	}
	void Stage01::CalkTask()
	{
		ImpackCalk();

	}
	void Stage01::ImpackCalk()
	{

	}
}