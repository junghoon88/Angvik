#pragma once
#include "DxWindow.h"
#include "sceneInit.h"
#include "sceneGame.h"


class mainGame : public DxWindow
{
private:
	void initScene(void);

public:
	mainGame(HINSTANCE hInstance, LPCWSTR className, LPCSTR lpCmdLine, int nCmdShow);
	~mainGame();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

};

