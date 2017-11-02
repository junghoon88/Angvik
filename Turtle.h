#pragma once
#include "EnemyMother.h"
class Turtle :
	public EnemyMother
{
public:
	Turtle();
	~Turtle();

	void init(float x, float y);
	void update(void);
	void render(void);
	void move(void);
	void attack(void);
};

