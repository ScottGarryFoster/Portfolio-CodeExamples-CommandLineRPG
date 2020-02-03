#include "Player.h"



Player::Player()
{
	m_statStrength = 0;
	m_statDexterity = 0;
	m_statConstitution = 0;
	m_statIntelligence = 0;
	m_statWisdom = 0;
	m_statCharisma = 0;

	m_activeHealth = 0;
	m_activeWisdom = 0;
}


Player::~Player()
{
}

void Player::printBasicStats()
{
	cout << makeTopBottomLine();

	cout << '|';
	string hpLine = " HP: " + m_activeHealth + '/' + m_statConstitution;
	cout << hpLine;
	for (int i = 0; i < (15 - (int)hpLine.length()); i++)
		cout << ' ';
	cout << '|' << endl;

	cout << makeTopBottomLine();
}

string Player::makeTopBottomLine()
{
	string line = "+";
	for (int i = 0; i < 15; i++)
		line += '=';
	line += '+';
	return line;
}