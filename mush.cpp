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
	_stprintf(strKey, L"버섯맨%d", num);
	spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"버섯맨")->getFileName(),
		IMAGEMANAGER->findImage(L"버섯맨")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"버섯맨")->getMaxFrameY() + 1);
	TCHAR strKey2[100];
	_stprintf(strKey, L"버섯공격%d", num);
	atkspt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"버섯공격")->getFileName(),
		IMAGEMANAGER->findImage(L"버섯공격")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"버섯공격")->getMaxFrameY() + 1);
	TCHAR strKey3[100];
	_stprintf(strKey, L"버섯점프%d", num);
	jmpspt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"버섯점프")->getFileName(),
		IMAGEMANAGER->findImage(L"버섯점프")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"버섯점프")->getMaxFrameY() + 1);

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
	isImmune = true;
	immuneTime = 0;
	isUP = true;
	alpha = 255;
	frameCnt = 0;
	atkFrameCnt = 0;
	jumpFrameCnt = 0;
	index = 1;
	frameTime = 0;
	atkFrameTime = 0;
	jumpFrameTime = 0;

	rcHeight = amountHeight = 20; //렉트 높이! 감소율 적용하기 위함.
	amountY = 1; //Y축 비율
	amountX = 1;
	amountTime = 0; //Y축 감소용 시간

	atkCnt = 0;
	isAtk = false;

	rc = RectMakeCenter(ptX, ptY, 20, rcHeight);
	RECTMANAGER->addRect(DEVICE, rcName, { (float)rc.left,(float)rc.top }, { 20, rcHeight });
	probeY = rc.bottom;

}
void mush::update(void) {
	rc = RectMakeCenter(ptX, ptY, 20, rcHeight);
	
	if (life <= 0)
	{
		RIP();
	}
	else
	{
		if (isImmune) {    //무적시간
			if (isUP)
			{
				alpha += 50;
				if (alpha >= 255)
					isUP = false;
			}
			if (!isUP)
			{
				alpha -= 50;
				if (alpha <= 0)
					isUP = true;
			}
			immuneTime += TIMEMANAGER->getElapsedTime();
			if (immuneTime >= 1.5f) {
				alpha = 255;
				isImmune = false;
			}
		}
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
				if (atkFrameCnt >= 6)  atkFrameCnt = 0;
				
			}

		}
		else if (state == eJUMP || state == eFALL) {

			jumpFrameTime += TIMEMANAGER->getElapsedTime();
			if (jumpFrameTime >= 0.1f)
			{
				jumpFrameTime = 0;

				jumpFrameCnt++;
				if (jumpFrameCnt >= 2)jumpFrameCnt = 0;
			}

		}

		if (state == eIDLE) {
			atkCnt += TIMEMANAGER->getElapsedTime();
			if (atkCnt >= 1.5f)
			{
				atkCnt = 0;
				isAtk = true;
			}
		}
		move();
	}
	
}
void mush::render(void) {

	switch (state) {
		case eIDLE:
			spt->frameRender(frameCnt, 0,alpha);
			break;
		case eATK:
			atkspt->frameRender(atkFrameCnt, 0, alpha);
			break;
		case eJUMP:
			jmpspt->frameRender(jumpFrameCnt, 0, alpha);
			break;
		case eFALL:
			jmpspt->frameRender(jumpFrameCnt, 0, alpha);
			break;
		default:
			spt->frameRender(frameCnt, 0, alpha);
			break;
	}
	
	if (KEYMANAGER->isStayKeyDown(VK_F1)) RECTMANAGER->render(rcName);

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
	for (int i = probeY - 10; i < probeY + 15; ++i)//Y축 탐지
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
			state = eIDLE;
			break;
		}
		else if(state!=eJUMP)
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

		if ((r == 0 && g == 255 && b == 255)) // 관통형 바닥
		{
			if (i >= ptX)
			{
				ptX = i - 20;
				dir = eLEFT;
				jmpspt->setScale({ -1,1 });
				amountX = -1;
				jmpspt->setScaleOffset(25, 0);
				spt->setScale({ -1,1 });
				spt->setScaleOffset(25, 0);
			}
			else if (i < ptX)
			{
				ptX = i + 20;
				dir = eRIGHT;
				jmpspt->setScale({ 1,1 });
				amountX = 1;
				spt->setScale({ 1,1 });
			}
			break;
		}
	}
	// x축 탐지
}
