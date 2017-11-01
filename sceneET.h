#pragma once
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "stageManager.h"
#include "itemManager.h"

class sceneET : public DxWindow
{
private:
	PlayerManager* _pm;
	EnemyManager* _em;
	stageManager* _sm;
	itemManager* _im;


public:
	void init(void);
	void release(void);
	void update(void);
	void render(void);


	sceneET();
	~sceneET();

};

