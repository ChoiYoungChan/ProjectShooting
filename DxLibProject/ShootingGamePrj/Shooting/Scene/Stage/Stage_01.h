//--------------------------------------------------------------
//------------include DX
#include "DxLib.h"
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
		play_user::Player user;
		monster::Monster monster_enemy;

		void Draw();
		void CalkTask();

	private:
		int _time_count;
		int distance;

	};
}