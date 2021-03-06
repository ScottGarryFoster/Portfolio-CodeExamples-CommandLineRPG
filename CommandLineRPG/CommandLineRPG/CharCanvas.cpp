#include "CharCanvas.h"

CharCanvas::CharCanvas(int width, int height)
{
	m_width = width;
	m_height = height;
	m_grid = new char* [m_height];
	for (int i = 0; i < m_height; i++)
		m_grid[i] = new char[m_width];
	m_loaded = true;

	m_imageLayersLength = 5;
	for (int i = 0; i < m_imageLayersLength; i++)
	{
		p_imageLayers[i] = nullptr;
		m_imageLayerPosition[i] = nullptr;
	}

	m_redraw = true;
	m_usingInformationPanels = false;
}

CharCanvas::~CharCanvas()
{
	for (int c = 0; c < m_height; c++)
		delete[] m_grid[c];
	delete[] m_grid;

	//The vector2Ints for layer position are ours:
	for (int i = 0; i < m_imageLayersLength; i++)
	{
		if (m_imageLayerPosition[i] != nullptr)
			delete m_imageLayerPosition[i];
		if (m_informationPanelPosition[i] != nullptr)
			delete m_informationPanelPosition[i];
	}
}

void CharCanvas::cleanForLoading()
{
	//Deleting:
	for (int c = 0; c < m_height; c++)
		delete[] m_grid[c];
	delete[] m_grid;

	m_loaded = false;
	m_width = 0;
	m_height = 0;
	m_grid = nullptr;
}

void CharCanvas::createEmptyGrid(int width, int height)
{
	if (m_loaded) cleanForLoading();//Clean for loading should be run first
	m_height = height;//Don't need to plus one as this is always one step ahead of the loop
	m_width = width;

	m_grid = new char* [m_height];
	for (int i = 0; i < m_height; i++)
		m_grid[i] = new char[m_width];

	for (int r = 0; r < m_height; r++)
		for (int c = 0; c < m_width; c++)
			m_grid[r][c] = ' ';

	m_loaded = true;
}

void CharCanvas::clearGrid()
{
	if (!m_loaded) createEmptyGrid(m_width, m_height);
	for (int r = 0; r < m_height; r++)
		for (int c = 0; c < m_width; c++)
			m_grid[r][c] = ' ';
}

void CharCanvas::AddImage(CharacterImage* image, int layer, int locationX, int locationY)
{
	if (layer < 0) return;
	if (layer >= m_imageLayersLength) return;
	p_imageLayers[layer] = image;
	if (m_imageLayerPosition[layer] == nullptr)
		m_imageLayerPosition[layer] = new Vector2Int(locationX, locationY);
	else
		m_imageLayerPosition[layer]->set(locationX, locationY);
	m_redraw = true;
}

void CharCanvas::AddInformationPanel(InformationPanels* informationPanel, int layer, int locationX, int locationY)
{
	if (layer < 0) return;
	if (layer >= m_imageLayersLength) return;
	p_informationPanels[layer] = informationPanel;
	if (m_informationPanelPosition[layer] == nullptr)
		m_informationPanelPosition[layer] = new Vector2Int(locationX, locationY);
	else
		m_informationPanelPosition[layer]->set(locationX, locationY);
	m_redraw = true;
	
	for (int i = 0; i < m_imageLayersLength; i++)//If there is a single information panel
		if (p_informationPanels[i] != nullptr)
		{
			m_usingInformationPanels = true;//Always draw
			return;
		}
	m_usingInformationPanels = false;
}

void CharCanvas::Draw()
{
	if(m_redraw || m_usingInformationPanels)RedrawGrid();
	for (int r = 0; r < m_height; r++)
	{
		for (int c = 0; c < m_width; c++)
			cout << m_grid[r][c];
		cout << endl;
	}
}

void CharCanvas::RedrawGrid()
{
	clearGrid();
	for (int i = 0; i < m_imageLayersLength; i++)
		if (p_imageLayers[i] != nullptr)
			if (m_imageLayerPosition[i] != nullptr)
			{
				if (safetyCheck(p_imageLayers[i]))//Does it actually exist?
					AddImageToGrid(p_imageLayers[i], m_imageLayerPosition[i]);
				else
					p_imageLayers[i] = nullptr;//Something has deleted it so forget about it
			}

	if (!m_usingInformationPanels) return;
	for (int i = 0; i < m_imageLayersLength; i++)
		if (p_informationPanels[i] != nullptr)
			if (m_informationPanelPosition[i] != nullptr)
			{
				if (safetyCheck(p_informationPanels[i]))//Does it actually exist?
				{
					AddGridToGrid(p_informationPanels[i]->outputPanel(), p_informationPanels[i]->getWidth(), p_informationPanels[i]->getHeight(), m_informationPanelPosition[i]->x, m_informationPanelPosition[i]->y);
					if (p_informationPanels[i]->hasInformationTab())
					{
						const char** informationTab = p_informationPanels[i]->getInformationTab()->outputPanel();
						if(informationTab != nullptr)
							AddGridToGrid(informationTab, p_informationPanels[i]->getInformationTab()->getWidth(), p_informationPanels[i]->getInformationTab()->getHeight(), 0, 0);
					}
				}
				else
					p_informationPanels[i] = nullptr;//Something has deleted it so forget about it
			}
}
void CharCanvas::AddImageToGrid(CharacterImage* image, Vector2Int* point)
{
	if (!safetyCheck(image)) return;//Exception safety
	if (!safetyCheck(point)) return;//Exception safety
	char alphaCharacter = image->getTransparentCharacter();
	int startOfGridRow = point->y;
	if (startOfGridRow < 0) return;
	int startOfGridCol = point->x;
	if (startOfGridCol < 0) return;
	int imageWidth = image->getWidth();
	int imageHeight = image->getHeight();

	for (int r = startOfGridRow; (r < imageHeight) && (r < m_height); r++)
		for (int c = startOfGridCol; c < imageWidth && (c < m_width); c++)
		{
			char imageCharacter = image->getCharacterAtPoint(r, c);
			if (imageCharacter != alphaCharacter)
				m_grid[r][c] = imageCharacter;
		}
}

void CharCanvas::AddGridToGrid(const char** charArray, int charArrayWidth, int charArrayHeight, int locationX, int locationY)
{
	if (!m_loaded) return;
	for(int r = 0; r < charArrayHeight; r++)
		for (int c = 0; c < charArrayWidth; c++)
		{
			if (r + locationY >= m_height) break;
			if (c + locationX >= m_width) break;
			m_grid[r + locationY][c + locationX] = charArray[r][c];
		}
	m_redraw = false;
}

bool CharCanvas::safetyCheck(CharacterImage* image)
{
	if (image == nullptr) return false;
	try
	{
		image->awake();
	}
	catch (exception & e)
	{
		return false;//e.what() if I wanted to debug
	}
	return true;
}

bool CharCanvas::safetyCheck(Vector2Int* vector)
{
	if (vector == nullptr) return false;
	try
	{
		vector->awake();
	}
	catch (exception & e)
	{
		return false;//e.what() if I wanted to debug
	}
	return true;
}

bool CharCanvas::safetyCheck(InformationPanels* panel)
{
	if (panel == nullptr) return false;
	try
	{
		panel->awake();
	}
	catch (exception & e)
	{
		return false;//e.what() if I wanted to debug
	}
	return true;
}