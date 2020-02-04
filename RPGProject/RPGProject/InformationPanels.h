#pragma once
#include "InformationField.h"
#include "Utility.h"

class InformationPanels
{
	int m_width;
	int m_height;
	char** m_grid;

	InformationField *m_informationFields[8];
	int m_informaitonFieldLength = 8;

	string m_name;
public:
	InformationPanels();
	virtual ~InformationPanels();

	bool addNewField(InformationField* informaitonField, int layer);
	void namePanel(string newName);

	const char** outputPanel();
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

private:
	void updateGridWithTitle();
};

