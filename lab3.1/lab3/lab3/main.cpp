#include <iostream>
#include "Math.h"
using namespace std;

int main()
{
	Math m;
	cout << m.Add(2, 3) << endl << m.Add(1, 1, 1)<<endl;
	cout << m.Add(3.5, 1.5) << endl << m.Add(1.2, 1.3, 1.5) << endl;
	cout << m.Mul(2, 3) << endl;
	cout << m.Mul(2, 2, 3) << endl;
	cout << m.Mul(1.5, 4.0) << endl << m.Mul(1.5, 4.0, 3.0) <<endl;
}