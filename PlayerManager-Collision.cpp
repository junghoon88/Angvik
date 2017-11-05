#include "stdafx.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "stageManager.h"
#include "itemManager.h"

void PlayerManager::Collision(void)
{
	for (int i = 0; i < _em->getKongtan()->getVBullet().size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_em->getKongtan()->getVBullet()[i].rc,
			&_player->getRectBody()))
		{
			_em->getKongtan()->remove(i);

			break;
		}
	} // ÄáÅº




	for (int i = 0; i < _em->getSbmr()->getVBullet().size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_em->getSbmr()->getVBullet()[i].rc,
			&_player->getRectBody()))
		{
			_em->getSbmr()->remove(i);

			break;
		}
	}
}