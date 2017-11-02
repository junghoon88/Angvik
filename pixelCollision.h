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
	int		_dir;				//X축 바라보는 방향
	float	_probeXOffset;	//X축 바라보는 방향 옵셋(충돌체크할 픽셀)
	float	_probeYOffset;	//Y축 땅에 닿는 옵셋(충돌체크할 픽셀)


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
	bool getPixelGround(float* x, float* y, int widht, int height);

	

	//getter, setter

};

