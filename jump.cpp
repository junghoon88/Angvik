#include "stdafx.h"
#include "jump.h"


jump::jump()
{
}


jump::~jump()
{
}


void jump::init()
{
	_isJumping = FALSE;
	_jumpPower = _gravity = 0;
}

void jump::release()
{

}

void jump::update()
{
	if (!_isJumping) return;

	*_y -= _jumpPower;
	_jumpPower -= _gravity;

	//if (_startY <= *_y)
	//{
	//	_isJumping = FALSE;
	//	*_y = _startY;
	//}
}

void jump::render()
{

}

void jump::jumping(float* x, float* y, float jumpPower, float gravity)
{
	if (_isJumping) return;

	_isJumping = TRUE;

	_x = x;
	_y = y;

	_startX = *x;
	_startY = *y;

	_gravity = gravity;
	_jumpPower = jumpPower;
}