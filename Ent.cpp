#include "stdafx.h"
#include "Ent.h"


Ent::Ent()
{
}


Ent::~Ent()
{
}


void Ent::init(float x, float y)
{
	spt = IMAGEMANAGER->findImage(L"나무맨");

	//마더클래스 프로브축 추가해야함.

	life = 1;
	ptX = x;
	ptY = y;

	rc = RectMakeCenter(x, y, 50, 70);

	probeY = rc.bottom;
}
void Ent::update(void)
{
	rc = RectMakeCenter(ptX, ptY, 50, 70);
	probeY = rc.bottom;

	move();
}
void Ent::render(void)
{

}
void Ent::move(void)  
{
	/*
	for (int i = probeY - 3; i < probeY; ++i)
	{
		//COLORREF color = PBGMANAGER->getPixelColor("테스트배경"), ptX, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 255 && g == 0 && b == 0)) // 관통형 바닥
		{
			ptY = i  + 1;
			break;
		}
		*/
}
void Ent::attack(void)
{

}