//--------------------------------------------------------------
//------------include Lib
#include "DxLib.h"
#include <math.h>
#include <vector>

//--------------------------------------------------------------
//------------include Header
#include "..\Source\Player.h"

#include "..\Scene\StageManager.h"
#include "..\Scene\Result.h"
#include "..\..\Manager\MonsterManager.h"
#include "..\..\Manager\BulletManager.h"

#define MOVE_COUNTER 12
#define STAGE_MAX 3
#define END_TIME 63

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
			StageID = 0;
		}
		~Stage() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;

	private:
		play_user::Player * player = NULL;
		monstermanager::MonsterManager * enemyManager = NULL;
		bulletmanager::BulletManager * bulletManager = NULL;

		int player_invi_count = 0;

		std::vector<base::BaseObject> listObjects;

		data::GameData gamedata;
		scene::StageManager stagemanager;

		void Draw();
		void CalkTask();
		void SpawnMonster();
		void ImpactCheck();
		void CheckFinalize();

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

		MonsterMovement monster_table[STAGE_MAX][MOVE_COUNTER]
		{
			{
				{true,5, -400,-400, 500, 780},							//���ړ��p�^�[��
				{true,10,-300, 400, 880, 650},							//���ړ��p�^�[��
				{true,15, 800,-300, -50, 500},							//��O�ړ��p�^�[��
				{true,20,-400, 400, 800, 500},							//��l�ړ��p�^�[��
				{true,23, 750, 500,-300, 300},							//��܈ړ��p�^�[��
				{true,25, 400,-300, 300, 800},							//��Z�ړ��p�^�[��
				{true,30,-450,-300, 600, 600},							//�掵�ړ��p�^�[��
				{true,35, 800,-500,-200, 600},							//�攪�ړ��p�^�[��
				{true,40, 800, 500,-800, 500},							//���ړ��p�^�[��
				{true,45,-400, 750, 700,-200},							//��\�ړ��p�^�[��
				{true,50, 700, 880, 100,-100},							//��\��ړ��p�^�[��
				{true,55, 300, 750, 300,-500},							//��\��ړ��p�^�[��
			},
			{
				{true, 3, 400,-300, 300, 800},							//���ړ��p�^�[��
				{true, 8, 800,-500,-200, 600},							//���ړ��p�^�[��
				{true,12,-300, 400, 880, 650},							//��O�ړ��p�^�[��
				{true,15,-400, 400, 800, 500},							//��l�ړ��p�^�[��
				{true,20, 750, 500,-300, 300},							//��܈ړ��p�^�[��
				{true,23, 400,-300, 300, 800},							//��Z�ړ��p�^�[��
				{true,27,-450,-300, 600, 600},							//�掵�ړ��p�^�[��
				{true,30, 700, 880, 100,-100},							//�攪�ړ��p�^�[��
				{true,34, 800, 500,-800, 500},							//���ړ��p�^�[��
				{true,35, 300, 750, 300,-500},							//��\�ړ��p�^�[��
				{true,41, 700, 880, 100,-100},							//��\��ړ��p�^�[��
				{true,45, 300, 750, 300, 300},							//��\��ړ��p�^�[��
			},
			{
				{true, 2, 300, 880, 300,-100},							//���ړ��p�^�[��
				{true, 7, 400,-300, 300, 800},							//���ړ��p�^�[��
				{true,11, 800,-300, -50, 500},							//��O�ړ��p�^�[��
				{true,15,-400, 400, 800, 500},							//��l�ړ��p�^�[��
				{true,19, 300, 750, 300, 300},							//��܈ړ��p�^�[��
				{true,22, 400,-300, 300, 800},							//��Z�ړ��p�^�[��
				{true,26, 400,-300, 300, 800},							//�掵�ړ��p�^�[��
				{true,31, 800,-500,-200, 600},							//�攪�ړ��p�^�[��
				{true,35, 300, 750, 300,-500},							//���ړ��p�^�[��
				{true,39,-400, 750, 700,-200},							//��\�ړ��p�^�[��
				{true,40, 700, 880, 100,-100},							//��\��ړ��p�^�[��
				{true,44, 300, 750, 300, 300},							//��\��ړ��p�^�[��
			}
		};

		int _begin_time;							//Stage���n�߂����u�Ԃ̎���
		int _time_count;							//���݂̎��Ԃ����ă����X�^�[���\�������^�C�~���O����肷�邽�߂̕ϐ�
		
		const int MONSTER_COUNT = 5;							//���ɕ\������郂���X�^�[�̐�
		int StageID;
		bool monster_shoot;
		
	};
	
}