#include "Scroll.h"

Scroll::Scroll()
	:scrRX(750)
	,scrRY(450)
{
}

Scroll::~Scroll()
{
}

void Scroll::MoveScroll(VECTOR& plyPos, VECTOR& mapPos)
{
	if (plyPos.x > scrRX)
	{
		plyPos.x = scrRX;
		mapPos.x -= scrSpeed;
	}
}