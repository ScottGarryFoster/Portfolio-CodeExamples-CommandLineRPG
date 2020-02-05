#include "Player.h"



Player::Player()
{
	m_strengthLabel = "STR";
	m_statStrength = 0;
	m_dexterityLabel = "DEX";
	m_statDexterity = 0;
	m_statConstitution = 10;
	m_intelligenceLabel = "INT";
	m_statIntelligence = 0;
	m_statWisdom = 20;
	m_charismaLabel = "CHA";
	m_statCharisma = 0;

	m_heathLabel = "HP";
	m_activeHealth = 5;
	m_wisdomLabel = "MP";
	m_activeWisdom = 12;

	m_statTitle = "Player Stats";
	/*
		Information Panels
		Some classes need to be able to output variables to the screen.
		These don't need to worry about the code, but these need to be
		a conduit. Information Panels is that conduit.

		You create a Information Panel which you own and must delete when
		you are deleted.

		You create Information Fields where you pass pointers to vars to
		be displayed. These are destoryed when the panel itself dies.
		*THE POINTERS ARE NOT DESTROYED BUT THE CLASS IS*

		Then through a get the screen displaying things can then output
		data from the player indirectly.
	*/
	int currentLine = 0;
	m_infoPanel = new InformationPanels(18, 10);
	m_infoPanel->namePanel("Player");
	//Heath
	InformationField *fieldHealth = new InformationField(InformationField::InfoField_Type::ift_labelValueMax, &m_heathLabel, InformationField::InfoField_EntryType::ifet_int, &m_activeHealth, InformationField::InfoField_EntryType::ifet_int, &m_statConstitution);
	m_infoPanel->addNewField(fieldHealth, currentLine++);
	//Wisdom
	fieldHealth = new InformationField(InformationField::InfoField_Type::ift_labelValueMax, &m_wisdomLabel, InformationField::InfoField_EntryType::ifet_int, &m_activeWisdom, InformationField::InfoField_EntryType::ifet_int, &m_statWisdom);
	m_infoPanel->addNewField(fieldHealth, currentLine++);

	//Spacer
	fieldHealth = new InformationField(InformationField::InfoField_Type::ift_text, &m_statSpacer);
	m_infoPanel->addNewField(fieldHealth, currentLine++);

	//Stats Header
	fieldHealth = new InformationField(InformationField::InfoField_Type::ift_text, &m_statTitle);
	m_infoPanel->addNewField(fieldHealth, currentLine++);

	//Strength
	fieldHealth = new InformationField(InformationField::InfoField_Type::ift_textValue, &m_strengthLabel, InformationField::InfoField_EntryType::ifet_int, &m_statStrength);
	m_infoPanel->addNewField(fieldHealth, currentLine++);
	//Dexterity
	fieldHealth = new InformationField(InformationField::InfoField_Type::ift_textValue, &m_dexterityLabel, InformationField::InfoField_EntryType::ifet_int, &m_statDexterity);
	m_infoPanel->addNewField(fieldHealth, currentLine++);
	//Intelligence
	fieldHealth = new InformationField(InformationField::InfoField_Type::ift_textValue, &m_intelligenceLabel, InformationField::InfoField_EntryType::ifet_int, &m_statIntelligence);
	m_infoPanel->addNewField(fieldHealth, currentLine++);
	//Charisma
	fieldHealth = new InformationField(InformationField::InfoField_Type::ift_textValue, &m_charismaLabel, InformationField::InfoField_EntryType::ifet_int, &m_statCharisma);
	m_infoPanel->addNewField(fieldHealth, currentLine++);
}


Player::~Player()
{
	if (m_infoPanel != nullptr) delete m_infoPanel;
}