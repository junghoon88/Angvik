#pragma once
#include "DxWindow.h"
enum itemstate
{
	RIGHT_DONE,
	RIGHT_ATTACK,
	RIGHT_BACK,

};
enum itemstate2
{
	DONE,
	SWORD,
	LANCE,
	STAFF,
	BOOMERANG
};
enum oilstate
{
	WHITE_OIL,
	BLACK_OIL,
	GOLD_OIL
};
class sceneitemTest : public DxWindow
{
private:


	//debug
	int frameCnt;
	float frameTime;
	float angleDeg;

	itemstate itemState;
	itemstate2 itemState2;
	Sprite* spt;
	Sprite* temp;
	oilstate oilState;
	
public:
	sceneitemTest();
	~sceneitemTest();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

