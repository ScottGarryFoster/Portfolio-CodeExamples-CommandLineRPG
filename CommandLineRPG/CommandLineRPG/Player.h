#pragma once
#include <iostream>
#include <string>
#include "Utility.h"
#include "InformationPanels.h"
#include "InformationField.h"

using namespace std;

class Player
{
	string m_strengthLabel;
	int m_statStrength;
	string m_dexterityLabel;
	int m_statDexterity;
	int m_statConstitution;
	string m_intelligenceLabel;
	int m_statIntelligence;
	int m_statWisdom;
	string m_charismaLabel;
	int m_statCharisma;

	string m_heathLabel;
	int m_activeHealth;
	string m_wisdomLabel;
	int m_activeWisdom;

	string m_statTitle;
	string m_statSpacer;

	InformationPanels* m_infoPanel;
public:
	Player();
	virtual ~Player();

	InformationPanels* getInfoPanel() { return m_infoPanel; }

	void addHealth(int number) { m_activeHealth += number; }
};

