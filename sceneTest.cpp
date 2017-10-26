#include "stdafx.h"
#include "sceneTest.h"

sceneTest::sceneTest()
{
}


sceneTest::~sceneTest()
{
}

void sceneTest::init(void)
{
	initImage();
	initSound();
	initText();

	frameCnt = 0;
	frameTime = 0.0f;
	angleDeg = 0.0f;

}

void sceneTest::initImage(void)
{
	IMAGEMANAGER->addImage(DEVICE, L"배경1", L"image/1.png");
	IMAGEMANAGER->addFrameImage(DEVICE, L"더미", L"image/dummy.png", 2, 3);
}

void sceneTest::initSound(void)
{

}

void sceneTest::initText(void)
{

}

void sceneTest::release(void)
{

}

void sceneTest::update(void)
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
		IMAGEMANAGER->setRotate(L"더미", angleDeg);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		angleDeg -= 3.0f;
		IMAGEMANAGER->setRotate(L"더미", angleDeg);
	}

	if (KEYMANAGER->isOnceKeyDown(MK_LBUTTON) && _ptMouse.x < 100 && _ptMouse.y < 100)
	{
		frameCnt++;
		if (frameCnt >= 6) frameCnt = 0;
	}

	IMAGEMANAGER->setCoord(L"더미", 100, 100);


}

void sceneTest::render(void)
{
	IMAGEMANAGER->findImage(L"배경1")->render();

	int frameX = frameCnt % 2;
	int frameY = frameCnt / 2;

	IMAGEMANAGER->findImage(L"더미")->frameRender(frameX, frameY);

}
