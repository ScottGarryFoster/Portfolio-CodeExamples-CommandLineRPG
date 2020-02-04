#pragma once
#include "InformationField.h"
#include "Utility.h"

/*
	Information Panels (Point of view of the owner)
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

class InformationPanels
{
	int m_width;
	int m_height;
	char** m_grid;

	InformationField* m_informationFields[8] = { nullptr };
	int m_informaitonFieldLength = 8;

	string m_name;
public:
	InformationPanels();
	InformationPanels(int width, int height);
	virtual ~InformationPanels();

	/// <summary>Exists only to prove the class exists.
	/// </summary>
	void awake() {}

	bool addNewField(InformationField* informaitonField, int layer);
	void namePanel(string newName);

	const char** outputPanel();
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

private:
	void updateGridWithTitle();
	string returnEmptyLine();
	string returnTopBottomBorder();
};

