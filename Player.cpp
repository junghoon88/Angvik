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
	_headState = PLAYER_YOUNGEST;
	_bodyState = PLAYER_RIGHT_STOP;

	// 발 사이 맨 밑
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_jumpPower = JUMPPOWER;

	_rcHead = RectMakeCenter(_x - 9, _y - 52, 20, 20);
	_rcBody = RectMake(_x - 10, _y - 33, 20, 33);

	_armRightFrontImage = IMAGEMANAGER->findImage(L"armRightFront");
	_armRightBackImage = IMAGEMANAGER->findImage(L"armRightBack");
	_armLeftFrontImage = IMAGEMANAGER->findImage(L"armLeftFront");
	_armLeftBackImage = IMAGEMANAGER->findImage(L"armLeftBack");
	
	//========== 이미지 왼쪽 보게 바꾸기 ==========
	IMAGEMANAGER->findImage(L"headLeft0")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft1")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft2")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"headLeft3")->setScale({ -1,1 });

	IMAGEMANAGER->findImage(L"bodyLeftIdle")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"bodyLeftSit")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"bodyLeftJumpUp")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"bodyLeftJumpDown")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"bodyLeftWalk")->setScale({ -1,1 });

	IMAGEMANAGER->findImage(L"armLeftFront")->setScale({ -1,1 });
	IMAGEMANAGER->findImage(L"armLeftBack")->setScale({ -1,1 });

	//========== 키 애니메이션 초기화 ==========

	//	팔

	KEYANIMANAGER->addDefaultFrameAnimation(L"rightMove", L"bodyRightWalk", 10, false, true);
	KEYANIMANAGER->addDefaultFrameAnimation(L"leftMove", L"bodyLeftWalk", 10, false, true);


	//========== 각 부위 포지션 세팅 ==========
	IMAGEMANAGER->setCenterPos(L"head0", _x - 1, _y - 40);
	IMAGEMANAGER->setCenterPos(L"body_idle", _x, _y - 22);
	IMAGEMANAGER->setCenterPos(L"armFront0", _x - 8, _y - 34);
	IMAGEMANAGER->setCenterPos(L"armFront1", _x - 8, _y - 41);
	IMAGEMANAGER->setCenterPos(L"armFront2", _x - 8, _y - 41);
	IMAGEMANAGER->setCenterPos(L"armBack0", _x - 8, _y - 34);
	IMAGEMANAGER->setCenterPos(L"armBack1", _x - 8, _y - 41);
	IMAGEMANAGER->setCenterPos(L"armBack2", _x - 8, _y - 41);	
}

void Player::release(void)
{

}

void Player::update(void) 
{
	// ========== 이동 키 입력 ==========
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_bodyState = PLAYER_RIGHT_MOVE;
		_bodyMotion = KEYANIMANAGER->findAnimation(L"rightMove");
		_bodyMotion->start();

	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_bodyState = PLAYER_RIGHT_STOP;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_bodyState = PLAYER_LEFT_MOVE;
		_bodyMotion = KEYANIMANAGER->findAnimation(L"leftMove");
		_bodyMotion->start();

	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_bodyState = PLAYER_LEFT_STOP;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))		//	Sit 키, 충돌 렉트 변화 필요
	{
		if (_bodyState == PLAYER_RIGHT_STOP || _bodyState == PLAYER_RIGHT_MOVE)
		{
			_bodyState = PLAYER_RIGHT_SIT;
		}
		else if (_bodyState == PLAYER_LEFT_STOP || _bodyState == PLAYER_LEFT_MOVE)
		{
			_bodyState = PLAYER_LEFT_SIT;
		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		if (_bodyState == PLAYER_RIGHT_SIT)
		{
			_bodyState = PLAYER_RIGHT_STOP;
		}
		else if (_bodyState == PLAYER_LEFT_SIT)
		{
			_bodyState = PLAYER_LEFT_STOP;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))//	MENU
	{

	}
	if (KEYMANAGER->isOnceKeyDown('A'))		//	FRONT_WEAPON_ATTACK
	{

	}
	if (KEYMANAGER->isOnceKeyDown('S'))		//	JUMP
	{

	}
	if (KEYMANAGER->isOnceKeyDown('D'))		//	BACK_WEAPON_ATTACK
	{

	}



	KEYANIMANAGER->update();
}

void Player::render(void) 
{
	//	 몸
	switch (_bodyState)
	{
		case PLAYER_RIGHT_STOP:
			IMAGEMANAGER->findImage(L"bodyRightIdle")->render();
		break;
		case PLAYER_LEFT_STOP:
			IMAGEMANAGER->findImage(L"bodyRightIdle")->render();
		break;
		case PLAYER_RIGHT_MOVE:
			//IMAGEMANAGER->findImage(L"bodyRightMove")->aniRender();
		break;
		case PLAYER_LEFT_MOVE:
		//	IMAGEMANAGER->findImage(L"bodyLeftMove")->frameRender();
		break;
		case PLAYER_RIGHT_SIT:
			IMAGEMANAGER->findImage(L"bodyRightSit")->render();
		break;
		case PLAYER_LEFT_SIT:
			IMAGEMANAGER->findImage(L"bodyLeftIdle")->render();
		break;
		case PLAYER_RIGHT_JUMP: case PLAYER_LEFT_JUMP:
		break;
	}

	//	머 리
	switch (_bodyState)
	{
	case PLAYER_RIGHT_STOP:	case PLAYER_RIGHT_MOVE: case PLAYER_RIGHT_SIT: case PLAYER_RIGHT_JUMP:
		switch (_headState)
		{
		case PLAYER_YOUNGEST:
			IMAGEMANAGER->findImage(L"headRight0")->render();
			break;
		case PLAYER_YOUNG:
			IMAGEMANAGER->findImage(L"headRight1")->render();
			break;
		case PLAYER_OLD:
			IMAGEMANAGER->findImage(L"headRight2")->render();
			break;
		case PLAYER_ELDEST:
			IMAGEMANAGER->findImage(L"headRight3")->render();
			break;
		}
		break;
	case PLAYER_LEFT_STOP: case PLAYER_LEFT_MOVE: case PLAYER_LEFT_SIT: case PLAYER_LEFT_JUMP:
		switch (_headState)
		{
		case PLAYER_YOUNGEST:
			IMAGEMANAGER->findImage(L"headLeft0")->render();
			break;
		case PLAYER_YOUNG:
			IMAGEMANAGER->findImage(L"headLeft1")->render();
			break;
		case PLAYER_OLD:
			IMAGEMANAGER->findImage(L"headLeft2")->render();
			break;
		case PLAYER_ELDEST:
			IMAGEMANAGER->findImage(L"headLeft3")->render();
			break;
		}
		break;
	}
}