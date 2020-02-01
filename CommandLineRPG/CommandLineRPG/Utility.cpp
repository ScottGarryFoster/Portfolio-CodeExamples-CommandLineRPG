#include "Utility.h"

bool Utility::FileExists(string f_sName)
{
	struct stat buffer;
	return (stat(f_sName.c_str(), &buffer) == 0);
}