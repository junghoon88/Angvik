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
			  //피해신호
			_player->hitFeedback(_em->getKongtan()->getVBullet()[i].ptX);
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
			_player->hitFeedback(_em->getSbmr()->getVBullet()[i].ptX);
			_em->getSbmr()->remove(i);
			//아이템에 신호 넘겨줘야함

			break;
		}
	}

	/////////////////////////////////////////////

	for (int i = 0; i < _em->getvEnemy().size(); i++)   //플레이어 몬스터충돌처리
	{
		if (isCollision(_player->getRectBody(), _em->getvEnemy()[i]->getRect())&& _em->getvEnemy()[i]->getState() != toDeath)    //플레이어 피해받음
		{
			_player->hitFeedback(_em->getvEnemy()[i]->getX());
		}
		if (isCollision(_player->getRectFoot(), _em->getvEnemy()[i]->getRect())&&!_em->getvEnemy()[i]->getImmune() && _player->getIsJump())	  //플레이어가 적밟음
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
				if (_im->getVItem()[j]->getState() == ITEM_STATE_ATTACK)
				{
					if (IntersectRect(&temp, &_im->getVItem()[j]->getHitImg(), &_em->getvEnemy()[i]->getRect()) && !_em->getvEnemy()[i]->getImmune())
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
						if (_em->getvEnemy()[i]->getLife() <= 0)
						{
							_em->getvEnemy()[i]->setLife((_em->getvEnemy()[i]->getLife()) - 1);
							break;
						}
					}
				}
			}
		}
	}
}