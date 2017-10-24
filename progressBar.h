#pragma once
#include "gameNode.h"

class progressBar : public gameNode
{
private:
	POINT _pt;
	float _width;

	image* _progressBarTop;
	image* _progressBarBottom;

public:
	HRESULT init(TCHAR* name, int x, int y, int width, int height);
	void release();
	void update();
	void render(TCHAR* name);

	void setGauge(float currentGauge, float maxGauge);

	inline void setX(int x) { _pt.x = x; }
	inline void setY(int y) { _pt.y = y; }

	inline float getWidth(void) { return _width; }
	
	progressBar();
	~progressBar();
};

//=====================================================================================================================

class progressBarHP : public gameNode
{
private:
	MYPOINT _pt;
	int _width;
	int _height;
	int _hpNum;
	int _hpMaxNum;

	RECT _rcWhite;
	RECT _rcHp;

	HPEN _penWhite;
	HBRUSH _brushGreen, _brushYellow, _brushRed, _brushWhite;


public:
	HRESULT init(int x, int y, int width, int height);
	void release();
	void update();
	void render();

	void setGauge(int HP, int HPMAX);

	inline void setX(int x) { _pt.x = x; }
	inline void setY(int y) { _pt.y = y; }

	progressBarHP();
	~progressBarHP();
};

