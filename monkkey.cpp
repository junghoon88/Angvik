#include "stdafx.h"
#include "monkkey.h"


monkkey::monkkey()
{
}


monkkey::~monkkey()
{

}
void monkkey::init(int num, float x, float y, wstring rcKey) {

	TCHAR strKey[100];
	_stprintf(strKey, L"원숭이%d", num);
	spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"원숭이")->getFileName(),
		IMAGEMANAGER->findImage(L"원숭이")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"원숭이")->getMaxFrameY() + 1);

	//spt = IMAGEMANAGER->findImage(L"원숭이");
	gravity = 0;
	life = 1;
	ptX = x;
	ptY = y;
	rcName = rcKey;
	index = 0;
	spt->setCoord({ 0,0 });
	dir = eRIGHT;
	state = eIDLE;
	isImmune = false;
	frameCnt = 0;
	frameTime = 0;

	rcHeight = amountHeight = 45; //렉트 높이! 감소율 적용하기 위함.
	amountY = 1; //Y축 비율
	amountX = 1;
	amountTime = 0; //Y축 감소용 시간

	rc = RectMakeCenter(ptX, ptY, 45, rcHeight);   //100,60 의미x
	RECTMANAGER->addRect(DEVICE, rcName, { (float)rc.left,(float)rc.top }, { 45, rcHeight });
	probeY = rc.bottom;

}
void monkkey::update(void) {
	rc = RectMakeCenter(ptX, ptY, 45, rcHeight);

	if (life <= 0)
	{
		RIP();
	}
	else
	{
		probeY = rc.bottom;
		RECTMANAGER->findRect(rcName)->setCoord({ (float)rc.left,(float)rc.top });
		spt->setCoord({ (float)rc.left,(float)rc.top });

		frameTime += TIMEMANAGER->getElapsedTime();
		if (frameTime >= 0.1f)
		{
			frameTime = 0;

			frameCnt++;
			if (frameCnt >= 8) frameCnt = 0;
		}
		move();
	}



}
void monkkey::render(void) {

	spt->frameRender(frameCnt, 0);
	
	if (KEYMANAGER->isStayKeyDown(VK_F1)) RECTMANAGER->render(rcName);

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
	for (int i = probeY - 10; i < probeY + 10; ++i)//Y축 탐지
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
	//Y축 탐지

	for (int i = ptX - 20; i < ptX + 20; ++i) // x축 탐지
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG", i, ptY + 10);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255) || (r == 0 && g == 0 && b == 255))
		{
			if (i >= ptX)
			{
				ptX = i - 20;
				dir = eLEFT;
				spt->setScale({ -1,1 });
				amountX = -1;
				spt->setScaleOffset(45, 0);
			}
			else if (i < ptX)
			{
				ptX = i + 20;
				dir = eRIGHT;
				spt->setScale({ 1,1 });
				amountX = 1;
			}
			break;
		}
	}
	// x축 탐지

}
