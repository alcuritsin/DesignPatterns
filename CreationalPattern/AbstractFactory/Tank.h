#pragma once
#include <iostream>

using namespace std;

class Tank
{
	//  Абстрактный класс описывающий бак
protected:
	unsigned int volume;
public:
	Tank(unsigned int volume) :volume(volume) { }
	virtual ~Tank() { }

	virtual unsigned int get_volume()const = 0;

	void info()const
	{
		cout << typeid(*this).name() << ";   volume: " << volume << " l\n";
	}
};

class SportTank :public Tank
{
	//  Класс описывающий 'Бак для спорткара'
public:
	SportTank() : Tank(80) { }
	~SportTank() { }
	unsigned int get_volume()const
	{
		return this->volume;
	}
};

class TruckTank :public Tank
{
	//  Класс описывающий 'Бак для грузовика'
public:
	TruckTank() :Tank(2000) { }
	~TruckTank() { }
	unsigned int get_volume()const
	{
		return this->volume;
	}
};

class SuvTank :public Tank
{
	//  Класс описывающий 'Бак для вездехода'
public:
	SuvTank() :Tank(500) { }
	~SuvTank() { }
	unsigned int get_volume()const
	{
		return this->volume;
	}
};