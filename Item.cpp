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
	
	_rcImg = RectMake(300, 100, 100, 100);
	probeY = _rcImg.bottom;
}

void Item::release(void)
{

}

void Item::update(void)	
{

}

void Item::render(void)	
{
	//if(KEYMANAGER->isStayKeyDown('R')) IMAGEMANAGER->findImage(L"ÇÈ¼¿")->render();
	
	_img->render();
	
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
			_img = new Sprite(DEVICE, L"image/item/Èò»öÄ®.png");
			
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èò»öÄ®")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»öÄ®")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢Ä®.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµåÄ®.png");
			_img->init();
		}
		break;
	case ITEM_TYPE_LENCE:		//¹«±â-Ã¢
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»ö·£½º.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢·£½º.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµå·£½º.png");
			_img->init();
		}
		break;
	case ITEM_TYPE_BOOMERANG:	//¹«±â-ºÎ¸Þ¶û
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»öºÎ¸Þ¶û.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢ºÎ¸Þ¶û.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµåºÎ¸Þ¶û.png");
			_img->init();
		}
		break;
	case ITEM_TYPE_STAFF:		//¹«±â-ÁöÆÎÀÌ
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»öÁöÆÎÀÌ.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢ÁöÆÎÀÌ.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢ÁöÆÎÀÌ.png");
			_img->init();
		}
		break;
	case ITEM_TYPE_HEAD:			//¹æ¾î±¸-¸Ó¸®
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/¹éÅõ.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ÈæÅõ.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/È²Åõ.png");
			_img->init();
		}
		break;
	case ITEM_TYPE_BODY:			//¹æ¾î±¸-°©¿Ê
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/¹é°©.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/Èæ°©.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/È²°©.png");
			_img->init();
		}
		break;
	case ITEM_TYPE_FOOT:			//¹æ¾î±¸-½Å¹ß
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/¹é½Å.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/Èæ½Å.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/È²½Å.png");
			_img->init();
		}
		break;
	case ITEM_TYPE_OIL:			//
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»ö¿ÀÀÏ.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢¿ÀÀÏ.png");
			_img->init();
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµå¿ÀÀÏ.png");
			_img->init();
		}
		break;
	}
	////////////////////ÇÈ¼¿Ãæµ¹
	probeY = _rcImg.bottom;

	for (int i = probeY - 3; i < probeY+5; ++i)
	{
		COLORREF color = PBGMANAGER->getPixelColor(L"Å×½ºÆ®¹è°æ", probeY, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 0 && b == 0)) // °üÅëÇü ¹Ù´Ú
		{
			probeY = i + _rcImg.bottom;
			break;
		}
		else
		{
			_rcImg.top += 5;
			_rcImg.bottom += 5;
		}
	}
}

void Item::createEgg(ITEM_TYPE type, float x, float y)
{
	_type = type;
	_pt.x = x;
	_pt.y = y;
	
	_img = new Sprite(DEVICE, L"image/item/¾Ë.png");
	_img->setCoord(x, y);
	_img->init();
		


}