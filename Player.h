#pragma once
#include "DxWindow.h"

#define PLAYERSPEED 5.f
#define JUMPPOWER 10.f
#define GRAVITY 5.f

enum PLAYERHEADSTATE
{
	PLAYER_YOUNGEST,
	PLAYER_YOUNG,
	PLAYER_OLD,
	PLAYER_ELDEST
};

enum PLAYERBODYSTATE
{
	PLAYER_RIGHT_STOP,
	PLAYER_LEFT_STOP,
	PLAYER_RIGHT_MOVE,
	PLAYER_LEFT_MOVE,
	PLAYER_RIGHT_SIT,
	PLAYER_LEFT_SIT,
	PLAYER_RIGHT_JUMP,
	PLAYER_LEFT_JUMP
};

class Player : public DxWindow
{
private:
	PLAYERHEADSTATE _headState;
	PLAYERBODYSTATE _bodyState;

	animation* _motion;

	image* _bodyImage;

	RECT _rcHead;
	RECT _rcBody;

	float _x, _y;
	float _probeY;
	float _jumpPower;

public:
	Player();
	~Player();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

};