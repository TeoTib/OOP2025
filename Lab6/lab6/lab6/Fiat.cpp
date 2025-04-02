#include "Fiat.h"

Fiat::Fiat()
{
    fuelCapacity = 50;
    fuelConsumption = 6;
    averageSpeed[0] = 41;
    averageSpeed[1] = 90;
    averageSpeed[2] = 32;
}
float Fiat::GetSpeed(Weather weather)
{
    return averageSpeed[static_cast<int>(weather)];
}

float Fiat::GetFuelConsumption()
{
    return fuelConsumption;
}

float Fiat::GetFuelCapacity()
{
    return fuelCapacity;
}

void Fiat::UpdateFuelCapacity(float remaining)
{
    fuelCapacity = remaining;
}

const char* Fiat::GetName()
{
    return "Fiat";
}
