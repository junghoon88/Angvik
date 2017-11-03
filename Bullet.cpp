#include "stdafx.h"
#include "Bullet.h"

sBMR::sBMR() {}
sBMR::~sBMR() {}

void sBMR::init(void)
{

}
void sBMR::release(void)
{

}
void sBMR::update(float x, float y)
{
	move(x,y);
}
void sBMR::render(void)	
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->spt->frameRender(_viBullet->frameX, 1, 255);
	}
}
void sBMR::fire(float ptx, float pty ,float ang)
{

}
void sBMR::move(float x,float y)
{

}

void sBMR::remove(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}


//====================================================Äá³ª¹°Åº========================================================================
Kong::Kong(){}
Kong::~Kong(){}

void Kong::init(void)
{

}
void Kong::release(void)
{

}
void Kong::update(void)
{
	move();
}
void Kong::render(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->spt->frameRender(_viBullet->frameX, 1, 255);//ÇÁ·¹ÀÓ º¯¼ö Ãß°¡ÇØ¾ßÇÔ
	}
}
void Kong::fire(float ptx, float pty, float ang)
{
	tagBullet kong;
	ZeroMemory(&kong, sizeof(tagBullet));
	kong.spt = IMAGEMANAGER->findImage(L"ÄáÅº");
	kong.speed = 1.2f;
	kong.ptX = kong.fireX = ptx;
	kong.ptY = kong.fireY = pty;
	kong.angle = ang;
	kong.frameTime = 0;
	kong.frameX = 0;
	kong.rc = RectMakeCenter(kong.ptX, kong.ptY,18,16);
	_vBullet.push_back(kong);
}
void Kong::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->ptX += cos(_viBullet->angle) * _viBullet->speed;
		_viBullet->ptY += -sin(_viBullet->angle) * _viBullet->speed;

		_viBullet->rc = RectMakeCenter(_viBullet->ptX, _viBullet->ptY, 18, 16);

		_viBullet->frameTime += TIMEMANAGER->getElapsedTime();
		if (_viBullet->frameTime >= 0.1f)
		{
			_viBullet->frameTime = 0;

			_viBullet->frameX--;
			if (_viBullet->frameX >= _viBullet->spt->getMaxFrameX()) _viBullet->frameX = 0;
		}

		if (range < getDistance(_viBullet->ptX, _viBullet->ptY, _viBullet->fireX, _viBullet->fireY))
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;
	}
}

void Kong::remove(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}
