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
<<<<<<< HEAD
	virtual void init(float x,float y);
=======
	void init(void);
	void init(const char* imagekey,float x,float y);
>>>>>>> 771d3423ccb67fd990ca6bda0c428064a643553d
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

