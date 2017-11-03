#pragma once
#include "DxWindow.h"

class pixelCollision : public DxWindow
{
private:
	image* _imgPBG;

	float*	_x;				//center X
	float*	_y;				//center Y
	int		_width;				//
	int		_height;				//
	int		_dir;				//X�� �ٶ󺸴� ����
	float	_probeXOffset;	//X�� �ٶ󺸴� ���� �ɼ�(�浹üũ�� �ȼ�)
	float	_probeYOffset;	//Y�� ���� ��� �ɼ�(�浹üũ�� �ȼ�)


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
	bool getPixelGround(float* x, float* y, int widht, int height);

	

	//getter, setter

};

