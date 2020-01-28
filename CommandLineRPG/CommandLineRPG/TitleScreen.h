#pragma once
#include "Screen.h"
class TitleScreen :
	public Screen
{
public:
	TitleScreen();
	virtual ~TitleScreen();

	virtual void Setup(Player* player, void* Passover = nullptr);
	virtual void Output();
};

