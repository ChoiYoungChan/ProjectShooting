//--------------------------------------------------------------
//------------include Header
#include "InputKey.h"

namespace keyboard
{
	int key[256];

	/// <summary>
	/// “ü—Í‚ğó‚¯‚½Key‚ªw’è‚µ‚½Key‚È‚Ì‚©‚ğ”»’è‚·‚éŠÖ”
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
	/// Key‚Ì“ü—Í‚ğó‚¯‚éŠÖ”
	/// </summary>
	/// <param name="keyvalue">ó‚¯æ‚Á‚½Key‚Ì’l</param>
	/// <returns></returns>
	int GetKey(int keyvalue)
	{
		return key[keyvalue];
	}

	/// <summary>
/// Key‚Ì“ü—Í‚ğó‚¯‚éŠÖ”
/// </summary>
/// <param name="keyvalue">ó‚¯æ‚Á‚½Key‚Ì’l</param>
/// <returns></returns>
	bool GetKeyTrigger(int keyvalue)
	{
		return (key[keyvalue]==1)?(true):(false);
	}

}