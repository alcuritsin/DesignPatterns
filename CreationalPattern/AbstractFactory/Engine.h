#pragma once
#include <iostream>

using namespace std;

class Engine
{
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

class SportEngine:public Engine
{
public:
	SportEngine(): Engine(500) { }
	~SportEngine() { }

	unsigned int get_power()const
	{
		return this->power;
	}
};

class TruckEngine :public Engine
{
public:
	TruckEngine() :Engine(1000) { }
	~TruckEngine() { }

	unsigned int get_power()const
	{
		return this->power;
	}
};