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
	_stprintf(strKey, L"������%d", num);
	spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"������")->getFileName(), 
														IMAGEMANAGER->findImage(L"������")->getMaxFrameX() + 1, 
														IMAGEMANAGER->findImage(L"������")->getMaxFrameY() + 1);
	//spt = IMAGEMANAGER->findImage(L"������");
	index = 0;
	spt->setCoord({ 0,0 });
	dir = eRIGHT;
	state = eIDLE;
	life = 2;
	ptX = x;
	ptY = y;
	isAtk = false;
	frameCnt = spt->getMaxFrameX();
	frameTime = 0;
	rcHeight = amountHeight = 60; //��Ʈ ����! ������ �����ϱ� ����.
	amountY = 1; //Y�� ����
	amountTime = 0; //Y�� ���ҿ� �ð�
	rcName = rcKey;
	rc = RectMakeCenter(x, y, 40, rcHeight);
	sptrc = RectMakeCenter(x, y, 40, 70);
	RECTMANAGER->addRect(DEVICE, rcName, { (float)rc.left,(float)rc.top }, { 30, rcHeight });
	probeY = rc.bottom;
}
void Ent::update(void)
{
	rc = RectMakeCenter(ptX, ptY + 10, 30, 60);
	sptrc = RectMakeCenter(ptX - 15, ptY - 10, 40, 70);
	probeY = rc.bottom;
	spt->setCoord(sptrc.left,sptrc.top);
	RECTMANAGER->findRect(rcName)->setCoord({ (float)rc.left,(float)rc.top });
	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.1f)
	{
		frameTime = 0;

		frameCnt--;
		if (frameCnt <= 0) frameCnt = spt->getMaxFrameX();
	}
	move();
	RIP();
}
void Ent::render(void)
{
	//RECTMANAGER->render(L"�����Ƿ�Ʈ");
	spt->frameRender(frameCnt, 0);
	RECTMANAGER->render(rcName);
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
	for (int i = probeY - 10; i < probeY + 10; ++i)//Y�� Ž��
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
	//Y�� Ž��

	for (int i = ptX - 10; i < ptX + 25; ++i) // x�� Ž��
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
				spt->setScale( -1,1 );
				spt->setScaleOffset(73,0);
			}
			else if (i < ptX)
			{
				ptX = i + 10;
				dir = eRIGHT;
				spt->setScale( 1,1 );
			}
			break;
		}
	}
	// x�� Ž��
	
}
