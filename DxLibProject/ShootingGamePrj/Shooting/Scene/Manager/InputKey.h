#pragma once
#include "DxLib.h"

namespace keyboard
{
	void KeyUpdate();				//入力を受けたKeyが指定したKeyなのかを判定する関数
	int GetKey(int keyvalue);		//Keyの入力を受ける関数
}