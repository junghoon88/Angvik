#include "stdafx.h"
#include "inven.h"


inven::inven()
{
}


inven::~inven()
{
}

void inven::init(void)
{
	_isMenew = true;
	_isItem = false;
	_isOils = false;

	_timeCount = 0;
	_frameX = 0;
}

void inven::release(void)
{

}

void inven::update(void)
{

}

void inven::update(float x, float y)
{
	_timeCount += TIMEMANAGER->getElapsedTime();
	if (_timeCount > 0.07)
	{
		_timeCount = 0;
		_frameX++;
		if (_frameX >= 8) _frameX = 0;
	}

	IMAGEMANAGER->findImage(L"inventory")->setCoord({ x + 40, y - IMAGEMANAGER->findImage(L"inventory")->getRealSize().y - 20 });
	IMAGEMANAGER->findImage(L"itemBox")->setCoord({ x + 40,  y - IMAGEMANAGER->findImage(L"itemBox")->getRealSize().y - 20 });
	IMAGEMANAGER->findImage(L"oilsBox")->setCoord({ x + 40,  y - IMAGEMANAGER->findImage(L"oilsBox")->getRealSize().y - 20 });

	if (IMAGEMANAGER->findImage(L"inventory")->getCoord().y < 0) IMAGEMANAGER->findImage(L"inventory")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x, 0 });
	if (IMAGEMANAGER->findImage(L"itemBox")->getCoord().y < 0) IMAGEMANAGER->findImage(L"itemBox")->setCoord({ IMAGEMANAGER->findImage(L"itemBox")->getCoord().x, 0 });
	if (IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y < 0) IMAGEMANAGER->findImage(L"oilsBox")->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, 0 });

	IMAGEMANAGER->findImage(L"아이템선택")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 35} );
}

void inven::render(void)
{
	if (_isMenew)	IMAGEMANAGER->findImage(L"inventory")->render(200);
	if (_isItem)	IMAGEMANAGER->findImage(L"itemBox")->render(200);
	if (_isOils)	IMAGEMANAGER->findImage(L"oilsBox")->render(200);
	if (_isMenew || _isItem || _isOils) IMAGEMANAGER->findImage(L"아이템선택")->frameRender(_frameX, 0, 255);
}
