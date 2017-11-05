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
	int		_dir;				//X�� �ٶ󺸴� ����
	float	_probeX;	//X�� �ٶ󺸴� ���� �ɼ�(�浹üũ�� �ȼ�)
	float	_probeY;	//Y�� ���� ��� �ɼ�(�浹üũ�� �ȼ�)


	bool _isGround;		//������ �ִ���?
	bool _isWall;		//���� �ε�������?
	bool _isTrap;		//Ʈ���� �ɷȴ���?
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

	bool getPixelWall(float* x, float* y, int width, int height, int dir);	//dir = 1 -> ������, -1 �϶� ����

	tagPixelCollision getPlayerPixelGround(int cx, int cy, int width, int height);
	tagPixelCollision getPlayerPixelWall(int cx, int cy, int width, int height, int dir);	//dir = 1 -> ������, -1 �϶� ����
	tagPixelCollision getPlayerPixelCeiling(int cx, int cy, int width, int height);

	

	//getter, setter

};

