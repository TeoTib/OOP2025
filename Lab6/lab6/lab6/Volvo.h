#pragma once
#include "Car.h"

class Volvo :public Car {
public:
	Volvo();
	float GetSpeed(Weather weather) override;
	float GetFuelConsumption() override;
	float GetFuelCapacity() override;
	void UpdateFuelCapacity(float remaining) override;
	const char* GetName() override;
};
