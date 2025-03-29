#pragma once
#include <initializer_list>
using namespace std;
class Sort
{
    int* vector;
    int size;
public:
    Sort(int no, int min, int max);
    Sort(initializer_list<int> list);
    Sort(int v[], int size);
    Sort(int count, ...);
    Sort(char string[]);
    void InsertSort(bool ascendent);
    void QuickSort(bool ascendent);
    void BubbleSort(bool ascendent);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

