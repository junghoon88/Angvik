#include "stdafx.h"
#include "Item.h"

Item::Item()
{
}


Item::~Item()
{
}

void Item::init(void)
{
	_img = NULL;
}

void Item::release(void)
{

}

void Item::update(void)	
{

}

void Item::render(void)	
{

}


void Item::createItem(ITEM_TYPE type, ITEM_KIND kind, float x, float y)
{

	_type = type;
	_kind = kind;
	_pt.x = x;
	_pt.y = y;

	switch (_type)
	{
	case ITEM_TYPE_SWORD:		//����-��
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"���Į");
			_img->init();
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			//_img = new Sprite(DEVICE, L"���Į");
			_img->init();
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			//_img = new Sprite(DEVICE, L"���Į");
			_img->init();
		}
		break;
	case ITEM_TYPE_LENCE:		//����-â
		break;
	case ITEM_TYPE_BOOMERANG:	//����-�θ޶�
		break;
	case ITEM_TYPE_STAFF:		//����-������
		break;
	case ITEM_TYPE_HEAD:			//��-�Ӹ�
		break;
	case ITEM_TYPE_BODY:			//��-����
		break;
	case ITEM_TYPE_FOOT:			//��-�Ź�
		break;
	case ITEM_TYPE_OIL:			//
		break;
	case ITEM_TYPE_EGG:			//
		break;

	}
}