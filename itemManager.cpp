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
	IMAGEMANAGER->findImage(L"테스트배경")->render();
	
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
		it->createItem(ITEM_TYPE_SWORD, ITEM_KIND_WHITE, x, y);

		x += 100;

		_vItems.push_back(it);
	}
	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		Item* it = new Item;
		it->init();
		it->createEgg(ITEM_TYPE_EGG, x, y);
		
		x += 100;
		_vItems.push_back(it);
	}
}