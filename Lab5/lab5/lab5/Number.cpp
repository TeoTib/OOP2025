#include "Number.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


Number::Number(const char* value, int base)
{
	number = new char[strlen(value) + 1];
	strcpy_s(number, strlen(value)+1, value);
	this->base = base;
}

Number::Number(Number& n)
{
    //initializez this in functie de n
    //da tre sa si aloc spatiu
    number = new char[strlen(n.number) + 1];
    strcpy_s(number, strlen(n.number) + 1, n.number);
    base = n.base;
}

Number::Number(Number&& n)
{
    number = n.number;
    base = n.base;
    n.number = nullptr;
    n.base = 0;

}

Number& Number::operator=(Number&& n)
{
    if (this != &n)
    {
        delete[] number;
        number = n.number;
        base = n.base;
        n.number = nullptr;
        n.base = 0;
    }
    return *this;
}

Number::~Number()
{
	delete[] number;
}

char Number::operator[](int index)
{
    return number[index];
}

bool Number::operator>(const Number& other)
{
    //daca this e > other -> true altfel false
    int nr1, nr2;
    nr1 = strtol(number, nullptr, base);
    nr2 = strtol(other.number, nullptr, other.base);
    if (nr1 > nr2)
        return true;
    return false;
}

bool Number::operator<(const Number& other)
{
    int nr1, nr2;
    nr1 = strtol(number, nullptr, base);
    nr2 = strtol(other.number, nullptr, other.base);
    if (nr1 > nr2)
        return false;
    return true;
}

bool Number::operator>=(const Number& other)
{
    int nr1, nr2;
    nr1 = strtol(number, nullptr, base);
    nr2 = strtol(other.number, nullptr, other.base);
    if (nr1 >= nr2)
        return true;
    return false;
}

bool Number::operator<=(const Number& other)
{
    int nr1, nr2;
    nr1 = strtol(number, nullptr, base);
    nr2 = strtol(other.number, nullptr, other.base);
    if (nr1 <= nr2)
        return true;
    return false;
}

bool Number::operator==(const Number& other)
{
    int nr1, nr2;
    nr1 = strtol(number, nullptr, base);
    nr2 = strtol(other.number, nullptr, other.base);
    if (nr1 == nr2)
        return true;
    return false;
}

Number& Number::operator--()
{
    //remove first digit
    char* newnum = new char[strlen(number)];
    int i;
    for (i = 0; i < strlen(number) - 1; i++)
        newnum[i] = number[i + 1];
    newnum[i] = '\0';
    delete[] number;
    number = newnum;
    return *this;
}

Number Number::operator--(int value)
{
    int size = strlen(number);
    char* newnum = new char[size];
    for (int i = 0; i < size - 1; i++)
        newnum[i] = number[i];
    newnum[size - 1] = '\0';
    delete[] number;
    number = newnum;
    return *this;
}


void Number::SwitchBase(int newBase)
{
	int decimal = strtol(number, nullptr, base);
    char buffer[65];
    int index = 0;

    const char digits[] = "0123456789ABCDEF";

    if (decimal == 0) {
        buffer[index++] = '0';
    }
    else {
        while (decimal > 0) {
            buffer[index++] = digits[decimal % newBase];
            decimal /= newBase;
        }
    }

    buffer[index] = '\0';

    // Reverse the result to get the correct order
    for (int i = 0; i < index / 2; ++i) {
        swap(buffer[i], buffer[index - i - 1]);
    }
    //realoca number, pune valoarea schimbata
    delete[] number;
    number = new char[index + 1];
    strcpy_s(number, index + 1, buffer);
    //schimba baza
    base = newBase;
}

void Number::Print()
{
	cout << number<<endl;
}

int Number::GetDigitsCount()
{
	return strlen(number);
}

int Number::GetBase()
{
	return this->base;
}

Number operator+(const Number& n1, const Number& n2)
{
    int baza;
    if (n1.base > n2.base)
        baza = n1.base;
    else
        baza = n2.base;
    //aducem numerele in baza 10, le adunam si rezultatul il rescriem in baza mai mare
    int nr1, nr2, rez;
    nr1= strtol(n1.number, nullptr, n1.base);
    nr2= strtol(n2.number, nullptr, n2.base);
    rez = nr1 + nr2;
    char* buffer = new char[65];
    int index = 0;

    const char digits[] = "0123456789ABCDEF";

    if (rez == 0) {
        buffer[index++] = '0';
    }
    else {
        while (rez > 0) {
            buffer[index++] = digits[rez % baza];
            rez /= baza;
        }
    }

    buffer[index] = '\0';

    // Reverse the result to get the correct order
    for (int i = 0; i < index / 2; ++i) {
        swap(buffer[i], buffer[index - i - 1]);
    }
    Number rezultat(buffer, baza);
    delete[] buffer;
    return rezultat;
}

Number operator-(const Number& n1, const Number& n2)
{
    int baza;
    if (n1.base > n2.base)
        baza = n1.base;
    else
        baza = n2.base;
    //aducem numerele in baza 10, le adunam si rezultatul il rescriem in baza mai mare
    int nr1, nr2, rez;
    nr1 = strtol(n1.number, nullptr, n1.base);
    nr2 = strtol(n2.number, nullptr, n2.base);
    rez = nr1 - nr2;
    char* buffer = new char[65];
    int index = 0;

    const char digits[] = "0123456789ABCDEF";

    if (rez == 0) {
        buffer[index++] = '0';
    }
    else {
        while (rez > 0) {
            buffer[index++] = digits[rez % baza];
            rez /= baza;
        }
    }

    buffer[index] = '\0';

    // Reverse the result to get the correct order
    for (int i = 0; i < index / 2; ++i) {
        swap(buffer[i], buffer[index - i - 1]);
    }
    Number rezultat(buffer, baza);
    delete[] buffer;
    return rezultat;
}
