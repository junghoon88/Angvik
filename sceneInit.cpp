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
