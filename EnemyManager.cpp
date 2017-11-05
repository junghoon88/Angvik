#include "stdafx.h"
#include "EnemyManager.h"
#include "PlayerManager.h"
#include "itemManager.h"

EnemyManager::EnemyManager()
{
	monkkeyNum = 0;
	mushNum = 0;

	entNum = 0;
	turtleNum = 0;
	turtlecNum = 0;
	kongNum = 0;

	bulletNum = 0;
}


EnemyManager::~EnemyManager()
{
}

void EnemyManager::init(void)
{
	setEnemy1();
	kongTan = new Kongtan;
	kongTan->init();
	sBmr = new sBMR;
	sBmr->init();
	sBmr->setLinkAdressEnemyManager(this);
}
void EnemyManager::release(void)
{

}

void EnemyManager::update(void)	
{
	
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->update();
		if ((*_viEnemy)->getIndex() == 1 || (*_viEnemy)->getIndex() == 2) {
			(*_viEnemy)->setPlayerX(_pm->getPlayer()->getX());
			(*_viEnemy)->setPlayerY(_pm->getPlayer()->getY());
		}
	}
	enemyFire();
	kongTan->update();
	sBmr->update();
}
void EnemyManager::enemyFire(void)
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		if ((*_viEnemy)->getAtk())
		{
			int type = (*_viEnemy)->getIndex();
			float emX = (*_viEnemy)->getX(); 
			float emY = (*_viEnemy)->getY();
			float plX = _pm->getPlayer()->getX();
			float plY = _pm->getPlayer()->getY(); 
			float angle = getAngle(emX, emY, plX, plY); //가독성을 위해 일케함.

			if (type == 1)
			{
				sBmr->fire(bulletNum++, emX, emY, angle);
				(*_viEnemy)->setAtk(false);
				(*_viEnemy)->setState(eIDLE);

			}
			else if (type == 2)
			{
				kongTan->fire(bulletNum++, emX, emY, angle);
				(*_viEnemy)->setAtk(false);
			}
		}
	}
}
void EnemyManager::render(void)	
{
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{
		(*_viEnemy)->render();
	}
	kongTan->render();
	sBmr->render();
}

void EnemyManager::setEnemy1(void)
{
	monkkey* monkey1, *monkey2;
	Turtle* turtle1;
	mush* mush1;


	monkey2 = new monkkey;
	monkey2->init(monkkeyNum++, 200, 100,L"monkkeyRc2");
	_vEnemy.push_back(monkey2);


	mush1 = new mush;
	mush1->init(mushNum++, 1000, 50, L"mushRc1");
	_vEnemy.push_back(mush1);


	monkey1 = new monkkey;
	monkey1->init(monkkeyNum++, 590, 200, L"monkeyRc1");
	_vEnemy.push_back(monkey1);

	Ent* ent1;
	ent1 = new Ent;
	ent1->init(entNum++, 192, 415);//테스트용 좌표임
	_vEnemy.push_back(ent1);

	Ent* ent2;
	ent2 = new Ent;
	ent2->init(entNum++, 192, 200);//테스트용 좌표임
	_vEnemy.push_back(ent2);

	kong* kong1;
	kong1 = new kong;
	kong1->init(kongNum++, 860, 350);
	_vEnemy.push_back(kong1);
	//350,860 콩나물 위치
	
	turtle1 = new Turtle;
	turtle1->init(turtleNum++,580, 415);
	_vEnemy.push_back(turtle1);

}
void EnemyManager::deleteEnemy(void) {



}