#include "pch.h"
#include "Source.cpp"
#include <gtest/gtest.h>

TEST(test, toatenr)
{
    int array[] = { 453, 23, 67, 24, 22, 10, 9, 7, 4 };
    int size = 9;
    Sort <int> obj(array, size);
    obj.bubbleSort();
    EXPECT_EQ(size, obj.GetSize());
}

TEST(test, descrescator)
{
    int array[] = { 453, 23, 67, 24, 22, 10, 9, 7, 4 };
    int size = 9;
    Sort <int> obj(array, size);
    obj.bubbleSort();
    int sorted[] = { 4, 7, 9, 10, 22, 24, 67, 23, 453 };
    for (int i = 0; i < size; i++)
        EXPECT_EQ(sorted[i], obj.Get(i));
}

TEST(test, crescator)
{
    int array[] = { 4, 7, 9, 10, 22, 24, 67, 23, 453 };
    int size = 9;
    Sort <int> obj(array, size);
    obj.bubbleSort();
    int sorted[] = { 4, 7, 9, 10, 22, 24, 67, 23, 453 };
    for (int i = 0; i < size; i++)
        EXPECT_EQ(sorted[i], obj.Get(i));
}

TEST(test, random)
{
    int array[] = { 23, 4, 67, 453, 9, 10, 7, 24, 22 };
    int size = 9;
    Sort <int> obj(array, size);
    obj.bubbleSort();
    int sorted[] = { 4, 7, 9, 10, 22, 24, 67, 23, 453 };
    for (int i = 0; i < size; i++)
        EXPECT_EQ(sorted[i], obj.Get(i));
}

TEST(test, doidepatru)
{
    int array[] = { 23, 4, 67, 453, 9, 10, 4, 24, 22 };
    int size = 9;
    Sort <int> obj(array, size);
    obj.bubbleSort();
    int sorted[] = { 4, 4, 9, 10, 22, 24, 67, 23, 453 };
    for (int i = 0; i < size; i++)
        EXPECT_EQ(sorted[i], obj.Get(i));
}

TEST(test, toateegale)
{
    int array[] = { 5, 5, 5};
    int size = 3;
    Sort <int> obj(array, size);
    obj.bubbleSort();
    int sorted[] = {5, 5, 5};
    for (int i = 0; i < size; i++)
        EXPECT_EQ(sorted[i], obj.Get(i));
}

TEST(test, unsingurnumar)
{
    int array[] = { 1 };
    int size = 3;
    Sort <int> obj(array, size);
    obj.bubbleSort();
    int sorted[] = { 1 };
    for (int i = 0; i < size; i++)
        EXPECT_EQ(sorted[i], obj.Get(i));
}
