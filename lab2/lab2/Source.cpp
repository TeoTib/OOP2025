#include <iostream>
#include "NumberList.h"

int main()
{
	NumberList lista1;
	lista1.Init();
	lista1.Add(8);
	lista1.Add(3);
	lista1.Sort();
	lista1.Print();
}