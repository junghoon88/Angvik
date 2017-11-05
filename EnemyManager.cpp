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
//	entBeam = new Entbeam;
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
		if ((*_viEnemy)->getState() == Death) {

			if ((*_viEnemy)->getIndex() == 3) {
				Turtle_crash* cturtle;
				cturtle = new Turtle_crash;
				cturtle->init(turtleNum++, (*_viEnemy)->getX()-10, (*_viEnemy)->getY()-30,L"cturtlerc");
				_vEnemy.push_back(cturtle);
				mush* cmush;
				cmush = new mush;
				cmush->init(mushNum++, (*_viEnemy)->getX()+10, (*_viEnemy)->getY()-30, L"cmushrc");
				_vEnemy.push_back(cmush);
			}

			int droptable = 0;
			droptable = RND->getInt(10);//드랍확률
			if(droptable <= 3) _im->setItem((*_viEnemy)->getX(), (*_viEnemy)->getY() - 30);

			deleteEnemy(_viEnemy);
			break;
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
			else if (type == 4)
			{

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

	////////////////////////////몽키세팅
	monkkey* monkey1, *monkey2, *monkey3, *monkey4, *monkey5;
	//monkey1 = new monkkey;
	//monkey1->init(monkkeyNum++, 617, 390, L"monkeyRc1");
	//_vEnemy.push_back(monkey1);

	monkey2 = new monkkey;
	monkey2->init(monkkeyNum++, 1260, 420,L"monkkeyRc2");
	_vEnemy.push_back(monkey2);

	monkey3 = new monkkey;
	monkey3->init(monkkeyNum++, 1773, 212, L"monkkeyRc3");
	_vEnemy.push_back(monkey3);

	monkey4 = new monkkey;
	monkey4->init(monkkeyNum++, 2540, 90, L"monkkeyRc4");
	_vEnemy.push_back(monkey4);

	//monkey5 = new monkkey;
	//monkey5->init(monkkeyNum++, 5580, 885, L"monkkeyRc5");
	//_vEnemy.push_back(monkey5);

	/////////////////////////////////////
	mush* mush1;
	mush1 = new mush;
	mush1->init(mushNum++, 3790, 200, L"mushRc1");
	_vEnemy.push_back(mush1);



	///////////////////////////////엔트세팅
	Ent* ent1;    
	ent1 = new Ent;
	ent1->init(entNum++, 3090, 700, L"EntRc1");
	_vEnemy.push_back(ent1);

	Ent* ent2;
	ent2 = new Ent;
	ent2->init(entNum++, 3240, 250, L"EntRc2");
	_vEnemy.push_back(ent2);
	////////////////////////////////////////////



	//////////////////////////////콩세팅
	kong* kong1, *kong2, *kong3;
	kong1 = new kong;
	kong1->init(kongNum++, 2975, 553, L"kongRc1");
	_vEnemy.push_back(kong1);

	kong2 = new kong;
	kong2->init(kongNum++, 1995, 327, L"kongRc2");
	_vEnemy.push_back(kong2);

	kong3 = new kong;
	kong3->init(kongNum++, 4895, 790, L"kongRc3");
	_vEnemy.push_back(kong3);
	//////////////////////////////////



	///////////////////////////////거북이세팅
	Turtle* turtle1, *turtle2;
	turtle1 = new Turtle;  
	turtle1->init(turtleNum++,4150, 800, L"TurRc1");
	_vEnemy.push_back(turtle1);

	turtle2 = new Turtle;  
	turtle2->init(turtleNum++, 4160, 385, L"TurRc2");
	_vEnemy.push_back(turtle2);
	/////////////////////////////////

}
void EnemyManager::deleteEnemy(int arrNum) {

	//SAFE_DELETE(_vEnemy[arrNum]);
	_vEnemy.erase(_vEnemy.begin() + arrNum);

}
void EnemyManager::deleteEnemy(viEnemy viE) {
	_vEnemy.erase(viE);
}