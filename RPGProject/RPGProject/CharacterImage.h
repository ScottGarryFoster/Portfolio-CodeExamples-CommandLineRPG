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

	/// <summary>Exists only to prove the class exists.
	/// </summary>
	void awake() {}
	
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

	/// <summary>Gets the character at the row and coloumn
	/// <param name="row">row: int the row of the char.</param>
	/// <param name="col">col: int the col of the char.</param>
	/// <returns>Returns char: in the position within the grid or if not valid will return the alpha of the grid.</returns>
	/// </summary>
	const char getCharacterAtPoint(int row, int col);

	/// <summary>Gets the width in characters of the image
	/// <returns>Returns int.</returns>
	/// </summary>
	const int getWidth() { return m_width; }

	/// <summary>Gets the height in characters of the image
	/// <returns>Returns int.</returns>
	/// </summary>
	const int getHeight() { return m_height; }

	/// <summary>Gets the character considered not apart of the image
	/// <returns>Returns char.</returns>
	/// </summary>
	const char getTransparentCharacter() { return m_alphaChar; }
};

