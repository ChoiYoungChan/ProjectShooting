//--------------------------------------------------------------
//------------include Lib
#include "DxLib.h"
#include <math.h>

namespace monster
{
	class Bullet
	{
	public:
		Bullet()
		{
			bullet_pos_x = -100;
			bullet_pos_y = -100;
		}
		~Bullet() = default;

		void Initialize();
		void GetPos(int, int);
		void Draw();
		void Update();
		void Finalize();
		void CalkBullet(int, int);

	public:
		int bullet_pos_x, bullet_pos_y;			//モンスター弾丸の初期位置を設定
		int get_pos_x, get_pos_y;

	private:
		int _Bullet_img;						//モンスターの弾丸リソースをLoad
		const int bullet_speed = 20;			//弾丸を打った時を区分する数字とdefaultの弾丸の速度
		const int _damage = 100;				//ダメージ
		float bullet_speed_x, bullet_speed_y;

	};
}