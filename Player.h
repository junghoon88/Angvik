#pragma once
#include "DxWindow.h"

class Player : public DxWindow
{
public:
	Player();
	~Player();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

};

