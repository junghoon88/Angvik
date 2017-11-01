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

}

void itemManager::release(void)
{

}

void itemManager::update(void)
{
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		Item* it = new Item;
		it->init();
		it->createItem(ITEM_TYPE_SWORD, ITEM_KIND_WHITE, _ptMouse.x, _ptMouse.y);

		_vItems.push_back(it);
	}


}

void itemManager::render(void)
{
	for (int i = 0; i < _vItems.size(); i++)
	{
		_vItems[i]->render();
	}
}

