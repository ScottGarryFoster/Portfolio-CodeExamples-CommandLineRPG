// CommandLineRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ScreenManager.h"
#include <windows.h>
using namespace std;

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1280, 720, TRUE);

	ScreenManager* screenManager = new ScreenManager();
	while (true)
	{
		screenManager->Output();
	}
	return 0;
}