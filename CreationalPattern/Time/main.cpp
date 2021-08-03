#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<ctime>

using namespace std;

void main()
{
	setlocale(LC_ALL, "ru-RU");
	
	time_t timer;	//	timer - time_t - long long int

	time(&timer);

	cout << timer << endl;

	tm* current_time = localtime(&timer);

	cout << asctime(current_time) << endl;
}