#pragma once
#include "DxWindow.h"

class inven : public DxWindow
{
private:
	bool _isMenew;
	bool _isItem;
	bool _isOils;

public:
	inven();
	~inven();

	void init(void);
	void release(void);
	void update(void);
	void update(float x, float y);
	void render(void);
};

