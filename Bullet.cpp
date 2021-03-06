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
void sBMR::update(void)//����� �ּ�����. �θ޶� ���ƿö� �ӽ��������� �����ؼ� ��ǥ����.
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
void sBMR::fire(int num,float ptx, float pty ,float ang) //�߻����� ��ǥ,�÷��̾�� �������ؼ� �־��ٰ�
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	TCHAR strKey[100];

	_stprintf(strKey, L"�����θ޶�%d", num);
	bullet.spt = IMAGEMANAGER->addImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"�����θ޶�")->getFileName());
	
	bullet.angle = ang;
	bullet.speed = 9;// �θ޶� �ӵ�
	backPower = 0.3;//�θ޶� ���ӵ� ����
	bullet.ptX = bullet.fireX = ptx;
	bullet.ptY = bullet.fireY = pty;
	bullet.spt->setCoord(bullet.ptX, bullet.ptY);
	bullet.spt->setScale(0.5,0.5);
	bullet.spt->setCenterPer(0.5, 0.5);
	bullet.rc = RectMakeCenter(bullet.ptX, bullet.ptY, 18, 16);//������� ���߿� ����

	_vBullet.push_back(bullet);
}
void sBMR::move(void)

{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); _viBullet++) {
		if (!_em->getvEnemy().empty()) {
			for (int i = 0; i < _em->getvEnemy().size(); i++) {
				if (_em->getvEnemy()[i]->getIndex() == 1) {      //����ã��
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
		if (_viBullet->speed > 0) // ������ ������ ������ ó�� ���� �÷��̾� �������θ� ����.
		{
			_viBullet->ptX += cos(_viBullet->angle) * _viBullet->speed;
			_viBullet->ptY += -sin(_viBullet->angle) * _viBullet->speed;
			_viBullet->speed -= backPower; // �ӵ��� ���ӵ� ��ŭ �ٿ���.
		}
		if (_viBullet->speed <= 0)
		{			
			_viBullet->angle = getAngle(backX, backY, _viBullet->ptX, _viBullet->ptY); // ���ƿö� ������ ���� ���ư��Ƿ� �ޱ� ����
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


//====================================================�ᳪ��ź========================================================================
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
	_stprintf(strKey, L"��ź%d", num);
	Kongtan.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"��ź")->getFileName(), //�̹����� �ӽ� ��ź
		IMAGEMANAGER->findImage(L"��ź")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"��ź")->getMaxFrameY() + 1);

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

		for (int i = _viBullet->probeY - 10; i < _viBullet->probeY + 10; ++i)//Y�� Ž��
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

//==========================================================��ź��======================================================


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

	if (dir == 0)//����
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
				_stprintf(strKey, L"��1%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"��1")->getFileName(), //�̹����� �ӽ� ��ź
					IMAGEMANAGER->findImage(L"��1")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"��1")->getMaxFrameY() + 1);
				break;
			case 2:
				TCHAR strKey2[100];
				_stprintf(strKey2, L"��2%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey2, IMAGEMANAGER->findImage(L"��2")->getFileName(), //�̹����� �ӽ� ��ź
					IMAGEMANAGER->findImage(L"��2")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"��2")->getMaxFrameY() + 1);
				break;
			case 3:
				TCHAR strKey3[100];
				_stprintf(strKey3, L"��3%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey3, IMAGEMANAGER->findImage(L"��3")->getFileName(), //�̹����� �ӽ� ��ź
					IMAGEMANAGER->findImage(L"��3")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"��3")->getMaxFrameY() + 1);
				break;
			case 4:
				TCHAR strKey4[100];
				_stprintf(strKey4, L"��4%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey4, IMAGEMANAGER->findImage(L"��4")->getFileName(), //�̹����� �ӽ� ��ź
					IMAGEMANAGER->findImage(L"��4")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"��4")->getMaxFrameY() + 1);
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
	if (dir == 1)//����
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
				_stprintf(strKey, L"��1%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"��1")->getFileName(), //�̹����� �ӽ� ��ź
					IMAGEMANAGER->findImage(L"��1")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"��1")->getMaxFrameY() + 1);
				break;
			case 2:
				TCHAR strKey2[100];
				_stprintf(strKey2, L"��2%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey2, IMAGEMANAGER->findImage(L"��2")->getFileName(), //�̹����� �ӽ� ��ź
					IMAGEMANAGER->findImage(L"��2")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"��2")->getMaxFrameY() + 1);
				break;
			case 3:
				TCHAR strKey3[100];
				_stprintf(strKey3, L"��3%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey3, IMAGEMANAGER->findImage(L"��3")->getFileName(), //�̹����� �ӽ� ��ź
					IMAGEMANAGER->findImage(L"��3")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"��3")->getMaxFrameY() + 1);
				break;
			case 4:
				TCHAR strKey4[100];
				_stprintf(strKey4, L"��4%d", num);
				EntBeam.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey4, IMAGEMANAGER->findImage(L"��4")->getFileName(), //�̹����� �ӽ� ��ź
					IMAGEMANAGER->findImage(L"��4")->getMaxFrameX() + 1,
					IMAGEMANAGER->findImage(L"��4")->getMaxFrameY() + 1);
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