#include "Seat.h"

Seat::Seat()
{
    fuelCapacity = 55;
    fuelConsumption = 12;
    averageSpeed[0] = 45;
    averageSpeed[1] = 100;
    averageSpeed[2] = 35;
}
float Seat::GetSpeed(Weather weather)
{
    return averageSpeed[static_cast<int>(weather)];
}

float Seat::GetFuelConsumption()
{
    return fuelConsumption;
}

float Seat::GetFuelCapacity()
{
    return fuelCapacity;
}

void Seat::UpdateFuelCapacity(float remaining)
{
    fuelCapacity = remaining;
}

const char* Seat::GetName()
{
    return "Seat";
}
