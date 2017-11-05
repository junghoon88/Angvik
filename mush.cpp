#include "stdafx.h"
#include "mush.h"


mush::mush()
{
}
mush::~mush()
{
}

void mush::init(int num, float x, float y, wstring rcKey) {

	TCHAR strKey[100];
	_stprintf(strKey, L"πˆº∏∏«%d", num);
	spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"πˆº∏∏«")->getFileName(),
		IMAGEMANAGER->findImage(L"πˆº∏∏«")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"πˆº∏∏«")->getMaxFrameY() + 1);
	TCHAR strKey2[100];
	_stprintf(strKey, L"πˆº∏∞¯∞›%d", num);
	atkspt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"πˆº∏∞¯∞›")->getFileName(),
		IMAGEMANAGER->findImage(L"πˆº∏∞¯∞›")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"πˆº∏∞¯∞›")->getMaxFrameY() + 1);
	TCHAR strKey3[100];
	_stprintf(strKey, L"πˆº∏¡°«¡%d", num);
	jmpspt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"πˆº∏¡°«¡")->getFileName(),
		IMAGEMANAGER->findImage(L"πˆº∏¡°«¡")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"πˆº∏¡°«¡")->getMaxFrameY() + 1);

	gravity = 0;
	life = 1;
	ptX = x;
	ptY = y;
	rcName = rcKey;
	jumpPower = 0;
	spt->setCoord({ 0,0 });
	atkspt->setCoord({ 0,0 });
	jmpspt->setCoord({ 0,0 });

	dir = eRIGHT;
	state = eIDLE;

	frameCnt = 0;
	atkFrameCnt = 0;
	jumpFrameCnt = 0;
	index = 1;
	frameTime = 0;
	atkFrameTime = 0;
	jumpFrameTime = 0;
	atkCnt = 0;
	isAtk = false;

	rc = RectMakeCenter(ptX, ptY, 20, 20);  
	RECTMANAGER->addRect(DEVICE, rcName, { (float)rc.left,(float)rc.top }, { 20, 20 });
	probeY = rc.bottom;

}
void mush::update(void) {
	rc = RectMakeCenter(ptX, ptY, 20, 20);
	probeY = rc.bottom;
	RECTMANAGER->findRect(rcName)->setCoord({ (float)rc.left,(float)rc.top });

	spt->setCoord({ (float)rc.left,(float)rc.top });
	atkspt->setCoord({ (float)rc.left,(float)rc.top });
	jmpspt->setCoord({ (float)rc.left,(float)rc.top });

	if (state == eIDLE) {
		frameTime += TIMEMANAGER->getElapsedTime();
		if (frameTime >= 0.1f)
		{
			frameTime = 0;

			frameCnt++;
			if (frameCnt >= 7) frameCnt = 0;
		}
	}
	else if (state == eATK) {
		atkFrameTime += TIMEMANAGER->getElapsedTime();
		if (atkFrameTime >= 0.1f)
		{
			atkFrameTime = 0;
			atkFrameCnt++;
			if (atkFrameCnt >= 6) {
				isAtk = true;
				atkFrameCnt = 0;
				state = eIDLE;
			}
		}

	}
	else if (state == eJUMP||state == eFALL) {
	
		jumpFrameTime += TIMEMANAGER->getElapsedTime();
		if (jumpFrameTime >= 0.1f)
		{
			jumpFrameTime =0;

			jumpFrameCnt++;
			if (jumpFrameCnt >= 2)jumpFrameCnt = 0;
		}
		
	}

	move();
	if (state == eIDLE) {
		atkCnt += TIMEMANAGER->getElapsedTime();
		if (atkCnt >= 1.0f)
		{
			atkCnt = 0;
			state = eATK;
		}
	}
}
void mush::render(void) {

	switch (state) {
		case eIDLE:
			spt->frameRender(frameCnt, 0);
			break;
		case eATK:
			atkspt->frameRender(atkFrameCnt, 0);
			break;
		case eJUMP:
			jmpspt->frameRender(jumpFrameCnt, 0);
			break;
		case eFALL:
			jmpspt->frameRender(jumpFrameCnt, 0);
			break;
		default: break;
	}
	
	RECTMANAGER->render(rcName);

}
void mush::move(void) {

	if (dir == eLEFT && state == eIDLE)
	{
		gravity = 0;
		ptX -= 2;
	}
	if (dir == eRIGHT && state == eIDLE)
	{
		gravity = 0;
		ptX += 2;
	}
	if (state == eJUMP)
	{
		if(dir==eLEFT)
		{
			gravity += 0.2;

			ptX += cosf(2.09)*jumpPower;
			ptY += -sinf(2.09)*jumpPower + gravity;

		}
		else if (dir == eRIGHT)
		{
			gravity += 0.2;

			ptX += cosf(1.04)*jumpPower;
			ptY += -sinf(1.04)*jumpPower + gravity;

		}
	}

	if (state == eFALL)
	{
		gravity += 0.2;
		ptY += gravity;
	}
	for (int i = probeY - 10; i < probeY + 15; ++i)//Y√‡ ≈Ω¡ˆ
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", ptX, i);


		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 255 && g == 255 && b == 0) && state!=eJUMP)
		{	
			jumpPower = 7;
			state = eJUMP;
			break;
		}
		else if ((r == 0 && g == 0 && b == 0)&& (state!=eJUMP||gravity>=5))
		{
			ptY = i - 15;
			if (state != eATK)
				state = eIDLE;
			break;
		}
		else if(state!=eJUMP)
		{
			state = eFALL;
		}
	}
	//Y√‡ ≈Ω¡ˆ

	for (int i = ptX - 20; i < ptX + 20; ++i) // x√‡ ≈Ω¡ˆ
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", i, ptY + 10);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255)) // ∞¸≈Î«¸ πŸ¥⁄
		{
			if (i >= ptX)
			{
				ptX = i - 20;
				dir = eLEFT;
				jmpspt->setScale({ -1,1 });
				jmpspt->setScaleOffset(25, 0);
				spt->setScale({ -1,1 });
				spt->setScaleOffset(25, 0);
			}
			else if (i < ptX)
			{
				ptX = i + 20;
				dir = eRIGHT;
				jmpspt->setScale({ 1,1 });
				spt->setScale({ 1,1 });
			}
			break;
		}
	}
	// x√‡ ≈Ω¡ˆ
}
