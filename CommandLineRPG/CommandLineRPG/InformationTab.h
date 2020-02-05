#pragma once
#include <string>
#include <iostream>
using namespace std;

class InformationTab
{
	int m_numberOfOptions;
	string *m_tabLabels;

	int m_tabWidth;
	int m_tabHeight;
	char** m_grid;
protected:
	int *p_selectedTab; //We are given this and are not responsible for it's deletion
public:
	InformationTab();
	virtual ~InformationTab();

	const int getWidth() { return m_tabWidth; }
	const int getHeight() { return m_tabHeight; }

	void addNewOption(string label, int point = -1);
	void giveSelectedTab(int* selectedTab) { p_selectedTab = selectedTab; }

	void setWidth(int newWidth);

	const char** outputPanel();

	void printOptions();

private:
	void clearGrid();
	void enterCenterText(string label, int eachTabWidth, int startOfTab, char gapCharacter = ' ');
	void deleteGrid();
};

