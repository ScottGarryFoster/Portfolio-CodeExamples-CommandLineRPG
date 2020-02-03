#pragma once
#include "Player.h"

#include "Screen.h"

class ScreenManager
{
private:
	Screen* m_currentScreen = nullptr;
	Player* m_player = nullptr;
public:
	ScreenManager();
	virtual ~ScreenManager();

	void Output();
	void InstantiateNewScreen(ScreenTypes screenType);
};