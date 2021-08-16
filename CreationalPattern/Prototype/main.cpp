#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<string>
#include<ctime>
#include<map>

using namespace std;

//  Абстрактный прототип:
class BMW
{
protected:
	const unsigned int MAX_SPEED;
	const unsigned int DOOR;
public:
	BMW(const unsigned int max_speed, const unsigned int doors) : MAX_SPEED(max_speed), DOOR(doors) { }
	virtual ~BMW() { }
	virtual BMW* clone()const = 0; //  Просто чтобы сделать класс абстрактным. Чисто виртуальный метод.
	void info() const
	{
		cout << this << " : " << typeid(*this).name() << "\t";
		cout << "max_speed: " << MAX_SPEED << "\t doors: " << DOOR << endl;
	}
};

//  Конкретные прототипы:
class BMW_3 : public BMW
{
public:
	BMW_3() :BMW(220, 3) { }
	~BMW_3() { }
	BMW* clone() const
	{
		return new BMW_3(*this);
	}
};
class BMW_5 : public BMW
{
public:
	BMW_5() :BMW(250, 4) { }
	~BMW_5() { }
	BMW* clone() const
	{
		return new BMW_5(*this);
	}
};
class BMW_7 : public BMW
{
public:
	BMW_7() :BMW(280, 5) { }
	~BMW_7() { }
	BMW* clone() const
	{
		return new BMW_7(*this);
	}
};

class BMWFactory
{
	static map<int, BMW*> prototype;
public:
	static BMW* create_model(int model)  
	{
		return prototype[model]->clone();
	}

};

map<int, BMW*> BMWFactory::prototype =
{
	std::pair<int, BMW*>(3, new BMW_3),
	std::pair<int, BMW*>(5, new BMW_5),
	std::pair<int, BMW*>(7, new BMW_7)
};

void main()
{
	setlocale(LC_ALL, "ru-RU");
	srand(time(NULL));

	BMW* bmw = BMWFactory::create_model(3); bmw->info();
	BMW* bmw3 = BMWFactory::create_model(3); bmw3->info();

}