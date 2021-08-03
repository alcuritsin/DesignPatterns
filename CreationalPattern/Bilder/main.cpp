#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<string>
#include<ctime>

using namespace std;

//	Product
class Computer
{
	string CPU;
	string GPU;
	string RAM;
	string Disk;
	bool is_on;

public:
	Computer()
	{
		is_on = false;
	}

	void setCPU(const string CPU)
	{
		this->CPU = CPU;
	}
	void setGPU(const string GPU)
	{
		this->GPU = GPU;
	}
	void setRAM(const string RAM)
	{
		this->RAM = RAM;
	}
	void setDisk(const string Disk)
	{
		this->Disk = Disk;
	}
	void power_button()
	{
		is_on = is_on ? false : true;
	}
	void info()
	{
		if (is_on)
		{
			cout << "System properties: "<< endl;
			cout << " CPU: " << CPU << endl;
			cout << " GPU: " << GPU << endl;
			cout << " RAM: " << RAM << endl;
			cout << "Disk: " << Disk << endl;
		}
		else
		{
			cout << "Computer is off" << endl;
		}
	}
};

//	Abstravt builder
class ComputerBuilder
{
protected:
	Computer* computer;
public:
	ComputerBuilder()
	{
		this->computer = new Computer;
	}
	virtual ~ComputerBuilder()
	{
		delete this->computer;
	}

	Computer* getComputer() const
	{
		return this->computer;
	}

	virtual void setCPU() = 0;
	virtual void setGPU() = 0;
	virtual void setRAM() = 0;
	virtual void setDisk() = 0;
};

// Concret builder
class CheepComputerBuilder :public ComputerBuilder
{
public:
	~CheepComputerBuilder()
	{

	}
	void setCPU()
	{
		computer->setCPU("Celeron");
	}
	void setGPU()
	{
		computer->setGPU("IntelHD Graphics");
	}
	void setRAM()
	{
		computer->setRAM("4 Gb");
	}
	void setDisk()
	{
		computer->setDisk("Samsung 360 Gb");
	}
};

class OfficeComputerBuilder :public ComputerBuilder
{
public:
	~OfficeComputerBuilder()
	{

	}
	void setCPU()
	{
		computer->setCPU("Intel i5");
	}
	void setGPU()
	{
		computer->setGPU("GeForce GT 730 2 Gb");
	}
	void setRAM()
	{
		computer->setRAM("16 Gb");
	}
	void setDisk()
	{
		computer->setDisk("Goodram CX400 256 Gb");
	}
};

class GameComputerBuilder :public ComputerBuilder
{
public:
	~GameComputerBuilder()
	{

	}
	void setCPU()
	{
		computer->setCPU("Intel i9");
	}
	void setGPU()
	{
		computer->setGPU("GeForce RTX 3080 Ti 12 Gb");
	}
	void setRAM()
	{
		computer->setRAM("64 Gb");
	}
	void setDisk()
	{
		computer->setDisk("Samsung 980 PRO SSD M.2 PCI-E 4.0 x4 1000 Gb");
	}
};

//	Director
class Sysadmin
{
	ComputerBuilder* comp_builder;
public:
	void assamblayComputer(ComputerBuilder* comp_builder)
	{
		this->comp_builder = comp_builder;
		comp_builder->setCPU();
		comp_builder->setGPU();
		comp_builder->setRAM();
		comp_builder->setDisk();

	}
	void turnOnTheComputer()
	{
		comp_builder->getComputer()->power_button();
		comp_builder->getComputer()->info();
	}
};

void main()
{
	setlocale(LC_ALL, "ru-RU");

	Sysadmin nice_guy;

	CheepComputerBuilder computer_for_bookkeper;
	OfficeComputerBuilder office_computer;
	GameComputerBuilder gaming_computer;

	nice_guy.assamblayComputer(&computer_for_bookkeper);
	nice_guy.turnOnTheComputer();

	nice_guy.assamblayComputer(&office_computer);
	nice_guy.turnOnTheComputer();

	nice_guy.assamblayComputer(&gaming_computer);
	nice_guy.turnOnTheComputer();
}