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

void PBGManager::render(wstring strKey)
{
	mImgIter iter = _mImgBG.find(strKey);

	if (iter == _mImgBG.end())
		return;

	HDC backDC = iter->second->getMemDC();


	for (int i = 0; i < _vRectTraps.size(); i++)
	{
		HPEN hPen = CreatePen(PS_SOLID, 1, _vRectTraps[i].color);
		HBRUSH hBrush = CreateSolidBrush(_vRectTraps[i].color);

		HPEN oldPen = (HPEN)SelectObject(backDC, hPen);
		HBRUSH oldBrush = (HBRUSH)SelectObject(backDC, hBrush);

		Rectangle(backDC, _vRectTraps[i].rc.left, _vRectTraps[i].rc.top, _vRectTraps[i].rc.right, _vRectTraps[i].rc.bottom);

		SelectObject(backDC, hPen);
		SelectObject(backDC, hBrush);
	}
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


void PBGManager::addRect(int num, RECT rc, COLORREF color)
{
	tagRectTrap trap;
	ZeroMemory(&trap, sizeof(tagRectTrap));

	trap.num = num;
	trap.rc = rc;
	trap.color = color;

	_vRectTraps.push_back(trap);
}

void PBGManager::setRectColor(wstring strKey, int num, COLORREF color)
{
	mImgIter iter = _mImgBG.find(strKey);

	if (iter == _mImgBG.end())
		return;

	for (int i = 0; i < _vRectTraps.size(); i++)
	{
		if (_vRectTraps[i].num != num) continue;

		for (int x = _vRectTraps[i].rc.left; x <= _vRectTraps[i].rc.right; x++)
		{
			for (int y = _vRectTraps[i].rc.top; y <= _vRectTraps[i].rc.bottom; y++)
			{
				SetPixel(iter->second->getMemDC(), x, y, color);
			}
		}
	}
}
