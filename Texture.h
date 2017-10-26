#pragma once
class Texture
{
private:
	LPDIRECT3DDEVICE9 device;

	WCHAR fileName[255];
	D3DXIMAGE_INFO imageInfo;
	LPDIRECT3DTEXTURE9 texture;

	DWORD color;
	DWORD colorKey;

	int curFrameX;
	int curFrameY;
	int maxFrameX;
	int maxFrameY;
	int frameWidth;
	int frameHeight;


public:
	Texture(LPDIRECT3DDEVICE9 device, WCHAR* fileName, int const number = 0,
		DWORD color = 0xFFFFFFFF, DWORD colorKey = 0x00FFFFFF);
	~Texture();

	void init(void);
	void init(int frameX, int frameY);

	RECT getRect(void);
	RECT getRect(int frameX, int frameY);

	//getter, setter
	int getWidth(void) { return imageInfo.Width; }
	int getHeight(void) { return imageInfo.Height; }
	int getHalfWidth(void) { return (int)(imageInfo.Width * 0.5f); }
	int getHalfHeight(void) { return (int)(imageInfo.Height * 0.5f); }

	LPDIRECT3DTEXTURE9 getTexture() { return texture; }



};

