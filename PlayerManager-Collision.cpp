#include "stdafx.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "itemManager.h"

void PlayerManager::Collision(void)
{
	////////////////////////////////////////// �ҷ��浹
	for (int i = 0; i < _em->getKongtan()->getVBullet().size(); i++)
	{
		if (isCollision(_em->getKongtan()->getVBullet()[i].rc,
			_player->getRectBody()))
		{
			_player->setIsHit(true);    //���ؽ�ȣ
			_em->getKongtan()->remove(i);
			//�����ۿ� ��ȣ �Ѱ������
			break;
		}

	}
	///////////////////////////////////////////////
	// ��ź

	for (int i = 0; i < _em->getSbmr()->getVBullet().size(); i++)
	{
		RECT temp;
		if (isCollision(_em->getSbmr()->getVBullet()[i].rc,
			_player->getRectBody()))
		{
			_player->setIsHit(true);
			_em->getSbmr()->remove(i);
			//�����ۿ� ��ȣ �Ѱ������

			break;
		}
	}

	/////////////////////////////////////////////

	for (int i = 0; i < _em->getvEnemy().size(); i++)   //�÷��̾� �����浹ó��
	{
		RECT temp2;

		if (IntersectRect(&temp2, &_player->getRectBody(), &_em->getvEnemy()[i]->getRect()) && _player->getIsImmortal() == FALSE && _em->getvEnemy()[i]->getState() != toDeath)    //�÷��̾� ���ع���
		{
			if (_player->getHeadItem() != UNARMEDARMOR)
			{
				_player->setHeadItem(UNARMEDARMOR);
				_player->setIsImmortal(TRUE);
			}
			else if (_player->getBodyItem() != UNARMEDARMOR)
			{
				_player->setBodyItem(UNARMEDARMOR);
				_player->setIsImmortal(TRUE);
			}
			else if (_player->getFootItem() != UNARMEDARMOR)
			{
				_player->setFootItem(UNARMEDARMOR);
				_player->setIsImmortal(TRUE);
			}
			else
			{
				_player->setIsLive(FALSE);
			}
		}

		RECT temp;

		if (IntersectRect(&temp, &_player->getRectFoot(), &_em->getvEnemy()[i]->getRect()) && _player->getIsJump())	  //�÷��̾ ������
		{
			_em->getvEnemy()[i]->setLife((_em->getvEnemy()[i]->getLife()) - 1);   //life -1

			_player->setIsJumpAttack(TRUE);
		}
	}

	for (int i = 0; i < _em->getvEnemy().size(); i++)   //�÷��̾� ���� ����
	{
		for (int j = 0; j < _im->getVItem().size(); j++)
		{
			RECT temp;

			if (_im->getVItem()[j]->getState() == ITEM_STATE_ATTACK)
			{
				if (IntersectRect(&temp, &_im->getVItem()[j]->getHitImg(), &_em->getvEnemy()[i]->getRect()))
				{    //�÷��̾ ���⾸
					_im->getVItem()[j]->setdurability(_im->getVItem()[j]->getdurability() - 1);
					_em->getvEnemy()[i]->setLife((_em->getvEnemy()[i]->getLife()) - 1);   //life -1

					if (_im->getVItem()[j]->getType() == ITEM_TYPE_LANCE)
					{
						MYPOINT  pt;
						pt.x = _em->getvEnemy()[i]->getX() - 10;
						pt.y = _em->getvEnemy()[i]->getY() - 30;
						_im->getVItem()[j]->setPt(pt);

						_im->getVItem()[j]->setState(ITEM_STATE_IDLE);

					}
					if (_im->getVItem()[j]->getType() == ITEM_TYPE_BOOMERANG)
					{
						MYPOINT  pt;
						pt.x = _player->getHandX();
						pt.y = _player->getHandY();
						_im->getVItem()[j]->setPt(pt);

						_im->getVItem()[j]->setState(ITEM_STATE_INPLAYER);

					}
					if (_em->getvEnemy()[i]->getLife() <= 0)
					{
						_im->setItem(_em->getvEnemy()[i]->getX(), _em->getvEnemy()[i]->getY() - 30);
						_em->deleteEnemy(i);
						break;
					}
				}
			}

		}
	}


}