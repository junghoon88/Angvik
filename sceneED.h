#pragma once
#include "DxWindow.h"

class sceneED : public DxWindow
{
private:
	int number;
	float time;


public:
	void init(void);
	void release(void);
	void update(void);
	void render(void);

	sceneED();
	~sceneED();
};

