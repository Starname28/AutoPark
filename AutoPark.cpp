#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>


class Car
{
	int speed;
	std::string number;
	std::string mark;
	int engineVolume;
	int fuel;
public:
	
	Car(const int& speed, const std::string& number, const std::string& mark, const int& engineVolume, const int& fuel):
		speed(speed), number(number), mark(mark), engineVolume(engineVolume), fuel(fuel){}
	
	int getSpeed()const
	{
		return speed;
	}

	void setSpeed(const int& speed)
	{
		this->speed = speed;
	}

	std::string getNumber()const
	{
		return number;
	}

	void setNumber(const std::string& number)
	{
		this->number = number;
	}

	std::string getMark()const
	{
		return mark;
	}

	void setMark(const std::string& mark)
	{
		this->mark = mark;
	}

	int getEngineVolume()const
	{
		return engineVolume;
	}

	void setEngineVolume(const int& engineVolume)
	{
		this->engineVolume = engineVolume;
	}

	int getFuel()const
	{
		return fuel;
	}

	void setFuel(const int& fuel)
	{
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
		if (car->getFuel() == 0)
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
			if (car->getNumber() == number)
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
			if (car->getNumber() == number)
			{
				car->setFuel(fuel);
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
				std::cout << "Mark: " << Auto->getMark() << "; " << "Number: " << Auto->getNumber() << "; " << "Volume: " << Auto->getEngineVolume() << "; " << "Fuel: " << Auto->getFuel() << "; " << "Speed: " << Auto->getSpeed() << ";\n";
				return;
			}
			
		}
		std::cout << " There are not car" << std::endl;
	}

	void printInfo()
	{
		for (auto& Auto : Garage)
		{
			std::cout << "Mark: " << Auto->getMark() << "; " << "Number: " << Auto->getNumber() << "; " << "Volume: " << Auto->getEngineVolume() << "; " << "Fuel: " << Auto->getFuel() << "; " << "Speed: " << Auto->getSpeed() << ";\n";
		}
	}

	static AutoPark* createAutoPark(const int& distance)
	{
		
		AutoPark* park = new AutoPark;

		for (const auto& Auto : Garage)
		{
			if (distance == (Auto->getFuel() / Auto->getEngineVolume()))
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