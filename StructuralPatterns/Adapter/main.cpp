#include <iostream>
#include<string>
#include<ctime>

using namespace std;

typedef int Cable;

class EuropeanSocketInterface
{
public:
	virtual int voltage() = 0;

	virtual Cable line() = 0;  //  Фаза
	virtual Cable neutrale() = 0;  //  Ноль
	virtual Cable earth() = 0;  // Земля
};

class Socket :public EuropeanSocketInterface
{
	//  Интерфейсы не наследуют!!!
	//  Интерфейсы  РЕАЛИЗУЮТ

public:
	int voltage()
	{
		return 220;
	}
	Cable line()
	{
		return 1;
	}
	Cable neutrale()
	{
		return -1;
	}
	Cable earth()
	{
		return 0;
	}
};

class USASocketInterface
{
public:
	virtual int voltage() = 0;

	virtual Cable line() = 0;  //  Фаза
	virtual Cable neutrale() = 0;  //  Ноль
};


class Adapter :public USASocketInterface
{
	EuropeanSocketInterface* socket;
public:
	void plugIn(EuropeanSocketInterface* fork)
	{
		socket = fork;
	}
	int voltage()
	{
		return 110;
	}
	Cable line()
	{
		return socket->line();
	}
	Cable neutrale()
	{
		return socket->neutrale();
	}
};

class Kattle
{
	USASocketInterface* power;
public:
	void plugIn(USASocketInterface* socket)
	{
		power = socket;
	}

	void boil()
	{
		if (power->voltage()>110)
		{
			cout << "Fire in the hole" << endl;
		}
		else if (power->line() ==1 && power->neutrale()==-1)
		{
			cout << "Boil" << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "ru-RU");
	srand(time(NULL));

	Socket socket;
	Kattle kattle;
	Adapter	adapter;

	adapter.plugIn(&socket);
	kattle.plugIn(&adapter);
	kattle.boil();

}