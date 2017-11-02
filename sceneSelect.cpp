#include "stdafx.h"
#include "sceneSelect.h"


sceneSelect::sceneSelect()
{
}


sceneSelect::~sceneSelect()
{
}


void sceneSelect::init(void)
{
	//�޴� ����Ʈ ����
	_setSelect[0] = { 215, 375 };
	_setSelect[1] = { 415, 375 };
	_setSelect[2] = { 615, 375 };

	_setOptionSelect[0] = { 204, 175 };
	_setOptionSelect[1] = { 204, 212 };
	_setOptionSelect[2] = { 204, 247 };

	_setVolume[0] = { 472, 175 };
	_setVolume[1] = { 532, 175 };
	_setVolume[2] = { 592, 175 };
	_setVolume[3] = { 652, 175 };
	_setVolume[4] = { 712, 175 };

	_setMusic[0] = { 532, 210 };
	_setMusic[1] = { 472, 210 };

	//�̹��� ��ǥ ����
	IMAGEMANAGER->findImage(L"0")->setCoord({ 497, 185 });
	IMAGEMANAGER->findImage(L"25")->setCoord({ 552, 185 });
	IMAGEMANAGER->findImage(L"50")->setCoord({ 612, 185 });
	IMAGEMANAGER->findImage(L"75")->setCoord({ 672, 185 });
	IMAGEMANAGER->findImage(L"100")->setCoord({ 727, 185 });
	IMAGEMANAGER->findImage(L"on")->setCoord({ 552, 225 });
	IMAGEMANAGER->findImage(L"off")->setCoord({ 487, 220 });
	IMAGEMANAGER->findImage(L"start")->setCoord({ 265, 385 });
	IMAGEMANAGER->findImage(L"options")->setCoord({ 455, 385 });
	IMAGEMANAGER->findImage(L"exit")->setCoord({ 675, 385 });
	IMAGEMANAGER->findImage(L"����")->setCoord(_setSelect[0]);
	IMAGEMANAGER->findImage(L"�޴���")->setCoord({ 0, 374 });
	IMAGEMANAGER->findImage(L"�ɼǸ޴�")->setCoord({ 200, 174 });
	IMAGEMANAGER->findImage(L"volume")->setCoord({ 255, 185 });
	IMAGEMANAGER->findImage(L"music")->setCoord({ 260, 222 });
	IMAGEMANAGER->findImage(L"back")->setCoord({ 265, 255 });
	IMAGEMANAGER->findImage(L"selectVolume")->setCoord(_setVolume[4]);
	IMAGEMANAGER->findImage(L"selectMusic")->setCoord(_setMusic[1]);
	IMAGEMANAGER->findImage(L"�ΰ�")->setCoord({ 320, 150 });

	_frameX = 0;
	_countTime = 0;
	_selectNum = 0;
	_selectVolume = 4;

	_volume = DATABASE->getVolume();
	_isMute = DATABASE->getMute();

	_isOption = false;
	_isStart = false;
	_musicStart = false;
}

void sceneSelect::release(void)
{

}

void sceneSelect::update(void)
{
	DATABASE->setVolume(_volume);
	DATABASE->setMute(_isMute);
	
	_mainCamera.x = 0;
	_mainCamera.y = 0;

	if (!_musicStart)
	{
		if(SOUNDMANAGER->isPlaySound(L"stage1bgm"))
		{
			SOUNDMANAGER->stop(L"stage1bgm");
		}
		if (!SOUNDMANAGER->isPlaySound(L"�޴����"))
		{
			SOUNDMANAGER->play(L"�޴����", _volume);
		}
		_musicStart = true;
	}

	_countTime += TIMEMANAGER->getElapsedTime();
	if (_countTime >= 0.07)
	{
		_frameX++;
		_countTime = 0;
	}
	if (_frameX > IMAGEMANAGER->findImage(L"����")->getMaxFrameX()) _frameX = 0;

	if (!_isOption)
	{
		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_LEFT))
		{
			_selectNum--;
			if (_selectNum < 0) _selectNum = 2;

			//SOUNDMANAGER->play(L"�޴��̵�", _volume);
		}
		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_RIGHT))
		{
			_selectNum++;
			if (_selectNum == 3) _selectNum = 0;

			//SOUNDMANAGER->play(L"�޴��̵�", _volume);
		}
		if (_selectNum == 0 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			//SOUNDMANAGER->play(L"�޴�����", _volume);
			_isStart = true;
			DATABASE->setGameStart(_isStart);

			if (SOUNDMANAGER->isPlaySound(L"�޴����"))
			{
				SOUNDMANAGER->stop(L"�޴����");
			}

			_musicStart = false;
		}
		if (_selectNum == 1 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			_selectNum = 0;
			_isOption = true;
			//SOUNDMANAGER->play(L"�޴�����", _volume);
		}
		if (_selectNum == 2 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			PostQuitMessage(0);
			//SOUNDMANAGER->play(L"�޴�����", _volume);
		}

		IMAGEMANAGER->findImage(L"����")->setCoord(_setSelect[_selectNum]);
	}

	//�ɼ�
	else
	{
		//�̵�
		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_UP))
		{
			_selectNum--;
			if (_selectNum < 0) _selectNum = 2;
			//SOUNDMANAGER->play(L"�޴��̵�", _volume);
		}
		if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_DOWN))
		{
			_selectNum++;
			if (_selectNum == 3) _selectNum = 0;
			//SOUNDMANAGER->play(L"�޴��̵�", _volume);
		}
		if (_selectNum == 2 && KEYMANAGER->isOnceKeyDown(BTN_PLAYER_FRONT_HAND))
		{
			_selectNum = 1;
			_isOption = false;
			//SOUNDMANAGER->play(L"�޴�����", _volume);
		}

		//��������
		if (_selectNum == 0)
		{
			if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_LEFT))
			{
				_selectVolume--;
				if (_selectVolume < 0) _selectVolume = 4;
				_volume = (float)_selectVolume * 0.25;
				//SOUNDMANAGER->play(L"�޴��̵�", _volume);

				SOUNDMANAGER->setVolume(_volume);
			}
			if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_RIGHT))
			{
				_selectVolume++;
				if (_selectVolume == 5) _selectVolume = 0;
				_volume = (float)_selectVolume * 0.25;
				//SOUNDMANAGER->play(L"�޴��̵�", _volume);

				SOUNDMANAGER->setVolume(_volume);
			}
		}

		//����� ���� ����
		if (_selectNum == 1)
		{
			bool oldMute = _isMute;
			if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_LEFT))
			{
				if (_isMute) _isMute = false;
				else _isMute = true;
				//SOUNDMANAGER->play(L"�޴��̵�", _volume);

				SOUNDMANAGER->setMuteAll(_isMute);
			}
			if (KEYMANAGER->isOnceKeyDown(BTN_PLAYER_RIGHT))
			{
				if (_isMute) _isMute = false;
				else _isMute = true;
				//SOUNDMANAGER->play(L"�޴��̵�", _volume);

				SOUNDMANAGER->setMuteAll(_isMute);
			}
		}

		IMAGEMANAGER->findImage(L"����")->setCoord(_setOptionSelect[_selectNum]);
		IMAGEMANAGER->findImage(L"selectVolume")->setCoord(_setVolume[_selectVolume]);
		IMAGEMANAGER->findImage(L"selectMusic")->setCoord(_setMusic[_isMute]);
	}

	
}

void sceneSelect::render(void)
{
	IMAGEMANAGER->findImage(L"���ι��")->render();
	if (!_isOption) IMAGEMANAGER->findImage(L"�޴���")->render();
	else IMAGEMANAGER->findImage(L"�ɼǸ޴�")->render();
	IMAGEMANAGER->findImage(L"����")->frameRender(_frameX, 0);
	if (!_isOption)
	{
		IMAGEMANAGER->findImage(L"�ΰ�")->render();
		IMAGEMANAGER->findImage(L"start")->render();
		IMAGEMANAGER->findImage(L"options")->render();
		IMAGEMANAGER->findImage(L"exit")->render();
	}
	else
	{
		if (_selectNum != 1)		IMAGEMANAGER->findImage(L"selectMusic")->render(128);
		else						IMAGEMANAGER->findImage(L"selectMusic")->render();
		if (_selectNum != 0)		IMAGEMANAGER->findImage(L"selectVolume")->render(128);
		else						IMAGEMANAGER->findImage(L"selectVolume")->render();

		IMAGEMANAGER->findImage(L"volume")->render();
		IMAGEMANAGER->findImage(L"music")->render();
		IMAGEMANAGER->findImage(L"back")->render();

		IMAGEMANAGER->findImage(L"0")->render();
		IMAGEMANAGER->findImage(L"25")->render();
		IMAGEMANAGER->findImage(L"50")->render();
		IMAGEMANAGER->findImage(L"75")->render();
		IMAGEMANAGER->findImage(L"100")->render();
		IMAGEMANAGER->findImage(L"on")->render();
		IMAGEMANAGER->findImage(L"off")->render();
	}
}


