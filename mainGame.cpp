#include "stdafx.h"
#include "mainGame.h"


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
	SCENEMANAGER->addScene(L"±âº»¾À", new sceneInit);
	SCENEMANAGER->addScene(L"°ÔÀÓ¾À", new sceneGame);

	SCENEMANAGER->changeScene(L"±âº»¾À");
}

void mainGame::release(void)
{
	SCENEMANAGER->release();

	DxWindow::releaseSingleton();
}

void mainGame::update(void)	
{
	SCENEMANAGER->update();
}

void mainGame::render(void)	
{
	SCENEMANAGER->render();
}

