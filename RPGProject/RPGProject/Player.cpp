#include "Player.h"



Player::Player()
{
	m_statStrength = 0;
	m_statDexterity = 0;
	m_statConstitution = 10;
	m_statIntelligence = 0;
	m_statWisdom = 0;
	m_statCharisma = 0;

	m_heathLabel = "HP";
	m_activeHealth = 5;
	m_activeWisdom = 0;

	m_gridUpdated = false;
	m_informationPanelWidth = 17;
	m_informationPanelHeight = 3;

	m_infoPanel = new InformationPanels();
	m_infoPanel->namePanel("Player");
	InformationField *fieldHealth = new InformationField(InformationField::InfoField_Type::ift_labelValueMax, &m_heathLabel, InformationField::InfoField_EntryType::ifet_int, &m_activeHealth, InformationField::InfoField_EntryType::ifet_int, &m_statConstitution);
	m_infoPanel->addNewField(fieldHealth, 0);
}


Player::~Player()
{
}

void Player::printBasicStats()
{
	cout << makeTopBottomLine() << endl;
	cout << makeBasicHealthLine() << endl;
	cout << makeTopBottomLine() << endl;
}

const char** Player::getInformationPanel()
{
	if (!m_gridUpdated)makeInformationPanel();
	return const_cast<const char**>(m_informationPanel);
}

void Player::createInformationPanel()
{
	if (m_informationPanel != nullptr)
		for (int c = 0; c < m_informationPanelHeight; c++)
			delete[] m_informationPanel[c];

	m_informationPanel = new char* [m_informationPanelHeight];
	for (int i = 0; i < m_informationPanelHeight; i++)
		m_informationPanel[i] = new char[m_informationPanelWidth];
}

void Player::makeInformationPanel()
{
	if (m_informationPanel == nullptr)createInformationPanel();

	string topBottomLine = makeTopBottomLine();
	Utility::addStringToCharArray(m_informationPanel[0], 17, topBottomLine);
	Utility::addStringToCharArray(m_informationPanel[1], 17, makeBasicHealthLine());
	Utility::addStringToCharArray(m_informationPanel[2], 17, topBottomLine);
}

string Player::makeTopBottomLine()
{
	string line = "+";
	for (int i = 0; i < 15; i++)
		line += '=';
	line += '+';
	return line;
}

string Player::makeBasicHealthLine()
{
	string line = "|";
	string hpLine = " HP: " + to_string(m_activeHealth) + '/' + to_string(m_statConstitution);
	line += hpLine;
	for (int i = 0; i < (15 - (int)hpLine.length()); i++)
		line += ' ';
	line += '|';
	return line;
}