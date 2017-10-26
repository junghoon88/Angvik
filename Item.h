#pragma once
#include "DxWindow.h"
class Item : public DxWindow
{
public:
	Item();
	~Item();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

