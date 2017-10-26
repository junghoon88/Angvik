#pragma once
#include "DxWindow.h"

class PlayerManager : public DxWindow
{
public:
	PlayerManager();
	~PlayerManager();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

