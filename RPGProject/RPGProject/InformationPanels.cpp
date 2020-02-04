#include "InformationPanels.h"

InformationPanels::InformationPanels()
{
	m_width = 17;
	m_height = 10;
	m_grid = new char* [m_height];
	for (int i = 0; i < m_height; i++)
		m_grid[i] = new char[m_width];

	for (int i = 0; i < m_informaitonFieldLength; i++)
		m_informationFields[i] = nullptr;
}

InformationPanels::InformationPanels(int width, int height)
{
	m_width = width;
	m_height = height;
	m_informaitonFieldLength = height - 2;

	m_grid = new char* [m_height];
	for (int i = 0; i < m_height; i++)
		m_grid[i] = new char[m_width];

	for (int i = 0; i < m_informaitonFieldLength; i++)
		m_informationFields[i] = nullptr;
}
InformationPanels::~InformationPanels()
{
	for (int i = 0; i < 8; i++)
		if (m_informationFields[i] != nullptr)
			delete m_informationFields[i];

	for (int c = 0; c < m_height; c++)
		delete[] m_grid[c];
}

bool InformationPanels::addNewField(InformationField* informaitonField, int layer)
{
	if (informaitonField == nullptr) return false;
	if (layer < 0) return false;
	if (layer >= m_informaitonFieldLength) return false;
	m_informationFields[layer] = informaitonField;
}

void InformationPanels::namePanel(string newName)
{
	m_name = newName;
}

const char** InformationPanels::outputPanel()
{
	updateGridWithTitle();
	int linesSuccessful = 0;
	for (int i = 0; i < m_informaitonFieldLength; i++)
	{
		if (m_informationFields[i] == nullptr) continue;
		linesSuccessful++;
		string fieldOutput = "| " + m_informationFields[i]->buildOutput();
		for (int j = fieldOutput.length(); j < m_width - 1; j++)
			fieldOutput += ' ';
		fieldOutput += '|';
		Utility::addStringToCharArray(m_grid[i + 1], m_width, fieldOutput);
	}
	if (linesSuccessful < m_informaitonFieldLength)
	{
		string emptyLine = returnEmptyLine();
		for (int i = linesSuccessful; i < m_informaitonFieldLength; i++)
			Utility::addStringToCharArray(m_grid[i + 1], m_width, emptyLine);
	}
	Utility::addStringToCharArray(m_grid[m_height - 1], m_width, returnTopBottomBorder());
	
	return const_cast<const char**>(m_grid);
}

void InformationPanels::updateGridWithTitle()
{
	m_grid[0][0] = '+';
	if (m_name.length() >= m_width)
	{
		for (int i = 1; i < m_width - 1; i++)
			m_grid[0][i] = m_name[i - 1];
	}
	else if (m_name.length() > 0)
	{
		int centerOfWidth = (int)(m_width / 2);
		int centerOfString = (int)(m_name.length() / 2);
		int startCharacter = (centerOfWidth - centerOfString);
		int indexOfString = 0;
		for (int i = 1; i < m_width - 1; i++)
		{
			if (i < startCharacter || (i > startCharacter && indexOfString >= m_name.length()))
			{
				m_grid[0][i] = '=';
				continue;
			}
			m_grid[0][i] = m_name[indexOfString++];
		}
	}
	else
	{
		for (int i = 1; i < m_width - 1; i++)
			m_grid[0][i] = '=';
	}
	m_grid[0][m_width - 1] = '+';
}

string InformationPanels::returnEmptyLine()
{
	string returnString = "|";
	for (int i = 1; i < m_width - 1; i++)
		returnString += ' ';
	returnString += '|';
	return returnString;
}

string InformationPanels::returnTopBottomBorder()
{
	string returnString = "+";
	for (int i = 1; i < m_width - 1; i++)
		returnString += '=';
	returnString += '+';
	return returnString;
}