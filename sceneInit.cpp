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
<<<<<<< HEAD
	IMAGEMANAGER->addImage(DEVICE, L"¸ÞÀÎ¹è°æ", L"image/etc/¹è°æ.png");
	IMAGEMANAGER->addFrameImage(DEVICE, L"¼±ÅÃ", L"image/etc/¼±ÅÃ.png", 8, 1);
=======
	IMAGEMANAGER->addImage(device, L"¸ÞÀÎ¹è°æ", L"image/etc/¹è°æ.png");

	//¾ÆÀÌÅÛ ¹«±â & ¿ÀÀÏ
	IMAGEMANAGER->addImage(device, L"Èò»öÄ®", L"image/item/Èò»öÄ®.png");
	IMAGEMANAGER->addImage(device, L"Èò»ö·£½º", L"image/item/Èò»ö·£½º.png");
	IMAGEMANAGER->addImage(device, L"Èò»öºÎ¸Þ¶û", L"image/item/Èò»öºÎ¸Þ¶û.png");
	IMAGEMANAGER->addImage(device, L"Èò»öÁöÆÎÀÌ", L"image/item/Èò»öÁöÆÎÀÌ.png");
	IMAGEMANAGER->addImage(device, L"Èò»ö¿ÀÀÏ", L"image/item/Èò»ö¿ÀÀÏ.png");
	IMAGEMANAGER->addImage(device, L"ºí·¢Ä®", L"image/item/ºí·¢Ä®.png");
	IMAGEMANAGER->addImage(device, L"ºí·¢·£½º", L"image/item/ºí·¢·£½º.png");
	IMAGEMANAGER->addImage(device, L"ºí·¢ºÎ¸Þ¶û", L"image/item/ºí·¢ºÎ¸Þ¶û.png");
	IMAGEMANAGER->addImage(device, L"ºí·¢ÁöÆÎÀÌ", L"image/item/ºí·¢ÁöÆÎÀÌ.png");
	IMAGEMANAGER->addImage(device, L"ºí·¢¿ÀÀÏ", L"image/item/ºí·¢¿ÀÀÏ.png");
	IMAGEMANAGER->addImage(device, L"°ñµåÄ®", L"image/item/°ñµåÄ®.png");
	IMAGEMANAGER->addImage(device, L"°ñµå·£½º", L"image/item/°ñµå·£½º.png");
	IMAGEMANAGER->addImage(device, L"°ñµåºÎ¸Þ¶û", L"image/item/°ñµåºÎ¸Þ¶û.png");
	IMAGEMANAGER->addImage(device, L"°ñµåÁöÆÎÀÌ", L"image/item/°ñµåÁöÆÎÀÌ.png");
	IMAGEMANAGER->addImage(device, L"°ñµå¿ÀÀÏ", L"image/item/°ñµå¿ÀÀÏ.png");
	//¹æ¾î±¸
	IMAGEMANAGER->addImage(device, L"¹é°©", L"image/item/¹é°©.png");
	IMAGEMANAGER->addImage(device, L"¹éÅõ", L"image/item/¹éÅõ.png");
	IMAGEMANAGER->addImage(device, L"¹é½Å", L"image/item/¹é½Å.png");
	IMAGEMANAGER->addImage(device, L"Èæ°©", L"image/item/Èæ°©.png");
	IMAGEMANAGER->addImage(device, L"ÈæÅõ", L"image/item/ÈæÅõ.png");
	IMAGEMANAGER->addImage(device, L"Èæ½Å", L"image/item/Èæ½Å.png");
	IMAGEMANAGER->addImage(device, L"È²°©", L"image/item/È²°©.png");
	IMAGEMANAGER->addImage(device, L"È²Åõ", L"image/item/È²Åõ.png");
	IMAGEMANAGER->addImage(device, L"È²½Å", L"image/item/È²½Å.png");
	//¾Ë
	IMAGEMANAGER->addFrameImage(device, L"°ËÀº»õ", L"image/item/°ËÀº»õ.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"Èò»õ", L"image/item/Èò»õ.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"È²±Ý»õ", L"image/item/È²±Ý»õ.png", 8, 1);

	
>>>>>>> 7c30778d2b66290f0409b76110f523eea236564b
}

void sceneInit::update(void) 
{

}

void sceneInit::render(void) 
{

}

void sceneInit::initImage(void)
{
	playerInitImage();	//	ÇÃ·¹ÀÌ¾îÀÇ ÀÌ¹ÌÁö ÃÊ±âÈ­ ÇÔ¼ö
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