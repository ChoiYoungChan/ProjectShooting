//--------------------------------------------------------------
//------------include Lib
#include "DxLib.h"
#include <math.h>

//--------------------------------------------------------------
//------------include Header
#include "..\..\Source\Player.h"
#include "..\..\Source\Monster.h"
#include "..\StageManager.h"


namespace game
{
	class Stage01 : public scene::StageManager
	{
	public:
		Stage01()
		{
			_time_count = 0;
		}
		~Stage01() = default;

	public:

		void Initialize() override;
		void Update() override;
		void Finalize() override;

	private:
		play_user::Player player;
		play_user::PlayerBullet player_bullet;
		monster::Monster enemy;
		monster::Bullet monster_bullet;

		scene::StageManager stagemanager;

		void Draw();
		void CalkTask();
		void ImpactCalk();

	private:
		typedef struct								//�����X�^�[�̈ړ����p�^�[�������邽�߂�Struct
		{
			int monster_spawn_time;					//�����X�^�[��\������^�C�~���O
			int monster_pos_x;						//�����X�^�[�̂��Ƃ����̍��W
			int monster_pos_y;

		}MonsterMovement;

		MonsterMovement monster_move[5]
		{
			{5,   10, -10},							//���ړ��p�^�[��
			{10, -50,  10},							//���ړ��p�^�[��
			{15, 800,  20},							//��O�ړ��p�^�[��
			{20, -10, -10},							//��l�ړ��p�^�[��
			{25, 800, -10},							//��܈ړ��p�^�[��
		};

		int _time_count;							//���݂̎��Ԃ����ă����X�^�[���\�������^�C�~���O����肷�邽�߂̕ϐ�
		int distance_01;							//�����X�^�[�ƃv���C���[�̊Ԃ̋���->�Փ˔���Ɏg�p
		int distance_02;							//�����X�^�[�ƃv���C���[�e�̊Ԃ̋���->�Փ˔���Ɏg�p
		int distance_03;							//�����X�^�[�e�ƃv���C���[�̊Ԃ̋���->�Փ˔���Ɏg�p

	};
}