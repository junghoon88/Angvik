#pragma once
#include "DxWindow.h"

class inven : public DxWindow
{
private:
	D3DXVECTOR2 _invenPoint;

public:
	inven();
	~inven();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

