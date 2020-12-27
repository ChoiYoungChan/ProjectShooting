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

#define MOVE_COUNTER 12
#define STAGE_MAX 4
#define END_TIME 65
#define BOSS_TIME 11

namespace game
{
	class Stage : public scene::StageManager
	{
	public:
		Stage()
		{
			_begin_time = 0;
			_time_count = 0;
			monster_shoot = false;
			StageID = 1;
		}
		~Stage() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;

	private:
		playermanager::PlayerManager * playermanager = NULL;
		monstermanager::MonsterManager * enemyManager = NULL;
		bulletmanager::BulletManager * bulletManager = NULL;

		std::vector<base::BaseObject> listObjects;

		data::GameData gamedata;
		scene::StageManager stagemanager;

		void Draw();
		void CalkTask();
		void SpawnMonster();
		void ImpactCheck();
		void CheckFinalize();
		void CheckGameOver();
		void ResetFunc();

	private:

		typedef struct								//�����X�^�[�̈ړ����p�^�[�������邽�߂�Struct
		{
			bool isActive;
			bool type_boss;
			int monster_spawn_time;					//�����X�^�[��\������^�C�~���O
			int monster_pos_x;						//�����X�^�[�̂��Ƃ����̍��W
			int monster_pos_y;
			int destination_pos_x;
			int destination_pos_y;

		}MonsterMovement;

		MonsterMovement monster_table[STAGE_MAX][MOVE_COUNTER]
		{
			{
				{true, false,5, -400,-400, 500, 780},							//���ړ��p�^�[��
				{true, false,10,-300, 400, 880, 650},							//���ړ��p�^�[��
				{true, false,15, 800,-300, -50, 500},							//��O�ړ��p�^�[��
				{true, false,20,-400, 400, 800, 500},							//��l�ړ��p�^�[��
				{true, false,23, 750, 500,-300, 300},							//��܈ړ��p�^�[��
				{true, false,25, 400,-300, 300, 800},							//��Z�ړ��p�^�[��
				{true, false,30,-450,-300, 600, 600},							//�掵�ړ��p�^�[��
				{true, false,35, 800,-500,-200, 600},							//�攪�ړ��p�^�[��
				{true, false,40, 800, 500,-800, 500},							//���ړ��p�^�[��
				{true, false,45,-400, 750, 700,-200},							//��\�ړ��p�^�[��
				{true, false,50, 700, 880, 100,-100},							//��\��ړ��p�^�[��
				{true, false,55, 300, 750, 300,-500},							//��\��ړ��p�^�[��
			},
			{
				{true, false,3, 400,-300, 300, 800},							//���ړ��p�^�[��
				{true, false,8, 800,-500,-200, 600},							//���ړ��p�^�[��
				{true, false,12,-300, 400, 880, 650},							//��O�ړ��p�^�[��
				{true, false,15,-400, 400, 800, 500},							//��l�ړ��p�^�[��
				{true, false,20, 750, 500,-300, 300},							//��܈ړ��p�^�[��
				{true, false,23, 400,-300, 300, 800},							//��Z�ړ��p�^�[��
				{true, false,27,-450,-300, 600, 600},							//�掵�ړ��p�^�[��
				{true, false,30, 700, 880, 100,-100},							//�攪�ړ��p�^�[��
				{true, false,34, 800, 500,-800, 500},							//���ړ��p�^�[��
				{true, false,35, 300, 750, 300,-500},							//��\�ړ��p�^�[��
				{true, false,41, 700, 880, 100,-100},							//��\��ړ��p�^�[��
				{true, true, 45, 350, -50,  350, 80},							//��\��ړ��p�^�[��
			},
			{
				{true, false, 2, 300, 880, 300,-100},							//���ړ��p�^�[��
				{true, false, 7, 400,-300, 300, 800},							//���ړ��p�^�[��
				{true, false,11, 800,-300, -50, 500},							//��O�ړ��p�^�[��
				{true, false,15,-400, 400, 800, 500},							//��l�ړ��p�^�[��
				{true, false,19, 300, 750, 300, 300},							//��܈ړ��p�^�[��
				{true, false,22, 400,-300, 300, 800},							//��Z�ړ��p�^�[��
				{true, false,26, 400,-300, 300, 800},							//�掵�ړ��p�^�[��
				{true, false,31, 800,-500,-200, 600},							//�攪�ړ��p�^�[��
				{true, false,35, 300, 750, 300,-500},							//���ړ��p�^�[��
				{true, false,39,-400, 750, 700,-200},							//��\�ړ��p�^�[��
				{true, false,40, 700, 880, 100,-100},							//��\��ړ��p�^�[��
				{true, true, 45, 350, -50,  350, 80},							//��\��ړ��p�^�[��
			},
			{
				{true, true, 2, 350, -50,  350, 80}
			}
		};

		int _begin_time;							//Stage���n�߂����u�Ԃ̎���
		int _time_count;							//���݂̎��Ԃ����ă����X�^�[���\�������^�C�~���O����肷�邽�߂̕ϐ�

		int StageID;
		bool monster_shoot, first_init = true;
		
	};
	
}