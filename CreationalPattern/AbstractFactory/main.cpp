/*
TODO:
1. [x] Добавить на фабрику производство колес;
2. [ ] Фабрика должна начать производство внедорожников;
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<string>
#include<ctime>

#include "Factory.h"

using namespace std;

class SportCar
{
	//  Класс описывающий 'Спорткар'
	Engine* engine;
	Tank* tank;
	Wheel* wheel;
public:
	SportCar(SportCarFactory* factory)
	{
		this->engine = factory->createEngine();
		this->tank = factory->createTank();
		this->wheel = factory->createWheel();
	}
	~SportCar() { }

	void info() const
	{
		engine->info();
		tank->info();
		wheel->info();
	}
};

class Truck
{
	//  Класс описывающий 'Грузовик'
	Engine* engine;
	Tank* tank;
	Wheel* wheel;
public:
	Truck(TruckFactory* factory)
	{
		this->engine = factory->createEngine();
		this->tank = factory->createTank();
		this->wheel = factory->createWheel();
	}
	~Truck() { }

	void info() const
	{
		engine->info();
		tank->info();
		wheel->info();
	}
};

void main()
{
	setlocale(LC_ALL, "ru-RU");
	srand(time(NULL));

	cout << ":: SportCar ::" << endl;
	SportCar lambargini(new SportCarFactory);
	lambargini.info();
	cout << endl;

	cout << ":: Truck ::" << endl;
	Truck hugle(new TruckFactory);
	hugle.info();
	cout << endl;
}