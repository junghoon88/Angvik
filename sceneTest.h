#pragma once
#include "DxWindow.h"

class sceneTest : public DxWindow
{
private:
	void initImage(void);
	void initSound(void);
	void initText(void);

	//debug
	int frameCnt;
	float frameTime;
	float angleDeg;

public:
	sceneTest();
	~sceneTest();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

