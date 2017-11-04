#pragma once
#include "DxWindow.h"
#include "Item.h"

struct inven_item
{
	ITEM_TYPE type;
	ITEM_KIND kind;
	ITEM_STATE state;
};

class inven : public DxWindow
{
private:
	inven_item _item;

	int _frameX;

	float _timeCount;

	bool _isMenew;
	bool _isItem;
	bool _isOils;

public:
	inven();
	~inven();

	void init(void);
	void release(void);
	void update(void);
	void update(float x, float y);
	void render(void);
	bool close(void) { return false; }
};

