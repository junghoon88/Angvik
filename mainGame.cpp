#include "stdafx.h"
#include "mainGame.h"

mainGame::mainGame()
{

}


mainGame::~mainGame()
{

}
//푸쉬테스트트트트트타ㅡㅡ아ㅣ;ㄻ날어;ㄴㅁ
//초기화
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	initScene();



	return S_OK;
}

void mainGame::initScene(void)
{
	SCENEMANAGER->addScene(L"기본씬", new sceneInit);
}



//메모리 해제
void mainGame::release(void)
{
	gameNode::release();

	SCENEMANAGER->release();
}

//연산관련(타이머)
void mainGame::update(void)	
{
	gameNode::update();

	SCENEMANAGER->update();
}

//그려주는 함수
void mainGame::render(void)	
{
	//흰색 도화지 한 장 필요
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============================================================
	
	SCENEMANAGER->render();


	RENDERMANAGER->render();

	TIMEMANAGER->render(getMemDC());
	
	//========================================================================
	//백버퍼에 있는걸 HDC로 그려주는 역할
	this->getBackBuffer()->render(getHDC(), 0, 0);

}

