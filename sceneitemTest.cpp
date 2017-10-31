#include "stdafx.h"
#include "sceneitemTest.h"


sceneitemTest::sceneitemTest()
{
}


sceneitemTest::~sceneitemTest()
{
}

void sceneitemTest::init(void)
{
	

	frameCnt = 0;
	frameTime = 0.0f;
	angleDeg = 0.0f;

}


void sceneitemTest::release(void)
{

}

void sceneitemTest::update(void)
{
	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.2f)
	{
		frameTime -= 0.2f;
	
		frameCnt++;
		if (frameCnt >= 8) frameCnt = 0;
	}
	
	if (KEYMANAGER->isStayKeyDown(VK_RETURN))
	{
		IMAGEMANAGER->move(L"���Į", 10, 0);
		//IMAGEMANAGER->move(L"����2", 10, 0);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		static int dir = 1;
		dir *= -1;
		IMAGEMANAGER->setScale(L"���Į", dir, 1);
		IMAGEMANAGER->setScale(L"���Į", dir, 1);
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		//center�� ī�޶� �ɼ� ���ؾ���
		angleDeg += 3.0f;
		IMAGEMANAGER->setRotate(L"���Į", angleDeg);
		IMAGEMANAGER->setRotate(L"���Į", angleDeg);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		angleDeg -= 3.0f;
		IMAGEMANAGER->setRotate(L"���Į", angleDeg);
		IMAGEMANAGER->setRotate(L"���Į", angleDeg);
	}

	if (KEYMANAGER->isOnceKeyDown(MK_LBUTTON) && _ptMouse.x < 100 && _ptMouse.y < 100)
	{
		frameCnt++;
		if (frameCnt >= 8) frameCnt = 0;
	}

	if (KEYMANAGER->isStayKeyDown('W'))
	{
		IMAGEMANAGER->move(L"������", 0, -10);
		//MAINCAMERA->moveCamera(DIRECTION_UP);
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		IMAGEMANAGER->move(L"������", 0, 10);
		//MAINCAMERA->moveCamera(DIRECTION_DN);
	}
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		IMAGEMANAGER->move(L"������", -10, 0);
	//	MAINCAMERA->moveCamera(DIRECTION_LF);
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		IMAGEMANAGER->move(L"������", 10, 0);
		//MAINCAMERA->moveCamera(DIRECTION_RG);
	}

	if (KEYMANAGER->isOnceKeyDown('T'))
	{

	}

	Sprite* imgdummy = IMAGEMANAGER->findImage(L"����");
	Rect* rcdummy = RECTMANAGER->findRect(L"����");
	rcdummy->setCoord(imgdummy->getCoord());
	rcdummy->setSize(imgdummy->getSize());
	rcdummy->setScale(&imgdummy->getScale());
	rcdummy->setCenterPos(imgdummy->getCenter());
	rcdummy->setRotate(imgdummy->getAngle());

	float anglexx = imgdummy->getAngle();


	TCHAR str[200];
	_stprintf(str, L"camera X = %d, camera Y = %d", _mainCamera.x, _mainCamera.y);
	TEXTMANAGER->addText(L"�׽�Ʈ", str);
	_stprintf(str, L"imgdummy center X = %d, Y = %d", imgdummy->getCenter().x, imgdummy->getCenter().y);
	TEXTMANAGER->addText(L"�׽�Ʈ", str);
	_stprintf(str, L"rcdummy center X = %d, Y = %d", rcdummy->getCenter().x, rcdummy->getCenter().y);
	TEXTMANAGER->addText(L"�׽�Ʈ", str);

	_stprintf(str, L"angle = %d, %d", (int)imgdummy->getAngle(), (int)rcdummy->getAngle());
	TEXTMANAGER->addText(L"�׽�Ʈ", str);

}

void sceneitemTest::render(void)
{
	int frameX = frameCnt % 2;
	int frameY = frameCnt / 2;

	IMAGEMANAGER->findImage(L"�׽�Ʈ���")->render();
	//IMAGEMANAGER->findImage(L"����")->frameRender(frameX, frameX);
	IMAGEMANAGER->findImage(L"������")->frameRender(frameCnt, 0);
	
	//RECTMANAGER->findRect(L"����")->render();
	//
	//TEXTMANAGER->render(L"�׽�Ʈ");

}
