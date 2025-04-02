#pragma once
#include "Car.h"
class Seat : public Car
{
public:
	Seat();
	float GetSpeed(Weather weather) override;
	float GetFuelConsumption() override;
	float GetFuelCapacity() override;
	void UpdateFuelCapacity(float remaining) override;
	const char* GetName() override;
};

