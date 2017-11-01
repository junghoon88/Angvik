#include "stdafx.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

void EnemyManager::init(void)
{

}
void EnemyManager::release(void)
{

}

void EnemyManager::update(void)	
{

}

void EnemyManager::render(void)	
{

}

void EnemyManager::setEnemy1(void)
{
	monkkey* monkey1, *monkey2;

	monkey1 = new monkkey;
	monkey2 = new monkkey;

	monkey1->init(600, 400);
	monkey2->init(1250, 400);

	_vEnemy.push_back(monkey1);
	_vEnemy.push_back(monkey2);

}