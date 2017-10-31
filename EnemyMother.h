#pragma once
#include "DxWindow.h"
enum enemyDirection {
	eLEFT,
	eRIGHT
};
enum enemyState
{
	eIDLE,
	eATK,
	eJUMP
};

class EnemyMother
{
protected:
	Sprite* spt;
	RECT rc;
	float ptX;
	float ptY;
	float speed;
	float jumpPower;
	int life;
<<<<<<< HEAD
	
	int frameCnt;
	float frameTime;
=======

>>>>>>> 0b9979bfc1dbdc7dafd5842f650ecf7427e33e1c

	enemyDirection dir;
	enemyState state;

public:
<<<<<<< HEAD
=======
<<<<<<< HEAD

=======
>>>>>>> e8a3ab6eafc3de7f28c7c2fa081d912d60f04928
>>>>>>> 0b9979bfc1dbdc7dafd5842f650ecf7427e33e1c
	virtual void init(float x,float y);
	void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void move(void);
	virtual void attack(void);

	inline int getLife(void) { return life; }
	inline enemyState getState(void) { return state; }
	inline RECT getRect(void) { return rc; }


	EnemyMother();
	~EnemyMother();
};

