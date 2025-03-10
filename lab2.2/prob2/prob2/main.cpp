#include <iostream>
#include "student.h"
#include "functii.h"
using namespace std;

int main()
{
	student s1, s2;
	s1.setName("Teo");
	s1.setMath(8.3);
	s1.setEnglish(9.5);
	s1.setHistory(3.1);
	cout <<s1.getName()<<endl<< s1.getMath() << endl << s1.getEnglish() << endl << s1.getHistory() << endl << s1.getAverage()<<endl;
	s2.setName("Andrei");
	s2.getName();
	s2.setMath(3.7);
	s2.setEnglish(8.7);
	s2.setHistory(5.2);
	cout <<s2.getName()<<endl<< s2.getMath() << endl << s2.getEnglish()<<endl<<s2.getHistory()<<endl<<s2.getAverage()<<endl;
	cout << compName(s1.getName(), s2.getName())<<endl;
	cout << compGrade(s1.getAverage(), s2.getAverage())<<endl;
}