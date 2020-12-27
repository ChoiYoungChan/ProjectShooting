#include "InputKey.h"

namespace keyboard
{
	int key[256];
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
	int GetKey(int keyvalue)
	{
		return key[keyvalue];
	}

}