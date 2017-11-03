#pragma once
#include "EnemyMother.h"
class mush :
	public EnemyMother
{
private:
	Sprite *atkspt;
	Sprite *jmpspt;

	int startY;
	int atkFrameCnt;
	float atkFrameTime;
	int jumpFrameCnt;
	float jumpFrameTime;

public:
	void init(int num, float x, float y, wstring rcKeyy);
	void update(void);
	void render(void);
	void move(void);
	void attack(void);

	mush();
	~mush();
};

