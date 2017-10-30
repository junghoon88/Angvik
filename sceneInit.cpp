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


void sceneInit::initImage(void)
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

void sceneInit::initSound(void)
{

}

void sceneInit::initText(void)
{

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
