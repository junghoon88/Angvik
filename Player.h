#pragma once
#include "DxWindow.h"

#define PLAYERSPEED 2.f
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

	animation* _bodyMotion;
	animation* _armFrontMotion;
	animation* _armBackMotion;

	Sprite* _headImage;
	Sprite* _bodyRightImage;
	Sprite* _bodyLeftImage;
	Sprite* _armRightFrontImage;
	Sprite* _armRightBackImage;
	Sprite* _armLeftFrontImage;
	Sprite* _armLeftBackImage;

	RECT _rcHead;
	RECT _rcBody;

	float _x, _y;
	float _probeY;
	float _jumpPower;

	bool _isRight;

public:
	Player();
	~Player();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

	void imageReverse(void);
	void keyAnimationInit(void);
	void imagePosUpdate(void);

};