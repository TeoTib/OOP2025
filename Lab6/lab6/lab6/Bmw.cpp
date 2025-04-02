#include "Bmw.h"
Bmw::Bmw()
{
    fuelCapacity = 35;
    fuelConsumption = 9;
    averageSpeed[0] = 65;
    averageSpeed[1] = 120;
    averageSpeed[2] = 55;
}

float Bmw::GetSpeed(Weather weather)
{
    return averageSpeed[static_cast<int>(weather)];
}

float Bmw::GetFuelConsumption()
{
    return fuelConsumption;
}

float Bmw::GetFuelCapacity()
{
    return fuelCapacity;
}

void Bmw::UpdateFuelCapacity(float remaining)
{
    fuelCapacity = remaining;
}

const char* Bmw::GetName()
{
    return "BMW";
}
