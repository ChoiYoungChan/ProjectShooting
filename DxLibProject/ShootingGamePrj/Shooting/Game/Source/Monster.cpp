//--------------------------------------------------------------
//------------include Header
#include "Monster.h"
#include "..\..\Manager\BulletManager.h"

namespace monster
{
	void Monster::Initialize()
	{
		_isActive = false;
	}

	/// <summary>
	/// �����X�^�[��\������֐�
	/// </summary>
	void Monster::Draw()
	{
		if (_isActive)
		{
			DrawCircle(_pos_x, _pos_y, _radius, GetColor(255,255,255),false);
			DrawRotaGraph(_pos_x, _pos_y, 1.0, 0, _img, true);
		}
	}

	/// <summary>
	/// �����X�^�[�̏��(ID�A�C���[�W�A�ŏ��̈ʒu�A�ړI�n�̍��W)���󂯎��
	/// </summary>
	/// <param name="status">�����X�^�[��ID</param>
	/// <param name="image">NormalMonster��Boss�����X�^�[�̃C���[�W</param>
	/// <param name="get_pos_x">�����X�^�[��X�����W</param>
	/// <param name="get_pos_y">�����X�^�[��Y�����W</param>
	/// <param name="destnation_pos_x">�ړI�n��X�����W</param>
	/// <param name="destnation_pos_y">�ړI�n��Y�����W</param>
	void Monster::GetPosition(int status,int image, 
							  int get_pos_x, int get_pos_y, 
							  int destnation_pos_x, int destnation_pos_y)
	{
		_Monster_ID = status;
		switch (_Monster_ID)
		{
		case NORMAL_MONSTER_ID:
			Monster_HP = NORMAL_MONSTER_HP;
			_radius = NORMAL_MONSTER_RADIUS;
			break;

		case BOSS_MONSTER_ID:
			Monster_HP = BOSS_MONSTER_HP;
			_radius = BOSS_MONSTER_RADIUS;
			break;

		case LAST_BOSS_MONSTER_ID:
			Monster_HP = BOSS_MONSTER_HP;
			_radius = LAST_BOSS_MONSTER_RADIUS;
			break;
		}
		_img = image;
		if (_isActive == true)
		{
			_pos_x = get_pos_x;
			_pos_y = get_pos_y;

			get_monster_pos_x = get_pos_x;
			get_monster_pos_y = get_pos_y;

			dest_pos_x = destnation_pos_x;
			dest_pos_y = destnation_pos_y;

			float distance = (float)sqrt(pow(dest_pos_x - get_monster_pos_x, 2) + pow(dest_pos_y - get_monster_pos_y, 2));

			if (distance)
			{
				monster_speed_x = ((dest_pos_x - get_monster_pos_x) / distance * _speed);
				monster_speed_y = ((dest_pos_y - get_monster_pos_y) / distance * _speed);
			}
		}
	}
	
	/// /// <summary>
	/// �����X�^�[�Ōv�Z���K�v�ȏ���(�e��ł���)���܂Ƃ߂��֐�
	/// </summary>
	void Monster::CalkTask()
	{
		if (_isActive)
		{
			(_Monster_ID == NORMAL_MONSTER_ID) ? (NormalMonsterMove()) : (BossMonsterMove());
		}
	}

	/// <summary>
	/// ID��NormalMonster�̏ꍇ�Ɏ��s����ړ��֐�
	/// </summary>
	void Monster::NormalMonsterMove()
	{
		if (_isActive)
		{
			_pos_x += monster_speed_x;
			_pos_y += monster_speed_y;
			if (_pos_x == dest_pos_x || _pos_y == dest_pos_y)
			{
				_isActive = false;
			}
		}
	}

	/// <summary>
	/// ID��Boss�����X�^�[�̏ꍇ�Ɏ��s����ړ��֐�
	/// </summary>
	void Monster::BossMonsterMove()
	{
		if (_isActive)
		{
			_pos_y += monster_speed_y;
			if ((_pos_x > ZERO && _pos_x < WINDOW_SIZE_X &&
				_pos_y > ZERO && _pos_y < WINDOW_SIZE_Y))
			{
				_pos_y = dest_pos_y;
			}
		}
	}

	/// <summary>
	/// isActive��true�̎��ɒe�ۂ�ł�
	/// </summary>
	void Monster::ShootBullet()
	{
		if (_isActive)
		{
			BULLET_MANAGER().SetBullet(false, _Monster_ID, _pos_x, _pos_y);
		}
	}

	void Monster::Finalize()
	{
		_isActive = false;
	}
}