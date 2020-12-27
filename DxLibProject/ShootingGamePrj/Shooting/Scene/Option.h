#pragma once
#include "BaseSceneController.h"

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
		int key[256];
		int InputKey()
		{
			char keyvalue[256];
			GetHitKeyStateAll(keyvalue);
			for (int index = 0; index < 256; index++)
			{
				if (keyvalue[index] != 0)
					keyvalue[index] = 1;
				else
					keyvalue[index] = 0;
			}
		}
	};
}