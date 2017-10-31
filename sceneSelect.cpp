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
	_startRECT = RectMake(265, 380, 70, 20);
	RECTMANAGER->addRect(DEVICE, L"����", { 265, 380 }, { 70, 20 }, RGB(0, 0, 0), 255);
	RECTMANAGER->addRect(DEVICE, L"�ɼ�", { 455, 380 }, { 90, 22 }, RGB(0, 0, 0), 255);
	RECTMANAGER->addRect(DEVICE, L"������", { 675, 380 }, { 50, 20 }, RGB(0, 0, 0), 255);
	//455, 380
	//675, 380

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
	if (_frameX > IMAGEMANAGER->findImage(L"����")->getMaxFrameX()) _frameX = 0;
	IMAGEMANAGER->findImage(L"����")->setCoord({ 215, 375 });
}

void sceneSelect::render(void)
{
	IMAGEMANAGER->findImage(L"���ι��")->render();
	IMAGEMANAGER->findImage(L"����")->frameRender(_frameX, 0);
	RECTMANAGER->findRect(L"����")->render();
	RECTMANAGER->findRect(L"�ɼ�")->render();
	RECTMANAGER->findRect(L"������")->render();
}


