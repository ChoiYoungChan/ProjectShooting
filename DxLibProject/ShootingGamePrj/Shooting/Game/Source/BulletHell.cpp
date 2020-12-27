#include "BulletHell.h"
#include "Bullet.h"
#include "..\..\Manager\MonsterManager.h"

namespace bullet
{
	static void( * BulletPattern[PATTERN_COUNT])(Bullet *bullet) =
	{
		BulletHell::NormalMonster,
		BulletHell::BossMonster,
	};

	void BulletHell::NormalMonster(Bullet *bullet)
	{
		bullet->_pos_x += speed_x;
		bullet->_pos_y -= speed_y;
	}

	void BulletHell::BossMonster(Bullet *bullet)
	{
		int count = HP/50;

		speed_x = 0;
		speed_y = 1;

		if (count > 50)
		{
			PhaseOne(bullet, monsterID);
		}
		else if (count <= 50 && count > 30)
		{
			PhaseTwo(bullet, monsterID);
		}
		else if (count <= 30)
		{
			PhaseThree(bullet, monsterID);
		}
	}

	void BulletHell::Pattern(Bullet *bullet)
	{
		BulletPattern[monsterID](bullet);
	}

	void BulletHell::SetPosition(Bullet *bullet, int monster_id)
	{
	/*	center_x = monstermanager::MonsterManager::Instance().GetBoss()->_pos_x;
		center_y = monstermanager::MonsterManager::Instance().GetBoss()->_pos_y;

		HP = monstermanager::MonsterManager::Instance().GetBoss()->Monster_HP;
     */
		monsterID = monster_id;

		float distance = (float)sqrt(pow(bullet->_target_pos_x - bullet->_pos_x, 2) +
									 pow((bullet->_target_pos_y + 50) - bullet->_pos_y, 2));
		if (distance)
		{
			speed_x = (int)((bullet->_target_pos_x - bullet->_pos_x) / distance * bullet_speed);
			speed_y = (int)(((bullet->_target_pos_y + 50) - bullet->_pos_y) / distance * bullet_speed);
		}
		else
		{
			speed_x += bullet_speed;
			speed_y += bullet_speed;
		}
	}

	//Bossƒ‚ƒ“ƒXƒ^[‚ð’†S‚É‰ñ“]‚µ‚È‚ª‚ç”¼Œa‚ðL‚ª‚·
	void BulletHell::PhaseOne(Bullet *bullet, int level)
	{
		bullet->_theta += bullet->_omega;
		bullet->_vec_radi++;

		float calk_radi = (bullet->_radi + bullet->_vec_radi);

		double calk_cos = cos(bullet->_theta);
		double calk_sin = sin(bullet->_theta);

		bullet->_pos_x = (int)(center_x + (calk_radi * calk_cos));
		bullet->_pos_y = (int)(center_y + (calk_radi * calk_sin));

		if (bullet->_pos_y > WINDOW_SIZE_Y + 100)
		{
			bullet->_isActive = false;
		}
	}

	//îŒ`‚É’eŠÛ‚ð”­ŽË‚·‚é
	void BulletHell::PhaseTwo(Bullet *bullet, int level)
	{
		bullet->_theta = 5;						  // ’eŠÛ‚Æ’eŠÛ‚ÌŠÔ‚ÌŠp“x
		float radi = PI / 180 * bullet->_theta; // ’eŠÛ‚Æ’eŠÛ‚ÌŠÔ‚ÌŠp“x‚ðRadian‚ð—˜—p‚µ‚Ä•ÏŠ·‚·‚é

		float speed_x_new, speed_y_new;

		float center_radi = (BOSS_COUNT % 2) ? 
			(-BOSS_COUNT / 2 * radi) : (-BOSS_COUNT / 2 + 0.5 * radi);

		double calk_cos = cos(center_radi);
		double calk_sin = sin(center_radi);

		speed_x_new = ((speed_x * calk_cos) - (speed_y * calk_sin)) * bullet->_speed;
		speed_y_new = ((speed_x * calk_sin) + (speed_y * calk_cos)) * bullet->_speed;

		bullet->_pos_x += speed_x_new;
		bullet->_pos_y += speed_y_new;

		if (bullet->_pos_x > WINDOW_SIZE_X + 150 || bullet->_pos_y > WINDOW_SIZE_Y + 150)
		{
			bullet->_isActive = false;
		}
	}

	void BulletHell::PhaseThree(Bullet *bullet, int level)
	{
		float speed = 15.0f;
		float accel = 10.0f;

		speed_x/speed, speed_y/speed;

		speed += accel;

		bullet->_pos_x += speed;
		bullet->_pos_y += speed;

		if (bullet->_pos_x > WINDOW_SIZE_X + 150 || bullet->_pos_y > WINDOW_SIZE_Y + 150)
		{
			bullet->_isActive = false;
		}
	}
}