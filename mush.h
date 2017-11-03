#pragma once
#include "EnemyMother.h"
class mush :
	public EnemyMother
{
private:
	Sprite *atkspt;
	Sprite *jmpspt;

	int atkFrameCnt;
	float atkFrameTime;
	int jumpFrameCnt;
	float jumpFrameTime;

public:
	void init(float x, float y, wstring rcKey);
	void update(void);
	void render(void);
	void move(void);
	void attack(void);

	mush();
	~mush();
};

