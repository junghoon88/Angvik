#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{
}

HRESULT progressBar::init(TCHAR* name, int x, int y, int width, int height)
{
	_pt.x = x;
	_pt.y = y;

	TCHAR str[100] = L"";
	_stprintf(str, L"frontBar%s", name);
	_progressBarTop = IMAGEMANAGER->addImage(str, L"image/hpBarTop.bmp", x, y, width, height, true, RGB(255, 0, 255));
	_stprintf(str, L"backBar%s", name);
	_progressBarBottom = IMAGEMANAGER->addImage(str, L"image/hpBarBottom.bmp", x, y, width, height, true, RGB(255, 0, 255));

	_width = _progressBarTop->getWidth();

	return S_OK;
}

void progressBar::release()
{

}

void progressBar::update()
{
}

void progressBar::render(TCHAR* name)
{
	TCHAR str[100] = L"";
	_stprintf(str, L"backBar%s", name);
	IMAGEMANAGER->render(str, getMemDC(), _pt.x, _pt.y + _progressBarBottom->getHeight() / 2,
		0, 0,
		_progressBarBottom->getWidth(), _progressBarBottom->getHeight());

	_stprintf(str, L"frontBar%s", name);
	IMAGEMANAGER->render(str, getMemDC(), _pt.x, _pt.y + _progressBarBottom->getHeight() / 2,
		0, 0,
		_width, _progressBarBottom->getHeight());


}


void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _progressBarBottom->getWidth();
}

//=====================================================================================================================

progressBarHP::progressBarHP() {}
progressBarHP::~progressBarHP() {}

HRESULT progressBarHP::init(int x, int y, int width, int height)
{
	_pt.x = x;
	_pt.y = y;

	_width = width;
	_height = height;

	_rcWhite = RectMakeCenter(x, y, width, height);
	_rcHp = RectMakeCenter(x, y, width, height);
	_hpNum = _hpMaxNum = _rcHp.right - _rcHp.left;


	_penWhite = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	_brushGreen = CreateSolidBrush(RGB(33, 156, 33));
	_brushYellow = CreateSolidBrush(RGB(255, 206, 41));
	_brushRed = CreateSolidBrush(RGB(173, 8, 8));
	_brushWhite = CreateSolidBrush(RGB(255, 255, 255));

	return S_OK;
}
void progressBarHP::release()
{
	DeleteObject(_penWhite);
	DeleteObject(_brushGreen);
	DeleteObject(_brushYellow);
	DeleteObject(_brushRed);
	DeleteObject(_brushWhite);
}
void progressBarHP::update()
{
	_rcWhite = RectMakeCenter(_pt.x, _pt.y, _width, _height);
	_rcHp = RectMake(_rcWhite.left, _rcWhite.top, _hpNum, _height);
}

void progressBarHP::render()
{
	HPEN oldPen;
	HBRUSH oldBrush;

	oldPen = (HPEN)SelectObject(getMemDC(), _penWhite);
	oldBrush = (HBRUSH)SelectObject(getMemDC(), _brushWhite);
	//Rectangle(getMemDC(), _rcWhite.left - CAMERA->getCameraX(), _rcWhite.top - CAMERA->getCameraY(), _rcWhite.right - CAMERA->getCameraX(), _rcWhite.bottom - CAMERA->getCameraY());
	SelectObject(getMemDC(), oldBrush);

	//HP
	float percentHP = (float)_hpNum / (float)_hpMaxNum;

	if (percentHP > 0.5)
	{
		oldBrush = (HBRUSH)SelectObject(getMemDC(), _brushGreen);
	}
	else if (percentHP > 0.2)
	{
		oldBrush = (HBRUSH)SelectObject(getMemDC(), _brushYellow);
	}
	else
	{
		oldBrush = (HBRUSH)SelectObject(getMemDC(), _brushRed);
	}

	//Rectangle(getMemDC(), _rcHp.left - CAMERA->getCameraX(), _rcHp.top - CAMERA->getCameraY(), _rcHp.right - CAMERA->getCameraX(), _rcHp.bottom - CAMERA->getCameraY());
	SelectObject(getMemDC(), oldBrush);
	SelectObject(getMemDC(), oldPen);
}

void progressBarHP::setGauge(int HP, int HPMAX)
{
	_hpNum = HP * _hpMaxNum / HPMAX;
	//_rcHp = RectMake(_rcWhite.left + 1, _rcWhite.top + 1, _hpNum, _rcWhite.bottom - _rcWhite.top - 2);
}
