#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a, b;
	cout << "������� ���������� �:"; cin >> a;
	cout << endl << "������� ���������� b:"; cin >> b;
	a = a ^ b;
	b = a ^ b;
	a ^= b;
	cout << endl << "a = " << a << " b = " << b;
}