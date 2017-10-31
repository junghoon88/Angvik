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

}
void Ent::attack(void)
{

}