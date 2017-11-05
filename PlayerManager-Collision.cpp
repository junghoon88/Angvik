#include "stdafx.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "itemManager.h"

void PlayerManager::Collision(void)
{
	for (int i = 0; i < _em->getKongtan()->getVBullet().size();i++)
	{
		if (isCollision(_em->getKongtan()->getVBullet()[i].rc,
			_player->getRectBody()))
		{
			_em->getKongtan()->remove(i);
			//아이템에 신호 넘겨줘야함
			break;
		}
	
	} // 콩탄

	for (int i = 0; i < _em->getSbmr()->getVBullet().size(); i++)
	{
		RECT temp;
		if (isCollision(_em->getSbmr()->getVBullet()[i].rc,
			_player->getRectBody()))
		{
			_em->getSbmr()->remove(i);
			//아이템에 신호 넘겨줘야함

			break;
		}
	}


	for (int i = 0; i < _em->getvEnemy().size(); i++)   //플레이어 몬스터충돌처리
	{	
		RECT temp2;
		if (IntersectRect(&temp2, &_player->getRectBody(), &_em->getvEnemy()[i]->getRect()) && !_player->getIsJump()) {     //플레이어 피해받음
	

		}
		RECT temp;
		if (IntersectRect(&temp, &_player->getRectFoot(), &_em->getvEnemy()[i]->getRect()) && _player->getIsJump()) {    //플레이어가 적밟음
			_em->getvEnemy()[i]->setLife((_em->getvEnemy()[i]->getLife()) - 1);   //life -1

			if (_em->getvEnemy()[i]->getLife() <= 0) {
				_im->setItem(_em->getvEnemy()[i]->getX(), _em->getvEnemy()[i]->getY()-30);
				_em->deleteEnemy(i);
				break;
			}
		}
	}
}