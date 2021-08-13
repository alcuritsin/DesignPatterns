#pragma once

#include "Engine.h"
#include "Tank.h"
#include "Wheel.h"

class AbstractFactory
{
public:
	virtual Engine* createEngine() = 0;
	virtual Tank* createTank() = 0;
	virtual Wheel* createWheel() = 0;
};

class SportCarFactory :public AbstractFactory
{
	//	Фабрика по производству 'Спорткаров'
public:
	Engine* createEngine()
	{
		return new SportEngine;
	}
	Tank* createTank()
	{
		return new SportTank;
	}
	Wheel* createWheel()
	{
		return new SportWheel;
	}
};

class TruckFactory :public AbstractFactory
{
	//	Фабрика по производству 'Грузовиков'
public:
	Engine* createEngine()
	{
		return new TruckEngine;
	}
	Tank* createTank()
	{
		return new TruckTank;
	}
	Wheel* createWheel()
	{
		return new TruckWheel;
	}
};