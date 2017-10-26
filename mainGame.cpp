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
	SCENEMANAGER->addScene(L"기본씬", new sceneInit);
	SCENEMANAGER->addScene(L"게임씬", new sceneGame);

	SCENEMANAGER->changeScene(L"기본씬");
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

	//TIMEMANAGER->render();

	TEXTMANAGER->init(DEVICE, L"테스트");
	TEXTMANAGER->setFont(L"테스트", 20, L"돋움체");
	TEXTMANAGER->addText(L"테스트", L"테스트1");
	TEXTMANAGER->addText(L"테스트", L"테스트2");
	TEXTMANAGER->addText(L"테스트", L"테스트3");
	TEXTMANAGER->render(L"테스트");

}

