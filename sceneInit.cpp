#include "stdafx.h"
#include "sceneInit.h"

sceneInit::sceneInit()
{
}


sceneInit::~sceneInit()
{
}

void sceneInit::init(void)
{
	initImage();
	initSound();


	frameCnt = 0;
	frameTime = 0.0f;
	angleDeg = 0.0f;

}

void sceneInit::release(void)
{

}

void sceneInit::update(void) 
{
	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.2f)
	{
		frameTime -= 0.2f;

		frameCnt++;
		if (frameCnt >= 6) frameCnt = 0;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		angleDeg += 3.0f;
		IMAGEMANAGER->setRotate(L"����", angleDeg);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		angleDeg -= 3.0f;
		IMAGEMANAGER->setRotate(L"����", angleDeg);
	}

	if (KEYMANAGER->isOnceKeyDown(MK_LBUTTON) && _ptMouse.x < 100 && _ptMouse.y < 100)
	{
		frameCnt++;
		if (frameCnt >= 6) frameCnt = 0;
	}

	IMAGEMANAGER->setCoord(L"����", 100, 100);


}

void sceneInit::render(void) 
{
	IMAGEMANAGER->findImage(L"���1")->render();

	int frameX = frameCnt % 2;
	int frameY = frameCnt / 2;

	IMAGEMANAGER->findImage(L"����")->frameRender(frameX, frameY);

}

void sceneInit::initImage(void)
{
	IMAGEMANAGER->addImage(DEVICE, L"���1", L"image/1.png");
	IMAGEMANAGER->addFrameImage(DEVICE, L"����", L"image/dummy.png", 2, 3);
}

void sceneInit::initSound(void)
{

}
