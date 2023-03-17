#include <iostream>
#include <conio.h>
using namespace std;

//#define TASK1
//#define TASK2 // Не учитывает 0^0
#define TASK3 // Не закончено
//#define TASK4
//#define TASK5
//#define TASK6

void main()
{
	setlocale(LC_ALL, "Russian");
	int n, i, c;
	float a;

#ifdef TASK1
	cout << "Введите число, чтобы узнать его факториал: \n"; cin >> n;
	for (i = n; i > 1; i--)
	{
		a = n * (i - 1);
		n = a;
	}
	cout << n;
#endif

#ifdef TASK2 
	cout << "Введите основание: \n"; cin >> a;
	cout << "Введите степень: \n"; cin >> i;
	c = a;

	if (i == 0)
		a = 1;
	else
		if (i > 0)
		{
			for (i; i > 1; i--)
			{
				a = a * c;
			}
		}
		else
		{
			for (i; i < -1; i++)
			{
				// условие a = 1 / c не компилилось?
				a = a * c;
			}
			a = 1 / a;
		}
	cout << a;
#endif

#ifdef TASK3

	char key;
	i = 0;
	c = 0;
	for (n=0; n < 32; n++)
	{
		while (c != 8)
		{
			key = i;
			if (int(key) < 100 && int(key) >= 10)
			{
				if (int(key) == 27)
					cout << "     ";
				if (int(key) == 10)
				{
					key = i + 1;// Если убрать комментарий, то появляются 11 и 12, но теряются 8 и 9 ???
					//cout << "  ";
				}
				cout << key << "   " << int(key) << "  ";
			}
			if (int(key) >= 100)
			cout << key << "  " << int(key) << "  ";
			if (int(key) < 10 && int(key) >= 0)
			{
				if (int(key) == 7)
					cout << " ";
				cout << key << "    " << int(key) << "  ";
			}
			if (int(key) < 0 && int(key) > -10)
			cout << key << "   " << int(key) << "  ";
			if (int(key) <= -10 && int(key) > -100)
			cout << key << "  " << int(key) << "  ";
			if (int(key) <= -100)
			{
				if (int(key) == -107)
					cout << " ";
					cout << key << " " << int(key) << "  ";
			}
			i++;
			c++;
		}
		cout << "\n";
		c = 0;
	}

#endif

#ifdef TASK4
	cout << "Введите предел ряда Фибоначчи: \n"; cin >> n;
	c = 1;
	i = 1;
	if (n >= 1)
	{
		cout << 0 << " " << 1 << " " << 1 << " ";
		while ((c + i) <= n)
		{
			c = c + i;
			i = c - i;
			cout << c << " ";
		}
	}
	else
		cout << 0;
#endif

#ifdef TASK5

	cout << "Введите количество чисел ряда Фибоначчи: \n"; cin >> n;
	c = 0;
	i = 1;
	a = 0;
	while (a != n)
	{
		a++;
		cout << c << " ";
		c = c + i;
		i = c - i;
	}
#endif

#ifdef TASK6
	cout << "Введите предел простых чисел: \n"; cin >> n;
	i = 2;
	
	switch (n)
	{
	case (1): cout << "1";
		break;
	case (2): cout << "1 2";
		break;
	}

	if (n>2)
	cout << "1 2 ";
	for (c=3; c <= n; c++)
	{
		while (c!=i && c%i!=0)
		{
			i++;
			if (c % i == 0 && c == i)
			{
				cout << c << " ";
			}
			
		}
		i = 2;
	}
#endif

	
}