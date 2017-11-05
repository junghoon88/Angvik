#include "stdafx.h"
#include "Turtle.h"


Turtle::Turtle()
{
}


Turtle::~Turtle()
{
}

void Turtle::init(int num, float x, float y, wstring rcKey)
{
	TCHAR strKey[100];
	_stprintf(strKey, L"거북이%d", num);
	spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"거북이")->getFileName(),
		IMAGEMANAGER->findImage(L"거북이")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"거북이")->getMaxFrameY() + 1);

	isAtk = false;
	spt->setCoord({ 0,0 });
	index = 3;
	dir = eRIGHT;
	state = eIDLE;
	life = 1;
	ptX = x;
	ptY = y;
	frameCnt = spt->getMaxFrameX();
	frameTime = 0;
	isImmune = false;
	immuneTime = 0;
	rcHeight = amountHeight = 60; //렉트 높이! 감소율 적용하기 위함.
	amountY = 1; //Y축 비율
	amountX = 1;
	amountTime = 0; //Y축 감소용 시간

	rcName = rcKey;
	rc = RectMakeCenter(x, y, 100, rcHeight);
	//RECTMANAGER->addRect(DEVICE, rcName, { (float)rc.left,(float)rc.top }, { 100, rcHeight });
	sptrc = RectMakeCenter(x, y, 110, 70);
	probeY = rc.bottom;
}
void Turtle::update(void)
{
	rc = RectMakeCenter(ptX, ptY + 10, 100, rcHeight);
	if (life <= 0)
	{
		RIP();
	}
	else
	{
		sptrc = RectMakeCenter(ptX, ptY, 110, 70);
		probeY = sptrc.bottom;
		spt->setCoord(sptrc.left, sptrc.top);
		//RECTMANAGER->findRect(rcName)->setCoord({ (float)rc.left,(float)rc.top });
		frameTime += TIMEMANAGER->getElapsedTime();
		if (frameTime >= 0.1f)
		{
			frameTime = 0;

			frameCnt--;
			if (frameCnt <= 0) frameCnt = spt->getMaxFrameX();
		}
		move();
	}


}
void Turtle::render(void)
{
	spt->frameRender(frameCnt, 0, 255);
	//RECTMANAGER->render(rcName);
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
	for (int i = probeY - 10; i < probeY + 10; ++i)//Y축 탐지
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", ptX, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 0))
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
	//Y축 탐지

	for (int i = ptX - 50; i < ptX + 50; ++i) // x축 탐지
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", i, ptY + 10);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255) || (r == 0 && g == 0 && b == 255))
		{
			if (i >= ptX)
			{
				ptX = i - 50;
				dir = eLEFT;
				spt->setScale({ -1,1 });
				amountX = -1;
				spt->setScaleOffset(100, 0);
			}
			else if (i < ptX)
			{
				ptX = i + 50;
				dir = eRIGHT;
				spt->setScale({ 1,1 });
				amountX = 1;
			}
			break;
		}
	}
	// x축 탐지

}
