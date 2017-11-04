#include "stdafx.h"
#include "Bullet.h"
#include "EnemyManager.h"

sBMR::sBMR() {}
sBMR::~sBMR() {}

void sBMR::init(void)
{

}
void sBMR::release(void)
{

}
void sBMR::update(void)//Çì´õ¿¡ ÁÖ¼®ÀÖÀ½. ºÎ¸Þ¶û µ¹¾Æ¿Ã¶§ ¸Ó½¬·ëÂÊÀ¸·Î °¡¾ßÇØ¼­ ÁÂÇ¥¹ÞÀ½.
{
	move();
}
void sBMR::render(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->spt->frameRender(_viBullet->frameX, 1, 255);
	}
}
void sBMR::fire(int num,float ptx, float pty ,float ang) //¹ß»çÁöÁ¡ ÁÂÇ¥,ÇÃ·¹ÀÌ¾î¿Í °¢µµ±¸ÇØ¼­ ³Ö¾îÁÙ°Í
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	TCHAR strKey[100];
	_stprintf(strKey, L"ÄáÅº%d", num);
	bullet.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"ÄáÅº")->getFileName(), //ÀÌ¹ÌÁö´Â ÀÓ½Ã ÄáÅº
		IMAGEMANAGER->findImage(L"ÄáÅº")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"ÄáÅº")->getMaxFrameY() + 1);


	bullet.angle = ang;
	bullet.speed = 2;// ºÎ¸Þ¶û ¼Óµµ
	backPower = 0.15;//ºÎ¸Þ¶û °¨¼Óµµ Á¶Àý
	bullet.ptX = bullet.fireX = ptx;
	bullet.ptY = bullet.fireY = pty;
	bullet.rc = RectMakeCenter(bullet.ptX, bullet.ptY, 18, 16);//»çÀÌÁî´Â ³ªÁß¿¡ Á¶Àý

	_vBullet.push_back(bullet);
}
void sBMR::move(void)

{
	if (!_em->getvEnemy().empty()) {
		for (int i = 0; i < _em->getvEnemy().size(); i++) {
			if (_em->getvEnemy()[i]->getIndex() == 1) {      //¹ö¼¸Ã£À½
				backX = _em->getvEnemy()[i]->getX();
				backY = _em->getvEnemy()[i]->getY();
				break;
			}
			else {
				//void
			}
		}
	}

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		if (_viBullet->speed > 0) // ¾ÕÀ¸·Î ³ª°¡´Â µ¿¾ÈÀº Ã³À½ ¹ÞÀº ÇÃ·¹ÀÌ¾î ¹æÇâÀ¸·Î¸¸ ³¯¶ó°¨.
		{
			_viBullet->ptX += cos(_viBullet->angle) * _viBullet->speed;
			_viBullet->ptY += -sin(_viBullet->angle) * _viBullet->speed;
			_viBullet->speed -= backPower; // ¼Óµµ¸¦ °¨¼Óµµ ¸¸Å­ ÁÙ¿©ÁÜ.
		}
		if (_viBullet->speed <= 0)
		{			
			_viBullet->angle = getAngle(backX, backY, _viBullet->ptX, _viBullet->ptY); // µ¹¾Æ¿Ã¶§ ¹ö¼¸À» ÇâÇØ µ¹¾Æ°¡¹Ç·Î ¾Þ±Û °»½Å
			_viBullet->ptX += cos(_viBullet->angle) * _viBullet->speed;
			_viBullet->ptY += -sin(_viBullet->angle) * _viBullet->speed;
			_viBullet->speed -= backPower;
		}

		_viBullet->rc = RectMakeCenter(_viBullet->ptX, _viBullet->ptY, 18, 16);

		_viBullet->frameTime += TIMEMANAGER->getElapsedTime();
		if (_viBullet->frameTime >= 0.1f)
		{
			_viBullet->frameTime = 0;

			_viBullet->frameX--;
			if (_viBullet->frameX >= _viBullet->spt->getMaxFrameX()) _viBullet->frameX = 0;
		}

		else ++_viBullet;
	}
}

void sBMR::remove(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}


//====================================================Äá³ª¹°Åº========================================================================
Kongtan::Kongtan(){}
Kongtan::~Kongtan(){}

void Kongtan::init(void)
{

}
void Kongtan::release(void)
{

}
void Kongtan::update(void)
{
	move();
}
void Kongtan::render(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->spt->frameRender(_viBullet->frameX, 1, 255);
	}
}
void Kongtan::fire(int num,float ptx, float pty, float ang)
{
	tagBullet Kongtan;
	ZeroMemory(&Kongtan, sizeof(tagBullet));
	TCHAR strKey[100];
	_stprintf(strKey, L"ÄáÅº%d", num);
	Kongtan.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"ÄáÅº")->getFileName(), //ÀÌ¹ÌÁö´Â ÀÓ½Ã ÄáÅº
		IMAGEMANAGER->findImage(L"ÄáÅº")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"ÄáÅº")->getMaxFrameY() + 1);

	Kongtan.speed = 1.2f;
	Kongtan.ptX = Kongtan.fireX = ptx;
	Kongtan.ptY = Kongtan.fireY = pty;
	Kongtan.spt->setCoord(Kongtan.ptX, Kongtan.ptY);
	Kongtan.angle = ang;
	Kongtan.frameTime = 0;
	Kongtan.frameX = 0;
	Kongtan.rc = RectMakeCenter(Kongtan.ptX, Kongtan.ptY,18,16);
	_vBullet.push_back(Kongtan);
}
void Kongtan::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->ptX += cos(_viBullet->angle) * _viBullet->speed;
		_viBullet->ptY += -sin(_viBullet->angle) * _viBullet->speed;

		_viBullet->spt->setCoord(_viBullet->ptX, _viBullet->ptY);

		_viBullet->rc = RectMakeCenter(_viBullet->ptX, _viBullet->ptY, 18, 16);

		_viBullet->frameTime += TIMEMANAGER->getElapsedTime();
		if (_viBullet->frameTime >= 0.1f)
		{
			_viBullet->frameTime = 0;
			_viBullet->frameX--;
			if (_viBullet->frameX >= _viBullet->spt->getMaxFrameX()) _viBullet->frameX = 0;
		}

	//	if (range < getDistance(_viBullet->ptX, _viBullet->ptY, _viBullet->fireX, _viBullet->fireY))
	//	{
	//		_viBullet = _vBullet.erase(_viBullet);
	//	}
		else ++_viBullet;
	}
}

void Kongtan::remove(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}
