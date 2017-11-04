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
	wstring rcName;     //렉트 키네임
	RECT rc;
	RECT sptrc;//안쓰셔도 됨. 저는 이미지 그릴려고 추가합니다.
	float ptX;
	float ptY;
	float playerX;
	float playerY;
	float speed;
	float jumpPower;
	float gravity;
	int life;

	int probeY;
	int probeX;//딱히 필요는 없을지도?
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
	void setLife(int hit) { life -= hit; } //라이프 셋팅용.피해량 만큼 라이프 감소
	inline enemyState getState(void) { return state; }
	inline RECT getRect(void) { return rc; }
	inline int getIndex(void) { return index; }
	inline void setPlayerX(float x) { playerX = x; }
	inline void setPlayerY(float y) { playerY = y; }
	EnemyMother();
	~EnemyMother();
};

