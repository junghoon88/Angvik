#pragma once
#include "DxWindow.h"

class Interface : public DxWindow
{
public:
	Interface();
	~Interface();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

};

