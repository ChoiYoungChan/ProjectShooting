#include "BulletHell.h"
#include "Bullet.h"
#include "..\..\Manager\MonsterManager.h"
#include "..\..\Manager\BulletManager.h"

namespace bullet
{
	static void(*BulletPattern[PATTERN_COUNT])(Bullet *bullet) =
	{
		BulletHell::NormalMonster,
		BulletHell::BossMonster
	};

	void BulletHell::NormalMonster(Bullet *bullet)
	{
		bullet->pos_x += speed_x;
		bullet->pos_y -= speed_y;
	}

	void BulletHell::BossMonster(Bullet *bullet)
	{
		int count = HP / 50;

		center_x = -2.0f;
		center_y = 1.0f;

		if (count > 50)
		{
			PhaseTwo(bullet, monsterID);
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

	void BulletHell::SetPosition(Bullet *bullet, int monster_id, int count)
	{
		HP = monstermanager::MonsterManager::Instance().GetBoss()->Monster_HP;
	
		monsterID = monster_id;
		count_x = count;

		float distance = (float)sqrt(pow(bullet->target_pos_x - bullet->pos_x, 2) +
			pow((bullet->target_pos_y + 50) - bullet->pos_y, 2));
		if (distance)
		{
			speed_x = (int)((bullet->target_pos_x - bullet->pos_x) / distance * bullet_speed);
			speed_y = (int)(((bullet->target_pos_y + 50) - bullet->pos_y) / distance * bullet_speed);
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
		bullet->theta += bullet->omega;
		bullet->vec_radi++;

		float calk_radi = (bullet->radi + bullet->vec_radi);

		double calk_cos = cos(bullet->theta);
		double calk_sin = sin(bullet->theta);

		bullet->pos_x = (int)(center_x + (calk_radi * calk_cos));
		bullet->pos_y = (int)(center_y + (calk_radi * calk_sin));

		if (bullet->pos_y > WINDOW_SIZE_Y + 100)
		{
			bullet->isActive = false;
		}
	}

	//îŒ`‚É’eŠÛ‚ð”­ŽË‚·‚é
	void BulletHell::PhaseTwo(Bullet *bullet, int level)
	{
		bullet->theta = 5;						  // ’eŠÛ‚Æ’eŠÛ‚ÌŠÔ‚ÌŠp“x
		float radi = PI / 180 * bullet->theta;    // ’eŠÛ‚Æ’eŠÛ‚ÌŠÔ‚ÌŠp“x‚ðRadian‚ð—˜—p‚µ‚Ä•ÏŠ·‚·‚é

		float speed_x_new[BOSS_COUNT], speed_y_new[BOSS_COUNT];

		float center_radi = (BOSS_COUNT%2) ? (-BOSS_COUNT / 2 * radi) : ((-BOSS_COUNT / 2+0.5) * radi);

		for (int index = 0; index < BOSS_COUNT; index++)
		{
			double calk_cos = cos(center_radi);
			double calk_sin = sin(center_radi);

			speed_x_new[index] = ((center_x * calk_cos) - (center_y * calk_sin)) * bullet->speed;
			speed_y_new[index] = ((center_x * calk_sin) + (center_y * calk_cos)) * bullet->speed;

			bullet->pos_x += speed_x_new[index] + (count_x);
			bullet->pos_y += speed_y_new[index];

			bullet = bulletmanager::BulletManager::Instance().Getbullet(index);
		}

		if (bullet->pos_x > WINDOW_SIZE_X + 150 || bullet->pos_y > WINDOW_SIZE_Y + 150)
		{
			bullet->isActive = false;
		}
		
	}

	void BulletHell::PhaseThree(Bullet *bullet, int level)
	{
		float speed = 15.0f;
		float accel = 10.0f;

		speed_x / speed, speed_y / speed;

		speed += accel;

		bullet->pos_x += speed;
		bullet->pos_y += speed;

		if (bullet->pos_x > WINDOW_SIZE_X + 150 || bullet->pos_y > WINDOW_SIZE_Y + 150)
		{
			bullet->isActive = false;
		}
	}
}