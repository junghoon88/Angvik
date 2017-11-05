#include "stdafx.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "itemManager.h"

void PlayerManager::Collision(void)
{
	////////////////////////////////////////// 불렛충돌
	for (int i = 0; i < _em->getKongtan()->getVBullet().size(); i++)
	{
		if (isCollision(_em->getKongtan()->getVBullet()[i].rc,
			_player->getRectBody()))
		{
			_player->setIsHit(true);    //피해신호
			_em->getKongtan()->remove(i);
			//아이템에 신호 넘겨줘야함
			break;
		}

	}
	///////////////////////////////////////////////
	// 콩탄

	for (int i = 0; i < _em->getSbmr()->getVBullet().size(); i++)
	{
		RECT temp;
		if (isCollision(_em->getSbmr()->getVBullet()[i].rc,
			_player->getRectBody()))
		{
			_player->setIsHit(true);
			_em->getSbmr()->remove(i);
			//아이템에 신호 넘겨줘야함

			break;
		}
	}

	/////////////////////////////////////////////

	for (int i = 0; i < _em->getvEnemy().size(); i++)   //플레이어 몬스터충돌처리
	{
		RECT temp2;

		if (IntersectRect(&temp2, &_player->getRectBody(), &_em->getvEnemy()[i]->getRect()) && _player->getIsImmortal() == FALSE && _em->getvEnemy()[i]->getState() != toDeath)    //플레이어 피해받음
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

		if (IntersectRect(&temp, &_player->getRectFoot(), &_em->getvEnemy()[i]->getRect()) && _player->getIsJump())	  //플레이어가 적밟음
		{
			_em->getvEnemy()[i]->setLife((_em->getvEnemy()[i]->getLife()) - 1);   //life -1

			_player->setIsJumpAttack(TRUE);
		}
	}

	for (int i = 0; i < _em->getvEnemy().size(); i++)   //플레이어 무기 몬스터
	{
		for (int j = 0; j < _im->getVItem().size(); j++)
		{
			RECT temp;

			if (_im->getVItem()[j]->getState() == ITEM_STATE_ATTACK)
			{
				if (IntersectRect(&temp, &_im->getVItem()[j]->getHitImg(), &_em->getvEnemy()[i]->getRect()))
				{    //플레이어가 무기씀
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