//--------------------------------------------------------------
//------------include Lib
#include "DxLib.h"
#include <math.h>
#include <vector>

//--------------------------------------------------------------
//------------include Header

#include "..\Scene\StageManager.h"
#include "..\Scene\Result.h"
#include "..\..\Manager\MonsterManager.h"
#include "..\..\Manager\BulletManager.h"
#include "..\..\Manager\PlayerManager.h"

namespace game
{
	class Stage : public scene::StageManager
	{
	public:
		Stage()
		{
			_begin_time = ZERO;
			_time_count = ZERO;
			_NextState = false;
		}
		~Stage() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;
		void InitVar();

	public:
		bool _NextState;

	private:
		playermanager::PlayerManager * playermanager = NULL;
		monstermanager::MonsterManager * enemyManager = NULL;
		bulletmanager::BulletManager * bulletManager = NULL;

		std::vector<base::BaseObject> listObjects;
		data::GameData gamedata;

		void Draw();
		void CalkTask();
		void SpawnMonster();
		void ImpactCheck();
		void CheckFinalize();
		void CheckGameOver();
		void ReadyNextStage();
		void Pause();

	private:

		int _begin_time;							//Stage���n�߂����u�Ԃ̎���
		int _time_count;							//���݂̎��Ԃ����ă����X�^�[���\�������^�C�~���O����肷�邽�߂̕ϐ�
		int _nowSecond, boss_type;

		bool _isPause=false;

		typedef struct								//�����X�^�[�̈ړ����p�^�[�������邽�߂�Struct
		{
			bool isActive;
			bool type_boss;
			int monster_count;
			int monster_spawn_time;					//�����X�^�[��\������^�C�~���O
			int shoot_bullet_time;
			int monster_pos_x;						//�����X�^�[�̂��Ƃ����̍��W
			int monster_pos_y;
			int destination_pos_x;
			int destination_pos_y;

		}MonsterMovement;

		MonsterMovement _monster_table[StageState::Stage_Max][MOVE_COUNTER]
		{
			{ 
				{true, false,10, 5, 6,-400,-400, 500, 780},							//���ړ��p�^�[��
				{true, false,6 ,10,11,-300, 400, 880, 650},							//���ړ��p�^�[��
				{true, false,4 ,15,16, 800,-300, -50, 500},							//��O�ړ��p�^�[��
				{true, false,16,20,21,-400, 400, 800,-100},							//��l�ړ��p�^�[��
				{true, false,5 ,23,24, 750, 500,-300, 300},							//��܈ړ��p�^�[��
				{true, false,3 ,25,26, 400,-300, 300, 800},							//��Z�ړ��p�^�[��
				{true, false,8 ,30,31,-450,-300, 600, 600},							//�掵�ړ��p�^�[��
				{true, false,9 ,35,36, 800,-500,-200, 600},							//�攪�ړ��p�^�[��
				{true, false,5 ,40,41, 800, 500,-800, 500},							//���ړ��p�^�[��
				{true, false,4 ,45,46,-400, 750, 700,-200},							//��\�ړ��p�^�[��
				{true, false,12,50,51, 700, 880, 100,-100},							//��\��ړ��p�^�[��
				{true, false,1 ,55,56, 300, 750, 300,-500},							//��\��ړ��p�^�[��
			},
			{
				{true, false,7 , 3, 4, 400,-300, 300, 800},							//���ړ��p�^�[��
				{true, false,6 , 8, 9, 800,-500,-200, 600},							//���ړ��p�^�[��
				{true, false,4 ,12,13,-300, 400, 880, 650},							//��O�ړ��p�^�[��
				{true, false,16,15,16,-400, 400, 800, 500},							//��l�ړ��p�^�[��
				{true, false,5 ,20,21, 750, 500,-300, 300},							//��܈ړ��p�^�[��
				{true, false,3 ,23,24, 400,-300, 300, 800},							//��Z�ړ��p�^�[��
				{true, false,8 ,27,28,-450,-300, 600, 600},							//�掵�ړ��p�^�[��
				{true, false,9 ,30,31, 700, 880, 100,-100},							//�攪�ړ��p�^�[��
				{true, false,5 ,34,35, 800, 500,-800, 500},							//���ړ��p�^�[��
				{true, false,4 ,35,36, 300, 750, 300,-500},							//��\�ړ��p�^�[��
				{true, false,12,41,42, 700, 880, 100,-100},							//��\��ړ��p�^�[��
				{true, true, 1, 45,46, 350, -50,  350, 80},							//��\��ړ��p�^�[��
			},
			{
				{true, false,13, 2, 3, 300, 880, 300,-100},							//���ړ��p�^�[��
				{true, false,5 , 7, 8, 400,-300, 300, 800},							//���ړ��p�^�[��
				{true, false,9 ,11,12, 800,-300, -50, 500},							//��O�ړ��p�^�[��
				{true, false,10,15,16,-400, 400, 800, 500},							//��l�ړ��p�^�[��
				{true, false,8 ,19,20, 300, 750, 300, 300},							//��܈ړ��p�^�[��
				{true, false,4 ,22,23, 400,-300, 300, 800},							//��Z�ړ��p�^�[��
				{true, false,5 ,26,27, 400,-300, 300, 800},							//�掵�ړ��p�^�[��
				{true, false,6 ,31,32, 800,-500,-200, 600},							//�攪�ړ��p�^�[��
				{true, false,8 ,35,36, 300, 750, 300,-500},							//���ړ��p�^�[��
				{true, false,9 ,39,40,-400, 750, 700,-200},							//��\�ړ��p�^�[��
				{true, false,10,42,43, 700, 880, 100,-100},							//��\��ړ��p�^�[��
				{true, true, 1,	45,46, 350, -50,  350, 80},							//��\��ړ��p�^�[��
			}
		};
	
	};
}