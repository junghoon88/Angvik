#pragma once

class timer
{
private:
	bool _isHardware;		//������ �ϵ���� ��������
	float _timeScale;		//Ÿ�� ������
	float _timeElapsed;		//tickCount

	__int64 _curTime;
	__int64 _lastTime;
	__int64 _periodFrequency;

	unsigned long _frameRate;
	unsigned long _FPSFrameCount;
	float _FPSTimeElapsed;
	float _worldTime;


public:
	timer();
	~timer();

	void init(void);
	void tick(float lockFPS = 0.0f);
	unsigned long getFrameRate(TCHAR* str = NULL) const;

	inline float getElapsedTime(void) const { return _timeElapsed; }
	inline float getWorldTime(void) const { return _worldTime; }

};
