//--------------------------------------------------------------
//------------include Header
#include "BaseObject.h"


namespace base
{
	bool BaseObject::ConfirmImpact(BaseObject* otherobj)
	{
		_distance = sqrt(pow(_pos_x - otherobj->_pos_x,2) + pow(_pos_y - otherobj->_pos_y,2));

		return (_distance < (this->_radius + otherobj->_radius));
	}
}