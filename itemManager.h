#pragma once
#include "DxWindow.h"
#include "Item.h"


//���漱��
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
	viItems _viItems;

	int _x, _y;
	
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
	//���Ե� �������� 
	void setItem(float x, float y);

	//getter, setter
	inline void setLinkAdressPlayerManager(PlayerManager* pm) { _pm = pm; }
	inline void setLinkAdressEnemyManager(EnemyManager*   em) { _em = em; }
	inline void setLinkAdressStageManager(stageManager*   sm) { _sm = sm; }
	
	vector<Item*> getVItem(void) { return _vItems; }
	vector<Item*>::iterator getViItem(void) { return _viItems; }
	
};

