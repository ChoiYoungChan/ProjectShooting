#pragma once
#include "BaseSceneController.h"

namespace scene
{
	class Exit : public BaseScene
	{
	public:
		Exit() :BaseScene(State::Exit) {}
		~Exit() = default;

		void Initialize() override {};
		void Update() override {};
		void Finalize() override {};
	};
}