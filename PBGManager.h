#pragma once
#include "singletonBase.h"
#include "image.h"

class PBGManager : public singletonBase<PBGManager>
{
private:
	typedef map<wstring, image*> mImg;
	typedef map<wstring, image*>::iterator mImgIter;

private:
	mImg _mImgBG;



public:
	PBGManager();
	~PBGManager();

	void init(void);
	void release(void);

	void addImage(wstring strKey, const TCHAR* fileName, int width, int height);
	image* findImage(wstring strKey);
	COLORREF getPixelColor(wstring strKey, int x, int y);

};

