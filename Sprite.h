#pragma once

class Texture;
class Sprite
{
private:
	int const _number;

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

	void AdjustTransform();

public:
	Sprite(LPDIRECT3DDEVICE9 device, TCHAR* fileName,
		D3DXVECTOR2 coord = D3DXVECTOR2(0, 0),
		D3DXVECTOR2 size = D3DXVECTOR2(0, 0),
		D3DXVECTOR2 scale = D3DXVECTOR2(1, 1)
		, int const number = 0);
	~Sprite();

	void init();
	void release();
	void update();
	void render(bool bCamera = false);


	//getter, setter
	D3DXVECTOR2 getCoord(void) { return _coord; }
	D3DXVECTOR2 getSize(void) { return _size; }
	D3DXVECTOR2 getRealSize(void);

	void setCoord(D3DXVECTOR2 coord);
	void setScale(D3DXVECTOR2 scale);
	void setCenterPer(D3DXVECTOR2 centerPer); //size 기준 배율로
	void setCenterPos(D3DXVECTOR2 centerPos); //position
	void setRotate(float angleDeg);

	
};

