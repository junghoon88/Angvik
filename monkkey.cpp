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

	frameCnt = 0;
	frameTime = 0.0f;

}
void monkkey::update(void) {
	
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


}
void monkkey::move(void) {



}
void monkkey::attack(void) {



}