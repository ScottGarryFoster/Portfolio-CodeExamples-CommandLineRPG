#pragma once
#include "Player.h"
#include "IndependentEnumsAndStructs.h"
#include <iostream>
#include <string>

using namespace std;

class Screen
{
protected:
	Player* p_player = nullptr;
	bool p_haveSetup = false;
public:
	Screen();
	virtual ~Screen();

	ScreenTypes NewScreenType = ScreenTypes::None;
	void* ScreenPassover = nullptr;
	bool HaveSetup() { return p_haveSetup; };

	virtual void Setup(Player *player, void* Passover = nullptr) = 0;
	virtual void Output() = 0;
protected:
	virtual void DrawSeam();
};

