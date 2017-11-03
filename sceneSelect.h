#pragma once
#include "DxWindow.h"

class sceneSelect : public DxWindow
{
private:	
	int _frameX;
	int _selectNum;	
	int _selectVolume;

	D3DXVECTOR2 _setSelect[3];
	D3DXVECTOR2 _setOptionSelect[3];
	D3DXVECTOR2 _setVolume[5];
	D3DXVECTOR2 _setMusic[2];

	float _countTime;
	float _volume;

	bool _isOption;
	bool _isMute;
	bool _isStart;

	bool _musicStart;

public:
	sceneSelect();
	~sceneSelect();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

};

