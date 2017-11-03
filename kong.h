#pragma once
#include "EnemyMother.h"
class kong : public EnemyMother
{
private:
	int atkCnt;
public:
	kong();
	~kong();

	void init(int num, float x, float y);
	void update(float playerx,float playery);
	void render(void);
	void move(float playerx, float playery);
	bool attack(void);
};

