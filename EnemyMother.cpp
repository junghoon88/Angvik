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
	if (life <= 0 && state != toDeath)
	{
		amountTime += TIMEMANAGER->getElapsedTime();
		if (amountTime >= 0.2f)
		{
			amountY -= 0.1;
			rcHeight -= amountHeight / 10;
			spt->setScale(1, amountY);
			if (amountY < 0)state == toDeath;
		}

	}
}