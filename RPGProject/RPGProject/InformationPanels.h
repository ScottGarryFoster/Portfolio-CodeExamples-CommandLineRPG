#pragma once
#include "InformationField.h"

class InformationPanels
{
	int m_width;
	int m_height;
	char** m_grid;
public:
	InformationPanels();
	virtual ~InformationPanels();
};

