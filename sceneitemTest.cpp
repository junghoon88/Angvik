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
	itemState = RIGHT_DONE;
	itemState2 = SWORD;
	oilState = WHITE_OIL;
	spt = IMAGEMANAGER->findImage(L"���Į");
	temp = IMAGEMANAGER->findImage(L"���Į");
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
	temp->setCoord(spt->getCoord());
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
			spt->setCoord(temp->getCoord());
			break;
		case STAFF:
			spt = IMAGEMANAGER->findImage(L"���������");
			spt->setCoord(temp->getCoord());
			break;
		case BOOMERANG:
			spt = IMAGEMANAGER->findImage(L"����θ޶�");
			spt->setCoord(temp->getCoord());
			break;
		}
		break;

	case BLACK_OIL:
		switch (itemState2)
		{
		case SWORD:
			spt = IMAGEMANAGER->findImage(L"��Į");
			spt->setCoord(temp->getCoord());
			break;
		case LANCE:
			spt = IMAGEMANAGER->findImage(L"������");
			spt->setCoord(temp->getCoord());
			break;
		case STAFF:
			spt = IMAGEMANAGER->findImage(L"��������");
			spt->setCoord(temp->getCoord());
			break;
		case BOOMERANG:
			spt = IMAGEMANAGER->findImage(L"���θ޶�");
			spt->setCoord(temp->getCoord());
			break;
		}
		break;
	case GOLD_OIL:
		switch (itemState2)
		{
		case  SWORD:
			spt = IMAGEMANAGER->findImage(L"���Į");
			spt->setCoord(temp->getCoord());
			break;
		case LANCE:
			spt = IMAGEMANAGER->findImage(L"��巣��");
			spt->setCoord(temp->getCoord());
			break;
		case STAFF:
			spt = IMAGEMANAGER->findImage(L"���������");
			spt->setCoord(temp->getCoord());
			break;
		case BOOMERANG:
			spt = IMAGEMANAGER->findImage(L"���θ޶�");
			spt->setCoord(temp->getCoord());
			break;
		}
		break;
	}
	////////////////////������ ��� /////////////////////////

	if (itemState2 == SWORD)
	{
		if (itemState == RIGHT_DONE)
		{
			spt->setRotate(80.0f);
		}
	}
	else if (itemState2 == LANCE)
	{
		if (itemState == RIGHT_DONE)
		{
			spt->setRotate(80.0f);
		}
	}
	else if (itemState2 == STAFF)
	{
		if (itemState == RIGHT_DONE)
		{
			spt->setRotate(80.0f);
		}
	}
	else if (itemState2 == BOOMERANG)
	{

		if (itemState == RIGHT_DONE)
		{
			spt->setRotate(80.0f);
		}
	}

	///////////////////����//////////////
	if (itemState2 == SWORD)
	{
		if (itemState == RIGHT_ATTACK)
		{

			spt->setRotate(spt->getAngle() - 7.0f);
			if (spt->getAngle() <= 0.0f)
			{
				itemState = RIGHT_DONE;
			}
		}
	}
	if (itemState2 == LANCE)
	{
		if (itemState == RIGHT_ATTACK)
		{
			spt->move(10, 0);

		}
	}
	if (itemState2 == STAFF)
	{
		spt->setRotate(spt->getAngle() - 5.0f);
		if (spt->getAngle() <= 70.0f)
		{
			itemState = RIGHT_DONE;
		}
	}
	if (itemState2 == BOOMERANG)
	{
		if (itemState == RIGHT_ATTACK)
		{
			spt->move(10, 0);

		}
	}


	if (angleDeg >= 360.f) angleDeg -= 360.0f;

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (itemState2 == SWORD)
		{
			if (itemState == RIGHT_DONE)
			{
				spt->setRotate(120.0f);
				itemState = RIGHT_ATTACK;
			}
		}
		else if (itemState2 == LANCE)
		{
			if (itemState == RIGHT_DONE)
			{
				spt->setRotate(0.0f);
				itemState = RIGHT_ATTACK;
			}
		}
		else if (itemState2 == STAFF)
		{
			if (itemState == RIGHT_DONE)
			{
				spt->setRotate(90.0f);
				itemState = RIGHT_ATTACK;
			}
		}
		else if (itemState2 == BOOMERANG)
		{
			if (itemState == RIGHT_DONE)
			{
				spt->setRotate(0.0f);
				itemState = RIGHT_ATTACK;
			}
		}
	}
	//////////////////////////////////////////////////////





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



	//IMAGEMANAGER->setRotate(L"���Į", angleDeg);
	spt->getCoord();
}

void sceneitemTest::render(void)
{
	int frameX = frameCnt % 2;
	int frameY = frameCnt / 2;



	IMAGEMANAGER->findImage(L"�׽�Ʈ���")->render();


	
	IMAGEMANAGER->findImage(L"Stage1-BG")->render();
		

	spt->render();
	//IMAGEMANAGER->findImage(L"������")->frameRender(frameCnt, 0);



}
