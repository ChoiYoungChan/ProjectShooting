//--------------------------------------------------------------
//------------include Header
#include "InputKey.h"

namespace keyboard
{
	int key[256];

	/// <summary>
	/// ���͂��󂯂�Key���w�肵��Key�Ȃ̂��𔻒肷��֐�
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
	/// Key�̓��͂��󂯂�֐�
	/// </summary>
	/// <param name="keyvalue">�󂯎����Key�̒l</param>
	/// <returns></returns>
	int GetKey(int keyvalue)
	{
		return key[keyvalue];
	}

	/// <summary>
/// Key�̓��͂��󂯂�֐�
/// </summary>
/// <param name="keyvalue">�󂯎����Key�̒l</param>
/// <returns></returns>
	bool GetKeyTrigger(int keyvalue)
	{
		return (key[keyvalue]==1)?(true):(false);
	}

}