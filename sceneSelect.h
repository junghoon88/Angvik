#pragma once
#include "DxWindow.h"

class sceneSelect : public DxWindow
{
private:

public:
	sceneSelect();
	~sceneSelect();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

};

