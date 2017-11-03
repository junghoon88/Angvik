#include "stdafx.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	entNum = 0;
	turtleNum = 0;
	turtlecNum = 0;
	kongNum = 0;
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
	Turtle* turtle1;

	monkey1 = new monkkey;
	//monkey2 = new monkkey;

	Ent* ent1;
	ent1 = new Ent;
	ent1->init(entNum++, 192, 415);//테스트용 좌표임
	_vEnemy.push_back(ent1);

	Ent* ent2;
	ent2 = new Ent;
	ent2->init(entNum++, 192, 200);//테스트용 좌표임
	_vEnemy.push_back(ent2);

	monkey1->init(590,200,L"monkeyRc1");
//	monkey2->init(192, 400);

	turtle1 = new Turtle;
	turtle1->init(turtleNum++,580, 415);

	_vEnemy.push_back(monkey1);
//	_vEnemy.push_back(monkey2);
	_vEnemy.push_back(turtle1);

}
