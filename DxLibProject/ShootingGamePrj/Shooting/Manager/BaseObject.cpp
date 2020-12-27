#include "BaseObject.h"


namespace base
{
	bool BaseObject::ConfirmImpact(BaseObject* otherobj)
	{
		distance = sqrt(pow(pos_x - otherobj->pos_x,2) + pow(pos_y - otherobj->pos_y,2));

		return (distance < (this->_radius + otherobj->_radius));
	}
}