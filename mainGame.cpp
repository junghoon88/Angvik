#include "stdafx.h"
#include "mainGame.h"
#include "PrintText.h"


mainGame::mainGame(HINSTANCE hInstance, LPCWSTR className, LPCSTR lpCmdLine, int nCmdShow)
	: DxWindow(hInstance, className, lpCmdLine, nCmdShow)
{

}
mainGame::~mainGame()
{

}

void mainGame::init(void)	
{
	DxWindow::initialize();

	initScene();
}

void mainGame::initScene(void)
{
	DxWindow* scene = SCENEMANAGER->addScene(L"±âº»¾À", new sceneInit);
	scene->init();
	scene = SCENEMANAGER->addScene(L"¼¿·º¾À", new sceneSelect);
	scene->init();
	scene = SCENEMANAGER->addScene(L"°ÔÀÓ¾À", new sceneGame);
	scene->init();
	scene = SCENEMANAGER->addScene(L"Å×½ºÆ®¾À", new sceneStage);
	scene->init();
	scene = SCENEMANAGER->addScene(L"¿¡³Ê¹ÌÅ×½ºÆ®", new sceneET);
	scene->init();

	SCENEMANAGER->changeScene(L"¼¿·º¾À");
}

void mainGame::release(void)
{
	DxWindow::releaseSingleton();
}

void mainGame::update(void)	
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene(L"Å×½ºÆ®¾À");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene(L"°ÔÀÓ¾À");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F6))
	{
		SCENEMANAGER->changeScene(L"¼¿·º¾À");
	}

	SCENEMANAGER->update();

//	if (DATABASE->getGameStart()) 	SCENEMANAGER->changeScene(L"°ÔÀÓ¾À");
//	else							SCENEMANAGER->changeScene(L"¼¿·º¾À");

}

void mainGame::render(void)	
{
	SCENEMANAGER->render();

	//TIMEMANAGER->render();
}

