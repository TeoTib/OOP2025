#include "Volvo.h"

Volvo::Volvo()
{
	fuelCapacity = 20;
	fuelConsumption = 8;
	averageSpeed[0] = 60;
	averageSpeed[1] = 100;
	averageSpeed[2] = 50;
}

float Volvo::GetSpeed(Weather weather)
{
	return averageSpeed[static_cast<int>(weather)];
}

float Volvo::GetFuelConsumption()
{
	return fuelConsumption;
}

float Volvo::GetFuelCapacity()
{
	return fuelCapacity;
}

void Volvo::UpdateFuelCapacity(float remaining)
{
	fuelCapacity = remaining;
}

const char* Volvo::GetName()
{
	return "Volvo";
}
