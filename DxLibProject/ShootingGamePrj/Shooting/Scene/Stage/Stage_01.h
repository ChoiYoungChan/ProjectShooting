//--------------------------------------------------------------
//------------include Lib
#include "DxLib.h"
#include <math.h>

//--------------------------------------------------------------
//------------include Header
#include "..\..\Source\Player.h"
#include "..\..\Source\Monster.h"
#include "..\StageManager.h"
#include "..\Result.h"

namespace game
{
	class Stage01 : public scene::StageManager
	{
	public:
		Stage01()
		{
			_begin_time = 0;
			_time_count = 0;

			StageID = 1;
		}
		~Stage01() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;

	private:
		play_user::Player player;
		monster::Monster enemy[5];
		data::GameData gamedata;
		scene::StageManager stagemanager;

		void Draw();
		void CalkTask();
		bool ImpactCalk(int);
		void SpawnMonster();

	private:

		typedef struct								//�����X�^�[�̈ړ����p�^�[�������邽�߂�Struct
		{
			bool isActive;
			int monster_spawn_time;					//�����X�^�[��\������^�C�~���O
			int monster_pos_x;						//�����X�^�[�̂��Ƃ����̍��W
			int monster_pos_y;
			int destination_pos_x;
			int destination_pos_y;

		}MonsterMovement;

		MonsterMovement monster_move[11]
		{
			{true,5, -200,-200, 500, 780},							//���ړ��p�^�[��
			{true,10,-200,-200, 780, 700},							//���ړ��p�^�[��
			{true,15, 800,-200, -50, 500},							//��O�ړ��p�^�[��
			{true,20,-300,-300, 780, 600},							//��l�ړ��p�^�[��
			{true,25, 800,-200, -10, 600},							//��܈ړ��p�^�[��
			{true,30,-150,-200, 600, 600},							//��Z�ړ��p�^�[��
			{true,35,-200,-500, 200, 600},							//�掵�ړ��p�^�[��
			{true,40,-300,-200, 300, 600},							//�攪�ړ��p�^�[��
			{true,45,-200, 750, 300,-800},							//���ړ��p�^�[��
			{true,50, 700, 880, 300,-100},							//��\�ړ��p�^�[��
			{true,55, 600, 750,-100,-800},							//��\��ړ��p�^�[��

		};


		int _begin_time;							//Stage���n�߂����u�Ԃ̎���
		int _time_count;							//���݂̎��Ԃ����ă����X�^�[���\�������^�C�~���O����肷�邽�߂̕ϐ�
		
		int distance_01;							//�����X�^�[�ƃv���C���[�̊Ԃ̋���->�Փ˔���Ɏg�p
		int distance_02;							//�����X�^�[�ƃv���C���[�e�̊Ԃ̋���->�Փ˔���Ɏg�p
		int distance_03;							//�����X�^�[�e�ƃv���C���[�̊Ԃ̋���->�Փ˔���Ɏg�p

		const int move_counter = 11;
		const int MONSTER_COUNT = 5;							//���ɕ\������郂���X�^�[�̐�
		int StageID;

		scene::Result result;
	};
	
}