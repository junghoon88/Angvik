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
	itemState = SWORD_RIGHT_DONE;
	itemState2 = SWORD;
	oilState = WHITE_OIL;
	spt = IMAGEMANAGER->findImage(L"���Į");
	spt->setCoord({ 500, 200 });
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

	switch (oilState)
	{
	case WHITE_OIL:
		switch (itemState2)
		{
		case  SWORD:
			spt = IMAGEMANAGER->findImage(L"���Į");
			break;
		case LANCE:
			spt = IMAGEMANAGER->findImage(L"�������");
			break;
		case STAFF:
			spt = IMAGEMANAGER->findImage(L"���������");
			break;
		case BOOMERANG:
			spt = IMAGEMANAGER->findImage(L"����θ޶�");
			break;
		}
		break;

	case BLACK_OIL:
		switch (itemState2)
		{
		case SWORD:
			spt = IMAGEMANAGER->findImage(L"��Į");
			break;
		case LANCE:
			spt = IMAGEMANAGER->findImage(L"������");
			break;
		case STAFF:
			spt = IMAGEMANAGER->findImage(L"��������");
			break;
		case BOOMERANG:
			spt = IMAGEMANAGER->findImage(L"���θ޶�");
			break;
		}
		break;
	case GOLD_OIL:
		switch (itemState2)
		{
		case  SWORD:
			spt = IMAGEMANAGER->findImage(L"���Į");
			break;
		case LANCE:
			spt = IMAGEMANAGER->findImage(L"��巣��");
			break;
		case STAFF:
			spt = IMAGEMANAGER->findImage(L"���������");
			break;
		case BOOMERANG:
			spt = IMAGEMANAGER->findImage(L"���θ޶�");
			break;
		}
		break;
	}
////////////////////Į ��� /////////////////////////
	if (itemState == SWORD_RIGHT_DONE) angleDeg = 80.0f;
	else if (itemState == SWORD_LEFT_DONE) angleDeg = 110.0f;

	if (itemState == SWORD_RIGHT_ATTACK)
	{
			angleDeg -= 7.0f;
		if (angleDeg <= 0.0f)
		{
			itemState = SWORD_RIGHT_DONE;
		}
	}
	else if (itemState == SWORD_LEFT_ATTACK)
	{
		angleDeg += 7.0f;
		if (angleDeg >= 180.0f)
		{
			itemState = SWORD_LEFT_DONE;
		}
	}
	if (angleDeg >= 360.f) angleDeg -= 360.0f;
		
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (itemState == SWORD_RIGHT_DONE)
		{
			itemState = SWORD_RIGHT_ATTACK;
			angleDeg = 120.0f;
		}
		else if (itemState == SWORD_LEFT_DONE)
		{
			itemState = SWORD_LEFT_ATTACK;
			angleDeg = 70.0f;
		}
	
	}
//////////////////////////////////////////////////////
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		itemState = SWORD_LEFT_DONE;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		itemState = SWORD_RIGHT_DONE;
	}
	
	
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		spt->move(0, -10);
		
		//MAINCAMERA->moveCamera(DIRECTION_UP);
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		spt->move(0, 10);
		//MAINCAMERA->moveCamera(DIRECTION_DN);
	}
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		spt->move(-10, 0);
	//	MAINCAMERA->moveCamera(DIRECTION_LF);
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		spt->move(10, 0);
		//MAINCAMERA->moveCamera(DIRECTION_RG);
	}

	if (KEYMANAGER->isStayKeyDown('Z'))oilState = WHITE_OIL;
	if (KEYMANAGER->isStayKeyDown('X'))oilState = BLACK_OIL;
	if (KEYMANAGER->isStayKeyDown('C'))oilState = GOLD_OIL;
	if (KEYMANAGER->isStayKeyDown('V'))itemState2 = SWORD;
	if (KEYMANAGER->isStayKeyDown('B'))itemState2 = LANCE;
	if (KEYMANAGER->isStayKeyDown('N'))itemState2 = STAFF;
	if (KEYMANAGER->isStayKeyDown('M'))itemState2 = BOOMERANG;
	


	IMAGEMANAGER->setRotate(L"���Į", angleDeg);
	spt->getCoord();
}

void sceneitemTest::render(void)
{
	int frameX = frameCnt % 2;
	int frameY = frameCnt / 2;

	
	IMAGEMANAGER->findImage(L"�׽�Ʈ���")->render();
		
	spt->render();
	//IMAGEMANAGER->findImage(L"������")->frameRender(frameCnt, 0);
	


}
