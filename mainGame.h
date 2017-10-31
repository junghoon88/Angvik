#pragma once
#include "DxWindow.h"
#include "sceneInit.h"
#include "sceneSelect.h"
#include "sceneGame.h"
#include "sceneTest.h"

#include "sceneitemTest.h"

#include "playerSceneTest.h"



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

