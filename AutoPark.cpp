#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>


class Car
{
public:
	int speed;
	std::string number;
	std::string mark;
	int engineVolume;
	int fuel;

	Car(const int& speed, const std::string& number, const std::string& mark, const int& engineVolume, const int& fuel):
		speed(speed), number(number), mark(mark), engineVolume(engineVolume), fuel(fuel){}

	bool operator== (Car& car);
};

bool Car::operator==(Car& car)
{
	return (car.engineVolume == engineVolume && car.fuel == fuel  && car.speed == speed && car.number == number && car.mark == mark) ? true : false;
}


class AutoPark
{
    static std::vector <Car*> Garage;
public:
	~AutoPark()
	{
		for (Car* car : Garage)
		{
			delete car;
			car = nullptr;
		}
	}
	void addCar(Car* car)
	{
		if (car->fuel == 0)
		{
			Garage.push_back(car);
			return;
		}
		std::cout << "Car is not empty" << std::endl;
	}

	void removeCar(const std::string& number)
	{
		for (auto& car : Garage)
		{
			int i = 0;
			if (car->number == number)
			{
				Garage.erase(Garage.begin() + i);
				return;
			}
			
			i++;
		}

		std::cout << "There is not car" << std::endl;
	}

	void fuelCar(const std::string& number,const int& fuel)
	{
		for (auto& car : Garage)
		{
			if (car->number == number)
			{
				car->fuel = fuel;
			}
		}
		std::cout << " There are not car" << std::endl;
	}

	void carInfo(Car& car)
	{
		for (auto& Auto : Garage)
		{
			if (*Auto == car)
			{
				std::cout << "Mark: " << Auto->mark << "; " << "Number: " << Auto->number << "; " << "Volume: " << Auto->engineVolume << "; " << "Fuel: " << Auto->fuel << "; " << "Speed: " << Auto->speed << ";\n";
				return;
			}
			
		}
		std::cout << " There are not car" << std::endl;
	}

	void printInfo()
	{
		for (auto& Auto : Garage)
		{
				std::cout << "Mark: " << Auto->mark << "; " << "Number: " << Auto->number << "; " << "Volume: " << Auto->engineVolume << "; " << "Fuel: " << Auto->fuel << "; " << "Speed: " << Auto->speed << ";\n";
		}
	}

	static AutoPark* createAutoPark(const int& distance)
	{
		
		AutoPark* park = new AutoPark;

		for (const auto& Auto : Garage)
		{
			if (distance == (Auto->fuel / Auto->engineVolume))
			{
				park->addCar(Auto);
				return park;
			}
			else
			{
				return nullptr;
			}
		}
	}
};

int main()
{
//	Car one(80, "AT 12", "BMW", 2, 0);
//	Car Two(90, "NB 22", "Mers", 2, 0);


	AutoPark* park = AutoPark::createAutoPark(10);
	//park->addCar(&one);
	park->printInfo();
	delete park;
	system("pause");
	return 0;
}