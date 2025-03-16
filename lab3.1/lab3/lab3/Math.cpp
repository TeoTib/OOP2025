#include "Math.h"
#include <stdarg.h>
#include <cstring>

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

int Math::Add(double a, double b)
{
	return a + b;
}

int Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

int Math::Mul(double a, double b)
{
	return a * b;
}

int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	int val;
	int sum=0;
	va_list v1;
	va_start(v1, count);
		for (int i = 0; i < count; i++)
		{
			val = va_arg(v1, int);
			sum += val;
		}
	va_end(v1);
	return sum;
}

char* Math::Add(const char* ptr1, const char* ptr2)
{
	if (ptr1==nullptr || ptr2==nullptr)
		return nullptr;
	else
	{
		int size;
		size = strlen(ptr1) + strlen(ptr2) + 1;
		char* newsir = new char[size];
		for (int i = 0; i < strlen(ptr1); i++)
			newsir[i] = ptr1[i];
		for (int i = strlen(ptr1); i < size; i++)
			newsir[i] = ptr2[i];
		newsir[size] = NULL;
	}
}
