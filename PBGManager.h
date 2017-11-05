#pragma once
#include "singletonBase.h"
#include "image.h"

struct tagRectTrap
{
	int num;
	RECT rc;
	COLORREF color;
};


class PBGManager : public singletonBase<PBGManager>
{
private:
	typedef map<wstring, image*> mImg;
	typedef map<wstring, image*>::iterator mImgIter;

	typedef vector<tagRectTrap> vRectTrap;
	typedef vector<tagRectTrap>::iterator viRectTrap;


private:
	mImg _mImgBG;

	vRectTrap _vRectTraps;


public:
	PBGManager();
	~PBGManager();

	void init(void);
	void release(void);
	void render(wstring strKey);

	void addImage(wstring strKey, const TCHAR* fileName, int width, int height);
	image* findImage(wstring strKey);
	COLORREF getPixelColor(wstring strKey, int x, int y);


	void addRect(int num, RECT rc, COLORREF color);
	void setRectColor(int num, COLORREF color);

};

