#include "stdafx.h"
#include "pixelCollision.h"


pixelCollision::pixelCollision()
	: _imgPBG(NULL)
	, _isGround(FALSE)		//¶¥À§¿¡ ÀÖ´ÂÁö?
	, _isWall(FALSE)		//º®¿¡ ºÎµúÇû´ÂÁö?
	, _isTrap(FALSE)		//Æ®·¦¿¡ °É·È´ÂÁö?
{
	int stage = STAGE;
	TCHAR str[128];
	_stprintf(str, L"Stage%d-PBG", stage);
	_imgPBG = PBGMANAGER->findImage(str);
}


pixelCollision::~pixelCollision()
{
}

void pixelCollision::init(void)
{

}
void pixelCollision::release(void)
{

}
void pixelCollision::update(void)
{

}
void pixelCollision::render(void)
{

}

