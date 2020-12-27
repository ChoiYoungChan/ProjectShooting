#pragma once
//===========================================
//=========System
#define ZERO 0

//===========================================
//=========モンスター
#define ENEMY_MAX 20
#define BULLET_MAX 1000
#define NORMAL_MONSTER_ID 0
#define BOSS_MONSTER_ID 1
#define LAST_BOSS_MONSTER_ID 2
#define NORMAL_MONSTER_HP 1
#define BOSS_MONSTER_HP 5000
#define NORMAL_MONSTER_RADIUS 30
#define BOSS_MONSTER_RADIUS 90
#define LAST_BOSS_MONSTER_RADIUS 50


//===========================================
//=========Main
const int WINDOW_SIZE_X = 720;
const int WINDOW_SIZE_Y = 720;

//===========================================
//=========Stage
#define MOVE_COUNTER 12
#define STAGE_MAX 4
#define END_TIME 60
#define TIME_RESET _begin_time = ZERO, _time_count = ZERO,_nowSecond = ZERO

#define MONSTER_MANAGER() monstermanager::MonsterManager::Instance()
#define PLAYER_MANAGER() playermanager::PlayerManager::Instance()
#define BULLET_MANAGER() bulletmanager::BulletManager::Instance()
#define GAME_DATA() data::GameData::Instance()

//===========================================
//=========弾幕
#define PATTERN_COUNT 2
#define BOSS_COUNT 5
#define PI 3.14159265

//===========================================
//=========弾丸
#define PLAYER_BULLET_SIZE 0.05
#define MONSTER_BULLET_SIZE 0.3
#define PLAYER_BULLET_RADIUS 15
#define MONSTER_BULLET_RADIUS 10

//===========================================
//=========画面
#define BACK_TO_TITLE 15

//===========================================
//=========プレイヤー
#define PLAYER_RADIUS 20