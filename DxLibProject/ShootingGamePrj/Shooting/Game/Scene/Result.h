#pragma once

#include "BaseSceneController.h"
#include "..\..\Manager\InputKey.h"

namespace scene
{
	class Result : public BaseScene
	{
	public:
		Result()
		{
			result_stage_number = 1;
			result_score = 0;
		}

		~Result() = default;
		void Initialize() override;
		void Update() override;
		void Finalize() override;
		void GetGameData(bool,int,int);
		void DrawTask();

	private:
		int StrWidth, StrLen;
		bool winorlose;
		char result_status;
		int result_stage_number;
		int result_score;
	};

}