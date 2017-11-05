#pragma once
#include "EnemyMother.h"
class mush :
	public EnemyMother
{
private:
	Sprite *atkspt;
	Sprite *jmpspt;

	float atkCnt;
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
	

	mush();
	~mush();
};

