#include "stdafx.h"
#include "monkkey.h"


monkkey::monkkey()
{
}


monkkey::~monkkey()
{

}
void monkkey::init(float x, float y, wstring rcKey) {

	spt = IMAGEMANAGER->findImage(L"ø¯º˛¿Ã");
	gravity = 0;
	life = 1;
	ptX = x;
	ptY = y;
	rcName = rcKey;

	spt->setCoord({ 0,0 });
	dir = eRIGHT;
	state = eIDLE;

	frameCnt = spt->getMaxFrameX();
	frameTime = 0;

	rc = RectMakeCenter(ptX, ptY, 45, 45);   //100,60 ¿«πÃx
	RECTMANAGER->addRect(DEVICE, rcName, { (float)rc.left,(float)rc.top }, { 45, 45 });
	probeY = rc.bottom;

}
void monkkey::update(void) {
	rc = RectMakeCenter(ptX, ptY, 45, 45);
	probeY = rc.bottom;
	RECTMANAGER->findRect(rcName)->setCoord({ (float)rc.left,(float)rc.top });
	spt->setCoord({(float)rc.left,(float)rc.top });
	
	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.1f)
	{
		frameTime -= 0.1f;

		frameCnt++;
		if (frameCnt >= 8) frameCnt = 0;
	}

	move();
	

}
void monkkey::render(void) {

	spt->frameRender(frameCnt, 0);
	
	RECTMANAGER->render(rcName);

}
void monkkey::move(void) {

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
