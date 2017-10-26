#pragma once
#include "DxWindow.h"

class sceneInit : public DxWindow
{
private:
	void initImage(void);
	void initSound(void);

	//debug
	int frameCnt;
	float frameTime;

public:
	sceneInit();
	~sceneInit();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

