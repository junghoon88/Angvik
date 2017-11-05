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

	itemNum = 0;
}

void itemManager::release(void)
{

}

void itemManager::update(void)
{
	
	
	
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
	
	
	//���;�����Ʈ
	for (int i = 0; i < _vItems.size(); i++)
	{
		_vItems[i]->update();

		if (KEYMANAGER->isOnceKeyDown('P'))
		{
			removeItem(i);
		}
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
	Item* it = new Item;
	it->init();
	it->createItem((ITEM_TYPE)RND->getInt(ITEM_TYPE_MAX), (ITEM_KIND)RND->getInt(ITEM_KIND_MAX), ITEM_STATE_IDLE, x, y);
	it->setNum(itemNum++);
		
	_vItems.push_back(it);
}

void itemManager::dropItem(int type, int kind, int state, int x, int y)
{

}


void itemManager::setFieldItem(int i , int j)
{
	Item* field = new Item;
	field->init();
	field->createItem((ITEM_TYPE)j, (ITEM_KIND)i, ITEM_STATE_IDLE, _x, _y);

	_vItems.push_back(field);
}
void itemManager::removeItem(int arrNum)//����������
{
	_vItems[arrNum]->release();
	_vItems.erase(_vItems.begin() + arrNum);
}
void itemManager::Itemcompose(int itemNum, int oilNum)//�������ռ�
{
	//������ Ÿ�� ���� üũ(����, ���̸� ����)
	int itemtype = (int)_vItems[itemNum]->getType();
	if (itemtype >= ITEM_TYPE_OIL)
		return;

	//���Ϲ�ȣ �������� ������ �ƴϸ� ����
	if (_vItems[oilNum]->getType() != ITEM_TYPE_OIL)
		return;

	//�������� kind�� ������ kind�� �ٲ��ش�.
	_vItems[itemNum]->setKind(_vItems[oilNum]->getKind());
	//�������� �������� �ִ�ġ�� �ٲ��ش�.
	_vItems[itemNum]->setdurabilityMax();

	//������ ���Ϳ��� �����Ѵ�.
	_vItems[oilNum]->release();
	_vItems.erase(_vItems.begin() + oilNum);
}