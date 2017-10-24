#pragma once
#include <vector>

class animation
{
public:
	typedef vector<POINT> vFrameList;
	typedef vector<int> vPlayList;

private:
	int			_frameNum;			//몇 프레임인지

	vFrameList	_frameList;			//애니메이션 프레임 리스트
	vPlayList	_playList;			//애니메이션 플레이 인덱스 담을 리스트

	int			_frameWidth;		//프레임 가로크기
	int			_frameHeight;		//프레임 세로크기

	BOOL		_loop;				//애니메이션 루프 여부

	float		_frameUpdateSec;	//프레임 갱신 속도
	float		_elapsedSec;

	DWORD		_nowPlayIndex;		//현재 재생 중인 플레이 인덱스
	BOOL		_play;


public:
	animation();
	~animation();

	HRESULT init(int totalW, int totalH, int frameW, int frameH);
	void release(void);

	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);
	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);

	void setFPS(int framePerSec);

	void frameUpdate(float elapsedTime);

	void start(void);
	void stop(void);
	void pause(void);
	void resume(void);

	inline BOOL isPlay(void) { return _play; }
	inline POINT getFramePos(void) { return _frameList[_playList[_nowPlayIndex]]; }
	inline int getFrameWidth(void) { return _frameWidth; }
	inline int getFrameHeight(void) { return _frameHeight; }


};

