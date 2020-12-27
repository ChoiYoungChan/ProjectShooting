#include "Title.h"

namespace scene
{
	void Title::Initialize()
	{
		SetBackgroundColor(0, 200, 0);
		G_SelectNumber = 0;
	}
	/// <summary>
	/// ���͂��󂯂ă��j���̈ړ��ƑI������֐�
	/// </summary>
	void Title::Update()
	{
		if (keyboard::GetKey(KEY_INPUT_DOWN) == 1)
		{
			G_SelectNumber = (G_SelectNumber + 1) % MENU;
		}
		if (keyboard::GetKey(KEY_INPUT_UP) == 1)
		{
			G_SelectNumber = (G_SelectNumber + 2) % MENU;
		}

		for (int _menu_number = 0; _menu_number < MENU; _menu_number++)
		{
			if (_menu_number == G_SelectNumber)
			{
				MenuElement[_menu_number].menu_pos_x = MENU_SELECT_POS_X;
			}
			else
				MenuElement[_menu_number].menu_pos_x = MENU_UNSELECT_POS_X;		//�I������Ă��Ȃ����j���̈ʒu���w�肷��

			DrawFormatString(MenuElement[_menu_number].menu_pos_x, MenuElement[_menu_number].menu_pos_y,
				GetColor(255, 255, 255), MenuElement[_menu_number].name);
		}

		if (keyboard::GetKey(KEY_INPUT_SPACE) == 1)						//�I�����ꂽ���j����Space�������ƊY����Scene���Ăяo�����
		{
			switch (G_SelectNumber)
			{
			case 0:
				SetNextState(State::InGame);
				break;
			case 1:
				SetNextState(State::Options);
				break;
			case 2:
				SetNextState(State::Exit);
				break;
			default:
				assert(false);
				break;
			}
		}

	}

	void Title::Finalize()
	{
		SetBackgroundColor(0, 0, 0);
	}	
}