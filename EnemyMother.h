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
	image* img;
	RECT rc;
	float ptX;
	float ptY;
	float speed;
	float jumpPower;
	int life;
	
	enemyDirection dir;
	enemyState state;

public:
	void init(void);
	void init(const char* imagekey,float x,float y);
	void release(void);
	void update(void);
	void render(void);

	virtual void move(void);
	virtual void attack(void);

	inline int getLife(void) { return life; }
	inline enemyState getState(void) { return state; }
	inline RECT getRect(void) { return rc; }


	EnemyMother();
	~EnemyMother();
};

