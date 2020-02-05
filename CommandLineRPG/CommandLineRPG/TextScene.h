#pragma once
#include "Screen.h"
#include "IndependentEnumsAndStructs.h"
#include "CharacterImage.h"
#include "CharCanvas.h"
#include "InformationPanels.h"

class TextScene :
	public Screen
{
	CharacterImage* mImage;
	CharCanvas* m_Canvas;
	CharCanvas* m_CanvasInformation;
	InformationPanels* m_tab;
	int m_selectedTab;
public:
	TextScene();
	virtual ~TextScene();

	virtual void Setup(Player* player, void* Passover = nullptr);
	virtual void Output();
};

