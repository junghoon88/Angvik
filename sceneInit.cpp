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
	IMAGEMANAGER->addImage(device, L"���ι��", L"image/etc/���.png", WINSIZEX, WINSIZEY);
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
