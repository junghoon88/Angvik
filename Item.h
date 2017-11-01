#pragma once
#include "DxWindow.h"

enum ITEM_TYPE
{
	ITEM_TYPE_SWORD,
	ITEM_TYPE_LENCE,
	ITEM_TYPE_BOOMERANG,
	ITEM_TYPE_STAFF,
	ITEM_TYPE_OIL,
	ITEM_TYPE_EGG
};

enum ITEM_KIND
{
	ITEM_KIND_WHITE,
	ITEM_KIND_BLACK,
	ITEM_KIND_GOLD
};

enum ITEM_STATE
{
	ITEM_STATE_IDLE
};

class Item : public DxWindow
{
private:
	Sprite* spt;
	ITEM_TYPE _type;
	ITEM_KIND _kind;
	ITEM_STATE _state;

	//debug
	int frameCnt;
	float frameTime;
	float angleDeg;




public:
	Item();
	~Item();

	void init(ITEM_TYPE type, ITEM_KIND kind);
	void release(void);
	void update(void);
	void render(void);
};

