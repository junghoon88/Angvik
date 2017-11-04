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
void sBMR::update(void)//헤더에 주석있음. 부메랑 돌아올때 머쉬룸쪽으로 가야해서 좌표받음.
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
void sBMR::fire(int num,float ptx, float pty ,float ang) //발사지점 좌표,플레이어와 각도구해서 넣어줄것
{
	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	TCHAR strKey[100];
	_stprintf(strKey, L"버섯부메랑%d", num);
	bullet.spt = IMAGEMANAGER->addImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"버섯부메랑")->getFileName());
	

	bullet.angle = ang;
	bullet.speed = 11;// 부메랑 속도
	backPower = 0.3;//부메랑 감속도 조절
	bullet.ptX = bullet.fireX = ptx;
	bullet.ptY = bullet.fireY = pty;
	bullet.spt->setCoord(bullet.ptX, bullet.ptY);
	bullet.spt->setScale(0.5,0.5);
	bullet.rc = RectMakeCenter(bullet.ptX, bullet.ptY, 18, 16);//사이즈는 나중에 조절
	
	_vBullet.push_back(bullet);
}
void sBMR::move(void)

{
	if (!_em->getvEnemy().empty()) {
		for (int i = 0; i < _em->getvEnemy().size(); i++) {
			if (_em->getvEnemy()[i]->getIndex() == 1) {      //버섯찾음
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
		if (_viBullet->speed > 0) // 앞으로 나가는 동안은 처음 받은 플레이어 방향으로만 날라감.
		{
			_viBullet->ptX += cos(_viBullet->angle) * _viBullet->speed;
			_viBullet->ptY += -sin(_viBullet->angle) * _viBullet->speed;
			_viBullet->speed -= backPower; // 속도를 감속도 만큼 줄여줌.
		}
		if (_viBullet->speed <= 0)
		{			
			_viBullet->angle = getAngle(backX, backY, _viBullet->ptX, _viBullet->ptY); // 돌아올때 버섯을 향해 돌아가므로 앵글 갱신
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


//====================================================콩나물탄========================================================================
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
	_stprintf(strKey, L"콩탄%d", num);
	Kongtan.spt = IMAGEMANAGER->addFrameImage(DEVICE, strKey, IMAGEMANAGER->findImage(L"콩탄")->getFileName(), //이미지는 임시 콩탄
		IMAGEMANAGER->findImage(L"콩탄")->getMaxFrameX() + 1,
		IMAGEMANAGER->findImage(L"콩탄")->getMaxFrameY() + 1);

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
