#include "stdafx.h"
#include "playerSceneTest.h"


playerSceneTest::playerSceneTest()
{
}


playerSceneTest::~playerSceneTest()
{
}


void playerSceneTest::init(void)
{
	initImage();
	initSound();
	initText();

	_pm = new PlayerManager;
	_pm->init();
}


void playerSceneTest::initImage(void)
{
}

void playerSceneTest::initSound(void)
{
}

void playerSceneTest::initText(void) 
{
}


void playerSceneTest::release(void)
{

}
void playerSceneTest::update(void)
{

}
void playerSceneTest::render(void)
{

}