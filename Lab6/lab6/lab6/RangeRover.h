#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
	RangeRover();
	float GetSpeed(Weather weather) override;
	float GetFuelConsumption() override;
	float GetFuelCapacity() override;
	void UpdateFuelCapacity(float remaining) override;
	const char* GetName() override;
};

