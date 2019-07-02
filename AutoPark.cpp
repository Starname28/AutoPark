#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car
{
public:
	int speed;
	std::string number;
	std::string mark;
	int engineVolume;
	int fuel;

	Car(int speed, std::string number, std::string mark, int engineVolume, int fuel)
	{
		this->speed = speed;
		this->number = number;
		this->mark = mark;
		this->engineVolume = engineVolume;
		this->fuel = fuel;
	}

	bool operator== (Car& car);
};

bool Car::operator==(Car& car)
{
	return (car.engineVolume == engineVolume && car.fuel == fuel  && car.speed == speed && car.number == number && car.mark == mark) ? true : false;
}


class AutoPark
{
public:

	std::vector <Car> Garage;

	void addCar(Car car)
	{
		if (car.fuel == 0)
		{
			Garage.push_back(car);
		}
	}

	void removeCar(std::string number)
	{
		for (auto& car : Garage)
		{
			int i = 0;
			int count = 0;

			if (car.number == number)
			{
				Garage.erase(Garage.begin() + i);
				count++;
			}
			else if (i == Garage.size() && count == 0)
			{
				std::cout << "There are no car" << std::endl;
			}
			i++;
		}
	}

	void fuelCar(std::string number, int fuel)
	{
		int i = 0;
		int count = 0;

		for (auto& car : Garage)
		{
			if (car.number == number)
			{
				car.fuel = fuel;
				i++;
			}
			else if (Garage.size()== count && i == 0)
			{
				std::cout << "There are no car" << std::endl;
			}
		}
	}

	void carInfo(Car& car)
	{
		for (auto& Auto : Garage)
		{
			int i = 0;
			int count = 0;

			if (Auto == car)
			{
				std::cout << "Mark: " << Auto.mark << "; " << "Number: " << Auto.number << "; " << "Volume: " << Auto.engineVolume << "; " << "Fuel: " << Auto.fuel << "; " << "Speed: " << Auto.speed << ";\n";
				i++;
			}
			else if(Garage.size()== count && i == 0)
			{
				std::cout << "There are no car" << std::endl;
			}
		}
	}

	Car* getCar(int distance)
	{
		Car* car = nullptr;

		for (auto& Auto : Garage)
		{
			if (distance == (Auto.fuel / Auto.engineVolume))
			{
				car = &Auto;
				return car;
			}
			else
			{
				return car;
			}
		}
	}
};

int main()
{
	Car one(80, "AT 12", "BMW", 2, 0);
	Car Two(90, "NB 22", "Mers", 2, 0);

	AutoPark Garage;

	Garage.addCar(one);
	Garage.fuelCar("AT 12", 80);

	Garage.addCar(Two);
	//Garage.fuelCar("NB 22", 0);

	Garage.carInfo(Two);
	Garage.fuelCar("NB 22", 10);
	Garage.carInfo(Two);
	system("pause");
	return 0;
}