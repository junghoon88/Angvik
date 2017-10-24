#pragma once
#include "gameNode.h"
#include "sceneInit.h"
#include "sceneSelect.h"
#include "sceneGame.h"

class mainGame : public gameNode
{
private:

private:
	void initScene(void);

public:
	virtual HRESULT init(void);		//초기화
	virtual void release(void);		//메모리 해제
	virtual void update(void);		//연산관련(타이머)
	virtual void render(void);	//그려주는 함수
	
	mainGame();
	~mainGame();
};

