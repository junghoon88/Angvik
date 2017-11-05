#include "stdafx.h"
#include "itemManager.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "stageManager.h"

itemManager::itemManager()
	: _pm(NULL)
{
}


itemManager::~itemManager()
{
}


void itemManager::init(void)
{
	_x = 350;
	_y = 200;
	i = j = 0;

	itemNum = 0;

}

void itemManager::release(void)
{

}

void itemManager::update(void)
{

	if (_pm != NULL)
	{
		float x = _pm->getPlayer()->getX();
		float y = _pm->getPlayer()->getY();
		float hx = _pm->getPlayer()->getHandX();
		float hy = _pm->getPlayer()->getHandY();

		for (int i = 0; i < _vItems.size(); i++)
		{
			
			
			if (_vItems[i]->getState() == ITEM_STATE_INPLAYER)
			{
				switch (_vItems[i]->getType())
				{
				case ITEM_TYPE_HEAD :
						_vItems[i]->targetPlayer(x, y-30);
					break;
				case ITEM_TYPE_SWORD:
						_vItems[i]->targetPlayer(hx, hy);
					break;
				case ITEM_TYPE_STAFF:
						_vItems[i]->targetPlayer(hx, hy);
					break;
				case ITEM_TYPE_LANCE:
						_vItems[i]->targetPlayer(hx, hy);
					break;
				case ITEM_TYPE_BOOMERANG:
						_vItems[i]->targetPlayer(hx, hy);
					break;
				}
			}


		}
	}
	
	
	if (issetting)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				setFieldItem(i, j);
			}
			_x += 150;
		}
		issetting = false;
	}
	
	
	//벡터업데이트
	for (int i = 0; i < _vItems.size(); i++)
	{
		_vItems[i]->update();
		
	}
	//내구도 0되면 아이템 삭제
	for (int i = 0; i < _vItems.size(); i++)
	{
		if (_vItems[i]->getdurability() == 0)
			removeItem(i);
	}
}

void itemManager::render(void)
{

	for (int i = 0; i < _vItems.size(); i++)
	{
		_vItems[i]->render();
	}
}

void itemManager::setItem(float x , float y)
{
	Item* it = new Item;
	it->init();
	it->createItem((ITEM_TYPE)RND->getInt(ITEM_TYPE_MAX), (ITEM_KIND)RND->getInt(ITEM_KIND_MAX), ITEM_STATE_IDLE, x, y);
	it->setNum(itemNum++);
		
	_vItems.push_back(it);
}



void itemManager::setFieldItem(int i , int j)
{
	Item* field = new Item;
	field->init();
	field->createItem((ITEM_TYPE)j, (ITEM_KIND)i, ITEM_STATE_IDLE, _x, _y);

	_vItems.push_back(field);
}
void itemManager::removeItem(int arrNum)//아이템제거
{
	_vItems[arrNum]->release();
	_vItems.erase(_vItems.begin() + arrNum);
}
void itemManager::Itemcompose(int itemNum, int oilNum)//아이템합성
{
	//아이템 타입 에러 체크(오일, 알이면 리턴)
	int itemtype = (int)_vItems[itemNum]->getType();
	if (itemtype >= ITEM_TYPE_OIL)
		return;

	//오일번호 아이템이 오일이 아니면 리턴
	if (_vItems[oilNum]->getType() != ITEM_TYPE_OIL)
		return;

	//아이템의 kind를 오일의 kind로 바꿔준다.
	_vItems[itemNum]->setKind(_vItems[oilNum]->getKind());
	//아이템의 내구도를 최대치로 바꿔준다.
	_vItems[itemNum]->setdurabilityMax();

	//오일을 벡터에서 삭제한다.
	_vItems[oilNum]->release();
	_vItems.erase(_vItems.begin() + oilNum);
}