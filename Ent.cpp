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
}
void Ent::update(void)
{

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