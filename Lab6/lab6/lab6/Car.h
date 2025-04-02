#pragma once
#include "Weather.h"

class Car {
protected:
	float fuelCapacity;
	float fuelConsumption;
	float averageSpeed[3];
public:
	virtual ~Car(){}
	virtual float GetSpeed(Weather weather) = 0;
	virtual float GetFuelConsumption() = 0;
	virtual float GetFuelCapacity() = 0;
	virtual void UpdateFuelCapacity(float remaining) = 0;
	virtual const char* GetName() = 0;
};
