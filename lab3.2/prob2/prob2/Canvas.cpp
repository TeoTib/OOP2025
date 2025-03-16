#include "Canvas.h"
#include <iostream>
using namespace std;

Canvas::Canvas(int width, int height)
{
	char** matrix = new char* [height];
	for (int i = 0; i < height; i++)
		matrix[i] = new char[width];
	lines = height;
	columns = width;
	this->matrix = matrix;

}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray-1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray+1))
				matrix[i][j] = ch;
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray*ray)
				matrix[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i < bottom; i++)
		for (int j = left; j < right; j++)
			if (i==top || i==bottom-1 || j==left || j==right-1)
			matrix[i][j] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i < bottom; i++)
		for (int j = left; j < right; j++)
			if (!(i == top || i == bottom - 1 || j == left || j == right - 1))
				matrix[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx, dy, D, y;
	dx = x2 - x1;
	dy = y2 - y1;
	D = 2 * dy - dx;
	y = y1;
	for (int x = x1; x <= x2; x++)
	{
		matrix[x][y] = ch;
		if (D > 0)
		{
			y++;
			D -= 2 * dx;
		}
		D += 2 * dy;
	}
}

void Canvas::Print()
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = ' ';
}
