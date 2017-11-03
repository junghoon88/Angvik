#pragma once
#include "DxWindow.h"
#include <vector>

struct tagBullet
{
	RECT rc;
	Sprite* spt;
	float speed;
	float ptX, ptY;//����ü ��ǥ
	float fireX, fireY;//����ü ��������
	int probeX, probeY;//�ȼ��浹��
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

public:
	void init(void);
	void release(void);
	void update(float x, float y);
	void render(void);

	void fire(float ptx, float pty, float ang);
	void move(float x,float y);
	void remove(int arrNum);
	vector<tagBullet> getVBullet(void) { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet(void) { return _viBullet; }

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

	void fire(float ptx, float pty, float ang);
	void move(void);
	void remove(int arrNum);
	vector<tagBullet> getVBullet(void) { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet(void) { return _viBullet; }

	Kong();
	~Kong();
};