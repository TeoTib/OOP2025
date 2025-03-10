#include "functii.h"
#include <cstring>

int compName(char* name1, char* name2)
{
	return strcmp(name1, name2);
}

int compGrade(float grade1, float grade2)
{
	if (grade1 > grade2)
		return 1;
	else if (grade1 < grade2)
		return -1;
	else return 0;
}
