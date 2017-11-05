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

	_bird = new invenBird;
	_bird->init(_player->getX(), _player->getY());

	_inven = new inven;
	_inven->init();

	_playerRcHead = _player->getRectHead();
	_playerRcBody = _player->getRectBody();
	_playerRcFoot = _player->getRectFoot();
}

void PlayerManager::release(void)
{

}

void PlayerManager::update(void) 
{
	_player->update();
	_bird->update(_player->getX(), _player->getY());
	_inven->update(_player->getX(), _player->getY());
}

void PlayerManager::render(void) 
{
	_player->render();
	_bird->render();
	_inven->render();
}

