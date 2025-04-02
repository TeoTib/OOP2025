#pragma once
#include "Car.h"
class Circuit
{
private:
	int length;
	Weather weather;
	Car** cars;
	int carCount;
	int capacity;
public:
	Circuit();
	~Circuit();
	void SetLength(int length);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

