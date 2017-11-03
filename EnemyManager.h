#pragma once
#include "DxWindow.h"
#include "EnemyMother.h"
#include "monkkey.h"
#include "Ent.h"
#include "Turtle.h"
#include "Bullet.h"
#include <vector>

//전방선언
class PlayerManager;
class stageManager;
class itemManager;

class EnemyManager : public DxWindow
{
	typedef vector<EnemyMother*> vEnemy;
	typedef vector<EnemyMother*>::iterator viEnemy;
private:
	
	vEnemy _vEnemy;
	viEnemy _viEnemy;

	int entNum;
<<<<<<< HEAD
	int monkkeyNum;
	int mushNum;
	int tutleNum;
=======
	int turtleNum;
	int turtlecNum;
	int kongNum;
>>>>>>> edf7b881d15513fe56d4a4a76a89b1919a850da4

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
	void deleteEnemy(void);


	//getter, setter
	inline void setLinkAdressPlayerManager(PlayerManager* pm) { _pm = pm; }
	inline void setLinkAdressStageManager(stageManager*   sm) { _sm = sm; }
	inline void setLinkAdressItemManager(itemManager*     im) { _im = im; }


	
};

