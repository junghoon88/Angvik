#include "stdafx.h"
#include "Bullet.h"

sBMR::sBMR() {}
sBMR::~sBMR() {}

void sBMR::init(void)
{

}
void sBMR::release(void)
{

}
void sBMR::update(float mushroomX, float mushroomy)//����� �ּ�����. �θ޶� ���ƿö� �ӽ��������� �����ؼ� ��ǥ����.
{
	move(mushroomX, mushroomy);
}
void sBMR::render(void)	
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->spt->frameRender(_viBullet->frameX, 1, 255);
	}
}
void sBMR::fire(int num,float ptx, float pty ,float ang) //�߻����� ��ǥ,�÷��̾�� �������ؼ� �־��ٰ�
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	TCHAR strKey[100];
	_stprintf(strKey, L"��ź%d", num);
	bullet.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"��ź")->getFileName(), //�̹����� �ӽ� ��ź
		IMAGEMANAGER->findImage(L"��ź")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"��ź")->getMaxFrameY() + 1);


	bullet.angle = ang;
	bullet.speed = 2;// �θ޶� �ӵ�
	backPower = 0.15;//�θ޶� ���ӵ� ����
	bullet.ptX = bullet.fireX = ptx;
	bullet.ptY = bullet.fireY = pty;
	bullet.rc = RectMakeCenter(bullet.ptX, bullet.ptY, 18, 16);//������� ���߿� ����

	_vBullet.push_back(bullet);
}
void sBMR::move(float x,float y)
{
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
			_viBullet->angle = getAngle(x, y, _viBullet->ptX, _viBullet->ptY); // ���ƿö� ������ ���� ���ư��Ƿ� �ޱ� ����
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


//====================================================�ᳪ��ź========================================================================
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
		_viBullet->spt->frameRender(_viBullet->frameX, 1, 255);//������ ���� �߰��ؾ���
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
	Kongtan.speed = 1.2f;
	Kongtan.ptX = Kongtan.fireX = ptx;
	Kongtan.ptY = Kongtan.fireY = pty;
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

		_viBullet->rc = RectMakeCenter(_viBullet->ptX, _viBullet->ptY, 18, 16);

		_viBullet->frameTime += TIMEMANAGER->getElapsedTime();
		if (_viBullet->frameTime >= 0.1f)
		{
			_viBullet->frameTime = 0;

			_viBullet->frameX--;
			if (_viBullet->frameX >= _viBullet->spt->getMaxFrameX()) _viBullet->frameX = 0;
		}

		if (range < getDistance(_viBullet->ptX, _viBullet->ptY, _viBullet->fireX, _viBullet->fireY))
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
