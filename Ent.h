#pragma once
#include "EnemyMother.h"
class Ent : public EnemyMother
{
private:
	float atkCnt;
	Sprite* atkSpt;
public:
	Ent();
	~Ent();

	void init(int num, float x, float y, wstring rcKey);
	void update(void);
	void render(void);
	void move(void);
};

