#include "stdafx.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "itemManager.h"

void PlayerManager::Collision(void)
{
	for (int i = 0; i < _em->getKongtan()->getVBullet().size(); i++)
	{
		if (isCollision(_em->getKongtan()->getVBullet()[i].rc,
			_player->getRectBody()))
		{
			_em->getKongtan()->remove(i);
			//�����ۿ� ��ȣ �Ѱ������
			break;
		}
	} // ��ź
	
	for (int i = 0; i < _em->getSbmr()->getVBullet().size(); i++)
	{
		RECT temp;
		if (isCollision(_em->getSbmr()->getVBullet()[i].rc,
			_player->getRectBody()))
		{
			_em->getSbmr()->remove(i);
			//�����ۿ� ��ȣ �Ѱ������
			break;
		}
	}


}