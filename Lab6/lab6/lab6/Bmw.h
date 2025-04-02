#pragma once
#include "Car.h";
class Bmw : public Car
{
public:
	Bmw();
	float GetSpeed(Weather weather) override;
	float GetFuelConsumption() override;
	float GetFuelCapacity() override;
	void UpdateFuelCapacity(float remaining) override;
	const char* GetName() override;
};

