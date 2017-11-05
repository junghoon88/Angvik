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
	eFALL,
	toDeath,
	Death
};

class EnemyMother : public DxWindow
{
protected:
	Sprite* spt;

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
	float amountX;
	float amountY;
	float amountTime;
	float rcHeight;
	int amountHeight;
	int life;

	int probeY;
	int probeX;//���� �ʿ�� ��������?
	int index;//1�� �θ޶�,2�� ���ź
	int frameCnt;
	float frameTime;
	float immuneTime;

	bool isAtk;
	bool isImmune;

	enemyDirection dir;
	enemyState state;

public:

	virtual void init(float x,float y);
	virtual void init(int num, float x, float y, wstring rcKey);
	void release(void);
	virtual void update(void);
	virtual void render(void);
	virtual void RIP(void);

	virtual void move(void);
	virtual bool attack(void);

	inline float getX(void) { return ptX; }
	inline float getY(void) { return ptY; }
	inline int getLife(void) { return life; }
	inline void setLife(int lf) { life = lf; } 
	inline void setState(enemyState estate) { state = estate; }
	inline enemyState getState(void) { return state; }
	inline enemyDirection getDir(void) { return dir; }
	inline RECT getRect(void) { return rc; }
	inline int getIndex(void) { return index; }
	inline bool getAtk(void) { return isAtk; }
	inline void setAtk(bool isatk) { isAtk = isatk; }
	inline void setPlayerX(float x) { playerX = x; }
	inline void setPlayerY(float y) { playerY = y; }
	inline bool getImmune(void) { return isImmune; }
	EnemyMother();
	~EnemyMother();
};