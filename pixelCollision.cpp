#include "stdafx.h"
#include "pixelCollision.h"


pixelCollision::pixelCollision()
	: _isGround(FALSE)		//땅위에 있는지?
	, _isWall(FALSE)		//벽에 부딪혔는지?
	, _isTrap(FALSE)		//트랩에 걸렸는지?
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

bool pixelCollision::getPixelGroundLT(float* lx, float* ty, int width, int height)
{
	int pixelGap = 2;

	_x = lx;
	_y = ty;

	_probeX = *_x + width / 2;
	_probeY = *_y + height;

	for (int i = _probeY - pixelGap; i < _probeY + pixelGap; ++i)
	{
		//
		int j = _probeX;
		{
			COLORREF color = PBGMANAGER->getPixelColor(strPBG, j, i);

			if (color == RGB(0, 0, 0) || color == RGB(0, 255, 255))
			{
				*_y = i - height - 1;

				return true;
			}
		}
	}

	return false;
}

bool pixelCollision::getPixelGroundCC(float* cx, float* cy, int width, int height)
{
	int pixelGap = 5;

	_x = cx;
	_y = cy;

	_probeX = *_x;
	_probeY = *_y + height / 2;

	for (int i = _probeY - pixelGap; i < _probeY + pixelGap; ++i)
	{
		//
		int j = _probeX;
		{
			COLORREF color = PBGMANAGER->getPixelColor(strPBG, j, i);

			if (color == RGB(0, 0, 0) || color == RGB(0, 255, 255))
			{
				*_y = i - height / 2 - 1;

				return true;
			}
		}
	}

	return false;
}


bool pixelCollision::getPixelWall(float* x, float* y, int width, int height, int dir)
{
	int pixelGap = 5;

	_x = x;
	_y = y;

	if (dir < 0)
	{
//		_probeX = *_x - width / 2;
		_probeX = *_x;
		_probeY = *_y;

		//for (int i = _probeY - pixelGap; i < _probeY + pixelGap; ++i)
		int i = _probeY;
		{
			for (int j = _probeX + pixelGap; j > _probeX - pixelGap; --j)
			{
				COLORREF color = PBGMANAGER->getPixelColor(strPBG, j, i);

				if (color == RGB(0, 255, 255) || color == RGB(0, 0, 0))
				{
					*_x = j;// +width / 2;

					return true;
				}
			}
		}
	}
	else if (dir > 0)
	{
//		_probeX = *_x + width / 2;
		_probeX = *_x + width;
		_probeY = *_y;

		//for (int i = _probeY - pixelGap; i < _probeY + pixelGap; ++i)
		int i = _probeY;
		{
			for (int j = _probeX - pixelGap; j < _probeX + pixelGap; ++j)
			{
				COLORREF color = PBGMANAGER->getPixelColor(strPBG, j, i);

				if (color == RGB(0, 255, 255) || color == RGB(0, 0, 0))
				{
					*_x = j - width;// -width / 2;

					return true;
				}
			}
		}
	}

	return false;

}

tagPixelCollision pixelCollision::getPlayerPixelGround(int cx, int cy, int width, int height)
{
	int pixelGapP = 2;
	int pixelGapM = 10;

	tagPixelCollision res;
	res.detect = false;
	res.trap = false;
	res.offset = { 0, 0 };

	int probeX = cx;
	int probeY = cy + height / 2;

	for (int i = probeY - pixelGapP; i < probeY + pixelGapM; ++i)
	{
		//int j = probeX;
		for (int j = 0; abs(j) < width / 2;)
		{
			//COLORREF color = PBGMANAGER->getPixelColor(strPBG, j, i);
			COLORREF color = PBGMANAGER->getPixelColor(strPBG, j + probeX, i);
			if (color == RGB(255, 0, 0))  //가시검사
			{
				res.trap = true;
			}
			if (color == RGB(0, 0, 0))// || color == RGB(0, 255, 255))
			{
				res.detect = true;
				res.offset.x = cx;
				res.offset.y = i - height / 2 - 1;

				return res;
			}
			
			//중앙을 기준으로 검색하도록 함
			if (j == 0)			j = 1;
			else if (j > 0)		j = -j;
			else if (j < 0)		j = -j + 1;
		}
	}
	return res;
}

tagPixelCollision pixelCollision::getPlayerPixelWall(int cx, int cy, int width, int height, int dir)	//dir = 1 -> 오른쪽, -1 일때 왼쪽
{
	int pixelGapP = 2;
	int pixelGapM = 10;

	tagPixelCollision res;
	res.detect = false;
	res.offset = { 0, 0 };

	if (dir < 0)
	{
		int probeX = cx - width / 2;
		int probeY = cy;

		//int i = probeY;
		for(int i = probeY; i > probeY - pixelGapM; --i)
		{
			for (int j = probeX + pixelGapP; j > probeX - pixelGapM; --j)
			{
				COLORREF color = PBGMANAGER->getPixelColor(strPBG, j, i);

				if (color == RGB(0, 255, 255))// || color == RGB(0, 0, 0))
				{
					res.detect = true;
					res.offset.x = j + width / 2;
					res.offset.y = cy;

					return res;
				}
			}
		}
	}
	else if (dir > 0)
	{
		int probeX = cx + width / 2;
		int probeY = cy + height / 2;

		//int i = probeY;
		for (int i = probeY; i > probeY - pixelGapM; --i)
		{
			for (int j = probeX - pixelGapP; j < probeX + pixelGapM; ++j)
			{
				COLORREF color = PBGMANAGER->getPixelColor(strPBG, j, i);

				if (color == RGB(0, 255, 255))
				{
					res.detect = true;
					res.offset.x = j - width / 2;
					res.offset.y = cy;

					return res;
				}
			}
		}
	}
	return res;
}


tagPixelCollision pixelCollision::getPlayerPixelCeiling(int cx, int cy, int width, int height)
{
	int pixelGapP = 2;
	int pixelGapM = 10;

	tagPixelCollision res;
	res.detect = false;
	res.offset = { 0, 0 };

	int probeX = cx;
	int probeY = cy - height / 2;

	for (int i = probeY + pixelGapP; i > probeY - pixelGapM; --i)
	{
		//int j = probeX;
		for (int j = 0; abs(j) < width / 2;)
		{
			//COLORREF color = PBGMANAGER->getPixelColor(strPBG, j, i);
			COLORREF color = PBGMANAGER->getPixelColor(strPBG, j + probeX, i);

			if (/*color == RGB(0, 0, 0) || */color == RGB(0, 255, 255))
			{
				res.detect = true;
				res.offset.x = cx;
				res.offset.y = i + height / 2;

				return res;
			}

			//중앙을 기준으로 검색하도록 함
			if (j == 0)			j = 1;
			else if (j > 0)		j = -j;
			else if (j < 0)		j = -j + 1;
		}
	}
	return res;
}

