#pragma once
#include "DxWindow.h"
class sceneitemTest : public DxWindow
{
private:


	//debug
	int frameCnt;
	float frameTime;
	float angleDeg;

public:
	sceneitemTest();
	~sceneitemTest();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

