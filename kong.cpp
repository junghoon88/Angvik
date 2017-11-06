#include "stdafx.h"
#include "kong.h"


kong::kong(){}
kong::~kong(){}


void kong::init(int num, float x, float y, wstring rcKey)
{
	TCHAR strKey[100];
	_stprintf(strKey, L"콩나물%d", num);
	spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"콩나물")->getFileName(),
		IMAGEMANAGER->findImage(L"콩나물")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"콩나물")->getMaxFrameY() + 1);

	TCHAR strKey2[100];
	_stprintf(strKey, L"콩나물어택%d", num);
	atkSpt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"콩나물어택")->getFileName(),
		IMAGEMANAGER->findImage(L"콩나물어택")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"콩나물어택")->getMaxFrameY() + 1);
	//spt = IMAGEMANAGER->findImage(L"나무맨");

	index = 2;
	dir = eRIGHT;
	state = eIDLE;
	life = 1;
	ptX = x;
	ptY = y;
	atkCnt = 0;
	frameCnt = spt->getMaxFrameX();
	frameTime = 0;
	isImmune = false;
	rcHeight = amountHeight = 40; //렉트 높이! 감소율 적용하기 위함.
	amountY = 1; //Y축 비율
	amountX = 1;
	amountTime = 0; //Y축 감소용 시간

	rcName = rcKey;
	rc = RectMakeCenter(x, y, 26, rcHeight);
	sptrc = RectMakeCenter(x, y, 32, 50);
	spt->setCoord(sptrc.left,rc.bottom - 54);
	atkSpt->setCoord(sptrc.left, rc.bottom - 40);
	spt->setScaleOffset(32, 0); //조정해야함
	atkSpt->setScaleOffset(34, 0); //조정해야함
	RECTMANAGER->addRect(DEVICE, rcName, { (float)rc.left,(float)rc.top }, { 26, rcHeight });
	isAtk = false;
}
void kong::update(void)
{
	rc = RectMakeCenter(ptX, ptY, 26, rcHeight);
	if (life <= 0)
	{
		RIP();
	}
	else
	{
		RECTMANAGER->findRect(rcName)->setCoord({ (float)rc.left,(float)rc.top });

		if (playerX < ptX)
		{
			dir = eLEFT;
			amountX = -1;
			spt->setScale(-1, 1);
			atkSpt->setScale(-1, 1);

		}
		else if (playerX > ptX)
		{
			dir = eRIGHT;
			amountX = 1;
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

}
void kong::render(void)
{
	switch (state)
	{
	case eIDLE:spt->frameRender(frameCnt, 0);
		break;
	case eATK:atkSpt->frameRender(frameCnt, 0);
		break;
	default:spt->frameRender(frameCnt, 0);
		break;
	}

	if (KEYMANAGER->isStayKeyDown(VK_F1)) RECTMANAGER->render(rcName);
	
}
