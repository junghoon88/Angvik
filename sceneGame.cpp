#include "stdafx.h"
#include "sceneGame.h"

sceneGame::sceneGame()
{
}


sceneGame::~sceneGame()
{
}

void sceneGame::init(void)
{
	initImage();
	initSound();
	initText();
}

void sceneGame::release(void)
{

}

void sceneGame::update(void)
{

}

void sceneGame::render(void)
{

}

void sceneGame::initImage(void)
{
	IMAGEMANAGER->addImage(DEVICE, L"¹è°æ2", L"image/2.png");
}

void sceneGame::initSound(void)
{

}

void sceneGame::initText(void)
{

}
