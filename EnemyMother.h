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
	
	int frameCnt;
	float frameTime;

	enemyDirection dir;
	enemyState state;

public:
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

