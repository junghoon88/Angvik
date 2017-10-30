#include "stdafx.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "stageManager.h"
#include "itemManager.h"

PlayerManager::PlayerManager()
{
}


PlayerManager::~PlayerManager()
{
}

void PlayerManager::init(void)
{
	_player = new Player;
	_player->init();
}

void PlayerManager::release(void)
{

}

void PlayerManager::update(void) 
{
	_player->update();
}

void PlayerManager::render(void) 
{
	_player->render();
}

