#include<iostream>
using namespace std;

//#define logical_types
//#define data_types
#define DECLARATION_AND_INITIALISATION 

void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Привет DataTypes" << endl;


#if defined logical_types
	cout << true << endl;
	cout << false << endl;
	cout << 0.0000000001 << endl;
#endif


#if defined data_types
	cout << sizeof(long long) << endl;
	cout << "long long:\n";
	cout << "unsigned long long:" << LLONG_MIN << "..." << LLONG_MAX << endl;
	cout << "unsigned long long:" << 0 << " ... " << ULLONG_MAX << endl;
	cout << "\n-------------------------------------------\n";

	cout << "float:\n";
	cout << sizeof(float) << endl;
	cout << FLT_MIN << " ... " << FLT_MAX << endl;
	cout << "\n-------------------------------------------\n";
	cout << "double:\n";
	cout << sizeof(double) << endl;
	cout << DBL_MIN << "..." << DBL_MAX << endl;

#endif 


#if defined DECLARATION_AND_INITIALISATION
	double price_of_coffe;
	int number_of_cups;
	cout << "Введите стоимость кофе:"; cin >> price_of_coffe;
	cout << "введите количество чашек:"; cin >> number_of_cups;
	double total_price = price_of_coffe * number_of_cups;
	cout << "Общая стоимость:" << total_price << endl;
	//cout << price_of_coffee << endl;
#endif 

	cout << sizeof('+') << endl;
	cout << sizeof("+") << endl;

}




