#pragma once
#include <iostream>
#include <string>
#include "Utility.h"
#include "InformationPanels.h"
#include "InformationField.h"

using namespace std;

class Player
{
	int m_statStrength;
	int m_statDexterity;
	int m_statConstitution;
	int m_statIntelligence;
	int m_statWisdom;
	int m_statCharisma;

	string m_heathLabel;
	int m_activeHealth;
	int m_activeWisdom;

	bool m_gridUpdated;
	char** m_informationPanel;
	int m_informationPanelWidth;
	int m_informationPanelHeight;

	InformationPanels* m_infoPanel;
public:
	Player();
	virtual ~Player();

	void printBasicStats();
	const char** getInformationPanel();
	InformationPanels* getInfoPanel() { return m_infoPanel; }

	const int getWidth(){return m_informationPanelWidth;}
	const int getHeight(){return m_informationPanelHeight;}

	void addHealth(int number) { m_activeHealth += number; }
private:
	void makeInformationPanel();
	void createInformationPanel();
	string makeTopBottomLine();
	string makeBasicHealthLine();
};

