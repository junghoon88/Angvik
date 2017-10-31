#pragma once
#include "animation.h"

class Texture;
class Sprite
{
private:
	LPDIRECT3DDEVICE9 _device;
	LPD3DXSPRITE _sprite;
	Texture* _texture;

	TCHAR _fileName[255];	//�����̸�
	D3DXVECTOR2 _coord;		//��ǥ
	D3DXVECTOR2 _size;		//���������� �� ������
	D3DXVECTOR2 _scale;		//������(�⺻���� ���)
	D3DXVECTOR2 _center;	//ȸ����
	float _angleDeg;		//����(Degree)

	D3DXMATRIX _world;

	void AdjustTransform();

public:
	Sprite(LPDIRECT3DDEVICE9 device, const TCHAR* fileName,
		D3DXVECTOR2 coord = D3DXVECTOR2(0, 0),
		D3DXVECTOR2 size = D3DXVECTOR2(0, 0),
		D3DXVECTOR2 scale = D3DXVECTOR2(1, 1));
	~Sprite();

	void init();
	void init(int frameX, int frameY);
	void release();
	void update();
	void render(bool cameraOffset = true);
	void frameRender(int frameX, int frameY, bool cameraOffset = true);
	void aniRender(animation* ani, bool cameraOffset = true);


	void move(float moveX, float moveY);

	void getPixel(void);

	//getter, setter
	inline D3DXVECTOR2 getCoord(void) { return _coord; }
	inline D3DXVECTOR2 getSize(void) { return _size; }
	inline D3DXVECTOR2 getScale(void) { return _scale; }
	inline D3DXVECTOR2 getCenter(void) { return _center; }
	inline float getAngle(void) { return _angleDeg; }


	D3DXVECTOR2 getRealSize(void);

	void setCoord(D3DXVECTOR2 coord);
	void setScale(D3DXVECTOR2 scale);
	void setCenterPer(D3DXVECTOR2 centerPer); //size ���� ������
	void setCenterPos(D3DXVECTOR2 centerPos); //position
	void setRotate(float angleDeg);

	int getCurFrameX(void);
	int getCurFrameY(void);
	void setCurFrameX(int frameX);
	void setCurFrameY(int frameY);
	int getMaxFrameX(void);
	int getMaxFrameY(void);


	inline Texture* getTexture(void) { return _texture; }
};

