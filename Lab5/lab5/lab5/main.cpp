#include <iostream>
#include "Number.h"
using namespace std;


int main()
{
	Number n1("10110010", 2);
	Number n2("734", 8);
	Number n3("FF", 16);
	printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
	n3.Print();
	n3.SwitchBase(10);
	n3.Print();
	Number n4 = n2;
	n4.Print();
	Number n5 = move(n1);
	n5.Print();
	Number n6("101", 2);
	Number n7("15", 10);
	Number n8 = n6 + n7;
	n8.Print();
	n8 = n7 - n6+n3;
	n8.Print();
	if (n8 > n5) cout << "e mai mare"<<endl;
	if (n5 < n8) cout << "e mai mic"<<endl;
	n8--;
	n8.Print();
	--n5;
	n5.Print();
	cout << n8[1];
}


