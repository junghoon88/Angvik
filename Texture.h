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
	Texture(LPDIRECT3DDEVICE9 device, WCHAR* fileName, DWORD color = 0xFFFFFFFF, DWORD colorKey = 0x00FFFFFF);
	~Texture();

	void init(void);
	void init(int frameX, int frameY);

	RECT getRect(void);
	RECT getRect(int frameX, int frameY);

	//getter, setter
	inline int getWidth(void) { return imageInfo.Width; }
	inline int getHeight(void) { return imageInfo.Height; }
	inline int getHalfWidth(void) { return (int)(imageInfo.Width * 0.5f); }
	inline int getHalfHeight(void) { return (int)(imageInfo.Height * 0.5f); }
	inline int getFrameWidth(void) { return frameWidth; }
	inline int getFrameHeight(void) { return frameHeight; }

	LPDIRECT3DTEXTURE9 getTexture() { return texture; }



};

