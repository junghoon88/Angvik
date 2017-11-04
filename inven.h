#pragma once
#include "DxWindow.h"
#include "Item.h"

class inven : public DxWindow
{
private:
	ITEM_TYPE _itemType;
	ITEM_KIND _itemKind;
	ITEM_STATE _itemState;

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

	ITEM_TYPE getItemType(void) { return _itemType; }
};

