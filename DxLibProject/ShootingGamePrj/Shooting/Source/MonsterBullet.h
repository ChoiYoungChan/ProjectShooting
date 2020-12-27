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
			bullet_speed = 20;
			bullet_pos_x = -100;
			bullet_pos_y = -100;
			_damage = 100;
		}
		~Bullet() = default;

		void Initialize(int, int);
		void Update();
		void Finalize();
		void CalkBullet(int, int);
	public:
		int bullet_pos_x, bullet_pos_y;			//モンスター弾丸の初期位置を設定

	private:
		int _Bullet_img;						//モンスターの弾丸リソースをLoad
		int shootnumber, bullet_speed;			//弾丸を打った時を区分する数字とdefaultの弾丸の速度
		int _damage;							//ダメージ
		int WINDOW_SIZE_X = 720, WINDOW_SIZE_Y = 720;
		float bullet_speed_x, bullet_speed_y;

	};
}