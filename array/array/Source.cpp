#include<iostream>
#include<conio.h>
using namespace std;
int shiftLeft(int arr[], const int n);
int shiftRight(int arr[], const int n);
//#define LEFT 75
//#define RIGHT 77 

//enum Switch
//{
//	LEFT = 75,
//	RIGHT = 77,
//
void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;	// = 5; //������������ �������
						//cin >> n;
	int arr[n];
						//arr[2] = 123;
						//cout << arr[2] << endl;
	cout << "������� �������� �������: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	cout << "���������� ������� �������: " << max << endl;

	int min = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	cout << "���������� ������� �������: " << min << endl;

	float sum= arr[0];
	for (int i = 1; i < n; i++)
	{
		sum += arr[i];
	}
	cout <<"������� �������������� �������: "<< sum / n << endl;
	cout <<"����� �������: "<< sum << endl;
	cout << "�������� ��������: <-     ->" << endl;
	
	int code = _getch();
	cout << code << endl;
	if (code == 0 || code == 224)
		code = _getch();
	cout << code;
	switch (code)
	{
	case 75: shiftLeft(arr, n);
		break;
	case 77: shiftRight(arr, n);
		break;
	}


		for (int i = 0; i < n; i++)cout << arr[i] << "\t";
	cout << endl;
}

int shiftLeft(int arr[], const int n)
{
	int m;
	cout << "������� ��������: "; cin >> m;
	m = m % n;
	for (m; m != 0; m--)
	{
		int a = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n-1] = a;
	
	}
	return arr[n];
}

int shiftRight(int arr[], const int n)
{
	int m;
	cout << "������� ��������: "; cin >> m;
	m = m % n;
	for (m; m != 0; m--)
	{
		int a = arr[n-1];
		for (int i = n-1; i >0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = a;

	}
	return arr[n];
}