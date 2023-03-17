#include<iostream>
#include<conio.h>
//#include<windows.h>
using namespace std;

#define PREDIDUSHIY_UROK
//#define P
//#define TABL_UMN
//#define TABL_PIF

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef P
	int n; //Количесво итерация
	cout << "Введите кол ит"; cin >> n;

	for (
		int i=0;
		i<n;
		i++)
	{
		cout << i << "\t";
	}
#endif

#ifdef PREDIDUSHIY_UROK
	char key; //эта переменная будет хранить код нажатой клавиши
	do
	{
		key = _getch(); 
		cout << (int)key << "\t" << key << endl;
	} while ((int)key != 27);
#endif
	
	//return 1;
	//key = key + 0;	
	//return;
	//key = (int)key;
	//cout << key;

#ifdef TABL_UMN
	for (int i = 1; i <= 10; i++)
	{
		
		cout << "Таблица умножения на " << i << "\n";
		for (int j = 1; j <= 10; j++)
		{
			if (i < 10)cout << " ";
			cout << i << " * ";
			if (j < 10)cout << " ";
			cout << j << " = ";
			if (i * j < 100)cout << " ";
			if (i * j < 10)cout << " ";
			cout << i * j << endl;
			//Sleep(50);
		}
		cout << endl;
	}
#endif

#ifdef TABL_PIF
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cout.width(4); //??? цифра в скобках это колличество знаков для вывода
			cout << i * j << "\t";
		}
		cout << endl;
	}
#endif


}