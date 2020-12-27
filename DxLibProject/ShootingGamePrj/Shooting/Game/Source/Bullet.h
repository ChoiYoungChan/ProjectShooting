#pragma once
#include "..\..\Manager\BaseObject.h"
#include "DxLib.h"

namespace bullet
{
	class Bullet : public base::BaseObject
	{
	public:
		Bullet() = default;
		~Bullet() = default;

	public:
		void Initialize(int);
		void Update();
		void CalkTask();
		void DrawTask();
		void Finalize();

		void PlayerBulletUpdate();
		void MonsterBulletUpdate();
		void SetPosition(int,int);
		void SetTargetPosition(int ,int);

	private:
		int pos_x, pos_y, image;
		int target_pos_x, target_pos_y;
		const int bullet_speed = 30;
	};
}