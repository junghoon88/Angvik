#include "stdafx.h"
#include "monkkey.h"


monkkey::monkkey()
{
}


monkkey::~monkkey()
{

}
void monkkey::init(float x, float y) {

	spt = IMAGEMANAGER->findImage(L"¿ø¼þÀÌ");

	life = 1;
	ptX = x;
	ptY = y;

	spt->setCoord({ 0,0 });

	dir = eRIGHT;
	state = eIDLE;

	frameCnt = spt->getMaxFrameX();
	frameTime = 0;

	rc = RectMakeCenter(ptX, ptY, 100, 60);
	RECTMANAGER->addRect(DEVICE, L"monkey1rc", { (float)rc.left,(float)rc.top }, { 70, 70 });
	probeY = rc.bottom;

}
void monkkey::update(void) {
	
	spt->setCoord({(float)rc.left,(float)rc.top });

	frameTime += TIMEMANAGER->getElapsedTime();
	if (frameTime >= 0.2f)
	{
		frameTime -= 0.2f;

		frameCnt++;
		if (frameCnt >= 8) frameCnt = 0;
	}
	move();
	

}
void monkkey::render(void) {

	spt->frameRender(frameCnt, 0);
	
	RECTMANAGER->render(L"monkey1rc");

}
void monkkey::move(void) {



}
void monkkey::attack(void) {



}