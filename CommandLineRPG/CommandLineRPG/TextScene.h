#pragma once
#include "Screen.h"
class TextScene :
	public Screen
{
public:
	TextScene();
	virtual ~TextScene();

	virtual void Setup(Player* player, void* Passover = nullptr);
	virtual void Output();
};

