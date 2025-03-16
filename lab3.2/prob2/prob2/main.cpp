#include <iostream>
#include "Canvas.h"

using namespace std;

int main()
{
	Canvas c(25, 25); //coloane si apoi linii
	c.Clear();
	c.DrawCircle(10, 10, 4, 'a');
	c.Print();
	c.FillCircle(10, 10, 4, 'c');
	c.Print();
	c.Clear();
	c.DrawRect(5, 6, 10, 12, 'd');
	c.Print();
	c.FillRect(5, 6, 10, 12, 'e');
	c.Print();
	c.Clear();
	c.SetPoint(0, 0, 'z');
	c.Print();
	c.Clear();
	c.DrawLine(0, 0, 10, 5, '#');
	c.Print();
	return 0;
}