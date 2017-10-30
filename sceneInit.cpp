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
	IMAGEMANAGER->addImage(DEVICE, L"���ι��", L"image/etc/���.png");
	IMAGEMANAGER->addFrameImage(DEVICE, L"����", L"image/etc/����.png", 8, 1);
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
