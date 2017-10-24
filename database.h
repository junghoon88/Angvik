#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

class elements
{
public:


	elements(){};
	~elements(){};
};

class database : public singletonBase<database>
{
private:
	typedef vector<wstring> arrElements;
	typedef vector<wstring>::iterator iterElements;

	typedef map<wstring, elements*> arrElement;
	typedef map<wstring, elements*>::iterator iterElement;

private:
	arrElement _mTotalElement;
	float _volume;
	bool _mute;

public:
	HRESULT init();
	void release();

	void loadDatabase(wstring name);

	//속성에 대한 접근자
	elements* getElementData(wstring str) { return _mTotalElement.find(str)->second; }

	//설정자
	void setElementCharactor(wstring str, int charactor);

	void setMute(bool mute) { _mute = mute; }
	bool getMute(void) { return _mute; }

	void setVolume(float volume) { _volume = volume; }
	float getVolume(void) { return _volume; }

	database();
	~database();
};

