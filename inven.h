#pragma once
#include "DxWindow.h"
#include "Item.h"

class itemManager;
class invenBird;

class inven : public DxWindow
{
private:
	typedef vector<Item*> vItems;
	typedef vector<Item*>::iterator viItems;

	vItems _vItems;
	viItems _viItems;

	itemManager* _im;
	invenBird* _ib;

	D3DXVECTOR2 _selectPoint[5];

	int _selectNum;
	int _frameX;
	int _goldOils, _blackOils, _whiteOils;
	int _inventoryMax;
	int _inventoryNum;

	float _timeCount;

	bool _isMenew;
	bool _isItem;
	bool _isOils;
	bool _isInven;
	bool _isEquip;
	bool _isCompose;

public:
	inven();
	~inven();

	void init(void);
	void release(void);
	void update(void);
	void update(float x, float y);
	void render(void);
	bool close(void) { return false; }

	inline void itemUpdate(void);

	void menewBoxUpdate(float x, float y);
	void itemBoxUpdate(float x, float y);
	void oilsBoxUpdate(float x, float y);
	void equipBoxUpdate(float x, float y);
	void composeBoxUpdate(float x, float y);

	inline bool getInven(void) { return _isInven; }
	inline void setLinkAdressItemManager(itemManager* im) { _im = im; }
	inline void setLinkAdressInvenBird(invenBird* ib) { _ib = ib; }
};

