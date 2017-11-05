#include "stdafx.h"
#include "Bullet.h"
#include "EnemyManager.h"

sBMR::sBMR() {}
sBMR::~sBMR() {}

void sBMR::init(void)
{
	budegree = 0;
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
		_viBullet->spt->render();
	}
}
void sBMR::fire(int num,float ptx, float pty ,float ang) //¹ß»çÁöÁ¡ ÁÂÇ¥,ÇÃ·¹ÀÌ¾î¿Í °¢µµ±¸ÇØ¼­ ³Ö¾îÁÙ°Í
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	TCHAR strKey[100];

	_stprintf(strKey, L"¹ö¼¸ºÎ¸Þ¶û%d", num);
	bullet.spt = IMAGEMANAGER->addImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"¹ö¼¸ºÎ¸Þ¶û")->getFileName());
	
	bullet.angle = ang;
	bullet.speed = 9;// ºÎ¸Þ¶û ¼Óµµ
	backPower = 0.3;//ºÎ¸Þ¶û °¨¼Óµµ Á¶Àý
	bullet.ptX = bullet.fireX = ptx;
	bullet.ptY = bullet.fireY = pty;
	bullet.spt->setCoord(bullet.ptX, bullet.ptY);
	bullet.spt->setScale(0.5,0.5);
	bullet.spt->setCenterPer(0.5, 0.5);
	bullet.rc = RectMakeCenter(bullet.ptX, bullet.ptY, 18, 16);//»çÀÌÁî´Â ³ªÁß¿¡ Á¶Àý

	_vBullet.push_back(bullet);
}
void sBMR::move(void)

{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); _viBullet++) {
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
		_viBullet->spt->setRotate(budegree+=20 );
		if (budegree >= 360) {
			budegree = 0;
		}
		_viBullet->spt->setCoord(_viBullet->ptX, _viBullet->ptY);
		_viBullet->rc = RectMakeCenter(_viBullet->ptX, _viBullet->ptY, 18, 16);

		_viBullet->frameTime += TIMEMANAGER->getElapsedTime();
		if (_viBullet->frameTime >= 0.1f)
		{
			_viBullet->frameTime = 0;
			
			_viBullet->frameX++;
			if (_viBullet->frameX >= _viBullet->spt->getMaxFrameX()) _viBullet->frameX = 0;
		}

		if (getDistance(_viBullet->ptX, _viBullet->ptY, backX, backY) <= 10 && _viBullet->speed <= 0) {

			_viBullet = _vBullet.erase(_viBullet);
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
	range = 400;
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

	Kongtan.speed = 2.0f;
	Kongtan.ptX = Kongtan.fireX = ptx;
	Kongtan.ptY = Kongtan.fireY = pty;
	Kongtan.spt->setCoord(Kongtan.ptX, Kongtan.ptY);
	
	Kongtan.angle = ang;
	Kongtan.frameTime = 0;
	Kongtan.frameX = 0;
	Kongtan.spt->setRotate(Kongtan.angle*(180 / PI));
	Kongtan.rc = RectMakeCenter(Kongtan.ptX, Kongtan.ptY,18,16);
	Kongtan.valid = true;

	probeY = Kongtan.ptY;

	_vBullet.push_back(Kongtan);
}
void Kongtan::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->ptX += cos(_viBullet->angle) * _viBullet->speed;
		_viBullet->ptY += -sin(_viBullet->angle) * _viBullet->speed;
		_viBullet->probeY = _viBullet->ptY;
		_viBullet->spt->setCoord(_viBullet->ptX, _viBullet->ptY);
		_viBullet->rc = RectMakeCenter(_viBullet->ptX, _viBullet->ptY, 18, 16);
		_viBullet->frameTime += TIMEMANAGER->getElapsedTime();

		if (_viBullet->frameTime >= 0.2f)
		{
			_viBullet->frameTime = 0;
			_viBullet->frameX++;
			if (_viBullet->frameX >= _viBullet->spt->getMaxFrameX()) _viBullet->frameX = 0;
		}

		for (int i = _viBullet->probeY - 10; i < _viBullet->probeY + 10; ++i)//YÃà Å½Áö
		{
			COLORREF color = PBGMANAGER->getPixelColor(L"Stage1-PBG",(int)_viBullet->ptX, i);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if((r == 0 && g == 0 && b == 0) || (r == 255 && g == 255 && b == 0) || (r == 0 && g == 255 && b == 255))
			{
				_viBullet->valid = false;
				break;
			}
		}

		if (range < getDistance(_viBullet->ptX, _viBullet->ptY, _viBullet->fireX, _viBullet->fireY))
		{
			_viBullet->valid = false;
		}

		if (_viBullet->valid == false)
		{
			_viBullet = _vBullet.erase(_viBullet);

		}
		else ++_viBullet;
	}


}

void Kongtan::remove(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}

//==========================================================ÄáÅº³¡======================================================


Entbeam::Entbeam() {}
Entbeam::~Entbeam() {}

void Entbeam::init(void)
{
	range = 200;
}
void Entbeam::release(void)
{

}
void Entbeam::update(void)
{
	move();
}
void Entbeam::render(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->spt->render();
	}
}
void Entbeam::fire(int num, float ptx, float pty, int dir)
{
	tagBullet EntBeam;
	ZeroMemory(&EntBeam, sizeof(tagBullet));

	EntBeam.ptX = EntBeam.fireX = ptx;
	EntBeam.ptY = EntBeam.fireY = pty;
	EntBeam.spt->setCoord(EntBeam.ptX, EntBeam.ptY);

	if (dir == 0)//¿ÞÂÊ
	{
		for (int i = 0; i < 4; i++)
		{
			float rndang;
			rndang = RND->getFromFloatTo(170, 190);
			EntBeam.angle = Deg2Rad(rndang);

			float rspd;
			rspd = RND->getFromFloatTo(2.0, 3.0);
			EntBeam.speed = rspd;
			
			switch (i)
			{
			case 1:
				TCHAR strKey[100];
				_stprintf(strKey, L"ÀÙ1%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"ÀÙ1")->getFileName(), //ÀÌ¹ÌÁö´Â ÀÓ½Ã ÄáÅº
					IMAGEMANAGER->findImage(L"ÀÙ1")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"ÀÙ1")->getMaxFrameY() + 1);
				break;
			case 2:
				TCHAR strKey2[100];
				_stprintf(strKey2, L"ÀÙ2%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey2, IMAGEMANAGER->findImage(L"ÀÙ2")->getFileName(), //ÀÌ¹ÌÁö´Â ÀÓ½Ã ÄáÅº
					IMAGEMANAGER->findImage(L"ÀÙ2")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"ÀÙ2")->getMaxFrameY() + 1);
				break;
			case 3:
				TCHAR strKey3[100];
				_stprintf(strKey3, L"ÀÙ3%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey3, IMAGEMANAGER->findImage(L"ÀÙ3")->getFileName(), //ÀÌ¹ÌÁö´Â ÀÓ½Ã ÄáÅº
					IMAGEMANAGER->findImage(L"ÀÙ3")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"ÀÙ3")->getMaxFrameY() + 1);
				break;
			case 4:
				TCHAR strKey4[100];
				_stprintf(strKey4, L"ÀÙ4%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey4, IMAGEMANAGER->findImage(L"ÀÙ4")->getFileName(), //ÀÌ¹ÌÁö´Â ÀÓ½Ã ÄáÅº
					IMAGEMANAGER->findImage(L"ÀÙ4")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"ÀÙ4")->getMaxFrameY() + 1);
				break;
			default:break;
			}
			EntBeam.spt->setRotate(Rad2Deg(EntBeam.angle));
			EntBeam.rc = RectMakeCenter(EntBeam.ptX, EntBeam.ptY, 15, 15);

			EntBeam.valid = true;

			probeY = EntBeam.ptY;

			_vBullet.push_back(EntBeam);
		}
	}
	if (dir == 1)//¿ÞÂÊ
	{
		for (int i = 0; i < 4; i++)
		{
			float rndang;
			rndang = RND->getFromFloatTo(-10, 10);
			EntBeam.angle = Deg2Rad(rndang);

			float rspd;
			rspd = RND->getFromFloatTo(2.0, 3.0);
			EntBeam.speed = rspd;

			switch (i)
			{
			case 1:
				TCHAR strKey[100];
				_stprintf(strKey, L"ÀÙ1%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"ÀÙ1")->getFileName(), //ÀÌ¹ÌÁö´Â ÀÓ½Ã ÄáÅº
					IMAGEMANAGER->findImage(L"ÀÙ1")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"ÀÙ1")->getMaxFrameY() + 1);
				break;
			case 2:
				TCHAR strKey2[100];
				_stprintf(strKey2, L"ÀÙ2%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey2, IMAGEMANAGER->findImage(L"ÀÙ2")->getFileName(), //ÀÌ¹ÌÁö´Â ÀÓ½Ã ÄáÅº
					IMAGEMANAGER->findImage(L"ÀÙ2")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"ÀÙ2")->getMaxFrameY() + 1);
				break;
			case 3:
				TCHAR strKey3[100];
				_stprintf(strKey3, L"ÀÙ3%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey3, IMAGEMANAGER->findImage(L"ÀÙ3")->getFileName(), //ÀÌ¹ÌÁö´Â ÀÓ½Ã ÄáÅº
					IMAGEMANAGER->findImage(L"ÀÙ3")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"ÀÙ3")->getMaxFrameY() + 1);
				break;
			case 4:
				TCHAR strKey4[100];
				_stprintf(strKey4, L"ÀÙ4%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey4, IMAGEMANAGER->findImage(L"ÀÙ4")->getFileName(), //ÀÌ¹ÌÁö´Â ÀÓ½Ã ÄáÅº
					IMAGEMANAGER->findImage(L"ÀÙ4")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"ÀÙ4")->getMaxFrameY() + 1);
				break;
			default:break;
			}
			EntBeam.spt->setRotate(Rad2Deg(EntBeam.angle));
			EntBeam.rc = RectMakeCenter(EntBeam.ptX, EntBeam.ptY, 15, 15);

			EntBeam.valid = true;

			probeY = EntBeam.ptY;

			_vBullet.push_back(EntBeam);
		}
	}




}
void Entbeam::move(void)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->ptX += cos(_viBullet->angle) * _viBullet->speed;
		_viBullet->ptY += -sin(_viBullet->angle) * _viBullet->speed;
		_viBullet->probeY = _viBullet->ptY;
		_viBullet->spt->setCoord(_viBullet->ptX, _viBullet->ptY);
		_viBullet->rc = RectMakeCenter(_viBullet->ptX, _viBullet->ptY, 15, 15);


		if (range < getDistance(_viBullet->ptX, _viBullet->ptY, _viBullet->fireX, _viBullet->fireY))
		{
			_viBullet->valid = false;
		}

		if (_viBullet->valid == false)
		{
			_viBullet = _vBullet.erase(_viBullet);

		}
		else ++_viBullet;
	}


}

void Entbeam::remove(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}