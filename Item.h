#pragma once
#include "DxWindow.h"
#include "pixelCollision.h"




enum ITEM_TYPE
{
	ITEM_TYPE_SWORD,		//����-��
	ITEM_TYPE_LANCE,		//����-â
	ITEM_TYPE_BOOMERANG,	//����-�θ޶�
	ITEM_TYPE_STAFF,		//����-������
	ITEM_TYPE_HEAD,			//��-�Ӹ�
	ITEM_TYPE_BODY,			//��-����
	ITEM_TYPE_FOOT,			//��-�Ź�
	ITEM_TYPE_OIL,			//���� - ����
	ITEM_TYPE_EGG,			//���� - ��

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
	
	ITEM_STATE_IDLE,		//�⺻
	ITEM_STATE_INPLAYER,	//�÷��̾� 
	ITEM_STATE_ATTACK,		//�÷��̾� ����
	ITEM_STATE_ININVEN
};

class Item : public DxWindow
{
private:
	Sprite* _img;

	int _num;
	
	ITEM_TYPE _type;
	ITEM_KIND _kind;
	ITEM_STATE _state;

	int _durability; // ������
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
	
	float targetX;
	float targetY;

	bool isarm;
	bool isPlayerRIGHT;
public:
	Item();
	~Item();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

	inline void setPoint(float x, float y) { _pt.set(x, y); }
	inline void targetPlayer(float x, float y) { targetX = x; targetY = y; }
	inline void setPt(MYPOINT pt) { _pt = pt; }

	//������Ÿ�� �ټ�
	inline Sprite* getImage(void) { return _img; }

	inline void setNum(int num) { _num = num; }
	inline int getNum(void) { return _num; }
	inline void setType(ITEM_TYPE type) { _type = type; }
	inline ITEM_TYPE getType(void) { return _type; }
	
	inline void setisPlayerRIGHT(bool right) { isPlayerRIGHT = right; }
	inline void setisPlayerARM(bool arm) { isarm = arm; }
	//���� �ټ�
	inline void setKind(ITEM_KIND kind) { _kind = kind; }
	inline ITEM_KIND getKind(void) { return _kind; }
	
	//���� �ټ�
	inline void setState(ITEM_STATE state) { _state = state; }
	inline ITEM_STATE getState(void) { return _state; }

	//�����ۻ���
	void createItem(ITEM_TYPE type, ITEM_KIND kind, ITEM_STATE state, float x, float y);
	

	
	//�ޱ� �ټ�
	inline void setAngle(float angle) { angleDeg = angle; }
	inline float getAngle(void) { return angleDeg; }
	//������ �浹��Ʈ
	inline RECT getrcImg(void) { return _rcImg; }
	inline RECT getHitImg(void) { return _rcHit; }
	//������ �ټ�
	inline void setdurability(int durability) { _durability = durability; }
	inline int getdurability(void) { return _durability; }
	inline void setdurabilityMax(void) { _durability = _durabilityMax; }

	

};

