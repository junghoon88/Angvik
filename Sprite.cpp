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

	_scaleOffset = { 0.0f, 0.0f };

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

void Sprite::render(BYTE alpha)
{
	if (!AdjustTransform())
		return;

	LONG color = ((LONG)alpha << 24) | 0x00FFFFFF;

	_sprite->SetTransform(&_world);
	_sprite->Begin(D3DXSPRITE_ALPHABLEND);
	_sprite->Draw(_texture->getTexture(), &_texture->getRect(), NULL, NULL, color);
	_sprite->End();
}

void Sprite::frameRender(int frameX, int frameY, BYTE alpha)
{
	if (!AdjustTransform())
		return;

	LONG color = ((LONG)alpha << 24) | 0x00FFFFFF;

	_sprite->SetTransform(&_world);
	_sprite->Begin(D3DXSPRITE_ALPHABLEND);
	_sprite->Draw(_texture->getTexture(), &_texture->getRect(frameX, frameY), NULL, NULL, color);
	_sprite->End();

	_texture->setFrame(frameX, frameY);
}

void Sprite::aniRender(animation* ani, BYTE alpha)
{
	if (!AdjustTransform())
		return;

	LONG color = ((LONG)alpha << 24) | 0x00FFFFFF;

	_sprite->SetTransform(&_world);
	_sprite->Begin(D3DXSPRITE_ALPHABLEND);

	//�̹��� ������ �ִϸ��̼��� ��ġ������ ��´�.
	RECT rcAni = _texture->getRect();
	rcAni.left += ani->getFramePos().x;
	rcAni.right = rcAni.left + ani->getFrameWidth();
	rcAni.top += ani->getFramePos().y;
	rcAni.bottom = rcAni.top + ani->getFrameHeight();

	_sprite->Draw(_texture->getTexture(), &rcAni, NULL, NULL, color);
	_sprite->End();
}


bool Sprite::AdjustTransform()
{
	D3DXVECTOR2 coord = _coord;
	if (_bCameraOffset)
	{
		coord.x -= _mainCamera.x;
		coord.y -= _mainCamera.y;
	}

	if (_scale.x < 0)
	{
		coord.x += _scaleOffset.x;
	}
	if (_scale.y < 0)
	{
		coord.y += _scaleOffset.y;
	}

	RECT temp;
	RECT rcSprite = RectMake(_coord.x, _coord.y, fabs(_size.x), fabs(_size.y));
	RECT rcCamera = RectMake(_mainCamera.x, _mainCamera.y, WINSIZEX, WINSIZEY);

	if (!IntersectRect(&temp, &rcSprite, &rcCamera))
		return false;


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
	//D3DXMatrixTranslation(&translate, FLOAT(_coord.x), FLOAT(_coord.y), 0);
	D3DXMatrixTranslation(&translate, FLOAT(coord.x), FLOAT(coord.y), 0);

	_world = scale * rotationInverseCenter * rotation * rotationCenter * translate;

	return true;
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

	//AdjustTransform();
}

void Sprite::setScale(D3DXVECTOR2 scale)
{
	_scale = scale;

	_size.x = _texture->getWidth() * _scale.x;
	_size.y = _texture->getHeight() * _scale.y;

	//AdjustTransform();
}
void Sprite::setCenterPer(D3DXVECTOR2 centerPer)
{
	_center.x = _size.x * centerPer.x;
	_center.y = _size.y * centerPer.y;

	//AdjustTransform();
}
void Sprite::setCenterPos(D3DXVECTOR2 centerPos)
{
	_center.x = centerPos.x;
	_center.y = centerPos.y;

	//AdjustTransform();
}
void Sprite::setScaleOffset(D3DXVECTOR2 scaleOffset)
{
	_scaleOffset = scaleOffset;
}

void Sprite::setCoord(float coordX, float corrdY)
{
	_coord.x = coordX;
	_coord.y = corrdY;
}
void Sprite::setScale(float scaleX, float scaleY)
{
	_scale.x = scaleX;
	_scale.y = scaleY;
}
void Sprite::setCenterPer(float centerPerX, float centerPerY)
{
	_center.x = _size.x * centerPerX;
	_center.y = _size.y * centerPerY;
}
void Sprite::setCenterPos(float centerPosX, float centerPosY)
{
	_center.x = centerPosX;
	_center.y = centerPosY;
}
void Sprite::setScaleOffset(float scaleOffsetX, float scaleOffsetY)
{
	_scaleOffset.x = scaleOffsetX;
	_scaleOffset.y = scaleOffsetY;
}



void Sprite::setRotate(float angleDeg)
{
	_angleDeg = angleDeg;

	//AdjustTransform();
}

void Sprite::move(float moveX, float moveY)
{
	_coord.x += moveX;
	_coord.y += moveY;

	//AdjustTransform();
}



int Sprite::getCurFrameX(void) { if (_texture) return _texture->getCurFrameX(); }
int Sprite::getCurFrameY(void) { if (_texture) return _texture->getCurFrameY(); }
void Sprite::setCurFrameX(int frameX) { if (_texture) _texture->setCurFrameX(frameX); }
void Sprite::setCurFrameY(int frameY) { if (_texture) _texture->setCurFrameY(frameY); }
int Sprite::getMaxFrameX(void) { if (_texture) return _texture->getMaxFrameX(); }
int Sprite::getMaxFrameY(void) { if (_texture) return _texture->getMaxFrameY(); }
