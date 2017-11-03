#pragma once
#include "DxWindow.h"

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
	bool getPixelGround(float* x, float* y, int width, int height);

	

	//getter, setter

};

