#include "stdafx.h"
#include "sceneSelect.h"


sceneSelect::sceneSelect()
{
}


sceneSelect::~sceneSelect()
{
}


void sceneSelect::init(void)
{
	_frameX = 0;
	_countTime = 0;
}

void sceneSelect::release(void)
{

}

void sceneSelect::update(void)
{
	_countTime += TIMEMANAGER->getElapsedTime();
	if (_countTime >= 0.07)
	{
		_frameX++;
		_countTime = 0;
	}
	if (_frameX == 9) _frameX = 0;
	IMAGEMANAGER->findImage(L"����")->setCoord({ 0,0 });
}

void sceneSelect::render(void)
{
	IMAGEMANAGER->findImage(L"���ι��")->render();
	IMAGEMANAGER->findImage(L"����")->frameRender(_frameX, 0);
}


