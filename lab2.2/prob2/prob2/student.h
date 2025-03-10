#pragma once
class student
{
	char name[100];
	float math;
	float english;
	float history;
	float avg;
public:
	void setName(const char* name);
	char* getName();
	void setMath(float math);
	float getMath();
	void setEnglish(float english);
	float getEnglish();
	void setHistory(float history);
	float getHistory();
	float getAverage();
};

