#pragma once
#include "..\Scene\Manager\BaseObject.h"
#include "DxLib.h"

namespace bullet
{
	class Bullet : public base::BaseObject
	{
	public:
		Bullet()
		{
			shoot_number = 1;
			isActive = true;
		}
		~Bullet();

	public:
		void Initialize(int);
		void Update();
		void CalkTask();
		void DrawTask(int,int);
		void GetPosition(int,int);
		void SetTargetPosition(int ,int);
		void Finalize();

		void NormalPattern();
		void FirstPattern();
		void SecondPattern();
		void ThirdPattern();
		void ForthPattern();
		void FifthPattern();

	private:
		int pos_x, pos_y, image;
		int target_pos_x, target_pos_y;
		int shoot_number;
	};
}