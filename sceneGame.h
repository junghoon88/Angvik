#pragma once
#include "DxWindow.h"

class sceneGame : public DxWindow
{
private:
	void initImage(void);
	void initSound(void);

public:
	sceneGame();
	~sceneGame();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

