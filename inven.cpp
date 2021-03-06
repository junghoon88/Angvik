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

	_timeCount = 0;
	_selectNum = 0;
	_frameX = 0;

	_goldOils = _blackOils = _whiteOils = 0;

	_inventoryMax = 4;
	_inventoryNum = 0;

	_swapItemNum = 0;
	_swapInvenNum = 0;

	_enchantItemNum = 0;
	_enchantInvenNum = 0;

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
	if (_isItem || _isCompose)	IMAGEMANAGER->findImage(L"itemBox")->render(200);
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
		for (int i = 0; i < _vInvenOils.size(); i++)
		{
			_vInvenOils[i]->getImage()->render();
		}
		IMAGEMANAGER->findImage(L"back")->render();
	}
	else if (_isEquip)
	{
		IMAGEMANAGER->findImage(L"equip")->render();
		IMAGEMANAGER->findImage(L"drop")->render();
		IMAGEMANAGER->findImage(L"back")->render();
	}
	else if (_isCompose)
	{
		for (int i = 0; i < _vInvenItems.size(); i++)
		{
			_vInvenItems[i]->getImage()->render();
		}
		IMAGEMANAGER->findImage(L"back")->render();
	}
}


bool inven::insertInven(int num)
{
	vector<Item*> items = _im->getVItem();

	_whiteOils = _goldOils = _blackOils = 0;

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
			if (it->getKind() == ITEM_KIND_WHITE)
			{
				_whiteOils++;
				if (_whiteOils == _inventoryMax) return false;
				_vInvenOils.push_back(it);
				return true;
			}
			if (it->getKind() == ITEM_KIND_GOLD)
			{
				_goldOils++;
				if (_goldOils == _inventoryMax) return false;
				_vInvenOils.push_back(it);
				return true;
			}
			if (it->getKind() == ITEM_KIND_BLACK)
			{
				_blackOils++;
				if (_blackOils == _inventoryMax) return false;
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
			img->setCoord({ _selectPoint[i].x + IMAGEMANAGER->findImage(L"itemBox")->getSize().x / 2 - img->getSize().x / 2, _selectPoint[i].y + IMAGEMANAGER->findImage(L"아이템선택")->getSize().y / 2 - img->getSize().y / 2 });
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

		if ((_selectNum < 4) && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			if (_selectNum < _vInvenItems.size())
			{
				_swapInvenNum = _selectNum;
				_swapItemNum = _vInvenItems[_selectNum]->getNum();

				_selectNum = 0;
				_isItem = false;
				_isEquip = true;
				SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
			}
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
	D3DXVECTOR2 oilsBoxCoord = { x + 40,  y - IMAGEMANAGER->findImage(L"oilsBox")->getRealSize().y - 20 };
	if (oilsBoxCoord.y < 0)
		oilsBoxCoord.y = 0;

	IMAGEMANAGER->findImage(L"oilsBox")->setCoord(oilsBoxCoord);
	IMAGEMANAGER->findImage(L"back")->setCoord(oilsBoxCoord.x + 40, oilsBoxCoord.y + 175);

	if (_isOils)
	{
		_selectPoint[0] = { oilsBoxCoord.x, oilsBoxCoord.y + 35 };
		_selectPoint[1] = { oilsBoxCoord.x, oilsBoxCoord.y + 80 };
		_selectPoint[2] = { oilsBoxCoord.x, oilsBoxCoord.y + 125 };
		_selectPoint[3] = { oilsBoxCoord.x, oilsBoxCoord.y + 165 };

		for (int i = 0; i < _vInvenOils.size(); i++)
		{
			Sprite* img = _vInvenOils[i]->getImage();
			img->setCoord(_selectPoint[i].x + 40, _selectPoint[i].y + 10);
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
		if (_selectNum > 3) _selectNum = 0;
		if (_selectNum < 0) _selectNum = 3;

		if (_selectNum < 3 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			if (_selectNum < _vInvenOils.size())
			{
				_enchantItemNum = _selectNum;
				_enchantInvenNum = _vInvenOils[_selectNum]->getNum();

				_selectNum = 0;
				_isOils = false;
				_isCompose = true;
				SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
			}
		}

		if ((_selectNum == 3 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND)) || KEYMANAGER->isOnceKeyDown(BTN_PLAYER_JUMP))
		{
			_selectNum = 0;
			_isMenew = true;
			_isOils = false;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}

		_goldNum = _blackNum = _whiteNum = 0;

		//for (int i = 0; i < _vInvenOils.size(); i++)
		//{
		//	Sprite* img = _vInvenOils[i]->getImage();
		//	if (_vInvenOils[i]->getKind() == ITEM_KIND_WHITE)
		//	{
		//		img->setCoord(_selectPoint[(int)_vInvenOils[i]->getKind()].x + 40 + IMAGEMANAGER->findImage(L"흰색오일")->getSize().x * _whiteNum, _selectPoint[(int)_vInvenOils[i]->getKind()].y + 7);
		//		img->setRotate(0.0f);
		//		_whiteNum++;
		//	}
		//	if (_vInvenOils[i]->getKind() == ITEM_KIND_GOLD)
		//	{
		//		img->setCoord(_selectPoint[(int)_vInvenOils[i]->getKind()].x + 40 + IMAGEMANAGER->findImage(L"골드오일")->getSize().x * _goldNum, _selectPoint[(int)_vInvenOils[i]->getKind()].y + 7);
		//		img->setRotate(0.0f);
		//		_goldNum++;
		//	}
		//	if (_vInvenOils[i]->getKind() == ITEM_KIND_BLACK)
		//	{
		//		img->setCoord(_selectPoint[(int)_vInvenOils[i]->getKind()].x + 35 + IMAGEMANAGER->findImage(L"블랙오일")->getSize().x * _blackNum, _selectPoint[(int)_vInvenOils[i]->getKind()].y + 7);
		//		img->setRotate(0.0f);
		//		_blackNum++;
		//	}
		//}
	}
}

void inven::equipBoxUpdate(float x, float y)
{
	//상시 인벤 위치 업데이트
	D3DXVECTOR2 inventoryCoord = IMAGEMANAGER->findImage(L"inventory")->getCoord();

	if (_isEquip)
	{
		IMAGEMANAGER->findImage(L"equip")->setCoord({ inventoryCoord.x + 45, inventoryCoord.y + 45 });
		IMAGEMANAGER->findImage(L"drop")->setCoord({ inventoryCoord.x + 45, inventoryCoord.y + 90 });
		IMAGEMANAGER->findImage(L"back")->setCoord({ inventoryCoord.x + 45, inventoryCoord.y + 132 });
		_selectPoint[0] = { inventoryCoord.x, inventoryCoord.y + 35 };
		_selectPoint[1] = { inventoryCoord.x, inventoryCoord.y + 80 };
		_selectPoint[2] = { inventoryCoord.x, inventoryCoord.y + 122 };

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
			//장착
			//1. 장착할 아이템의 타입을 찾는다.
			ITEM_TYPE swapItemType;	//
			int swapItemVectorNum;	//스왑할 아이템의 아이템매니저 벡터번호
			vector<Item*> items = _im->getVItem();
			for (int i = 0; i < items.size(); i++)
			{
				if (_swapItemNum == items[i]->getNum())
				{
					swapItemType = items[i]->getType();
					swapItemVectorNum = i;
					break;
				}
			}

			//2. 장착할 아이템 타입이 현재 플레이어가 장착중인지 확인하고 스왑한다.
			bool swap = false;
			for (int i = 0; i < items.size(); i++)
			{
				if (items[i]->getState() != ITEM_STATE_INPLAYER) continue;
				if ((int)items[i]->getType() <= ITEM_TYPE_STAFF && (int)swapItemType <= ITEM_TYPE_STAFF)
				{
					swap = true;
					items[swapItemVectorNum]->setState(ITEM_STATE_INPLAYER);
					_vInvenItems[_swapInvenNum] = items[i];

					items[i]->setState(ITEM_STATE_ININVEN);

					break;
				}
				else if (items[i]->getType() == swapItemType)
				{
					swap = true;
					items[swapItemVectorNum]->setState(ITEM_STATE_INPLAYER);
					_vInvenItems[_swapInvenNum] = items[i];

					items[i]->setState(ITEM_STATE_ININVEN);

					break;
				}
			}

			//3. 스왑이 안되면 장착한다.
			if (!swap)
			{
				items[swapItemVectorNum]->setState(ITEM_STATE_INPLAYER);
				_vInvenItems.erase(_vInvenItems.begin() + _swapInvenNum);
			}

			_selectNum = 0;
			_isEquip = false;
			_isItem = true;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
		if (_selectNum == 1 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			//드랍
			vector<Item*> items = _im->getVItem();
			for (int i = 0; i < items.size(); i++)
			{
				if (_swapItemNum == items[i]->getNum())
				{
					items[i]->setPoint(x, y);
					items[i]->setState(ITEM_STATE_IDLE);
					_vInvenItems.erase(_vInvenItems.begin() + _swapInvenNum);
					break;
				}
			}

			_selectNum = 0;
			_isEquip = false;
			_isItem = true;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
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
	//상시 아이템박스 위치 업데이트
	D3DXVECTOR2 itemBoxCoord = { x + 40, y - IMAGEMANAGER->findImage(L"itemBox")->getRealSize().y - 20 };
	if (itemBoxCoord.y < 0)
		itemBoxCoord.y = 0;

	if (_isCompose)
	{
		IMAGEMANAGER->findImage(L"itemBox")->setCoord(itemBoxCoord);
		IMAGEMANAGER->findImage(L"back")->setCoord(itemBoxCoord.x + 40, itemBoxCoord.y + 215);

		_selectPoint[0] = { itemBoxCoord.x, itemBoxCoord.y + 35 };
		_selectPoint[1] = { itemBoxCoord.x, itemBoxCoord.y + 80 };
		_selectPoint[2] = { itemBoxCoord.x, itemBoxCoord.y + 125 };
		_selectPoint[3] = { itemBoxCoord.x, itemBoxCoord.y + 170 };
		_selectPoint[4] = { itemBoxCoord.x, itemBoxCoord.y + 205 };

		for (int i = 0; i < _vInvenItems.size(); i++)
		{
			Sprite* img = _vInvenItems[i]->getImage();
			img->setCoord({ _selectPoint[i].x + IMAGEMANAGER->findImage(L"itemBox")->getSize().x / 2 - img->getSize().x / 2, _selectPoint[i].y + IMAGEMANAGER->findImage(L"아이템선택")->getSize().y / 2 - img->getSize().y / 2 });
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

		if ((_selectNum < 4) && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			if (_selectNum < _vInvenItems.size())
			{
				_im->Itemcompose(_vInvenItems[_selectNum]->getNum(), _enchantInvenNum);
				_vInvenOils.erase(_vInvenOils.begin() + _enchantItemNum);

				_selectNum = 0;
				_isCompose = false;
				_isMenew = true;
				SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
			}
		}
		if ((_selectNum == 4 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND)) || KEYMANAGER->isOnceKeyDown(BTN_PLAYER_JUMP))
		{
			_selectNum = 0;
			_isCompose = false;
			_isOils = true;
			SOUNDMANAGER->play(L"메뉴선택", DATABASE->getVolume());
		}
	}
}
