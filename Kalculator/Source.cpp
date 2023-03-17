#include<iostream>
using namespace std;
//#define TASK7
//#define TASK1
//#define TASK2
//#define TASK3
//#define TASK4
//#define TASK5
//#define TASK6

void main()
{
	setlocale(LC_ALL, "Rus");
	
#if defined TASK7
	float a, b, c;
	int i;
	cout << "введите а" << endl;
	cin >> a;
	cout << "введите b" << endl;
	cin >> b;
	cout << "выберите действие:\n 1)+\n 2)-\n 3)*\n 4)/" << endl;
	cin >> i;

	if (i == 1)
	{
		c = a + b;
		cout << "a + b = " << c << endl;
	}
	else
	if (i == 2)
	{
		c = a - b;
		cout << "a - b = " << c << endl;
	}
	else
	if (i == 3)
	{
		c = a * b;
		cout << "a * b = " << c << endl;
	}
	else
	if (i == 4)
	{
		c = a / b;
		cout << "a / b = " << c << endl;
	}

#endif

#if defined TASK1
	int i = 3;
	i = ++i + ++i;
	cout << i << endl;
#endif

#if defined TASK2
	int i = 3;
	i = ++i + 1 + ++i * 2;
	cout << i << endl;
#endif

#if defined TASK3
	int i = 3;
	i = ++i + 1 + (++i *= 2);
	cout << i << endl;
#endif


#if defined TASK4
	int i = 3;
	i += ++i + 1 + (++i *= 2);
	cout << i << endl;
#endif

#if defined TASK5
	int i = 3;
	i *= ++i + 1 + (++i += 2);
	cout << i << endl;
#endif


#if defined TASK6
	int i, a;
	a = 0;
cout << "Сколько должно быть транзисторов, чтобы микросхему можно было назвать сверх большой интегральной?"
"\n 1)50<\n 2)100<\n 3)500<\n 4)1000<" << endl;
cin >> i;

if (i == 4)
{
	a++;
	cout << "правильных ответов: " << a << endl;
}
else
cout << "правильных ответов: " << a << endl;

cout << "Как называется математический сопроцессор для работы с дробными числами?"
"\n 1)ФПУ\n 2)АЛУ\n 3)ТГУ\n 4)СПУ" << endl;
cin >> i;

if (i == 1)
{
	a++;
	cout << "правильных ответов: " << a << endl;
}
else
cout << "правильных ответов: " << a << endl;

cout << "Сколько место выделяется для переменной типа Long?"
"\n 1)2 байта\n 2)4 байта\n 3)6 байт\n 4)8 байт" << endl;
cin >> i;

if (i == 2)
{
	a++;
	cout << "правильных ответов: " << a << endl;
}
else
cout << "правильных ответов: " << a << endl;

cout << "Вещественное число двоичной точности, занимает 8 байт памяти называется:"
"\n 1)Int\n 2)Long Long\n 3)Double\n 4)Float" << endl;
cin >> i;
if (i == 3)
{
	a++;
	cout << "правильных ответов: " << a << endl;
}
else
cout << "правильных ответов: " << a << endl;

cout << "Сколько будет 2+2*2?"
"\n 1)4\n 2)2\n 3)8\n 4)6" << endl;
cin >> i;
if (i == 4)
{
	a++;
	cout << "правильных ответов: " << a << endl;
}
else
cout << "правильных ответов: " << a << endl;

#endif
}


