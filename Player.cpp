#include "stdafx.h"
#include "Player.h"

Player::Player()
{
}


Player::~Player()
{
}


void Player::init(void)
{
	_playerJump = new jump;
	_playerJump->init();

	_headState = PLAYER_YOUNGEST;
	_bodyState = PLAYER_RIGHT_STOP;

	// 발 사이 맨 밑
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	_rcHead = RectMakeCenter(_x - 9, _y - 52, 20, 20);
	_rcBody = RectMake(_x - 10, _y - 33, 20, 33);

	_headImage = IMAGEMANAGER->findImage(L"headRight0");

	_bodyRightImage = IMAGEMANAGER->findImage(L"unarmedBodyRight");
	_bodyLeftImage = IMAGEMANAGER->findImage(L"unarmedBodyLeft");

	_armRightFrontImage = IMAGEMANAGER->findImage(L"armRightFront");
	_armRightBackImage = IMAGEMANAGER->findImage(L"armRightBack");
	_armLeftFrontImage = IMAGEMANAGER->findImage(L"armLeftFront");
	_armLeftBackImage = IMAGEMANAGER->findImage(L"armLeftBack");

	_isRight = TRUE;
	_isLive = TRUE;

	//========== 이미지 왼쪽 보게 바꾸기 ==========

	imageReverse();

	//========== 부위별 키 애니메이션 초기화 ==========

	keyAnimationInit();

	//========== 각 부위 위치 업데이트 ==========

	imagePosUpdate();

	//========== 최초 모션 세팅 ==========
	_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightStop");
	_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightStop");
	_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightStop");
	_armFrontMotion->start();
	_armBackMotion->start();

	TEXTMANAGER->init(DEVICE, L"플레이어상태");

}

void Player::release(void)
{

}

void Player::update(void)
{
	keyInputSettings();		//	KEY INPUT

	if (_isRight == TRUE)
	{
		switch (_headState)
		{
		case PLAYER_YOUNGEST:
			_headImage = IMAGEMANAGER->findImage(L"headRight0");
			break;
		case PLAYER_YOUNG:
			_headImage = IMAGEMANAGER->findImage(L"headRight1");
			break;
		case PLAYER_OLD:
			_headImage = IMAGEMANAGER->findImage(L"headRight2");
			break;
		case PLAYER_ELDEST:
			_headImage = IMAGEMANAGER->findImage(L"headRight3");
			break;
		}
	}
	else
	{
		switch (_headState)
		{
		case PLAYER_YOUNGEST:
			_headImage = IMAGEMANAGER->findImage(L"headLeft0");
			break;
		case PLAYER_YOUNG:
			_headImage = IMAGEMANAGER->findImage(L"headLeft1");
			break;
		case PLAYER_OLD:
			_headImage = IMAGEMANAGER->findImage(L"headLeft2");
			break;
		case PLAYER_ELDEST:
			_headImage = IMAGEMANAGER->findImage(L"headLeft3");
			break;
		}
	}

	switch (_bodyState)
	{
		case PLAYER_RIGHT_STOP: case PLAYER_LEFT_STOP:
		break;
		case PLAYER_RIGHT_MOVE:	case PLAYER_RIGHT_MOVE_JUMP:
			_x += PLAYERSPEED;
			imagePosUpdate();
			_rcHead = RectMakeCenter(_x - 9, _y - 52, 20, 20);
			_rcBody = RectMake(_x - 10, _y - 33, 20, 33);
		break;
		case PLAYER_LEFT_MOVE: case PLAYER_LEFT_MOVE_JUMP:
			_x -= PLAYERSPEED;
			imagePosUpdate();
			_rcHead = RectMakeCenter(_x - 9, _y - 52, 20, 20);
			_rcBody = RectMake(_x - 10, _y - 33, 20, 33);
		break;
	}

	imagePosUpdate();
	_rcHead = RectMakeCenter(_x - 9, _y - 52, 20, 20);
	_rcBody = RectMake(_x - 10, _y - 33, 20, 33);

	_playerJump->update();

	KEYANIMANAGER->update();
	
	TCHAR str[100];
	switch (_bodyState)
	{
		case PLAYER_RIGHT_STOP:			_stprintf(str, L"PLAYER_RIGHT_STOP:		");	break;
		case PLAYER_LEFT_STOP:			_stprintf(str, L"PLAYER_LEFT_STOP:		");	break;
		case PLAYER_RIGHT_MOVE:			_stprintf(str, L"PLAYER_RIGHT_MOVE:		");	break;
		case PLAYER_LEFT_MOVE:			_stprintf(str, L"PLAYER_LEFT_MOVE:		");	break;
		case PLAYER_RIGHT_SIT:			_stprintf(str, L"PLAYER_RIGHT_SIT:		");	break;
		case PLAYER_LEFT_SIT:			_stprintf(str, L"PLAYER_LEFT_SIT:		");	break;
		case PLAYER_RIGHT_JUMP:			_stprintf(str, L"PLAYER_RIGHT_JUMP:		");	break;
		case PLAYER_LEFT_JUMP:			_stprintf(str, L"PLAYER_LEFT_JUMP:		");	break;
		case PLAYER_RIGHT_MOVE_JUMP:	_stprintf(str, L"PLAYER_RIGHT_MOVE_JUMP:");	break;
		case PLAYER_LEFT_MOVE_JUMP:		_stprintf(str, L"PLAYER_LEFT_MOVE_JUMP:	");	break;
		default: _stprintf(str, L""); break;

	}
	TEXTMANAGER->addText(L"플레이어상태", str);

	MAINCAMERA->setTargetPos(_x - WINSIZEX / 2, _y - WINSIZEY / 2);
	MAINCAMERA->update();
}

void Player::render(void) 
{
	//	B A C K 팔
	if (_isRight == TRUE)
	{
		_armRightBackImage->aniRender(_armBackMotion);
	}
	else
	{
		_armLeftBackImage->aniRender(_armBackMotion);
	}

	//	 몸
	if (_isRight == TRUE)
	{
		_bodyRightImage->aniRender(_bodyMotion);
	}
	else
	{
		_bodyLeftImage->aniRender(_bodyMotion);
	}


	//	F R O N T 팔

	if (_isRight == TRUE)
	{
		_armRightFrontImage->aniRender(_armFrontMotion);
	}
	else
	{
		_armLeftFrontImage->aniRender(_armFrontMotion);
	}

	//	머 리
	_headImage->render();

	RECT rcText = RectMake(0, 0, 100, 100);
	TEXTMANAGER->render(L"플레이어상태", rcText);
}

void Player::imageReverse(void)
{
	IMAGEMANAGER->findImage(L"headLeft0")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft1")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft2")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft3")->setScale({ -1,1 });

	//IMAGEMANAGER->findImage(L"bodyLeftIdle")->setScale({ -1,1 });
	//IMAGEMANAGER->findImage(L"bodyLeftSit")->setScale({ -1,1 });
	//IMAGEMANAGER->findImage(L"bodyLeftJumpUp")->setScale({ -1,1 });
	//IMAGEMANAGER->findImage(L"bodyLeftJumpDown")->setScale({ -1,1 });
	//IMAGEMANAGER->findImage(L"bodyLeftWalk")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"unarmedBodyLeft")->setScale({ -1,1 });

	IMAGEMANAGER->findImage(L"armLeftFront")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"armLeftBack")->setScale({ -1,1 });
}

void Player::keyAnimationInit(void)
{

	//	몸 - idle, jump0, jump1, sit, walk0 ~ walk11 순
	//	I D L E
	int bodyRightIdle[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyRightStop", L"unarmedBodyRight", bodyRightIdle, 1, 10, true);
	int bodyLeftIdle[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyLeftStop", L"unarmedBodyLeft", bodyLeftIdle, 1, 10, true);

	//	W A L K
	int bodyRightMove[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyRightMove", L"unarmedBodyRight", bodyRightMove, 12, 20, true);
	int bodyLeftMove[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyLeftMove", L"unarmedBodyLeft", bodyLeftMove, 12, 20, true);

	//	S I T
	int bodyRightSit[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyRightSit", L"unarmedBodyRight", bodyRightSit, 1, 10, true);
	int bodyLeftSit[] = { 8 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyLeftSit", L"unarmedBodyLeft", bodyLeftSit, 1, 10, true);

	//	J U M P
	int bodyRightJump[] = { 1,2 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyRightJump", L"unarmedBodyRight", bodyRightJump, 2, 2, false, rightJump, this);
	int bodyLeftJump[] = { 1,2 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyLeftJump", L"unarmedBodyLeft", bodyLeftJump, 2, 2, false, leftJump, this);
	int bodyRightMoveJump[] = { 1,2 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyRightMoveJump", L"unarmedBodyRight", bodyRightMoveJump, 2, 2, false, rightMoveJump, this);
	int bodyLeftMoveJump[] = { 1,2 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyLeftMoveJump", L"unarmedBodyLeft", bodyLeftMoveJump, 2, 2, false, leftMoveJump, this);

	//	팔 - 16개방향 * 3가지 모션
	//	F R O N T
	//		I D L E
	int armFrontRightIdle[] = { 12,11,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightStop", L"armRightFront", armFrontRightIdle, 4, 4, true);
	int armFrontLeftIdle[] = { 12,11,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftStop", L"armLeftFront", armFrontLeftIdle, 4, 4, true);

	//		W A L K
	int armFrontRightMove[] = { 12,11,10,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightMove", L"armRightFront", armFrontRightMove, 8, 20, true);
	int armFrontLeftMove[] = { 12,11,10,9,10,11,12,13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftMove", L"armLeftFront", armFrontLeftMove, 8, 20, true);

	//		S I T
	//		J U M P

	//	B A C K
	//		I D L E
	int armBackRightIdle[] = { 11,12,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightStop", L"armRightBack", armBackRightIdle, 4, 4, true);
	int armBackLeftIdle[] = { 11,12,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftStop", L"armLeftBack", armBackLeftIdle, 4, 4, true);

	//		W A L K
	int armBackRightMove[] = { 12,13,14,13,12,11,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightMove", L"armRightBack", armBackRightMove, 8, 20, true);
	int armBackLeftMove[] = { 12,13,14,13,12,11,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftMove", L"armLeftBack", armBackLeftMove, 8, 20, true);

	//		S I T
	//		J U M P

}

void Player::imagePosUpdate(void)
{
	_headImage->setCoord({ _x + 3, _y - 32 });

	_bodyRightImage->setCoord({ _x, _y - 22 });
	_bodyLeftImage->setCoord({ _x, _y - 22 });

	_armRightFrontImage->setCoord({ _x - 3, _y - 20 });
	_armRightBackImage->setCoord({ _x + 7, _y - 20 });
	_armLeftFrontImage->setCoord({ _x + 3, _y - 20 });
	_armLeftBackImage->setCoord({ _x - 7, _y - 20 });
}

void Player::keyInputSettings(void)
{
	// ========== 이동 키 입력 ==========
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_isRight = TRUE;
		_bodyState = PLAYER_RIGHT_MOVE;
		_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightMove");
		_bodyMotion->start();

		_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightMove");
		_armFrontMotion->start();

		_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightMove");
		_armBackMotion->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_bodyState = PLAYER_RIGHT_STOP;
		_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightStop");
		_bodyMotion->start();

		_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightStop");
		_armFrontMotion->start();

		_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightStop");
		_armBackMotion->start();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_isRight = FALSE;
		_bodyState = PLAYER_LEFT_MOVE;
		_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftMove");
		_bodyMotion->start();

		_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontLeftMove");
		_armFrontMotion->start();

		_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackLeftMove");
		_armBackMotion->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_bodyState = PLAYER_RIGHT_STOP;
		_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightStop");
		_bodyMotion->start();

		_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontLeftStop");
		_armFrontMotion->start();

		_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackLeftStop");
		_armBackMotion->start();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))		//	Sit 키, 충돌 렉트 변화 필요
	{
		if (_bodyState == PLAYER_RIGHT_STOP || _bodyState == PLAYER_RIGHT_MOVE)
		{
			_bodyState = PLAYER_RIGHT_SIT;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightSit");
			_bodyMotion->start();
		}
		else if (_bodyState == PLAYER_LEFT_STOP || _bodyState == PLAYER_LEFT_MOVE)
		{
			_bodyState = PLAYER_LEFT_SIT;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftSit");
			_bodyMotion->start();
		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		if (_bodyState == PLAYER_RIGHT_SIT)
		{
			_bodyState = PLAYER_RIGHT_STOP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightStop");
			_bodyMotion->start();
		}
		else if (_bodyState == PLAYER_LEFT_SIT)
		{
			_bodyState = PLAYER_LEFT_STOP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftStop");
			_bodyMotion->start();
		}
	}

	if (KEYMANAGER->isOnceKeyDown('A'))		//	FRONT_WEAPON_ATTACK
	{
	}
	if (KEYMANAGER->isOnceKeyDown('S'))		//	JUMP
	{
		_playerJump->jumping(&_x, &_y, JUMPPOWER, GRAVITY);

		if (_bodyState == PLAYER_RIGHT_STOP)
		{
			_bodyState = PLAYER_RIGHT_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightJump");
			_bodyMotion->start();
		}

		if (_bodyState == PLAYER_LEFT_STOP)
		{
			_bodyState = PLAYER_LEFT_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftJump");
			_bodyMotion->start();
		}

		if (_bodyState == PLAYER_RIGHT_MOVE)
		{
			_bodyState = PLAYER_RIGHT_MOVE_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightJump");
			_bodyMotion->start();
		}

		if (_bodyState == PLAYER_LEFT_MOVE)
		{
			_bodyState = PLAYER_LEFT_MOVE_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftJump");
			_bodyMotion->start();
		}
	}
	if (KEYMANAGER->isOnceKeyDown('D'))		//	BACK_WEAPON_ATTACK
	{

	}
}

void Player::rightJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_STOP);
	p->setPlayerBodyMotion(KEYANIMANAGER->findAnimation(L"playerBodyRightStop"));
	p->getPlayerBodyMotion()->start();
}
void Player::leftJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_STOP);
	p->setPlayerBodyMotion(KEYANIMANAGER->findAnimation(L"playerBodyLeftStop"));
	p->getPlayerBodyMotion()->start();
}
void Player::rightMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_MOVE);
	p->setPlayerBodyMotion(KEYANIMANAGER->findAnimation(L"playerBodyRightMove"));
	p->getPlayerBodyMotion()->start();
}
void Player::leftMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_MOVE);
	p->setPlayerBodyMotion(KEYANIMANAGER->findAnimation(L"playerBodyLeftMove"));
	p->getPlayerBodyMotion()->start();
}