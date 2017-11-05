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
	stageInitImage();	//�������� �̹���(���)

	playerInitImage();	//	�÷��̾��� �̹��� �ʱ�ȭ �Լ�
	uiInitImage();		//	UI �̹��� �ʱ�ȭ
	enemyInitImage(); //�� �̹��� ::

	//������ ���� & ����
	IMAGEMANAGER->addImage(DEVICE, L"���Į", L"image/item/���Į.png");
	IMAGEMANAGER->addImage(DEVICE, L"�������", L"image/item/�������.png");
	IMAGEMANAGER->addImage(DEVICE, L"����θ޶�", L"image/item/����θ޶�.png");
	IMAGEMANAGER->addImage(DEVICE, L"���������", L"image/item/���������.png");
	IMAGEMANAGER->addImage(DEVICE, L"�������", L"image/item/�������.png");
	IMAGEMANAGER->addImage(DEVICE, L"��Į", L"image/item/��Į.png");
	IMAGEMANAGER->addImage(DEVICE, L"������", L"image/item/������.png");
	IMAGEMANAGER->addImage(DEVICE, L"���θ޶�", L"image/item/���θ޶�.png");
	IMAGEMANAGER->addImage(DEVICE, L"��������", L"image/item/��������.png");
	IMAGEMANAGER->addImage(DEVICE, L"������", L"image/item/������.png");
	IMAGEMANAGER->addImage(DEVICE, L"���Į", L"image/item/���Į.png");
	IMAGEMANAGER->addImage(DEVICE, L"��巣��", L"image/item/��巣��.png");
	IMAGEMANAGER->addImage(DEVICE, L"���θ޶�", L"image/item/���θ޶�.png");
	IMAGEMANAGER->addImage(DEVICE, L"���������", L"image/item/���������.png");
	IMAGEMANAGER->addImage(DEVICE, L"������", L"image/item/������.png");
	
	//��
	IMAGEMANAGER->addImage(DEVICE, L"�鰩", L"image/item/�鰩.png");
	IMAGEMANAGER->addImage(DEVICE, L"����", L"image/item/����.png");
	IMAGEMANAGER->addImage(DEVICE, L"���", L"image/item/���.png");
	IMAGEMANAGER->addImage(DEVICE, L"�氩", L"image/item/�氩.png");
	IMAGEMANAGER->addImage(DEVICE, L"����", L"image/item/����.png");
	IMAGEMANAGER->addImage(DEVICE, L"���", L"image/item/���.png");
	IMAGEMANAGER->addImage(DEVICE, L"Ȳ��", L"image/item/Ȳ��.png");
	IMAGEMANAGER->addImage(DEVICE, L"Ȳ��", L"image/item/Ȳ��.png");
	IMAGEMANAGER->addImage(DEVICE, L"Ȳ��", L"image/item/Ȳ��.png");
	//��
	IMAGEMANAGER->addImage(DEVICE, L"�ް�", L"image/item/��.png");
	IMAGEMANAGER->addFrameImage(DEVICE, L"������", L"image/item/������.png", 8, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"���", L"image/item/���.png", 8, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"Ȳ�ݻ�", L"image/item/Ȳ�ݻ�.png", 8, 1);
	
}

void sceneInit::initSound(void)
{
	//UI
	SOUNDMANAGER->addSound(L"�޴����", L"sound/bgm/main.wav", true, true);
	SOUNDMANAGER->addSound(L"stage1bgm", L"sound/bgm/stage1.wav", true, true);
	SOUNDMANAGER->addSound(L"�޴��̵�", L"sound/UI/�޴��̵�.wav", false, false);
	SOUNDMANAGER->addSound(L"�޴�����", L"sound/UI/�޴�����.wav", false, false);
}

void sceneInit::initText(void)
{

}

void sceneInit::stageInitImage()	//�������� �̹���(���)
{
	//��׶���
	Sprite* background = IMAGEMANAGER->addImage(DEVICE, L"Stage1-BG", L"image/Stage/Stage1-Background.png");
	MAINCAMERA->setMinMax(0, 0, background->getSize().x - WINSIZEX, background->getSize().y - WINSIZEY);
	IMAGEMANAGER->addImage(DEVICE, L"Stage1-BG2", L"image/Stage/Stage1-Background2.png");
	IMAGEMANAGER->addImage(DEVICE, L"Stage1-Hidden", L"image/Stage/Stage1-Hidden.png");

	
	//�ȼ���׶���
	IMAGEMANAGER->addImage(DEVICE, L"Stage1-PBG", L"image/Stage/Stage1-PBG.bmp");
	PBGMANAGER->addImage(L"Stage1-PBG", L"image/stage/Stage1-PBG.bmp", 6709, 1290);

	//���ʹ� �׽�Ʈ�� ���
	IMAGEMANAGER->addImage(DEVICE, L"Stage1-TEST", L"image/Stage/Stage1-test.bmp");
	PBGMANAGER->addImage(L"Stage1-TEST", L"image/stage/Stage1-test.bmp", 6709, 1290);

	//����
	IMAGEMANAGER->addImage(DEVICE, L"����ũ����", L"image/Stage/End_front.png");
	IMAGEMANAGER->addImage(DEVICE, L"�������1", L"image/Stage/End_back1.png");
	IMAGEMANAGER->addImage(DEVICE, L"�������2", L"image/Stage/End_back2.png");
	IMAGEMANAGER->addImage(DEVICE, L"�������3", L"image/Stage/End_back3.png");

	
}



void sceneInit::playerInitImage(void)
{
	//	BONE
	IMAGEMANAGER->addImage(DEVICE, L"boneHead", L"image/player/bone_head.png");
	IMAGEMANAGER->addImage(DEVICE, L"boneBody", L"image/player/bone_body.png");
	IMAGEMANAGER->addImage(DEVICE, L"bone0", L"image/player/bone_etc.png");
	IMAGEMANAGER->addImage(DEVICE, L"bone1", L"image/player/bone_etc.png");
	IMAGEMANAGER->addImage(DEVICE, L"bone2", L"image/player/bone_etc.png");
	IMAGEMANAGER->addImage(DEVICE, L"bone3", L"image/player/bone_etc.png");

	//	UNARMED
	//	RIGHTSIDE
	IMAGEMANAGER->addImage(DEVICE, L"headRight0", L"image/player/unarmed/head_0.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight1", L"image/player/unarmed/head_1.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight2", L"image/player/unarmed/head_2.png");
	IMAGEMANAGER->addImage(DEVICE, L"headRight3", L"image/player/unarmed/head_3.png");

	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightIdle", L"image/player/unarmed/body_idle.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightSit", L"image/player/unarmed/body_sit.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightJumpUp", L"image/player/unarmed/body_jump_up.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightJumpDown", L"image/player/unarmed/body_jump_down.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyRightWalk", L"image/player/unarmed/body_walk.png", 12, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"unarmedBodyRight", L"image/player/unarmed/body.png", 12, 2);

	//	ITEM
	IMAGEMANAGER->addFrameImage(DEVICE, L"blackBodyRight", L"image/player/black/body.png", 12, 2);
	IMAGEMANAGER->addFrameImage(DEVICE, L"blackFootRight", L"image/player/black/foot.png", 12, 2);
	IMAGEMANAGER->addFrameImage(DEVICE, L"goldBodyRight", L"image/player/gold/body.png", 12, 2);
	IMAGEMANAGER->addFrameImage(DEVICE, L"goldFootRight", L"image/player/gold/foot.png", 12, 2);
	IMAGEMANAGER->addFrameImage(DEVICE, L"whiteBodyRight", L"image/player/white/body.png", 12, 2);
	IMAGEMANAGER->addFrameImage(DEVICE, L"whiteFootRight", L"image/player/white/foot.png", 12, 2);

	IMAGEMANAGER->addFrameImage(DEVICE, L"frontArmRight", L"image/player/unarmed/arm_front.png", 16, 3);
	IMAGEMANAGER->addFrameImage(DEVICE, L"backArmRight", L"image/player/unarmed/arm_back.png", 16, 3);

	//	LEFTSIDE
	IMAGEMANAGER->addImage(DEVICE, L"headLeft0", L"image/player/unarmed/head_0.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft1", L"image/player/unarmed/head_1.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft2", L"image/player/unarmed/head_2.png");
	IMAGEMANAGER->addImage(DEVICE, L"headLeft3", L"image/player/unarmed/head_3.png");

	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftIdle", L"image/player/unarmed/body_idle.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftSit", L"image/player/unarmed/body_sit.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftJumpUp", L"image/player/unarmed/body_jump_up.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftJumpDown", L"image/player/unarmed/body_jump_down.png", 1, 1);
	//IMAGEMANAGER->addFrameImage(DEVICE, L"bodyLeftWalk", L"image/player/unarmed/body_walk.png", 12, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"unarmedBodyLeft", L"image/player/unarmed/body.png", 12, 2);

	//	ITEM
	IMAGEMANAGER->addFrameImage(DEVICE, L"blackBodyLeft", L"image/player/black/body.png", 12, 2);
	IMAGEMANAGER->addFrameImage(DEVICE, L"blackFootLeft", L"image/player/black/foot.png", 12, 2);
	IMAGEMANAGER->addFrameImage(DEVICE, L"goldBodyLeft", L"image/player/gold/body.png", 12, 2);
	IMAGEMANAGER->addFrameImage(DEVICE, L"goldFootLeft", L"image/player/gold/foot.png", 12, 2);
	IMAGEMANAGER->addFrameImage(DEVICE, L"whiteBodyLeft", L"image/player/white/body.png", 12, 2);
	IMAGEMANAGER->addFrameImage(DEVICE, L"whiteFootLeft", L"image/player/white/foot.png", 12, 2);

	IMAGEMANAGER->addFrameImage(DEVICE, L"frontArmLeft", L"image/player/unarmed/arm_front.png", 16, 3);
	IMAGEMANAGER->addFrameImage(DEVICE, L"backArmLeft", L"image/player/unarmed/arm_back.png", 16, 3);

	//inventorybird
	IMAGEMANAGER->addFrameImage(DEVICE, L"inventoryBird", L"image/player/inventoryBird.png", 6, 4);
}

void sceneInit::uiInitImage(void)
{
	//���
	IMAGEMANAGER->addImage(DEVICE, L"���ι��", L"image/etc/���.png",false);

	//����
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
	IMAGEMANAGER->addImage(DEVICE, L"�ΰ�", L"image/etc/�ΰ�.png");
	IMAGEMANAGER->addImage(DEVICE, L"�¸�", L"image/etc/�¸�.png");
	IMAGEMANAGER->addImage(DEVICE, L"item", L"image/etc/item.png");
	IMAGEMANAGER->addImage(DEVICE, L"oils", L"image/etc/oils.png");
	IMAGEMANAGER->addImage(DEVICE, L"close", L"image/etc/close.png");
	IMAGEMANAGER->addImage(DEVICE, L"equip", L"image/etc/equip.png");
	IMAGEMANAGER->addImage(DEVICE, L"drop", L"image/etc/drop.png");

	//�޴�
	IMAGEMANAGER->addFrameImage(DEVICE, L"����", L"image/etc/����.png", 8, 1);
	IMAGEMANAGER->addImage(DEVICE, L"�޴���", L"image/etc/�޴���.png");
	IMAGEMANAGER->addImage(DEVICE, L"�ɼǸ޴�", L"image/etc/�ɼǸ޴�.png");
	IMAGEMANAGER->addImage(DEVICE, L"selectMusic", L"image/etc/select.png");
	IMAGEMANAGER->addImage(DEVICE, L"selectVolume", L"image/etc/select.png");

	//�κ��丮
	IMAGEMANAGER->addImage(DEVICE, L"inventory", L"image/etc/inventory.png");
	IMAGEMANAGER->addImage(DEVICE, L"itemBox", L"image/etc/itemBox.png");
	IMAGEMANAGER->addImage(DEVICE, L"oilsBox", L"image/etc/oilsBox.png");
	IMAGEMANAGER->addFrameImage(DEVICE, L"�����ۼ���", L"image/etc/�����ۼ���.png", 8, 1);
}

void sceneInit::enemyInitImage(void)	//����
{
	IMAGEMANAGER->addFrameImage(DEVICE, L"������", L"image/monster/������.png", 8, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"������", L"image/monster/������.png", 7, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"��������", L"image/monster/����������.png", 2, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"��������", L"image/monster/��������.png", 6, 1);
	IMAGEMANAGER->addImage(DEVICE, L"�����θ޶�", L"image/monster/�����θ޶�.png");
	IMAGEMANAGER->addFrameImage(DEVICE, L"�ź���", L"image/monster/Turtle_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"�ź��̴���", L"image/monster/Turtle_crash_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"������", L"image/monster/Ent_move_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"�����Ǿ���", L"image/monster/Ent_atk_6f.png", 6, 1);
	IMAGEMANAGER->addImage(DEVICE, L"��1", L"image/monster/leaf1.png");
	IMAGEMANAGER->addImage(DEVICE, L"��2", L"image/monster/leaf2.png");
	IMAGEMANAGER->addImage(DEVICE, L"��3", L"image/monster/leaf3.png");
	IMAGEMANAGER->addImage(DEVICE, L"��4", L"image/monster/leaf4.png");
	IMAGEMANAGER->addFrameImage(DEVICE, L"�ᳪ��", L"image/monster/kong_idle_6f.png", 6, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"�ᳪ������", L"image/monster/kong_atk_8f.png", 8, 1);
	IMAGEMANAGER->addFrameImage(DEVICE, L"��ź", L"image/monster/kongtan.png", 6, 1);
	PBGMANAGER->addImage(L"�浹�׽�Ʈ", L"image/stage/test_bmp.bmp",768,305);
	IMAGEMANAGER->addImage(DEVICE,L"�浹�׽�Ʈ�������", L"image/stage/test_collision.png");
}