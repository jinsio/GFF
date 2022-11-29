#include "Scroll.h"

Scroll::Scroll()
	:scrRX(750)
	,scrRY(450)
	,scrPos()
{
}

Scroll::~Scroll()
{
}

void Scroll::MoveScroll(VECTOR& plyPos)
{
	if (plyPos.x > scrRX)
	{
		plyPos.x = scrRX;
		scrPos.x -= scrSpeed;
	}
	if (plyPos.y > scrRY)
	{
		plyPos.y = scrRY;
		scrPos.y -= scrSpeed;
	}
}