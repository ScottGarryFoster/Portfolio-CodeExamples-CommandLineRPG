#pragma once
#include "CharacterImage.h"
#include "Vector2Int.h"

using namespace std;

class CharCanvas
{
	int m_width;
	int m_height;
	char** m_grid;
	bool m_loaded;
	int m_imageLayersLength;//Length of the image layer array
	Vector2Int* m_imageLayerPosition[5]; //Top Left position of the layers.

	bool m_redraw;//If true a redraw is needed.
protected:
	CharacterImage* p_imageLayers[5];//We're not responsible for deleting these
public:
	CharCanvas(int width, int height);
	virtual ~CharCanvas();

	void cleanForLoading();
	void createEmptyGrid(int width, int height);
	void clearGrid();

	void AddImage(CharacterImage *image, int layer, int locationX = 0, int locationY = 0);
	void AddGridToGrid(const char** charArray, int charArrayWidth, int charArrayHeight, int locationX = 0, int locationY = 0);

	void Draw();
private:
	void RedrawGrid();
	void AddImageToGrid(CharacterImage *image, Vector2Int *point);

	bool safetyCheck(CharacterImage* image);
	bool safetyCheck(Vector2Int* vector);
};