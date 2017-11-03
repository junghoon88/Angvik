#pragma once
#include "EnemyMother.h"
class monkkey :
	public EnemyMother
{

public:
	void init(float x, float y,wstring rcKey);
	void update(void);
	void render(void);
	void move(void);
	void attack(void);

	monkkey();
	~monkkey();
};

