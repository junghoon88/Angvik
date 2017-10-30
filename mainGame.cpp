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
	scene = SCENEMANAGER->addScene(L"Å×½ºÆ®¾À", new sceneTest);
	scene->init();

<<<<<<< HEAD
	SCENEMANAGER->changeScene(L"¼¿·º¾À");
=======
	SCENEMANAGER->changeScene(L"Å×½ºÆ®¾À");
>>>>>>> 383a20fe0a84cf08da9b913d89fe5e28246e1215
}

void mainGame::release(void)
{
	DxWindow::releaseSingleton();
}

void mainGame::update(void)	
{
	SCENEMANAGER->update();

}

void mainGame::render(void)	
{
	SCENEMANAGER->render();

	//TIMEMANAGER->render();
}

