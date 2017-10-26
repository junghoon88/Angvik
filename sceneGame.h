#pragma once
#include "DxWindow.h"

class sceneGame : public DxWindow
{
private:

private:
	void initImage(void);
	void initSound(void);
	void initText(void);

public:
	sceneGame();
	~sceneGame();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

