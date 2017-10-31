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


	enemyDirection dir;
	enemyState state;

public:
<<<<<<< HEAD

=======
>>>>>>> e8a3ab6eafc3de7f28c7c2fa081d912d60f04928
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

