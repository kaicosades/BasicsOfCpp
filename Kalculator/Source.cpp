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
	cout << "������� �" << endl;
	cin >> a;
	cout << "������� b" << endl;
	cin >> b;
	cout << "�������� ��������:\n 1)+\n 2)-\n 3)*\n 4)/" << endl;
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
cout << "������� ������ ���� ������������, ����� ���������� ����� ���� ������� ����� ������� ������������?"
"\n 1)50<\n 2)100<\n 3)500<\n 4)1000<" << endl;
cin >> i;

if (i == 4)
{
	a++;
	cout << "���������� �������: " << a << endl;
}
else
cout << "���������� �������: " << a << endl;

cout << "��� ���������� �������������� ����������� ��� ������ � �������� �������?"
"\n 1)���\n 2)���\n 3)���\n 4)���" << endl;
cin >> i;

if (i == 1)
{
	a++;
	cout << "���������� �������: " << a << endl;
}
else
cout << "���������� �������: " << a << endl;

cout << "������� ����� ���������� ��� ���������� ���� Long?"
"\n 1)2 �����\n 2)4 �����\n 3)6 ����\n 4)8 ����" << endl;
cin >> i;

if (i == 2)
{
	a++;
	cout << "���������� �������: " << a << endl;
}
else
cout << "���������� �������: " << a << endl;

cout << "������������ ����� �������� ��������, �������� 8 ���� ������ ����������:"
"\n 1)Int\n 2)Long Long\n 3)Double\n 4)Float" << endl;
cin >> i;
if (i == 3)
{
	a++;
	cout << "���������� �������: " << a << endl;
}
else
cout << "���������� �������: " << a << endl;

cout << "������� ����� 2+2*2?"
"\n 1)4\n 2)2\n 3)8\n 4)6" << endl;
cin >> i;
if (i == 4)
{
	a++;
	cout << "���������� �������: " << a << endl;
}
else
cout << "���������� �������: " << a << endl;

#endif
}


