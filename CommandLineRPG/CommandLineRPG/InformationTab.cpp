#include "InformationTab.h"

InformationTab::InformationTab()
{
	m_numberOfOptions = 0;
	m_tabLabels = nullptr;
	p_selectedTab = nullptr;

	m_tabWidth = 0;
	m_tabHeight = 3;
	m_grid = nullptr;
}
InformationTab::~InformationTab()
{
	if (m_tabLabels != nullptr)
		delete[] m_tabLabels;

	if(m_grid != nullptr)
		for (int c = 0; c < m_tabHeight; c++)
			delete[] m_grid[c];
}

void InformationTab::setWidth(int newWidth)
{
	deleteGrid();
	m_tabWidth = newWidth;
}

void InformationTab::addNewOption(string label, int point)
{
	if (point < -1) point = -1;
	if (m_numberOfOptions > 0)
	{
		string* holderArray = new string[m_numberOfOptions];
		for (int i = 0; i < m_numberOfOptions; i++)
			holderArray[i] = m_tabLabels[i];//Save old version
		delete[] m_tabLabels;//Deletes the whole old version

		m_numberOfOptions++;
		m_tabLabels = new string[m_numberOfOptions];//Make new store
		if (point >= m_numberOfOptions) point = -1;//If the push in point is bigger than the new size, put it at the end
		for (int i = 0; i < m_numberOfOptions; i++)
		{
			if (point == -1 && i >= m_numberOfOptions - 1) break;
			if (i < point || point == -1)
				m_tabLabels[i] = holderArray[i];//Copy old version to new version
			else if (i == point)
				m_tabLabels[i] = label;
			else
				m_tabLabels[i] = holderArray[i - 1];//Copy old version to new version
		}
		delete[] holderArray;//Delete old version

		if ((point == -1) || (point >= m_numberOfOptions - 1))
			m_tabLabels[m_numberOfOptions - 1] = label;
	}
	else
	{
		m_numberOfOptions = 1;
		m_tabLabels = new string[m_numberOfOptions];
		m_tabLabels[m_numberOfOptions - 1] = label;
	}
}

void InformationTab::printOptions()
{
	for (int i = 0; i < m_numberOfOptions; i++)
		cout << "i: " << i << " : " << m_tabLabels[i] << endl;
}

const char** InformationTab::outputPanel()
{
	if (m_tabWidth <= 0) return nullptr;
	if (m_numberOfOptions <= 0) return nullptr;
	if (p_selectedTab == nullptr) return nullptr;
	clearGrid();

	int tabSize = m_tabWidth / m_numberOfOptions;
	for (int i = 1; i < m_numberOfOptions; i++)
	{
		int splitPoint = tabSize * i;
		m_grid[1][splitPoint] = '|';
	}
	for (int i = 0; i < m_numberOfOptions; i++)
		enterCenterText(m_tabLabels[i], tabSize - 1, tabSize * i + 1, (*p_selectedTab == i) ? '#' : ' ');

	m_grid[1][m_tabWidth - 1] = '|';//Helps when the math rounds off
	/*cout << "Other output:" << endl;
	for (int i = 0; i < m_tabHeight; i++)
	{
		for (int j = 0; j < m_tabWidth; j++)
			cout << m_grid[i][j];
		cout << endl;
	}*/
	return const_cast<const char**>(m_grid);
}

void InformationTab::clearGrid()
{
	deleteGrid();

	m_grid = new char* [m_tabHeight];
	for (int i = 0; i < m_tabHeight; i++)
		m_grid[i] = new char[m_tabWidth];

	m_grid[0][0] = '+';
	m_grid[2][0] = '+';
	for (int i = 1; i < m_tabWidth - 1; i++)
	{
		m_grid[0][i] = '=';
		m_grid[2][i] = '=';
	}
	m_grid[0][m_tabWidth - 1] = '+';
	m_grid[2][m_tabWidth - 1] = '+';

	m_grid[1][0] = '|';
	for (int i = 1; i < m_tabWidth - 1; i++)
		m_grid[1][i] = ' ';
	m_grid[1][m_tabWidth - 1] = '|';
}

void InformationTab::deleteGrid()
{
	if (m_grid != nullptr)
		for (int c = 0; c < m_tabHeight; c++)
			delete[] m_grid[c];
	delete[] m_grid;
}

void InformationTab::enterCenterText(string label, int eachTabWidth, int startOfTab, char gapCharacter)
{
	int centerOfWidth = eachTabWidth / 2;
	int centerOfString = (int)(label.length() / 2);
	int startCharacter = startOfTab + (centerOfWidth - centerOfString);
	int indexOfString = 0;
	for (int i = startOfTab; i < startOfTab + eachTabWidth; i++)
	{
		if (i < startCharacter || (i > startCharacter&& indexOfString >= label.length()))
		{
			m_grid[1][i] = gapCharacter;
			continue;
		}
		m_grid[1][i] = label[indexOfString++];
	}
}