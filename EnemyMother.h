#pragma once
#include "DxWindow.h"
enum enemyDirection {
	eLEFT,
	eRIGHT
};
enum enemyState
{
	eIDLE,
	eATK,
	eJUMP,
	eFALL
};

class EnemyMother : public DxWindow
{
protected:
	Sprite* spt;
	Rect* rct;
	wstring rcName;     //��Ʈ Ű����
	RECT rc;
	RECT sptrc;//�Ⱦ��ŵ� ��. ���� �̹��� �׸����� �߰��մϴ�.
	float ptX;
	float ptY;
	float playerX;
	float playerY;
	float speed;
	float jumpPower;
	float gravity;
	int life;

	int probeY;
	int probeX;//���� �ʿ�� ��������?
	int index;
	int frameCnt;
	float frameTime;

	enemyDirection dir;
	enemyState state;

public:

	virtual void init(float x,float y);
	virtual void init(int num, float x, float y, wstring rcKey);
	void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void move(void);
	virtual bool attack(void);

	inline float getX(void) { return ptX; }
	inline float getY(void) { return ptY; }
	inline int getLife(void) { return life; }
	void setLife(int hit) { life -= hit; } //������ ���ÿ�.���ط� ��ŭ ������ ����
	inline enemyState getState(void) { return state; }
	inline RECT getRect(void) { return rc; }
	inline int getIndex(void) { return index; }
	inline void setPlayerX(float x) { playerX = x; }
	inline void setPlayerY(float y) { playerY = y; }
	EnemyMother();
	~EnemyMother();
};

