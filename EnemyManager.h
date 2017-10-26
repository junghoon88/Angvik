#pragma once
#include "DxWindow.h"

class EnemyManager : public DxWindow
{
public:
	EnemyManager();
	~EnemyManager();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

};

