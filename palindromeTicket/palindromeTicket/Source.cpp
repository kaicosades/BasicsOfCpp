#include<iostream>
#define PALINDROM
//#define TICKET
using namespace std;
void main()
{
	setlocale(LC_ALL, "");

	int a, n, exp, i;
	cout << "������� �����:" << endl;
	cin >> a;

#ifdef PALINDROM
	
	if (a % 10 == 0 && a != 0) // ���� ����� ������������ �� 0, �� ��� �� ���������, ����� ������ 0
		cout << "����� �� ���������." << endl;
	else
		if (-10 < a && a < 10) // �������� �� ����������� �����
			cout << "����� ���������." << endl;
		else
			if (-100 < a && a < 100 && a % 11 == 0) // �������� �� ���������� �����
				cout << "����� ���������." << endl;
			else
			{
				n = 0; //���������� ����
				i = a; //��������������� ���������� ��� ���������� ���������� ����
				while (i >= 1)
				{
					n++;
					i = i / 10;
				}

				i = n; //�������
				exp = 1; //������ � �������, ������������ ���������� �����
				while (i > 1)
				{
					exp = exp * 10;
					i = i - 1;
				}

				n = n / 2; // ������� ���� ����� ��������
				i = 0; // �������
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
						cout << "����� �� ���������." << endl;
						i = n + 1;
					}
				if (i < n + 1)
					cout << "����� ���������." << endl;


			}
#endif

#ifdef TICKET
	exp = 0;
	i = 0;
	while (i != 3)
	{
		exp = exp + a % 10; // ������ ����� ������
		a = a / 10;
		i++;
	}
	n = 0;
	i = 0;
	while (i != 3)
	{
		n = n + a % 10; // ����� ����� ������
		a = a / 10;
		i++;
	}
	if (n == exp)
		cout << "����� ����������.";
	else
		cout << "����� �������.";
#endif

}