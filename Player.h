#pragma once
#include "DxWindow.h"
#include "jump.h"
#include "pixelCollision.h"

#define HEAD_WIDTH		26
#define HEAD_HEIGHT		25

#define BODY_WIDTH		30
#define BODY_HEIGHT		32

#define FOOT_WIDTH		30
#define FOOT_HEIGHT		10

#define PLAYERSPEED		 4.0f
#define JUMPPOWER		10.0f
#define ATTACKJUMPPOWER	 5.0f
#define GRAVITY			 0.5f

//아이템 상태
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

enum EQUIPARMORSTATE
{
	UNARMEDARMOR,
	WHITE,
	GOLD,
	BLACK
};

enum EQUIPWEAPONSTATE
{
	UNARMEDWEAPON,
	WHITE_SWORD,
	WHITE_LANCE,
	WHITE_BOOMERANG,
	WHITE_STAFF,
	GOLD_SWORD,
	GOLD_LANCE,
	GOLD_BOOMERANG,
	GOLD_STAFF,
	BLACK_SWORD,
	BLACK_LANCE,
	BLACK_BOOMERANG,
	BLACK_STAFF
};

class Player : public DxWindow
{
private:
	PLAYERHEADSTATE _headState;
	PLAYERBODYSTATE _bodyState;

	EQUIPARMORSTATE _headItem;
	EQUIPARMORSTATE _bodyItem;
	EQUIPARMORSTATE _footItem;

	EQUIPWEAPONSTATE _frontItem;
	EQUIPWEAPONSTATE _backItem;

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

	Sprite* _blackBodyRightImage;
	Sprite* _blackBodyLeftImage;
	Sprite* _blackFootRightImage;
	Sprite* _blackFootLeftImage;

	Sprite* _goldBodyRightImage;
	Sprite* _goldBodyLeftImage;
	Sprite* _goldFootRightImage;
	Sprite* _goldFootLeftImage;

	Sprite* _whiteBodyRightImage;
	Sprite* _whiteBodyLeftImage;
	Sprite* _whiteFootRightImage;
	Sprite* _whiteFootLeftImage;

	Sprite* _boneHead;
	Sprite* _boneBody;
	Sprite* _bone[4];

	RECT _rcHead;
	RECT _rcBody;
	RECT _rcFoot;

	jump* _playerJump;
	pixelCollision* _playerPixelCollision;

	float _x, _y;
	float _probeY;

	bool _isFrontAttack;	//	front로 공격했는지
	bool _isBackAttack;		//	back으로 공격했는지
	bool _isRight;			//	오른쪽으로 보고 있는지
	bool _isSit;			//	앉아있는지
	bool _isLive;			//	살아있는지
	bool _isDead;			//	
	bool _isInven;			//	인벤토리를 활성화했는지
	bool _isJumpAttack;		//	점프공격중인지
	bool _isHit;			//	피격상태인지
	bool _isImmortal;		//	무적상태인지

	float _handX, _handY;
	float _armLen0, _armLen1, _armLen2;
	float _frameAngle;

public:
	Player();
	~Player();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
	
	void itemPosUpdate(void);
	void playerDeadMotion(void);

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
	void rectUpdate(void);


	//========== GETTER && SETTER =======
	float getX(void) { return _x; }
	float getY(void) { return _y; }

	RECT getRectHead(void) { return _rcHead; }
	RECT getRectBody(void) { return _rcBody; }
	RECT getRectFoot(void) { return _rcFoot; }

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
	void setIsBackAttack(bool isAttack)
	{
		_isBackAttack = isAttack;
	}

	bool getIsfrontAttack(void)	{ return _isFrontAttack; }	
	bool getIsBackAttack(void)	{ return _isBackAttack; }

	bool getIsSit(void)			{ return _isSit; }
	bool getIsJump(void)		{ return _playerJump->getIsJumping(); }
	bool getIsLive(void)		{ return _isLive; }
	
	bool getIsHit(void)			{ return _isHit; }
	void setIsHit(bool isHit)	{ _isHit = isHit; }

	bool getIsImmortal(void) { return _isImmortal; }
	void setIsImmortal(bool isImmortal) { _isImmortal = isImmortal; }

	bool getIsInven(void)		{ return _isInven; }
	void setIsInven(bool isInven) { _isInven = isInven; }

	bool getIsRight(void) { return _isRight; }
	EQUIPARMORSTATE getHeadItem(void) { return _headItem; }	
	EQUIPARMORSTATE getBodyItem(void) { return _bodyItem; }	
	EQUIPARMORSTATE getFootItem(void) { return _footItem; }

	EQUIPWEAPONSTATE getFrontItem(void) { return _frontItem; }
	EQUIPWEAPONSTATE getBackItem(void) { return _backItem; }

	void setHeadItem(EQUIPARMORSTATE item) { _headItem = item; }
	void setBodyItem(EQUIPARMORSTATE item) { _bodyItem = item; }
	void setFootItem(EQUIPARMORSTATE item) { _footItem = item; }

	void setFrontItem(EQUIPWEAPONSTATE item) { _frontItem = item; }
	void setBackItem(EQUIPWEAPONSTATE item) { _backItem = item; }

	float getHandX(void) { return _handX; }
	float getHandY(void) { return _handY; }

	void setIsJumpAttack(bool isJumpAttack) { _isJumpAttack = isJumpAttack; }
};