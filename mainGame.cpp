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
	DxWindow* scene = SCENEMANAGER->addScene(L"�⺻��", new sceneInit);
	scene->init();
	scene = SCENEMANAGER->addScene(L"������", new sceneSelect);
	scene->init();
	scene = SCENEMANAGER->addScene(L"�׽�Ʈ��", new sceneStage);
	scene->init();
	scene = SCENEMANAGER->addScene(L"����", new sceneED);
	scene->init();
	SCENEMANAGER->changeScene(L"������");
}

void mainGame::release(void)
{
	DxWindow::releaseSingleton();
}

void mainGame::update(void)	
{
	if (KEYMANAGER->isOnceKeyDown(VK_F3)) DATABASE->setGameStart(false);

	SCENEMANAGER->update();

	if (DATABASE->getGameEnd()) SCENEMANAGER->changeScene(L"����");
	else if (DATABASE->getGameStart()) 	SCENEMANAGER->changeScene(L"�׽�Ʈ��");
	else							SCENEMANAGER->changeScene(L"������");
}

void mainGame::render(void)	
{
	SCENEMANAGER->render();

	//TIMEMANAGER->render();
}

