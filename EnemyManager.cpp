#include "stdafx.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	entNum = 0;
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
<<<<<<< HEAD
	EnemyMother* ent1, *ent2;
	Turtle* turtle1;

	monkey1 = new monkkey;
	monkey2 = new monkkey;
	ent1 = new Ent;
	ent2 = new Ent;
=======
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

>>>>>>> 87fb64677be62a0f29f5cbbd04faace4d1246048
	turtle1 = new Turtle;
	
	monkey1->init(590,200,L"monkeyRc1");
//	monkey2->init(192, 400);
<<<<<<< HEAD

	ent1->init(192, 415);//테스트용 좌표임
	_vEnemy.push_back(ent1);
	ent2->init(192, 100);
	_vEnemy.push_back(ent2);
	turtle1->init(580, 415);



=======
	turtle1->init(580, 415);

>>>>>>> 87fb64677be62a0f29f5cbbd04faace4d1246048
	_vEnemy.push_back(monkey1);
	_vEnemy.push_back(monkey2);
	_vEnemy.push_back(turtle1);

}
