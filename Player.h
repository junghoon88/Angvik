#pragma once
#include "DxWindow.h"
#include "jump.h"

#define PLAYERSPEED 4.f
#define JUMPPOWER 8.f
#define GRAVITY 0.4f

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
	PLAYER_LEFT_JUMP,
	PLAYER_RIGHT_MOVE_JUMP,
	PLAYER_LEFT_MOVE_JUMP
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

	jump* _playerJump;

	float _x, _y;
	float _probeY;

	bool _isRight;
	bool _isLive;

public:
	Player();
	~Player();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

	static void bodyRightJump(void* obj);
	static void bodyLeftJump(void* obj);
	static void bodyRightMoveJump(void* obj);
	static void bodyLeftMoveJump(void* obj);

	static void armFrontRightJump(void* obj);
	static void armFrontLeftJump(void* obj);
	static void armFrontRightMoveJump(void* obj);
	static void armFrontLeftMoveJump(void* obj);

	static void armBackRightJump(void* obj);
	static void armBackLeftJump(void* obj);
	static void armBackRightMoveJump(void* obj);
	static void armBackLeftMoveJump(void* obj);

	PLAYERBODYSTATE getPlayerBodyState(void) { return _bodyState; }
	void setPlayerBodyState(PLAYERBODYSTATE state) { _bodyState = state; }

	animation* getPlayerBodyMotion(void) { return _bodyMotion; }
	void setPlayerBodyMotion(animation* ani) { _bodyMotion = ani; }

	animation* getPlayerArmFrontMotion(void) { return _armFrontMotion; }
	void setPlayerArmFrontMotion(animation* ani) { _armFrontMotion = ani; }

	animation* getPlayerArmBackMotion(void) { return _armBackMotion; }
	void setPlayerArmBackMotion(animation* ani) { _armBackMotion = ani; }

	//========== I N I T ==========
	void imageReverse(void);
	void keyAnimationInit(void);
	void imagePosUpdate(void);

	//========== U P D A T E ==========
	void keyInputSettings(void);

};