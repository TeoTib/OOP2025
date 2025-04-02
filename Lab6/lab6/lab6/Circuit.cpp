#include "Circuit.h"
#include <iostream>
using namespace std;

Circuit::Circuit()
{
	length = 0;
	weather = Weather::Sunny;
	carCount = 0;
	capacity = 5;
	cars = new Car * [capacity];
}

Circuit::~Circuit()
{
	for (int i = 0; i < carCount; i++)
		delete cars[i];
	delete[] cars;
}

void Circuit::SetLength(int length)
{
	this->length = length;
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}

void Circuit::AddCar(Car* car)
{
	///tre sa adaug inca un spatiu pentru car, ceea ce inseamna nou vector, copiere de elemente, stergerea vectorului vechi + elem nou
	///sterg ce era inainte doar daca carcount >= capacity
	if (carCount >= capacity)
	{
		capacity *= 2;
		Car** newCars = new Car * [capacity];
		for (int i = 0; i < carCount; i++)
			newCars[i] = cars[i];
		delete[] cars;
		cars = newCars;
	}
	cars[carCount++] = car;
}

void Circuit::Race()
{
	for (int i = 0; i < carCount - 1; ++i) {
		for (int j = i + 1; j < carCount; ++j) {
			///daca au enough fuel amandoua, calculam timpul necesar terminarii
			float fuelRemaining1 = cars[i]->GetFuelCapacity() - (cars[i]->GetFuelConsumption() * length / 100);
			float fuelRemaining2 = cars[j]->GetFuelCapacity() - (cars[j]->GetFuelConsumption() * length / 100);
			///pt showwhodidnotfinish, updatam fuelcapacity
			cars[i]->UpdateFuelCapacity(fuelRemaining1);
			cars[j]->UpdateFuelCapacity(fuelRemaining2);
			float time1 = static_cast<float>(length) / cars[i]->GetSpeed(weather);
			float time2 = static_cast<float>(length) / cars[j]->GetSpeed(weather);
			if (time1 > time2) {
				Car* temp = cars[i];
				cars[i] = cars[j];
				cars[j] = temp;
			}
		}
	}
}

void Circuit::ShowFinalRanks()
{
	for (int i = 0; i < carCount; i++)
	{
		if (cars[i]->GetFuelCapacity() >= 0)
			cout << cars[i]->GetName() << " a terminat in " << (length / cars[i]->GetSpeed(weather))<<" si mai are "<<cars[i]->GetFuelCapacity()<<"L" << endl;
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < carCount; i++)
		if (cars[i]->GetFuelCapacity() < 0)
			cout << cars[i]->GetName() << " nu a terminat cursa" << endl;
}
