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
	Sprite* addImage(LPDIRECT3DDEVICE9 device, wstring strKey, const TCHAR* fileName);
	//Sprite* addImage(LPDIRECT3DDEVICE9 device, wstring strKey, const TCHAR* fileName, float x, float y, int width, int height, bool trans = FALSE, COLORREF transColor = FALSE, bool blend = FALSE);

	Sprite* addFrameImage(LPDIRECT3DDEVICE9 device, wstring strKey, const TCHAR* fileName, int frameX, int frameY);
	//Sprite* addFrameImage(wstring strKey, const TCHAR* fileName, int width, int height, int frameX, int frameY, bool trans = FALSE, COLORREF transColor = FALSE, bool blend = FALSE);

	Sprite* findImage(wstring strKey);

	//BOOL deleteImage(wstring strKey);

	BOOL deleteAll(void);

	void setCoord(wstring strKey, float destX, float destY);
	void setScale(wstring strKey, float scaleX, float scaleY);
	void setCenterPer(wstring strKey, float centerPerX, float centerPerY); //size 기준 배율로
	void setCenterPos(wstring strKey, float centerPosX, float centerPosY); //position
	void setRotate(wstring strKey, float angleDeg);
	void move(wstring strKey, float moveX, float moveY);

	void render(wstring strKey, bool cameraOffset = true);
	//void render(wstring strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	void frameRender(wstring strKey, int frameX, int frameY, bool cameraOffset = true);
	//void frameRender(wstring strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//void loopRender(wstring strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	//void alphaRender(wstring strKey, HDC hdc, BYTE alpha);
	//void alphaRender(wstring strKey, HDC hdc, int destX, int destY, BYTE alpha);
	//void alphaRender(wstring strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	//void alphaFrameRender(wstring strKey, HDC hdc, int destX, int destY, BYTE alpha);
	//void alphaFrameRender(wstring strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha);

	void aniRender(wstring strKey, animation* ani, bool cameraOffset = true);
	//void aniAlphaRender(wstring strKey, HDC hdc, int destX, int destY, animation* ani, BYTE alpha);

	int getCurFrameX(wstring strKey);
	int getCurFrameY(wstring strKey);
	void setCurFrameX(wstring strKey, int frameX);
	void setCurFrameY(wstring strKey, int frameY);
	void setCurFrame(wstring strKey, int frameX, int frameY);
	int getMaxFrameX(wstring strKey);
	int getMaxFrameY(wstring strKey);

	//getter
	//wstring FindKeyByImage(Sprite* img);
};

