#include "Math.h"

//-------------------------------------------------------------------------------
// @brief ƒxƒNƒgƒ‹“¯Žm‚Ì‰ÁŽZ
//-------------------------------------------------------------------------------
VECTOR operator+(const VECTOR& lhs, const VECTOR& rhs)
{
	VECTOR ret;
	ret.x = lhs.x + rhs.x;
	ret.y = lhs.y + rhs.y;
	ret.z = lhs.z + rhs.z;
	return ret;
}

//-------------------------------------------------------------------------------
// @brief += VECTOR‚Ì‰‰ŽZŽq
//-------------------------------------------------------------------------------
VECTOR operator+=(VECTOR& lhs, const VECTOR& rhs)
{
	lhs = lhs + rhs;
	return lhs;
}