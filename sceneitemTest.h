#pragma once
#include "DxWindow.h"
enum itemstate
{
	SWORD_RIGHT_DONE,
	SWORD_RIGHT_ATTACK,
	LANCE_RIGHT_DONE,
	LANCE_RIGHT_ATTACK,
	LANCE_RIGHT_GRAVITY,
	STAFF_RIGHT_DONE,
	STAFF_RIGHT_ATTACK,
	BOOMERANG_RIGHT_DONE,
	BOOMERANG_RIGHT_ATTACK,
	BOOBMERANG_RIGHT_RETURN,
	SWORD_LEFT_DONE,
	SWORD_LEFT_ATTACK,
	LANCE_LEFT_DONE,
	LANCE_LEFT_ATTACK,
	LANCE_LEFF_GRAVITY,
	STAFF_LEFT_DONE,
	STAFF_LEFT_ATTACK,
	BOOMERANG_LEFT_DONE,
	BOOMERANG_LEFT_ATTACK,
	BOOBMERANG_LEFT_RETURN
	

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
	oilstate oilState;
	
public:
	sceneitemTest();
	~sceneitemTest();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

