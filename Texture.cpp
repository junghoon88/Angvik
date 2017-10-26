#include "stdafx.h"
#include "Texture.h"



Texture::Texture(LPDIRECT3DDEVICE9 device, WCHAR* fileName, int const number,
	DWORD color, DWORD colorKey)
	: device(device), color(color), colorKey(colorKey)
{
	_tcscpy(this->fileName, fileName);
	TCHAR		szPath[128] = L"";

	for (size_t i = 0; i < number + 1; i++)
	{
		wsprintf(szPath, fileName, i);
	}

	HRESULT hr;
	hr = D3DXCreateTextureFromFileEx
	(
		device
		, szPath
		, D3DX_DEFAULT
		, D3DX_DEFAULT
		, 1
		, 0
		, D3DFMT_UNKNOWN
		, D3DPOOL_MANAGED
		, 0x0000001
		, 0x0000001
		, colorKey
		, &imageInfo
		, NULL
		, &texture
	);
	assert(SUCCEEDED(hr));
}


Texture::~Texture()
{
	SAFE_RELEASE(texture);
}

void Texture::init(void)
{
	curFrameX = 0;
	curFrameY = 0;
	maxFrameX = 0;
	maxFrameY = 0;
	frameWidth = imageInfo.Width;
	frameHeight = imageInfo.Height;
}

void Texture::init(int frameX, int frameY)
{
	curFrameX = 0;
	curFrameY = 0;
	maxFrameX = frameX - 1;
	maxFrameY = frameY - 1;
	frameWidth = imageInfo.Width / frameX;
	frameHeight = imageInfo.Height / frameY;
}


RECT Texture::getRect(void)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = imageInfo.Width;
	rc.bottom = imageInfo.Height;
	
	return rc;
}

RECT Texture::getRect(int frameX, int frameY)
{
	if (frameX > maxFrameX) 
		frameX = maxFrameX;
	if (frameX < 0) 
		frameX = 0;

	if (frameY > maxFrameY)
		frameY = maxFrameY;
	if (frameY < 0) 
		frameY = 0;

	RECT rc;
	rc.left = frameWidth * frameX;
	rc.top = frameHeight * frameY;
	rc.right = rc.left + frameWidth;
	rc.bottom = rc.top + frameHeight;

	return rc;
}
