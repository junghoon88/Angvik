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
	case ITEM_TYPE_SWORD:		//¹«±â-°Ë
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"Èò»öÄ®");
			_img->init();
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			//_img = new Sprite(DEVICE, L"Èò»öÄ®");
			_img->init();
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			//_img = new Sprite(DEVICE, L"Èò»öÄ®");
			_img->init();
		}
		break;
	case ITEM_TYPE_LENCE:		//¹«±â-Ã¢
		break;
	case ITEM_TYPE_BOOMERANG:	//¹«±â-ºÎ¸Þ¶û
		break;
	case ITEM_TYPE_STAFF:		//¹«±â-ÁöÆÎÀÌ
		break;
	case ITEM_TYPE_HEAD:			//¹æ¾î±¸-¸Ó¸®
		break;
	case ITEM_TYPE_BODY:			//¹æ¾î±¸-°©¿Ê
		break;
	case ITEM_TYPE_FOOT:			//¹æ¾î±¸-½Å¹ß
		break;
	case ITEM_TYPE_OIL:			//
		break;
	case ITEM_TYPE_EGG:			//
		break;

	}
}