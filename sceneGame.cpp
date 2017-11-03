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
}

void sceneGame::release(void)
{

}

void sceneGame::update(void)
{
	_pm->update();

	if (!SOUNDMANAGER->isPlaySound(L"stage1bgm"))
	{
		if (SOUNDMANAGER->isPlaySound(L"메뉴브금"))
		{
			SOUNDMANAGER->stop(L"메뉴브금");
		}
		SOUNDMANAGER->play(L"stage1bgm", DATABASE->getVolume());
		SOUNDMANAGER->setMuteAll(DATABASE->getMute());
	}

	MAINCAMERA->update();
}

void sceneGame::render(void)
{
	IMAGEMANAGER->findImage(L"Stage1-BG")->render();
	_pm->render();
}
