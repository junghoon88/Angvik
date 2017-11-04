#include "stdafx.h"
#include "itemManager.h"


itemManager::itemManager()
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
}

void itemManager::release(void)
{

}

void itemManager::update(void)
{
	
	setItem(_x,_y);
	
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
}

void itemManager::render(void)
{
	IMAGEMANAGER->findImage(L"Stage1-BG")->render();
	
	for (int i = 0; i < _vItems.size(); i++)
	{
		_vItems[i]->render();
	}
}

void itemManager::setItem(float x , float y)
{
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		Item* it = new Item;
		it->init();
		it->createItem((ITEM_TYPE)RND->getInt(ITEM_TYPE_MAX), (ITEM_KIND)RND->getInt(ITEM_KIND_MAX), ITEM_STATE_IDLE, x, y);
		
		
		_vItems.push_back(it);
	}

}
void itemManager::setFieldItem(int i , int j)
{
	Item* field = new Item;
	field->init();
	field->createItem((ITEM_TYPE)j, (ITEM_KIND)i, ITEM_STATE_IDLE, _x, _y);

	

		_vItems.push_back(field);
}