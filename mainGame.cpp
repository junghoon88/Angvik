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
	scene = SCENEMANAGER->addScene(L"Å×½ºÆ®¾À", new sceneStage);
	scene->init();
	scene = SCENEMANAGER->addScene(L"¿£µù", new sceneED);
	scene->init();
	SCENEMANAGER->changeScene(L"¼¿·º¾À");
}

void mainGame::release(void)
{
	DxWindow::releaseSingleton();
}

void mainGame::update(void)	
{
	if (KEYMANAGER->isOnceKeyDown(VK_F3)) DATABASE->setGameStart(false);

	SCENEMANAGER->update();

	if (DATABASE->getGameEnd()) SCENEMANAGER->changeScene(L"¿£µù");
	else if (DATABASE->getGameStart()) 	SCENEMANAGER->changeScene(L"Å×½ºÆ®¾À");
	else							SCENEMANAGER->changeScene(L"¼¿·º¾À");
}

void mainGame::render(void)	
{
	SCENEMANAGER->render();

	//TIMEMANAGER->render();
}

