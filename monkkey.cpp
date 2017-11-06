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
	_stprintf(strKey, L"������%d", num);
	spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"������")->getFileName(),
		IMAGEMANAGER->findImage(L"������")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"������")->getMaxFrameY() + 1);

	//spt = IMAGEMANAGER->findImage(L"������");
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

	rcHeight = amountHeight = 45; //��Ʈ ����! ������ �����ϱ� ����.
	amountY = 1; //Y�� ����
	amountX = 1;
	amountTime = 0; //Y�� ���ҿ� �ð�

	rc = RectMakeCenter(ptX, ptY, 45, rcHeight);   //100,60 �ǹ�x
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
	for (int i = probeY - 10; i < probeY + 10; ++i)//Y�� Ž��
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
	//Y�� Ž��

	for (int i = ptX - 20; i < ptX + 20; ++i) // x�� Ž��
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
	// x�� Ž��

}
