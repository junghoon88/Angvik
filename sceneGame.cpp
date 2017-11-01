#include "stdafx.h"
#include "sceneGame.h"

sceneGame::sceneGame()
{
}


sceneGame::~sceneGame()
{
}

void sceneGame::init(void)
{
	_pm = new PlayerManager;
	_pm->init();
	_em = new EnemyManager;
	_em->init();
	_sm = new stageManager;
	_sm->init();
	_im = new itemManager;
	_im->init();

	_pm->setLinkAdressEnemyManager(_em);
	_pm->setLinkAdressStageManager(_sm);
	_pm->setLinkAdressItemManager(_im);

	_em->setLinkAdressPlayerManager(_pm);
	_em->setLinkAdressStageManager(_sm);
	_em->setLinkAdressItemManager(_im);

	_sm->setLinkAdressPlayerManager(_pm);
	_sm->setLinkAdressEnemyManager(_em);
	_sm->setLinkAdressItemManager(_im);
	
	_im->setLinkAdressPlayerManager(_pm);
	_im->setLinkAdressEnemyManager(_em);
	_im->setLinkAdressStageManager(_sm);


	Sprite* background = IMAGEMANAGER->addImage(DEVICE, L"테스트배경", L"image/Stage/Stage1-Background.png", false);
	MAINCAMERA->setMinMax(0, 0, background->getSize().x - WINSIZEX, background->getSize().y - WINSIZEY);
}

void sceneGame::release(void)
{

}

void sceneGame::update(void)
{
	_pm->update();

	MAINCAMERA->update();
}

void sceneGame::render(void)
{
	IMAGEMANAGER->findImage(L"테스트배경")->render();
	_pm->render();
}
