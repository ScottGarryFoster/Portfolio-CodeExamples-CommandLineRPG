#include "Screen.h"



Screen::Screen()
{
}


Screen::~Screen()
{
}

void Screen::DrawSeam()
{
	for (int i = 0; i < CHARACTER_WIDTH; i++)
		cout << CHARACTER_SEAM;
	cout << endl;
}