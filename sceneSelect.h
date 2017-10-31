#pragma once
#include "DxWindow.h"

class sceneSelect : public DxWindow
{
private:
	RECT _selectRECT;
	RECT _startRECT;
	RECT _optionRECT;
	RECT _exitRECT;
	
	int _frameX;

	float _countTime;
	float _volume;

	bool _isOption;
	bool _isMute;

public:
	sceneSelect();
	~sceneSelect();

	void init(void);
	void release(void);
	void update(void);
	void render(void);

};

