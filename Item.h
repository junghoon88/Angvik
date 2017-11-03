#pragma once
#include "DxWindow.h"

enum ITEM_TYPE
{
	ITEM_TYPE_SWORD,		//����-��
	ITEM_TYPE_LENCE,		//����-â
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
	ITEM_STATE_ATTACK		//�÷��̾� ����
};

class Item : public DxWindow
{
private:
	Sprite* _img;
	
	ITEM_TYPE _type;
	ITEM_KIND _kind;
	ITEM_STATE _state;

	int _durability; // ������

	//debug
	int frameCnt;
	float frameTime;
	float angleDeg;

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

	void createItem(ITEM_TYPE type, ITEM_KIND kind, ITEM_STATE state, float x, float y);

};

