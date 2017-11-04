#include "stdafx.h"
#include "invenBird.h"


invenBird::invenBird()
{
}


invenBird::~invenBird()
{
}


void invenBird::init()
{
	
}

void invenBird::init(float x, float y)
{
	for (int i = 0; i < 5; i++)
	{
		_birdPoint[i] = { x - 40, y - 40 };
	}
	_birdMaxSpeed = 5.0f;

	_birdX = _birdY = 0;

	_frameX = _frameY = 0;
	_birdPointCount = 0;
	_timeCount = 0;
	_birdPointNum = 0;
	_inInventory = false;
}

void invenBird::release(void)
{

}

void invenBird::update(void)
{

}

void invenBird::update(float x, float y)
{
	move(x, y);
	birdFrame(x, y);
}

void invenBird::render(void)
{
	IMAGEMANAGER->findImage(L"inventoryBird")->frameRender(_frameX, _frameY);
}

void invenBird::move(float x, float y)
{
	_birdPointCount += TIMEMANAGER->getElapsedTime();

	if (_birdPointCount > 0.0001)
	{
		_birdPointNum++;
		if (_birdPointNum > 4) _birdPointNum = 0;
		_birdPointCount = 0;

		_birdPoint[_birdPointNum] = { x - 40, y - 40 };
	}

	for (int i = 0; i < 5; i++)
	{
		_birdX += _birdPoint[i].x;
		_birdY += _birdPoint[i].y;
	}

	_birdX = _birdX / 5;
	_birdY = _birdY / 5;

	_birdXY = IMAGEMANAGER->findImage(L"inventoryBird")->getCoord();

	_birdSpeed = getDistance(_birdXY.x, _birdXY.y, _birdX, _birdY) / 50;
	_angle = getAngle(_birdXY.x, _birdXY.y, _birdX, _birdY);

	IMAGEMANAGER->findImage(L"inventoryBird")->setCoord({ _birdXY.x + cosf(_angle) * _birdSpeed, _birdXY.y + -sinf(_angle) * _birdSpeed });

	_birdX = _birdY = 0;
}

void invenBird::birdFrame(float x, float y)
{
	_timeCount += TIMEMANAGER->getElapsedTime();

	if (_timeCount > 0.05)
	{
		_timeCount = 0;
		_frameX++;
	}
	if (_frameX > IMAGEMANAGER->findImage(L"inventoryBird")->getMaxFrameX())	_frameX = 0;

	_birdXY = IMAGEMANAGER->findImage(L"inventoryBird")->getCoord();

	if (!_inInventory)
	{
		if (_birdXY.x > x) _frameY = 1;
		else _frameY = 0;
	}
	else
	{
		if (_birdXY.x > x) _frameY = 3;
		else _frameY = 2;
	}
}

