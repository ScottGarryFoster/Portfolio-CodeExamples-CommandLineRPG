#pragma once
#include <string>

using namespace std;

class Utility
{
public:
	static bool FileExists(string f_sName);

	static void addStringToCharArray(char* inputCharArray, int charArrayLength, string stringData, int startIndex = 0);
};

