#include "stdafx.h"
#include "sceneED.h"

sceneED::sceneED(){}
sceneED::~sceneED(){}

void sceneED::init(void)
{
	number = 0;
	time = 0;
}
void sceneED::release(void)
{

}
void sceneED::update(void) 
{
	_mainCamera.x = 0;
	_mainCamera.y = 0;

	if (number <= 3)
	{
		time += TIMEMANAGER->getElapsedTime();
		if (time > 3.0f)
		{
			time = 0;
			number++;
		}
	}
	else if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{

		DATABASE->setGameEnd(false);
	}

}
void sceneED::render(void) 
{
	switch (number)
	{
	case 0:IMAGEMANAGER->findImage(L"엔딩배경1")->render();
		break;
	case 1:IMAGEMANAGER->findImage(L"엔딩배경2")->render();
		break;
	case 2:IMAGEMANAGER->findImage(L"엔딩배경3")->render();
		break;
	default:IMAGEMANAGER->findImage(L"엔딩배경3")->render();
		break;
	}
	IMAGEMANAGER->findImage(L"엔딩크레딧")->render();
}