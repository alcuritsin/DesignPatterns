#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<string>
#include<ctime>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Human
{
	unsigned int hp;
	unsigned int damage;
	unsigned int armor;
public:
	Human(unsigned int hp, unsigned int damage, unsigned int armor)
	{
		this->hp = hp;
		this->damage = damage;
		this->armor = armor;
	}
	virtual ~Human()
	{
		cout << "No Human - No problem" << endl;
	}

	virtual void info() const
	{
		cout << "\n---------------------------------------------------------\n";
		cout << typeid(* this).name() << endl;
		cout << "    hp: " << hp << "\t";
		cout << " armor: " << armor << "\t";
		cout << "damage: " << damage << "\n";
	}
};

class Traveller : public Human
{
public:
	Traveller(unsigned int hp, unsigned int damage, unsigned int armor):Human(hp,damage,armor) { }
	~Traveller() { }
};

class PoliceOficer :public Human
{
	std::string weapon;
public:
	PoliceOficer(unsigned int hp, unsigned int damage, unsigned int armor, const std::string weapon) :Human(hp, damage, armor)
	{
		this->weapon = weapon;
	}
	~PoliceOficer() { }
	void info() const
	{
		Human::info();
		cout << "weapon: " << weapon << endl;
	}
};

class Bandit:public Human
{
	std::string weapon;
public:
	Bandit(unsigned int hp, unsigned int damage, unsigned int armor, const std::string weapon ="") :Human(hp, damage, armor)
	{
		this->weapon = weapon;
	}
	~Bandit() { }
	void info() const
	{
		Human::info();
		cout << "weapon: " << weapon << endl;
	}
};

enum HumanType
{
	Traveller,
	PoliceOfficer,
	Bandit
};

std::string weapons[] =
{
	"",
	"Knife",
	"Beretta",
	"SPAS-12",
	"Ingram",
	"M4A1"
};

Human* humanFactory(HumanType human_type)
{
	switch (human_type)
	{
	case Traveller:
		return new class Traveller(100, rand() % 10 + 10, 0);
		break;
	case PoliceOfficer:
		return new class PoliceOficer (100, rand() % 10 + 20, 100, "Beretta");
		break;
	case Bandit:
		return new class Bandit (rand()%50+50, rand() % 10 + 30, rand()%20+80, weapons[rand()%(sizeof(weapons)/sizeof(std::string))]);
		break;
	default:
		break;
	}
}

enum MovingOn
{
	Earth,
	Water,
	Air
};

class Transport
{
	unsigned int hp;
	unsigned int damage;
	unsigned int speed;
	MovingOn moving_on;

public:
	Transport(unsigned int hp, unsigned int damage, unsigned int speed, MovingOn moving_on)
	{
		this->hp = hp;
		this->damage = damage;
		this->speed = speed;
		this->moving_on = moving_on;
	}
	virtual ~Transport()
	{
		cout << "Transport dematerialise\n";
	}
	virtual void info() const
	{
		cout << "\n---------------------------------------------------------\n";
		cout << typeid(*this).name() << endl;
		cout << "    hp: " << hp << "\t";
		cout << "damage: " << damage << "\n";
		cout << " speed: " << speed << "\n";
	}
};

class Car : public Transport
{
public:
	Car(unsigned int hp, unsigned int damage, unsigned int speed, MovingOn moving_on):Transport(hp,damage,speed,moving_on) { }
	~Car() { }
	void info()const
	{
		Transport::info();
		cout << "moving: " << "по земле" << "\n";
	}
};

class Plane : public Transport
{
public:
	Plane(unsigned int hp, unsigned int damage, unsigned int speed, MovingOn moving_on):Transport(hp,damage,speed,moving_on) { }
	~Plane() { }
	void info()const
	{
		Transport::info();
		cout << "moving: " << "по воздуху" << "\n";
	}

};

class Boat : public Transport
{
public:
	Boat(unsigned int hp, unsigned int damage, unsigned int speed, MovingOn moving_on):Transport(hp,damage,speed,moving_on) { }
	~Boat() { }
	void info()const
	{
		Transport::info();
		cout << "moving: " << "по воде" << "\n";
	}
};

enum TransportType
{
	Car,
	Plane,
	Boat
};

Transport* transportFactory(TransportType transport_type)
{
	switch (transport_type)
	{
	case Car:
		return new class Car(100, rand() % 20 + 40, rand() % 50 + 70, Earth);
		break;
	case Plane:
		return new class Plane(100, 100, rand() % 50 + 70, Air);
		break;
	case Boat:
		return new class Plane(100, rand() % 20 + 20, rand() % 20 + 30, Water);
		break;
	}
}
//#define FACTORY_CHECK_1

void main()
{
	setlocale(LC_ALL, "ru-RU");
	srand(time(NULL));

#ifdef FACTORY_CHECK_1
	Human* t = humanFactory(Traveller);
	t->info();

	Human* p = humanFactory(PoliceOfficer);
	p->info();

	Human* b = humanFactory(Bandit);
	b->info();
#endif // FACTORY_CHECK_1

	const int n = 10;

	cout << "\n:: Human ::\n";
	Human* human[n]{};
	unsigned int traveller_count = 0;
	unsigned int policeOfficer_count = 0;
	unsigned int bandit_count = 0;

	for (int i = 0; i < n; i++)
	{
		human[i] = humanFactory(HumanType(rand() % 3));
		human[i]->info();

		//if (typeid(*human[i]) == typeid(Traveller)) traveller_count++;
		//if (typeid(*human[i]) == typeid(PoliceOfficer)) policeOfficer_count++;
		//if (typeid(*human[i]) == typeid(Bandit)) bandit_count++;
	}

	cout << typeid(*human[0]).name() << endl;
	cout << typeid(Traveller).name() << endl;

	cout << "    traveller: " << traveller_count << "\t";
	cout << "policeOfficer: " << policeOfficer_count << "\t";
	cout << "       bandit: " << bandit_count << endl;
	for (int i = 0; i < n; i++)
	{
		delete human[i];
	}

	cout << "\n:: Transport ::\n";
	Transport* transport[n]{};
	unsigned int car_count = 0;
	unsigned int plane_count = 0;
	unsigned int boat_count = 0;

	for (int i = 0; i < n; i++)
	{
		transport[i] = transportFactory(TransportType(rand() % 3));
		transport[i]->info();
		//if (typeid(*transport[i]) == typeid(Car)) car_count++;
		//if (typeid(*transport[i]) == typeid(Plane)) plane_count++;
		//if (typeid(*transport[i]) == typeid(Boat)) boat_count++;
	}

	cout << "  car_count: " << car_count << "\t";
	cout << "plane_count: " << plane_count << "\t";
	cout << " boat_count: " << boat_count << endl;

	for (int i = 0; i < n; i++)
	{
		delete transport[i];
	}

}