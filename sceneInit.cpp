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
	IMAGEMANAGER->addImage(device, L"���ι��", L"image/etc/���.png");

	//������ ���� & ����
	IMAGEMANAGER->addImage(device, L"���Į", L"image/item/���Į.png");
	IMAGEMANAGER->addImage(device, L"�������", L"image/item/�������.png");
	IMAGEMANAGER->addImage(device, L"����θ޶�", L"image/item/����θ޶�.png");
	IMAGEMANAGER->addImage(device, L"���������", L"image/item/���������.png");
	IMAGEMANAGER->addImage(device, L"�������", L"image/item/�������.png");
	IMAGEMANAGER->addImage(device, L"��Į", L"image/item/��Į.png");
	IMAGEMANAGER->addImage(device, L"������", L"image/item/������.png");
	IMAGEMANAGER->addImage(device, L"���θ޶�", L"image/item/���θ޶�.png");
	IMAGEMANAGER->addImage(device, L"��������", L"image/item/��������.png");
	IMAGEMANAGER->addImage(device, L"������", L"image/item/������.png");
	IMAGEMANAGER->addImage(device, L"���Į", L"image/item/���Į.png");
	IMAGEMANAGER->addImage(device, L"��巣��", L"image/item/��巣��.png");
	IMAGEMANAGER->addImage(device, L"���θ޶�", L"image/item/���θ޶�.png");
	IMAGEMANAGER->addImage(device, L"���������", L"image/item/���������.png");
	IMAGEMANAGER->addImage(device, L"������", L"image/item/������.png");
	//��
	IMAGEMANAGER->addImage(device, L"�鰩", L"image/item/�鰩.png");
	IMAGEMANAGER->addImage(device, L"����", L"image/item/����.png");
	IMAGEMANAGER->addImage(device, L"���", L"image/item/���.png");
	IMAGEMANAGER->addImage(device, L"�氩", L"image/item/�氩.png");
	IMAGEMANAGER->addImage(device, L"����", L"image/item/����.png");
	IMAGEMANAGER->addImage(device, L"���", L"image/item/���.png");
	IMAGEMANAGER->addImage(device, L"Ȳ��", L"image/item/Ȳ��.png");
	IMAGEMANAGER->addImage(device, L"Ȳ��", L"image/item/Ȳ��.png");
	IMAGEMANAGER->addImage(device, L"Ȳ��", L"image/item/Ȳ��.png");
	//��
	IMAGEMANAGER->addFrameImage(device, L"������", L"image/item/������.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"���", L"image/item/���.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"Ȳ�ݻ�", L"image/item/Ȳ�ݻ�.png", 8, 1);

	
}

void sceneInit::update(void) 
{

}

void sceneInit::render(void) 
{

}

void sceneInit::initImage(void)
{
	playerInitImage();	//	�÷��̾��� �̹��� �ʱ�ȭ �Լ�
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
	IMAGEMANAGER->addImage(DEVICE, L"boneHead", L"image/player/bone_head.bmp");
	IMAGEMANAGER->addImage(DEVICE, L"boneBody", L"image/player/bone_body.bmp");
	IMAGEMANAGER->addImage(DEVICE, L"boneEtc", L"image/player/bone_etc.bmp");

	//	UNARMED
	//		RIGHTSIDE
	IMAGEMANAGER->addImage(DEVICE, L"headRight0", L"image/player/unarmed/head_0.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight1", L"image/player/unarmed/head_1.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight2", L"image/player/unarmed/head_2.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight3", L"image/player/unarmed/head_3.png");

	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightIdle", L"image/player/unarmed/body_idle.bmp", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightSit", L"image/player/unarmed/body_sit.bmp", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightJumpUp", L"image/player/unarmed/body_jump_up.bmp", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightJumpDown", L"image/player/unarmed/body_jump_down.bmp", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightWalk", L"image/player/unarmed/body_walk.png", 12, 1);

	IMAGEMANAGER->addFrameImage(DEVICE, L"armRightFront", L"image/player/unarmed/arm_front.bmp", 16, 3);
	IMAGEMANAGER->addFrameImage(DEVICE, L"armRightBack", L"image/player/unarmed/arm_back.bmp", 16, 3);

	//		LEFTSIDE
	IMAGEMANAGER->addImage(DEVICE, L"headLeft0", L"image/player/unarmed/head_0.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft1", L"image/player/unarmed/head_1.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft2", L"image/player/unarmed/head_2.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft3", L"image/player/unarmed/head_3.png");

	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftIdle", L"image/player/unarmed/body_idle.bmp", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftSit", L"image/player/unarmed/body_sit.bmp", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftJumpUp", L"image/player/unarmed/body_jump_up.bmp", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftJumpDown", L"image/player/unarmed/body_jump_down.bmp", 1, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftWalk", L"image/player/unarmed/body_walk.png", 12, 1);

	IMAGEMANAGER->addFrameImage(DEVICE, L"armLeftFront", L"image/player/unarmed/arm_front.bmp", 16, 3);
	IMAGEMANAGER->addFrameImage(DEVICE, L"armLeftBack", L"image/player/unarmed/arm_back.bmp", 16, 3);
}