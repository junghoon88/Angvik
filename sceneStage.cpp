#include "stdafx.h"
#include "sceneStage.h"


sceneStage::sceneStage()
{
}


sceneStage::~sceneStage()
{
}

void sceneStage::init(void)
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

	_pm->getInven()->setLinkAdressItemManager(_im);
	_pm->getPlayer()->setLinkAdressItemManager(_im);

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

void sceneStage::release(void)
{

}

void sceneStage::update(void)
{
	_pm->update();
	_em->update();
	_sm->update();
	_im->update();

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

void sceneStage::render(void)
{
	_sm->render();
	if (KEYMANAGER->isStayKeyDown(VK_F2)) IMAGEMANAGER->findImage(L"Stage1-PBG")->render();
	_em->render();
	_pm->render();
	_im->render();
}
