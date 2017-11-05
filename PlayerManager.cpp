#include "stdafx.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "stageManager.h"
#include "itemManager.h"

PlayerManager::PlayerManager()
	:_im(NULL), _em(NULL), _sm(NULL)
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

	_playerRcHead = _player->getRectHead();
	_playerRcBody = _player->getRectBody();
	_playerRcFoot = _player->getRectFoot();
}

void PlayerManager::release(void)
{

}

void PlayerManager::update(void) 
{
	playerItemCollision();		//	�����۸Ŵ������� �����ۺ��͸� �ҷ��� ��, �������� ��Ʈ�� �÷��̾��� ��Ʈ�� ���ؼ� �ش� �������� ������ �÷��̾� ���¸� ����


	_player->update();
	_bird->update(_player->getX(), _player->getY());
	_inven->update(_player->getX(), _player->getY());
}

void PlayerManager::render(void) 
{
	_player->render();
	_bird->render();
	_inven->render();
}

void PlayerManager::playerItemCollision(void)
{
	if (_im == NULL)
		return;


	vItems item = _im->getVItem();

	//�ҽ� �����Ұ�
	for (int i = 0; i < item.size(); i++)
	{
		item[i]->getState();
		item[i]->setState(ITEM_STATE_INPLAYER);

		//_inven->
	}
	

	for (_viItems = item.begin(); _viItems != item.end(); ++_viItems)
	{
		RECT rc;
		if (IntersectRect(&rc, &((*_viItems)->getrcImg()), &(_player->getRectFoot())))
		{
			//�������� Ÿ�Կ� ����
			//�÷��̾��� ������ ������ ���� ����

			switch ((*_viItems)->getState() == ITEM_STATE_IDLE)
			{
			case ITEM_TYPE_SWORD:
				if (_player->getBackItem() == UNARMEDWEAPON)	//�� ���� �������,
				{
					switch ((*_viItems)->getKind())
					{
					case ITEM_KIND_WHITE:
						_player->setBackItem(WHITE_SWORD);	//���
						break;
					case ITEM_KIND_GOLD:
						_player->setBackItem(GOLD_SWORD);	//Ȳ�ݻ�
						break;
					case ITEM_KIND_BLACK:
						_player->setBackItem(BLACK_SWORD);	//������
						break;
					}
				}
				else if (_player->getFrontItem() == UNARMEDWEAPON)	//�� ���� �ְ�, �� ���� �������,
				{
					switch ((*_viItems)->getKind())
					{
					case ITEM_KIND_WHITE:
						_player->setFrontItem(WHITE_SWORD);	//���
						break;
					case ITEM_KIND_GOLD:
						_player->setFrontItem(GOLD_SWORD);	//Ȳ�ݻ�
						break;
					case ITEM_KIND_BLACK:
						_player->setFrontItem(BLACK_SWORD);	//������
						break;
					}
				}
				else
				{
					//���濡 ������ ������
					//���濡 ������ ������
				}
				break;
			case ITEM_TYPE_LANCE:
				if (_player->getBackItem() == UNARMEDWEAPON)	//�� ���� �������,
				{
					switch ((*_viItems)->getKind())
					{
					case ITEM_KIND_WHITE:
						_player->setBackItem(WHITE_LANCE);	//���
						break;
					case ITEM_KIND_GOLD:
						_player->setBackItem(GOLD_LANCE);	//Ȳ�ݻ�
						break;
					case ITEM_KIND_BLACK:
						_player->setBackItem(BLACK_LANCE);	//������
						break;
					}
				}
				else if (_player->getFrontItem() == UNARMEDWEAPON)	//�� ���� �ְ�, �� ���� �������,
				{
					switch ((*_viItems)->getKind())
					{
					case ITEM_KIND_WHITE:
						_player->setFrontItem(WHITE_LANCE);	//���
						break;
					case ITEM_KIND_GOLD:
						_player->setFrontItem(GOLD_LANCE);	//Ȳ�ݻ�
						break;
					case ITEM_KIND_BLACK:
						_player->setFrontItem(BLACK_LANCE);	//������
						break;
					}
				}
				else
				{
					//���濡 ������ ������
					//���濡 ������ ������
				}
				break;
			case ITEM_TYPE_BOOMERANG:
				if (_player->getBackItem() == UNARMEDWEAPON)	//�� ���� �������,
				{
					switch ((*_viItems)->getKind())
					{
					case ITEM_KIND_WHITE:
						_player->setBackItem(WHITE_BOOMERANG);	//���
						break;
					case ITEM_KIND_GOLD:
						_player->setBackItem(GOLD_BOOMERANG);	//Ȳ�ݻ�
						break;
					case ITEM_KIND_BLACK:
						_player->setBackItem(BLACK_BOOMERANG);	//������
						break;
					}
				}
				else if (_player->getFrontItem() == UNARMEDWEAPON)	//�� ���� �ְ�, �� ���� �������,
				{
					switch ((*_viItems)->getKind())
					{
					case ITEM_KIND_WHITE:
						_player->setFrontItem(WHITE_BOOMERANG);	//���
						break;
					case ITEM_KIND_GOLD:
						_player->setFrontItem(GOLD_BOOMERANG);	//Ȳ�ݻ�
						break;
					case ITEM_KIND_BLACK:
						_player->setFrontItem(BLACK_BOOMERANG);	//������
						break;
					}
				}
				else
				{
					//���濡 ������ ������
					//���濡 ������ ������
				}
				break;
			case ITEM_TYPE_STAFF:
				if (_player->getBackItem() == UNARMEDWEAPON)	//�� ���� �������,
				{
					switch ((*_viItems)->getKind())
					{
					case ITEM_KIND_WHITE:
						_player->setBackItem(WHITE_STAFF);	//���
						break;
					case ITEM_KIND_GOLD:
						_player->setBackItem(GOLD_STAFF);	//Ȳ�ݻ�
						break;
					case ITEM_KIND_BLACK:
						_player->setBackItem(BLACK_STAFF);	//������
						break;
					}
				}
				else if (_player->getFrontItem() == UNARMEDWEAPON)	//�� ���� �ְ�, �� ���� �������,
				{
					switch ((*_viItems)->getKind())
					{
					case ITEM_KIND_WHITE:
						_player->setFrontItem(WHITE_STAFF);	//���
						break;
					case ITEM_KIND_GOLD:
						_player->setFrontItem(GOLD_STAFF);	//Ȳ�ݻ�
						break;
					case ITEM_KIND_BLACK:
						_player->setFrontItem(BLACK_STAFF);	//������
						break;
					}
				}
				else
				{
					//���濡 ������ ������
					//���濡 ������ ������
				}
				break;

			case ITEM_TYPE_HEAD:
				if (_player->getHeadItem() == UNARMEDARMOR)
				{
					switch ((*_viItems)->getKind())
					{
					case ITEM_KIND_WHITE:
						_player->setHeadItem(WHITE);	//���
						break;
					case ITEM_KIND_GOLD:
						_player->setHeadItem(GOLD);		//Ȳ�ݻ�
						break;
					case ITEM_KIND_BLACK:
						_player->setHeadItem(BLACK);	//������
						break;
					}
				}
				else
				{
					//���濡 ������ ������
					//���濡 ������ ������
				}
				break;
			case ITEM_TYPE_BODY:
				if (_player->getHeadItem() == UNARMEDARMOR)
				{
					switch ((*_viItems)->getKind())
					{
					case ITEM_KIND_WHITE:
						_player->setBodyItem(WHITE);	//���
						break;
					case ITEM_KIND_GOLD:
						_player->setBodyItem(GOLD);		//Ȳ�ݻ�
						break;
					case ITEM_KIND_BLACK:
						_player->setBodyItem(BLACK);	//������
						break;
					}
				}
				else
				{
					//���濡 ������ ������
					//���濡 ������ ������
				}
				break;
			case ITEM_TYPE_FOOT:
				if (_player->getHeadItem() == UNARMEDARMOR)
				{
					switch ((*_viItems)->getKind())
					{
					case ITEM_KIND_WHITE:
						_player->setFootItem(WHITE);	//���
						break;
					case ITEM_KIND_GOLD:
						_player->setFootItem(GOLD);		//Ȳ�ݻ�
						break;
					case ITEM_KIND_BLACK:
						_player->setFootItem(BLACK);	//������
						break;
					}
				}
				else
				{
					//���濡 ������ ������
					//���濡 ������ ������
				}
				break;

			case ITEM_TYPE_OIL:
			case ITEM_TYPE_EGG:		//	��Ÿ
				break;
			}
		}
	}
<<<<<<< HEAD

Collision();
	_player->update();
	_bird->update(_player->getX(), _player->getY());



	_inven->update(_player->getX(), _player->getY());

}

void PlayerManager::render(void) 
{
	_player->render();
	_bird->render();
	_inven->render();
}

=======
}
>>>>>>> b741292506ec0381226c358f2bbd70dadb97870f
