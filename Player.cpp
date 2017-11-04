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
	_playerPixelCollision = new pixelCollision;
	_playerPixelCollision->init();

	_headState = PLAYER_YOUNGEST;
	_bodyState = PLAYER_RIGHT_STOP;

	// 발 사이 맨 밑
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	_rcHead = RectMakeCenter(_x - 9, _y - 52, 20, 20);
	_rcBody = RectMake(_x - 10, _y - 33, BODY_WIDTH, BODY_HEIGHT);

	_headImage = IMAGEMANAGER->findImage(L"headRight0");

	_bodyRightImage = IMAGEMANAGER->findImage(L"unarmedBodyRight");
	_bodyLeftImage = IMAGEMANAGER->findImage(L"unarmedBodyLeft");

	_armRightFrontImage = IMAGEMANAGER->findImage(L"armRightFront");
	_armRightBackImage = IMAGEMANAGER->findImage(L"armRightBack");
	_armLeftFrontImage = IMAGEMANAGER->findImage(L"armLeftFront");
	_armLeftBackImage = IMAGEMANAGER->findImage(L"armLeftBack");

	_isFrontAttack = FALSE;
	_isBackAttack = FALSE;
	_isRight = TRUE;
	_isLive = TRUE;
	_isSit = FALSE;

	_weaponType = ITEM_TYPE_SWORD;

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


	//debug
	RECTMANAGER->addRect(DEVICE, L"플레이어바디", { 0, 0 }, { BODY_WIDTH, BODY_HEIGHT }, RGB(255, 0, 0));

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
			{
				_x += PLAYERSPEED;
				tagPixelCollision res = _playerPixelCollision->getPlayerPixelWall(_x + 5 + BODY_WIDTH / 2, _y, BODY_WIDTH, BODY_HEIGHT, 1);
				if (res.detect)
				{
					_x = res.offset.x /*- 5*/ - BODY_WIDTH / 2 - 10;
					_y = res.offset.y;
				}
				//imagePosUpdate();
				//_rcHead = RectMakeCenter(_x - 9, _y - 52, 20, 20);
				//_rcBody = RectMake(_x - 10, _y - 33, BODY_WIDTH, BODY_HEIGHT);
			}
		break;
		case PLAYER_LEFT_MOVE: case PLAYER_LEFT_MOVE_JUMP:
			{
				_x -= PLAYERSPEED;
				tagPixelCollision res = _playerPixelCollision->getPlayerPixelWall(_x + 5 + BODY_WIDTH / 2, _y, BODY_WIDTH, BODY_HEIGHT, -1);
				if (res.detect)
				{
					_x = res.offset.x /*- 5*/ - BODY_WIDTH / 2 - 1;
					_y = res.offset.y;
				}
				//imagePosUpdate();
				//_rcHead = RectMakeCenter(_x - 9, _y - 52, 20, 20);
				//_rcBody = RectMake(_x - 10, _y - 33, BODY_WIDTH, BODY_HEIGHT);
			}
		break;
		case PLAYER_RIGHT_SIT: case PLAYER_LEFT_SIT:
			//imagePosUpdate();
			//_rcHead = RectMakeCenter(_x - 9, _y - 52, 20, 20);
			//_rcBody = RectMake(_x - 10, _y - 33, BODY_WIDTH, BODY_HEIGHT);
		break;
	}


	_playerJump->update();

	//jhkim 픽셀충돌 수정 (점프중일때는 점프파워가 0보다 작을때만 체크하고, 점프가 아닐때에는 픽셀충돌을 못하면 점프되도록 한다.)
	if (_playerJump->getIsJumping())
	{
		if (_playerJump->getJumpPower() < 0)
		{
			tagPixelCollision res = _playerPixelCollision->getPlayerPixelGround(_x + 5 + BODY_WIDTH / 2, _y, BODY_WIDTH, BODY_HEIGHT);
			if (res.detect)
			{
				_playerJump->setIsJumping(false);
				_x = res.offset.x - 5 - BODY_WIDTH / 2;
				_y = res.offset.y;
			}
		}
	}
	else
	{
		tagPixelCollision res = _playerPixelCollision->getPlayerPixelGround(_x + 5 + BODY_WIDTH / 2, _y, BODY_WIDTH, BODY_HEIGHT);

		if (res.detect)
		{
			_x = res.offset.x - 5 - BODY_WIDTH / 2;
			_y = res.offset.y;
		}
		else
		{
			_playerJump->jumping(&_x, &_y, 0, GRAVITY);
		}
	}


	//jhkim 점프 수정
	if (_playerJump->getIsJumping() == false)
	{
		if (_bodyState == PLAYER_RIGHT_JUMP)
		{
			bodyRightJump(this);
			armFrontRightJump(this);
			armBackRightJump(this);
		}
		if (_bodyState == PLAYER_LEFT_JUMP)
		{
			bodyLeftJump(this);
			armFrontLeftJump(this);
			armBackLeftJump(this);
		}
		if (_bodyState == PLAYER_RIGHT_MOVE_JUMP)
		{
			bodyRightMoveJump(this);
			armFrontRightMoveJump(this);
			armBackRightMoveJump(this);
		}
		if (_bodyState == PLAYER_LEFT_MOVE_JUMP)
		{
			bodyLeftMoveJump(this);
			armFrontLeftMoveJump(this);
			armBackLeftMoveJump(this);
		}
	}

	imagePosUpdate();
	_rcHead = RectMakeCenter(_x - 9, _y - 52, 20, 20);
	_rcBody = RectMake(_x - 10, _y - 33, BODY_WIDTH, BODY_HEIGHT);

	KEYANIMANAGER->update();

	if (!_isLive)
	{
		DATABASE->setGameStart(_isLive);
	}
	
	//debug
	TCHAR str[100];
	switch (_bodyState)
	{
		case PLAYER_RIGHT_STOP:				_stprintf(str, L"PLAYER_RIGHT_STOP:		pos = %d, %d", (int)_x, (int)_y);	break;
		case PLAYER_LEFT_STOP:				_stprintf(str, L"PLAYER_LEFT_STOP:		pos = %d, %d", (int)_x, (int)_y);	break;
		case PLAYER_RIGHT_MOVE:				_stprintf(str, L"PLAYER_RIGHT_MOVE:		pos = %d, %d", (int)_x, (int)_y);	break;
		case PLAYER_LEFT_MOVE:				_stprintf(str, L"PLAYER_LEFT_MOVE:		pos = %d, %d", (int)_x, (int)_y);	break;
		case PLAYER_RIGHT_SIT:				_stprintf(str, L"PLAYER_RIGHT_SIT:		pos = %d, %d", (int)_x, (int)_y);	break;
		case PLAYER_LEFT_SIT:				_stprintf(str, L"PLAYER_LEFT_SIT:		pos = %d, %d", (int)_x, (int)_y);	break;
		case PLAYER_RIGHT_JUMP:				_stprintf(str, L"PLAYER_RIGHT_JUMP:		pos = %d, %d", (int)_x, (int)_y);	break;
		case PLAYER_LEFT_JUMP:				_stprintf(str, L"PLAYER_LEFT_JUMP:		pos = %d, %d", (int)_x, (int)_y);	break;
		case PLAYER_RIGHT_MOVE_JUMP:		_stprintf(str, L"PLAYER_RIGHT_MOVE_JUMP:pos = %d, %d", (int)_x, (int)_y);	break;
		case PLAYER_LEFT_MOVE_JUMP:			_stprintf(str, L"PLAYER_LEFT_MOVE_JUMP:	pos = %d, %d", (int)_x, (int)_y);	break;
		//case PLAYER_RIGHT_ATTACK:				_stprintf(str, L"PLAYER_RIGHT_ATTACK:			"); break;
		//case PLAYER_LEFT_ATTACK:				_stprintf(str, L"PLAYER_LEFT_ATTACK:			"); break;
		//case PLAYER_RIGHT_MOVE_ATTACK:			_stprintf(str, L"PLAYER_RIGHT_MOVE_ATTACK:		"); break;
		//case PLAYER_LEFT_MOVE_ATTACK:			_stprintf(str, L"PLAYER_LEFT_MOVE_ATTACK:		"); break;
		//case PLAYER_RIGHT_SIT_ATTACK:			_stprintf(str, L"PLAYER_RIGHT_SIT_ATTACK:		"); break;
		//case PLAYER_LEFT_SIT_ATTACK:			_stprintf(str, L"PLAYER_LEFT_SIT_ATTACK:		"); break;
		//case PLAYER_RIGHT_JUMP_ATTACK:			_stprintf(str, L"PLAYER_RIGHT_JUMP_ATTACK:		"); break;
		//case PLAYER_LEFT_JUMP_ATTACK:			_stprintf(str, L"PLAYER_LEFT_JUMP_ATTACK:		"); break;
		//case PLAYER_RIGHT_MOVE_JUMP_ATTACK:		_stprintf(str, L"PLAYER_RIGHT_MOVE_JUMP_ATTACK:	"); break;
		//case PLAYER_LEFT_MOVE_JUMP_ATTACK:		_stprintf(str, L"PLAYER_LEFT_MOVE_JUMP_ATTACK:	"); break;

		default: _stprintf(str, L""); break;

	}
	TEXTMANAGER->addText(L"플레이어상태", str);

	MAINCAMERA->setTargetPos(_x - WINSIZEX / 2, _y - WINSIZEY / 2);
	MAINCAMERA->update();

	if (KEYMANAGER->isOnceKeyDown('P')) _isLive = false;
}

void Player::render(void) 
{
	//	B A C K 팔
	if (_isFrontAttack == FALSE)
	{
		if (_isRight == TRUE)
		{
			_armRightBackImage->aniRender(_armBackMotion);
		}
		else
		{
			_armLeftBackImage->aniRender(_armBackMotion);
		}
	}
	else
	{
		if (_isRight == TRUE)
		{
			_armRightBackImage->aniRender(_backArmFrontAttackMotion);
		}
		else
		{
			_armLeftBackImage->aniRender(_armBackMotion);
		}
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

	//	머 리
	_headImage->render();

	RECT rcText = RectMake(0, 0, 100, 100);
	TEXTMANAGER->render(L"플레이어상태", rcText);


	//	F R O N T 팔
	if (_isFrontAttack == FALSE)
	{
		if (_isRight == TRUE)
		{
			_armRightFrontImage->aniRender(_armFrontMotion);
		}
		else
		{
			_armLeftFrontImage->aniRender(_armFrontMotion);
		}
	}
	else
	{
		if (_isRight == TRUE)
		{
			_armRightFrontImage->aniRender(_frontArmFrontAttackMotion);
		}
		else
		{
			_armLeftFrontImage->aniRender(_armFrontMotion);
		}
	}


	//debug
	RECTMANAGER->setCoord(L"플레이어바디", _x + 5, _y - BODY_HEIGHT / 2);
	RECTMANAGER->render(L"플레이어바디");
}

void Player::imageReverse(void)
{
	//	머리
	IMAGEMANAGER->findImage(L"headLeft0")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft1")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft2")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft3")->setScale({ -1,1 });

	IMAGEMANAGER->findImage(L"headLeft0")->setScaleOffset(50.0f, 0.0f);
	IMAGEMANAGER->findImage(L"headLeft1")->setScaleOffset(50.0f, 0.0f);
	IMAGEMANAGER->findImage(L"headLeft2")->setScaleOffset(50.0f, 0.0f);
	IMAGEMANAGER->findImage(L"headLeft3")->setScaleOffset(50.0f, 0.0f);

	//	몸
	IMAGEMANAGER->findImage(L"unarmedBodyLeft")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"unarmedBodyLeft")->setScaleOffset(50.0f, 0.0f);

	//	팔
	IMAGEMANAGER->findImage(L"armLeftFront")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"armLeftBack")->setScale({ -1,1 });

	IMAGEMANAGER->findImage(L"armLeftFront")->setScaleOffset(50.0f, 0.0f);
	IMAGEMANAGER->findImage(L"armLeftBack")->setScaleOffset(50.0f, 0.0f);
}

void Player::imagePosUpdate(void)
{
	if (_isRight == TRUE)
	{
		if (_isSit == TRUE)
		{
			_headImage->setCoord({ _x + 8, _y - 18 });
		}
		else
		{
			_headImage->setCoord({ _x + 3, _y - 32 });
		}
	}
	else
	{
		if (_isSit == TRUE)
		{
			_headImage->setCoord({ _x - 8, _y - 18 });
		}
		else
		{
			_headImage->setCoord({ _x - 3, _y - 32 });
		}
	}

	_bodyRightImage->setCoord({ _x, _y - 22 });
	_bodyLeftImage->setCoord({ _x, _y - 22 });

	if (_isSit == TRUE)
	{
		_armRightFrontImage->setCoord({ _x - 4, _y - 12 });
		_armRightBackImage->setCoord({ _x + 7, _y - 12 });
		_armLeftFrontImage->setCoord({ _x + 4, _y - 12 });
		_armLeftBackImage->setCoord({ _x - 7, _y - 12 });
	}
	else
	{
		_armRightFrontImage->setCoord({ _x - 4, _y - 20 });
		_armRightBackImage->setCoord({ _x + 7, _y - 20 });
		_armLeftFrontImage->setCoord({ _x + 4, _y - 20 });
		_armLeftBackImage->setCoord({ _x - 7, _y - 20 });
	}
}

void Player::keyAnimationInit(void)
{

	//	몸 - idle, jump0, jump1, sit, walk0 ~ walk11 순
	//	I D L E
	int bodyRightIdle[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyRightStop", L"unarmedBodyRight", bodyRightIdle, 1, 10, true);
	int bodyLeftIdle[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyLeftStop", L"unarmedBodyLeft", bodyLeftIdle, 1, 10, true);

	//	W A L K
	int bodyRightMove[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyRightMove", L"unarmedBodyRight", bodyRightMove, 12, 20, true);
	int bodyLeftMove[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyLeftMove", L"unarmedBodyLeft", bodyLeftMove, 12, 20, true);

	//	S I T
	int bodyRightSit[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyRightSit", L"unarmedBodyRight", bodyRightSit, 1, 10, true);
	int bodyLeftSit[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyLeftSit", L"unarmedBodyLeft", bodyLeftSit, 1, 10, true);

	//	J U M P
	int bodyRightJump[] = { 1,2 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyRightJump", L"unarmedBodyRight", bodyRightJump, 2, 2, true);
	int bodyLeftJump[] = { 1,2 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyLeftJump", L"unarmedBodyLeft", bodyLeftJump, 2, 2, true);
	int bodyRightMoveJump[] = { 1,2 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyRightMoveJump", L"unarmedBodyRight", bodyRightMoveJump, 2, 2, false);
	int bodyLeftMoveJump[] = { 1,2 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBodyLeftMoveJump", L"unarmedBodyLeft", bodyLeftMoveJump, 2, 2, false);

	//	팔 - 16개방향 * 3가지 모션
	//	F R O N T
	//		I D L E
	int armFrontRightIdle[] = { 11,10 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightStop", L"armRightFront", armFrontRightIdle, 2, 2, true);
	int armFrontLeftIdle[] = { 11,10 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftStop", L"armLeftFront", armFrontLeftIdle, 2, 2, true);

	//		W A L K
	int armFrontRightMove[] = { 43,42,41,40,41,42,43,44 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightMove", L"armRightFront", armFrontRightMove, 8, 20, true);
	int armFrontLeftMove[] = { 43,42,41,40,41,42,43,44 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftMove", L"armLeftFront", armFrontLeftMove, 8, 20, true);

	//		J U M P
	int armFrontRightJump[] = { 12,11,10,9,8,7,7,7,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightJump", L"armRightFront", armFrontRightJump, 13, 10, true);
	int armFrontLeftJump[] = { 12,11,10,9,8,7,7,7,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftJump", L"armLeftFront", armFrontLeftJump, 13, 10, true);

	//		S I T
	int armFrontRightSit[] = { 9 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightSit", L"armRightFront", armFrontRightSit, 1, 10, true);
	int armFrontLeftSit[] = { 9 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftSit", L"armLeftFront", armFrontLeftSit, 1, 10, true);

	//		FRONT ATTACK - UNARMED
	int armFrontRightUnarmedFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightUnarmedFrontAttack", L"armRightFront", armFrontRightUnarmedFrontAttack, 1, 10, true);
	int armFrontLeftUnarmedFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftUnarmedFrontAttack", L"armLeftFront", armFrontLeftUnarmedFrontAttack, 1, 10, true);
	//		FRONT ATTACK - SWORD
	int armFrontRightSwordFrontAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13};
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightSwordFrontAttack", L"armRightFront", armFrontRightSwordFrontAttack, 16, 30, false, attackIsEnd, this);
	int armFrontLeftSwordFrontAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftSwordFrontAttack", L"armLeftFront", armFrontLeftSwordFrontAttack, 16, 30, false, attackIsEnd, this);
	//		FRONT ATTACK - LANCE
	int armFrontRightLanceFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightLanceFrontAttack", L"armRightFront", armFrontRightLanceFrontAttack, 1, 10, true);
	int armFrontLeftLanceFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftLanceFrontAttack", L"armLeftFront", armFrontLeftLanceFrontAttack, 1, 10, true);
	//		FRONT ATTACK - BOOMERANG
	int armFrontRightBoomerangFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightBoomerangFrontAttack", L"armRightFront", armFrontRightBoomerangFrontAttack, 1, 10, true);
	int armFrontLeftBoomerangFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightBoomerangFrontAttack", L"armLeftFront", armFrontLeftBoomerangFrontAttack, 1, 10, true);
	//		FRONT ATTACK - STAFF
	int armFrontRightStaffFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightStaffFrontAttack", L"armRightFront", armFrontRightStaffFrontAttack, 1, 10, true);
	int armFrontLeftStaffFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightStaffFrontAttack", L"armLeftFront", armFrontLeftStaffFrontAttack, 1, 10, true);

	//		BACK ATTACK - UNARMED
	int armFrontRightUnarmedBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightUnarmedBackAttack", L"armRightFront", armFrontRightUnarmedBackAttack, 1, 10, true);
	int armFrontLeftUnarmedBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftUnarmedBackAttack", L"armLeftFront", armFrontLeftUnarmedBackAttack, 1, 10, true);
	//		BACK ATTACK - SWORD
	int armFrontRightSwordBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightSwordBackAttack", L"armRightFront", armFrontRightSwordBackAttack, 1, 10, true);
	int armFrontLeftSwordBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftSwordBackAttack", L"armLeftFront", armFrontLeftSwordBackAttack, 1, 10, true);
	//		BACK ATTACK - LANCE
	int armFrontRightLanceBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightLanceBackAttack", L"armRightFront", armFrontRightLanceBackAttack, 1, 10, true);
	int armFrontLeftLanceBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontLeftLanceBackAttack", L"armLeftFront", armFrontLeftLanceBackAttack, 1, 10, true);
	//		BACK ATTACK - BOOMERANG
	int armFrontRightBoomerangBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightBoomerangBackAttack", L"armRightFront", armFrontRightBoomerangBackAttack, 1, 10, true);
	int armFrontLeftBoomerangBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightBoomerangBackAttack", L"armLeftFront", armFrontLeftBoomerangBackAttack, 1, 10, true);
	//		BACK ATTACK - STAFF
	int armFrontRightStaffBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightStaffBackAttack", L"armRightFront", armFrontRightStaffBackAttack, 1, 10, true);
	int armFrontLeftStaffBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmFrontRightStaffBackAttack", L"armLeftFront", armFrontLeftStaffBackAttack, 1, 10, true);

	//	B A C K
	//		I D L E
	int armBackRightIdle[] = { 11,12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightStop", L"armRightBack", armBackRightIdle, 2, 2, true);
	int armBackLeftIdle[] = { 11,12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftStop", L"armLeftBack", armBackLeftIdle, 2, 2, true);

	//		W A L K
	int armBackRightMove[] = { 42,43,44,43,42,41,40,41 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightMove", L"armRightBack", armBackRightMove, 8, 20, true);
	int armBackLeftMove[] = { 42,43,44,43,42,41,40,41 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftMove", L"armLeftBack", armBackLeftMove, 8, 20, true);

	//		J U M P
	int armBackRightJump[] = { 11,10,11,12,13,14,14,14,14,14,14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightJump", L"armRightBack", armBackRightJump, 13, 10, true);
	int armBackLeftJump[] = { 11,10,11,12,13,14,14,14,14,14,14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftJump", L"armLeftBack", armBackLeftJump, 13, 10, true);

	//		S I T
	int armBackRightSit[] = { 42 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightSit", L"armRightBack", armBackRightSit, 1, 10, true);
	int armBackLeftSit[] = { 42 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftSit", L"armLeftFront", armBackLeftSit, 1, 10, true);

	//		FRONT ATTACK - UNARMED
	int armBackRightUnarmedFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightUnarmedFrontAttack", L"armRightBack", armBackRightUnarmedFrontAttack, 1, 10, true);
	int armBackLeftUnarmedFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftUnarmedFrontAttack", L"armLeftBack", armBackLeftUnarmedFrontAttack, 1, 10, true);
	//		FRONT ATTACK - SWORD
	int armBackRightSwordFrontAttack[] = { 12,28,44,43,42,41,40,39,38,22,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightSwordFrontAttack", L"armRightBack", armBackRightSwordFrontAttack, 16, 20, false);
	int armBackLeftSwordFrontAttack[] = { 12,13,14,15,14,13,12,28,44,43,42,41,25,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftSwordFrontAttack", L"armLeftBack", armBackLeftSwordFrontAttack, 16, 20, false);
	//		FRONT ATTACK - LANCE
	int armBackRightLanceFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightLanceFrontAttack", L"armRightBack", armBackRightLanceFrontAttack, 1, 10, true);
	int armBackLeftLanceFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftLanceFrontAttack", L"armLeftBack", armBackLeftLanceFrontAttack, 1, 10, true);
	//		FRONT ATTACK - BOOMERANG
	int armBackRightBoomerangFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightBoomerangFrontAttack", L"armRightBack", armBackRightBoomerangFrontAttack, 1, 10, true);
	int armBackLeftBoomerangFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightBoomerangFrontAttack", L"armLeftBack", armBackLeftBoomerangFrontAttack, 1, 10, true);
	//		FRONT ATTACK - STAFF
	int armBackRightStaffFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightStaffFrontAttack", L"armRightBack", armBackRightStaffFrontAttack, 1, 10, true);
	int armBackLeftStaffFrontAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightStaffFrontAttack", L"armLeftBack", armBackLeftStaffFrontAttack, 1, 10, true);

	//		BACK ATTACK - UNARMED
	int armBackRightUnarmedBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightUnarmedBackAttack", L"armRightBack", armBackRightUnarmedBackAttack, 1, 10, true);
	int armBackLeftUnarmedBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftUnarmedBackAttack", L"armLeftBack", armBackLeftUnarmedBackAttack, 1, 10, true);
	//		BACK ATTACK - SWORD
	int armBackRightSwordBackAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightSwordBackAttack", L"armRightBack", armBackRightSwordBackAttack, 16, 30, false, attackIsEnd, this);
	int armBackLeftSwordBackAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftSwordBackAttack", L"armLeftBack", armBackLeftSwordBackAttack, 16, 30, false, attackIsEnd, this);
	//		BACK ATTACK - LANCE
	int armBackRightLanceBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightLanceBackAttack", L"armRightBack", armBackRightLanceBackAttack, 1, 10, true);
	int armBackLeftLanceBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackLeftLanceBackAttack", L"armLeftBack", armBackLeftLanceBackAttack, 1, 10, true);
	//		BACK ATTACK - BOOMERANG
	int armBackRightBoomerangBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightBoomerangBackAttack", L"armRightBack", armBackRightBoomerangBackAttack, 1, 10, true);
	int armBackLeftBoomerangBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightBoomerangBackAttack", L"armLeftBack", armBackLeftBoomerangBackAttack, 1, 10, true);
	//		BACK ATTACK - STAFF
	int armBackRightStaffBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightStaffBackAttack", L"armRightBack", armBackRightStaffBackAttack, 1, 10, true);
	int armBackLeftStaffBackAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerArmBackRightStaffBackAttack", L"armLeftBack", armBackLeftStaffBackAttack, 1, 10, true);
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
		_bodyState = PLAYER_LEFT_STOP;
		_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftStop");
		_bodyMotion->start();

		_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontLeftStop");
		_armFrontMotion->start();

		_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackLeftStop");
		_armBackMotion->start();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))		//	Sit 키, 충돌 렉트 변화 필요
	{
		_isSit = TRUE;

		if (_bodyState == PLAYER_RIGHT_STOP || _bodyState == PLAYER_RIGHT_MOVE)
		{
			_bodyState = PLAYER_RIGHT_SIT;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightSit");
			_bodyMotion->start();

			_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightSit");
			_armFrontMotion->start();

			_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightSit");
			_armBackMotion->start();
		}
		else if (_bodyState == PLAYER_LEFT_STOP || _bodyState == PLAYER_LEFT_MOVE)
		{
			_bodyState = PLAYER_LEFT_SIT;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftSit");
			_bodyMotion->start();

			_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontLeftSit");
			_armFrontMotion->start();

			_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackLeftSit");
			_armBackMotion->start();
		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_isSit = FALSE;

		if (_bodyState == PLAYER_RIGHT_SIT)
		{
			_bodyState = PLAYER_RIGHT_STOP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightStop");
			_bodyMotion->start();

			_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightStop");
			_armFrontMotion->start();

			_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightStop");
			_armBackMotion->start();
		}
		else if (_bodyState == PLAYER_LEFT_SIT)
		{
			_bodyState = PLAYER_LEFT_STOP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftStop");
			_bodyMotion->start();

			_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontLeftStop");
			_armFrontMotion->start();

			_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackLeftStop");
			_armBackMotion->start();
		}
	}

	if (KEYMANAGER->isOnceKeyDown('A'))		//	FRONT_WEAPON_ATTACK
	{
		//	공격용 충돌 렉트 생성

		_isFrontAttack = TRUE;

		_frontArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightSwordFrontAttack");
		_backArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightSwordFrontAttack");

		_frontArmFrontAttackMotion->start();
		_backArmFrontAttackMotion->start();

		//switch (_weaponType)
		//{
		//	case ITEM_TYPE_SWORD:
		//		_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightSwordFrontAttack");
		//		_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightSwordFrontAttack");
		//	break;
		//	case ITEM_TYPE_LANCE:
		//		_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightLanceFrontAttack");
		//		_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightLanceFrontAttack");
		//	break;
		//	case ITEM_TYPE_BOOMERANG:
		//		_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightBoomerangFrontAttack");
		//		_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightBoomerangFrontAttack");
		//	break;
		//	case ITEM_TYPE_STAFF:
		//		_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightStaffFrontAttack");
		//		_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightStaffFrontAttack");
		//	break;			
		//}
		//
		//_armFrontMotion->start();
		//_armBackMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown('S'))		//	JUMP
	{
		_playerJump->jumping(&_x, &_y, JUMPPOWER, GRAVITY);

		if (_bodyState == PLAYER_RIGHT_STOP)
		{
			_bodyState = PLAYER_RIGHT_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightJump");
			_bodyMotion->start();

			_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightJump");
			_armFrontMotion->start();

			_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightJump");
			_armBackMotion->start();
		}
		else if (_bodyState == PLAYER_LEFT_STOP)
		{
			_bodyState = PLAYER_LEFT_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftJump");
			_bodyMotion->start();

			_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontLeftJump");
			_armFrontMotion->start();

			_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackLeftJump");
			_armBackMotion->start();
		}

		if (_bodyState == PLAYER_RIGHT_MOVE)
		{
			_bodyState = PLAYER_RIGHT_MOVE_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightJump");
			_bodyMotion->start();

			_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightJump");
			_armFrontMotion->start();

			_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightJump");
			_armBackMotion->start();
		}
		else if (_bodyState == PLAYER_LEFT_MOVE)
		{
			_bodyState = PLAYER_LEFT_MOVE_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftJump");
			_bodyMotion->start();

			_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontLeftJump");
			_armFrontMotion->start();

			_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackLeftJump");
			_armBackMotion->start();
		}
	}
	if (KEYMANAGER->isOnceKeyDown('D'))		//	BACK_WEAPON_ATTACK
	{
		//	공격용 충돌 렉트 생성

		_isBackAttack = TRUE;

		switch (_weaponType)
		{
			case ITEM_TYPE_SWORD:
				_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightSwordBackAttack");
				_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightSwordBackAttack");
			break;
			case ITEM_TYPE_LANCE:
				_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightLanceBackAttack");
				_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightLanceBackAttack");
			break;
			case ITEM_TYPE_BOOMERANG:
				_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightBoomerangBackAttack");
				_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightBoomerangBackAttack");
			break;
			case ITEM_TYPE_STAFF:
				_armFrontMotion = KEYANIMANAGER->findAnimation(L"playerArmFrontRightStaffBackAttack");
				_armBackMotion = KEYANIMANAGER->findAnimation(L"playerArmBackRightStaffBackAttack");
			break;
		}

		_armFrontMotion->start();
		_armBackMotion->start();
	}
}

void Player::attackMotions(void)
{

}

void Player::bodyRightJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_STOP);
	p->setPlayerBodyMotion(KEYANIMANAGER->findAnimation(L"playerBodyRightStop"));
	p->getPlayerBodyMotion()->start();
}
void Player::bodyLeftJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_STOP);
	p->setPlayerBodyMotion(KEYANIMANAGER->findAnimation(L"playerBodyLeftStop"));
	p->getPlayerBodyMotion()->start();
}
void Player::bodyRightMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_MOVE);
	p->setPlayerBodyMotion(KEYANIMANAGER->findAnimation(L"playerBodyRightMove"));
	p->getPlayerBodyMotion()->start();
}
void Player::bodyLeftMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_MOVE);
	p->setPlayerBodyMotion(KEYANIMANAGER->findAnimation(L"playerBodyLeftMove"));
	p->getPlayerBodyMotion()->start();
}

void Player::armFrontRightJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_STOP);
	p->setPlayerArmFrontMotion(KEYANIMANAGER->findAnimation(L"playerArmFrontRightStop"));
	p->getPlayerArmFrontMotion()->start();
}
void Player::armFrontLeftJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_STOP);
	p->setPlayerArmFrontMotion(KEYANIMANAGER->findAnimation(L"playerArmFrontLeftStop"));
	p->getPlayerArmFrontMotion()->start();
}
void Player::armFrontRightMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_MOVE);
	p->setPlayerArmFrontMotion(KEYANIMANAGER->findAnimation(L"playerArmFrontRightMove"));
	p->getPlayerArmFrontMotion()->start();
}
void Player::armFrontLeftMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_MOVE);
	p->setPlayerArmFrontMotion(KEYANIMANAGER->findAnimation(L"playerArmFrontLeftMove"));
	p->getPlayerArmFrontMotion()->start();
}

void Player::armBackRightJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_STOP);
	p->setPlayerArmBackMotion(KEYANIMANAGER->findAnimation(L"playerArmBackRightStop"));
	p->getPlayerArmBackMotion()->start();
}
void Player::armBackLeftJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_STOP);
	p->setPlayerArmBackMotion(KEYANIMANAGER->findAnimation(L"playerArmBackLeftStop"));
	p->getPlayerArmBackMotion()->start();
}
void Player::armBackRightMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_MOVE);
	p->setPlayerArmBackMotion(KEYANIMANAGER->findAnimation(L"playerArmBackRightMove"));
	p->getPlayerArmBackMotion()->start();
}
void Player::armBackLeftMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_MOVE);
	p->setPlayerArmBackMotion(KEYANIMANAGER->findAnimation(L"playerArmBackLeftMove"));
	p->getPlayerArmBackMotion()->start();
}

void Player::attackIsEnd(void* obj)
{
	Player* p = (Player*)obj;

	p->setIsFrontAttack(FALSE);
	p->setIsBackAttack(FALSE);
}