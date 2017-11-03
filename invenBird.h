#pragma once
#include "DxWindow.h"

class invenBird : public DxWindow
{
private:
	D3DXVECTOR2 _birdPoint[5];
	D3DXVECTOR2 _birdXY;
	
	int _frameX, _frameY;
	int _birdPointNum;

	float _birdX, _birdY;
	float _birdSpeed;
	float _birdMaxSpeed;
	float _timeCount;
	float _birdPointCount;
	float _angle;

	bool _inInventory;

public:
	invenBird();
	~invenBird();

	void init();
	void init(float x, float y);
	void release(void);
	void update(void);
	void update(float x, float y);
	void render(void);

	void move(float x, float y);
	void birdFrame(float x, float y);
};

