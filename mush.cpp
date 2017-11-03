#include "stdafx.h"
#include "mush.h"


mush::mush()
{
}
mush::~mush()
{
}

void mush::init(float x, float y, wstring rcKey) {


	atkspt = IMAGEMANAGER->findImage(L"πˆº∏∞¯∞›");
	jmpspt = IMAGEMANAGER->findImage(L"πˆº∏¡°«¡");
	spt = IMAGEMANAGER->findImage(L"πˆº∏∏«");

	gravity = 0;
	life = 1;
	ptX = x;
	ptY = y;
	rcName = rcKey;

	spt->setCoord({ 0,0 });
	atkspt->setCoord({ 0,0 });
	jmpspt->setCoord({ 0,0 });

	dir = eRIGHT;
	state = eIDLE;

	frameCnt = spt->getMaxFrameX();
	atkFrameCnt = atkspt->getMaxFrameX();
	jumpFrameCnt = jmpspt->getMaxFrameX();

	frameTime = 0;
	atkFrameTime = 0;
	jumpFrameTime = 0;
	

	rc = RectMakeCenter(ptX, ptY, 20, 20);  
	RECTMANAGER->addRect(DEVICE, rcName, { (float)rc.left,(float)rc.top }, { 20, 20 });
	probeY = rc.bottom;

}
void mush::update(void) {
	rc = RectMakeCenter(ptX, ptY, 20, 20);
	probeY = rc.bottom;
	RECTMANAGER->findRect(rcName)->setCoord({ (float)rc.left,(float)rc.top });
	spt->setCoord({ (float)rc.left,(float)rc.top });


	if (state == eIDLE) {
		frameTime += TIMEMANAGER->getElapsedTime();
		if (frameTime >= 0.1f)
		{
			frameTime -= 0.1f;

			frameCnt++;
			if (frameCnt >= 7) frameCnt = 0;
		}
	}
	else if (state == eATK) {
		atkFrameTime += TIMEMANAGER->getElapsedTime();
		if (atkFrameTime >= 0.1f)
		{
			atkFrameTime -= 0.1f;

			atkFrameCnt++;
			if (atkFrameCnt >= 6)atkFrameCnt = 0;
		}

	}
	else if (state == eJUMP||state == eFALL) {
	
		jumpFrameTime += TIMEMANAGER->getElapsedTime();
		if (jumpFrameTime >= 0.1f)
		{
			jumpFrameTime -= 0.1f;

			jumpFrameCnt++;
			if (jumpFrameCnt >= 2)jumpFrameCnt = 0;
		}
		
	}
	move();


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

			ptX += cosf(1.04)*jumpPower;
			ptY += -sinf(1.04)*jumpPower + gravity;

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
	for (int i = probeY - 10; i < probeY + 10; ++i)//Y√‡ ≈Ω¡ˆ
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", ptX, i);


		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 0))
		{
			ptY = i - 20;
			state = eIDLE;
			break;
		}
		else if ((r == 255 && g == 255 && b == 0))
		{
			state = eJUMP;
			break;
		}
		else
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
				spt->setScale({ -1,1 });
				spt->setScaleOffset(45, 0);
			}
			else if (i < ptX)
			{
				ptX = i + 20;
				dir = eRIGHT;
				spt->setScale({ 1,1 });
			}
			break;
		}
	}
	// x√‡ ≈Ω¡ˆ

}
void mush::attack(void) {



}