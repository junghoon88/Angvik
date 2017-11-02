#pragma once
#include "DxWindow.h"
#include "invenBird.h"

class test2 :	public DxWindow
{
private:
	invenBird* _bird;

public:
	void init(void);
	void release(void);
	void update(void);
	void render(void);

	test2();
	~test2();
};

