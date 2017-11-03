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
}

void inven::release(void)
{

}

void inven::update(void)
{

}

void inven::update(float x, float y)
{
	IMAGEMANAGER->findImage(L"inventory")->setCoord({ x + 40, y - IMAGEMANAGER->findImage(L"inventory")->getRealSize().y - 20 });
	IMAGEMANAGER->findImage(L"itemBox")->setCoord({ x + 40,  y - IMAGEMANAGER->findImage(L"itemBox")->getRealSize().y - 20 });
	IMAGEMANAGER->findImage(L"oilsBox")->setCoord({ x + 40,  y - IMAGEMANAGER->findImage(L"oilsBox")->getRealSize().y - 20 });

	if (IMAGEMANAGER->findImage(L"inventory")->getCoord().y < 0) IMAGEMANAGER->findImage(L"inventory")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x, 0 });
	if (IMAGEMANAGER->findImage(L"itemBox")->getCoord().y < 0) IMAGEMANAGER->findImage(L"itemBox")->setCoord({ IMAGEMANAGER->findImage(L"itemBox")->getCoord().x, 0 });
	if (IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y < 0) IMAGEMANAGER->findImage(L"oilsBox")->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, 0 });
}

void inven::render(void)
{
	//IMAGEMANAGER->findImage(L"inventory")->render(200);
	//IMAGEMANAGER->findImage(L"itemBox")->render(200);
	IMAGEMANAGER->findImage(L"oilsBox")->render(200);
}
