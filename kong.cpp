#include "stdafx.h"
#include "kong.h"


kong::kong(){}
kong::~kong(){}


void kong::init(int num, float x, float y)
{
	TCHAR strKey[100];
	_stprintf(strKey, L"�ᳪ��%d", num);
	spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"�ᳪ��")->getFileName(),
		IMAGEMANAGER->findImage(L"�ᳪ��")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"�ᳪ��")->getMaxFrameY() + 1);

	TCHAR strKey2[100];
	_stprintf(strKey, L"�ᳪ������%d", num);
	atkSpt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"�ᳪ������")->getFileName(),
		IMAGEMANAGER->findImage(L"�ᳪ������")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"�ᳪ������")->getMaxFrameY() + 1);
	//spt = IMAGEMANAGER->findImage(L"������");

	index = 2;
	dir = eRIGHT;
	state = eIDLE;
	life = 2;
	ptX = x;
	ptY = y;
	spt->setCoord(ptX, ptY);
	atkCnt = 0;
	frameCnt = spt->getMaxFrameX();
	frameTime = 0;
	rc = RectMakeCenter(x, y, 40, 70);
	sptrc = RectMakeCenter(x, y, 50, 86);
}
void kong::update(void)
{
	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.1f)
	{
		frameTime = 0;
		atkCnt++;
		frameCnt--;
		if (frameCnt <= 0) frameCnt = spt->getMaxFrameX();
	}

	if (playerX < ptX)
	{
		dir = eLEFT;
		spt->setScale(-1, 1);
		spt->setScaleOffset(68, 0); //�����ؾ���
	}
	else if (playerY > ptX)
	{
		dir = eRIGHT;
		spt->setScale(1, 1);
	}

}
void kong::render(void)
{
	spt->frameRender(frameCnt, 0);
}

bool kong::attack(void)
{
	if (atkCnt >= 2)
	{
		atkCnt = 0;
		return true;
	}
}