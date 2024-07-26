#include<iostream>
#define PALINDROM
//#define TICKET
using namespace std;
void main()
{
	setlocale(LC_ALL, "");

	int a, n, exp, i;
	cout << "Введите число:" << endl;
	cin >> a;

#ifdef PALINDROM
	
	if (a % 10 == 0 && a != 0) // если число оканчивается на 0, то оно не полиндром, кроме самого 0
		cout << "Число не полиндром." << endl;
	else
		if (-10 < a && a < 10) // проверка на однозначное число
			cout << "Число полиндром." << endl;
		else
			if (-100 < a && a < 100 && a % 11 == 0) // проверка на двузначное число
				cout << "Число полиндром." << endl;
			else
			{
				n = 0; //количество цифр
				i = a; //вспомогательная переменная для вычисления количества цифр
				while (i >= 1)
				{
					n++;
					i = i / 10;
				}

				i = n; //степень
				exp = 1; //десять в степени, равнозначная введенному числу
				while (i > 1)
				{
					exp = exp * 10;
					i = i - 1;
				}

				n = n / 2; // сколько цифр нужно сравнить
				i = 0; // счетчик
				while (i < n)
					if (a / exp == a % 10)
					{
						a = a - (a % 10) * exp;
						a = a / 10;
						exp = exp / 100;
						i++;
					}
					else
					{
						cout << "Число не полиндром." << endl;
						i = n + 1;
					}
				if (i < n + 1)
					cout << "Число полиндром." << endl;


			}
#endif

#ifdef TICKET
	exp = 0;
	i = 0;
	while (i != 3)
	{
		exp = exp + a % 10; // правая часть билета
		a = a / 10;
		i++;
	}
	n = 0;
	i = 0;
	while (i != 3)
	{
		n = n + a % 10; // левая часть билета
		a = a / 10;
		i++;
	}
	if (n == exp)
		cout << "Билет счастливый.";
	else
		cout << "Билет обычный.";
#endif

}