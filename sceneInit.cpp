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
	playerInitImage();	//	ÇÃ·¹ÀÌ¾îÀÇ ÀÌ¹ÌÁö ÃÊ±âÈ­ ÇÔ¼ö
	uiInitImage();		//	UI ÀÌ¹ÌÁö ÃÊ±âÈ­
	enemyInitImage(); //Àû ÀÌ¹ÌÁö ::

	//¾ÆÀÌÅÛ ¹«±â & ¿ÀÀÏ
	IMAGEMANAGER->addImage(DEVICE, L"Èò»öÄ®", L"image/item/Èò»öÄ®.png");
	IMAGEMANAGER->addImage(DEVICE, L"Èò»ö·£½º", L"image/item/Èò»ö·£½º.png");
	IMAGEMANAGER->addImage(DEVICE, L"Èò»öºÎ¸Þ¶û", L"image/item/Èò»öºÎ¸Þ¶û.png");
	IMAGEMANAGER->addImage(DEVICE, L"Èò»öÁöÆÎÀÌ", L"image/item/Èò»öÁöÆÎÀÌ.png");
	IMAGEMANAGER->addImage(DEVICE, L"Èò»ö¿ÀÀÏ", L"image/item/Èò»ö¿ÀÀÏ.png");
	IMAGEMANAGER->addImage(DEVICE, L"ºí·¢Ä®", L"image/item/ºí·¢Ä®.png");
	IMAGEMANAGER->addImage(DEVICE, L"ºí·¢·£½º", L"image/item/ºí·¢·£½º.png");
	IMAGEMANAGER->addImage(DEVICE, L"ºí·¢ºÎ¸Þ¶û", L"image/item/ºí·¢ºÎ¸Þ¶û.png");
	IMAGEMANAGER->addImage(DEVICE, L"ºí·¢ÁöÆÎÀÌ", L"image/item/ºí·¢ÁöÆÎÀÌ.png");
	IMAGEMANAGER->addImage(DEVICE, L"ºí·¢¿ÀÀÏ", L"image/item/ºí·¢¿ÀÀÏ.png");
	IMAGEMANAGER->addImage(DEVICE, L"°ñµåÄ®", L"image/item/°ñµåÄ®.png");
	IMAGEMANAGER->addImage(DEVICE, L"°ñµå·£½º", L"image/item/°ñµå·£½º.png");
	IMAGEMANAGER->addImage(DEVICE, L"°ñµåºÎ¸Þ¶û", L"image/item/°ñµåºÎ¸Þ¶û.png");
	IMAGEMANAGER->addImage(DEVICE, L"°ñµåÁöÆÎÀÌ", L"image/item/°ñµåÁöÆÎÀÌ.png");
	IMAGEMANAGER->addImage(DEVICE, L"°ñµå¿ÀÀÏ", L"image/item/°ñµå¿ÀÀÏ.png");
	//¹æ¾î±¸
	IMAGEMANAGER->addImage(DEVICE, L"¹é°©", L"image/item/¹é°©.png");
	IMAGEMANAGER->addImage(DEVICE, L"¹éÅõ", L"image/item/¹éÅõ.png");
	IMAGEMANAGER->addImage(DEVICE, L"¹é½Å", L"image/item/¹é½Å.png");
	IMAGEMANAGER->addImage(DEVICE, L"Èæ°©", L"image/item/Èæ°©.png");
	IMAGEMANAGER->addImage(DEVICE, L"ÈæÅõ", L"image/item/ÈæÅõ.png");
	IMAGEMANAGER->addImage(DEVICE, L"Èæ½Å", L"image/item/Èæ½Å.png");
	IMAGEMANAGER->addImage(DEVICE, L"È²°©", L"image/item/È²°©.png");
	IMAGEMANAGER->addImage(DEVICE, L"È²Åõ", L"image/item/È²Åõ.png");
	IMAGEMANAGER->addImage(DEVICE, L"È²½Å", L"image/item/È²½Å.png");
	//¾Ë
	IMAGEMANAGER->addFrameImage(DEVICE, L"°ËÀº»õ", L"image/item/°ËÀº»õ.png", 8, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"Èò»õ", L"image/item/Èò»õ.png", 8, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"È²±Ý»õ", L"image/item/È²±Ý»õ.png", 8, 1);

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
	//	RIGHTSIDE
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

	//	LEFTSIDE
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

void sceneInit::uiInitImage(void)
{
	//¹è°æ
	IMAGEMANAGER->addImage(DEVICE, L"¸ÞÀÎ¹è°æ", L"image/etc/¹è°æ.png");

	//±ÛÀÚ
	IMAGEMANAGER->addImage(DEVICE, L"0", L"image/etc/0.png");
	IMAGEMANAGER->addImage(DEVICE, L"25", L"image/etc/25.png");
	IMAGEMANAGER->addImage(DEVICE, L"50", L"image/etc/50.png");
	IMAGEMANAGER->addImage(DEVICE, L"75", L"image/etc/75.png");
	IMAGEMANAGER->addImage(DEVICE, L"100", L"image/etc/100.png");
	IMAGEMANAGER->addImage(DEVICE, L"exit", L"image/etc/exit.png");
	IMAGEMANAGER->addImage(DEVICE, L"start", L"image/etc/start.png");
	IMAGEMANAGER->addImage(DEVICE, L"music", L"image/etc/music.png");
	IMAGEMANAGER->addImage(DEVICE, L"off", L"image/etc/off.png");
	IMAGEMANAGER->addImage(DEVICE, L"on", L"image/etc/on.png");
	IMAGEMANAGER->addImage(DEVICE, L"options", L"image/etc/options.png");
	IMAGEMANAGER->addImage(DEVICE, L"start", L"image/etc/start.png");
	IMAGEMANAGER->addImage(DEVICE, L"volume", L"image/etc/volume.png");
	IMAGEMANAGER->addImage(DEVICE, L"back", L"image/etc/back.png");
	IMAGEMANAGER->addImage(DEVICE, L"·Î°í", L"image/etc/·Î°í.png");
	IMAGEMANAGER->addImage(DEVICE, L"½Â¸®", L"image/etc/½Â¸®.png");

	//¸Þ´º
	IMAGEMANAGER->addFrameImage(DEVICE, L"¼±ÅÃ", L"image/etc/¼±ÅÃ.png", 8, 1);
	IMAGEMANAGER->addImage(DEVICE, L"¸Þ´º¹Ù", L"image/etc/¸Þ´º¹Ù.png");
	IMAGEMANAGER->addImage(DEVICE, L"¿É¼Ç¸Þ´º", L"image/etc/¿É¼Ç¸Þ´º.png");
	IMAGEMANAGER->addImage(DEVICE, L"selectMusic", L"image/etc/select.png");
	IMAGEMANAGER->addImage(DEVICE, L"selectVolume", L"image/etc/select.png");

}

void sceneInit::enemyInitImage(void)	//¸ó½ºÅÍ
{

	IMAGEMANAGER->addFrameImage(device, L"¿ø¼þÀÌ", L"image/monster/¿ø¼þÀÌ.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"¹ö¼¸¸Ç", L"image/monster/¹ö¼¸¸Ç.png", 7, 1);
	IMAGEMANAGER->addFrameImage(device, L"¹ö¼¸Á¡ÇÁ", L"image/monster/¹ö¼¸¸ÇÁ¡ÇÁ.png", 2, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"°ÅºÏÀÌ", L"image/monster/Turtle_f6.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"°ÅºÏÀÌ´©µå", L"image/monster/Turtle_crash_f6.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"³ª¹«¸Ç", L"image/monster/Ent_move_f6.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"Äá³ª¹°", L"image/monster/kong_idle_f6.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"Äá³ª¹°¾îÅÃ", L"image/monster/kong_atk_f8.png", 8, 1);
	PBGMANAGER->addImage(L"Å×½ºÆ®¹è°æ", L"image/stage/test_collision.png",768,305);

}