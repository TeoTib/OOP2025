#pragma once
#include "Car.h"
class Fiat : public Car
{
public:
	Fiat();
	float GetSpeed(Weather weather) override;
	float GetFuelConsumption() override;
	float GetFuelCapacity() override;
	void UpdateFuelCapacity(float remaining) override;
	const char* GetName() override;
};

