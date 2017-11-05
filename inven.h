#pragma once
#include "DxWindow.h"
#include "Item.h"

class itemManager;

class inven : public DxWindow
{
private:
	typedef vector<Item*> vItems;
	typedef vector<Item*>::iterator viItems;

	vItems _vItems;
	viItems _viItems;

	itemManager* _im;

	D3DXVECTOR2 _selectPoint[5];

	int _selectNum;
	int _frameX;
	int _goldOils, _blackOils, _whiteOils;

	float _timeCount;

	bool _isMenew;
	bool _isItem;
	bool _isOils;
	bool _isInven;

public:
	inven();
	~inven();

	void init(void);
	void release(void);
	void update(void);
	void update(float x, float y);
	void render(void);
	bool close(void) { return false; }

	void itemUpdate(void);

	inline bool getInven(void) { return _isInven; }
	inline void setLinkAdressItemManager(itemManager*     im) { _im = im; }
};

