#include "stdafx.h"
#include "inven.h"
#include "itemManager.h"
#include "invenBird.h"

inven::inven()
	: _im(NULL), _ib(NULL)
{
}


inven::~inven()
{
}

void inven::init(void)
{
	_isMenew = false;
	_isItem = false;
	_isOils = false;
	_isInven = false;
	_isCompose = false;
	_isEquip = false;

	_goldOils = _blackOils = _whiteOils = 0;

	_timeCount = 0;
	_selectNum = 0;
	_frameX = 0;

	_inventoryMax = 4;
	_inventoryNum = 0;
}

void inven::release(void)
{

}

void inven::update(void)
{

}

void inven::update(float x, float y)
{
	_timeCount += TIMEMANAGER->getElapsedTime();
	if (_timeCount > 0.07)
	{
		_timeCount = 0;
		_frameX++;
		if (_frameX >= 8) _frameX = 0;
	}

	if (KEYMANAGER->isStayKeyDown(BTN_PLAYER_INVENTORY) && !_isInven)
	{
		_isInven = true;
		_isMenew = true;
		_selectNum = 0;
		SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
	}

	//선택지 위치 업데이트
	IMAGEMANAGER->findImage(L"아이템선택")->setCoord(_selectPoint[_selectNum]);

	menewBoxUpdate(x, y);
	itemBoxUpdate(x, y);
	oilsBoxUpdate(x, y);
	equipBoxUpdate(x, y);
	composeBoxUpdate(x, y);
}

void inven::render(void)
{
	if (!_isInven)
		return;

	if (_isMenew || _isEquip)	IMAGEMANAGER->findImage(L"inventory")->render(200);
	if (_isItem)	IMAGEMANAGER->findImage(L"itemBox")->render(200);
	if (_isOils)	IMAGEMANAGER->findImage(L"oilsBox")->render(200);

	IMAGEMANAGER->findImage(L"아이템선택")->frameRender(_frameX, 0, 255);


	if (_isMenew)
	{
		IMAGEMANAGER->findImage(L"item")->render();
		IMAGEMANAGER->findImage(L"oils")->render();
		IMAGEMANAGER->findImage(L"close")->render();
	}
	else if (_isItem)
	{
		for (int i = 0; i < _vInvenItems.size(); i++)
		{
			_vInvenItems[i]->getImage()->render();
		}


		IMAGEMANAGER->findImage(L"back")->render();
	}
	else if (_isOils)
	{
		IMAGEMANAGER->findImage(L"back")->render();
		//for (int i = 0; i < _vItems.size(); i++)
		//{
		//	if (_vItems[i]->getType() == ITEM_TYPE_OIL)
		//	{
		//		if (_vItems[i]->getKind() == ITEM_KIND_WHITE)
		//		{
		//			_vItems[i]->render();
		//		}
		//		if (_vItems[i]->getKind() == ITEM_KIND_BLACK)
		//		{
		//			_vItems[i]->render();
		//		}
		//		if (_vItems[i]->getKind() == ITEM_KIND_GOLD)
		//		{
		//			_vItems[i]->render();
		//		}
		//	}
		//}
	}
	else if (_isEquip)
	{
		IMAGEMANAGER->findImage(L"equip")->render();
		IMAGEMANAGER->findImage(L"drop")->render();
		IMAGEMANAGER->findImage(L"back")->render();
	}


}

#if 0
void inven::itemUpdate(void)
{
	vItems item = _im->getVItem();

	for (int i = 0; i < item.size(); i++)
	{
		if (item[i]->getState() == ITEM_STATE_ININVEN)
		{
			if (_vItems.size() == 0)
			{
				_vItems.push_back(item[i]);
			}
			else
			{
				for (int j = 0; j < _vItems.size(); j++)
				{
					if (_vItems[j]->getNum() == item[i]->getNum()) break;

					if ((int)_vItems[j]->getType() < ITEM_TYPE_OIL)
					{

					}
				
					if (j == _vItems.size() - 1)
					{
						_vItems.push_back(item[i]);
					}
				}
			}
		}
	}
}
#endif

bool inven::insertInven(int num)
{
	vector<Item*> items = _im->getVItem();

	for (int i = 0; i < items.size(); i++)
	{
		if (num != items[i]->getNum()) continue;

		Item* it = items[i];
		if ((int)it->getType() < ITEM_TYPE_OIL)
		{
			if (_vInvenItems.size() >= _inventoryMax)
			{
				return false;
			}
			else
			{
				_vInvenItems.push_back(it);
				return true;
			}
		}
		else if (it->getType() == ITEM_TYPE_OIL)
		{
			if (_vInvenOils.size() >= _inventoryMax)
			{
				return false;
			}
			else
			{
				_vInvenOils.push_back(it);
				return true;
			}
		}
		else if (it->getType() == ITEM_TYPE_EGG)
		{
			_vInvenEggs.push_back(it);
			return true;
		}
	}

	return false;
}

void inven::menewBoxUpdate(float x, float y)
{
	//상시 인벤 위치 업데이트
	IMAGEMANAGER->findImage(L"inventory")->setCoord({ x + 40, y - IMAGEMANAGER->findImage(L"inventory")->getRealSize().y - 20 });
	if (IMAGEMANAGER->findImage(L"inventory")->getCoord().y < 0) IMAGEMANAGER->findImage(L"inventory")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x, 0 });
	IMAGEMANAGER->findImage(L"item")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x + 45, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 45 });
	IMAGEMANAGER->findImage(L"oils")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x + 45, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 90 });
	IMAGEMANAGER->findImage(L"close")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x + 40, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 132 });

	if (_isMenew)
	{
		_selectPoint[0] = { IMAGEMANAGER->findImage(L"inventory")->getCoord().x, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 35 };
		_selectPoint[1] = { IMAGEMANAGER->findImage(L"inventory")->getCoord().x, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 80 };
		_selectPoint[2] = { IMAGEMANAGER->findImage(L"inventory")->getCoord().x, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 122 };

		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_DOWN))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum++;
		}
		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_UP))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum--;
		}
		if (_selectNum > 2) _selectNum = 0;
		if (_selectNum < 0) _selectNum = 2;

		if (_selectNum == 0 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			_selectNum = 0;
			_isMenew = false;
			_isItem = true;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
		if (_selectNum == 1 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			_selectNum = 0;
			_isMenew = false;
			_isOils = true;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
		if ((_selectNum == 2 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND)) || KEYMANAGER->isOnceKeyDown(BTN_PLAYER_JUMP))
		{
			_selectNum = 0;
			_isMenew = false;
			_isInven = false;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
	}
}

void inven::itemBoxUpdate(float x, float y)
{
	_inventoryNum = 0;

	//상시 아이템박스 위치 업데이트
	D3DXVECTOR2 itemBoxCoord = { x + 40, y - IMAGEMANAGER->findImage(L"itemBox")->getRealSize().y - 20 };
	if (itemBoxCoord.y < 0) 
		itemBoxCoord.y = 0;

	IMAGEMANAGER->findImage(L"itemBox")->setCoord(itemBoxCoord);
	IMAGEMANAGER->findImage(L"back")->setCoord(itemBoxCoord.x + 40, itemBoxCoord.y + 215);

	if (_isItem)
	{
		_selectPoint[0] = { itemBoxCoord.x, itemBoxCoord.y + 35 };
		_selectPoint[1] = { itemBoxCoord.x, itemBoxCoord.y + 80 };
		_selectPoint[2] = { itemBoxCoord.x, itemBoxCoord.y + 125 };
		_selectPoint[3] = { itemBoxCoord.x, itemBoxCoord.y + 170 };
		_selectPoint[4] = { itemBoxCoord.x, itemBoxCoord.y + 205 };

		for (int i = 0; i < _vInvenItems.size(); i++)
		{
			Sprite* img = _vInvenItems[i]->getImage();
			img->setCoord(_selectPoint[i]);
			img->setRotate(0.0f);
		}

		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_DOWN))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum++;
		}
		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_UP))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum--;
		}
		if (_selectNum > 4) _selectNum = 0;
		if (_selectNum < 0) _selectNum = 4;

		if ((_selectNum >= 0 && _selectNum < 4) && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			_selectNum = 0;
			_isItem = false;
			_isEquip = true;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
		if ((_selectNum == 4 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND)) || KEYMANAGER->isOnceKeyDown(BTN_PLAYER_JUMP))
		{
			_selectNum = 0;
			_isMenew = true;
			_isItem = false;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
	}
}

void inven::oilsBoxUpdate(float x, float y)
{
	//상시 오일박스 위치 업데이트
	IMAGEMANAGER->findImage(L"oilsBox")->setCoord({ x + 40,  y - IMAGEMANAGER->findImage(L"oilsBox")->getRealSize().y - 20 });
	if (IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y < 0) IMAGEMANAGER->findImage(L"oilsBox")->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, 0 });
	IMAGEMANAGER->findImage(L"back")->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x + 40, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 175 });

	if (_isOils)
	{
		_selectPoint[0] = { IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 35 };
		_selectPoint[1] = { IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 80 };
		_selectPoint[2] = { IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 125 };
		_selectPoint[3] = { IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 165 };

		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_DOWN))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum++;
		}
		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_UP))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum--;
		}
		if (_selectNum > 3) _selectNum = 0;
		if (_selectNum < 0) _selectNum = 3;

		if ((_selectNum == 3 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND)) || KEYMANAGER->isOnceKeyDown(BTN_PLAYER_JUMP))
		{
			_selectNum = 0;
			_isMenew = true;
			_isOils = false;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}

		_whiteOils = _blackOils = _goldOils = 0;

		//for (int i = 0; i < _vItems.size(); i++)
		//{
		//	if (_vItems[i]->getType() == ITEM_TYPE_OIL)
		//	{
		//		if (_vItems[i]->getKind() == ITEM_KIND_WHITE)
		//		{
		//			_whiteOils++;
		//			Sprite* img = _vItems[i]->getImage();
		//			img->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x + IMAGEMANAGER->findImage(L"골드오일")->getSize().x * _whiteOils, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 45 });
		//		}
		//		if (_vItems[i]->getKind() == ITEM_KIND_BLACK)
		//		{
		//			_blackOils++;
		//			Sprite* img = _vItems[i]->getImage();
		//			img->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x + IMAGEMANAGER->findImage(L"골드오일")->getSize().x * _whiteOils, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 90 });
		//		}	
		//		if (_vItems[i]->getKind() == ITEM_KIND_GOLD)
		//		{
		//			_goldOils++;
		//			Sprite* img = _vItems[i]->getImage();
		//			img->setCoord({ IMAGEMANAGER->findImage(L"oilsBox")->getCoord().x + IMAGEMANAGER->findImage(L"골드오일")->getSize().x * _whiteOils, IMAGEMANAGER->findImage(L"oilsBox")->getCoord().y + 135 });
		//		}
		//	}
		//}
	}
}

void inven::equipBoxUpdate(float x, float y)
{
	//상시 인벤 위치 업데이트
	IMAGEMANAGER->findImage(L"equip")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x + 45, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 45 });
	IMAGEMANAGER->findImage(L"drop")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x + 45, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 90 });
	IMAGEMANAGER->findImage(L"back")->setCoord({ IMAGEMANAGER->findImage(L"inventory")->getCoord().x + 45, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 132 });

	if (_isEquip)
	{
		_selectPoint[0] = { IMAGEMANAGER->findImage(L"inventory")->getCoord().x, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 35 };
		_selectPoint[1] = { IMAGEMANAGER->findImage(L"inventory")->getCoord().x, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 80 };
		_selectPoint[2] = { IMAGEMANAGER->findImage(L"inventory")->getCoord().x, IMAGEMANAGER->findImage(L"inventory")->getCoord().y + 122 };

		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_DOWN))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum++;
		}
		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_UP))
		{
			SOUNDMANAGER->play(L"메뉴이동", DATABASE->getVolume());
			_selectNum--;
		}
		if (_selectNum > 2) _selectNum = 0;
		if (_selectNum < 0) _selectNum = 2;

		if (_selectNum == 0 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			
		}
		if (_selectNum == 1 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
		
		}
		if ((_selectNum == 2 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND)) || KEYMANAGER->isOnceKeyDown(BTN_PLAYER_JUMP))
		{
			_selectNum = 0;
			_isEquip = false;
			_isItem = true;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
	}
}

void inven::composeBoxUpdate(float x, float y)
{
}
