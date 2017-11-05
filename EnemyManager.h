#pragma once
#include "DxWindow.h"
#include "EnemyMother.h"
#include "monkkey.h"
#include "Ent.h"
#include "Turtle.h"
#include "mush.h"
#include "kong.h"
#include "Bullet.h"
#include <vector>

//전방선언
class PlayerManager;
class stageManager;
class itemManager;
class sBMR;

class EnemyManager : public DxWindow
{
	typedef vector<EnemyMother*> vEnemy;
	typedef vector<EnemyMother*>::iterator viEnemy;
private:
	
	vEnemy _vEnemy;
	viEnemy _viEnemy;

	sBMR* sBmr;
	Kongtan* kongTan;

	int monkkeyNum;
	int mushNum;

	int entNum;
	int turtleNum;
	int turtlecNum;
	int kongNum;

	int bulletNum;

private:
	PlayerManager* _pm;
	stageManager* _sm;
	itemManager* _im;

public:
	EnemyManager();
	~EnemyManager();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

	void setEnemy1(void);
	void enemyFire(void);
	void deleteEnemy(int arrNum);
	void deleteEnemy(viEnemy viE);
	
	//getter, setter
	inline void setLinkAdressPlayerManager(PlayerManager* pm) { _pm = pm; }
	inline void setLinkAdressStageManager(stageManager*   sm) { _sm = sm; }
	inline void setLinkAdressItemManager(itemManager*     im) { _im = im; }
	inline void setLinkAdresssBMR(sBMR* sBMR) { sBmr = sBMR; }

	inline vEnemy getvEnemy(void) { return _vEnemy; }
	inline viEnemy getviEnemy(void) { return _viEnemy; }
	
	Kongtan* getKongtan() { return kongTan; }
	sBMR* getSbmr() { return sBmr; }

};

