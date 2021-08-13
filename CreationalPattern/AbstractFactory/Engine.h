#pragma once
#include <iostream>

using namespace std;

class Engine
{
	//  Абстрактный класс описывающий двигатель
protected:
	unsigned int power;
public:
	Engine(unsigned int power) :power(power) { }
	virtual ~Engine() { }

	virtual unsigned int get_power() const = 0;
	void info()const
	{
		cout << typeid(*this).name() << ";   power: " << power << " hors\n";
	}
};

class SportEngine :public Engine
{
	//  Класс описывающий 'Спортивный жвигатель'
public:
	SportEngine() : Engine(500) { }
	~SportEngine() { }

	unsigned int get_power()const
	{
		return this->power;
	}
};

class TruckEngine :public Engine
{
	//  Класс описывающий 'Двигатель для грузовика'
public:
	TruckEngine() :Engine(1000) { }
	~TruckEngine() { }

	unsigned int get_power()const
	{
		return this->power;
	}
};

class SuvEngine :public Engine
{
	//  Класс описывающий 'Дигатель для внедорожника'
public:
	SuvEngine() :Engine(750) { }
	~SuvEngine() { }

	unsigned int get_power()const
	{
		return this->power;
	}
};