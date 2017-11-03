#include "stdafx.h"
#include "Turtle.h"


Turtle::Turtle()
{
}


Turtle::~Turtle()
{
}

void Turtle::init(float x, float y)
{
	spt = IMAGEMANAGER->findImage(L"°ÅºÏÀÌ");   //°ÅºÏÀÌ´©µå
	spt->setCoord({ 0,0 });

	dir = eRIGHT;
	state = eIDLE;
	life = 2;
	ptX = x;
	ptY = y;
	frameCnt = spt->getMaxFrameX();
	frameTime = 0;
	rc = RectMakeCenter(x, y, 100, 60);
	sptrc = RectMakeCenter(x, y, 110, 70);
	probeY = rc.bottom;
}
void Turtle::update(void)
{
	rc = RectMakeCenter(ptX, ptY, 100, 60);
	sptrc = RectMakeCenter(ptX, ptY , 110, 70);
	probeY = sptrc.bottom;
	spt->setCoord(sptrc.left, sptrc.top);
	if (life == 1 && spt == IMAGEMANAGER->findImage(L"°ÅºÏÀÌ")) spt = IMAGEMANAGER->findImage(L"°ÅºÏÀÌ´©µå");

	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.1f)
	{
		frameTime = 0;

		frameCnt--;
		if (frameCnt <= 0) frameCnt = spt->getMaxFrameX();
	}
	move();
}
void Turtle::render(void)
{
	spt->frameRender(frameCnt, 0, 255);
}
void Turtle::move(void)
{
	if (dir == eLEFT && state == eIDLE)
	{
		ptX -= 1;
	}
	if (dir == eRIGHT && state == eIDLE)
	{
		ptX += 1;
	}
	if (state == eFALL)
	{
		ptY += 1;
	}
	for (int i = probeY - 10; i < probeY + 10; ++i)//YÃà Å½Áö
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", ptX, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 0)) // °üÅëÇü ¹Ù´Ú
		{
			ptY = i - 35;
			state = eIDLE;
			break;
		}
		else
		{
			state = eFALL;
		}
	}
	//YÃà Å½Áö

	for (int i = ptX - 50; i < ptX + 50; ++i) // xÃà Å½Áö
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", i, ptY + 10);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255)) // °üÅëÇü ¹Ù´Ú
		{
			if (i >= ptX)
			{
				ptX = i - 50;
				dir = eLEFT;
				spt->setScale({ -1,1 });
				spt->setScaleOffset(100, 0);
			}
			else if (i < ptX)
			{
				ptX = i + 50;
				dir = eRIGHT;
				spt->setScale({ 1,1 });
			}
			break;
		}
	}
	// xÃà Å½Áö

}
void Turtle::attack(void)
{

}