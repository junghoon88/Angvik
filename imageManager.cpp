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

Sprite* imageManager::addImage(LPDIRECT3DDEVICE9 device, wstring strKey, const TCHAR* fileName)
{
	Sprite* sprite = findImage(strKey);

	if (sprite) return sprite;

	sprite = new Sprite(device, fileName);
	sprite->init();

	_mImageList.insert(make_pair(strKey, sprite));

	return sprite;
}

Sprite* imageManager::addFrameImage(LPDIRECT3DDEVICE9 device, wstring strKey, const TCHAR* fileName, int frameX, int frameY)
{
	Sprite* sprite = findImage(strKey);

	if (sprite) return sprite;

	sprite = new Sprite(device, fileName);
	sprite->init(frameX, frameY);

	_mImageList.insert(make_pair(strKey, sprite));
	
	return sprite;
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

void imageManager::setCoord(wstring strKey, float destX, float destY)
{
	Sprite* sprite = findImage(strKey);

	if (sprite) sprite->setCoord({ destX, destY });
}

void imageManager::setScale(wstring strKey, float scaleX, float scaleY)
{
	Sprite* sprite = findImage(strKey);

	if (sprite) sprite->setScale({ scaleX, scaleY});
}

void imageManager::setCenterPer(wstring strKey, float centerPerX, float centerPerY)
{
	Sprite* sprite = findImage(strKey);

	if (sprite) sprite->setCenterPer({ centerPerX, centerPerY });
}


void imageManager::setCenterPos(wstring strKey, float centerPosX, float centerPosY)
{
	Sprite* sprite = findImage(strKey);

	if (sprite) sprite->setCenterPos({ centerPosX, centerPosY });
}

void imageManager::setRotate(wstring strKey, float angleDeg)				  
{
	Sprite* sprite = findImage(strKey);

	if (sprite) sprite->setRotate(angleDeg);
}

void imageManager::move(wstring strKey, float moveX, float moveY)
{
	Sprite* sprite = findImage(strKey);

	if (sprite) sprite->move(moveX, moveY);
}





void imageManager::render(wstring strKey)
{
	Sprite* sprite = findImage(strKey);

	if (sprite) sprite->render();
}

void imageManager::frameRender(wstring strKey, int frameX, int frameY)
{
	Sprite* sprite = findImage(strKey);

	if (sprite) sprite->frameRender(frameX, frameY);
}
