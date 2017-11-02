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
	setEnemy1();
}
void EnemyManager::release(void)
{

}

void EnemyManager::update(void)	
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->update();
	}
}

void EnemyManager::render(void)	
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->render();
	}
}

void EnemyManager::setEnemy1(void)
{
	monkkey* monkey1, *monkey2;
	Ent* ent1;
	Turtle* turtle1;

	monkey1 = new monkkey;
	monkey2 = new monkkey;
	ent1 = new Ent;
	turtle1 = new Turtle;
	
	monkey1->init(192, 400);
	monkey2->init(192, 400);
	ent1->init(192, 415);//테스트용 좌표임
	turtle1->init(580, 415);

	_vEnemy.push_back(ent1);
	_vEnemy.push_back(monkey1);
	_vEnemy.push_back(monkey2);
	_vEnemy.push_back(turtle1);

}