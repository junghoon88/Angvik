#include "stdafx.h"
#include "Sprite.h"
#include "Texture.h"


Sprite::Sprite(LPDIRECT3DDEVICE9 device, const TCHAR* fileName,
	D3DXVECTOR2 coord, D3DXVECTOR2 size, D3DXVECTOR2 scale)
	: _device(device), _coord(coord), _size(size),
	_sprite(NULL), _texture(NULL), _angleDeg(0.0f), _scale(scale)
{
	_tcscpy(_fileName, fileName);

	_center.x = 0.0f;
	_center.y = 0.0f;

	//4D Matrix ..?
	D3DXMatrixIdentity(&_world);
}
Sprite::~Sprite()
{

}

void Sprite::init(bool bCameraOffset)
{
	HRESULT hr;
	hr = D3DXCreateSprite(_device, &_sprite);
	assert(SUCCEEDED(hr));

	_texture = new Texture(_device, _fileName);
	_texture->init();
	_size.x = (_size.x < 1) ? _texture->getWidth()  : _size.x;
	_size.y = (_size.y < 1) ? _texture->getHeight() : _size.y;

	_bCameraOffset = bCameraOffset;

	AdjustTransform();
}

void Sprite::init(int frameX, int frameY, bool bCameraOffset)
{
	HRESULT hr;
	hr = D3DXCreateSprite(_device, &_sprite);
	assert(SUCCEEDED(hr));

	_texture = new Texture(_device, _fileName);
	_texture->init(frameX, frameY);
	_size.x = (_size.x < 1) ? _texture->getWidth() : _size.x;
	_size.y = (_size.y < 1) ? _texture->getHeight() : _size.y;

	_bCameraOffset = bCameraOffset;

	AdjustTransform();
}

void Sprite::release()
{
	SAFE_DELETE(_texture);
	SAFE_RELEASE(_sprite);
}

void Sprite::update()
{

}

void Sprite::render(bool cameraOffset)
{
	AdjustTransform();

	_sprite->SetTransform(&_world);
	_sprite->Begin(D3DXSPRITE_ALPHABLEND);
	//camera offset
	D3DXVECTOR3 center = _center;

	D3DXVECTOR3 offset = {0.0f, 0.0f, 0.0f};
	if (cameraOffset)
	{
		int cameraX = _mainCamera.x;
		int cameraY = _mainCamera.y;

		if (_scale.x < 0) cameraX *= -1;
		if (_scale.y < 0) cameraY *= -1;

		offset = { (float)-cameraX, (float)-cameraY, 0.0f };

		//center.x -= cameraX / 5;
		//center.y -= cameraY / 5;

		if (_scale.x < 0) offset.x += _size.x / 2;
		if (_scale.y < 0) offset.y += _size.y / 2;

		//D3DXVECTOR3 vEyePt(0.0f, 0.0f, -5.0f);							//1. 눈의 위치
		//D3DXVECTOR3 vLookatPt(-cameraX, -cameraY, 0.0f);						//2. 눈이 바라보는 위치
		//D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);							//3. 천정방향을 나타내는 상방벡터
		//D3DXMATRIXA16 matView;											//
		//D3DXMatrixLookAtLH(&matView, &vEyePt, &vLookatPt, &vUpVec);		//뷰 행렬 생성
		//_sprite->SetWorldViewLH(&_world, &matView);

		_sprite->Draw(_texture->getTexture(), &_texture->getRect(), NULL, NULL, 0xFFFFFFFF);
		_sprite->End();
	}
	else
	{
		_sprite->Draw(_texture->getTexture(), &_texture->getRect(), NULL, NULL, 0xFFFFFFFF);
		_sprite->End();
	}
}

void Sprite::frameRender(int frameX, int frameY, bool cameraOffset)
{
	AdjustTransform();

	_sprite->SetTransform(&_world);
	_sprite->Begin(D3DXSPRITE_ALPHABLEND);
	//camera offset
	D3DXVECTOR3 offset = { 0.0f, 0.0f, 0.0f };
	if (cameraOffset)
	{
		int cameraX = _mainCamera.x;
		int cameraY = _mainCamera.y;

		if (_scale.x < 0) cameraX *= -1;
		if (_scale.y < 0) cameraY *= -1;

		offset = { (float)-cameraX, (float)-cameraY, 0.0f };

		if (_scale.x < 0) offset.x += _size.x / 2;
		if (_scale.y < 0) offset.y += _size.y / 2;

	}
	_sprite->Draw(_texture->getTexture(), &_texture->getRect(frameX, frameY), NULL, NULL, 0xFFFFFFFF);
	_sprite->End();
}

void Sprite::aniRender(animation* ani, bool cameraOffset)
{
	AdjustTransform();

	_sprite->SetTransform(&_world);
	_sprite->Begin(D3DXSPRITE_ALPHABLEND);

	//camera는
	RECT temp = _texture->getRect();
	temp.left += ani->getFramePos().x;
	temp.right = temp.left + ani->getFrameWidth();
	temp.top += ani->getFramePos().y;
	temp.bottom = temp.top + ani->getFrameHeight();

	//camera offset
	D3DXVECTOR3 offset = { 0.0f, 0.0f, 0.0f };
	if (cameraOffset)
	{
		int cameraX = _mainCamera.x;
		int cameraY = _mainCamera.y;

		if (_scale.x < 0) cameraX *= -1;
		if (_scale.y < 0) cameraY *= -1;

		offset = { (float)-cameraX, (float)-cameraY, 0.0f };

		if (_scale.x < 0) offset.x += _size.x / 2;
		if (_scale.y < 0) offset.y += _size.y / 2;

	}
	_sprite->Draw(_texture->getTexture(), &temp, NULL, NULL, 0xFFFFFFFF);
	_sprite->End();
}


void Sprite::AdjustTransform()
{
	//4D Matrix ..?
	D3DXMatrixIdentity(&_world);

	float angle = D3DXToRadian(_angleDeg);
	D3DXMATRIX scale;
	D3DXMATRIX rotation;
	D3DXMATRIX rotationCenter;
	D3DXMATRIX rotationInverseCenter;
	D3DXMATRIX translate;

	D3DXMatrixIdentity(&scale);
	D3DXMatrixIdentity(&rotation);
	D3DXMatrixIdentity(&rotationCenter);
	D3DXMatrixIdentity(&rotationInverseCenter);
	D3DXMatrixIdentity(&translate);

	D3DXMatrixScaling(&scale, _scale.x, _scale.y, 1.0f);

	//_center.x = _size.x * 0.5f;
	//_center.y = _size.y * 0.5f;

	D3DXVECTOR2 coord = _coord;
	if (_bCameraOffset)
	{
		coord.x -= _mainCamera.x;
		coord.y -= _mainCamera.y;
	}


	D3DXMatrixTranslation(&rotationInverseCenter, -_center.x, -_center.y, 0);
	D3DXMatrixRotationZ(&rotation, -angle);
	D3DXMatrixTranslation(&rotationCenter, _center.x, _center.y, 0);
	//D3DXMatrixTranslation(&translate, FLOAT(_coord.x), FLOAT(_coord.y), 0);
	D3DXMatrixTranslation(&translate, FLOAT(coord.x), FLOAT(coord.y), 0);

	_world = scale * rotationInverseCenter * rotation * rotationCenter * translate;
}


D3DXVECTOR2 Sprite::getRealSize(void)
{
	D3DXVECTOR2 temp = _size;
	temp.x *= _scale.x;
	temp.y *= _scale.y;
	
	return temp;
}

void Sprite::setCoord(D3DXVECTOR2 coord)
{
	_coord = coord;

	AdjustTransform();
}

void Sprite::setScale(D3DXVECTOR2 scale)
{
	_scale = scale;

	_size.x = _texture->getWidth() * _scale.x;
	_size.y = _texture->getHeight() * _scale.y;

	//if (_scale.x < 0)
	//{
	//	_coord.x -= fabs(_texture->getWidth() * _scale.x);
	//}
	//if (_scale.y < 0)
	//{
	//	_coord.y -= fabs(_texture->getHeight() * _scale.y);
	//}

	AdjustTransform();
}
void Sprite::setCenterPer(D3DXVECTOR2 centerPer)
{
	_center.x = _size.x * centerPer.x;
	_center.y = _size.y * centerPer.y;

	AdjustTransform();
}
void Sprite::setCenterPos(D3DXVECTOR2 centerPos)
{
	_center.x = centerPos.x;
	_center.y = centerPos.y;

	AdjustTransform();
}
void Sprite::setRotate(float angleDeg)
{
	_angleDeg = angleDeg;

	AdjustTransform();
}

void Sprite::move(float moveX, float moveY)
{
	_coord.x += moveX;
	_coord.y += moveY;

	AdjustTransform();
}

void Sprite::getPixel(void)
{
	//LPCSTR ss = D3DXGetPixelShaderProfile(_device);
	//IDirect3DPixelShader9** pixelshader = (_device);
	//_device->GetPixelShader(pixelshader);
	printf("");
}


int Sprite::getCurFrameX(void) { if (_texture) return _texture->getCurFrameX(); }
int Sprite::getCurFrameY(void) { if (_texture) return _texture->getCurFrameY(); }
void Sprite::setCurFrameX(int frameX) { if (_texture) _texture->setCurFrameX(frameX); }
void Sprite::setCurFrameY(int frameY) { if (_texture) _texture->setCurFrameY(frameY); }
int Sprite::getMaxFrameX(void) { if (_texture) return _texture->getMaxFrameX(); }
int Sprite::getMaxFrameY(void) { if (_texture) return _texture->getMaxFrameY(); }
