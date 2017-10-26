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

	TEXTMANAGER->init(DEVICE, L"테스트");
	TEXTMANAGER->setFont(L"테스트", 20, L"돋움체");

}

void mainGame::initScene(void)
{
	SCENEMANAGER->addScene(L"기본씬", new sceneInit);
	SCENEMANAGER->addScene(L"게임씬", new sceneGame);
	SCENEMANAGER->addScene(L"테스트씬", new sceneTest);

	SCENEMANAGER->changeScene(L"테스트씬");
}

void mainGame::release(void)
{
	SCENEMANAGER->release();

	DxWindow::releaseSingleton();
}

void mainGame::update(void)	
{
	SCENEMANAGER->update();

	TEXTMANAGER->addText(L"테스트", L"테스트1");
	TEXTMANAGER->addText(L"테스트", L"테스트2");
	TEXTMANAGER->addText(L"테스트", L"테스트3");
}

void mainGame::render(void)	
{
	SCENEMANAGER->render();

	//TIMEMANAGER->render();


	TEXTMANAGER->render(L"테스트");

}

