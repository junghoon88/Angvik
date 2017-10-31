#include "stdafx.h"
#include "sceneInit.h"

sceneInit::sceneInit()
{
}


sceneInit::~sceneInit()
{
}

void sceneInit::init(void)
{
	initImage();
	initSound();
	initText();
}

void sceneInit::release(void)
{

}

void sceneInit::update(void) 
{

}

void sceneInit::render(void) 
{

}

void sceneInit::initImage(void)
{
	playerInitImage();	//	플레이어의 이미지 초기화 함수
	enemyInitImage(); //적 이미지 ::

	IMAGEMANAGER->addImage(device, L"메인배경", L"image/etc/배경.png");
	IMAGEMANAGER->addFrameImage(DEVICE, L"선택", L"image/etc/선택.png", 8, 1);

	//아이템 무기 & 오일
	IMAGEMANAGER->addImage(device, L"흰색칼", L"image/item/흰색칼.png");
	IMAGEMANAGER->addImage(device, L"흰색랜스", L"image/item/흰색랜스.png");
	IMAGEMANAGER->addImage(device, L"흰색부메랑", L"image/item/흰색부메랑.png");
	IMAGEMANAGER->addImage(device, L"흰색지팡이", L"image/item/흰색지팡이.png");
	IMAGEMANAGER->addImage(device, L"흰색오일", L"image/item/흰색오일.png");
	IMAGEMANAGER->addImage(device, L"블랙칼", L"image/item/블랙칼.png");
	IMAGEMANAGER->addImage(device, L"블랙랜스", L"image/item/블랙랜스.png");
	IMAGEMANAGER->addImage(device, L"블랙부메랑", L"image/item/블랙부메랑.png");
	IMAGEMANAGER->addImage(device, L"블랙지팡이", L"image/item/블랙지팡이.png");
	IMAGEMANAGER->addImage(device, L"블랙오일", L"image/item/블랙오일.png");
	IMAGEMANAGER->addImage(device, L"골드칼", L"image/item/골드칼.png");
	IMAGEMANAGER->addImage(device, L"골드랜스", L"image/item/골드랜스.png");
	IMAGEMANAGER->addImage(device, L"골드부메랑", L"image/item/골드부메랑.png");
	IMAGEMANAGER->addImage(device, L"골드지팡이", L"image/item/골드지팡이.png");
	IMAGEMANAGER->addImage(device, L"골드오일", L"image/item/골드오일.png");
	//방어구
	IMAGEMANAGER->addImage(device, L"백갑", L"image/item/백갑.png");
	IMAGEMANAGER->addImage(device, L"백투", L"image/item/백투.png");
	IMAGEMANAGER->addImage(device, L"백신", L"image/item/백신.png");
	IMAGEMANAGER->addImage(device, L"흑갑", L"image/item/흑갑.png");
	IMAGEMANAGER->addImage(device, L"흑투", L"image/item/흑투.png");
	IMAGEMANAGER->addImage(device, L"흑신", L"image/item/흑신.png");
	IMAGEMANAGER->addImage(device, L"황갑", L"image/item/황갑.png");
	IMAGEMANAGER->addImage(device, L"황투", L"image/item/황투.png");
	IMAGEMANAGER->addImage(device, L"황신", L"image/item/황신.png");
	//알
	IMAGEMANAGER->addFrameImage(device, L"검은새", L"image/item/검은새.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"흰새", L"image/item/흰새.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"황금새", L"image/item/황금새.png", 8, 1);






}

void sceneInit::initSound(void)
{

}

void sceneInit::initText(void)
{

}

void sceneInit::playerInitImage(void)
{
	//	BONE
	IMAGEMANAGER->addImage(DEVICE, L"boneHead", L"image/player/bone_head.png");
	IMAGEMANAGER->addImage(DEVICE, L"boneBody", L"image/player/bone_body.png");
	IMAGEMANAGER->addImage(DEVICE, L"boneEtc", L"image/player/bone_etc.png");

	//	UNARMED
	//		RIGHTSIDE
	IMAGEMANAGER->addImage(DEVICE, L"headRight0", L"image/player/unarmed/head_0.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight1", L"image/player/unarmed/head_1.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight2", L"image/player/unarmed/head_2.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight3", L"image/player/unarmed/head_3.png");

	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightIdle", L"image/player/unarmed/body_idle.png", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightSit", L"image/player/unarmed/body_sit.png", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightJumpUp", L"image/player/unarmed/body_jump_up.png", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightJumpDown", L"image/player/unarmed/body_jump_down.png", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightWalk", L"image/player/unarmed/body_walk.png", 12, 1);

	IMAGEMANAGER->addFrameImage(DEVICE, L"armRightFront", L"image/player/unarmed/arm_front.png", 16, 3);
	IMAGEMANAGER->addFrameImage(DEVICE, L"armRightBack", L"image/player/unarmed/arm_back.png", 16, 3);

	//		LEFTSIDE
	IMAGEMANAGER->addImage(DEVICE, L"headLeft0", L"image/player/unarmed/head_0.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft1", L"image/player/unarmed/head_1.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft2", L"image/player/unarmed/head_2.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft3", L"image/player/unarmed/head_3.png");

	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftIdle", L"image/player/unarmed/body_idle.png", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftSit", L"image/player/unarmed/body_sit.png", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftJumpUp", L"image/player/unarmed/body_jump_up.png", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftJumpDown", L"image/player/unarmed/body_jump_down.png", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftWalk", L"image/player/unarmed/body_walk.png", 12, 1);

	IMAGEMANAGER->addFrameImage(DEVICE, L"armLeftFront", L"image/player/unarmed/arm_front.png", 16, 3);
	IMAGEMANAGER->addFrameImage(DEVICE, L"armLeftBack", L"image/player/unarmed/arm_back.png", 16, 3);
}

void sceneInit::enemyInitImage(void)
{
	IMAGEMANAGER->addFrameImage(device, L"원숭이", L"image/monster/원숭이.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"버섯맨", L"image/monster/버섯맨.png", 7, 1);
	IMAGEMANAGER->addFrameImage(device, L"거북이", L"image/monster/Turtle_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(device, L"거북이누드", L"image/monster/Turtle_crash_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(device, L"나무맨", L"image/monster/Ent_move_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(device, L"콩나물", L"image/monster/kong_idle_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(device, L"콩나물어택", L"image/monster/kong_atk_8f.png", 8, 1);
}