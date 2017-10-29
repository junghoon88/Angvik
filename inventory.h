#pragma once
#include "DxWindow.h"

class inventory : public DxWindow
{
public:
	inventory();
	~inventory();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

};

