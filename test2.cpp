#include "stdafx.h"
#include "test2.h"


test2::test2()
{
}


test2::~test2()
{
}

void test2::init(void)
{
	_bird = new invenBird;
	_bird->init();
}

void test2::release(void)
{

}

void test2::update(void)
{
	_bird->update();
}

void test2::render(void)
{
	_bird->render();
}

