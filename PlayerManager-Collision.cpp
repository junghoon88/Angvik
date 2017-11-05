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


	for (int i = 0; i < _em->getvEnemy().size(); i++)   //�÷��̾� �����浹ó��
	{	
		RECT temp2;
		if (IntersectRect(&temp2, &_player->getRectBody(), &_em->getvEnemy()[i]->getRect()) && !_player->getIsJump()) {     //�÷��̾� ���ع���
	

		}
		RECT temp;
		if (IntersectRect(&temp, &_player->getRectFoot(), &_em->getvEnemy()[i]->getRect()) && _player->getIsJump()) {    //�÷��̾ ������
			_em->getvEnemy()[i]->setLife((_em->getvEnemy()[i]->getLife()) - 1);   //life -1

			if (_em->getvEnemy()[i]->getLife() <= 0) {
				_im->setItem(_em->getvEnemy()[i]->getX(), _em->getvEnemy()[i]->getY()-30);
				_em->deleteEnemy(i);
				break;
			}
		}
	}
}