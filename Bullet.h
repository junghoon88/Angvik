#pragma once
#include "DxWindow.h"
#include <vector>

class EnemyManager;

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
};

class sBMR : public DxWindow
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float backPower;//�θ޶� ���ӵ�

	float backX;
	float backY;

	EnemyManager* _em;

public:
	void init(void);
	void release(void);
<<<<<<< HEAD
	void update(void); //�ӽ��� ��ġ�� �ǵ��ư��ߵǴϱ� �ӽ��� ��ǥ�� �޾ƾ���.
	void render(void);

	void fire(int num,float ptx, float pty, float ang); // ���ޱ۷� ang �־��ָ� �÷��̾� �������� �߽�!
	void move();//������Ʈ���� �ӽ��� ��ġ �޾ƿ��°���
=======
	void update(void); 
	void render(void);

	void fire(int num,float ptx, float pty, float ang); // ���ޱ۷� ang �־��ָ� �÷��̾� �������� �߽�!
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