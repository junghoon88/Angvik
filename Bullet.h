#pragma once
#include "DxWindow.h"
#include <vector>

class EnemyManager;

struct tagBullet
{
	RECT rc;
	Sprite* spt;
	float speed;
	float ptX, ptY;//투사체 좌표
	float fireX, fireY;//투사체 시작지점
	int probeX, probeY;//픽셀충돌용
	float angle;

	int frameX;
	float frameTime;
};

class sBMR : public DxWindow
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float backPower;//부메랑 감속도

	float backX;
	float backY;

	EnemyManager* _em;

public:
	void init(void);
	void release(void);
<<<<<<< HEAD
	void update(void); //머쉬룸 위치로 되돌아가야되니까 머쉬룸 좌표를 받아야함.
	void render(void);

	void fire(int num,float ptx, float pty, float ang); // 갯앵글로 ang 넣어주면 플레이어 방향으로 발싸!
	void move();//업데이트에서 머쉬룸 위치 받아오는거임
=======
	void update(void); 
	void render(void);

	void fire(int num,float ptx, float pty, float ang); // 갯앵글로 ang 넣어주면 플레이어 방향으로 발싸!
	void move(void);
>>>>>>> 54bec3f0509c3d83560e975f3d19db5d525b3db3
	void remove(int arrNum);
	vector<tagBullet> getVBullet(void) { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet(void) { return _viBullet; }

	inline void setLinkAdressEnemyManager(EnemyManager *em) { _em = em; }

	sBMR();
	~sBMR();
};

class Kongtan : public DxWindow
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float range;

public:
	void init(void);
	void release(void);
	void update(void);
	void render(void);

	void fire(int num,float ptx, float pty, float ang);
	void move(void);
	void remove(int arrNum);
	vector<tagBullet> getVBullet(void) { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet(void) { return _viBullet; }

	Kongtan();
	~Kongtan();
};