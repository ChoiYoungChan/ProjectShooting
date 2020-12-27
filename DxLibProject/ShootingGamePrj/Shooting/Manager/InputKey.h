#pragma once
//--------------------------------------------------------------
//------------include Header
#include "DxLib.h"

namespace keyboard
{
	void KeyUpdate();
	int GetKey(int keyvalue);

	bool GetKeyTrigger(int keyvalue);

}