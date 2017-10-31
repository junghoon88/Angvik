#pragma once
#include "DxWindow.h"
#include "PlayerManager.h"


class playerSceneTest : public DxWindow
{
private:
	PlayerManager* _pm;

private:
	void initImage(void);
	void initSound(void);
	void initText(void);


public:
	playerSceneTest();
	~playerSceneTest();

	void init(void);
	void release(void);
	void update(void);
	void render(void);
};

