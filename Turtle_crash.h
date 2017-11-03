#pragma once
#include "EnemyMother.h"
class Turtle_crash :
	public EnemyMother
{
public:
	Turtle_crash();
	~Turtle_crash();

	void init(int num, float x, float y);
	void update(void);
	void render(void);
	void move(void);
};

