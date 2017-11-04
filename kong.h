#pragma once
#include "EnemyMother.h"

class kong : public EnemyMother
{
private:
	float atkCnt;
	Sprite* atkSpt;
	float playerX, playerY;

public:
	kong();
	~kong();



	void init(int num, float x, float y);
	void update(void);
	void render(void);
	

	void setPlayerX();
};

