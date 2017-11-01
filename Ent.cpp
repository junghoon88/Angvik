#include "stdafx.h"
#include "Ent.h"


Ent::Ent()
{
}


Ent::~Ent()
{
}


void Ent::init(float x, float y)
{
	spt = IMAGEMANAGER->findImage(L"������");
	spt->setCoord({ 0,0 });
	//����Ŭ���� ���κ��� �߰��ؾ���.
	dir = eRIGHT;

	life = 2;
	ptX = x;
	ptY = y;
	frameCnt = 0;
	rc = RectMakeCenter(x, y, 50, 80);
	probeY = rc.bottom;
}
void Ent::update(void)
{
	rc = RectMakeCenter(ptX, ptY, 50, 80);
	probeY = rc.bottom;
	spt->setCoord({ptX,(float)rc.top });

	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.1f)
	{
		frameTime -= 0.2f;

		frameCnt++;
		if (frameCnt >= 6) frameCnt = 0;
	}

	move();
}
void Ent::render(void)
{
	spt->frameRender(frameCnt, 0, 255);
}
void Ent::move(void)  
{
	
	if (dir == eLEFT)
	{
		ptX -= 2;
	}
	else if (dir == eRIGHT)
	{
		ptX += 2;
	}

	for (int i = probeY - 10; i < probeY + 10; ++i)//Y�� Ž��
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"�浹�׽�Ʈ", ptX, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 0)) // ������ �ٴ�
		{
			ptY = i - 40;
			break;
		}
	}
	//Y�� Ž��

	for (int i = ptX - 25; i < ptX + 25; ++i) // x�� Ž��
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"�浹�׽�Ʈ", i, ptY);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255)) // ������ �ٴ�
		{
			if (i > ptX)
			{
				ptX = i - 25;
				dir = eLEFT;
				spt->setScale({ -1,1 });
			}
			else if (i < ptX)
			{
				ptX = i + 25;
				dir = eRIGHT;
				spt->setScale({ 1,1 });
			}
			break;
		}
	}
	// x�� Ž��
	
}
void Ent::attack(void)
{

}