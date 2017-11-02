#pragma once
#include "DxWindow.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "stageManager.h"
#include "itemManager.h"

class sceneGame : public DxWindow
{
private:
	PlayerManager* _pm;
	EnemyManager* _em;
	stageManager* _sm;
	itemManager* _im;

	bool _musicStart;

public:
	sceneGame();
	~sceneGame();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

