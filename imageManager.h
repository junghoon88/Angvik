#pragma once
#include "singletonBase.h"
#include "Sprite.h"
#include <map>

class imageManager : public singletonBase<imageManager>
{
private:
	typedef map<wstring, Sprite*> mapImageList;
	typedef map<wstring, Sprite*>::iterator mapImageIter;

	mapImageList _mImageList;

public:
	imageManager();
	~imageManager();

	void init();
	void release();

	//Sprite* addImage(LPDIRECT3DDEVICE9 device, wstring strKey, int width, int height);
	Sprite* addImage(LPDIRECT3DDEVICE9 device, wstring strKey, const TCHAR* fileName, int width, int height);
	//Sprite* addImage(LPDIRECT3DDEVICE9 device, wstring strKey, const TCHAR* fileName, float x, float y, int width, int height, bool trans = FALSE, COLORREF transColor = FALSE, bool blend = FALSE);

	//Sprite* addFrameImage(wstring strKey, const TCHAR* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans = FALSE, COLORREF transColor = FALSE, bool blend = FALSE);
	//Sprite* addFrameImage(wstring strKey, const TCHAR* fileName, int width, int height, int frameX, int frameY, bool trans = FALSE, COLORREF transColor = FALSE, bool blend = FALSE);

	Sprite* findImage(wstring strKey);

	//BOOL deleteImage(wstring strKey);

	BOOL deleteAll(void);

	//void render(wstring strKey, HDC hdc, int destX, int destY);
	//void render(wstring strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//void frameRender(wstring strKey, HDC hdc, int destX, int destY);
	//void frameRender(wstring strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//void loopRender(wstring strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	//void alphaRender(wstring strKey, HDC hdc, BYTE alpha);
	//void alphaRender(wstring strKey, HDC hdc, int destX, int destY, BYTE alpha);
	//void alphaRender(wstring strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	//void alphaFrameRender(wstring strKey, HDC hdc, int destX, int destY, BYTE alpha);
	//void alphaFrameRender(wstring strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha);

	//void aniRender(wstring strKey, HDC hdc, int destX, int destY, animation* ani);
	//void aniAlphaRender(wstring strKey, HDC hdc, int destX, int destY, animation* ani, BYTE alpha);

	//getter
	//wstring FindKeyByImage(Sprite* img);
};

