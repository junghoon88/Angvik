#pragma once
#include "DxWindow.h"

//전방선언
class PlayerManager;
class EnemyManager;
class itemManager;

class stageManager : public DxWindow
{
private:



	PlayerManager* _pm;
	EnemyManager* _em;
	itemManager* _im;

public:
	stageManager();
	~stageManager();

	void init(void);
	void release(void);
	void update(void);
	void render(void);



	//getter, setter
	inline void setLinkAdressPlayerManager(PlayerManager* pm) { _pm = pm; }
	inline void setLinkAdressEnemyManager(EnemyManager*   em) { _em = em; }
	inline void setLinkAdressItemManager(itemManager*     im) { _im = im; }

};

