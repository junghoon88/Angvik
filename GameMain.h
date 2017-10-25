#pragma once
#include "DxWindow.h"


class GameMain : public DxWindow
{
private:


public:
	GameMain(HINSTANCE hInstance, LPCWSTR className, LPCSTR lpCmdLine, int nCmdShow);
	~GameMain();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

};

