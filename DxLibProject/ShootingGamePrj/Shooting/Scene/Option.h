#pragma once
#include "BaseSceneController.h"
#include "Manager/InputKey.h"

namespace scene
{
	class Option : public BaseScene
	{
	public:
		Option() = default;

		~Option() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;

	private:
	};
}