#include "stdafx.h"
#include "sceneET.h"


sceneET::sceneET()
{
}


sceneET::~sceneET()
{
}


void sceneET::init(void)
{
	//_pm = new PlayerManager;
	//_pm->init();
	_em = new EnemyManager;
	_em->init();
	_sm = new stageManager;
	_sm->init();
	_im = new itemManager;
	_im->init();

//_pm->setLinkAdressEnemyManager(_em);
//_pm->setLinkAdressStageManager(_sm);
//_pm->setLinkAdressItemManager(_im);

	_em->setLinkAdressPlayerManager(_pm);
	_em->setLinkAdressStageManager(_sm);
	_em->setLinkAdressItemManager(_im);

	_sm->setLinkAdressPlayerManager(_pm);
	_sm->setLinkAdressEnemyManager(_em);
	_sm->setLinkAdressItemManager(_im);

	_im->setLinkAdressPlayerManager(_pm);
	_im->setLinkAdressEnemyManager(_em);
	_im->setLinkAdressStageManager(_sm);
}

void sceneET::release(void)
{

}

void sceneET::update(void)
{
	//_pm->update();
	_em->update();
}

void sceneET::render(void)
{
//	_pm->render();
	_em->render();
	IMAGEMANAGER->findImage(L"충돌테스트보여줘요")->render();

}