#pragma once
#include "DxWindow.h"

#define TREETRAP_MAX 11

//전방선언
class PlayerManager;
class EnemyManager;
class itemManager;

struct tagTreeTrap
{
	int num;
	Sprite* img;
	RECT rc;
	int dir; //1 : 왼쪽, -1 : 오른쪽

	int frameCnt;
	float frameTime;
	float frameFPS;
	
	float refreshTime;
	
	bool show;
};

class stageManager : public DxWindow
{
private:
	Sprite* _imgBackground;
	image* _imgPBG;

	tagTreeTrap _treeTrap[TREETRAP_MAX]; //1스테이지 나뭇가지 트랩

	RECT _rcHidden[2];
	bool _hiddenShow;


private:
	PlayerManager* _pm;
	EnemyManager* _em;
	itemManager* _im;

private:
	void frameUpdate(void);
	void hiddenCheck(void);

public:
	stageManager();
	~stageManager();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

	void GoNextStage(void);
	


	//getter, setter
	inline void setLinkAdressPlayerManager(PlayerManager* pm) { _pm = pm; }
	inline void setLinkAdressEnemyManager(EnemyManager*   em) { _em = em; }
	inline void setLinkAdressItemManager(itemManager*     im) { _im = im; }

	inline int getStage(void) { return _stage; }
	inline image* getCurPBG(void) { return _imgPBG; }

};

