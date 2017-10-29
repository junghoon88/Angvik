#pragma once
#include "DxWindow.h"

class invenBird : public DxWindow
{
public:
	invenBird();
	~invenBird();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

};

