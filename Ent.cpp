#include "stdafx.h"
#include "Ent.h"

Ent::Ent()
{
}


Ent::~Ent()
{
}


void Ent::init(int num, float x, float y, wstring rcKey)
{
	TCHAR strKey[100];
	_stprintf(strKey, L"나무맨%d", num);
	spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"나무맨")->getFileName(), 
														IMAGEMANAGER->findImage(L"나무맨")->getMaxFrameX() + 1, 
														IMAGEMANAGER->findImage(L"나무맨")->getMaxFrameY() + 1);

	TCHAR strKey2[100];
	_stprintf(strKey, L"나무맨어택%d", num);
	atkSpt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"나무맨어택")->getFileName(),
		IMAGEMANAGER->findImage(L"나무맨어택")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"나무맨어택")->getMaxFrameY() + 1);

	//spt = IMAGEMANAGER->findImage(L"나무맨");
	index = 4;
	spt->setCoord({ 0,0 });
	dir = eRIGHT;
	state = eIDLE;
	life = 2;
	ptX = x;
	ptY = y;
	isAtk = false;
	frameCnt = spt->getMaxFrameX();
	frameTime = 0;
	rcHeight = amountHeight = 60; //렉트 높이! 감소율 적용하기 위함.
	amountY = 1; //Y축 비율
	amountX = 1;//X축 비율
	amountTime = 0; //Y축 감소용 시간
	rcName = rcKey;
	rc = RectMakeCenter(x, y, 40, rcHeight);
	sptrc = RectMakeCenter(x, y, 40, 70);
	//RECTMANAGER->addRect(DEVICE, rcName, { (float)rc.left,(float)rc.top }, { 30, rcHeight });
	probeY = rc.bottom;
}
void Ent::update(void)
{
	rc = RectMakeCenter(ptX, ptY + 10, 30, 60);
	sptrc = RectMakeCenter(ptX - 15, ptY - 10, 40, 70);
	if (life <= 0)
	{
		RIP();
	}
	else
	{
		probeY = rc.bottom;
		spt->setCoord(sptrc.left, sptrc.top);
		//RECTMANAGER->findRect(rcName)->setCoord({ (float)rc.left,(float)rc.top });
		frameTime += TIMEMANAGER->getElapsedTime();
		if (state == eIDLE)
		{
			if (frameTime >= 0.2f)
			{
				frameTime = 0;
				frameCnt--;

				if (frameCnt <= 0)
				{
					frameCnt = spt->getMaxFrameX();
					atkCnt++;
					if (atkCnt >= 2)
					{
						atkCnt = 0;
						frameCnt = 0;
						state = eATK;
					}
				}
			}
		}
		else if (state == eATK)
		{
			if (frameTime >= 0.2f)
			{
				frameTime = 0;
				frameCnt++;

				if (frameCnt >= 3) isAtk = true;
				if (frameCnt >= atkSpt->getMaxFrameX())
				{
					frameCnt = spt->getMaxFrameX();
					state = eIDLE;
				}
			}
		}
		move();
	}

}
void Ent::render(void)
{
	spt->frameRender(frameCnt, 0);
	//RECTMANAGER->render(rcName);
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
		ptY += 1.5;
	}
	for (int i = probeY - 10; i < probeY + 10; ++i)//Y축 탐지
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", ptX, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 0) || (r == 255 && g == 255 && b == 0))
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

		if ((r == 0 && g == 255 && b == 255) || (r == 0 && g == 0 && b == 255))
		{
			if (i >= ptX)
			{
				ptX = i - 25;
				dir = eLEFT;
				amountX = -1;
				spt->setScale( -1,1 );
				spt->setScaleOffset(73,0);
			}
			else if (i < ptX)
			{
				ptX = i + 10;
				dir = eRIGHT;
				amountX = 1;
				spt->setScale( 1,1 );
			}
			break;
		}
	}
	// x축 탐지
	
}
