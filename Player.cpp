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

	// 발 사이 맨 밑
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	//========== 렉트 초기화 ==========
	rectUpdate();

	_headImage = IMAGEMANAGER->findImage(L"headRight0");

	_bodyRightImage = IMAGEMANAGER->findImage(L"unarmedBodyRight");
	_bodyLeftImage = IMAGEMANAGER->findImage(L"unarmedBodyLeft");

	_frontArmRightImage = IMAGEMANAGER->findImage(L"frontArmRight");
	_backArmRightImage = IMAGEMANAGER->findImage(L"backArmRight");
	_frontArmLeftImage = IMAGEMANAGER->findImage(L"frontArmLeft");
	_backArmLeftImage = IMAGEMANAGER->findImage(L"backArmLeft");

	_isFrontAttack = FALSE;
	_isBackAttack = FALSE;
	_isRight = TRUE;
	_isLive = TRUE;
	_isSit = FALSE;


	//========== 이미지 왼쪽 보게 바꾸기 ==========

	imageReverse();

	//========== 부위별 키 애니메이션 초기화 ==========

	keyAnimationInit();

	//========== 각 부위 위치 업데이트 ==========

	imagePosUpdate();

	//========== 최초 모션 세팅 ==========

	_headState = PLAYER_YOUNGEST;
	_bodyState = PLAYER_RIGHT_STOP;
	_weaponType = ITEM_TYPE_SWORD;

	_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightStop");
	_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightStop");
	_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightStop");

	_frontArmMotion->start();
	_backArmMotion->start();

	TEXTMANAGER->init(DEVICE, L"플레이어상태");
	TEXTMANAGER->init(DEVICE, L"앞공격");
	TEXTMANAGER->init(DEVICE, L"뒷공격");


	//debug
	RECTMANAGER->addRect(DEVICE, L"플레이어헤드",		{ 0, 0 }, { HEAD_WIDTH, HEAD_HEIGHT }, RGB(255, 0, 0));
	RECTMANAGER->addRect(DEVICE, L"플레이어바디",		{ 0, 0 }, { BODY_WIDTH, BODY_HEIGHT }, RGB(0, 255, 0));
	RECTMANAGER->addRect(DEVICE, L"플레이어발",		{ 0, 0 }, { FOOT_WIDTH, FOOT_HEIGHT }, RGB(0, 0, 255));

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
			frontArmRightJump(this);
			backArmRightJump(this);
		}
		if (_bodyState == PLAYER_LEFT_JUMP)
		{
			bodyLeftJump(this);
			frontArmLeftJump(this);
			backArmLeftJump(this);
		}
		if (_bodyState == PLAYER_RIGHT_MOVE_JUMP)
		{
			bodyRightMoveJump(this);
			frontArmRightMoveJump(this);
			backArmRightMoveJump(this);
		}
		if (_bodyState == PLAYER_LEFT_MOVE_JUMP)
		{
			bodyLeftMoveJump(this);
			frontArmLeftMoveJump(this);
			backArmLeftMoveJump(this);
		}
	}

	imagePosUpdate();	//	
	rectUpdate();		//	렉트 업데이트

	KEYANIMANAGER->update();

	if (!_isLive)
	{
		DATABASE->setGameStart(_isLive);
	}

	if (!_isFrontAttack && !_isBackAttack)
	{
		if (_isRight)
		{
			_frontArmRightImage->aniRender(_frontArmMotion);
			_backArmRightImage->aniRender(_backArmMotion);
		}
		else
		{
			_frontArmLeftImage->aniRender(_frontArmMotion);
			_backArmLeftImage->aniRender(_backArmMotion);
		}
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


	TCHAR strfa[100];
	TCHAR strba[100];
	(_isFrontAttack) ? _stprintf(strfa, L"FRONT: TRUE") : _stprintf(strfa, L"FRONT: FALSE");
	(_isBackAttack) ? _stprintf(strba, L"BACK: TRUE") : _stprintf(strba, L"BACK: FALSE");
	TEXTMANAGER->addText(L"앞공격", strfa);
	TEXTMANAGER->addText(L"뒷공격", strba);

	MAINCAMERA->setTargetPos(_x - WINSIZEX / 2, _y - WINSIZEY / 2);
	MAINCAMERA->update();

	if (KEYMANAGER->isOnceKeyDown('P')) _isLive = false;
}

void Player::render(void) 
{
	//	B A C K 팔
	if (_isFrontAttack == TRUE)
	{
		if (_isRight == TRUE)
		{
			_backArmRightImage->aniRender(_backArmFrontAttackMotion);
		}
		else
		{
			_backArmLeftImage->aniRender(_backArmFrontAttackMotion);
		}
	}
	else if (_isBackAttack == TRUE)
	{
		if (_isRight == TRUE)
		{
			_backArmRightImage->aniRender(_backArmBackAttackMotion);
		}
		else
		{
			_backArmLeftImage->aniRender(_backArmBackAttackMotion);
		}
	}
	else
	{
		if (_isRight == TRUE)
		{
			_backArmRightImage->aniRender(_backArmMotion);
		}
		else
		{
			_backArmLeftImage->aniRender(_backArmMotion);
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
	RECT rcFAText = RectMake(0, 100, 100, 100);
	TEXTMANAGER->render(L"앞공격", rcFAText);
	RECT rcBAText = RectMake(0, 200, 100, 100);
	TEXTMANAGER->render(L"뒷공격", rcBAText);
	
	//	F R O N T 팔
	if (_isFrontAttack == TRUE)
	{
		if (_isRight == TRUE)
		{
			_frontArmRightImage->aniRender(_frontArmFrontAttackMotion);
		}
		else
		{
			_frontArmLeftImage->aniRender(_frontArmFrontAttackMotion);
		}
	}
	else if (_isBackAttack == TRUE)
	{
		if (_isRight == TRUE)
		{
			_frontArmRightImage->aniRender(_frontArmBackAttackMotion);
		}
		else
		{
			_frontArmLeftImage->aniRender(_frontArmBackAttackMotion);
		}
	}
	else
	{
		if (_isRight == TRUE)
		{
			_frontArmRightImage->aniRender(_frontArmMotion);
		}
		else
		{
			_frontArmLeftImage->aniRender(_frontArmMotion);
		}
	}


	//debug
	RECTMANAGER->setCoord(L"플레이어헤드", _rcHead.left, _rcHead.top);
	RECTMANAGER->setCoord(L"플레이어바디", _rcBody.left, _rcBody.top);
	RECTMANAGER->setCoord(L"플레이어발",	  _rcFoot.left, _rcFoot.top);
	
	RECTMANAGER->render(L"플레이어헤드");
	RECTMANAGER->render(L"플레이어바디");
	RECTMANAGER->render(L"플레이어발");
}

void Player::imageReverse(void)
{
	float offsetVal = 41.0f;
	//	머리
	IMAGEMANAGER->findImage(L"headLeft0")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft1")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft2")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft3")->setScale({ -1,1 });

	IMAGEMANAGER->findImage(L"headLeft0")->setScaleOffset(offsetVal, 0.0f);
	IMAGEMANAGER->findImage(L"headLeft1")->setScaleOffset(offsetVal, 0.0f);
	IMAGEMANAGER->findImage(L"headLeft2")->setScaleOffset(offsetVal, 0.0f);
	IMAGEMANAGER->findImage(L"headLeft3")->setScaleOffset(offsetVal, 0.0f);

	//	몸
	IMAGEMANAGER->findImage(L"unarmedBodyLeft")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"unarmedBodyLeft")->setScaleOffset(offsetVal, 0.0f);

	//	팔
	IMAGEMANAGER->findImage(L"frontArmLeft")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"backArmLeft")->setScale({ -1,1 });

	IMAGEMANAGER->findImage(L"frontArmLeft")->setScaleOffset(offsetVal, 0.0f);
	IMAGEMANAGER->findImage(L"backArmLeft")->setScaleOffset(offsetVal, 0.0f);
}

void Player::imagePosUpdate(void)
{
	int correction = -5;
	if (_isRight == TRUE)
	{
		if (_isSit == TRUE)
		{
			_headImage->setCoord({ _x + 5 + correction, _y - 18 });
		}
		else
		{
			_headImage->setCoord({ _x + correction, _y - 32 });
		}
	}
	else
	{
		if (_isSit == TRUE)
		{
			_headImage->setCoord({ _x + 5 + correction, _y - 18 });
		}
		else
		{
			_headImage->setCoord({ _x + correction, _y - 32 });
		}
	}

	_bodyRightImage->setCoord({ _x + correction, _y - 22 });
	_bodyLeftImage->setCoord({ _x + correction, _y - 22 });

	if (_isSit == TRUE)
	{
		_frontArmRightImage->setCoord({ _x - 7 + correction, _y - 11 });
		_frontArmLeftImage->setCoord({ _x + 7 + correction, _y - 11 });
		_backArmRightImage->setCoord({ _x + 7 + correction, _y - 11 });
		_backArmLeftImage->setCoord({ _x - 7 + correction, _y - 11 });
	}
	else
	{
		_frontArmRightImage->setCoord({ _x - 7 + correction, _y - 20 });
		_frontArmLeftImage->setCoord({ _x + 7 + correction, _y - 20 });
		_backArmRightImage->setCoord({ _x + 7 + correction, _y - 20 });
		_backArmLeftImage->setCoord({ _x - 7 + correction, _y - 20 });
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
	int frontArmRightIdle[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightStop", L"frontArmRight", frontArmRightIdle, 1, 10, true);
	int frontArmLeftIdle[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmLeftStop", L"frontArmLeft", frontArmLeftIdle, 1, 10, true);

	//		W A L K
	int frontArmRightMove[] = { 43,42,41,40,41,42,43,44 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightMove", L"frontArmRight", frontArmRightMove, 8, 20, true);
	int frontArmLeftMove[] = { 43,42,41,40,41,42,43,44 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmLeftMove", L"frontArmLeft", frontArmLeftMove, 8, 20, true);

	//		J U M P
	int frontArmRightJump[] = { 12,11,10,9,8,7,7,7,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightJump", L"frontArmRight", frontArmRightJump, 13, 10, true);
	int frontArmLeftJump[] = { 12,11,10,9,8,7,7,7,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmLeftJump", L"frontArmLeft", frontArmLeftJump, 13, 10, true);

	//		S I T
	int frontArmRightSit[] = { 9 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightSit", L"frontArmRight", frontArmRightSit, 1, 10, true);
	int frontArmLeftSit[] = { 9 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmLeftSit", L"frontArmLeft", frontArmLeftSit, 1, 10, true);

	//		FRONT ATTACK - UNARMED
	int frontArmRightUnarmedFrontAttack[] = { 29,28,42,41 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightUnarmedFrontAttack", L"frontArmRight", frontArmRightUnarmedFrontAttack, 4,20, false, attackIsEnd, this);
	int frontArmLeftUnarmedFrontAttack[] = { 29,28,42,41 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmLeftUnarmedFrontAttack", L"frontArmLeft", frontArmLeftUnarmedFrontAttack, 4,20, false, attackIsEnd, this);
	//		FRONT ATTACK - SWORD
	int frontArmRightSwordFrontAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightSwordFrontAttack", L"frontArmRight", frontArmRightSwordFrontAttack, 16, 40, false, attackIsEnd, this);
	int frontArmLeftSwordFrontAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmLeftSwordFrontAttack", L"frontArmLeft", frontArmLeftSwordFrontAttack, 16, 40, false, attackIsEnd, this);
	//		FRONT ATTACK - LANCE
	int frontArmRightLanceFrontAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightLanceFrontAttack", L"frontArmRight", frontArmRightLanceFrontAttack, 16, 40, false, attackIsEnd, this);
	int frontArmLeftLanceFrontAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmLeftLanceFrontAttack", L"frontArmLeft", frontArmLeftLanceFrontAttack, 16, 40, false, attackIsEnd, this);
	//		FRONT ATTACK - BOOMERANG
	int frontArmRightBoomerangFrontAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightBoomerangFrontAttack", L"frontArmRight", frontArmRightBoomerangFrontAttack, 16, 40, false, attackIsEnd, this);
	int frontArmLeftBoomerangFrontAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightBoomerangFrontAttack", L"frontArmLeft", frontArmLeftBoomerangFrontAttack, 16, 40, false, attackIsEnd, this);
	//		FRONT ATTACK - STAFF
	int frontArmRightStaffFrontAttack[] = { 29,28,42,41,42,43,44,45,31,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightStaffFrontAttack", L"frontArmRight", frontArmRightStaffFrontAttack, 16, 40, false, attackIsEnd, this);
	int frontArmLeftStaffFrontAttack[] = { 29,28,42,41,42,43,44,45,31,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightStaffFrontAttack", L"frontArmLeft", frontArmLeftStaffFrontAttack, 16, 40, false, attackIsEnd, this);

	//		BACK ATTACK - UNARMED
	int frontArmRightUnarmedBackAttack[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightUnarmedBackAttack", L"frontArmRight", frontArmRightUnarmedBackAttack, 1, 10, false, attackIsEnd, this);
	int frontArmLeftUnarmedBackAttack[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmLeftUnarmedBackAttack", L"frontArmLeft", frontArmLeftUnarmedBackAttack, 1, 10, false, attackIsEnd, this);
	//		BACK ATTACK - SWORD
	int frontArmRightSwordBackAttack[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightSwordBackAttack", L"frontArmRight", frontArmRightSwordBackAttack, 1, 10, false, attackIsEnd, this);
	int frontArmLeftSwordBackAttack[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmLeftSwordBackAttack", L"frontArmLeft", frontArmLeftSwordBackAttack, 1, 10, false, attackIsEnd, this);
	//		BACK ATTACK - LANCE
	int frontArmRightLanceBackAttack[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightLanceBackAttack", L"frontArmRight", frontArmRightLanceBackAttack, 1, 10, false, attackIsEnd, this);
	int frontArmLeftLanceBackAttack[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmLeftLanceBackAttack", L"frontArmLeft", frontArmLeftLanceBackAttack, 1, 10, false, attackIsEnd, this);
	//		BACK ATTACK - BOOMERANG
	int frontArmRightBoomerangBackAttack[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightBoomerangBackAttack", L"frontArmRight", frontArmRightBoomerangBackAttack, 1, 10, false, attackIsEnd, this);
	int frontArmLeftBoomerangBackAttack[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightBoomerangBackAttack", L"frontArmLeft", frontArmLeftBoomerangBackAttack, 1, 10, false, attackIsEnd, this);
	//		BACK ATTACK - STAFF
	int frontArmRightStaffBackAttack[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightStaffBackAttack", L"frontArmRight", frontArmRightStaffBackAttack, 1, 10, false, attackIsEnd, this);
	int frontArmLeftStaffBackAttack[] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerFrontArmRightStaffBackAttack", L"frontArmLeft", frontArmLeftStaffBackAttack, 1, 10, false, attackIsEnd, this);

	//	B A C K
	//		I D L E
	int backArmRightIdle[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightStop", L"backArmRight", backArmRightIdle, 1, 10, true);
	int backArmLeftIdle[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmLeftStop", L"backArmLeft", backArmLeftIdle, 1, 10, true);

	//		W A L K
	int backArmRightMove[] = { 42,43,44,43,42,41,40,41 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightMove", L"backArmRight", backArmRightMove, 8, 20, true);
	int backArmLeftMove[] = { 42,43,44,43,42,41,40,41 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmLeftMove", L"backArmLeft", backArmLeftMove, 8, 20, true);

	//		J U M P
	int backArmRightJump[] = { 11,10,11,12,13,14,14,14,14,14,14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightJump", L"backArmRight", backArmRightJump, 13, 10, true);
	int backArmLeftJump[] = { 11,10,11,12,13,14,14,14,14,14,14,13,12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmLeftJump", L"backArmLeft", backArmLeftJump, 13, 10, true);

	//		S I T
	int backArmRightSit[] = { 42 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightSit", L"backArmRight", backArmRightSit, 1, 10, true);
	int backArmLeftSit[] = { 42 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmLeftSit", L"backArmLeft", backArmLeftSit, 1, 10, true);

	//		FRONT ATTACK - UNARMED
	int backArmRightUnarmedFrontAttack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightUnarmedFrontAttack", L"backArmRight", backArmRightUnarmedFrontAttack, 1, 10, false, attackIsEnd, this);
	int backArmLeftUnarmedFrontAttack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmLeftUnarmedFrontAttack", L"backArmLeft", backArmLeftUnarmedFrontAttack, 1, 10, false, attackIsEnd, this);
	//		FRONT ATTACK - SWORD
	int backArmRightSwordFrontAttack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightSwordFrontAttack", L"backArmRight", backArmRightSwordFrontAttack, 1, 10, false, attackIsEnd, this);
	int backArmLeftSwordFrontAttack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmLeftSwordFrontAttack", L"backArmLeft", backArmLeftSwordFrontAttack, 1, 10, false, attackIsEnd, this);
	//		FRONT ATTACK - LANCE
	int backArmRightLanceFrontAttack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightLanceFrontAttack", L"backArmRight", backArmRightLanceFrontAttack, 1, 10, false, attackIsEnd, this);
	int backArmLeftLanceFrontAttack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmLeftLanceFrontAttack", L"backArmLeft", backArmLeftLanceFrontAttack, 1, 10, false, attackIsEnd, this);
	//		FRONT ATTACK - BOOMERANG
	int backArmRightBoomerangFrontAttack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightBoomerangFrontAttack", L"backArmRight", backArmRightBoomerangFrontAttack, 1, 10, false, attackIsEnd, this);
	int backArmLeftBoomerangFrontAttack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightBoomerangFrontAttack", L"backArmLeft", backArmLeftBoomerangFrontAttack, 1, 10, false, attackIsEnd, this);
	//		FRONT ATTACK - STAFF
	int backArmRightStaffFrontAttack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightStaffFrontAttack", L"backArmRight", backArmRightStaffFrontAttack, 1, 10, false, attackIsEnd, this);
	int backArmLeftStaffFrontAttack[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightStaffFrontAttack", L"backArmLeft", backArmLeftStaffFrontAttack, 1, 10, false, attackIsEnd, this);

	//		BACK ATTACK - UNARMED
	int backArmRightUnarmedBackAttack[] = { 29,28,42,41 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightUnarmedBackAttack", L"backArmRight", backArmRightUnarmedBackAttack,4,20, true);
	int backArmLeftUnarmedBackAttack[] = { 29,28,42,41 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmLeftUnarmedBackAttack", L"backArmLeft", backArmLeftUnarmedBackAttack, 4,20, true);
	//		BACK ATTACK - SWORD
	int backArmRightSwordBackAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightSwordBackAttack", L"backArmRight", backArmRightSwordBackAttack, 16, 40, false, attackIsEnd, this);
	int backArmLeftSwordBackAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmLeftSwordBackAttack", L"backArmLeft", backArmLeftSwordBackAttack, 16, 40, false, attackIsEnd, this);
	//		BACK ATTACK - LANCE
	int backArmRightLanceBackAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightLanceBackAttack", L"backArmRight", backArmRightLanceBackAttack, 16, 40, true);
	int backArmLeftLanceBackAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmLeftLanceBackAttack", L"backArmLeft", backArmLeftLanceBackAttack, 16, 40, true);
	//		BACK ATTACK - BOOMERANG
	int backArmRightBoomerangBackAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightBoomerangBackAttack", L"backArmRight", backArmRightBoomerangBackAttack, 16, 40, true);
	int backArmLeftBoomerangBackAttack[] = { 12, 13, 29, 45, 46, 47, 32, 33, 34, 18, 2, 1, 0, 15, 14, 13 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightBoomerangBackAttack", L"backArmLeft", backArmLeftBoomerangBackAttack, 16, 40, true);
	//		BACK ATTACK - STAFF
	int backArmRightStaffBackAttack[] = { 29,28,42,41,42,43,44,45,31,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightStaffBackAttack", L"backArmRight", backArmRightStaffBackAttack, 11,30, true);
	int backArmLeftStaffBackAttack[] = { 29,28,42,41,42,43,44,45,31,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation(L"playerBackArmRightStaffBackAttack", L"backArmLeft", backArmLeftStaffBackAttack, 11,30, true);
}

void Player::keyInputSettings(void)
{
	// ========== 이동 키 입력 ==========
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) && !_isSit)
	{
		_isRight = TRUE;
		_bodyState = PLAYER_RIGHT_MOVE;
		_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightMove");
		_bodyMotion->start();

		_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightMove");
		_frontArmMotion->start();

		_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightMove");
		_backArmMotion->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT) && !_isSit)
	{
		_bodyState = PLAYER_RIGHT_STOP;
		_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightStop");
		_bodyMotion->start();

		_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightStop");
		_frontArmMotion->start();

		_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightStop");
		_backArmMotion->start();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT) && !_isSit)
	{
		_isRight = FALSE;
		_bodyState = PLAYER_LEFT_MOVE;
		_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftMove");
		_bodyMotion->start();

		_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmLeftMove");
		_frontArmMotion->start();

		_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmLeftMove");
		_backArmMotion->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT) && !_isSit)
	{
		_bodyState = PLAYER_LEFT_STOP;
		_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftStop");
		_bodyMotion->start();

		_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmLeftStop");
		_frontArmMotion->start();

		_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmLeftStop");
		_backArmMotion->start();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))		//	Sit 키, 충돌 렉트 변화 필요
	{
		_isSit = TRUE;

		if (_bodyState == PLAYER_RIGHT_STOP || _bodyState == PLAYER_RIGHT_MOVE)
		{
			_bodyState = PLAYER_RIGHT_SIT;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightSit");
			_bodyMotion->start();

			_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightSit");
			_frontArmMotion->start();

			_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightSit");
			_backArmMotion->start();
		}
		else if (_bodyState == PLAYER_LEFT_STOP || _bodyState == PLAYER_LEFT_MOVE)
		{
			_bodyState = PLAYER_LEFT_SIT;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftSit");
			_bodyMotion->start();

			_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmLeftSit");
			_frontArmMotion->start();

			_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmLeftSit");
			_backArmMotion->start();
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

			_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightStop");
			_frontArmMotion->start();

			_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightStop");
			_backArmMotion->start();
		}
		else if (_bodyState == PLAYER_LEFT_SIT)
		{
			_bodyState = PLAYER_LEFT_STOP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftStop");
			_bodyMotion->start();

			_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmLeftStop");
			_frontArmMotion->start();

			_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmLeftStop");
			_backArmMotion->start();
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))	//	INVENTORY
	{

	}

	if (KEYMANAGER->isOnceKeyDown('W'))			//	BIRD BOMB
	{

	}

	if (KEYMANAGER->isOnceKeyDown('A'))			//	FRONT_WEAPON_ATTACK
	{
		//	공격용 충돌 렉트 생성

		_isFrontAttack = TRUE;

		//_frontArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightStaffFrontAttack");
		//_backArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightSwordFrontAttack");
		//
		//_frontArmFrontAttackMotion->start();
		//_backArmFrontAttackMotion->start();

		switch (_weaponType)
		{
			case ITEM_TYPE_SWORD:
				_frontArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightSwordFrontAttack");
				_backArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightSwordFrontAttack");
			break;
			case ITEM_TYPE_LANCE:
				_frontArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightLanceFrontAttack");
				_backArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightLanceFrontAttack");
			break;
			case ITEM_TYPE_BOOMERANG:
				_frontArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightBoomerangFrontAttack");
				_backArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightBoomerangFrontAttack");
			break;
			case ITEM_TYPE_STAFF:
				_frontArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightStaffFrontAttack");
				_backArmFrontAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightStaffFrontAttack");
			break;
			default:
				_frontArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightUnarmedBackAttack");
				_backArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightUnarmedBackAttack");
			break;
		}
		
		_frontArmFrontAttackMotion->start();
		_backArmFrontAttackMotion->start();
	}
	if (KEYMANAGER->isOnceKeyDown('S'))			//	JUMP
	{
		_playerJump->jumping(&_x, &_y, JUMPPOWER, GRAVITY);

		if (_bodyState == PLAYER_RIGHT_STOP)
		{
			_bodyState = PLAYER_RIGHT_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightJump");
			_bodyMotion->start();

			_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightJump");
			_frontArmMotion->start();

			_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightJump");
			_backArmMotion->start();
		}
		else if (_bodyState == PLAYER_LEFT_STOP)
		{
			_bodyState = PLAYER_LEFT_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftJump");
			_bodyMotion->start();

			_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmLeftJump");
			_frontArmMotion->start();

			_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmLeftJump");
			_backArmMotion->start();
		}

		if (_bodyState == PLAYER_RIGHT_MOVE)
		{
			_bodyState = PLAYER_RIGHT_MOVE_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyRightJump");
			_bodyMotion->start();

			_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightJump");
			_frontArmMotion->start();

			_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightJump");
			_backArmMotion->start();
		}
		else if (_bodyState == PLAYER_LEFT_MOVE)
		{
			_bodyState = PLAYER_LEFT_MOVE_JUMP;
			_bodyMotion = KEYANIMANAGER->findAnimation(L"playerBodyLeftJump");
			_bodyMotion->start();

			_frontArmMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmLeftJump");
			_frontArmMotion->start();

			_backArmMotion = KEYANIMANAGER->findAnimation(L"playerBackArmLeftJump");
			_backArmMotion->start();
		}
	}
	if (KEYMANAGER->isOnceKeyDown('D'))			//	BACK_WEAPON_ATTACK
	{
		//	공격용 충돌 렉트 생성

		_isBackAttack = TRUE;


		//_frontArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightSwordBackAttack");
		//_backArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightSwordBackAttack");
		//
		//_frontArmBackAttackMotion->start();
		//_backArmBackAttackMotion->start();

		switch (_weaponType)
		{
			case ITEM_TYPE_SWORD:
				_frontArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightSwordBackAttack");
				_backArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightSwordBackAttack");
			break;
			case ITEM_TYPE_LANCE:
				_frontArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightLanceBackAttack");
				_backArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightLanceBackAttack");
			break;
			case ITEM_TYPE_BOOMERANG:
				_frontArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightBoomerangBackAttack");
				_backArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightBoomerangBackAttack");
			break;
			case ITEM_TYPE_STAFF:
				_frontArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightStaffBackAttack");
				_backArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightStaffBackAttack");
			break;
			default:
				_frontArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerFrontArmRightUnarmedBackAttack");
				_backArmBackAttackMotion = KEYANIMANAGER->findAnimation(L"playerBackArmRightUnarmedBackAttack");
			break;
		}
		
		_frontArmBackAttackMotion->start();
		_backArmBackAttackMotion->start();
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

void Player::frontArmRightJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_STOP);
	p->setPlayerFrontArmMotion(KEYANIMANAGER->findAnimation(L"playerFrontArmRightStop"));
	p->getPlayerFrontArmMotion()->start();
}
void Player::frontArmLeftJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_STOP);
	p->setPlayerFrontArmMotion(KEYANIMANAGER->findAnimation(L"playerFrontArmLeftStop"));
	p->getPlayerFrontArmMotion()->start();
}
void Player::frontArmRightMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_MOVE);
	p->setPlayerFrontArmMotion(KEYANIMANAGER->findAnimation(L"playerFrontArmRightMove"));
	p->getPlayerFrontArmMotion()->start();
}
void Player::frontArmLeftMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_MOVE);
	p->setPlayerFrontArmMotion(KEYANIMANAGER->findAnimation(L"playerFrontArmLeftMove"));
	p->getPlayerFrontArmMotion()->start();
}

void Player::backArmRightJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_STOP);
	p->setPlayerBackArmMotion(KEYANIMANAGER->findAnimation(L"playerBackArmRightStop"));
	p->getPlayerBackArmMotion()->start();
}
void Player::backArmLeftJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_STOP);
	p->setPlayerBackArmMotion(KEYANIMANAGER->findAnimation(L"playerBackArmLeftStop"));
	p->getPlayerBackArmMotion()->start();
}
void Player::backArmRightMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_RIGHT_MOVE);
	p->setPlayerBackArmMotion(KEYANIMANAGER->findAnimation(L"playerBackArmRightMove"));
	p->getPlayerBackArmMotion()->start();
}
void Player::backArmLeftMoveJump(void* obj)
{
	Player* p = (Player*)obj;

	p->setPlayerBodyState(PLAYER_LEFT_MOVE);
	p->setPlayerBackArmMotion(KEYANIMANAGER->findAnimation(L"playerBackArmLeftMove"));
	p->getPlayerBackArmMotion()->start();
}

void Player::attackIsEnd(void* obj)
{
	Player* p = (Player*)obj;

	p->setIsFrontAttack(FALSE);
	p->setIsBackAttack(FALSE);
}

void Player::rectUpdate(void)
{
	_rcHead = RectMake(_x + 2, _y - 24, HEAD_WIDTH, HEAD_HEIGHT);
	_rcBody = RectMake(_x, _y - 6, BODY_WIDTH, BODY_HEIGHT);
	_rcFoot = RectMake(_x, _y + 20, FOOT_WIDTH, FOOT_HEIGHT);
}