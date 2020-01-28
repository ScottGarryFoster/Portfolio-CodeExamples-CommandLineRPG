// CommandLineRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ScreenManager.h"

int main()
{
	ScreenManager* screenManager = new ScreenManager();
	while (true)
	{
		screenManager->Output();
	}
	return 0;
}