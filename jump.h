#pragma once
#include "DxWindow.h"


class jump : public DxWindow
{
private:
	float _jumpPower;
	float _gravity;

	float* _x;
	float* _y;

	float _startX;
	float _startY;

	bool _isJumping;

public:
	jump();
	~jump();

	void init();
	void release();
	void update();
	void render();

	void jumping(float* x, float* y, float jumpPower, float gravity);

	bool getIsJumping() { return _isJumping; }
};

