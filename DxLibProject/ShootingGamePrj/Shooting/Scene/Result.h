#pragma once

#include "BaseSceneController.h"

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