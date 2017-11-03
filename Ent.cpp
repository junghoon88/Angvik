#include "stdafx.h"
#include "Ent.h"


Ent::Ent()
{
}


Ent::~Ent()
{
}


void Ent::init(float x, float y)
{
	spt = IMAGEMANAGER->findImage(L"나무맨");
	spt->setCoord({ 0,0 });
	//마더클래스 프로브축 추가해야함.
	dir = eRIGHT;
	state = eIDLE;
	life = 2;
	ptX = x;
	ptY = y;
	frameCnt = spt->getMaxFrameX();
	frameTime = 0;
	rc = RectMakeCenter(x, y, 40, 70);
	sptrc = RectMakeCenter(x, y, 50, 86);
	probeY = rc.bottom;
}
void Ent::update(void)
{
	rc = RectMakeCenter(ptX, ptY, 40, 70);
	sptrc = RectMakeCenter(ptX, ptY - 3, 50, 86);
	probeY = rc.bottom;
	spt->setCoord(sptrc.left,sptrc.top);

	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.1f)
	{
		frameTime = 0;

		frameCnt--;
		if (frameCnt <= 0) frameCnt = spt->getMaxFrameX();
	}
	move();
}
void Ent::render(void)
{
	spt->frameRender(frameCnt, 0);
}
void Ent::move(void)  
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
	for (int i = probeY - 10; i < probeY + 10; ++i)//Y축 탐지
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", ptX, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 0)) // 관통형 바닥
		{
			ptY = i - 40;
			state = eIDLE;
			break;
		}
		else
		{
			state = eFALL;
		}
	}
	//Y축 탐지

	for (int i = ptX - 10; i < ptX + 25; ++i) // x축 탐지
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", i, ptY + 10);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255)) // 관통형 바닥
		{
			if (i >= ptX)
			{
				ptX = i - 25;
				dir = eLEFT;
				spt->setScale({ -1,1 });
				spt->setScaleOffset(68,0);
			}
			else if (i < ptX)
			{
				ptX = i + 10;
				dir = eRIGHT;
				spt->setScale({ 1,1 });
			}
			break;
		}
	}
	// x축 탐지
	
}
void Ent::attack(void)
{

}