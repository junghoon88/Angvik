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
	_isMenew = false;
	_isItem = false;
	_isOils = false;
	_isInven = false;

	_goldOils = _blackOils = _whiteOils = 1;

	_timeCount = 0;
	_selectNum = 0;
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
	if (KEYMANAGER->isStayKeyDown(BTN_PLAYER_INVENTORY) && !_isMenew)
	{
		_isInven = true;
		_isMenew = true;
		SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
	}
	//상시 인벤 위치 업데이트
	IMAGEMANAGER->findImage(L"inventory")->setCoord({ x + 40, y - IMAGEMANAGER->findImage(L"inventory")->getRealSize().y - 20 });
	if (IMAGEMANAGER->findImage(L"inventory")->getCoord().y < 0) IMAGEMANAGER->findImage(L"inventory")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x, 0 });
	IMAGEMANAGER->findImage(L"item")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x + 45, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 45 });
	IMAGEMANAGER->findImage(L"oils")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x + 45, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 90 });
	IMAGEMANAGER->findImage(L"close")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x + 40, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 132 });

	if (_isMenew)
	{
		_selectPoint[0] = { IMAGEMANAGER->findImage(L"inventory")->getCoord().x, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 35 };
		_selectPoint[1] = { IMAGEMANAGER->findImage(L"inventory")->getCoord().x, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 80 };
		_selectPoint[2] = { IMAGEMANAGER->findImage(L"inventory")->getCoord().x, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 122 };

		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_DOWN))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum++;
		}
		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_UP))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum--;
		}
		if (_selectNum > 2) _selectNum = 0;
		if (_selectNum < 0) _selectNum = 2;

		if (_selectNum == 0 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			_selectNum = 0;
			_isMenew = false;
			_isItem = true;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
		if (_selectNum == 1 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			_selectNum = 0;
			_isMenew = false;
			_isOils = true;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
		if ((_selectNum == 2 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND)) || KEYMANAGER->isOnceKeyDown(BTN_PLAYER_JUMP))
		{
			_selectNum = 0;
			_isMenew = false;
			_isInven = false;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
	}

	//상시 아이템박스 위치 업데이트
	IMAGEMANAGER->findImage(L"itemBox")->setCoord({ x + 40,  y - IMAGEMANAGER->findImage(L"itemBox")->getRealSize().y - 20 });
	if (IMAGEMANAGER->findImage(L"itemBox")->getCoord().y < 0) IMAGEMANAGER->findImage(L"itemBox")->setCoord({ IMAGEMANAGER->findImage(L"itemBox")->getCoord().x, 0 });
	IMAGEMANAGER->findImage(L"back")->setCoord({ IMAGEMANAGER->findImage(L"itemBox")->getCoord().x + 40, IMAGEMANAGER->findImage(L"itemBox")->getCoord().y + 215 });

	if (_isItem)
	{
		_selectPoint[0] = { IMAGEMANAGER->findImage(L"itemBox")->getCoord().x, IMAGEMANAGER->findImage(L"itemBox")->getCoord().y + 35 };
		_selectPoint[1] = { IMAGEMANAGER->findImage(L"itemBox")->getCoord().x, IMAGEMANAGER->findImage(L"itemBox")->getCoord().y + 75 };
		_selectPoint[2] = { IMAGEMANAGER->findImage(L"itemBox")->getCoord().x, IMAGEMANAGER->findImage(L"itemBox")->getCoord().y + 115 };
		_selectPoint[3] = { IMAGEMANAGER->findImage(L"itemBox")->getCoord().x, IMAGEMANAGER->findImage(L"itemBox")->getCoord().y + 155 };
		_selectPoint[4] = { IMAGEMANAGER->findImage(L"itemBox")->getCoord().x, IMAGEMANAGER->findImage(L"itemBox")->getCoord().y + 205 };

		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_DOWN))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum++;
		}
		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_UP))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum--;
		}
		if (_selectNum > 4) _selectNum = 0;
		if (_selectNum < 0) _selectNum = 4;

		if ((_selectNum == 4 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND)) || KEYMANAGER->isOnceKeyDown(BTN_PLAYER_JUMP))
		{
			_selectNum = 0;
			_isMenew = true;
			_isItem = false;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
	}

	//상시 오일박스 위치 업데이트
	IMAGEMANAGER->findImage(L"oilsBox")->setCoord({ x + 40,  y - IMAGEMANAGER->findImage(L"oilsBox")->getRealSize().y - 20 });
	if (IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y < 0) IMAGEMANAGER->findImage(L"oilsBox")->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, 0 });
	IMAGEMANAGER->findImage(L"back")->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x + 40, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 175 });
	
	for (int i = 0; i < _goldOils; i++)
	{
		IMAGEMANAGER->findImage(L"골드오일")->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x + 20,  IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 40 });
	}
	for (int i = 0; i < _blackOils; i++)
	{
		IMAGEMANAGER->findImage(L"블랙오일")->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x + 20,  IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 85 });
	}
	for (int i = 0; i < _whiteOils; i++)
	{
		IMAGEMANAGER->findImage(L"흰색오일")->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x + 20,  IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 130 });
	}

	if (_isOils)
	{
		_selectPoint[0] = { IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 35 };
		_selectPoint[1] = { IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 80 };
		_selectPoint[2] = { IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 125 };
		_selectPoint[3] = { IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 165 };

		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_DOWN))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum++;
		}
		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_UP))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum--;
		}
		if (_selectNum > 3) _selectNum = 0;
		if (_selectNum < 0) _selectNum = 3;

		if ((_selectNum == 3 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND)) || KEYMANAGER->isOnceKeyDown(BTN_PLAYER_JUMP))
		{
			_selectNum = 0;
			_isMenew = true;
			_isOils = false;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
	}

	//선택지 위치 업데이트
	IMAGEMANAGER->findImage(L"아이템선택")->setCoord(_selectPoint[_selectNum]);
}

void inven::render(void)
{
	if (_isMenew)	IMAGEMANAGER->findImage(L"inventory")->render(200);
	if (_isItem)	IMAGEMANAGER->findImage(L"itemBox")->render(200);
	if (_isOils)	IMAGEMANAGER->findImage(L"oilsBox")->render(200);
	if (_isMenew || _isItem || _isOils) IMAGEMANAGER->findImage(L"아이템선택")->frameRender(_frameX, 0, 255);
	if (_isMenew)
	{
		IMAGEMANAGER->findImage(L"item")->render();
		IMAGEMANAGER->findImage(L"oils")->render();
		IMAGEMANAGER->findImage(L"close")->render();
	}
	else if (_isItem)
	{
		IMAGEMANAGER->findImage(L"back")->render();
	}
	else if (_isOils)
	{
		IMAGEMANAGER->findImage(L"back")->render();
		IMAGEMANAGER->findImage(L"골드오일")->render();
		IMAGEMANAGER->findImage(L"블랙오일")->render();
		IMAGEMANAGER->findImage(L"흰색오일")->render();
	}
}
