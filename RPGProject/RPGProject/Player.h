#pragma once
#include <iostream>

using namespace std;

class Player
{
	int m_statStrength;
	int m_statDexterity;
	int m_statConstitution;
	int m_statIntelligence;
	int m_statWisdom;
	int m_statCharisma;

	int m_activeHealth;
	int m_activeWisdom;
public:
	Player();
	virtual ~Player();

	void printBasicStats();
private:
	string makeTopBottomLine();
};

