#include "CharacterImage.h"

CharacterImage::CharacterImage()
{
	m_loaded = false;
	m_width = 0;
	m_height = 0;
	m_grid = nullptr;
	m_alphaChar = '#';
}
CharacterImage::~CharacterImage()
{
	for (int c = 0; c < m_height; c++)
		delete[] m_grid[c];
	delete[] m_grid;
}

void CharacterImage::loadFromFile(string fileName)
{
	if (!Utility::FileExists(fileName))
	{
		cout << "CharacterImage::loadFromFile: File does not exist: " << fileName << endl;
		return;
	}
	if (m_loaded) cleanForLoading();//Ensures no memory leaks

	//Setting up storage for the file
	string fileAsAWhole[40];
	for (int i = 0; i < 40; i++)
		fileAsAWhole[i] = "";

	//Reading the file:
	int lineIndex = 0, longestLine = 0;
	ifstream readInFile(fileName);// Read from the text file
	string fileLine;	// Create a text string, which is used to output the text file
	//The first character is the alpha character
	getline(readInFile, fileLine);//So the first get is outside of the loop
	m_alphaChar = fileLine[0];//For the alpha character

	while (getline(readInFile, fileLine))// Use a while loop together with the getline() function to read the file line by line
	{
		fileAsAWhole[lineIndex++] = fileLine;
		if (longestLine < fileAsAWhole[lineIndex - 1].length())
			longestLine = fileAsAWhole[lineIndex - 1].length();
	}
	readInFile.close();// Close the file

	//Moving forward with information with the file
	createEmptyGrid(longestLine, lineIndex);

	for (int lines = 0; lines < lineIndex; lines++)
		for (int c = 0; c < fileAsAWhole[lines].length(); c++)
			m_grid[lines][c] = fileAsAWhole[lines][c];

	m_loaded = true;
}

void CharacterImage::cleanForLoading()
{
	//Deleting:
	for (int c = 0; c < m_height; c++)
		delete[] m_grid[c];
	delete[] m_grid;

	m_loaded = false;
	m_width = 0;
	m_height = 0;
	m_grid = nullptr;
	m_alphaChar = '#';
}

void CharacterImage::createEmptyGrid(int width, int height)
{
	if (m_loaded) cleanForLoading();//Clean for loading should be run first
	m_height = height;//Don't need to plus one as this is always one step ahead of the loop
	m_width = width;

	m_grid = new char* [m_height];
	for (int i = 0; i < m_height; i++)
		m_grid[i] = new char[m_width];

	for (int r = 0; r < m_height; r++)
		for (int c = 0; c < m_width; c++)
			m_grid[r][c] = '#';

	m_loaded = true;
}

void CharacterImage::print()
{
	for (int r = 0; r < m_height; r++)
	{
		for (int c = 0; c < m_width; c++)
			cout << m_grid[r][c];
		cout << endl;
	}
}

const char CharacterImage::getCharacterAtPoint(int row, int col)
{
	if (row < 0) return m_alphaChar;
	if (col < 0) return m_alphaChar;
	if (row >= m_height)return m_alphaChar;
	if (col >= m_width)return m_alphaChar;
	return m_grid[row][col];
}