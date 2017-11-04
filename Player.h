#pragma once
#include "DxWindow.h"
#include "Item.h"
#include "jump.h"
#include "pixelCollision.h"

#define BODY_WIDTH		33
#define BODY_HEIGHT		54

#define PLAYERSPEED 4.f
#define JUMPPOWER 9.f
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
	animation* _frontArmMotion;
	animation* _backArmMotion;

	animation* _frontArmFrontAttackMotion;
	animation* _frontArmBackAttackMotion;
	animation* _backArmFrontAttackMotion;
	animation* _backArmBackAttackMotion;

	Sprite* _headImage;
	Sprite* _bodyRightImage;
	Sprite* _bodyLeftImage;
	Sprite* _frontArmRightImage;
	Sprite* _backArmRightImage;
	Sprite* _frontArmLeftImage;
	Sprite* _backArmLeftImage;

	RECT _rcHead;
	RECT _rcBody;
	RECT _rcAttack;
	RECT _rcItem;

	jump* _playerJump;
	pixelCollision* _playerPixelCollision;

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
	

	//========== CALL BACK ==========
	static void bodyRightJump(void* obj);
	static void bodyLeftJump(void* obj);
	static void bodyRightMoveJump(void* obj);
	static void bodyLeftMoveJump(void* obj);

	static void frontArmRightJump(void* obj);
	static void frontArmLeftJump(void* obj);
	static void frontArmRightMoveJump(void* obj);
	static void frontArmLeftMoveJump(void* obj);

	static void backArmRightJump(void* obj);
	static void backArmLeftJump(void* obj);
	static void backArmRightMoveJump(void* obj);
	static void backArmLeftMoveJump(void* obj);

	static void attackIsEnd(void* obj);


	//========== I N I T ==========
	void imageReverse(void);
	void imagePosUpdate(void);
	void keyAnimationInit(void);


	//========== U P D A T E ==========
	void keyInputSettings(void);
	void attackMotions(void);
		

	//========== GETTER && SETTER =======
	float getX(void) { return _x; }
	float getY(void) { return _y; }

	RECT getRectHead(void) { return _rcHead; }
	RECT getRectBody(void) { return _rcBody; }

	PLAYERBODYSTATE getPlayerBodyState(void) { return _bodyState; }
	void setPlayerBodyState(PLAYERBODYSTATE state) { _bodyState = state; }

	animation* getPlayerBodyMotion(void) { return _bodyMotion; }
	void setPlayerBodyMotion(animation* ani) { _bodyMotion = ani; }

	animation* getPlayerFrontArmMotion(void) { return _frontArmMotion; }
	void setPlayerFrontArmMotion(animation* ani) { _frontArmMotion = ani; }

	animation* getPlayerBackArmMotion(void) { return _backArmMotion; }
	void setPlayerBackArmMotion(animation* ani) { _backArmMotion = ani; }

	PLAYERBODYSTATE getBodyState(void) { return _bodyState; }
	void setBodyState(PLAYERBODYSTATE state) { _bodyState = state; }

	void setIsFrontAttack(bool isAttack)
	{
		_isFrontAttack = isAttack; 
	}

	void setIsBackAttack(bool isAttack) { _isBackAttack = isAttack; }

};