#include "stdafx.h"
#include "pixelCollision.h"


pixelCollision::pixelCollision()
	: _imgPBG(NULL)
	, _isGround(FALSE)		//������ �ִ���?
	, _isWall(FALSE)		//���� �ε�������?
	, _isTrap(FALSE)		//Ʈ���� �ɷȴ���?
{
	int stage = STAGE;
	TCHAR str[128];
	_stprintf(str, L"Stage%d-PBG", stage);
	_imgPBG = PBGMANAGER->findImage(str);
}


pixelCollision::~pixelCollision()
{
}

void pixelCollision::init(void)
{

}
void pixelCollision::release(void)
{

}
void pixelCollision::update(void)
{

}
void pixelCollision::render(void)
{

}

