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

	bool isShoot;
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
	void update(void); 
	void render(void);

	void fire(int num,float ptx, float pty, float ang); // 갯앵글로 ang 넣어주면 플레이어 방향으로 발싸!
	void move(void);
	void remove(int arrNum);
	vector<tagBullet> getVBullet(void) { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet(void) { return _viBullet; }

	inline void setLinkAdressEnemyManager(EnemyManager *em) { _em = em; }

	sBMR();
	~sBMR();
};

class Kong : public DxWindow
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

	Kong();
	~Kong();
};