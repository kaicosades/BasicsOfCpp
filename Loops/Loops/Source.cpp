#include<iostream>
#include<cmath>
using namespace std;
//#define while_1
//#define while_2
#define while_3

void main()
{

	setlocale(LC_ALL, "");	//�� ������� ������������� ���������� ����
#ifdef while_1
	int i = 0; //������� �����
	int n;     //���������� ��������
	cout << "������� ��������� ��������:"; cin >> n;
	while (i<n)
	{
		cout << i++ << "������" << endl;
		//i++;
	}
#endif

#ifdef while_2
	int n;     //���������� ��������
	cout << "������� ��������� ��������:"; cin >> n;
	while (n-- > 0) //while(n--)��������, ������ ��� �������� ��������� ���������� true ��� false
	{
		cout << n << "\t";
	}
#endif

#ifdef while_3
	int a, n,z,f,g,r,y;
	n = a = 0;
	cin >> a;
	if (-10 < a && a < 10)
		cout << "����� ���������";
	else
		if (-100 < a && a < 100 && a % 11 == 0)
			cout << "����� ���������";
		else
		{//cout << "����� �� ���������";
			z = a;
			while (z >= 1)
			{
				n++;
				z = z / 10;
			}
			cout << n << endl;
			r = n / 2;
			g = pow(10, r);// 10 ^ r; 
			f = a % g;
			cout << f << endl;
			//cout << n / 2;
			y = a / pow(10, (r + 1));
			if (y == f) // ��������
				cout << "����� ���������";
			else	
				cout << "����� �� ���������";

		}
	/*if (n % 2 == 1)
		do
		a = a - (1 * 10 ^ n + 1); 
		while (*/


#endif
	//int a;
	//cin >> a;
	//cout << a % 11;
}