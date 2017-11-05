#pragma once
#include "DxWindow.h"
#include "Player.h"
#include "invenBird.h"
#include "inven.h"

//전방선언
class EnemyManager;
class stageManager;
class itemManager;

class PlayerManager : public DxWindow
{
private:
	typedef vector<Item*> vItems;
	typedef vector<Item*>::iterator viItems;

private:
	vItems _vItems;
	viItems _viItems;

private:
	Player*			_player;
	invenBird*		_bird;
	inven*			_inven;
	
	EnemyManager*	_em;
	stageManager*	_sm;
	itemManager*	_im;


	RECT _playerRcHead;
	RECT _playerRcBody;
	RECT _playerRcFoot;

public:
	PlayerManager();
	~PlayerManager();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

	void playerItemCollision(void);

	void Collision(void);


	//getter, setter
	inline void setLinkAdressEnemyManager(EnemyManager*   em) { _em = em; }
	inline void setLinkAdressStageManager(stageManager*   sm) { _sm = sm; }
	inline void setLinkAdressItemManager(itemManager*     im) { _im = im; }


	inline Player* getPlayer(void) { return _player; }
};

