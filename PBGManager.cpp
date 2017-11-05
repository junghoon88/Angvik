#include "stdafx.h"
#include "PBGManager.h"


PBGManager::PBGManager()
{
}


PBGManager::~PBGManager()
{
}


void PBGManager::init(void)
{

}

void PBGManager::release(void)
{
	mImgIter iter = _mImgBG.begin();

	for (; iter != _mImgBG.end();)
	{
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = _mImgBG.erase(iter);
		}
		else ++iter;
	}
	_mImgBG.clear();
}

image* PBGManager::findImage(wstring strKey)
{
	mImgIter iter = _mImgBG.find(strKey);

	if (iter != _mImgBG.end())
	{
		return iter->second;
	}

	return NULL;
}

void PBGManager::addImage(wstring strKey, const TCHAR* fileName, int width, int height)
{
	image* img = findImage(strKey);

	if (img) return;

	img = new image;
	if (FAILED(img->init(fileName, width, height)))
	{
		SAFE_DELETE(img);

		return;
	}

	_mImgBG.insert(make_pair(strKey, img));
}

COLORREF PBGManager::getPixelColor(wstring strKey, int x, int y)
{
	image* img = findImage(strKey);
	
	if (img == NULL) return 0;

	return GetPixel(img->getMemDC(), x, y) & RGB(255, 255, 255);
}

