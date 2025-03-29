#include <iostream>
#include "Sort.h"

using namespace std;

int main()
{
	char string[] = "10,40,100,5,70";
	int v[] = { 4, 8, 2, 34, 8, 12 };
	int size = sizeof(v) / sizeof(v[1]);
	Sort s({ 3, 8, 5, 2, 8, 5, 9, 5, 5, 3 }); //initialization list
	Sort s1(5, 5, 25); //random
	Sort s2(v, size); //vector
	Sort s3(5, 5, 2, 4, 3, 1); //variadic parameters
	Sort s4(string); //string
	s.InsertSort(true);
	s.Print();
	s1.Print();
	s1.QuickSort(false);
	s1.Print();
	s2.BubbleSort(false);
	s2.Print();
	cout << s3.GetElementsCount()<<endl;
	cout << s4.GetElementFromIndex(2)<<endl;
	return 0;
}