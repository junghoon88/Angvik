#include "stdafx.h"
#include "pixelCollision.h"


pixelCollision::pixelCollision()
	: _isGround(FALSE)		//¶¥À§¿¡ ÀÖ´ÂÁö?
	, _isWall(FALSE)		//º®¿¡ ºÎµúÇû´ÂÁö?
	, _isTrap(FALSE)		//Æ®·¦¿¡ °É·È´ÂÁö?
{
	int stage = STAGE;
	_stprintf(strPBG, L"Stage%d-PBG", stage);
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

bool pixelCollision::getPixelGround(float* x, float* y, int width, int height)
{
	int pixelGap = 10;

	_x = x;
	_y = y;

	_probeX = *_x;
	_probeY = *_y + height / 2;

	for (int i = _probeY - pixelGap; i < _probeY + pixelGap; ++i)
	{
		//for (int j = _probeX - width / 2; j < _probeY + width / 2; ++j)
		int j = *_x;
		{
			COLORREF color = PBGMANAGER->getPixelColor(strPBG, j, i);

			if (color == RGB(0, 0, 0) || color == RGB(0, 255, 255))
			{
				*_y = i - height / 2;

				return true;
			}
		}
	}

	return false;
}