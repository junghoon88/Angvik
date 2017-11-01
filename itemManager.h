#pragma once
#include "DxWindow.h"
#include "Item.h"


//전방선언
class PlayerManager;
class EnemyManager;
class stageManager;

class itemManager : public DxWindow
{
private:
	typedef vector<Item*> vItems;
	typedef vector<Item*>::iterator viItems;

private:
	vItems _vItems;



private:
	PlayerManager* _pm;
	EnemyManager* _em;
	stageManager* _sm;

public:
	itemManager();
	~itemManager();

	void init(void);
	void release(void);
	void update(void);
	void render(void);


	//getter, setter
	inline void setLinkAdressPlayerManager(PlayerManager* pm) { _pm = pm; }
	inline void setLinkAdressEnemyManager(EnemyManager*   em) { _em = em; }
	inline void setLinkAdressStageManager(stageManager*   sm) { _sm = sm; }

};

