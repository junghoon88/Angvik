#pragma once
#include "gameNode.h"

class sceneSelect : public gameNode
{
private:
	void initImage(void);
	void initSound(void);

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	sceneSelect();
	~sceneSelect();
};

