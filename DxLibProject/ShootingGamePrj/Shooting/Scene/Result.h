#pragma once

#include "BaseSceneController.h"
#include "Manager/InputKey.h"

namespace scene
{
	class Result : public BaseScene
	{
	public:
		Result() = default;
		~Result() = default;
		void Initialize() override;
		void Update() override;
		void Finalize() override;
	private:

	};

}