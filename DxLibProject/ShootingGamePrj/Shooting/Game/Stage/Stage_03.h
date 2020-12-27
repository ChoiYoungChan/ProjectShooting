#include "DxLib.h"
#include "..\Scene\StageManager.h"
#include "..\Scene\Result.h"

namespace game
{
	class Stage03 : public scene::StageManager
	{
	public:
		Stage03()
		{
			_time_count = 0;
		}
		~Stage03() = default;

		void Initialize() override;
		void Update() override;
		void Finalize() override;

	private:
		int _time_count;
		
	};
}