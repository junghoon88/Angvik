#include "stdafx.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "stageManager.h"
#include "itemManager.h"

PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

void PlayerManager::init(void)
{
	_player = new Player;
	_player->init();
	_bird = new invenBird;
	_bird->init(_player->getX(), _player->getY());

	_inven = new inven;
	_inven->init();
	_inven->setLinkAdressItemManager(_im);

	_playerRcHead = _player->getRectHead();
	_playerRcBody = _player->getRectBody();
	_playerRcFoot = _player->getRectFoot();
}

void PlayerManager::release(void)
{

}

void PlayerManager::update(void) 
{
	////플레이어의 풋 렉트와 아이템의 렉트를 충돌 비교
	vItems item = _im->getVItem();
	for ( _viItems = item.begin(); _viItems != item.end();)
	{
		RECT rc;
		if (IntersectRect(&rc, &((*_viItems)->getrcImg()), &(_player->getRectFoot())))
		{
			//아이템의 타입에 따라
			//플레이어의 부위별 아이템 상태 변경

			switch ((*_viItems)->getState() == ITEM_STATE_IDLE)
			{
				case ITEM_TYPE_SWORD:
					if (_player->getBackItem() == UNARMEDWEAPON)	//뒤 손이 비었으면,
					{
						switch((*_viItems)->getKind())
						{
							case ITEM_KIND_WHITE:
								_player->setBackItem(WHITE_SWORD);	//흰색
							break;
							case ITEM_KIND_GOLD:
								_player->setBackItem(GOLD_SWORD);	//황금색
							break;
							case ITEM_KIND_BLACK:
								_player->setBackItem(BLACK_SWORD);	//검은색
							break;
						}
					}
					else if (_player->getFrontItem() == UNARMEDWEAPON)	//뒤 손이 있고, 앞 손이 비었으면,
					{
						switch ((*_viItems)->getKind())
						{
							case ITEM_KIND_WHITE:
								_player->setFrontItem(WHITE_SWORD);	//흰색
							break;
							case ITEM_KIND_GOLD:
								_player->setFrontItem(GOLD_SWORD);	//황금색
							break;
							case ITEM_KIND_BLACK:
								_player->setFrontItem(BLACK_SWORD);	//검은색
							break;
						}
					}
					else
					{
						//가방에 여분이 있을때
						//가방에 여분이 없을때
					}
				break;
				case ITEM_TYPE_LANCE:
					if (_player->getBackItem() == UNARMEDWEAPON)	//뒤 손이 비었으면,
					{
						switch ((*_viItems)->getKind())
						{
							case ITEM_KIND_WHITE:
								_player->setBackItem(WHITE_LANCE);	//흰색
							break;
							case ITEM_KIND_GOLD:
								_player->setBackItem(GOLD_LANCE);	//황금색
							break;
							case ITEM_KIND_BLACK:
								_player->setBackItem(BLACK_LANCE);	//검은색
							break;
						}
					}
					else if (_player->getFrontItem() == UNARMEDWEAPON)	//뒤 손이 있고, 앞 손이 비었으면,
					{
						switch ((*_viItems)->getKind())
						{
							case ITEM_KIND_WHITE:
								_player->setFrontItem(WHITE_LANCE);	//흰색
							break;
							case ITEM_KIND_GOLD:
								_player->setFrontItem(GOLD_LANCE);	//황금색
							break;
							case ITEM_KIND_BLACK:
								_player->setFrontItem(BLACK_LANCE);	//검은색
							break;
						}
					}
					else
					{
						//가방에 여분이 있을때
						//가방에 여분이 없을때
					}
				break;
				case ITEM_TYPE_BOOMERANG:
					if (_player->getBackItem() == UNARMEDWEAPON)	//뒤 손이 비었으면,
					{
						switch ((*_viItems)->getKind())
						{
							case ITEM_KIND_WHITE:
								_player->setBackItem(WHITE_BOOMERANG);	//흰색
							break;
							case ITEM_KIND_GOLD:
								_player->setBackItem(GOLD_BOOMERANG);	//황금색
							break;
							case ITEM_KIND_BLACK:
								_player->setBackItem(BLACK_BOOMERANG);	//검은색
							break;
						}
					}
					else if (_player->getFrontItem() == UNARMEDWEAPON)	//뒤 손이 있고, 앞 손이 비었으면,
					{
						switch ((*_viItems)->getKind())
						{
							case ITEM_KIND_WHITE:
								_player->setFrontItem(WHITE_BOOMERANG);	//흰색
							break;
							case ITEM_KIND_GOLD:
								_player->setFrontItem(GOLD_BOOMERANG);	//황금색
							break;
							case ITEM_KIND_BLACK:
								_player->setFrontItem(BLACK_BOOMERANG);	//검은색
							break;
						}
					}
					else
					{
						//가방에 여분이 있을때
						//가방에 여분이 없을때
					}
				break;
				case ITEM_TYPE_STAFF:
					if (_player->getBackItem() == UNARMEDWEAPON)	//뒤 손이 비었으면,
					{
						switch ((*_viItems)->getKind())
						{
							case ITEM_KIND_WHITE:
								_player->setBackItem(WHITE_STAFF);	//흰색
							break;
							case ITEM_KIND_GOLD:
								_player->setBackItem(GOLD_STAFF);	//황금색
							break;
							case ITEM_KIND_BLACK:
								_player->setBackItem(BLACK_STAFF);	//검은색
							break;
						}
					}
					else if (_player->getFrontItem() == UNARMEDWEAPON)	//뒤 손이 있고, 앞 손이 비었으면,
					{
						switch ((*_viItems)->getKind())
						{
							case ITEM_KIND_WHITE:
								_player->setFrontItem(WHITE_STAFF);	//흰색
							break;
							case ITEM_KIND_GOLD:
								_player->setFrontItem(GOLD_STAFF);	//황금색
							break;
							case ITEM_KIND_BLACK:
								_player->setFrontItem(BLACK_STAFF);	//검은색
							break;
						}
					}
					else
					{
						//가방에 여분이 있을때
						//가방에 여분이 없을때
					}
				break;

				case ITEM_TYPE_HEAD:
					if (_player->getHeadItem() == UNARMEDARMOR)
					{
						switch ((*_viItems)->getKind())
						{
							case ITEM_KIND_WHITE:
								_player->setHeadItem(WHITE);	//흰색
							break;
							case ITEM_KIND_GOLD:
								_player->setHeadItem(GOLD);		//황금색
							break;
							case ITEM_KIND_BLACK:
								_player->setHeadItem(BLACK);	//검은색
							break;
						}
					}
					else
					{
						//가방에 여분이 있을때
						//가방에 여분이 없을때
					}
				break;
				case ITEM_TYPE_BODY:
					if (_player->getHeadItem() == UNARMEDARMOR)
					{
						switch ((*_viItems)->getKind())
						{
							case ITEM_KIND_WHITE:
								_player->setBodyItem(WHITE);	//흰색
							break;
							case ITEM_KIND_GOLD:
								_player->setBodyItem(GOLD);		//황금색
							break;
							case ITEM_KIND_BLACK:
								_player->setBodyItem(BLACK);	//검은색
							break;
						}
					}
					else
					{
						//가방에 여분이 있을때
						//가방에 여분이 없을때
					}
				break;
				case ITEM_TYPE_FOOT:
					if (_player->getHeadItem() == UNARMEDARMOR)
					{
						switch ((*_viItems)->getKind())
						{
							case ITEM_KIND_WHITE:
								_player->setFootItem(WHITE);	//흰색
							break;
							case ITEM_KIND_GOLD:
								_player->setFootItem(GOLD);		//황금색
							break;
							case ITEM_KIND_BLACK:
								_player->setFootItem(BLACK);	//검은색
							break;
						}
					}
					else
					{
						//가방에 여분이 있을때
						//가방에 여분이 없을때
					}
				break;

				case ITEM_TYPE_OIL:
				case ITEM_TYPE_EGG:		//	기타
				break;

				_viItems = item.erase(_viItems);
			}
		}
		else
		{
			++_viItems;
		}
	}

Collision();
	_player->update();
	_bird->update(_player->getX(), _player->getY());
	_inven->update(_player->getX(), _player->getY());
	_player->setIsInven(_inven->getInven());
}

void PlayerManager::render(void) 
{
	_player->render();
	_bird->render();
	_inven->render();
}

