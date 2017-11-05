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

	targetX = 0.0f;
	targetY = 0.0f;
}

void Item::release(void)
{

}

void Item::update(void)
{
	//if (_type == ITEM_TYPE_SWORD)
	//{
	//	//if (_kind == ITEM_KIND_WHITE)
	//	//{
	//		if (KEYMANAGER->isStayKeyDown(VK_UP)) _pt.y -= 5;
	//		if (KEYMANAGER->isStayKeyDown(VK_DOWN))_pt.y += 5;
	//		if (KEYMANAGER->isStayKeyDown(VK_LEFT))_pt.x -= 5;
	//		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))_pt.x += 5;
	//	//}
	//}
	//////////////////¾ÆÀÌÅÛ ÁöÇü ÇÈ¼¿Ãæµ¹///////////
	if (_state == ITEM_STATE_IDLE)
	{

		if (itemCollision->getPixelGroundLT(&_pt.x, &_pt.y, _img->getRealSize().x, _img->getRealSize().y ) == false)

		if (itemCollision->getPixelGroundLT(&_pt.x, &_pt.y, _img->getRealSize().x, _img->getRealSize().y) == false)

		{
			_pt.y += 5;
		}
	}


	if (_state == ITEM_STATE_INPLAYER)
	{
		if (_type == ITEM_TYPE_SWORD || _type == ITEM_TYPE_LANCE || _type == ITEM_TYPE_STAFF || _type == ITEM_TYPE_BOOMERANG)
			_img->setRotate(80.0f);

		
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			switch (_type)

				{
				case  ITEM_TYPE_SWORD:
				{
					_img->setRotate(120.0f);
					_img->setCoord(targetX, targetY);
					_state = ITEM_STATE_ATTACK;
					
				}
				break;
				case  ITEM_TYPE_LANCE:
					_img->setCoord(targetX, targetY);
					_img->setRotate(0.0f);
					_state = ITEM_STATE_ATTACK;
					break;
				case  ITEM_TYPE_STAFF:
					_img->setCoord(targetX, targetY);
					_img->setRotate(100.0f);
					_state = ITEM_STATE_ATTACK;
					break;
				case  ITEM_TYPE_BOOMERANG:
					_img->setCoord(targetX, targetY);
					_img->setRotate(0.0f);
					_state = ITEM_STATE_ATTACK;

					break;
				}
			}
	}
	
	
	if (_state == ITEM_STATE_ATTACK)
	{
		switch (_type)
		{
		case  ITEM_TYPE_SWORD:
			{	
			switch (_kind)	
				{
				case ITEM_KIND_WHITE:
					_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"Èò»öÄ®")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»öÄ®")->getRealSize().y);
				break;
				case ITEM_KIND_BLACK:
					_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"ºí·¢Ä®")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢Ä®")->getRealSize().y);
				break;
				case ITEM_KIND_GOLD : 
					_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"°ñµåÄ®")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµåÄ®")->getRealSize().y);
				break;
				}
				_img->setRotate(_img->getAngle() - 7.0f);
				if (_img->getAngle() <= 0.0f)
				{
					_state = ITEM_STATE_INPLAYER;
				}
			}
			break;
		case  ITEM_TYPE_LANCE:
			switch (_kind)
			{
			case ITEM_KIND_WHITE:
				_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"Èò»ö·£½º")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»ö·£½º")->getRealSize().y);
				break;
			case ITEM_KIND_BLACK:
				_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"ºí·¢·£½º")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢·£½º")->getRealSize().y);
				break;
			case ITEM_KIND_GOLD:
				_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"°ñµå·£½º")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµå·£½º")->getRealSize().y);
				break;
			}
				_pt.x += 10;
				
			break;
		case  ITEM_TYPE_STAFF:
			switch (_kind)
			{
			case ITEM_KIND_WHITE:
				_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"Èò»öÁöÆÎÀÌ")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»öÁöÆÎÀÌ")->getRealSize().y);
				break;
			case ITEM_KIND_BLACK:
				_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"ºí·¢ÁöÆÎÀÌ")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢ÁöÆÎÀÌ")->getRealSize().y);
				break;
			case ITEM_KIND_GOLD:
				_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"°ñµåÁöÆÎÀÌ")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµåÁöÆÎÀÌ")->getRealSize().y);
				break;
			}
			_img->setRotate(_img->getAngle() - 5.0f);
			if (_img->getAngle() <= 0.0f)
			{
				_state = ITEM_STATE_INPLAYER;
			}
			break;
		case  ITEM_TYPE_BOOMERANG:
			switch (_kind)
			{

			case ITEM_KIND_WHITE:
				_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"Èò»öºÎ¸Þ¶û")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»öºÎ¸Þ¶û")->getRealSize().y);
				break;
			case ITEM_KIND_BLACK:
				_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"ºí·¢ºÎ¸Þ¶û")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢ºÎ¸Þ¶û")->getRealSize().y);
				break;
			case ITEM_KIND_GOLD:
				_rcHit = RectMake(_pt.x, _pt.y, IMAGEMANAGER->findImage(L"°ñµåºÎ¸Þ¶û")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµåºÎ¸Þ¶û")->getRealSize().y);
				break;
			}
				_img->setCenterPer(0.5,0.5);
				_img->setRotate(_img->getAngle() - 15.0f);
				_pt.x += 10;
			
			
			break;
		}
	}
	if(_state == ITEM_STATE_IDLE || _state == ITEM_STATE_ATTACK)_img->setCoord(_pt.x, _pt.y);
	else if (_state == ITEM_STATE_INPLAYER)_img->setCoord(targetX , targetY);

	

}

void Item::render(void)	
{
	
	if (_state != ITEM_STATE_ININVEN)
	{
		_img->render();
	}
	
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
			_durabilityMax = _durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢Ä®.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ºí·¢Ä®")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢Ä®")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµåÄ®.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"°ñµåÄ®")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµåÄ®")->getRealSize().y);
			_durabilityMax = _durability = 4;
		}
		break;
	case ITEM_TYPE_LANCE:		//¹«±â-Ã¢
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»ö·£½º.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èò»ö·£½º")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»ö·£½º")->getRealSize().y);
			_durabilityMax = _durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢·£½º.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ºí·¢·£½º")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢·£½º")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµå·£½º.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"°ñµå·£½º")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµå·£½º")->getRealSize().y);
			_durabilityMax = _durability = 4;
		}
		break;
	case ITEM_TYPE_BOOMERANG:	//¹«±â-ºÎ¸Þ¶û
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»öºÎ¸Þ¶û.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èò»öºÎ¸Þ¶û")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»öºÎ¸Þ¶û")->getRealSize().y);
			_durabilityMax = _durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢ºÎ¸Þ¶û.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ºí·¢ºÎ¸Þ¶û")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢ºÎ¸Þ¶û")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµåºÎ¸Þ¶û.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"°ñµåºÎ¸Þ¶û")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµåºÎ¸Þ¶û")->getRealSize().y);
			_durabilityMax = _durability = 4;
		}
		break;
	case ITEM_TYPE_STAFF:		//¹«±â-ÁöÆÎÀÌ
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»öÁöÆÎÀÌ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èò»öÁöÆÎÀÌ")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»öÁöÆÎÀÌ")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢ÁöÆÎÀÌ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ºí·¢ÁöÆÎÀÌ")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢ÁöÆÎÀÌ")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµåÁöÆÎÀÌ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"°ñµåÁöÆÎÀÌ")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµåÁöÆÎÀÌ")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		break;
	case ITEM_TYPE_HEAD:			//¹æ¾î±¸-¸Ó¸®
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/¹éÅõ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"¹éÅõ")->getRealSize().x, IMAGEMANAGER->findImage(L"¹éÅõ")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ÈæÅõ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ÈæÅõ")->getRealSize().x, IMAGEMANAGER->findImage(L"ÈæÅõ")->getRealSize().y);
			_durabilityMax = _durability = 2;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/È²Åõ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"È²Åõ")->getRealSize().x, IMAGEMANAGER->findImage(L"È²Åõ")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		break;
	case ITEM_TYPE_BODY:			//¹æ¾î±¸-°©¿Ê
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/¹é°©.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"¹é°©")->getRealSize().x, IMAGEMANAGER->findImage(L"¹é°©")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/Èæ°©.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èæ°©")->getRealSize().x, IMAGEMANAGER->findImage(L"Èæ°©")->getRealSize().y);
			_durabilityMax = _durability = 2;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/È²°©.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"È²°©")->getRealSize().x, IMAGEMANAGER->findImage(L"È²°©")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		break;
	case ITEM_TYPE_FOOT:			//¹æ¾î±¸-½Å¹ß
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/¹é½Å.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"¹é½Å")->getRealSize().x, IMAGEMANAGER->findImage(L"¹é½Å")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/Èæ½Å.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èæ½Å")->getRealSize().x, IMAGEMANAGER->findImage(L"Èæ½Å")->getRealSize().y);
			_durabilityMax = _durability = 2;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/È²½Å.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"È²½Å")->getRealSize().x, IMAGEMANAGER->findImage(L"È²½Å")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		break;
	case ITEM_TYPE_OIL:			//
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/Èò»ö¿ÀÀÏ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Èò»ö¿ÀÀÏ")->getRealSize().x, IMAGEMANAGER->findImage(L"Èò»ö¿ÀÀÏ")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/ºí·¢¿ÀÀÏ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"ºí·¢¿ÀÀÏ")->getRealSize().x, IMAGEMANAGER->findImage(L"ºí·¢¿ÀÀÏ")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/°ñµå¿ÀÀÏ.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"°ñµå¿ÀÀÏ")->getRealSize().x, IMAGEMANAGER->findImage(L"°ñµå¿ÀÀÏ")->getRealSize().y);
			
		}
		break;
	case ITEM_TYPE_EGG:
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/¾Ë.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"´Þ°¿")->getRealSize().x, IMAGEMANAGER->findImage(L"´Þ°¿")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/¾Ë.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"´Þ°¿")->getRealSize().x, IMAGEMANAGER->findImage(L"´Þ°¿")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/¾Ë.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"´Þ°¿")->getRealSize().x, IMAGEMANAGER->findImage(L"´Þ°¿")->getRealSize().y);
			
		}
		break;
	}
	////////////////////ÇÈ¼¿Ãæµ¹
	
}

