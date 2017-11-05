#include "stdafx.h"
#include "EnemyMother.h"


EnemyMother::EnemyMother(){}
EnemyMother::~EnemyMother(){}

void EnemyMother::init(float x, float y)
{

}
void EnemyMother::init(int num, float x, float y, wstring rcKey)
{
	
}
void EnemyMother::release(void)
{

}
void EnemyMother::update(void) 
{

}
void EnemyMother::render(void) 
{

}
void EnemyMother::move(void)
{

}
bool EnemyMother::attack(void)
{
	return false;
}
void EnemyMother::RIP(void)
{
	if (life <= 0 && state != Death)
	{
		state = toDeath;
		amountTime += TIMEMANAGER->getElapsedTime();
		if (amountTime >= 0.075f)
		{
			amountTime = 0;
			amountY -= 0.2;
			rcHeight -= amountHeight / 20;
			ptY += amountHeight / 5;
			spt->setScale(amountX, amountY);
			spt->setCoord((float)rc.left,(float)rc.top);
			if (amountY <= 0)state = Death;
			
		}

	}
}