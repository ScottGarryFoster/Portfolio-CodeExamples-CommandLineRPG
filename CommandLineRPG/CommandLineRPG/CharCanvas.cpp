#include "CharCanvas.h"

CharCanvas::CharCanvas(int width, int height)
{
	m_width = width;
	m_height = height;
	m_grid = new char* [m_height];
	for (int i = 0; i < m_height; i++)
		m_grid[i] = new char[m_width];
}

CharCanvas::~CharCanvas()
{
	for (int c = 0; c < m_height; c++)
		delete[] m_grid[c];
}