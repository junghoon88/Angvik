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

	life = 1;
	ptX = x;
	ptY = y;

	rc = RectMakeCenter(x, y, 50, 80);
	probeY = rc.bottom;
}
void Ent::update(void)
{
	rc = RectMakeCenter(ptX, ptY, 50, 80);
	probeY = rc.bottom;
	spt->setCoord({ ptX,ptY });

	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.1f)
	{
		frameTime -= 0.2f;

		frameCnt++;
		if (frameCnt >= 8) frameCnt = 0;
	}

	move();
}
void Ent::render(void)
{
	spt->frameRender(frameCnt, 0, true);
}
void Ent::move(void)  
{
	
	if (dir == eLEFT)
	{
		ptX -= 5;
	}
	else if (dir == eRIGHT)
	{
		ptX += 5;
	}

	for (int i = probeY - 10; i < probeY + 10; ++i)//Y축 탐지
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"테스트배경", ptX, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 0)) // 관통형 바닥
		{
			ptY = i - 40;
			break;
		}
	}
	//Y축 탐지

	for (int i = ptX - 20; i < ptX + 20; ++i) // x축 탐지
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"테스트배경", i, ptY);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255)) // 관통형 바닥
		{
			if (i > ptX) dir = eLEFT;
			else if (i < ptX) dir = eRIGHT;
			break;
		}
	}
	// x축 탐지
	
}
void Ent::attack(void)
{

}