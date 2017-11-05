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

	//////////////////������ ���� �ȼ��浹///////////
	if (_state == ITEM_STATE_IDLE)
	{

		if (itemCollision->getPixelGroundLT(&_pt.x, &_pt.y, _img->getRealSize().x, _img->getRealSize().y) == false)

		{
			_pt.y += 5;
		}
		_rcImg = RectMake(_pt.x, _pt.y, _img->getTexture()->getFrameWidth(), _img->getTexture()->getFrameHeight());
		_rcHit = RectMake(_pt.x, _pt.y, _img->getTexture()->getFrameWidth(), _img->getTexture()->getFrameHeight());
	}
	
	if (_state == ITEM_STATE_INPLAYER)
	{

		if (_type == ITEM_TYPE_SWORD || _type == ITEM_TYPE_LANCE || _type == ITEM_TYPE_STAFF || _type == ITEM_TYPE_BOOMERANG)
			{
				_img->setCenterPer(0, 0);
				if (isPlayerRIGHT)	_img->setRotate(80.0f);
				else _img->setRotate(100.0f);
			}
			if (_type == ITEM_TYPE_HEAD)
			{
				if (isPlayerRIGHT) _img->setScale(1, 1);
				else _img->setScale(-1, 1);
			}

		
		if (isAttack)
		{
			switch (_type)

				{
				case  ITEM_TYPE_SWORD:
				{
					if (isPlayerRIGHT)
					{
						_img->setRotate(120.0f);
						_img->setCenterPer(0, 0);
						_img->setCoord(targetX, targetY);
					}
					else
					{
						_img->setRotate(80.0f);
						_img->setCenterPer(0, 1);
						_img->setCoord(targetX, targetY);
						
					}
					_state = ITEM_STATE_ATTACK;
				}
				break;
				case  ITEM_TYPE_LANCE:
					if (isPlayerRIGHT)
					{
						_img->setCoord(targetX, targetY);
						_img->setRotate(0.0f);
					}
					else
					{
						_img->setCoord(targetX, targetY);
						_img->setRotate(180.0f);
					}
					_state = ITEM_STATE_ATTACK;
					break;
				case  ITEM_TYPE_STAFF:
					if (isPlayerRIGHT)
					{
						_img->setCoord(targetX, targetY);
						_img->setRotate(100.0f);
						_img->setCenterPer(0, 0);
					}
					else
					{
						_img->setCoord(targetX, targetY);
						_img->setCenterPer(0, 1);
						_img->setRotate(80.0f);
					}
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
					_img->setCoord(targetX, targetY);
					_rcHit = RectMake(targetX, targetY, IMAGEMANAGER->findImage(L"���Į")->getRealSize().x, IMAGEMANAGER->findImage(L"���Į")->getRealSize().y);
					
				break;
				case ITEM_KIND_BLACK:
					_img->setCoord(targetX, targetY);
					_rcHit = RectMake(targetX, targetY,  IMAGEMANAGER->findImage(L"��Į")->getRealSize().x, IMAGEMANAGER->findImage(L"��Į")->getRealSize().y);
				break;
				case ITEM_KIND_GOLD : 
					_img->setCoord(targetX, targetY);
					_rcHit = RectMake(targetX, targetY, IMAGEMANAGER->findImage(L"���Į")->getRealSize().x, IMAGEMANAGER->findImage(L"���Į")->getRealSize().y);
				break;
				}
				
				if (isPlayerRIGHT)
				{
					_img->setRotate(_img->getAngle() - 7.0f);
					if (_img->getAngle() <= 0.0f)
					{
						_state = ITEM_STATE_INPLAYER;
						
					}
				}
				else
				{
					_img->setRotate(_img->getAngle() + 7.0f);
					if (_img->getAngle() >= 180.0f)
					{
						_state = ITEM_STATE_INPLAYER;
						
					}
				}
			}
			break;
		case  ITEM_TYPE_LANCE:
			switch (_kind)
			{
			case ITEM_KIND_WHITE:
				_img->setCoord(targetX, targetY);
				_rcHit = RectMake(targetX, targetY-20, IMAGEMANAGER->findImage(L"�������")->getRealSize().x, IMAGEMANAGER->findImage(L"�������")->getRealSize().y);
				break;
			case ITEM_KIND_BLACK:
				_img->setCoord(targetX, targetY);
				_rcHit = RectMake(targetX, targetY-20, IMAGEMANAGER->findImage(L"������")->getRealSize().x, IMAGEMANAGER->findImage(L"������")->getRealSize().y);
				break;
			case ITEM_KIND_GOLD:
				_img->setCoord(targetX, targetY);
				_rcHit = RectMake(targetX, targetY-20, IMAGEMANAGER->findImage(L"��巣��")->getRealSize().x, IMAGEMANAGER->findImage(L"��巣��")->getRealSize().y);
				break;
			}
			if (isPlayerRIGHT)
			{
				targetX += 10;
				_pt.x += 10;
			}
			else
			{
				targetX -= 10;
				_pt.x -= 10;
			}
				
			break;
		case  ITEM_TYPE_STAFF:
			switch (_kind)
			{
			case ITEM_KIND_WHITE:
				_img->setCoord(targetX, targetY);
				_rcHit = RectMake(targetX, targetY, IMAGEMANAGER->findImage(L"���������")->getRealSize().x, IMAGEMANAGER->findImage(L"���������")->getRealSize().y);
				break;
			case ITEM_KIND_BLACK:
				_img->setCoord(targetX, targetY);
				_rcHit = RectMake(targetX, targetY, IMAGEMANAGER->findImage(L"��������")->getRealSize().x, IMAGEMANAGER->findImage(L"��������")->getRealSize().y);
				break;
				_img->setCoord(targetX, targetY);
			case ITEM_KIND_GOLD:
				_img->setCoord(targetX, targetY);
				_rcHit = RectMake(targetX, targetY, IMAGEMANAGER->findImage(L"���������")->getRealSize().x, IMAGEMANAGER->findImage(L"���������")->getRealSize().y);
				break;
			}
			if (isPlayerRIGHT)
			{
				_img->setRotate(_img->getAngle() - 5.0f);
				if (_img->getAngle() <= 0.0f)
				{
					_state = ITEM_STATE_INPLAYER;
				}
			}
			else
			{
				_img->setRotate(_img->getAngle() + 5.0f);
				if (_img->getAngle() >= 180.0f)
				{
					_state = ITEM_STATE_INPLAYER;
				}
			}
			
			break;
		case  ITEM_TYPE_BOOMERANG:
			switch (_kind)
			{

			case ITEM_KIND_WHITE:
				_img->setCoord(targetX, targetY);
				_rcHit = RectMake(targetX, targetY, IMAGEMANAGER->findImage(L"����θ޶�")->getRealSize().x, IMAGEMANAGER->findImage(L"����θ޶�")->getRealSize().y);
				break;
			case ITEM_KIND_BLACK:
				_img->setCoord(targetX, targetY);
				_rcHit = RectMake(targetX, targetY, IMAGEMANAGER->findImage(L"���θ޶�")->getRealSize().x, IMAGEMANAGER->findImage(L"���θ޶�")->getRealSize().y);
				break;
			case ITEM_KIND_GOLD:
				_img->setCoord(targetX, targetY);
				_rcHit = RectMake(targetX, targetY, IMAGEMANAGER->findImage(L"���θ޶�")->getRealSize().x, IMAGEMANAGER->findImage(L"���θ޶�")->getRealSize().y);
				break;
			}
				
				
				_img->setCenterPer(0.5,0.5);

				_img->setRotate(_img->getAngle() - 15.0f);
				if (isPlayerRIGHT)
				{
					targetX += 10;

					_pt.x += 10;
				}
				else
				{
					targetX -= 10;

					_pt.x -= 10;
				}
			
			break;
		}
	}
	if (_state == ITEM_STATE_IDLE)
	{
		_img->setCoord(_pt.x, _pt.y);
		
		
	}
	else if (_state == ITEM_STATE_INPLAYER || _state == ITEM_STATE_ATTACK)_img->setCoord(targetX , targetY);

	

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
	case ITEM_TYPE_SWORD:		//����-��
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/���Į.png");
			
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���Į")->getRealSize().x, IMAGEMANAGER->findImage(L"���Į")->getRealSize().y);
			_durabilityMax = _durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/��Į.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"��Į")->getRealSize().x, IMAGEMANAGER->findImage(L"��Į")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/���Į.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���Į")->getRealSize().x, IMAGEMANAGER->findImage(L"���Į")->getRealSize().y);
			_durabilityMax = _durability = 4;
		}
		break;
	case ITEM_TYPE_LANCE:		//����-â
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/�������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�������")->getRealSize().x, IMAGEMANAGER->findImage(L"�������")->getRealSize().y);
			_durabilityMax = _durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"������")->getRealSize().x, IMAGEMANAGER->findImage(L"������")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/��巣��.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"��巣��")->getRealSize().x, IMAGEMANAGER->findImage(L"��巣��")->getRealSize().y);
			_durabilityMax = _durability = 4;
		}
		break;
	case ITEM_TYPE_BOOMERANG:	//����-�θ޶�
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/����θ޶�.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"����θ޶�")->getRealSize().x, IMAGEMANAGER->findImage(L"����θ޶�")->getRealSize().y);
			_durabilityMax = _durability = 4;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/���θ޶�.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���θ޶�")->getRealSize().x, IMAGEMANAGER->findImage(L"���θ޶�")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/���θ޶�.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���θ޶�")->getRealSize().x, IMAGEMANAGER->findImage(L"���θ޶�")->getRealSize().y);
			_durabilityMax = _durability = 4;
		}
		break;
	case ITEM_TYPE_STAFF:		//����-������
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/���������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���������")->getRealSize().x, IMAGEMANAGER->findImage(L"���������")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/��������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"��������")->getRealSize().x, IMAGEMANAGER->findImage(L"��������")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/���������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���������")->getRealSize().x, IMAGEMANAGER->findImage(L"���������")->getRealSize().y);
			_durabilityMax = _durability = 6;
		}
		break;
	case ITEM_TYPE_HEAD:			//��-�Ӹ�
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/����.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"����")->getRealSize().x, IMAGEMANAGER->findImage(L"����")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/����.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"����")->getRealSize().x, IMAGEMANAGER->findImage(L"����")->getRealSize().y);
			_durabilityMax = _durability = 2;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/Ȳ��.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().x, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		break;
	case ITEM_TYPE_BODY:			//��-����
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/�鰩.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�鰩")->getRealSize().x, IMAGEMANAGER->findImage(L"�鰩")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/�氩.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�氩")->getRealSize().x, IMAGEMANAGER->findImage(L"�氩")->getRealSize().y);
			_durabilityMax = _durability = 2;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/Ȳ��.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().x, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		break;
	case ITEM_TYPE_FOOT:			//��-�Ź�
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/���.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���")->getRealSize().x, IMAGEMANAGER->findImage(L"���")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/���.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"���")->getRealSize().x, IMAGEMANAGER->findImage(L"���")->getRealSize().y);
			_durabilityMax = _durability = 2;
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/Ȳ��.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().x, IMAGEMANAGER->findImage(L"Ȳ��")->getRealSize().y);
			_durabilityMax = _durability = 1;
		}
		break;
	case ITEM_TYPE_OIL:			//
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/�������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�������")->getRealSize().x, IMAGEMANAGER->findImage(L"�������")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"������")->getRealSize().x, IMAGEMANAGER->findImage(L"������")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/������.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"������")->getRealSize().x, IMAGEMANAGER->findImage(L"������")->getRealSize().y);
			
		}
		break;
	case ITEM_TYPE_EGG:
		if (_kind == ITEM_KIND_WHITE)
		{
			_img = new Sprite(DEVICE, L"image/item/��.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�ް�")->getRealSize().x, IMAGEMANAGER->findImage(L"�ް�")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_BLACK)
		{
			_img = new Sprite(DEVICE, L"image/item/��.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�ް�")->getRealSize().x, IMAGEMANAGER->findImage(L"�ް�")->getRealSize().y);
			
		}
		else if (_kind == ITEM_KIND_GOLD)
		{
			_img = new Sprite(DEVICE, L"image/item/��.png");
			_img->setCoord(x, y);
			_img->init();
			_rcImg = RectMake(x, y, IMAGEMANAGER->findImage(L"�ް�")->getRealSize().x, IMAGEMANAGER->findImage(L"�ް�")->getRealSize().y);
			
		}
		break;
	}
	////////////////////�ȼ��浹
	
}
