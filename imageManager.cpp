#include "stdafx.h"
#include "imageManager.h"



imageManager::imageManager()
{
}


imageManager::~imageManager()
{
}

void imageManager::init()
{

}
void imageManager::release()
{
	deleteAll();
}

Sprite* imageManager::addImage(LPDIRECT3DDEVICE9 device, wstring strKey, const TCHAR* fileName, int width, int height)
{
	Sprite* sprite = findImage(strKey);

	if (sprite) return sprite;

	sprite = new Sprite(device, fileName);
	sprite->init();

	_mImageList.insert(make_pair(strKey, sprite));
}

Sprite* imageManager::findImage(wstring strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		return key->second;
	}

	return NULL;
}

BOOL imageManager::deleteAll(void)
{
	mapImageIter iter = _mImageList.begin();

	for (; iter != _mImageList.end();)
	{
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else ++iter;
	}

	_mImageList.clear();

	return TRUE;
}
