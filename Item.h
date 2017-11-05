#pragma once
#include "DxWindow.h"
#include "pixelCollision.h"

enum ITEM_TYPE
{
	ITEM_TYPE_SWORD,		//무기-검
	ITEM_TYPE_LANCE,		//무기-창
	ITEM_TYPE_BOOMERANG,	//무기-부메랑
	ITEM_TYPE_STAFF,		//무기-지팡이
	ITEM_TYPE_HEAD,			//방어구-머리
	ITEM_TYPE_BODY,			//방어구-갑옷
	ITEM_TYPE_FOOT,			//방어구-신발
	ITEM_TYPE_OIL,			//잡템 - 오일
	ITEM_TYPE_EGG,			//잡템 - 알

	ITEM_TYPE_MAX
};

enum ITEM_KIND
{
	ITEM_KIND_WHITE,
	ITEM_KIND_BLACK,
	ITEM_KIND_GOLD,

	ITEM_KIND_MAX
};

enum ITEM_STATE
{
	
	ITEM_STATE_IDLE,		//기본
	ITEM_STATE_INPLAYER,	//플레이어 
	ITEM_STATE_ATTACK,		//플레이어 공격
	ITEM_STATE_ININVEN
};

class Item : public DxWindow
{
private:
	Sprite* _img;
	
	ITEM_TYPE _type;
	ITEM_KIND _kind;
	ITEM_STATE _state;

	int _durability; // 내구도
	int _durabilityMax;

	//debug
	int frameCnt;
	float frameTime;
	float angleDeg;
	pixelCollision* itemCollision;

	int probeY;
	MYPOINT	_pt;
	RECT _rcImg;
	RECT _rcHit;



public:
	Item();
	~Item();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
	
	//아이템타입 겟셋
	inline void setType(ITEM_TYPE type) { _type = type; }
	inline ITEM_TYPE getType(void) { return _type; }
	
	//종류 겟셋
	inline void setKind(ITEM_KIND kind) { _kind = kind; }
	inline ITEM_KIND getKind(void) { return _kind; }
	
	//상태 겟셋
	inline void setState(ITEM_STATE state) { _state = state; }
	inline ITEM_STATE getState(void) { return _state; }

	//아이템생성
	void createItem(ITEM_TYPE type, ITEM_KIND kind, ITEM_STATE state, float x, float y);
	
	//아이템 충돌렉트
	inline RECT getrcImg(void) { return _rcImg; }
	//내구도 겟셋
	inline void setdurability(int durability) { _durability = durability; }
	inline int getdurability(void) { return _durability; }
	inline void setdurabilityMax(void) { _durability = _durabilityMax; }

	

};

