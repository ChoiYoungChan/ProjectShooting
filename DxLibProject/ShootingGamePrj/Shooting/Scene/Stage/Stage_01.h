//--------------------------------------------------------------
//------------include DX
#include "DxLib.h"
//--------------------------------------------------------------
//------------include Header
#include "..\..\Source\Player.h"
#include "..\..\Source\Monster.h"
#include "..\StageManager.h"
#include <math.h>


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
		play_user::Player user;
		monster::Monster monster_enemy;

		void Draw();
		void CalkTask();
		void ImpackCalk();

	private:
		int _time_count;
		int distance;

		typedef struct								//�����X�^�[�̈ړ����p�^�[�������邽�߂�Struct
		{
			int monster_spawn_time;					//�����X�^�[��\������^�C�~���O
			int monster_pos_x;						//�����X�^�[�̂��Ƃ����̍��W
			int monster_pos_y;

		}MonsterMovement;

		MonsterMovement monster_move[5]
		{
			{5,   10, -10},							//���p�^�[��
			{10, -50,  10},							//���p�^�[��
			{15, 800,  20},							//��O�p�^�[��
			{20, -10, -10},							//��l�p�^�[��
			{25, 800, -10},							//��܃p�^�[��
		};

		typedef struct								//�����X�^�[���łe�̒e���̐ݒ�����邽�߂�Struct
		{
			int monster_bullet_x;
			int monster_bullet_y;
		}MonsterBullet;

		MonsterBullet monster_bullet[2]
		{
			{},{}
		};

	};
}