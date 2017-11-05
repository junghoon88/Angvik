#pragma once
#include "DxWindow.h"

struct tagPixelCollision
{
	bool detect;
	POINT offset;
};

class pixelCollision : public DxWindow
{
private:
	TCHAR strPBG[100];

	float*	_x;				//center X
	float*	_y;				//center Y
	int		_width;				//
	int		_height;				//
	int		_dir;				//X축 바라보는 방향
	float	_probeX;	//X축 바라보는 방향 옵셋(충돌체크할 픽셀)
	float	_probeY;	//Y축 땅에 닿는 옵셋(충돌체크할 픽셀)


	bool _isGround;		//땅위에 있는지?
	bool _isWall;		//벽에 부딪혔는지?
	bool _isTrap;		//트랩에 걸렸는지?
	//bool 
	



public:
	pixelCollision();
	~pixelCollision();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

public:
	bool getPixelGroundLT(float* lx, float* ty, int width, int height);		//x,y -> c
	bool getPixelGroundCC(float* cx, float* cy, int width, int height);		//

	bool getPixelWall(float* x, float* y, int width, int height, int dir);	//dir = 1 -> 오른쪽, -1 일때 왼쪽

	tagPixelCollision getPlayerPixelGround(int cx, int cy, int width, int height);
	tagPixelCollision getPlayerPixelWall(int cx, int cy, int width, int height, int dir);	//dir = 1 -> 오른쪽, -1 일때 왼쪽
	tagPixelCollision getPlayerPixelCeiling(int cx, int cy, int width, int height);

	

	//getter, setter

};

