#pragma once
#include "animation.h"

class Texture;
class Sprite
{
private:
	LPDIRECT3DDEVICE9 _device;
	LPD3DXSPRITE _sprite;
	Texture* _texture;

	TCHAR _fileName[255];	//파일이름
	D3DXVECTOR2 _coord;		//좌표
	D3DXVECTOR2 _size;		//스케일적용 전 사이즈
	D3DXVECTOR2 _scale;		//스케일(기본기준 몇배)
	D3DXVECTOR2 _center;	//회전축
	float _angleDeg;		//각도(Degree)

	D3DXMATRIX _world;

	bool _bCameraOffset;

	void AdjustTransform();

public:
	Sprite(LPDIRECT3DDEVICE9 device, const TCHAR* fileName,
		D3DXVECTOR2 coord = D3DXVECTOR2(0, 0),
		D3DXVECTOR2 size = D3DXVECTOR2(0, 0),
		D3DXVECTOR2 scale = D3DXVECTOR2(1, 1));
	~Sprite();

	void init(bool bCameraOffset);
	void init(int frameX, int frameY, bool bCameraOffset);
	void release();
	void update();
	void render(BYTE alpha = 255);
	void frameRender(int frameX, int frameY, BYTE alpha = 255);
	void aniRender(animation* ani, BYTE alpha = 255);


	void move(float moveX, float moveY);


	//getter, setter
	inline D3DXVECTOR2 getCoord(void) { return _coord; }
	inline D3DXVECTOR2 getSize(void) { return _size; }
	inline D3DXVECTOR2 getScale(void) { return _scale; }
	inline D3DXVECTOR2 getCenter(void) { return _center; }
	inline float getAngle(void) { return _angleDeg; }


	D3DXVECTOR2 getRealSize(void);

	void setCoord(D3DXVECTOR2 coord);
	void setScale(D3DXVECTOR2 scale);
	void setCenterPer(D3DXVECTOR2 centerPer); //size 기준 배율로
	void setCenterPos(D3DXVECTOR2 centerPos); //position

	void setCoord(float coordX, float corrdY);
	void setScale(float scaleX, float scaleY);
	void setCenterPer(float centerPerX, float centerPerY); //size 기준 배율로
	void setCenterPos(float centerPosX, float centerPosY); //position
	void setRotate(float angleDeg);

	int getCurFrameX(void);
	int getCurFrameY(void);
	void setCurFrameX(int frameX);
	void setCurFrameY(int frameY);
	int getMaxFrameX(void);
	int getMaxFrameY(void);


	inline Texture* getTexture(void) { return _texture; }
};

