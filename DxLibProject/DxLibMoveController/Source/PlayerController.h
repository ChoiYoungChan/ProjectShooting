#pragma once
#include "DxLib.h"

namespace controller
{
	class PlayerController
	{
	public:
		PlayerController()
		{

		}
		~PlayerController() = default;
		void Controller(int, int);
	private:
		int speed;
	};
}

