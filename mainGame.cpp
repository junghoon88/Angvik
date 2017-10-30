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
	scene = SCENEMANAGER->addScene(L"���Ӿ�", new sceneGame);
	scene->init();
	scene = SCENEMANAGER->addScene(L"�׽�Ʈ��", new sceneTest);
	scene->init();
	scene = SCENEMANAGER->addScene(L"�������׽�Ʈ��", new sceneitemTest);
	scene->init();
	SCENEMANAGER->changeScene(L"�������׽�Ʈ��");
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

