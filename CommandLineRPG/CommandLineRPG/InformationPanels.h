#pragma once
#include "InformationField.h"
#include "Utility.h"
#include "InformationTab.h"
#include "Vector2Int.h"

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

	InformationTab* m_informationTabs = nullptr;
	Vector2Int* m_informationTabLocation = nullptr;

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
	const int getWidth() { return m_width; }
	const int getHeight() { return m_height; }

	void setSize(int newWidth, int newHeight){ m_width = newWidth; m_height = newHeight;}
	void setWidth(int newWidth) { m_width = newWidth; }
	void setHeight(int newHeight) { m_height = newHeight; }

	InformationTab* addInformationTab(int locationX = 0, int locationY = 0);
	InformationTab* getInformationTab();
	void moveInformationTab(int locationX = 0, int locationY = 0);

private:
	void updateGridWithTitle();
	string returnEmptyLine();
	string returnTopBottomBorder();

	void addTabsToGrid(int& linesSuccessful);
	void addFieldsToGrid(int &linesSuccessful);

	void AddGridToGrid(const char** charArray, int charArrayWidth, int charArrayHeight, int locationX, int locationY);
};

