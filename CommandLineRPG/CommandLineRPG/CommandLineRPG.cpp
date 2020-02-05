// CommandLineRPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ScreenManager.h"
#include <windows.h>

#include "InformationTab.h"
using namespace std;

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1280, 720, TRUE);

	ScreenManager* screenManager = new ScreenManager();
	/*int selectedTab = 1;
	InformationTab* tab = new InformationTab();
	tab->addNewOption("First");
	tab->addNewOption("Second");
	tab->addNewOption("Third");
	tab->setWidth(100);
	tab->giveSelectedTab(&selectedTab);
	tab->outputPanel();
	int number;
	cin >> number;
	*/
	while (true)
	{
		screenManager->Output();
	}
	return 0;
}