#pragma once
#include "DxWindow.h"
#include "Item.h"
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
	PLAYER_LEFT_MOVE_JUMP/*,
	PLAYER_RIGHT_ATTACK,
	PLAYER_LEFT_ATTACK,
	PLAYER_RIGHT_MOVE_ATTACK,
	PLAYER_LEFT_MOVE_ATTACK,
	PLAYER_RIGHT_SIT_ATTACK,
	PLAYER_LEFT_SIT_ATTACK,
	PLAYER_RIGHT_JUMP_ATTACK,
	PLAYER_LEFT_JUMP_ATTACK,
	PLAYER_RIGHT_MOVE_JUMP_ATTACK,
	PLAYER_LEFT_MOVE_JUMP_ATTACK*/
};

class Player : public DxWindow
{
private:
	PLAYERHEADSTATE _headState;
	PLAYERBODYSTATE _bodyState;

	animation* _bodyMotion;
	animation* _armFrontMotion;
	animation* _armBackMotion;

	animation* _frontArmFrontAttackMotion;
	animation* _frontArmBackAttackMotion;
	animation* _backArmFrontAttackMotion;
	animation* _backArmBackAttackMotion;

	Sprite* _headImage;
	Sprite* _bodyRightImage;
	Sprite* _bodyLeftImage;
	Sprite* _armRightFrontImage;
	Sprite* _armRightBackImage;
	Sprite* _armLeftFrontImage;
	Sprite* _armLeftBackImage;

	RECT _rcHead;
	RECT _rcBody;
	RECT _rcAttack;

	jump* _playerJump;

	ITEM_TYPE _weaponType;

	float _x, _y;
	float _probeY;

	bool _isFrontAttack;
	bool _isBackAttack;
	bool _isRight;
	bool _isSit;
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

	static void attackIsEnd(void* obj);

	PLAYERBODYSTATE getPlayerBodyState(void) { return _bodyState; }
	void setPlayerBodyState(PLAYERBODYSTATE state) { _bodyState = state; }

	animation* getPlayerBodyMotion(void) { return _bodyMotion; }
	void setPlayerBodyMotion(animation* ani) { _bodyMotion = ani; }

	animation* getPlayerArmFrontMotion(void) { return _armFrontMotion; }
	void setPlayerArmFrontMotion(animation* ani) { _armFrontMotion = ani; }

	animation* getPlayerArmBackMotion(void) { return _armBackMotion; }
	void setPlayerArmBackMotion(animation* ani) { _armBackMotion = ani; }

	PLAYERBODYSTATE getBodyState(void) { return _bodyState; }
	void setBodyState(PLAYERBODYSTATE state) { _bodyState = state; }

	void setIsFrontAttack(bool isAttack) { _isFrontAttack = isAttack; }
	void setIsBackAttack(bool isAttack) { _isBackAttack = isAttack; }

	//========== I N I T ==========
	void imageReverse(void);
	void imagePosUpdate(void);
	void keyAnimationInit(void);

	//========== U P D A T E ==========
	void keyInputSettings(void);
	void attackMotions(void);

};