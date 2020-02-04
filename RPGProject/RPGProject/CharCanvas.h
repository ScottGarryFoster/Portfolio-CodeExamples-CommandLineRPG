#pragma once
#include "CharacterImage.h"
#include "Vector2Int.h"
#include "InformationPanels.h"

using namespace std;

class CharCanvas
{
	int m_width;
	int m_height;
	char** m_grid;
	bool m_loaded;
	int m_imageLayersLength;//Length of the image layer array
	Vector2Int* m_imageLayerPosition[5] = { nullptr }; //Top Left position of the layers.
	Vector2Int* m_informationPanelPosition[5] = { nullptr }; //Top Left position of the informaitonPanel Layers.

	bool m_redraw;//If true a redraw is needed.
	bool m_usingInformationPanels;//If using Information Panels. If true a redraw is always used.

protected:
	CharacterImage* p_imageLayers[5] = { nullptr };//We're not responsible for deleting these
	InformationPanels* p_informationPanels[5] = { nullptr };//We're not responsible for deleting these
public:
	CharCanvas(int width, int height);
	virtual ~CharCanvas();

	void cleanForLoading();
	void createEmptyGrid(int width, int height);
	void clearGrid();

	void AddImage(CharacterImage *image, int layer, int locationX = 0, int locationY = 0);
	void AddInformationPanel(InformationPanels* informationPanel, int layer, int locationX = 0, int locationY = 0);
	void AddGridToGrid(const char** charArray, int charArrayWidth, int charArrayHeight, int locationX = 0, int locationY = 0);

	void Draw();
private:
	void RedrawGrid();
	void AddImageToGrid(CharacterImage *image, Vector2Int *point);

	bool safetyCheck(CharacterImage* image);
	bool safetyCheck(Vector2Int* vector);
	bool safetyCheck(InformationPanels* panel);
};
