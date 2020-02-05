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
	delete[] m_grid;

	if (m_informationTabLocation != nullptr)
		delete m_informationTabLocation;
	if (m_informationTabs != nullptr)
		delete m_informationTabs;
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
	if (m_informationTabs != nullptr)
		addTabsToGrid(linesSuccessful);
	addFieldsToGrid(linesSuccessful);//Add fields to the information panel
	if (linesSuccessful < m_informaitonFieldLength)
	{
		string emptyLine = returnEmptyLine();
		for (int i = linesSuccessful; i < m_informaitonFieldLength; i++)
			Utility::addStringToCharArray(m_grid[i + 1], m_width, emptyLine);
	}
	Utility::addStringToCharArray(m_grid[m_height - 1], m_width, returnTopBottomBorder());
	
	return const_cast<const char**>(m_grid);
}

void InformationPanels::addFieldsToGrid(int& linesSuccessful)
{
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
}

void InformationPanels::addTabsToGrid(int& linesSuccessful)
{
	if (m_informationTabs == nullptr) return;
	if (m_grid == nullptr) return;
	int tabWidth = m_informationTabs->getWidth();
	if (tabWidth < 1) return;
	int tabHeight = m_informationTabs->getHeight();
	const char** tabData = m_informationTabs->outputPanel();
	if (tabData == nullptr) return;

	//AddGridToGrid(const_cast<const char**>(tabData), tabWidth, tabHeight,0,0);

	int innerI = 0, innerJ = 0;
	//for (int i = m_informationTabLocation->y; i < m_informationTabLocation->y + tabHeight && i < m_height; i++)
	//{
	linesSuccessful++; linesSuccessful++;
		for (int j = m_informationTabLocation->x; j < m_informationTabLocation->x + tabWidth && j < m_width; j++)
		{
			if (innerI >= tabHeight) break;
			if (innerJ >= tabWidth) break;
			
			m_grid[1][j] = tabData[1][innerJ++];
		}
		linesSuccessful++;
		innerI++;
		innerJ = 0;
	//}
}

void InformationPanels::AddGridToGrid(const char** charArray, int charArrayWidth, int charArrayHeight, int locationX, int locationY)
{
	for (int r = 0; r < charArrayHeight; r++)
		for (int c = 0; c < charArrayWidth; c++)
		{
			if (r + locationY >= m_height) break;
			if (c + locationX >= m_width) break;
			m_grid[r + locationY][c + locationX] = charArray[r][c];
		}
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

InformationTab* InformationPanels::addInformationTab(int locationX, int locationY)
{
	if (m_informationTabs != nullptr) delete m_informationTabs;
	m_informationTabs = new InformationTab();
	if (m_informationTabLocation != nullptr)
		m_informationTabLocation->set(locationX, locationY);
	else
		m_informationTabLocation = new Vector2Int(locationX, locationY);
	return m_informationTabs;
}
InformationTab* InformationPanels::getInformationTab()
{
	return m_informationTabs;
}
void InformationPanels::moveInformationTab(int locationX, int locationY)
{
	if (m_informationTabLocation != nullptr)
		m_informationTabLocation->set(locationX, locationY);
	else
		m_informationTabLocation = new Vector2Int(locationX, locationY);
}