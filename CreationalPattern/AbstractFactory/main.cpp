#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<string>
#include<ctime>

#include "Factory.h"

using namespace std;

class SportCar
{
	Engine* engine;
	Tank* tank;
public:
	SportCar(SportCarFactory* factory)
	{
		this->engine = factory->createEngine();
		this->tank = factory->createTank();
	}
	~SportCar() { }

	void info() const
	{
		engine->info();
		tank->info();
	}
};

class Truck
{
	Engine* engine;
	Tank* tank;
public:
	Truck(TruckFactory* factory)
	{
		this->engine = factory->createEngine();
		this->tank = factory->createTank();
	}
	~Truck() { }

	void info() const
	{
		engine->info();
		tank->info();
	}
};

void main()
{
	setlocale(LC_ALL, "ru-RU");
	srand(time(NULL));

	SportCar lambargini(new SportCarFactory);
	lambargini.info();

	Truck hugle (new TruckFactory);
	hugle.info();

}