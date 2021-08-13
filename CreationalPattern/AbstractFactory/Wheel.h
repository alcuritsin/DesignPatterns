#pragma once
#include <iostream>

using namespace std;

class Wheel
{
	//  Абстрактный класс описывающий колёса
protected:
	unsigned int diameter;
public:
	Wheel(unsigned int diameter) : diameter(diameter) { }
	virtual ~Wheel() { }

	virtual unsigned int get_diametr() const = 0;

	void info() const
	{
		cout << typeid(*this).name() << ";   diameter: " << diameter << " inch\n";
	}
};

class SportWheel :public Wheel
{
	//  Класс описывающий 'Колёса для спорткара'
public:
	SportWheel() : Wheel(26) { }
	~SportWheel() { }
	unsigned int get_diametr() const
	{
		return this->diameter;
	}
};

class TruckWheel :public Wheel
{
	//  Класс описывающий 'Колёса для грузовика'
public:
	TruckWheel() : Wheel(24) { }
	~TruckWheel() { }
	unsigned int get_diametr() const
	{
		return this->diameter;
	}
};

class SuvWheel :public Wheel
{
	//  Класс описывающий 'Колёса для вездехода'
public:
	SuvWheel() : Wheel(22) { }
	~SuvWheel() { }
	unsigned int get_diametr() const
	{
		return this->diameter;
	}
};