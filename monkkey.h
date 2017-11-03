#pragma once
#include "EnemyMother.h"
class monkkey :
	public EnemyMother
{

public:
<<<<<<< HEAD
	void init(int num, float x, float y, wstring rcKey);
=======
	void init(float x, float y, wstring rcKey);
>>>>>>> edf7b881d15513fe56d4a4a76a89b1919a850da4
	void update(void);
	void render(void);
	void move(void);

	monkkey();
	~monkkey();
};

