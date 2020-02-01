#pragma once
class CharCanvas
{
	int m_width;
	int m_height;
	char** m_grid;
public:
	CharCanvas(int width, int height);
	virtual ~CharCanvas();

	void AddImage();
};

