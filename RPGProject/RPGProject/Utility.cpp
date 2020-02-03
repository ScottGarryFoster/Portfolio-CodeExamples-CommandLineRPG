#include "Utility.h"

bool Utility::FileExists(string f_sName)
{
	struct stat buffer;
	return (stat(f_sName.c_str(), &buffer) == 0);
}

void Utility::addStringToCharArray(char* inputCharArray, int charArrayLength, string stringData, int startIndex)
{
	for (int i = startIndex; (i < stringData.length()) && (i < charArrayLength); i++)
		inputCharArray[i] = stringData[i];
}