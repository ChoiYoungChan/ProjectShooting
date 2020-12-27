#pragma once
//--------------------------------------------------------------
//------------include Header
#include "BaseSceneController.h"
#include "..\..\Manager\GameData.h"
#include "..\..\Manager\InputKey.h"
#include "..\..\Manager\Singleton.h"


namespace scene
{
	class Result : public BaseScene, singleton::Singleton<Result>
	{
	public:
		Result() :BaseScene(State::Result) {}
		~Result() = default;

	public:
		void Initialize() override;
		void Update() override;
		void Finalize() override;

		void CalkTask();
		void DrawTask();

	private:
		int _G_SelectNumber;
		int _begin_time, _inLoop_time;
		int _COLOR;
		const int _RESULT_MENU = 2;
		const int _MENU_SELECT = GetColor(255, 0, 0), _MENU_UNSELECT = GetColor(255, 255, 255);

	private:
		typedef struct
		{
			int menu_pos_x, menu_pos_y;
			char name[256];

		}MenuElement_t;

		MenuElement_t MenuElement[2] =								//ÉÅÉjÉÖÇÃì‡óe
		{
			{ 200, 500, "Go to Title"},
			{ 400, 500, "Exit Game"}
		};

	private:
		friend class singleton::Singleton<Result>;
	};

}