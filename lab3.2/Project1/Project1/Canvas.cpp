#include "Canvas.h"
#include <stdlib.h>

Canvas::Canvas(int width, int height)
{
	//width = columns
	//height = lines
	char** matrix = (char**)(malloc(height * sizeof(char*)));
	for (int i = 0; i < height; i++)
		matrix[i] = (char*)(malloc(width * sizeof(char)));
}
