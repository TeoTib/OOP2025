#pragma once
class Number
{
	char* number;
	int base;
public:
	//constructor
	Number(const char* value, int base); // where base is between 2 and 16
	//copy constructor
	Number(Number& n);
	//move constructor
	Number(Number&& n);
	//move assignment operator
	Number& operator= (Number&& n);
	//destructor
	~Number();


	//addition
	friend Number operator+(const Number& n1, const Number& n2);
	//substraction
	friend Number operator-(const Number& n1, const Number& n2);
	//index
	char operator [](int index);
	//relation
	bool operator>(const Number& other);
	bool operator<(const Number& other);
	bool operator>=(const Number& other);
	bool operator<=(const Number& other);
	bool operator==(const Number& other);
	// --
	Number& operator--(); //prefix
	Number operator--(int value); //postfix



	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};

