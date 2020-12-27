#include "InputKey.h"

namespace keyboard
{
	int key[256];

	/// <summary>
	/// 入力を受けたKeyが指定したKeyなのかを判定する関数
	/// </summary>
	void KeyUpdate()
	{
		char tmpkey[256];
		GetHitKeyStateAll(tmpkey);
		for (int index = 0; index < 256; index++)
		{
			if (tmpkey[index] != 0)
				key[index] ++;
			else
				key[index] = 0;
		}
	}

	/// <summary>
	/// Keyの入力を受ける関数
	/// </summary>
	/// <param name="keyvalue">受け取ったKeyの値</param>
	/// <returns></returns>
	int GetKey(int keyvalue)
	{
		return key[keyvalue];
	}

}