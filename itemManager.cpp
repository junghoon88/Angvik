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
	x = y = 100;
}

void itemManager::release(void)
{

}

void itemManager::update(void)
{
	setItem();
	

}

void itemManager::render(void)
{
	IMAGEMANAGER->findImage(L"Stage1-BG")->render();
	
	for (int i = 0; i < _vItems.size(); i++)
	{
		_vItems[i]->render();
	}
}

void itemManager::setItem(void)
{
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		Item* it = new Item;
		it->init();
		it->createItem((ITEM_TYPE)RND->getInt(ITEM_TYPE_MAX), (ITEM_KIND)RND->getInt(ITEM_KIND_MAX), ITEM_STATE_IDLE, x, y);
		
		x += 100;

		_vItems.push_back(it);
	}

}