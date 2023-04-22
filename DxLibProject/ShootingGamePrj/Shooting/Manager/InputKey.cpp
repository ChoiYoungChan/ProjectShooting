//--------------------------------------------------------------
//------------include Header
#include "InputKey.h"

namespace keyboard
{
	int key[256];

	/// <summary>
	/// ìıÕôªòáôª±ª¿Keyª¬ò¦ïÒª·ª¿KeyªÊªÎª«ªò÷÷ïÒª¹ªë??
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
	/// KeyìıÕôªòáôª±ªë??
	/// </summary>
	/// <param name="keyvalue">>áôª±ö¢ªÃª¿KeyªÎö·</param>
	/// <returns></returns>
	int GetKey(int keyvalue)
	{
		return key[keyvalue];
	}

	/// <summary>
/// KeyªÎìıÕôªòáôª±ªë??
/// </summary>
/// <param name="keyvalue">áôª±ö¢ªÃª¿KeyªÎö·</param>
/// <returns></returns>
	bool GetKeyTrigger(int keyvalue)
	{
		return (key[keyvalue]==1)?(true):(false);
	}

}