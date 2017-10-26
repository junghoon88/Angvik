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

	TEXTMANAGER->init(DEVICE, L"�׽�Ʈ");
	TEXTMANAGER->setFont(L"�׽�Ʈ", 20, L"����ü");

}

void mainGame::initScene(void)
{
	SCENEMANAGER->addScene(L"�⺻��", new sceneInit);
	SCENEMANAGER->addScene(L"���Ӿ�", new sceneGame);
	SCENEMANAGER->addScene(L"�׽�Ʈ��", new sceneTest);

	SCENEMANAGER->changeScene(L"�׽�Ʈ��");
}

void mainGame::release(void)
{
	SCENEMANAGER->release();

	DxWindow::releaseSingleton();
}

void mainGame::update(void)	
{
	SCENEMANAGER->update();

	TEXTMANAGER->addText(L"�׽�Ʈ", L"�׽�Ʈ1");
	TEXTMANAGER->addText(L"�׽�Ʈ", L"�׽�Ʈ2");
	TEXTMANAGER->addText(L"�׽�Ʈ", L"�׽�Ʈ3");
}

void mainGame::render(void)	
{
	SCENEMANAGER->render();

	//TIMEMANAGER->render();


	TEXTMANAGER->render(L"�׽�Ʈ");

}

