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
	initText();
}


void sceneInit::initImage(void)
{
	IMAGEMANAGER->addImage(DEVICE, L"메인배경", L"image/etc/배경.png");
	IMAGEMANAGER->addFrameImage(DEVICE, L"선택", L"image/etc/선택.png", 8, 1);
}

void sceneInit::initSound(void)
{

}

void sceneInit::initText(void)
{

}

void sceneInit::release(void)
{

}

void sceneInit::update(void) 
{

}

void sceneInit::render(void) 
{

}
