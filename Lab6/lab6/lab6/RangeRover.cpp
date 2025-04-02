#include "RangeRover.h"

RangeRover::RangeRover()
{
    fuelCapacity = 70;
    fuelConsumption = 15;
    averageSpeed[0] = 70;
    averageSpeed[1] = 135;
    averageSpeed[2] = 65;
}
float RangeRover::GetSpeed(Weather weather)
{
    return averageSpeed[static_cast<int>(weather)];
}

float RangeRover::GetFuelConsumption()
{
    return fuelConsumption;
}

float RangeRover::GetFuelCapacity()
{
    return fuelCapacity;
}

void RangeRover::UpdateFuelCapacity(float remaining)
{
    fuelCapacity = remaining;
}

const char* RangeRover::GetName()
{
    return "RangeRover";
}
