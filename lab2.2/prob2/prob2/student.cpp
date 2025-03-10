#include "student.h"
#include <cstring>
#include <iostream>
using namespace std;



void student::setName(const char* name)
{
	strcpy_s(this->name, 20, name);
}

char* student::getName()
{
	return name;
}

void student::setMath(float math)
{
	this->math = math;
}

float student::getMath()
{
	return math;
}

void student::setEnglish(float english)
{
	this->english = english;
}

float student::getEnglish()
{
	return english;
}

void student::setHistory(float history)
{
	this->history = history;
}

float student::getHistory()
{
	return history;
}

float student::getAverage()
{
	avg = (math + history + english) / 3;
	return avg;
}
