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
	scene = SCENEMANAGER->addScene(L"���ʹ��׽�Ʈ", new sceneET);
	scene->init();
	scene = SCENEMANAGER->addScene(L"�κ��׽�Ʈ", new invenBird);
	scene->init();

	SCENEMANAGER->changeScene(L"�׽�Ʈ��");
}

void mainGame::release(void)
{
	DxWindow::releaseSingleton();
}

void mainGame::update(void)	
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		SCENEMANAGER->changeScene(L"�׽�Ʈ��");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		SCENEMANAGER->changeScene(L"���Ӿ�");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		SCENEMANAGER->changeScene(L"�������׽�Ʈ��");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		SCENEMANAGER->changeScene(L"���ʹ��׽�Ʈ");
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F5))
	{
		SCENEMANAGER->changeScene(L"������");
	}

	SCENEMANAGER->update();

}

void mainGame::render(void)	
{
	SCENEMANAGER->render();

	//TIMEMANAGER->render();
}

