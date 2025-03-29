#include "Sort.h"
#include <initializer_list>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cstring>
#include <cstdlib>
using namespace std;

int partition(int* vec, int low, int high, bool ascendent) {

	// Selecting last element as the pivot
	int pivot = vec[high];

	// Index of elemment just before the last element
	// It is used for swapping
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {

		// If current element is smaller than or
		// equal to pivot
		if (ascendent == true)
		{
			if (vec[j] <= pivot) {
				i++;
				swap(vec[i], vec[j]);
			}
		}
		else
		{
			if (vec[j] >= pivot) {
				i++;
				swap(vec[i], vec[j]);
			}
		}
	}

	// Put pivot to its position
	swap(vec[i + 1], vec[high]);

	// Return the point of partition
	return (i + 1);
}

void sortare(int *vec, int low, int high, bool ascendent) {

	// Base case: This part will be executed till the starting
	// index low is lesser than the ending index high
	if (low < high) {

		// pi is Partitioning Index, arr[p] is now at
		// right place
		int pi = partition(vec, low, high, ascendent);

		// Separately sort elements before and after the
		// Partition Index pi
		sortare(vec, low, pi - 1, ascendent);
		sortare(vec, pi + 1, high, ascendent);
	}
}

Sort::Sort(int no, int min, int max)
{
	size = no;
	vector = new int[size];
	srand(time(0));
	for (int i = 0; i < no; i++)
	{
		int nr = min + rand() % (max - min + 1);
		vector[i] = nr;
	}

}

Sort::Sort(initializer_list<int> list)
{
	int size = list.size();
	vector = new int[size];
	this->size = size;
	int cnt = 0;
	for (int value : list)
		vector[cnt++] = value;

}

Sort::Sort(int v[], int size)
{
	this->size = size;
	vector = new int[size];
	for (int i = 0; i < size; i++)
		vector[i] = v[i];
}

Sort::Sort(int count, ...)
{
	size = count;
	vector = new int[count];
	int val;
	va_list v1;
	va_start(v1, count);
	for (int i = 0; i < count; i++)
	{
		val = va_arg(v1, int);
		vector[i] = val;
	}
	va_end(v1);
}

Sort::Sort(char string[])
{
	int size = strlen(string);
	vector = new int[size];
	int countvector = 0;
	int first=0, second=0;
	while (string[second] != NULL)
	{
		
		while (string[second] != ',' && string[second] != NULL)
		{
			second++;
		}
		char aux[100];
		int cnt = 0;
		aux[0] = '\0';
		for (int i = first; i < second; i++)
			aux[cnt++] = string[i];
		aux[cnt] = '\0';
		int num = atoi(aux);
		vector[countvector++] = num;
		if (string[second] != NULL)
		{
			second++;
			first = second;
		}
	}
	this->size = countvector;
}

void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	for (i = 1; i < size; i++) {
		key = vector[i];
		j = i - 1;

		// Move elements of arr[0..i-1],
		// that are greater than key, to one
		// position ahead of their
		// current position
		if (ascendent == true)
		{
			while (j >= 0 && vector[j] > key) {
				vector[j + 1] = vector[j];
				j = j - 1;
			}
		}
		else
		{
			while (j >= 0 && vector[j] < key) {
				vector[j + 1] = vector[j];
				j = j - 1;
			}
		}
		vector[j + 1] = key;
	}
}

void Sort::QuickSort(bool ascendent)
{
	sortare(vector, 0, size-1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
	// Outer loop that corresponds to the number of
	// elements to be sorted
	for (int i = 0; i < size - 1; i++) {

		// Last i elements are already
		// in place
		for (int j = 0; j < size - i - 1; j++) {

			// Comparing adjacent elements
			if (ascendent == true)
			{
				if (vector[j] > vector[j + 1])

					// Swapping if in the wrong order
					swap(vector[j], vector[j + 1]);
			}
			else
			{
				if (vector[j] < vector[j + 1])

					// Swapping if in the wrong order
					swap(vector[j], vector[j + 1]);
			}
		}
	}
}



void Sort::Print()
{
	for (int i = 0; i < size; i++)
		cout << vector[i] << " ";
	cout << endl;
}

int Sort::GetElementsCount()
{
	return size;
}

int Sort::GetElementFromIndex(int index)
{
	return vector[index];
}
