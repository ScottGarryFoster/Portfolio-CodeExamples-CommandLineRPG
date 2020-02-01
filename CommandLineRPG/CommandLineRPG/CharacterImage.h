#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Utility.h"

using namespace std;

class CharacterImage
{
	bool m_loaded;
	int m_width;
	int m_height;
	char** m_grid;
	char m_alphaChar;

	void cleanForLoading();
	void createEmptyGrid(int width, int height);
public:
	CharacterImage();
	virtual ~CharacterImage();
	
	/// <summary>If true then something exists within the grid as an ASCii image.
	/// </summary>
	const bool isImageLoaded() { return m_loaded; }

	/// <summary>Loads ASCii Text File Images to a grid in order to load it to a file.
	/// <param name="fileName">fileName: relative to where program is run.</param>
	/// </summary>
	void loadFromFile(string fileName);

	/// <summary>Test class if you want to see to screen what is loaded.
	/// </summary>
	void print();

};

