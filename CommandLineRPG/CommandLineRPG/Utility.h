#pragma once
#include <string>
#include <windows.h>

using namespace std;

class Utility
{
public:
	static bool FileExists(string f_sName);

	static void addStringToCharArray(char* inputCharArray, int charArrayLength, string stringData, int startIndex = 0);

	static void ClearScreen();
};

