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
	wstring rcName;     //렉트 키네임
	RECT rc;
	RECT sptrc;//안쓰셔도 됨. 저는 이미지 그릴려고 추가합니다.
	float ptX;
	float ptY;
	float speed;
	float jumpPower;
	float gravity;
	int life;

	int probeY;
	int probeX;//딱히 필요는 없을지도?

	int frameCnt;
	float frameTime;

	enemyDirection dir;
	enemyState state;

public:

	virtual void init(float x,float y);
	virtual void init(float x, float y, wstring rcKey);
	void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void move(void);
	virtual void attack(void);

	inline float getX(void) { return ptX; }
	inline float getY(void) { return ptY; }
	inline int getLife(void) { return life; }
	void setLife(int hit) { life -= hit; } //라이프 셋팅용.피해량 만큼 라이프 감소
	inline enemyState getState(void) { return state; }
	inline RECT getRect(void) { return rc; }


	EnemyMother();
	~EnemyMother();
};

