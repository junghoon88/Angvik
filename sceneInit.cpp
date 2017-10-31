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
	playerInitImage();	//	«√∑π¿ÃæÓ¿« ¿ÃπÃ¡ˆ √ ±‚»≠ «‘ºˆ
	uiInitImage();		//	UI ¿ÃπÃ¡ˆ √ ±‚»≠
	enemyInitImage(); //¿˚ ¿ÃπÃ¡ˆ ::

	//æ∆¿Ã≈€ π´±‚ & ø¿¿œ
	IMAGEMANAGER->addImage(DEVICE, L"»ÚªˆƒÆ", L"image/item/»ÚªˆƒÆ.png");
	IMAGEMANAGER->addImage(DEVICE, L"»Úªˆ∑£Ω∫", L"image/item/»Úªˆ∑£Ω∫.png");
	IMAGEMANAGER->addImage(DEVICE, L"»Úªˆ∫Œ∏ﬁ∂˚", L"image/item/»Úªˆ∫Œ∏ﬁ∂˚.png");
	IMAGEMANAGER->addImage(DEVICE, L"»Úªˆ¡ˆ∆Œ¿Ã", L"image/item/»Úªˆ¡ˆ∆Œ¿Ã.png");
	IMAGEMANAGER->addImage(DEVICE, L"»Úªˆø¿¿œ", L"image/item/»Úªˆø¿¿œ.png");
	IMAGEMANAGER->addImage(DEVICE, L"∫Ì∑¢ƒÆ", L"image/item/∫Ì∑¢ƒÆ.png");
	IMAGEMANAGER->addImage(DEVICE, L"∫Ì∑¢∑£Ω∫", L"image/item/∫Ì∑¢∑£Ω∫.png");
	IMAGEMANAGER->addImage(DEVICE, L"∫Ì∑¢∫Œ∏ﬁ∂˚", L"image/item/∫Ì∑¢∫Œ∏ﬁ∂˚.png");
	IMAGEMANAGER->addImage(DEVICE, L"∫Ì∑¢¡ˆ∆Œ¿Ã", L"image/item/∫Ì∑¢¡ˆ∆Œ¿Ã.png");
	IMAGEMANAGER->addImage(DEVICE, L"∫Ì∑¢ø¿¿œ", L"image/item/∫Ì∑¢ø¿¿œ.png");
	IMAGEMANAGER->addImage(DEVICE, L"∞ÒµÂƒÆ", L"image/item/∞ÒµÂƒÆ.png");
	IMAGEMANAGER->addImage(DEVICE, L"∞ÒµÂ∑£Ω∫", L"image/item/∞ÒµÂ∑£Ω∫.png");
	IMAGEMANAGER->addImage(DEVICE, L"∞ÒµÂ∫Œ∏ﬁ∂˚", L"image/item/∞ÒµÂ∫Œ∏ﬁ∂˚.png");
	IMAGEMANAGER->addImage(DEVICE, L"∞ÒµÂ¡ˆ∆Œ¿Ã", L"image/item/∞ÒµÂ¡ˆ∆Œ¿Ã.png");
	IMAGEMANAGER->addImage(DEVICE, L"∞ÒµÂø¿¿œ", L"image/item/∞ÒµÂø¿¿œ.png");
	//πÊæÓ±∏
	IMAGEMANAGER->addImage(DEVICE, L"πÈ∞©", L"image/item/πÈ∞©.png");
	IMAGEMANAGER->addImage(DEVICE, L"πÈ≈ı", L"image/item/πÈ≈ı.png");
	IMAGEMANAGER->addImage(DEVICE, L"πÈΩ≈", L"image/item/πÈΩ≈.png");
	IMAGEMANAGER->addImage(DEVICE, L"»Ê∞©", L"image/item/»Ê∞©.png");
	IMAGEMANAGER->addImage(DEVICE, L"»Ê≈ı", L"image/item/»Ê≈ı.png");
	IMAGEMANAGER->addImage(DEVICE, L"»ÊΩ≈", L"image/item/»ÊΩ≈.png");
	IMAGEMANAGER->addImage(DEVICE, L"»≤∞©", L"image/item/»≤∞©.png");
	IMAGEMANAGER->addImage(DEVICE, L"»≤≈ı", L"image/item/»≤≈ı.png");
	IMAGEMANAGER->addImage(DEVICE, L"»≤Ω≈", L"image/item/»≤Ω≈.png");
	//æÀ
	IMAGEMANAGER->addFrameImage(DEVICE, L"∞À¿∫ªı", L"image/item/∞À¿∫ªı.png", 8, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"»Úªı", L"image/item/»Úªı.png", 8, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"»≤±›ªı", L"image/item/»≤±›ªı.png", 8, 1);

<<<<<<< HEAD
=======
	//∏ÛΩ∫≈Õ
	IMAGEMANAGER->addFrameImage(device, L"ø¯º˛¿Ã", L"image/monster/ø¯º˛¿Ã.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"πˆº∏∏«", L"image/monster/πˆº∏∏«.png", 7, 1);
	IMAGEMANAGER->addFrameImage(device, L"πˆº∏¡°«¡", L"image/monster/πˆº∏∏«¡°«¡.png", 2, 1);

>>>>>>> e8a3ab6eafc3de7f28c7c2fa081d912d60f04928
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
	//πË∞Ê
	IMAGEMANAGER->addImage(DEVICE, L"∏ﬁ¿ŒπË∞Ê", L"image/etc/πË∞Ê.png");

	//±€¿⁄
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
	IMAGEMANAGER->addImage(DEVICE, L"∑Œ∞Ì", L"image/etc/∑Œ∞Ì.png");
	IMAGEMANAGER->addImage(DEVICE, L"Ω¬∏Æ", L"image/etc/Ω¬∏Æ.png");

	//∏ﬁ¥∫
	IMAGEMANAGER->addFrameImage(DEVICE, L"º±≈√", L"image/etc/º±≈√.png", 8, 1);
	IMAGEMANAGER->addImage(DEVICE, L"∏ﬁ¥∫πŸ", L"image/etc/∏ﬁ¥∫πŸ.png");
	IMAGEMANAGER->addImage(DEVICE, L"ø…º«∏ﬁ¥∫", L"image/etc/ø…º«∏ﬁ¥∫.png");
	IMAGEMANAGER->addImage(DEVICE, L"selectMusic", L"image/etc/select.png");
	IMAGEMANAGER->addImage(DEVICE, L"selectVolume", L"image/etc/select.png");

}

void sceneInit::enemyInitImage(void)	//∏ÛΩ∫≈Õ
{
<<<<<<< HEAD
	IMAGEMANAGER->addFrameImage(device, L"ø¯º˛¿Ã", L"image/monster/ø¯º˛¿Ã.png", 8, 1);
	IMAGEMANAGER->addFrameImage(device, L"πˆº∏∏«", L"image/monster/πˆº∏∏«.png", 7, 1);
	IMAGEMANAGER->addFrameImage(device, L"πˆº∏¡°«¡", L"image/monster/πˆº∏∏«¡°«¡.png", 2, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"∞≈∫œ¿Ã", L"image/monster/Turtle_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"∞≈∫œ¿Ã¥©µÂ", L"image/monster/Turtle_crash_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"≥™π´∏«", L"image/monster/Ent_move_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"ƒ·≥™π∞", L"image/monster/kong_idle_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"ƒ·≥™π∞æÓ≈√", L"image/monster/kong_atk_8f.png", 8, 1);

=======
	IMAGEMANAGER->addFrameImage(DEVICE, L"ø¯º˛¿Ã", L"image/monster/ø¯º˛¿Ã.png", 8, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"πˆº∏∏«", L"image/monster/πˆº∏∏«.png", 7, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"∞≈∫œ¿Ã", L"image/monster/Turtle_6f.png", 6, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"∞≈∫œ¿Ã¥©µÂ", L"image/monster/Turtle_crash_6f.png", 6, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"≥™π´∏«", L"image/monster/Ent_move_6f.png", 6, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"ƒ·≥™π∞", L"image/monster/kong_idle_6f.png", 6, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"ƒ·≥™π∞æÓ≈√", L"image/monster/kong_atk_8f.png", 8, 1);
>>>>>>> e8a3ab6eafc3de7f28c7c2fa081d912d60f04928
}