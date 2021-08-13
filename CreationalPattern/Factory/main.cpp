#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<string>
#include<ctime>

using namespace std;

class Human
{
	unsigned int hp;
	unsigned int demage;
	unsigned int armor;
public:
	Human(unsigned int hp, unsigned int demage, unsigned int armor)
	{
		this->hp = hp;
		this->demage = demage;
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
		cout << "demage: " << demage << "\n";
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
	Human* human[n]{};
	unsigned int traveller_count = 0;
	unsigned int policeOfficer_count = 0;
	unsigned int bandit_count = 0;

	for (int i = 0; i < n; i++)
	{
		human[i] = humanFactory(HumanType(rand() % 3));
		human[i]->info();
		if (typeid(*human[i]) == typeid(class Traveller)) traveller_count++;
		if (typeid(*human[i]) == typeid(class PoliceOficer)) policeOfficer_count++;
		if (typeid(*human[i]) == typeid(class Bandit)) bandit_count++;
	}
	cout << "    traveller: " << traveller_count << "\t";
	cout << "policeOfficer: " << policeOfficer_count << "\t";
	cout << "       bandit: " << bandit_count << endl;
	for (int i = 0; i < n; i++)
	{
		delete human[i];
	}
}