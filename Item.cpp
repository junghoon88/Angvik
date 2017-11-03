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
	
	//_rcImg = RectMake(_pt.x, _pt.y, _img->getRealSize().x, _img->getRealSize().y);
	itemCollision = new pixelCollision;
	itemCollision->init();
}

void Item::release(void)
{

}

void Item::update(void)
{
	if (_state == ITEM_STATE_IDLE)
	{
		if (itemCollision->getPixelGroundLT(&_pt.x, &_pt.y, _img->getRealSize().x, _img->getRealSize().y + 10) == false)
		{
			_pt.y += 5;
		}
	}
	_img->setCoord(_pt.x, _pt.y);

}

void Item::render(void)	
{
	//if(KEYMANAGER->isStayKeyDown('R')) IMAGEMANAGER->findImage(L"ÇÈ¼¿")->render();
	
	_img->render();
	
}


void Item::createItem(ITEM_TYPE type, ITEM_KIND kind, ITEM_STATE state,float x, float y)
{

	_type = type;
	_kind = kind;
	_state = state;
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
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ºí·¢Ä®")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢Ä®")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµåÄ®.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"°ñµåÄ®")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµåÄ®")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_LANCE:		//¹«±â-Ã¢
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»ö·£½º.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èò»ö·£½º")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»ö·£½º")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢·£½º.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ºí·¢·£½º")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢·£½º")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµå·£½º.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"°ñµå·£½º")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµå·£½º")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_BOOMERANG:	//¹«±â-ºÎ¸Þ¶û
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»öºÎ¸Þ¶û.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èò»öºÎ¸Þ¶û")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»öºÎ¸Þ¶û")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢ºÎ¸Þ¶û.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ºí·¢ºÎ¸Þ¶û")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢ºÎ¸Þ¶û")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµåºÎ¸Þ¶û.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"°ñµåºÎ¸Þ¶û")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµåºÎ¸Þ¶û")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_STAFF:		//¹«±â-ÁöÆÎÀÌ
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»öÁöÆÎÀÌ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èò»öÁöÆÎÀÌ")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»öÁöÆÎÀÌ")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢ÁöÆÎÀÌ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ºí·¢ÁöÆÎÀÌ")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢ÁöÆÎÀÌ")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢ÁöÆÎÀÌ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ºí·¢ÁöÆÎÀÌ")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢ÁöÆÎÀÌ")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_HEAD:			//¹æ¾î±¸-¸Ó¸®
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/¹éÅõ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"¹éÅõ")->getRealSize().x, IMAGEMANAGER->findImage(L"¹éÅõ")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ÈæÅõ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ÈæÅõ")->getRealSize().x, IMAGEMANAGER->findImage(L"ÈæÅõ")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/È²Åõ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"È²Åõ")->getRealSize().x, IMAGEMANAGER->findImage(L"È²Åõ")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_BODY:			//¹æ¾î±¸-°©¿Ê
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/¹é°©.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"¹é°©")->getRealSize().x, IMAGEMANAGER->findImage(L"¹é°©")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/Èæ°©.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èæ°©")->getRealSize().x, IMAGEMANAGER->findImage(L"Èæ°©")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/È²°©.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"È²°©")->getRealSize().x, IMAGEMANAGER->findImage(L"È²°©")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_FOOT:			//¹æ¾î±¸-½Å¹ß
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/¹é½Å.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"¹é½Å")->getRealSize().x, IMAGEMANAGER->findImage(L"¹é½Å")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/Èæ½Å.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èæ½Å")->getRealSize().x, IMAGEMANAGER->findImage(L"Èæ½Å")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/È²½Å.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"È²½Å")->getRealSize().x, IMAGEMANAGER->findImage(L"È²½Å")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_OIL:			//
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»ö¿ÀÀÏ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èò»ö¿ÀÀÏ")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»ö¿ÀÀÏ")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢¿ÀÀÏ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ºí·¢¿ÀÀÏ")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢¿ÀÀÏ")->getRealSize().y);
			_durability = 4;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµå¿ÀÀÏ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"°ñµå¿ÀÀÏ")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµå¿ÀÀÏ")->getRealSize().y);
			_durability = 4;
		}
		break;
	case ITEM_TYPE_EGG:
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/¾Ë.png");
			_img->setCoord(x, y);
			_img->init();
			//_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"¾Ë")->getRealSize().x, IMAGEMANAGER->findImage(L"¾Ë")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/¾Ë.png");
			_img->setCoord(x, y);
			_img->init();
			//_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"¾Ë")->getRealSize().x, IMAGEMANAGER->findImage(L"¾Ë")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/¾Ë.png");
			_img->setCoord(x, y);
			_img->init();
			//_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"¾Ë")->getRealSize().x, IMAGEMANAGER->findImage(L"¾Ë")->getRealSize().y);
			
		}
		break;
	}
	////////////////////ÇÈ¼¿Ãæµ¹
	
}

