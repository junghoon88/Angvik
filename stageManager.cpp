#include "stdafx.h"
#include "stageManager.h"


stageManager::stageManager()
{
}


stageManager::~stageManager()
{
}


void stageManager::init(void)
{
	//_imgBackground = IMAGEMANAGER->findImage(L"Stage1-BG");
	_imgBackground = IMAGEMANAGER->findImage(L"Stage1-PBG");
	_imgPBG = PBGMANAGER->findImage(L"Stage1-PBG");
}

void stageManager::release(void)
{

}

void stageManager::update(void)
{

}

void stageManager::render(void)
{
	_imgBackground->render();
}

void stageManager::GoNextStage(void)
{

}
