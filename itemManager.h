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

	int itemNum;

	int _x, _y;
	int i, j;
	bool issetting;

	
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
	void render(void)
		;
	//���Ե� �������� 
	void setItem(float x, float y);
	////////////////////////
	void setFieldItem(int i, int j);
	void removeItem(int arrNum);

	

	void Itemcompose(int itemNum, int oilNum);//�ռ�

	//getter, setter
	inline void setLinkAdressPlayerManager(PlayerManager* pm) { _pm = pm; }
	inline void setLinkAdressEnemyManager(EnemyManager*   em) { _em = em; }
	inline void setLinkAdressStageManager(stageManager*   sm) { _sm = sm; }
	
	vector<Item*> getVItem(void) { return _vItems; }
	vector<Item*>::iterator getViItem(void) { return _viItems; }
	
};

