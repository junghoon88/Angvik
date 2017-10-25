#include "stdafx.h"
#include "Sprite.h"
#include "Texture.h"


Sprite::Sprite(LPDIRECT3DDEVICE9 device, TCHAR* fileName,
	D3DXVECTOR2 coord, D3DXVECTOR2 size, D3DXVECTOR2 scale, int const number)
	: _device(device), _coord(coord), _size(size),
	_sprite(NULL), _texture(NULL), _angleDeg(0.0f), _scale(scale), _number(number)
{
	_tcscpy(_fileName, fileName);

	_center.x = _size.x * 0.5f;
	_center.y = _size.y * 0.5f;

	//4D Matrix ..?
	D3DXMatrixIdentity(&_world);
}
Sprite::~Sprite()
{

}

void Sprite::init()
{
	HRESULT hr;
	hr = D3DXCreateSprite(_device, &_sprite);
	assert(SUCCEEDED(hr));

	_texture = new Texture(_device, _fileName, _number);
	_size.x = (_size.x < 1) ? _texture->getWidth()  : _size.x;
	_size.y = (_size.y < 1) ? _texture->getHeight() : _size.y;

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
void Sprite::render(bool bCamera)
{
	_sprite->SetTransform(&_world);
	_sprite->Begin(D3DXSPRITE_ALPHABLEND);
	if (bCamera)
	{
		//camera´Â?
		_sprite->Draw(_texture->getTexture(), &_texture->getRect(), NULL, NULL, 0xFFFFFFFF);
	}
	else
	{
		//camera´Â?
		_sprite->Draw(_texture->getTexture(), &_texture->getRect(), NULL, NULL, 0xFFFFFFFF);
	}
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

	D3DXMatrixTranslation(&rotationInverseCenter, -_center.x, -_center.y, 0);
	D3DXMatrixRotationZ(&rotation, -angle);
	D3DXMatrixTranslation(&rotationCenter, _center.x, _center.y, 0);
	D3DXMatrixTranslation(&translate, FLOAT(_coord.x), FLOAT(_coord.y), 0);

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
