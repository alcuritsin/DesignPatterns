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
	//	������� �� ������������ '����������'
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
	//	������� �� ������������ '����������'
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

class SuvFactory :public AbstractFactory
{
	//	������� �� ������������ '����������'
public:
	Engine* createEngine()
	{
		return new SuvEngine;
	}
	Tank* createTank()
	{
		return new SuvTank;
	}
	Wheel* createWheel()
	{
		return new SuvWheel;
	}
};
