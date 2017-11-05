#include "stdafx.h"
#include "kong.h"


kong::kong(){}
kong::~kong(){}


void kong::init(int num, float x, float y, wstring rcKey)
{
	TCHAR strKey[100];
	_stprintf(strKey, L"Äá³ª¹°%d", num);
	spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"Äá³ª¹°")->getFileName(),
		IMAGEMANAGER->findImage(L"Äá³ª¹°")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"Äá³ª¹°")->getMaxFrameY() + 1);

	TCHAR strKey2[100];
	_stprintf(strKey, L"Äá³ª¹°¾îÅÃ%d", num);
	atkSpt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"Äá³ª¹°¾îÅÃ")->getFileName(),
		IMAGEMANAGER->findImage(L"Äá³ª¹°¾îÅÃ")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"Äá³ª¹°¾îÅÃ")->getMaxFrameY() + 1);
	//spt = IMAGEMANAGER->findImage(L"³ª¹«¸Ç");

	index = 2;
	dir = eRIGHT;
	state = eIDLE;
	life = 2;
	ptX = x;
	ptY = y;
	atkCnt = 0;
	frameCnt = spt->getMaxFrameX();
	frameTime = 0;
	rcName = rcKey;
	rc = RectMakeCenter(x, y, 32, 50);
	sptrc = RectMakeCenter(x, y, 32, 50);
	spt->setCoord(sptrc.left,rc.bottom - 54);
	atkSpt->setCoord(sptrc.left, rc.bottom - 40);
	playerX = 0;
	playerY = 0;
	RECTMANAGER->addRect(DEVICE, rcName, { (float)rc.left,(float)rc.top }, { 32, 50 });
	isAtk = false;
}
void kong::update(void)
{
	RECTMANAGER->findRect(rcName)->setCoord({ (float)rc.left,(float)rc.top });

	if (playerX < ptX)
	{
		dir = eLEFT;
		spt->setScale(-1, 1);
		atkSpt->setScale(-1, 1);
		spt->setScaleOffset(32, 0); //Á¶Á¤ÇØ¾ßÇÔ
		atkSpt->setScaleOffset(34, 0); //Á¶Á¤ÇØ¾ßÇÔ
	}
	else if (playerX > ptX)
	{
		dir = eRIGHT;
		atkSpt->setScale(1, 1);
		spt->setScale(1, 1);
	}
	//====
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

			if (frameCnt == 4) isAtk = true;
			if (frameCnt >= atkSpt->getMaxFrameX())
			{
				frameCnt = spt->getMaxFrameX();
				state = eIDLE;
			}
		}
	


	}


}
void kong::render(void)
{
	switch (state)
	{
	case eIDLE:spt->frameRender(frameCnt, 0);
		break;
	case eATK:atkSpt->frameRender(frameCnt, 0);
		break;
	}

	RECTMANAGER->render(rcName);
	
}
