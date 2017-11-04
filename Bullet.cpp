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
	bullet.speed = 11;// �θ޶� �ӵ�
	backPower = 0.3;//�θ޶� ���ӵ� ����
	bullet.ptX = bullet.fireX = ptx;
	bullet.ptY = bullet.fireY = pty;
	bullet.spt->setCoord(bullet.ptX, bullet.ptY);
	bullet.spt->setScale(0.5,0.5);
	bullet.rc = RectMakeCenter(bullet.ptX, bullet.ptY, 18, 16);//������� ���߿� ����
	
	_vBullet.push_back(bullet);
}
void sBMR::move(void)

{
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
